# In this code generator works faster than vectorization
# probably because iterations starting to beat vectorization
# after some memory treshold (need to allocate memory for vectorization)

xs = np.random.uniform(0, 100, size=3000)
def func(xs, a, x0, gamma):
    return a * gamma / (gamma ** 2 + (xs - x0) ** 2)


def gen(xs, a, x0, gamma):
    while True:
        yield func(xs, a, x0, gamma)


def test_gen(xs, n, m):
    aas = np.ones(m) * 5
    x0s = np.ones(m) * 10
    gas = np.ones(m) * 2
    generator = gen(xs, aas[:, np.newaxis], x0s[:, np.newaxis], gas[:, np.newaxis])
    return np.array(list(itertools.islice(generator, n))).sum(axis=1)


def test_calc(xs, n, m):
    aas = np.ones((n, m)) * 5
    x0s = np.ones((n, m)) * 10
    gas = np.ones((n, m)) * 2
    return func(xs, aas[:, :, np.newaxis], x0s[:, :, np.newaxis], gas[:, :, np.newaxis]).sum(axis=1)

# wins calc
# %timeit test_gen(100, 5)
# %timeit test_calc(100, 5)

# wins gen
# %timeit test_gen(100, 200)
# %timeit test_calc(100, 200)
