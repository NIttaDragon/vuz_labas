# подключение используемых библиотек
import numpy as np
import skfuzzy as fuzz
from skfuzzy import control as ctrl
import matplotlib

# задание значений переменных для подсчёта степеней принадлежностей
price = np.arange(0, 91, 1)
herz = np.arange(0, 3, 1)
star = np.arange(0, 5, 1)

# задание диапазонов
price_low = fuzz.trimf(price, [29, 45, 61])
price_hight = fuzz.trimf(price, [49, 90, 91])
herz_low = fuzz.trimf(herz, [1.5, 1.5, 3])
herz_hight = fuzz.trimf(herz, [1.5, 3, 3])
star_low = fuzz.trimf(star, [0, 1.5, 3])
star_hight = fuzz.trimf(star, [2, 3.5, 5])
star_normal_1 = fuzz.trimf(star, [1, 2, 3])
star_normal_2 = fuzz.trimf(star, [2, 3, 4])

# создание лейблов переменных
price_ctrl = ctrl.Antecedent(price, 'price')
herz_ctrl = ctrl.Antecedent(herz, 'herz')
star_ctrl = ctrl.Consequent(star, 'star')

# создание элементов правил
price_ctrl['price_low'] = price_low
price_ctrl['price_hight'] = price_hight
herz_ctrl['herz_low'] = herz_low
herz_ctrl['herz_hight'] = herz_hight
star_ctrl['star_low'] = star_low
star_ctrl['star_hight'] = star_hight
star_ctrl['star_norm_1'] = star_normal_1
star_ctrl['star_norm_2'] = star_normal_2

# задание правил
rule_good = ctrl.Rule(antecedent=(price_ctrl['price_low'] & herz_ctrl['herz_hight']), consequent=star_ctrl['star_hight'])
rule_bad = ctrl.Rule(antecedent=(price_ctrl['price_hight'] & herz_ctrl['herz_low']), consequent=star_ctrl['star_low'])
rule_norm_1 = ctrl.Rule(antecedent=(price_ctrl['price_low'] & herz_ctrl['herz_low']), consequent=star_ctrl['star_norm_1'])
rule_norm_2 = ctrl.Rule(antecedent=(price_ctrl['price_hight'] & herz_ctrl['herz_hight']), consequent=star_ctrl['star_norm_2'])

# создание нечёткой системы
fuzzy_system = ctrl.ControlSystem([rule_good, rule_bad, rule_norm_1, rule_norm_2])
fuzzy_simulation = ctrl.ControlSystemSimulation(fuzzy_system)

# ввод начальных значений
print('Enter PC price in interval (30-90)')
a = int(input())
fuzzy_simulation.input['price'] = a
print('Enter PC Herz in interval (1-3)')
b = int(input())
fuzzy_simulation.input['herz'] = b

# запуск системы
fuzzy_simulation.compute()

# вывод выходного значения
star_output = fuzzy_simulation.output['star']
print(star_output)
