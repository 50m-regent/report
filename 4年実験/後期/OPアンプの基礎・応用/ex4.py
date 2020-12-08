import numpy as np
import matplotlib.pyplot as plt
from control.matlab import *

plt.rcParams['text.usetex'] = True

n = [-1]
d = [0.0005, 2]
P = tf(n, d)
f1 = np.logspace(2, 5, 10000)
gain, phase, f1 = bode(P, f1, Plot=False)

g = [6, 6, 6, 5.1, 4.1, 2.9, 1.6, -3.1, -8.4, -20]
phi = [-180, -180, -165.6, -151.2, -140.4, -136.8, -133.2, -108.0, -100.8, -90]
f2 = [100, 500, 1000, 2000, 3000, 4000, 5000, 10000, 20000, 50000]

plt.semilogx(
    f1, 20 * np.log10(gain) + 12,
    color='blue',
    linestyle='--'
)
plt.semilogx(
    f2, g,
    color='k',
    marker='o',
    markersize=5,
)
plt.xlim([100, 100000])
plt.xlabel('$f \ [\\rm{Hz}]$')
plt.ylabel('$G \ [\\rm{dB}]$', rotation=0)
plt.savefig('img/intex2-1.eps')
plt.show()

plt.semilogx(
    f1, -phase * 180 / np.pi,
    color='blue',
    linestyle='--'
)
plt.semilogx(
    f2, phi,
    color='k',
    marker='o',
    markersize=5,
)
plt.xlim([100, 100000])
plt.xlabel('$f \ [\\rm{Hz}]$')
plt.ylabel('$\phi \ [^\\circ]$', rotation=0)
plt.savefig('img/intex2-2.eps')
plt.show()