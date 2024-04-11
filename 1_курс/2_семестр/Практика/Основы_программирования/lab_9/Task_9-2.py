def get_tested(ege):
    for number in range(len(subjects)):
        if ege.find(subjects[number]):
            print("ЕГЭ по дисциплине " + str(subjects[number]))
def lower(sub):
    for i in range(len(subjects)):
        sub[i].lower()
    return sub



ege1 = "Математика - 78, Информатика - 75, Русский язык - 62"
subjects = [ 'Русский язык', 'Информатика', 'Математика', 'Английский язык', 'Физика']
ege1 = ege1.lower()
subjects = lower(subjects)
get_tested(ege1)