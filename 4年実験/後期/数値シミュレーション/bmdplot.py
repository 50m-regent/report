import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import odeint

def x(t):
    return 1.154 * (1 - np.exp(-0.0939 * t) * np.cos(0.2691 * t))

def v(t):
    # return 1.154 * np.exp(-0.0939 * t) * (0.2691 * np.sin(0.2691 * t) + 0.0939 * np.cos(0.2691 * t))
    return 0.3483 * np.exp(-0.0939 * t) * np.sin(0.2691 * t)

def vf(t):
    return 1.154 * np.exp(-0.0939 * t) * (0.2691 * np.sin(0.2691 * t) + 0.0939 * np.cos(0.2691 * t))

t = np.linspace(0, 80, 1000)

plt.plot(
    t, x(t),
    color='k'
)
plt.xlabel('t[s]')
plt.ylabel('x[cm]   ', rotation=0)
plt.ylim([1.525, 1.565])
plt.xlim([10, 12])
plt.show()

fig = plt.figure()
s1 = fig.add_subplot(2, 1, 1)
s2 = fig.add_subplot(2, 1, 2)

for dt in t:
    print('{:5f} {:5f}'.format(x(dt), v(dt)))

s2.plot(
    t, x(t),
    color='k'
)
s2.set_xlabel('t[s]')
s2.set_xlim([0, 80])
s2.set_ylabel('x[cm]       ', rotation=0)
s2.set_ylim([0, 1.6])

s1.plot(
    t, v(t),
    color='k'
)
s1.set_xlabel('t[s]')
s1.set_xlim([0, 80])
s1.set_ylabel('v[cm/s]', rotation=0)
s1.set_ylim([-0.1, 0.25])
plt.show()