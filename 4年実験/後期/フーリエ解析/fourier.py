import matplotlib.pyplot as plt
import numpy as np
import random as rand
import csv

def dft(f, s):
    N = len(f)
    X = np.array([0j for i in range(N)])
    for l in range(N):
        for k in range(N):
            X[l] += f[k] * np.e ** (-1j * 2 * np.pi * k * l / N)
    return X * s / N

def idft(F, s):
    N = len(F)
    x = np.array([0j for i in range(N)])
    for l in range(N):
        X = 0
        for k in range(N):
            x[l] += F[k] * np.e ** (1j * 2 * np.pi * k * l / N)
        
    return x / s

def load_from_csv(filename):
    with open(filename) as f:
        reader = csv.reader(f)
        return np.array([float(row[0]) for row in reader])

if __name__ == '__main__':
    N = 1000
    fm = 10
    s = 2
    
    y = np.zeros(N)
    t = np.linspace(0, s, N)
    for f in range(1, fm + 1):
        y += np.sin(2 * np.pi * f * t)

    fy = dft(y, s)
    y = idft(fy, s).real

    plt.subplot2grid((2, 2), (0, 0), colspan=2)
    plt.plot(t, y)

    plt.subplot2grid((2, 2), (1, 0))
    plt.bar(np.arange(1, fm + 13), abs(fy)[1:fm + 13])
    plt.xticks(np.arange(1, fm + 13, 2))

    plt.subplot2grid((2, 2), (1, 1))
    plt.bar(np.arange(N - fm - 5, N), abs(fy)[-fm - 5:])
    plt.xticks(np.arange(N - fm - 5, N, 2))
    plt.yticks([])

    plt.subplots_adjust(wspace=0)
    plt.show()