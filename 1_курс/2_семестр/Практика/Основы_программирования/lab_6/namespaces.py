var1="глобальная"

def my_func():
    global var1
    var1="локальная"
    print(var1)
    var2="вторая"

my_func()
print(var1)
print(var2)
