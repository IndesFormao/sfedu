import math

def sin(deg):
    result = [ math.sin(x) for x in deg ]
    return result

def sin_cos(deg):
    result = [ [math.sin(x), math.cos(x)] for x in deg ]
    return result

print('---------\nЗадание 1. Часть 1')
deg_1 = [math.pi/6, math.pi/4, math.pi/3]
deg_2 = (math.pi/6, math.pi/4, math.pi/3)
print(sin(deg_1))
print(sin(deg_2))

print('---------\nЗадание 1. Часть 2')
# Углы берутся из deg_1 прошлой части
print(sin_cos(deg_1))