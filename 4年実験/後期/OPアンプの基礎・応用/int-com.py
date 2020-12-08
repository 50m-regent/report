import numpy as np
import matplotlib.pyplot as plt

plt.rcParams['text.usetex'] = True
plt.rcParams['axes.facecolor'] = (1, 1, 1, 0)

g1 = [27, 22.3, 15.8, 10.9, 2.6, -1.9, -12, -14]
phi1 = [-90.7, -90, -90, -93.6, -90, -90, -93.6, -90]
f1 = [300, 500, 1000, 2000, 5000, 10000, 20000, 50000]

g2 = [6, 6, 6, 5.1, 4.1, 2.9, 1.6, -3.1, -8.4, -20]
phi2 = [-180, -180, -165.6, -151.2, -140.4, -136.8, -133.2, -108.0, -100.8, -90]
f2 = [100, 500, 1000, 2000, 3000, 4000, 5000, 10000, 20000, 50000]

plt.semilogx(
    f1, g1,
    color='k',
    marker='o',
    markersize=5,
    label='BI'
)
plt.semilogx(
    f2, g2,
    color='k',
    marker='s',
    markersize=5,
    label='PI'
)

plt.xlabel('$f \ [\\rm{Hz}]$')
plt.xlim([100, 100000])
plt.ylabel('$G \ [\\rm{dB}]$', rotation=0)
plt.ylim([-20, 30])
plt.legend()
plt.savefig('img/int-com-graph1.eps')
plt.show()

plt.semilogx(
    f1, phi1,
    color='k',
    marker='o',
    markersize=5,
    label='BI'
)
plt.semilogx(
    f2, phi2,
    color='k',
    marker='s',
    markersize=5,
    label='PI'
)

plt.xlabel('$f \ [\\rm{Hz}]$')
plt.xlim([100, 100000])
plt.ylabel('$\phi \ [^\\circ]$', rotation=0)
plt.ylim([-180, -80])
plt.legend()
plt.savefig('img/int-com-graph2.eps')
plt.show()