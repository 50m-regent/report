import numpy as np
import matplotlib.pyplot as plt

plt.rcParams['text.usetex'] = True
plt.rcParams['axes.facecolor'] = (1, 1, 1, 0)

g1 = [-31.1, -25, -17.1, -11.1, -5.1, 2.8, 8.9, 15.1]
phi1 = [-90.1, -90.2, -90.3, -90.5, -89, -91.9, -92.8, -93.6]
f1 = [100, 200, 500, 1000, 2000, 5000, 10000, 20000]

g2 = [-31, -24.9, -17, -11, -5.3, -1.2, 2.9, 3.4, 3.9, 4.2, 5.5, 5.9]
phi2 = [-91, -91.8, -94.3, -98.3, -106.1, -125.5, -134.8, -138.5, -141.8, -144.6, -160.4, -171.8]
f2 = [100, 200, 500, 1000, 2000, 5000, 7000, 8000, 9000, 10000, 20000, 50000]

plt.semilogx(
    f1, g1,
    color='k',
    marker='o',
    markersize=5,
    label='BD'
)
plt.semilogx(
    f2, g2,
    color='k',
    marker='s',
    markersize=5,
    label='PD'
)

plt.xlabel('$f \ [\\rm{Hz}]$')
plt.xlim([100, 100000])
plt.ylabel('$G \ [\\rm{dB}]$', rotation=0)
plt.ylim([-35, 20])
plt.legend()
plt.savefig('img/dif-com-graph1.eps')
plt.show()

plt.semilogx(
    f1, phi1,
    color='k',
    marker='o',
    markersize=5,
    label='BD'
)
plt.semilogx(
    f2, phi2,
    color='k',
    marker='s',
    markersize=5,
    label='PD'
)

plt.xlabel('$f \ [\\rm{Hz}]$')
plt.xlim([100, 100000])
plt.ylabel('$\phi \ [^\\circ]$', rotation=0)
plt.ylim([-180, -80])
plt.legend()
plt.savefig('img/dif-com-graph2.eps')
plt.show()