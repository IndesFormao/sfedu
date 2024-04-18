def subjects(ege):
    subjects_list = []
    for i in ege:
        subjects_list.append(i.split(" - ")[0])
    return subjects_list

def marks(ege):
    subjects_list = []
    for i in ege:
        subjects_list.append(int(i.split(" - ")[1]))
    return subjects_list

def print_results(subjects, marks):
    for i in range(3):
        print(f"{subjects[i]} - {marks[i]}")
    print(f"Сумма баллов: {sum(marks)}")   

ege2 = ["Математика - 78", "Информатика - 75", "Русский язык - 62"]

print_results(subjects(ege2), marks(ege2))
