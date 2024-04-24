def word(words):
    result = [ elem for elem in words if (isinstance(elem, str) and elem.isalpha()) ]
    return result

def check_input(data):
    if data=='' or data=="[]":
        print('Пустые данные')
        words=[]
    elif data[0]=='[' and data[-1]==']':
        words=eval(data)
    else:
        words=[data]
    words = word(words)
    return words

data=input('Введите слова для их проверки на палиндром: ')
words=check_input(data)
print(words)