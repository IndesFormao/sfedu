print('ЗАДАНИЕ 2. ЧАСТЬ 1')
mark1=['хорошо','удовлетворительно']
print(mark1)
print(id(mark1))
print()
mark1.append("неудовлетворительно")
mark1.insert(0, "отлично")
print()
print(mark1[0:3])
print()
print('ЗАДАНИЕ 2. ЧАСТЬ 2')
mark2=['чётный','нечётный']
print(mark2)
print(id(mark2))
print()
mark3=mark2*2
print(mark2)
print(id(mark2))
print(mark3)
print(id(mark3))
