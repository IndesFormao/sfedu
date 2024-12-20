#include <iostream>
#include <math.h>
using namespace std;


float f1(float& x, float acc){
    float sum = 0.0;
    float A = -x/1.0;
    
    int count = 2;
    for (; fabs(A) > acc; count++){
        sum += A;
        A *= -x * 1.0 / count;
    }
    
    x = count - 1;
    return sum;
}


void f2(float* arr, int arr_len, float& sum, int& countt){
    for(int i = 0; i < arr_len; i++){
        if (arr[i] < 0){
            sum += arr[i];
            countt++;
        }
    }
}

void f3(float* arr, int arr_len){
    for (int i = 0; i < arr_len; i++){
        if (arr[i] < 0){
            arr[i] = (3.0 * i) / (2.0 * i + 1.0);
        }
    }
}

int main()
{
    int i;
    
    cout << "Куракин Н.А., группа 2.6" << endl;
    cout << "Дата: 27.11.2024" << endl;
    
    while (i!=-1){
    cout << "Введите номер задачи: " << endl;
    cin >> i;
        switch(i){
            case 1:
            {
                float num, accuracy, sum_1;
    
                cout << "Введите число для вычисление суммы ряда, а после точность" << endl;
                cin >> num >> accuracy;
                sum_1 = f1(num, accuracy);
                cout << "Сумма вычисленного ряда: " << sum_1 << "\nКол-во вычисленных элементов: " << num << endl;
                
                break;
            }
            case 2:
            {
                int n, count = 0, sign = 1;
                
                cout << "Введите параметры: " << endl;
                cin >> n;
                float *a = new float [n];
                float sum_2 = 0;
                cout << "Массив: " << endl;
                for(int i = 0; i < n; i++){
                    a[i]=sign*((2*i)/(i+1.0));
                    sign=-sign;
                    cout << a[i] << endl;
                }
                f2(a, n, sum_2, count);
                cout << "Сумма отрицательных чисел: " << sum_2 << "\nИх количество: " << count << endl;
                break;
            }
            case 3:
            {
                int n2, count2 = 0, sign2 = 1;
                
                cout << "Введите параметры: " << endl;
                cin >> n2;
                float *a2 = new float [n2];
                float sum_2 = 0;
                cout << "Массив: " << endl;
                for(int i = 0; i < n2; i++){
                    a2[i]=sign2*((2*i)/(i+1.0));
                    sign2=-sign2;
                    cout<<a2[i]<<endl;
                }
                f3(a2, n2);
                cout << "-------------" << endl;
                for(int i = 0; i < n2; i++){
                    cout << a2[i] << endl;
                }
                break;
            }
        }
    }
}