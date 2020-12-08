import numpy as np
import matplotlib.pyplot as plt
from control.matlab import *

plt.rcParams['text.usetex'] = True

n = [-0.00022, 0]
d = [0.00015, 1]
P = tf(n, d)
f1 = np.logspace(2, 5, 10000)
gain, phase, f1 = bode(P, f1, Plot=False)

g = [-31, -24.9, -17, -11, -5.3, -1.2, 2.9, 3.4, 3.9, 4.2, 5.5, 5.9]
phi = [-91, -91.8, -94.3, -98.3, -106.1, -125.5, -134.8, -138.5, -141.8, -144.6, -160.4, -171.8]
f2 = [100, 200, 500, 1000, 2000, 5000, 7000, 8000, 9000, 10000, 20000, 50000]

plt.semilogx(
    f1, 20 * np.log10(gain) + 2,
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
# plt.savefig('img/ex2-1.eps')
plt.show()

plt.semilogx(
    f1, phase * 180 / np.pi,
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
# plt.savefig('img/ex2-2.eps')
plt.show()