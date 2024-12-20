#include <iostream>
#include <math.h>
using namespace std;


void f1(){
    int arr[10][10], sum[10];
    
    cout << "Изначальная матрица"<< endl;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            arr[i][j] = rand()%100-50;    // -50 ... 50
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
    
    cout << "Сумма строк:" << endl;
    for (int i = 0; i < 10; i++){
        sum[i] = 0;
        for (int j = 0; j < 10; j++){
            sum[i] += arr[i][j];
        }
        cout << sum[i] << endl;
    }
}

void f2(){
    int arr[10][10];
    long mull[10];
    
    cout << "Изначальная матрица"<< endl;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            arr[i][j] = rand()%100-50;    // -50 ... 50
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
    
    cout << "Произведение столбцов:" << endl;
    for (int i = 0; i < 10; i++){
        mull[i] = 1;
        for (int j = 0; j < 10; j++){
            mull[i] *= (long)arr[j][i];
        }
        cout << mull[i] << endl;
    }
}

void f3(){
    int arr[10][10], sum=0;
    
    cout << "Изначальная матрица"<< endl;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            arr[i][j] = rand()%100-50;    // -50 ... 49
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
    
    for (int i = 0; i < 10; i++){
        if (arr[i][i] > 0){
            sum += arr[i][i];
        }
    }
    
    
    cout << "Сумма положительных элементов главной диагонали: " << sum << endl;
}

void f4(){
    int arr[10][10], sum=0;
    cout << "Изначальная матрица:"<< endl;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            arr[i][j] = rand()%100-50;    // -50 ... 49
            cout << arr[i][j] << "   ";
        }
        cout << endl;
        
        for (int k=i+1; k < 10; k++){
            sum += arr[i][k];
        }
    }
    cout << "Сумма элементов выше главной диагонали: " << sum << endl;
}

void f5(){
    int arr[10][10], sum=0, line, col;
    float avg, elem= 100.0;
    cout << "Изначальная матрица:"<< endl;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            arr[i][j] = rand()%100-50;    // -50 ... 49
            cout << arr[i][j] << "   ";
            
            sum += arr[i][j];
        }
        cout << endl;
    }
    cout << "-----------------" << endl;
    
    avg = sum / 100.0;
    cout << "Среднее значение всех элементов матрицы: " << avg << endl;
    
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (fabs(avg - arr[i][j]) < fabs(avg - elem)){
                elem = arr[i][j];
                line = i;
                col = j;
            }
        }
    }
    
    cout << "Ближайший к среднему значению элемент: arr[" << line << "][" << col << "]" << endl;
    cout << "Его значение: " << elem << endl;
}

void f6(){
    int arr[10][10], K1, K2, warp;
    
    cout << "Изначальная матрица:"<< endl;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            arr[i][j] = rand()%100-50;    // -50 ... 49
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
    
    cout << "Введите 2 числа (K1 и K2):" << endl;
    cin >> K1 >> K2;
    for (int k = 0; k < 10; k++){
        warp = arr[K1-1][k];
        arr[K1-1][k] = arr[K2-1][k];
        arr[K2-1][k] = warp;
    }
    
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
}

void f7(){
    int arr[10][10], K1, K2, warp;
    
    cout << "Изначальная матрица:"<< endl;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            arr[i][j] = rand()%100-50;    // -50 ... 49
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
    
    cout << "Введите 2 числа (K1 и K2):" << endl;
    cin >> K1 >> K2;
    for (int k = 0; k < 10; k++){
        warp = arr[k][K1-1];
        arr[k][K1-1] = arr[k][K2-1];
        arr[k][K2-1] = warp;
    }
    
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
}

void f8(){
    int arr[10][10], K1, K2, warp;
    
    cout << "Изначальная матрица:"<< endl;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            arr[i][j] = rand()%100-50;    // -50 ... 49
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
    
    cout << "----------------" << endl;
    for (int i = 0; i < 10; i++){
        for (int j = i+1; j < 10; j++){
            warp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = warp;
        }
    }
    
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
}

void f9(){
    int arr[10][10], sum=0;
    
    cout << "Изначальная матрица:"<< endl;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            arr[i][j] = rand()%100-50;    // -50 ... 49
            cout << arr[i][j] << "   ";
        }
        cout << endl;
        
        for (int k=i-1; k >= 0; k--){
            arr[i][k] = 0;
        }
    }
    
    cout << "----------------" << endl;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
}

void f10(){
    int arr[10][10], brr[10][10], crr[10][10];
    cout << "Матрица 1:"<< endl;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            crr[i][j] = rand()%100-50;    // -50 ... 49
            cout << crr[i][j] << "   ";
        }
        cout << endl;
    }
    cout << "Матрица 2:"<< endl;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            brr[i][j] = rand()%100-50;    // -50 ... 49
            cout << brr[i][j] << "   ";
        }
        cout << endl;
    }
    cout << "Матрица 3:"<< endl;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            arr[i][j] = crr[i][j] + brr[i][j];
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
}

void f11(){
    float arr[10][10], diag[10];
    
    cout << "Матрица 1:"<< endl;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            arr[i][j] = rand()%100-50;    // -50 ... 49
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
    
    cout << "-----------------"<< endl;
    cout << "Вектор главной диагонали:"<< endl;
    for (int i = 0; i < 10; i++){
        diag[i] = arr[i][i] * 1.0;
        cout << diag[i] << "   ";
    }
    cout << endl;
    
    cout << "-----------------"<< endl;
    cout << "Матрица 2:"<< endl;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            arr[i][j] /= diag[i];
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
}

void f12(){
    float arr[10][10];
    
    cout << "Матрица 1:"<< endl;
    for (int i = 0; i < 10; i++){
        for (int j = i; j < 10; j++){
            arr[i][j] = (i+j)/(2.0*(i+j+1));
            arr[j][i] = arr[i][j];
        }
    }
    
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
}

int main()
{
    int i;
    cout << "Куракин Н.А., группа 2.6" << endl;
    cout << "Дата: 06.11.2024" << endl;
    while (i!=-1){
    cout << "Введите номер задачи: " << endl;
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
            case 10:
                f10();
                break;
            case 11:
                f11();
                break;
            case 12:
                f12();
                break;
            default:
                exit(0);
        }
    }
}
