import numpy as np
import matplotlib.pyplot as plt

plt.rcParams['text.usetex'] = True
plt.rcParams['axes.facecolor'] = (1, 1, 1, 0)

g = [6, 6, 6, 6, 6, 6, 6, 2.6, -0.4, -4.8, -11.2, -18.1, -21.4, -26]
f = [100, 200, 500, 1000, 2000, 5000, 10000, 20000, 30000, 50000, 100000, 200000, 300000, 500000]

plt.semilogx(
    [100, 1000000], [6, 6],
    linestyle='--',
    color='blue'
)
plt.semilogx(
    [15000, 800000], [6, -30],
    linestyle='--',
    color='blue'
)
plt.semilogx(
    f, g,
    color='k',
    marker='o',
    markersize=5,
    label='$G \ [\\rm{dB}]$'
)
plt.xlabel('$f \ [\\rm{Hz}]$')
plt.xlim([100, 1000000])
plt.ylabel('$G \ [\\rm{dB}]$', rotation=0)
plt.ylim([-30, 10])

plt.savefig('img/inv-amp-ex-graph.eps')
plt.show()