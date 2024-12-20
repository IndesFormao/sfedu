#include <iostream>
#include <math.h>
using namespace std;


float f1(float x){
    float y = 1;
    
    if (x < 0){
        y = -2 / x;
    }
    else if (x >= 9){
        y *= -x;
    }
    else if (x < 9 && x >=3){
        y = x * x * x;
    }
    else{
        y = 26.2;
    }
    
    return y;
}

float f2(int N){
    float sum = 0;
    
    for (int i = 1; i <= N; i++){
        sum += (i + 1.0) / (2 * i);
    }
    
    return sum;
}

int f3(int D){
    int K = 0;
    
    while (K <= 0){
        cout << "Введите число K: " << endl;
        cin >> K;
    }
    
    K = K*10 + D;
    
    return K;
}

void f4(float& X1, float& Y1){
    float swap;
    
    swap = X1;
    X1 = Y1;
    Y1 = swap;
}

void f5(float x, float y, float& arifm, float& geom){
    arifm = (x + y) / 2.0;
    geom = sqrt(x * y);
}

void f6(float& x, float& y, float& z){
    float swap;
    
    if (y < x){
        f4(y, x);
    }
    if (z < x){
        f4(z, x);
    }
    if (z < y){
        f4(z, y);
    }
}

void f7(float* y, int x){
    y[0] = 0.5;
    for (int i = 1; i <= x; i++){
        y[i] = (i + 1) / (2.0 * i);
    }
}

void f8(int* array, int sizee, int& minn, int& n_min, int& maxx, int& n_max, int& sum_poz){
    for (int i = 0; i < sizee; i++){
        if (array[i] > maxx){
            maxx = array[i];
            n_max = i;
        }
        if (array[i] < minn){
            minn = array[i];
            n_min = i;
        }
        if (array[i] > 0){
            sum_poz += array[i];
        }
    }
}

float f9(int x){
    float factt = 1.0;
    
    for (int i = 1; i <= x; i++){
        factt *= i;
    }
    
    return factt;
}

int main()
{
    int i;
    cout << "Куракин Н.А., группа 2.6" << endl;
    cout << "Дата: 13.11.2024" << endl;
    while (i!=-1){
    cout << "Введите номер задачи: " << endl;
    cin >> i;
        switch(i){
            case 1:
            {
                float input, output;
                
                cout << "Введите x" << endl;
                cin >> input;
                
                output = f1(input);
                cout << "y = " << output << endl;
                
                break;
            }
            case 2:
            {
                int number_iterations;
                float summ;
                
                cout << "Введите N" << endl;
                cin >> number_iterations;
                
                summ = f2(number_iterations);
                cout << "S = " << summ << endl;
                
                break;
            }
            case 3:
            {
                int KD, nume = 10;
                
                while (nume < 0 || nume > 9){
                    cout << "Введите цифру (0-9)" << endl;
                    cin >> nume;
                }
                
                KD = f3(nume);
                cout << KD << endl;
                
                break;
            }
            case 4:
            {
                float x, y;
                
                cout << "Введите 2 числа" << endl;
                cin >> x >> y;
                
                f4(x, y);
                
                cout << "x = " << x << endl;
                cout << "y = " << y << endl;
                
                break;
            }
            case 5:
            {
                float num1, num2, avg_arifm, avg_geom;
                
                cout << "Введите 2 числа" << endl;
                cin >> num1 >> num2;
                
                f5(num1, num2, avg_arifm, avg_geom);
                
                cout << "Среднее арифметическое: " << avg_arifm << endl;
                cout << "Среднее геометрическое: " << avg_geom << endl;
                
                break;
            }
            case 6:
            {
                float A, B, C;
                
                cout << "Введите 3 числа" << endl;
                cin >> A >> B >> C;
                
                f6(A, B, C);
                
                cout << "Числа в порядке возрастания: " << A << ", " << B << ", " << C << endl;
                break;
            }
            case 7:
            {
                int N_arr;
                
                cout << "Введите длину массива" << endl;
                cin >> N_arr;
                float arr[N_arr];
                
                f7(arr, N_arr);
                
                cout << "Массив:" << endl;
                for (int i = 0; i <= N_arr; i++){
                     cout << arr[i] << endl;
                }
                break;
            }
            case 8:
            {
                int size, min = 51, num_min, max = -51, num_max, poz = 0;
                
                cout << "Введите длину массива" << endl;
                cin >> size;
                int arr[size];
                
                for (int i = 0; i < size; i++){
                    arr[i] = rand()%100-50;             // -50 ... 50
                    cout << arr[i] << ' ';
                }
                cout << endl;
                
                f8(arr, size, min, num_min, max, num_max, poz);
                
                cout << endl << "Минимальное значение: " << min << "\nЕго номер: " << num_min << endl << endl;
                cout << "Максимальное значение: " << max << "\nЕго номер: " << num_max << endl;
                cout << "Сумма положительных элементов массива: " << poz << endl;
                
                cout << endl << "*Номера считаются с 0" << endl;
                break;
            }
            case 9:
            {
                int N = 0, fact;
                
                while (N <= 0){
                    cout << "Введите положительное число" << endl;
                    cin >> N;
                }
                
                fact = f9(N);
                
                cout << "Факториал данного числа равен " << fact << endl;
                
                break;
            }
            default:
                exit(0);
        }
    }
}
