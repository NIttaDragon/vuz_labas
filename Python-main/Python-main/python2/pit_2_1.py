import math

class Points:  # точки
    xpk = []
    ypk = []
    ma = [0, 0]
    mi = [0, 0]
    mam, mim = 0, 1000

    def prisv(self, n): # присваивание координат точкам
        for i in range(n):
            print(i+1, "точка")
            print("Введите координату x: ")
            x = int(input())
            self.xpk.append(x)
            print("Введите координату y: ")
            y = int(input())
            self.ypk.append(y)

    def print_kor(self, n): # вывод координат точек
        for i in range(n):
            print(i+1, "точка: (", self.xpk[i], ",", self.ypk[i], ")")

    def ydal(self, n): # поиск наиболее удалённых и ближайших точек
        for i in range(n-1):
            for j in range(i+1, n):
                d = math.sqrt((self.xpk[i] - self.xpk[j]) ** 2 + (self.ypk[i] - self.ypk[j]) ** 2)
                if d > self.mam:
                    self.mam = d
                    self.ma[0] = i
                    self.ma[1] = j
                if d < self.mim:
                    self.mim = d
                    self.mi[0] = i
                    self.mi[1] = j
        print("Ближайшая пара точек", self.mi[0]+1, self.mi[1]+1)
        print("Наиболее удаленная пара точек", self.ma[0]+1, self.ma[1]+1)


class Segments:  # отрезки
    xsk = [[], []]
    ysk = [[], []]
    my_dict = {}

    def prisv(self, n): # присваивание координат точкам отрезков
        for i in range(n):
            self.my_dict[i] = i
            self.xsk.append([])
            self.ysk.append([])
            print(i + 1, "отрезок")
            for j in range(2):
                print("Введите координату x: ")
                x = int(input())
                self.xsk[i].append(x)
                print("Введите координату y: ")
                y = int(input())
                self.ysk[i].append(y)

    def print_kor(self, n): # вывод координат точек отрезков
        for i in range(n):
            print("(", self.xsk[i][0], ",", self.ysk[i][0], ")", ",",
                  "(", self.xsk[i][1], ",", self.ysk[i][1], ")")

    def dlina(self, n): # поиск длинн отрезков
        print("Длины отрезков: ")
        for i in range(n):
            d = math.sqrt((self.xsk[i][1]-self.xsk[i][0])**2+(self.ysk[i][1]-self.ysk[i][0])**2)
            print(d)

    def peres(self, n): # поиск пересекающихся отрезков
        s1, s2, x = 0, 0, 0
        for i in range(n-1):
            for j in range(i+1, n):
                if i != j:
                    x1 = self.xsk[i][0]
                    x2 = self.xsk[i][1]
                    x3 = self.xsk[j][0]
                    x4 = self.xsk[j][1]
                    y1 = self.xsk[i][0]
                    y2 = self.xsk[i][1]
                    y3 = self.xsk[j][0]
                    y4 = self.xsk[j][1]
                    if x1 > x2:
                        x1, x2 = x2, x1
                    if x3 > x4:
                        x3, x4 = x4, x3
                    if y1 == y2:
                        k1 = 0
                    else:
                        k1 = (y2 - y1)/(x2 - x1)
                    if y3 == y4:
                        k2 = 0
                    else:
                        k2 = (y4 - y3)/(x4 - x3)
                    if k1 != k2:
                        b1 = y1 - k1 * x1
                        b2 = y3 - k2 * x3
                        x = (b2 - b1) / (k1 - k2)
                    if ((x1 <= x) and (x <= x2)) or ((x3 <= x) and (x <= x4)):
                        print("Отрезки", self.my_dict[i], "и", self.my_dict[j], "пересекаются")


class Triangles:  # треугольники
    xtk = [[], []]
    ytk = [[], []]

    def prisv(self, n): # присваивание координат точкам треугольников
        for i in range(n):
            self.xtk.append([])
            self.ytk.append([])
            print(i + 1, "треугольник")
            for j in range(3):
                print("Введите координату x: ")
                x = int(input())
                self.xtk[i].append(x)
                print("Введите координату y: ")
                y = int(input())
                self.ytk[i].append(y)

    def print_kor(self, n): # вывод координат точкек треугольников
        for i in range(n):
            print("(", self.xtk[i][0], ",", self.ytk[i][0], ")", ",",
                  "(", self.xtk[i][1], ",", self.ytk[i][1], ")", ",",
                  "(", self.xtk[i][2], ",", self.ytk[i][2], ")")

    def ps(self, n): # поиск площади и периметра треугольников
        print("Периметры и Площади треугольников: ")
        for i in range(n):
            a = math.sqrt((self.xtk[i][1] - self.xtk[i][0]) ** 2 + (self.ytk[i][1] - self.ytk[i][0]) ** 2)
            b = math.sqrt((self.xtk[i][2] - self.xtk[i][1]) ** 2 + (self.ytk[i][2] - self.ytk[i][1]) ** 2)
            c = math.sqrt((self.xtk[i][0] - self.xtk[i][2]) ** 2 + (self.ytk[i][0] - self.ytk[i][2]) ** 2)
            p = a + b + c
            print("Периметр", i+1, "треугольника", p)
            p = p/2
            s = (p*(p-a)*(p-b)*(p-c))**(1/2)
            print("Площадь", i+1, "треугольника", s)


class Relations(Points, Triangles):  # отношения
    tx = [[], []]
    ty = [[], []]
    ss = []
    tty = []
    ttx = []
    ytt = [[], []]
    xtt = [[], []]
    perx = []
    pery = []
    obx = []
    oby = []

    def pris(self, l): # присваивание координат точкам множеств
        for i in range(l):
            self.tx.append([])
            self.ty.append([])
            print("Введите количество точек в множестве", i+1)
            k = int(input())
            print("Введите координаты точек")
            Points.prisv(self, k)
            for j in range(k):
                self.tx[i].append(self.xpk[j])
                self.ty[i].append(self.ypk[j])
            self.xpk.clear()
            self.ypk.clear()

    def per(self, l): # поиск пересечения множеств
        for i in range(l-1):
            for j in range(i+1, l):
                for k in range(len(self.tx[i])):
                    for s in range(len(self.tx[j])):
                        if (self.tx[i][k] == self.tx[j][s]) & (self.ty[i][k] == self.ty[j][s]):
                            self.perx.append(self.tx[j][s])
                            self.pery.append(self.ty[j][s])
        print("Точки пересечения множеств")
        if len(self.perx) != 0:
            for i in range(len(self.perx)):
                print("(", self.perx[i], ",", self.pery[i], ")")
        else:
            print("Таких точек нет")

    def ob(self, l): # поиск объединения множеств
        for i in range(l):
            for j in range(len(self.tx[i])):
                if len(self.perx) != 0:
                    for k in range(len(self.perx)):
                        if (self.tx[i][j] != self.perx[k]) and (self.ty[i][j] != self.pery[k]):
                            self.obx.append(self.tx[i][j])
                            self.oby.append(self.ty[i][j])
                else:
                    self.obx.append(self.tx[i][j])
                    self.oby.append(self.ty[i][j])
        self.obx.extend(self.perx)
        self.oby.extend(self.pery)
        print("Точки объединения множеств")
        for i in range(len(self.obx)):
            print("(", self.obx[i], ",", self.oby[i], ")")

    def pot(self, l, k): # поиск точек, принадлежащих треугольникам
        Triangles.prisv(self, l)
        for i in range(l):
            self.xtt.append([])
            self.ytt.append([])
            for j in range(3):
                self.xtt[i].append(self.xtk[i][j])
                self.ytt[i].append(self.ytk[i][j])
        Points.prisv(self, k)
        for j in range(k):
            self.ttx.append(self.xpk[j])
            self.tty.append(self.ypk[j])
        for i in range(l):
            a = math.sqrt((self.xtt[i][1] - self.xtt[i][0]) ** 2 + (self.ytt[i][1] - self.ytt[i][0]) ** 2)
            b = math.sqrt((self.xtt[i][2] - self.xtt[i][1]) ** 2 + (self.ytt[i][2] - self.ytt[i][1]) ** 2)
            c = math.sqrt((self.xtt[i][0] - self.xtt[i][2]) ** 2 + (self.ytt[i][0] - self.ytt[i][2]) ** 2)
            p = (a + b + c)/2
            s = (p * (p - a) * (p - b) * (p - c)) ** (1 / 2)
            for j in range(k):
                e = math.sqrt((self.xtt[i][0] - self.ttx[j]) ** 2 + (self.ytt[i][0] - self.tty[j]) ** 2)
                d = math.sqrt((self.xtt[i][1] - self.ttx[j]) ** 2 + (self.ytt[i][1] - self.tty[j]) ** 2)
                f = math.sqrt((self.xtt[i][2] - self.ttx[j]) ** 2 + (self.ytt[i][2] - self.tty[j]) ** 2)
                p = a + d + e
                if p <= 0:
                    p = 0
                else:
                    p = p // 2
                self.ss.append(math.sqrt(p * abs(p - a) * abs(p - d) * abs(p - e)))
                p = e + b + f
                if p <= 0:
                    p = 0
                else:
                    p = p // 2
                self.ss.append(math.sqrt(p * abs(p - e) * abs(p - b) * abs(p - f)))
                p = d + f + c
                if p <= 0:
                    p = 0
                else:
                    p = p // 2
                self.ss.append(math.sqrt(p * abs(p - d) * abs(p - f) * abs(p - c)))
                if s-(self.ss[0]+self.ss[1]+self.ss[2]) <= 0.01:
                    print("Точка (", self.ttx[j], ",", self.tty[j], ") принадлежит треугольнику ", i+1)
                self.ss.clear()
        self.xtk.clear()
        self.ytk.clear()
        self.xpk.clear()
        self.ypk.clear()


print("---------------------------------------------------------------")
print("Заполнения класса Points")
print("Введите количесво точек n: ")
n = int(input())
p = Points()
p.prisv(n)
p.print_kor(n)
p.ydal(n)
print("---------------------------------------------------------------")
print("Заполнения класса Segments")
print("Введите количесво отрезков n: ")
n = int(input())
s = Segments()
s.prisv(n)
s.print_kor(n)
s.dlina(n)
s.peres(n)
print("---------------------------------------------------------------")
print("Заполнения класса Triangles")
print("Введите количесво треугольников n: ")
n = int(input())
t = Triangles()
t.prisv(n)
t.print_kor(n)
t.ps(n)
print("---------------------------------------------------------------")
print("Создание класса Relations")
print("Работа с точками")
print("Введите количество множеств для анализа")
l = int(input())
r = Relations()
r.pris(l)
r.per(l)r.ob(l)
print("Работа с треугольниками")
print("Введите количество трегольников")
l = int(input())
print("Введите количество точек, для которых вы хотите проверить принадлежность")
k = int(input())
r.pot(l, k)
