import random
from random import randint
import matplotlib.pyplot as plt
import math


class Points:
    xpk = [[], []]
    ypk = [[], []]
    metr1 = [[], []]
    metr2 = [[], []]

    def prisv(self):
        for i in range(2):
            self.ypk.append([])
            self.xpk.append([])
            k = 10
            if i > 0:
                for j in range(k):
                    self.ypk[i].append(random.randint(-5, 0))
                    self.xpk[i].append(random.randint(-5, 0))
            else:
                for j in range(k):
                    self.ypk[i].append(random.randint(0, 5))
                    self.xpk[i].append(random.randint(0, 5))
        plt.scatter(self.xpk[0], self.ypk[0], color='green')
        plt.scatter(self.xpk[1], self.ypk[1], color='red')
        plt.show()

    def new_dot(self):  # метод ближнего соседа
        print("Введите новую точку")
        x = int(input("координата х: "))
        y = int(input("координата у: "))
        for j in range(len(self.xpk[0])):  # нахождение метрики Минковского
            self.metr1.append([])
            self.metr1[j].append(math.fabs(x - self.xpk[0][j]) + math.fabs(y - self.ypk[0][j]))
        for j in range(len(self.xpk[1])):  # нахождение метрики Минковского
            self.metr2.append([])
            self.metr2[j].append(math.fabs(x - self.xpk[1][j]) + math.fabs(y - self.ypk[1][j]))
        for i in range(9):
            for j in range(9-i):
                if self.metr1[j][0] > self.metr1[j+1][0]:
                    self.metr1[j][0], self.metr1[j+1][0] = self.metr1[j+1][0], self.metr1[j][0]
        for i in range(9):
            for j in range(9-i):
                if self.metr2[j][0] > self.metr2[j+1][0]:
                    self.metr2[j][0], self.metr2[j+1][0] = self.metr2[j+1][0], self.metr2[j][0]
        m1, m2 = 0, 0
        for i in range(5):
            if self.metr1[i][0] > self.metr2[i][0]:
                m2 += 1
            else:
                m1 += 1
        if m1 > m2:
            self.xpk[0].append(x)
            self.ypk[0].append(y)
        else:
            self.xpk[1].append(x)
            self.ypk[1].append(y)
        plt.scatter(self.xpk[0], self.ypk[0], color='green')
        plt.scatter(self.xpk[1], self.ypk[1], color='red')
        plt.show()


p = Points()
p.prisv()
p.new_dot()
