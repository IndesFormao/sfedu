def get_word():
    return input('Введите слово:')

def is_palindrome(word):
    check_word=word[::-1]
    what_is= 'палиндром' if word==check_word else 'не палиндром'
    return what_is

def message(word, what_is):
    print('Слово %s - %s'%(word, what_is))
  
def check_palindrome():
    print('Поиск палиндромов')
    word=get_word()
    what_is=is_palindrome(word)
    message(word, what_is)

check_palindrome()
