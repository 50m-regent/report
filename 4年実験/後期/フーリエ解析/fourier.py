import matplotlib.pyplot as plt
import numpy as np
import random as rand
import csv

def dft(f):
    N = len(f)
    X = []
    for l in range(N):
        x = 0
        for k in range(N):
            x += f[k] * np.e ** (-1j * 2 * np.pi * k * l / N)
        X.append(x)
    return np.array(X)

def idft(F):
    N = len(F)
    x = []
    for l in range(N):
        X = 0
        for k in range(N):
            X += F[k] * np.e ** (1j * 2 * np.pi * k * l / N)
        x.append(X)
    return np.array(x) / N

if __name__ == '__main__':
    with open('data/sample.csv') as f:
        reader = csv.reader(f)
        y = np.array([float(row[0]) for row in reader])

    plt.subplot2grid((2, 2), (0, 0), colspan=2)
    plt.plot(y)

    plt.subplot2grid((2, 2), (1, 0))
    plt.bar(np.arange(0, 15), abs(dft(y))[1:16])
    plt.xticks(np.arange(0, 15, 2))

    plt.subplot2grid((2, 2), (1, 1))
    plt.bar(np.arange(985, 1000), abs(dft(y))[-15:])
    plt.xticks(np.arange(985, 1000, 2))
    plt.yticks([])

    plt.subplots_adjust(wspace=0)
    plt.show()