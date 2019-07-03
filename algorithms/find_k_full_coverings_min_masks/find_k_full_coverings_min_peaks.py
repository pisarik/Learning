#
#
from time import time
from queue import Queue

import numpy as np
from scipy.ndimage.morphology import binary_dilation
import matplotlib.pyplot as plt


def generate_masks(n, size):
    masks = np.zeros((n,)+size, dtype=bool)

    # create holes
    holes_counts = np.random.poisson(8, n)
    for i in range(n):
        holes_xs = np.random.randint(0, size[1], holes_counts[i])
        holes_ys = np.random.randint(0, size[0], holes_counts[i])
        masks[i, holes_ys, holes_xs] = True

        hole_size = np.random.randint(min(size)//5) + min(size)//15
        masks[i] = binary_dilation(masks[i],
                                   # structure=np.ones((3, 3), dtype=bool),
                                   iterations=hole_size)

    return ~masks


def queue_divide(masks, k, max_hole_area=-np.inf):
    color = 0
    color_to_masks = []
    color_map = np.zeros((masks.shape[1], masks.shape[2]), dtype=int)
    que = Queue()
    que.put([0, masks.shape[1], 0, masks.shape[2]])
    while not que.empty():
        li, ri, lj, rj = que.get()
        area = (ri - li) * (rj - lj)
        if area < max_hole_area:
            continue
        is_mask_cover_roi_pixels = np.all(masks[:, li:ri, lj:rj], axis=(1, 2))
        if is_mask_cover_roi_pixels.sum() < k:
            ci = (ri + li) // 2
            cj = (rj + lj) // 2
            if ri - li > 1 and rj - lj > 1:
                que.put([li, ci, lj, cj])
                que.put([ci, ri, lj, cj])
                que.put([li, ci, cj, rj])
                que.put([ci, ri, cj, rj])
            elif ri - li == 1:
                que.put([li, ri, lj, cj])
                que.put([li, ri, cj, rj])
            elif rj - lj == 1:
                que.put([li, ci, lj, rj])
                que.put([ci, ri, lj, rj])
            else:
                raise ValueError('Lol')
        else:
            color_to_masks.append(is_mask_cover_roi_pixels)
            color_map[li:ri, lj:rj] = color
            color += 1

    return color_map, color_to_masks


def main():
    n_masks = 100
    k_covers = 10
    max_masks = 3
    width = 2**12
    height = 2**12

    print('Generating masks...')
    masks = generate_masks(n=n_masks, size=(width, height))
    # for i in range(10):
    #     plt.imshow(masks[np.random.randint(n_masks)])
    #     plt.show()
    assert np.all(masks.sum(axis=0) >= k_covers), 'Impossible to solve'

    print('Searching answer...', end=' ')
    start_time = time()
    cover_map, color_to_masks = queue_divide(masks, k_covers)
    print(time() - start_time)
    plt.imshow(cover_map)
    plt.show()

    print('-')


if __name__ == '__main__':
    main()

# recursive solution not cool in python
# def divide(map, masks, k, li, ri, lj, rj):
#     is_mask_cover_region_pixels = np.all(masks[:, li:ri, lj:rj], axis=(1, 2))
#     if is_mask_cover_region_pixels.sum() < k:
#         ci = (ri - li) // 2
#         cj = (rj - lj) // 2
#         if ri - li > 1 and rj - lj > 1:
#             divide(map, masks, k, li, ci, lj, cj)
#             divide(map, masks, k, ci, ri, lj, cj)
#             divide(map, masks, k, li, ci, cj, rj)
#             divide(map, masks, k, ci, ri, cj, rj)
#         elif ri - li == 1:
#             divide(map, masks, k, li, ri, lj, cj)
#             divide(map, masks, k, li, ri, cj, rj)
#         elif rj - lj == 1:
#             divide(map, masks, k, li, ci, lj, rj)
#             divide(map, masks, k, ci, ri, lj, rj)
#         else:
#             raise ValueError('Lol')
#     else:
#         masks[:, li:ri, lj:rj] = is_mask_cover_region_pixels[:, np.newaxis, np.newaxis]
#         map[li:ri, lj:rj] = map.min() + 1
