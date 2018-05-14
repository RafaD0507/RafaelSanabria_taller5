import matplotlib.pyplot as plt
import numpy as np

v = np.loadtxt('datos.txt')
plt.imshow(v, )
plt.savefig("placas.pdf")
