def number_of_solutions(a,b,c):
    d=b**2-4*a*c
    if d>=0:
        print('есть корни')
        if d==0:
            print('два равных корня')
        else: print('два различных корня')
    else: print('нет действительных корней')

print('Введите коэффициенты квадратного уравнения вида ax^2+bx+c=0')
a=int(input('Введите коэффициент a: '))
b=int(input('Введите коэффициент b: '))
c=int(input('Введите коэффициент c: '))
number_of_solutions(a,b,c)
