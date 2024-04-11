def get_info(number):
    list = [ ege2[number].split(" - ")[0], int(ege2[number].split(" - ")[1])]
    return list

ege2 = [ "Математика - 78", "Информатика - 75", "Русский язык - 62" ]
subjects=[]
marks=[]

for number in range(3):
    aboba = get_info(number)
    subjects.append(aboba[0])
    marks.append(aboba[1])

for i in range(3):
    print(subjects[i] + ' - ' + str(marks[i]))
print('Сумма баллов: ' + str(sum(marks)))