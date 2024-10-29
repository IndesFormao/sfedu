#include <iostream>
using namespace std;

void f1(){
    int A, B, sum, nums;
    sum=0;
    nums=0;
    
    cout << "Введите 2 числа (второе больше первого)" << endl;
    cin >> A >> B;
    int i;
    for (i=1; A<(B-i);i++){
        cout << B-i << endl;
        sum += B-i;
        nums+=1;
    }
    cout << "Сумма чисел: " << sum << "\nКоличество чисел: " << nums << endl;
    
}

void f2(){
    int N;
    float sum;
    
    cout << "Введите знаменатель последнего члена последовательности" << endl;
    cin >> N;
    int i;
    for (i=1; i<=N;i++){
        sum+=1.0/i;
    }
    cout << "Сумма последовательности: " << sum << endl;
}

void f3(){
    int N, sign;
    float sum;
    
    cout << "Введите число слагаемых: " << endl;
    cin >> N;
    
    sign = 1;
    int i;
    for (i=1; i<=N; i++){
        sum+=sign*(1+i/10.0);
        sign*= -1;
    }
    
    cout << "Сумма последовательности: " << sum << endl;
}

void f4(){
    int N, square_N;
    
    cout << "Введите число N" << endl;
    cin >> N;
    int i;
    for (i=1; i<=N; i++){
        square_N+=2*i-1;
    }
    
    cout << "Квадрат числа N: " << square_N << endl;
}

void f5(){
    int N, sign=-1;
    float A, B=1, sum=1;
    
    cout << "Введите вещественное число A, а после целое N: " << endl;
    cin >> A >> N;
    int i;
    for(i=1; i<=N; i++){
        B *= A;
        sum += sign*B;
        sign *= -1;
    }
    
    cout << "Сумма последовательности: " << sum << endl;
}

void f6(){
    int N, fact=1;
    
    cout << "Введите число N (>0)" << endl;
    cin >> N;
    
    int i;
    for (i=1; i<=N; i++){
        fact*=i;
    }
    cout << fact << endl;
}

void f7(){
    int N;
    float A, A0=2;
    
    cout << "Введите число N (>0)" << endl;
    cin >> N;
    cout << A0 << endl;
    int K;
    for (K=1; K<=N; K++){
        A=A0;
        A0=2+1.0/K/A;
        cout << A0 << endl;
    }
}

void f8(){
    int N, number, sum;
    cout << "Введите число N: " << endl;
    cin >> N;
    int i, j;
    for (i=1; i<=N; i++){
        number=1;
        for (j=1; j<=i; j++){
            number*=i;
        }
        sum+=number;
    }
    
    cout << "Сумма последовательности: " << sum << endl;
}

void f9(){
    int N, number, sum;
    cout << "Введите число N: " << endl;
    cin >> N;
    int i, j;
    for (i=1; i<=N; i++){
        number=1;
        for (j=1; j<=(N-i+1); j++){
            number*=i;
        }
        sum+=number;
    }
    
    cout << "Сумма последовательности: " << sum << endl;
}

int main()
{
    int i;
    cout << "Куракин Н.А., группа 2.6" << endl;
    cout << "Дата: 09.10.2024" << endl;
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
            default:
                exit(0);
        }
    }
}
