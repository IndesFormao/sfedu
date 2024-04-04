import sys

def get_word():
    word=input('Введите слово: ')
    if word.isalpha():
        return(word)
    elif word=='':
        print('Ошибка ввода: пустая строка!!!')
        sys.exit()
    else:
        print('Недопустимый символ')
        sys.exit()

def is_palindrome(word):
    word_lower=word.lower()
    check_word=word_lower[::-1]
    what_is=(word_lower==check_word)
    print(what_is)
    return(what_is)

def message(word, what_is):
    prefix='' if what_is==1 else 'не '
    print('Слово %s - %sпалиндром'%(word, prefix))
  
def check_palindrome():
    print('Поиск палиндромов')
    word=get_word()
    what_is=is_palindrome(word)
    message(word, what_is)

def is_palindrome_old(word):
    check_word=word[::-1]
    what_is= 'палиндром' if word==check_word else 'не палиндром'
    return what_is

check_palindrome()
