def get_tested(ege, subject, number):
    ege = ege.lower()
    print(ege)
    subject = subject[number].lower()
    print(subject)
    if ege.find(subject)!=-1:
        return True
    else:
        return False

ege1 = "Математика — 78, Информатика — 75, Русский язык — 62"
subjects = ['русский язык','информатика','физика','математика','история','обществознание']
for i in range(len(subjects)):
    print(get_tested(ege1, subjects, i))