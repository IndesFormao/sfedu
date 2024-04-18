def get_tested(ege, subject, number):
    ege = ege.lower()
    subject = subject[number].lower()
    if ege.find(subject)!=-1:
        return True
    else:
        return False

ege1 = "Математика — 78, Информатика — 75, Русский язык — 62"
subjects = ['русский язык','информатика','физика','математика','история','обществознание']
for number in range(len(subjects)):
    print(f'ЕГЭ по дисциплине {subjects[number]}{'' if get_tested(ege1, subjects, number) else ' не'} сдан')