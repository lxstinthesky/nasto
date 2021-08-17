from Files import Solution
import matplotlib.pyplot as plt
import numpy as np

data = Solution("cmake-build-debug//spiral.dat")

for line in data:
    print(line)

plt.scatter(data.t, data.x, c=data.y, marker=",")
plt.plot(1, 0, "mx", label="Magnet 1")

plt.show()

