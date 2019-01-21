import numpy as np
import math


def randomLinearAscend(length):
    ascend = np.zeros(length)
    start = np.random.randint(length)

    k = np.random.uniform(0.001, 10)
    ascend[start:] = k*np.arange(length-start)

    return ascend


def randomSigmoidAscend(length):
    ascend = np.zeros(length)
    start = np.random.randint(length)

    value_scale = np.random.uniform(0.001, 10*length)
    time_scale = np.random.uniform(0.001, 5)

    xs = np.linspace(-5, 5, length-start)
    ascend[start:] = value_scale / (1 + np.exp(-xs * time_scale))

    return ascend


def generateAscend(count, length):
    ascends = []
    types = [randomLinearAscend, randomSigmoidAscend]
    for i in range(count):
        ascend_func = np.random.choice(types)
        ascends.append(ascend_func(length))

    return np.array(ascends)
