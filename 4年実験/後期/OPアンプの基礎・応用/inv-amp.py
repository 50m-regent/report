import numpy as np
import matplotlib.pyplot as plt

plt.rcParams['text.usetex'] = True
plt.rcParams['axes.facecolor'] = (1, 1, 1, 0)

g = [6, 6, 6, 6, 6, 6, 6, 2.6, -0.4, -4.8, -11.2, -18.1, -21.4, -26]
phi = [0, 0, 0, 0, 0, 0, 0, -54, -68, -81, -90, -101, -119, -135]
f = [100, 200, 500, 1000, 2000, 5000, 10000, 20000, 30000, 50000, 100000, 200000, 300000, 500000]

fig = plt.figure()
ax1 = fig.add_subplot(111)
ax2 = ax1.twinx()

ax1.semilogx(
    f, g,
    color='k',
    marker='o',
    markersize=5,
    label='$G \ [\\rm{dB}]$'
)
ax1.set_xlabel('$f \ [\\rm{Hz}]$')
ax1.set_xlim([1000, 1000000])
ax1.set_ylabel('$G \ [\\rm{dB}]$', rotation=0)
ax1.set_ylim([-30, 10])

ax2.semilogx(
    f, phi,
    color='k',
    marker='s',
    markersize=5,
    label='$\phi \ [^\\circ]$'
)
ax2.set_ylabel('$\phi \ [^\\circ]$', rotation=0)
ax2.set_ylim([-140, 5])

h1, l1 = ax1.get_legend_handles_labels()
h2, l2 = ax2.get_legend_handles_labels()
ax1.legend(h1+h2, l1+l2)

plt.savefig('img/inv-amp-graph1.eps')
plt.show()