import os

import numpy as np
from keras import Sequential
from keras.layers import Dense
from keras.models import load_model
from keras.optimizers import Adam
from keras import backend as K


def build_simple_network():
    model = Sequential()

    model.add(Dense(2, activation='linear', input_shape=(2,)))
    model.add(Dense(3, activation='linear'))

    model.layers[0].set_weights([
        np.array([[2, -1], [1, 1]]),
        np.array([1, 0])
    ])

    model.layers[1].set_weights([
        np.array([[-2, 1, 4],
                  [1, 3, -1]]),
        np.array([6, 10, -5])
    ])

    model.compile(optimizer=Adam(), loss='mse')

    return model


def set_temperature_scaling(model, T):
    def temperature_softmax(x):
        return K.softmax(x / T)
    model.layers[-1].activation = temperature_softmax

    # workaround to rebuild graph with new activation function
    model_path = 'workaround_model.h5'
    try:
        model.save(model_path)
        model = load_model(
            model_path,
            custom_objects={'temperature_softmax': temperature_softmax}
        )
    finally:
        os.remove(model_path)

    return model


def get_gradients(x, model):
    fn = K.function([model.input], K.gradients(model.output, model.input))
    return fn([x])[0][0]


def main():
    x = np.array([1, -1])
    model = build_simple_network()
    y = model.predict(np.array([x]))
    print('Linear activations: f({}) = {}'.format(x, y))
    print('Gradients', get_gradients([x], model))

    temperature = 1
    t_model = set_temperature_scaling(model, temperature)
    y = t_model.predict(np.array([x]))
    grads = get_gradients([x], t_model)
    print('Temperature activation: f({}, T={}) = {}'.format(x, temperature, y))
    print('Gradients', grads)

    temperature = 1000
    t_model = set_temperature_scaling(model, temperature)
    y = t_model.predict(np.array([x]))
    grads = get_gradients([x], t_model)
    print('Temperature activation: f({}, T={}) = {}'.format(x, temperature, y))
    print('Gradients', grads)

    eps = 0.0015
    new_x = x - eps*(-grads)
    print('New x:', new_x)


if __name__ == '__main__':
    main()
