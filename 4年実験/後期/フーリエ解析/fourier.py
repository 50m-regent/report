import matplotlib.pyplot as plt
import numpy as np
import random as rand
import csv

def dft(f):
    N = len(f)
    X = np.array([0j for i in range(N)])
    for l in range(N):
        for k in range(N):
            X[l] += f[k] * np.e ** (-1j * 2 * np.pi * k * l / N)
    return X / N

def idft(F):
    N = len(F)
    x = np.array([0j for i in range(N)])
    for l in range(N):
        for k in range(N):
            x[l] += F[k] * np.e ** (1j * 2 * np.pi * k * l / N)
        
    return x

def load_from_csv(filename):
    with open(filename) as f:
        reader = csv.reader(f)
        return np.array([float(row[0]) for row in reader])

if __name__ == '__main__':
    N = 1000
    fm = 5
    
    y = np.zeros(N)
    t = np.linspace(0, 2 * np.pi, N)
    for omega, a in zip(range(1, fm + 1), [5, 1, 3, 4, 2]):
        y += a * np.sin(omega * t)

    fy = dft(y)
    y = idft(fy).real

    plt.subplot2grid((2, 2), (0, 0), colspan=2)
    plt.plot(t, y)
    plt.xticks([0, np.pi / 2, np.pi, np.pi * 3 / 2, np.pi * 2], ["0", "$0.5\pi$", "$\pi$", "$1.5\pi$", "$2\pi$"])
    plt.xlim([0, np.pi * 2])
    plt.ylabel("$f$", rotation=0)
    plt.xlabel("$t$ [s]")

    plt.subplot2grid((2, 2), (1, 0))
    plt.bar(np.arange(1, fm + 3), abs(fy)[1:fm + 3])
    plt.xticks(np.arange(1, fm + 3))
    plt.ylabel("$X$", rotation=0)
    plt.xlabel("$\omega$ [rad/s]")

    plt.subplot2grid((2, 2), (1, 1))
    plt.bar(np.arange(N - fm - 3, N), abs(fy)[-fm - 3:])
    plt.xticks(np.arange(N - fm - 3, N))
    plt.yticks([])
    plt.xlabel("$\omega$ [rad/s]")

    plt.subplots_adjust(wspace=0, hspace=0.3)
    plt.savefig("img/fourier1.eps")