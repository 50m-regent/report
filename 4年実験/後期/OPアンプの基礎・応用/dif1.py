import numpy as np
import matplotlib.pyplot as plt

plt.rcParams['text.usetex'] = True
plt.rcParams['axes.facecolor'] = (1, 1, 1, 0)

g = [-31.1, -25, -17.1, -11.1, -5.1, 2.8, 8.9, 15.1]
phi = [-90.1, -90.2, -90.3, -90.5, -89, -91.9, -92.8, -93.6]
f = [100, 200, 500, 1000, 2000, 5000, 10000, 20000]

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
ax1.set_xlim([100, 100000])
ax1.set_ylabel('$G \ [\\rm{dB}]$', rotation=0)
ax1.set_ylim([-35, 20])

ax2.semilogx(
    f, phi,
    color='k',
    marker='s',
    markersize=5,
    label='$\phi \ [^\\circ]$'
)
ax2.set_ylabel('$\phi \ [^\\circ]$', rotation=0)
ax2.set_ylim([-135, -45])

h1, l1 = ax1.get_legend_handles_labels()
h2, l2 = ax2.get_legend_handles_labels()
ax1.legend(h1+h2, l1+l2)

plt.savefig('img/difex-graph1.eps')
plt.show()