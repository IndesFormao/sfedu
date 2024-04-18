def get_info(str, number):
    ege = str[number].split(" - ")
    ege[1] = int(str[number].split(" - ")[1])
    return ege

ege2 = ["Математика - 78", "Информатика - 75", "Русский язык - 62"]
lst3=list()
lst4=[]

for i in range(3):
    lst3 += get_info(ege2, i)
    lst4.append(get_info(ege2, i))

print(lst3)
print(lst4)