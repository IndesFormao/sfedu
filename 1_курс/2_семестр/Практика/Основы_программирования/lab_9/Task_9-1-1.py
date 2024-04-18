def get_info(str, number):
    ege = [ str[number].split(" - ")[0], int(str[number].split(" - ")[1]) ]
    return ege

ege2 = ["Математика - 78", "Информатика - 75", "Русский язык - 62"]

for i in range(3):
    ege = get_info(ege2, i)
    print(ege)