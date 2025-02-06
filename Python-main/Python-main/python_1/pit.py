a = []
b = [[], []]
mi = []
ma = []
sushu = []
s = []


def nodk(a, n, s):
    for i in range(n):
        b.append([])
        for j in range(len(s)):
            if a[i] % s[j] == 0:
                k = 0
                while a[i] % s[j] == 0:
                    a[i] = a[i] / s[j]
                    k = k + 1
                b[i].append(k)
            else:
                k = 0
                b[i].append(k)
    for i in range(len(s)):
        mi.append(100)
        ma.append(0)
    for i in range(n):
        for j in range(len(s)):
            if b[i][j] < mi[j]:
                mi[j] = b[i][j]
            if b[i][j] > ma[j]:
                ma[j] = b[i][j]
    p, x = 1, 1
    for i in range(len(s)):
        mi[i] = sushu[i]**mi[i]
        ma[i] = sushu[i]**ma[i]
        p = p * mi[i]
        x = x * ma[i]
    print('NOD = ', p)
    print('NOK = ', x)


print("n = ")
n = int(input())
maxa = 0
for i in range(n):
    print("a = ")
    t = int(input())
    a.append(t)
    if t > maxa:
        maxa = t
sushu.append(2)
for i in range(maxa):
    for j in range(2, i):
        if i % j == 0:
            break
        else:
            sushu.append(i)
s = [i for n, i in enumerate(sushu) if i not in sushu[:n]]
nodk(a, n, s)
