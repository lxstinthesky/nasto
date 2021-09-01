from Files import Solution
import matplotlib.pyplot as plt
import numpy as np

data = Solution("cmake-build-debug//data.dat")

skip=(slice(None,None,1))
nrm = plt.Normalize(vmax=100)

color=[]
for x in data.p:
    color.append(x)

#nrm.autoscale(data.p)
plt.scatter(data.x, data.y, c=color, cmap="GnBu")
plt.show()
plt.quiver(data.x[skip], data.y[skip], data.u[skip], data.v[skip])


plt.show()

