def get_word():
    global word
    word=input('Введите слово:')

def is_palindrome():
    global what_is
    check_word=word[::-1]
    what_is= 'палиндром' if word==check_word else 'не палиндром'

def message():
    print('Слово %s - %s'%(word, what_is))
  
def check_palindrome():
    print('Поиск палиндромов')
    get_word()
    is_palindrome()
    message()

check_palindrome()
