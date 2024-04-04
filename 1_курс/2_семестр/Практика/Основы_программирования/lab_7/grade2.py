def grade2(mark):
    if mark<0 or mark>100:
        print('Ошибка. Введено неправильное число. Введите число от 0 до 100')
    elif mark<60:
        print('Неудовлетворительно')
    elif mark<71:
        print('Удовлетворительно')
    elif mark<85:
        print('Хорошо')
    else:
        print('Отлично')
        
mark=int(input('Введите ваши баллы: '))
grade2(mark)
