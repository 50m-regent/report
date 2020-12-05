import numpy as np
from scipy.integrate import odeint
import matplotlib.pyplot as plt

def f(x, t):
    return (x[1], 0.09375 - 0.08125 * x[0] - 0.18781 * x[1])

x0 = [0, 0]
t = np.linspace(0, 80, 1000)
y = odeint(f, x0, t)

fig = plt.figure()
s1 = fig.add_subplot(2, 1, 1)
s2 = fig.add_subplot(2, 1, 2)

s2.plot(
    t, y[:,[0]],
    color='k'
)
s2.set_xlabel('t[s]')
s2.set_xlim([0, 80])
s2.set_ylabel('x[cm]       ', rotation=0)
s2.set_ylim([0, 1.6])

s1.plot(
    t, y[:,[1]],
    color='k'
)
s1.set_xlabel('t[s]')
s1.set_xlim([0, 80])
s1.set_ylabel('v[cm/s]', rotation=0)
s1.set_ylim([-0.1, 0.25])

plt.show()