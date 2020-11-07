import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

v = np.array([
    [1, 5, 8],
    [3, 7, -2]
])

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

ax.quiver(0, 0, 0, v[0][0], v[0][1], v[0][2], normalize=True)
ax.quiver(0, 0, 0, v[1][0], v[1][1], v[1][2])
ax.set_xlim([0, 3])
ax.set_ylim([0, 7])
ax.set_zlim([-2, 8])

plt.show()