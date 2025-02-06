import random
from random import randint
import matplotlib.pyplot as plt


class Points:
    xpk = [[], []]
    ypk = [[], []]

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


print("Введите количество множеств")
n = int(input())
p = Points()
p.prisv(n)
