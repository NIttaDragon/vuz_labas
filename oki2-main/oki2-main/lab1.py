import numpy as np


class Actions:
    def kronk(self, ak, bk):
        ab1 = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
        t = []
        for i in range(2):
            for j in range(2):
                for k in range(2):
                    for l in range(2):
                        t.append(ak[i][j]*bk[k][l])
        k = 0
        for i in range(2):
            for j in range(2):
                ab1[i][j] = t[k]
                k = k+1
        for i in range(2):
            for j in range(2, 4):
                ab1[i][j] = t[k]
                k = k + 1
        for i in range(2, 4):
            for j in range(2):
                ab1[i][j] = t[k]
                k = k + 1
        for i in range(2, 4):
            for j in range(2, 4):
                ab1[i][j] = t[k]
                k = k + 1
        return ab1

    def multy(self, am, bm):
        ab2 = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
        for k in range(4):
            for i in range(4):
                for j in range(4):
                    ab2[i][j] = ab2[i][j] + am[i][k]*bm[k][j]
        return ab2


class Gates(Actions):
    g = [[1, 0], [0, 1]]  # матрица полученного кубита
    ng = [[0, 0], [0, 0]]  # матрица Not гейт
    ag = [[1, 1], [1, -1]]  # матрица гейта Адамара
    cng = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]  # матрица cnot гейта
    sg = [[], []]  # матрица swap гейта
    oz = [[1, 0], [0, 0]]
    zo = [[0, 0], [0, 1]]

    def opr(self):
        for i in range(2):
            print(self.g[i])
        if self.g[0][0] == 1 and self.g[1][0] == 1:
            self.ng[0][0] = 0
            self.ng[0][1] = 1
            self.ng[1][0] = 0
            self.ng[1][1] = 1
        elif self.g[0][0] == 1 and self.g[1][0] == 0:
            self.ng[0][0] = 0
            self.ng[0][1] = 1
            self.ng[1][0] = 1
            self.ng[1][1] = 0
        elif self.g[0][0] == 0 and self.g[1][0] == 1:
            self.ng[0][0] = 1
            self.ng[0][1] = 0
            self.ng[1][0] = 0
            self.ng[1][1] = 1
        else:
            self.ng[0][0] = 1
            self.ng[0][1] = 0
            self.ng[1][0] = 1
            self.ng[1][1] = 0
        print("Not гейт")
        for i in range(2):
            print(self.ng[i])

    def adamarg(self):
        for i in range(2):
            print(self.ag[i])
        print("* 1/sqrt(2)")

    def cnotg(self):
        a = self.oz
        b = self.g
        c = self.ng
        d = self.zo
        cng1 = Actions.kronk(self, a, b)
        cng2 = Actions.kronk(self, d, c)
        for i in range(4):
            for j in range(4):
                self.cng[i][j] = cng1[i][j] + cng2[i][j]
        for i in range(4):
            print(self.cng[i])

    def swapg(self):
        for i in range(4):
            self.sg.append([])
            for j in range(4):
                if i == j:
                    self.sg[i].append(1)
                else:
                    self.sg[i].append(0)
        self.sg[1][1], self.sg[2][1] = self.sg[2][1], self.sg[1][1]
        self.sg[1][2], self.sg[2][2] = self.sg[2][2], self.sg[1][2]
        for i in range(4):
            print(self.sg[i])

    def prob(self):
        a = self.cng
        b = self.sg
        t = Actions.multy(self, a, b)
        for i in range(4):
            print(t[i])


print("Класс Gates")
gate = Gates()
print("Матричное представление кубита")
gate.opr()
print("Гейт Адамара")
gate.adamarg()
print("Cnot гейт")
gate.cnotg()
print("Swap гейт")
gate.swapg()
print("Применение умножения из класса Actions на гейтах  Cnot и Swap")
gate.prob()
