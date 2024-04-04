print('ЗАДАНИЕ 1. ЧАСТЬ 1')
my_list=["победа","ничья","поражение"]
print(type(my_list))
print(len(my_list))
print(my_list[1])
print(id(my_list[0]))
print(id(my_list[1]))
print(id(my_list[2]))
print(id(my_list))
input()

print('ЗАДАНИЕ 1. ЧАСТЬ 2')
empty_list=[]
print(type(empty_list))
print(len(empty_list))
print()
print('пустой' if len(empty_list) else 'не пустой')
print()
square_list=[ [], [] ]
print(type(square_list))
print(len(square_list))
print('одинаковые' if id(square_list[0])==id(square_list[1]) else 'разные')
