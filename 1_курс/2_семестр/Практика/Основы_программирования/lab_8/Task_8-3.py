def total(ege):
    return ege[0]+ege[1]+ege[2]

def total2(ege3):
    return ege3[1]+ege3[3]+ege3[5]

def convert_list(ege3):
    return [ ege3[0:2], ege3[2:4], ege3[4:6] ]

print('ЗАДАНИЕ 3. ЧАСТЬ 1')
ege4 = [ ["Математика", 78], ["Информатика", 75], ["Русский язык", 62] ]
print(ege4[1][0])
ege=[ ege4[0][1], ege4[1][1], ege4[2][1] ]
summ=total(ege)
print("Общая сумма баллов %i"%summ)

print('\nЗАДАНИЕ 3. ЧАСТЬ 2')
ege3 = [ "Математика", 78, "Информатика", 75, "Русский язык", 62 ]
summ2=total2(ege3)
print("Общая сумма баллов %i"%summ2)
ege_new=convert_list(ege3)
ege=[ ege_new[0][1], ege_new[1][1], ege_new[2][1] ]
summ3=total(ege)
print("Общая сумма баллов %i"%summ3)
