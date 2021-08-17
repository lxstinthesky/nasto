def get_cols(file):
    t = []
    x = []
    y = []
    z = []
    for line in file:
        t.append(float(line.split(",")[0]))
        x.append(float(line.split(",")[1]))
        #y.append(float(line.split(" ")[2]))
        #z.append(float(line.split(";")[3]))
    return t, x, y, z


def offset(vector, off):
    for i in range(len(vector)):
        vector[i] = vector[i] + off
    return vector


class Solution:
    def __init__(self, path):
        self.file = open(path, "r")
        self.t, self.x, self.y, self.z = get_cols(self.file)
