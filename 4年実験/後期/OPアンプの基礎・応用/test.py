import numpy as np
import matplotlib.pyplot as plt
from control.matlab import  *

n = [1]
d = [10]
P = tf(n, d)
bode(P)
plt.show()