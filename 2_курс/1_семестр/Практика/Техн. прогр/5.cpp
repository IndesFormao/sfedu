#include<iostream>
using namespace std;

void f1()
{
    int num_1, num_2, num_3, max, num_num;
    cout << "Введите первое число" << endl;
    cin >> num_1;
    cout << "Введите второе число" << endl;
    cin >> num_2;
    cout << "Введите третье число" << endl;
    cin >> num_3;
    if (num_1 > num_2 && num_1 > num_3){
        max = num_1;
        num_num = 1;
    }
    else if (num_2 > num_3){
        max = num_2;
        num_num = 2;
    }
    else{
        max = num_3;
        num_num = 3;
    }
    cout << "Наибольшее число - " << max << "\n Номер числа: " << num_num << endl;
    
    return;
}

void f2()
{
    int num_1, num_2, num_3, first, second, third;
    cout << "Введите три числа" << endl;
    cin >> num_1 >> num_2 >> num_3;
    if (num_1 > num_2 && num_1 > num_3){
        cout << num_1 << ", ";
        if (num_2 > num_3){
            cout << num_2 << ", " << num_3 << endl;
        }
        else{
            cout << num_3 << ", " << num_2 << endl;
        }
    }
    else if (num_2 > num_3){
        cout << num_2 << ", ";
        if (num_1 > num_3){
            cout << num_1 << ", " << num_3 << endl;
        }
        else{
            cout << num_3 << ", " << num_1 << endl;
        }
    }
    else{
        cout << num_3 << ", ";
        if (num_1 > num_2){
            cout << num_1 << ", " << num_2 << endl;
        }
        else{
            cout << num_2 << ", " << num_1 << endl;
        }
    }
    
    return;
}

void f3()
{
    int A, B, C, dist_B, dist_C;
    cout << "Введите 3 целых числа для числовой оси (A, B, C соответственно)" << endl;
    cin >> A >> B >> C;
    
    dist_B = B-A;
    dist_C = C-A;
    // 2 if на случай отрицательного значения дистанций до точки
    if (dist_B < 0){
        dist_B -= 2*dist_B;
    }
    if (dist_C < 0){
        dist_C -= 2*dist_C;
    }
    
    if (dist_B > dist_C){
        cout << "Точка B ближе к точке A. Расстояние: " << dist_B << endl;
    }
    else{
        cout << "Точка C ближе к точке A. Расстояние: " << dist_C << endl;
    }
    
    return;
}

void f4()
{
    cout << "Рассматривается 'прямой' прямоугольник, т.е. который находится не под углом" << endl;
    int x1, y1, x2, y2, x3, y3, x4, y4;
    
    cout << "Введите первую точку (x, потом y): " << endl;
    cin >> x1 >> y1;
    cout << "Введите вторую точку (x, потом y): " << endl;
    cin >> x2 >> y2;
    cout << "Введите третью точку (x, потом y): " << endl;
    cin >> x3 >> y3;
    
    if (x1==x2){
        x4=x3;
    }
    else if (x1==x3){
        x4=x2;
    }
    else{
        x4=x1;
    }
    
    if (y1==y2){
        y4=y3;
    }
    else if (y1==y3){
        y4=y2;
    }
    else{
        y4=y1;
    }
    
    cout << "Координаты четвертой вершины\n x: " << x4 << "\n y: " << y4 << endl;
    return;
}

void f5()
{
    int x;
    double y;
    cout << "Введите число X:" << endl;
    cin >> x;
    if (x <= 0){
        y=-2.0/x;
    }
    else if (x >= 9){
        y=-x/3.0;
    }
    else if (x >= 3 && x < 9){
        y=x*x*x;
    }
    else{
        y=26.2;
    }
    cout << "y = " << y << endl;
    
    return;
}

void f6()
{
    int year;
    cout << "Введите год: " << endl;
    cin >> year;
    if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0))){
        cout << "В " << year << " году 366 дней" << endl;
    }
    else{
        cout << "В " << year << " году 365 дней" << endl;
    }
}

void f7()
{
    int day;
    cout << "Введите день недели (число от 1 до 7):" << endl;
    cin >> day;
    switch(day){
        case 1: cout << "Понедельник" << endl; break;
        case 2: cout << "Вторник" << endl; break;
        case 3: cout << "Среда" << endl; break;
        case 4: cout << "Четверг" << endl; break;
        case 5: cout << "Пятница" << endl; break;
        case 6: cout << "Суббота" << endl; break;
        case 7: cout << "Воскресенье" << endl; break;
        default: cout << "Ошибка" << endl; break;
    }
}

void f8()
{
    int nav_start, com1, com2, comms, nav_end, side;
    
    cout << "\n1-север \n2-запад \n3-юг \n4-восток \nВведите стартовую навигацию (число):" << endl;
    cin >> nav_start;

    cout << "Введите 2 команды (1 - поворот налево, -1 - поворот направо, 2 - поворот на 180°)" << endl;
    cin >> com1 >> com2;
    
    nav_end = nav_start + com1 + com2;
    //-1...8
    side = (nav_end + 4) % 4;
    switch(side){
        case 1: cout << "Север" << endl; break;
        case 2: cout << "Запад" << endl; break;
        case 3: cout << "Юг" << endl; break;
        case 4: cout << "Восток" << endl; break;
    }
    
    return;
}

void f9()
{
    int d, m;
    cout << "День:";
    cin>>d;
 
    cout << "Месяц:";
    cin>>m;
 
    switch (m) {
    case 1:
        if (d > 19)
            cout << "Водолей";
        else 
            cout << "Козерог";
        break;
    case 2:
        if (d > 18) 
            cout << "Рыбы";
        else 
            cout << "Водолей";
        break;
    case 3:
        if (d > 20) 
            cout << "Овен";
        else  
            cout << "Рыбы";
        break;
    case 4:
        if (d > 19) 
            cout << "Телец";
        else  
            cout << "Овен";
        break;
    case 5:
        if (d > 20) 
            cout << "Близнецы";
        else  
            cout << "Телец";
        break;
    case 6:
        if (d > 21)
            cout << "Рак";
        else 
            cout << "Близнецы";
        break;
    case 7:
        if (d > 22) 
            cout << "Лев";
        else 
            cout << "Рак";
        break;
    case 8:
        if (d > 22) 
            cout << "Дева";
        else 
            cout << "Лев";
        break;
    case 9:
        if (d > 22) 
            cout << "Весы";
        else 
            cout << "Дева";
        break;
    case 10:
        if (d > 22) 
            cout << "Скорпион";
        else 
            cout << "Весы";
        break;
    case 11:
        if (d > 22)
            cout << "Стрелец";
        else 
            cout << "Скорпион";
        break;
    case 12:
        if (d > 21)
            cout << "Козерог" << endl;
        else 
            cout << "Стрелец" << endl;
        break;
    }
    return;
}

int main()
{
    int i;
    while (i!=0){
    cout << "Введите номер задачи" << endl;
    cin >> i;
        switch(i){
            case 1:
                f1();
                break;
            case 2:
                f2();
                break;
            case 3:
                f3();
                break;
            case 4:
                f4();
                break;
            case 5:
                f5();
                break;
            case 6:
                f6();
                break;
            case 7:
                f7();
                break;
            case 8:
                f8();
                break;
            case 9:
                f9();
                break;
        }
    }
}
