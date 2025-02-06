import numpy as np
import skfuzzy as fuzz
from skfuzzy import control as ctrl

# создание переменных
service = ctrl.Antecedent(np.arange(0, 11, 1), 'service')
food = ctrl.Antecedent(np.arange(0, 11, 1), 'food')
zal = ctrl.Antecedent(np.arange(0, 11, 1), 'zal')
time = ctrl.Antecedent(np.arange(0, 31, 1), 'time')
money = ctrl.Consequent(np.arange(0, 26, 1), 'money')

# задание отношений
service.automf(3, names=['low', 'middle', 'high'])
service['low'] = fuzz.trimf(np.arange(0, 11, 1), [0, 2, 4])
service['middle'] = fuzz.trimf(np.arange(0, 11, 1), [3, 5, 7])
service['hight'] = fuzz.trimf(np.arange(0, 11, 1), [6, 8, 11])
food.automf(3, names=['bad', 'good'])
food['bad'] = fuzz.trimf(np.arange(0, 11, 1), [0, 3, 6])
food['good'] = fuzz.trimf(np.arange(0, 11, 1), [5, 7, 11])
zal.automf(3, names=['bad', 'normal', 'good'])
zal['bad'] = fuzz.trimf(np.arange(0, 11, 1), [0, 2, 4])
zal['normal'] = fuzz.trimf(np.arange(0, 11, 1), [3, 5, 7])
zal['good'] = fuzz.trimf(np.arange(0, 11, 1), [6, 8, 11])
time.automf(3, names=['bad', 'good'])
time['good'] = fuzz.trimf(np.arange(0, 31, 1), [0, 7, 14])
time['bad'] = fuzz.trimf(np.arange(0, 31, 1), [12, 21, 30])
money.automf(3, names=['low', 'normal', 'high'])
money['low'] = fuzz.trimf(np.arange(0, 26, 1), [0, 5, 10])
money['normal'] = fuzz.trimf(np.arange(0, 26, 1), [9, 14, 19])
money['hight'] = fuzz.trimf(np.arange(0, 26, 1), [18, 21, 25])

# создание правил
rule_low = ctrl.Rule(service['low'] & (food['bad'] | food['good']) & (zal['bad'] | zal['normal'] | zal['good']) & (time['bad'] | time['good']), money['low'])
rule_norm_1 = ctrl.Rule(service['middle'] & (food['bad'] | food['good']) | zal['bad'] & (time['bad'] | time['good']), money['normal'])
rule_norm_2 = ctrl.Rule(service['middle'] & food['bad'] & (zal['normal'] | zal['good']) & (time['bad'] | time['good']), money['normal'])
rule_norm_3 = ctrl.Rule(service['middle'] & food['good'] & (zal['normal'] | zal['good']) & time['bad'], money['normal'])
rule_norm_4 = ctrl.Rule(service['hight'] & food['bad'] & (zal['bad'] | zal['normal'] | zal['good']) & (time['bad'] | time['good']), money['normal'])
rule_norm_5 = ctrl.Rule(service['hight'] & food['good'] & zal['bad'] & (time['good'] | time['bad']), money['normal'])
rule_norm_6 = ctrl.Rule(service['hight'] & food['good'] & (zal['good'] | zal['normal']) & time['bad'], money['normal'])
rule_big = ctrl.Rule((service['middle'] | service['hight']) & food['good'] & (zal['good'] | zal['normal'])& time['good'], money['hight'])

# создание нечёткой системы
fuzzy_system = ctrl.ControlSystem([rule_low, rule_norm_1, rule_norm_2, rule_norm_3, rule_norm_4, rule_norm_5, rule_norm_6, rule_big])
fuzzy_simulation = ctrl.ControlSystemSimulation(fuzzy_system)

# ввод входных данных
print('Введите оценку обслуживания по шкале от 0 до 10, где 0 - ужасно, а 10 - великолепно')
a = int(input())
fuzzy_simulation.input['service'] = a
print('Введите оценку еды по шкале от 0 до 10, где 0 - ужасно, а 10 - великолепно')
b = int(input())
fuzzy_simulation.input['food'] = b
print('Введите оценку атмосферы и чистоты в зале по шкале от 0 до 10, где 0 - ужасно, а 10 - великолепно')
c = int(input())
fuzzy_simulation.input['zal'] = c
print('Введите время ожидания в минутах от 0 до 30')
d = int(input())
fuzzy_simulation.input['time'] = d

# запуск работы системы
fuzzy_simulation.compute()

# получение выходного значения
star_output = fuzzy_simulation.output['money']
print('Процент чаевых: ', round(star_output, 2))
