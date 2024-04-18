def convert_list14(ege):
    ege = ege1.split(',')
    ege2=[]
    for i in range(len(ege)):
        ege2.append(ege[i].strip())
    # получено ege2 ^^^^
    ege4 = []
    for j in range(len(ege)):
        ege4.append([ege2[j].split(' - ')[0], int(ege2[j].split(' - ')[1])])
    return ege4

ege1 = "Математика - 78,           Информатика - 75,  Русский язык - 62"
ege_new = convert_list14(ege1)
print(ege_new)