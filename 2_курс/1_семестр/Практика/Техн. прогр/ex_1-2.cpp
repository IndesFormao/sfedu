#include <iostream>
using namespace std;

int main() {
    
    // // задание 1
    // {
    //     cout << "Hello World" << endl;
    //     cout << "Привет Мир" << endl;
        
    //     int num_apple = 3;
    //     int num_pear = 6;
    //     int num_fruits = num_apple + num_pear;
    //     cout << "Количество фруктов: " << num_fruits << endl;
        
    //     int year_born;
    //     cin >> year_born;
    //     int age = 2024 - year_born;
    //     cout << "В этом году вам будет " << age << endl;
        
    //     int number_1 = 1;
    //     int number_2 = 4;
    //     int number_3 = 9;
    //     int number_4 = 16;
    //     int sum = number_1 + number_2 * number_3 / number_4;
    //     cout << sum << endl;
    // }
    // // конец задания 1
    
    
    // задание 1/2
    {
        {
            int a = 10;
            int b = 5;
            int per_rect = (a+b)*2;
            int square_rect = a*b;
            cout << "Площадь прямоугольника: " << per_rect << endl;
            cout << "Периметр прямоугольника: " << square_rect << endl;
        }
        
        double pi = 3.14;
        {
            double diam_circ = 20;
            double rad_circ = diam_circ/2.0;
            double square_circ = pi*rad_circ*rad_circ;
            double len_circ = 2*pi*rad_circ;
            cout << "Площадь окружности: " << square_circ << endl;
            cout << "Длина окружности: " << len_circ << endl;
        }
        {
            int r1 = 10;
            int r2 = 5;
            double square_circ_r1 = pi*r1*r1;
            double square_circ_r2 = pi*r2*r2;
            double square_ring = square_circ_r1 - square_circ_r2;
            cout << "Площадь окружности 1: " << square_circ_r1 << endl;
            cout << "Площадь окружности 2: " << square_circ_r2 << endl;
            cout << "Площадь кольца: " << square_ring << endl;
        }
        {
            double num_1 = 5;
            double num_2 = 3;
            double average = (num_1 + num_2) / 2;
            cout << "Среднее арифметическое: " << average << endl;
        }
        {
            int V = 60;
            int T = 3;
            int S = V*T;
            cout << "Автомобиль за " << T << " часов проедет " << S << " километров" << endl;
        }
        {
            int h = 17;
            int g = 10;
            int t = 1;
            int S_h = h - g*t*t/2;
            cout << "Через секунду тело будет находиться на высоте " << S_h << " метров" << endl;
        }
        {
            double T_f = 64;
            double T_c = (T_f - 32)*5/9;
            cout << T_f << " по шкале Фаренгейта это " << T_c << " по шкале Цельсия";
        }
    }    
    // конец задания 1/2
    
    return 0;
}