import sys

def get_word_2():
    max_attemps=5
    for attemps in range(max_attemps):
        word=input('Введите слово: ')
        if word.isalpha():
            retry=False
            return word
        else:
            print(f'Ошибка ввода. Просьба повторить ввод\nОсталось {max_attemps-attemps-1} попыток')
    else:
        print('Выполнено %s неудачных попыток. Выход из программы!'%max_attemps)
        sys.exit()

wordle=get_word_2()
print(wordle)