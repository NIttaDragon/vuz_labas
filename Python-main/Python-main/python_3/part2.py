import matplotlib.pyplot as plt
import math

class Points:
    x = []
    y = []

    def prisv(self):
        for i in range(2):
            print("Введите точку")
            self.x.append(int(input()))
            self.y.append(int(input()))
        m = math.fabs(self.x[0] - self.x[1]) + math.fabs(self.y[0] - self.y[1])
        print("Метрика Минковского", m)
        plt.plot(self.x, self.y, linestyle='--')
        plt.show()


print("Введите параметр p >= 1")
r = int(input())
if r >= 1:
    p = Points()
    p.prisv()
else:
    print("Неправильно введен параметр р")
