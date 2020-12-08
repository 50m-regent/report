import numpy as np
import matplotlib.pyplot as plt
from control.matlab import *

plt.rcParams['text.usetex'] = True

n = [-1, 0]
d = [0.00001, 1.1, 10000]
P = tf(n, d)
f1 = np.logspace(1, 6, 10000)
gain, phase, f1 = bode(P, f1 * 10, Plot=False)

g = [-24.4, -17.7, -10.5, -5.7, -4.4, -3.3, -3.1, -2.9, -2.4, -1.9, -1.9, -2.4, -3.1, -3.3, -4.3, -4.4, -10.5, -14.9, -21.9, -29.1]
phi = [90, 72, 72, 54, 50.4, 49, 36, 24.5, 28.8, 0, -18, -15.8, -28.8, -36, -37.7, -50.4, -66.6, -72, -86.4, -90]
f2 = [100, 200, 500, 1000, 1200, 1400, 1600, 1800, 2000, 5000, 10000, 12000, 14000, 16000, 18000, 20000, 50000, 100000, 200000, 500000]

f1 /= 6

plt.semilogx(
    f1, 20 * np.log10(gain),
    color='blue',
    linestyle='--'
)
plt.semilogx(
    f2, g,
    color='k',
    marker='o',
    markersize=5,
)
plt.xlim([100, 1000000])
plt.xlabel('$f \ [\\rm{Hz}]$')
plt.ylabel('$G \ [\\rm{dB}]$', rotation=0)
plt.savefig('img/band-1.eps')
plt.show()

plt.semilogx(
    f1, phase * 180 / np.pi + 180,
    color='blue',
    linestyle='--'
)
plt.semilogx(
    f2, phi,
    color='k',
    marker='o',
    markersize=5,
)
plt.xlim([100, 1000000])
plt.xlabel('$f \ [\\rm{Hz}]$')
plt.ylabel('$\phi \ [^\\circ]$', rotation=0)
plt.savefig('img/band-2.eps')
plt.show()