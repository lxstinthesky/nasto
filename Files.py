def get_cols(file):
    x = []
    y = []
    p = []
    u = []
    v = []
    for line in file:
        x.append(float(line.split(";")[0]))
        y.append(float(line.split(";")[1]))
        p.append(float(line.split(";")[2]))
        u.append(float(line.split(";")[3]))
        v.append(float(line.split(";")[4].split("\n")[0]))
    return x, y, p, u, v


def offset(vector, off):
    for i in range(len(vector)):
        vector[i] = vector[i] + off
    return vector


class Solution:
    def __init__(self, path):
        self.file = open(path, "r")
        self.x, self.y, self.p, self.u, self.v = get_cols(self.file)
