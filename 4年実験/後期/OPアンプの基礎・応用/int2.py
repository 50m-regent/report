import numpy as np
import matplotlib.pyplot as plt

plt.rcParams['text.usetex'] = True
plt.rcParams['axes.facecolor'] = (1, 1, 1, 0)

g = [6, 6, 6, 5.1, 4.1, 2.9, 1.6, -3.1, -8.4, -20]
phi = [-180, -180, -165.6, -151.2, -140.4, -136.8, -133.2, -108.0, -100.8, -90]
f = [100, 500, 1000, 2000, 3000, 4000, 5000, 10000, 20000, 50000]

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
ax1.set_ylim([-20, 10])

ax2.semilogx(
    f, phi,
    color='k',
    marker='s',
    markersize=5,
    label='$\phi \ [^\\circ]$'
)
ax2.set_ylabel('$\phi \ [^\\circ]$', rotation=0)
ax2.set_ylim([-185, -90])

h1, l1 = ax1.get_legend_handles_labels()
h2, l2 = ax2.get_legend_handles_labels()
ax1.legend(h1+h2, l1+l2)

plt.savefig('img/nice-int-graph.eps')
plt.show()