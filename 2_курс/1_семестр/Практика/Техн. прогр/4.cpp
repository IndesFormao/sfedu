#include<iostream>
using namespace std;

void f1()
{
    int a=7, b=9;
    cout << (a+b)/2.0 << endl;
}

void f2()
{
    double x=7.7;
    double a=77;
    double z=a/x;
    double y=11;
    cout << "1 кг стоит " << z << " рублей" << endl;
    cout << y << " кг стоит " << y*z << " рублей" << endl;
}

void f3()
{
   int v1 = 100, v2= 60, t=3;
   cout << "При движении автомобилей в одну сторону: через " << t << " часов расстояние между ними будет " << (v1-v2)*t << " км" << endl;
   cout << "При движении автомобилей в разные стороны: через " << t << " часов расстояние между ними будет " << (v1+v2)*t << " км" << endl;
}

void f4()
{
    int bytes=25000;
    cout << "Файл занимает " << bytes/1024 << " полных килобайтов (и " << bytes%1024 << " байта" << endl;
}

void f5()
{
    int n, mins, hours;
    cout << "Введите кол-во секунд" << endl;
    cin >> n;
    mins = n/60;
    hours = mins/60;
    cout << "С начала суток прошло " << hours << " часов или же " << mins << " минут. Текущее время: " << hours << ":" << mins%60 << endl; 
}

void f6()
{
    int a, a1, a2, a3, am, aa, ab;
    cout << "Введите трехзначное число" << endl;
    cin >> a;
    a1 = a/100;
    a2 = (a/10)%10;
    a3 = a%10;
    am = a1*a2*a3;
    aa = a1+a2+a3;
    ab = a3*100 + a2*10 + a1;
    cout << a1 << endl;
    cout << a2 << endl;
    cout << a3 << endl;
    cout << am << endl;
    cout << aa << endl;
    cout << ab << endl;
}

void f7()
{
    int random_day, day_week;
    cout << "Введите день года (1-365)" << endl;
    cin >> random_day;
    day_week = random_day % 7 + 1;
    cout << "Учитывая, что 1 января - вторник, то этот номер недели этого дня - " << day_week;
}

void f8()
{
    int a,b,c, empty, squares;
    cout << "a" << endl;
    cin >> a;
    cout << "b" << endl;
    cin >> b;
    cout << "c" << endl;
    cin >> c;
    squares = (a/c) * (b/c);
    empty = a*b - c*c*squares;
    cout << empty << endl;
    cout << squares << endl;
}

void f9()
{
    int x,y, number;
    string color;
    cout << "Введите первую координату" << endl;
    cin >> x;
    cout << "Введите вторую координату" << endl;
    cin >> y;
    color = "черный";
    number = (x+y) % 2;
    if (number == 1){
        color = "белый";
    }
    cout << color << endl;
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