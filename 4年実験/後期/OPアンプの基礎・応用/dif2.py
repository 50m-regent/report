import numpy as np
import matplotlib.pyplot as plt

plt.rcParams['text.usetex'] = True
plt.rcParams['axes.facecolor'] = (1, 1, 1, 0)

g = [-31, -24.9, -17, -11, -5.3, -1.2, 2.9, 3.4, 3.9, 4.2, 5.5, 5.9]
phi = [-91, -91.8, -94.3, -98.3, -106.1, -125.5, -134.8, -138.5, -141.8, -144.6, -160.4, -171.8]
f = [100, 200, 500, 1000, 2000, 5000, 7000, 8000, 9000, 10000, 20000, 50000]

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
ax1.set_ylim([-35, 10])

ax2.semilogx(
    f, phi,
    color='k',
    marker='s',
    markersize=5,
    label='$\phi \ [^\\circ]$'
)
ax2.set_ylabel('$\phi \ [^\\circ]$', rotation=0)
ax2.set_ylim([-180, -90])

h1, l1 = ax1.get_legend_handles_labels()
h2, l2 = ax2.get_legend_handles_labels()
ax1.legend(h1+h2, l1+l2)

plt.savefig('img/nice-dif-graph.eps')
plt.show()