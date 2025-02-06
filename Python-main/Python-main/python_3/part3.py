import random
from random import randint
import matplotlib.pyplot as plt
import math


class Points:
    xpk = [[], []]
    ypk = [[], []]
    sumx, sumy = 0, 0

    def prisv(self, n):
        for i in range(n):
            print("Множество ", i+1)
            self.ypk.append([])
            self.xpk.append([])
            print("Введите количество точек в множестве")
            k = int(input())
            for j in range(k):
                self.ypk[i].append(random.randint(-10, 10))
                self.xpk[i].append(random.randint(-10, 10))
            plt.scatter(self.xpk[i], self.ypk[i], color='green')
            plt.show()
            for j in range(k):
                self.sumx = self.sumx + self.xpk[i][j]
                self.sumy = self.sumy + self.ypk[i][j]
            self.sumx = self.sumx//k
            self.sumy = self.sumy//k


class Mink(Points):
    x = []
    y = []
    metr = []
    metr2 = [[], []]
    metr3 = []
    treex1 = []
    treey1 = []
    treex2 = []
    treey2 = []
    treer = []
    sr = 0
    xc = []
    yc = []
    cx = []
    cy = []

    def claster1(self, n):  # метод связных компонент
        for i in range(n):
            for j in range(len(self.xpk[i])):  # занесение сгенерированных точек в рабочий массив
                self.x.append(self.xpk[i][j])
                self.y.append(self.ypk[i][j])
            for j in range(len(self.x)):  # нахождение метрики Минковского
                for k in range(len(self.x)):
                    self.metr.append(math.fabs(self.x[j] - self.x[k]) + math.fabs(self.y[j] - self.y[k]))
            plt.hist(self.metr, bins=100)
            plt.show()
            self.sr = int(input())
            for j in range(len(self.x)):
                if math.fabs(self.x[j] - self.sumx) + math.fabs(self.y[j] - self.sumy) < self.sr:
                    self.xc.append(self.x[j])
                    self.yc.append(self.y[j])
                else:
                    self.cx.append(self.x[j])
                    self.cy.append(self.y[j])
            plt.scatter(self.xc, self.yc, color='red')
            plt.scatter(self.cx, self.cy, color='blue')
            plt.show()
            self.x.clear()
            self.y.clear()
            self.xc.clear()
            self.yc.clear()
            self.cx.clear()
            self.cy.clear()

    def claster2(self):
        for i in range(n):
            for j in range(len(self.xpk[i])):  # занесение сгенерированных точек в рабочий массив
                self.x.append(self.xpk[i][j])
                self.y.append(self.ypk[i][j])
            for j in range(len(self.x)):  # нахождение метрики Минковского
                self.metr2.append([])
                for k in range(len(self.x)):
                    self.metr2[j].append(math.fabs(self.x[j] - self.x[k]) + math.fabs(self.y[j] - self.y[k]))
            k = 0
            for j in range(len(self.x)):
                self.treex1.append(0)
                self.treex2.append(0)
                self.treey1.append(0)
                self.treey2.append(0)
                self.treer.append(0)
            s = 0
            for j in range(len(self.x)):  # получение минимального покрывающего дерева
                minn = 10000
                for m in range(j+1, len(self.x)):
                    if (self.metr2[j][m] < minn) & (self.metr2[j][m] != 0):
                        minn = self.metr2[j][m]
                        self.treex1[s] = self.x[j]
                        self.treex2[s] = self.x[m]
                        self.treey2[s] = self.y[m]
                        self.treey1[s] = self.y[j]
                        self.treer[s] = minn
                s += 1
            plt.plot((self.treex1, self.treex2), (self.treey1, self.treey2))
            plt.show()
            self.treex1[len(self.x)-1] = self.treex2[len(self.x)-2]
            self.treey1[len(self.x)-1] = self.treey2[len(self.x)-2]
            self.treer.append(0)
            maxx = 0.0
            for j in range(len(self.treer)):
                if self.treer[j] > maxx:
                    maxx = self.treer[j]
            for j in range(len(self.x)):
                if self.treer[j] == maxx:
                    flag = j
            for j in range(len(self.x)):
                if flag < j:
                    self.xc.append(self.treex1[j])
                    self.yc.append(self.treey1[j])
                else:
                    self.cx.append(self.treex1[j])
                    self.cy.append(self.treey1[j])
            plt.scatter(self.xc, self.yc, color='red')
            plt.scatter(self.cx, self.cy, color='blue')
            plt.show()
        self.x.clear()
        self.y.clear()
        self.xc.clear()
        self.yc.clear()
        self.cx.clear()
        self.cy.clear()

    def claster3(self):
        sr1 = -5
        sr2 = 5
        for i in range(n):
            for j in range(len(self.xpk[i])):  # занесение сгенерированных точек в рабочий массив
                self.x.append(self.xpk[i][j])
                self.y.append(self.ypk[i][j])
            for j in range(len(self.x)):
                if (math.fabs(self.x[j] - sr1) + math.fabs(self.y[j] - sr1)) <= 7.05:
                    self.xc.append(self.x[j])
                    self.yc.append(self.y[j])
                else:
                    self.cx.append(self.x[j])
                    self.cy.append(self.y[j])
            plt.scatter(self.xc, self.yc, color='red')
            plt.scatter(self.cx, self.cy, color='blue')
            plt.show()
        self.x.clear()
        self.y.clear()
        self.xc.clear()
        self.yc.clear()
        self.cx.clear()
        self.cy.clear()

print("Введите количество множеств")
n = int(input())
p = Points()
p.prisv(n)
print("Метод связных компонент")
m = Mink()
m.claster1(n)
print("Метод минимального покрывающего дерева")
m.claster2()
print("Алгоритм Форель")
m.claster3()
