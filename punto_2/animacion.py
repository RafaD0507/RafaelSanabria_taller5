import matplotlib.pyplot as plt
import numpy as np
import matplotlib.animation as animation

fig, ax = plt.subplots()

ims = np.loadtxt("datos.txt")

grafica = []

x = ims[:,0]
for i in range(1, len(ims[0])):
	grafica.append(list(ims[:,i]))

linea, = ax.plot(x, grafica[0])

def animar(i):
	linea.set_ydata(grafica[i])
	return linea

ax.axis((0,100,-1,1))
plt.title("Posicion con respecto al punto de equilibrio en el tiempo")
plt.xlabel("x")
plt.ylabel('Desplazamiento')
ani = animation.FuncAnimation(fig, animar, np.arange(1, 200), interval=80)

ani.save('cuerda.gif', writer='imagemagick', fps=10)

