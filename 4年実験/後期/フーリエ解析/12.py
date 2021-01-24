import matplotlib.pyplot as plt
import numpy as np
import random as rand

t = np.linspace(0, np.pi * 2, 6)
f = np.sin(t)
plt.scatter(t, f, color="red", zorder=10)

t = np.linspace(0, np.pi * 2, 10000)
y = np.sin(t)
plt.plot(t, y, label='$\sin t$')

y = np.sin(6 * t)
plt.plot(t, y, label='$\sin (6t)$')

plt.xlabel("$t$")
plt.xticks([0, np.pi / 2, np.pi, np.pi * 3 / 2, np.pi * 2], ["0", "$0.5\pi$", "$\pi$", "$1.5\pi$", "$2\pi$"])
plt.legend()
plt.savefig("img/12.eps")