import pandas as pd
import torch
import torch.nn as nn
import torch.optim as opt
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Чтение файла train.csv и выбор столбцов ABCE
data_tr = pd.read_csv('train1.csv', usecols=['A', 'B', 'C', 'E'])

# Преобразование столбцов в массивы (списки)
array_Atr = data_tr['A'].tolist()
array_Btr = data_tr['B'].tolist()
array_Ctr = data_tr['C'].tolist()
array_Etr = data_tr['E'].tolist()

X_train = torch.tensor([array_Atr, array_Btr, array_Ctr])
Y_train = torch.tensor(array_Etr)

# Чтение файла train.csv и выбор столбцов ABCE
data_ts = pd.read_csv('test1.csv', usecols=['A', 'B', 'C', 'E'])

# Преобразование столбцов в массивы (списки)
array_Ats = data_ts['A'].tolist()
array_Bts = data_ts['B'].tolist()
array_Cts = data_ts['C'].tolist()
array_Ets = data_ts['E'].tolist()

X_test = torch.tensor([array_Ats, array_Bts, array_Cts])
Y_test = torch.tensor(array_Ets)

# создание и описание класса нейросети
class NeuralNetwork(nn.Module):
    def __init__(self, neurons):
        super(NeuralNetwork, self).__init__()
        self.fc1 = torch.nn.Linear(3, neurons)
        self.act1 = torch.nn.Tanh()
        self.fc2 = torch.nn.Linear(neurons, neurons)
        self.act2 = torch.nn.Tanh()
        self.fc3 = torch.nn.Linear(neurons, 1)

    def forward(self, x):
        x = self.fc1(x)
        x = self.act1(x)
        x = self.fc2(x)
        x = self.act2(x)
        x = self.fc3(x)
        return x

def getAccuracy(model, xTest, yTest):
    yPred = model(xTest)
    n = int(yPred.shape[0])
    acc = 0.0
    for i in range(n):
        acc += (yPred[i].round() == yTest[i].round()).sum()
        print(yPred[i].detach().item(), yTest[i].detach().item())
    return acc.detach().item()/n

def displayPoints(net, x, y):
    fig = plt.figure()
    ax = fig.add_subplot(121, projection = '3d')
    yPred = net.forward(x)
    x1 = x[1]
    x2 = x[2]
    x3 = x[3]
    y0 = y
    img1 = ax.scatter(x1, x2, x3, c=y0)
    fig.colorbar(img1)
    ax = fig.add_subplot(122, projection='3d')
    y1 = yPred[:,0]
    print(y1)
    img2 = ax.scatter(x1, x2, x3, c=y1.detach().numpy())
    fig.colorbar(img2)
    plt.show()

model = NeuralNetwork(150)
criterion = nn.MSELoss()
optimizer = opt.Adam(model.parameters(), lr=0.01)

for i in range(5000):
    optimizer.zero_grad()
    yPred = model.forward(X_train)
    loss = criterion(yPred, Y_train)
    loss.backward()
    optimizer.step()

model.eval()
displayPoints(model, X_test, Y_test)
acc = getAccuracy(model, X_test, Y_test)
print(f"Средняя ошибка: No, \t Точность: {acc}")
