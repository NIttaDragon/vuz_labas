class Doich:
    g = [[1, 0], [0, 1]]  # матрица полученного кубита
    ng = [[0, 1], [1, 0]]  # матрица Not гейта
    ag = [[1, 1], [1, -1]]  # матрица гейта Адамара
    cng = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 0, 1], [0, 0, 1, 0]]

    def fun1(self):
        def kronk(ak, bk):
            ab1 = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
            t = []
            for i in range(2):
                for j in range(2):
                    for k in range(2):
                        for l in range(2):
                            t.append(ak[i][j] * bk[k][l])
            k = 0
            for i in range(2):
                for j in range(2):
                    ab1[i][j] = t[k]
                    k = k + 1
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

        def multy(am, bm):
            ab2 = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
            for k in range(4):
                for i in range(4):
                    for j in range(4):
                        ab2[i][j] = ab2[i][j] + am[i][k] * bm[k][j]
            return ab2

        a = self.g
        b = self.ag
        ge = [0, 1, 0, 0]
        i = kronk(b, a)
        f = kronk(a, a)
        f1 = multy(i, f)
        h = kronk(b, b)
        f1 = multy(f1, h)
        f11 = [0, 0, 0, 0]
        for i in range(4):
            f11[i] = f1[i][0] * ge[0] + f1[i][1] * ge[1] + f1[i][2] * ge[2] + f1[i][3] * ge[3]
        for i in range(4):
            if f11[i] != 0:
                f11[i] = f11[i] // 2
        print("f1", f11)

    def fun2(self):
        def kronk(ak, bk):
            ab1 = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
            t = []
            for i in range(2):
                for j in range(2):
                    for k in range(2):
                        for l in range(2):
                            t.append(ak[i][j] * bk[k][l])
            k = 0
            for i in range(2):
                for j in range(2):
                    ab1[i][j] = t[k]
                    k = k + 1
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

        def multy(am, bm):
            ab2 = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
            for k in range(4):
                for i in range(4):
                    for j in range(4):
                        ab2[i][j] = ab2[i][j] + am[i][k] * bm[k][j]
            return ab2

        a = self.g
        b = self.ag
        c = self.ng
        ge = [0, 1, 0, 0]
        i = kronk(b, a)
        f = kronk(a, c)
        f2 = multy(i, f)
        h = kronk(b, b)
        f2 = multy(f2, h)
        f22 = [0, 0, 0, 0]
        for i in range(4):
            f22[i] = f2[i][0] * ge[0] + f2[i][1] * ge[1] + f2[i][2] * ge[2] + f2[i][3] * ge[3]
        for i in range(4):
            if f22[i] != 0:
                f22[i] = f22[i] // 2
        print("f2", f22)

    def fun3(self):
        def kronk(ak, bk):
            ab1 = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
            t = []
            for i in range(2):
                for j in range(2):
                    for k in range(2):
                        for l in range(2):
                            t.append(ak[i][j] * bk[k][l])
            k = 0
            for i in range(2):
                for j in range(2):
                    ab1[i][j] = t[k]
                    k = k + 1
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

        def multy(am, bm):
            ab2 = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
            for k in range(4):
                for i in range(4):
                    for j in range(4):
                        ab2[i][j] = ab2[i][j] + am[i][k] * bm[k][j]
            return ab2
        a = self.g
        b = self.ag
        ge = [0, 1, 0, 0]
        i = kronk(b, a)
        f = self.cng
        f3 = multy(i, f)
        h = kronk(b, b)
        f3 = multy(f3, h)
        f33 = [0, 0, 0, 0]
        for i in range(4):
            f33[i] = f3[i][0] * ge[0] + f3[i][1] * ge[1] + f3[i][2] * ge[2] + f3[i][3] * ge[3]
        for i in range(4):
            if f33[i] != 0:
                f33[i] = f33[i] // 2
        print("f3", f33)

    def fun4(self):
        def kronk(ak, bk):
            ab1 = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
            t = []
            for i in range(2):
                for j in range(2):
                    for k in range(2):
                        for l in range(2):
                            t.append(ak[i][j] * bk[k][l])
            k = 0
            for i in range(2):
                for j in range(2):
                    ab1[i][j] = t[k]
                    k = k + 1
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

        def multy(am, bm):
            ab2 = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
            for k in range(4):
                for i in range(4):
                    for j in range(4):
                        ab2[i][j] = ab2[i][j] + am[i][k] * bm[k][j]
            return ab2
        a = self.g
        b = self.ag
        c = self.ng
        d = self.cng
        ge = [0, 1, 0, 0]
        i = kronk(b, a)
        f = kronk(i, c)
        f = multy(d, f)
        f4 = multy(i, f)
        h = kronk(b, b)
        f4 = multy(f4, h)
        f44 = [0, 0, 0, 0]
        for i in range(4):
            f44[i] = f4[i][0] * ge[0] + f4[i][1] * ge[1] + f4[i][2] * ge[2] + f4[i][3] * ge[3]
        for i in range(4):
            if f44[i] != 0:
                f44[i] = f44[i] // 2
        print("f4", f44)


print("Класс Doich")
do = Doich()
print("Константный 0")
do.fun1()
print("Константная 1")
do.fun2()
print("Само значение")
do.fun3()
print("Обратное значение")
do.fun4()
