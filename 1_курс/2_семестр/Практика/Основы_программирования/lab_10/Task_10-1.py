def get_word_1():
    retry=True
    while retry:
        word=input('Введите слово: ')
        if word.isalpha():
            retry=False
            return word
        else:
            print('Ошибка ввода. Просьба повторить ввод')

wordle=get_word_1()
print(wordle)