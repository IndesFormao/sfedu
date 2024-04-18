import sys

def get_word_list_1():
    print("Каждое слово вводить в одинарных кавычках! (')")
    word_list = eval(input("Введите список слов в формате [..., ..., ...]: "))
    new_word_list=[]
    for i in range(len(word_list)):
        if isinstance(word_list[i], str) and word_list[i].isalpha():
            new_word_list.append(word_list[i])
        else:
            print(f'{word_list[i]} - не является строкой')
    if new_word_list!=[]:
        return new_word_list
    else:
        print('Проблема с исходными данными!')
        sys.exit()

print(get_word_list_1())