import numpy as np
import matplotlib.pyplot as plt
from matplotlib import collections as mc

np.random.seed = 42

if __name__ == '__main__':
    samples_count = 1000
    cov_matrix = [[1, 1],
                  [1, 2]]
    X = np.random.multivariate_normal([0, 0], cov_matrix, samples_count)
    print(X)
    est_cov_matrix = np.dot(X.T, X) / samples_count

    real_transf_X = np.dot(cov_matrix, X.T).T
    est_transf_X = np.dot(est_cov_matrix, X.T).T

    unit_circle = np.array([[np.cos(rad), np.sin(rad)] for rad in range(360)])
    real_transf_circle = np.dot(cov_matrix, unit_circle.T).T
    est_transf_circle = np.dot(est_cov_matrix, unit_circle.T).T

    real_values, real_vectors = np.linalg.eig(cov_matrix)
    real_vectors = np.multiply(real_vectors.T, real_values.reshape(2, 1))

    est_values, est_vectors = np.linalg.eig(est_cov_matrix)
    est_vectors = np.multiply(est_vectors.T, est_values.reshape(2, 1))

    plt.figure(figsize=(20, 10))
    plt.subplot(2, 3, 1, aspect='equal')
    plt.title("Data")
    plt.scatter(X[:, 0], X[:, 1])
    tmp = np.zeros((4, 2))
    tmp[1::2] = real_vectors
    plt.plot(tmp[:, 0], tmp[:, 1], 'g')
    tmp[1::2] = est_vectors
    plt.plot(tmp[:, 0], tmp[:, 1], 'r')

    plt.subplot(2, 3, 2, aspect='equal')
    plt.title("Real Cov * Data")
    plt.scatter(real_transf_X[:, 0], real_transf_X[:, 1])

    plt.subplot(2, 3, 3, aspect='equal')
    plt.title("Estimated Cov * Data")
    plt.scatter(real_transf_X[:, 0], real_transf_X[:, 1])

    plt.subplot(2, 3, 4, aspect='equal')
    plt.title("Unit circle")
    plt.scatter(unit_circle[:, 0], unit_circle[:, 1])

    plt.subplot(2, 3, 5, aspect='equal')
    plt.title("Real Cov * circle")
    plt.scatter(real_transf_circle[:, 0], real_transf_circle[:, 1])

    plt.subplot(2, 3, 6, aspect='equal')
    plt.title("Estimated Cov * circle")
    plt.scatter(est_transf_circle[:, 0], est_transf_circle[:, 1])

    plt.show()
