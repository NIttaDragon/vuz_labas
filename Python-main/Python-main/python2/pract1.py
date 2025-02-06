class MyClass():
    def __init__(self):
        self.x = 10
    def print_x(self):
        print(self.x)

c = MyClass()
#c.print_x()
print(c.x)
#getattr(c,"x")
#setattr(c,"x",20)
#delattr(c, "x")
#hasattr(c,"x")
print("---------------------------------------------------------------")
class Myclass():
    pass
Myclass.x = 50
c1, c2 = Myclass(), Myclass()
c1.y = 10
c2.y = 20
print(c1.x, c1.y)
print(c2.x, c2.y)
print("---------------------------------------------------------------")
class Mmy:
    x = 10
    def __int__(self):
        self.y = 20
Mmy.x = 30 #изменение атрибута х у всех объектов класса
c3 = Mmy()
#c3.x=10
c3.y = 40
print(c3.x, c3.y)
print("----------------------- Наследование -----------------------------")
class Class1: #базовый класс
    def func1(self):
        print("Метод func1 класса Class1")
    def func2(self):
        print("Метод func2 класса Class1")
class Class2(Class1):
    def func3(self):
        print("Метод func3 класса Class2")
c4 = Class2()
c4.func1()
c4.func2()
c4.func3()
print("---------------------------------------------------------------")
class Class3:
    def __init__(self):
        print('Конструктор базового класса')
    def func1(self):
        print("Метод func1 класса Class3")
class Class4(Class3):
    def __init__(self):
        Class3.__init__(self)
        print("Конструктор производного класса")
    def func1(self):
        print("Метод func1 класса Class4")
        Class3.func1(self)
c = Class4()
c.func1()
c = Class4()
c.func1
print("---------------------------------------------------------------")
#другой способ
#super()
#Class.__init__(self)
#super().__init__()
print("------------------- Множественное наследование ----------------------")
class Clas1:
    def func1(self):
        print("Метод func1 класса Clas1")
class Clas2(Clas1):
    def func2(self):
        print("Метод func2 класса Clas2")
class Clas3(Clas1):
    def func3(self):
        print("Метод func3 класса Clas3")
    def func4(self):
        print("Метод func4 класса Clas3")
class Clas4(Clas2,Clas3):
    def func4(self):
        print("Метод func4 класса Clas4")

c5 = Clas4()
c5.func1()
c5.func2()
c5.func3()
c5.func4()
#c5.func5()
x1 = 3
#print(x1.__dict__())
print(Clas1.__bases__)
