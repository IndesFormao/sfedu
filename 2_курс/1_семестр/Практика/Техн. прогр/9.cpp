#include <iostream>
#include <math.h>
using namespace std;


void f1(){
    float A, B, BB=0;
    cout << "Введите 2 числа (первое число больше второго)" << endl;
    cin >> A >> B;
    while (A>=B){
        BB++;
        A-=B;
    }
    cout << "Кол-во отрезков B внутри A: " << BB << "\nНезанятая часть: " << A << endl;
}

void f2(){
    int N, K, BB=0;
    cout << "Введите 2 числа (первое число больше второго)" << endl;
    cin >> N >> K;
    while (N>=K){
        BB++;
        N-=K;
    }
    cout << "Частное: " << BB << "\nОстаток: " << N << endl;
}

void f3(){
    int N, K=0, BB=3;
    cout << "Введите целое число N: " << endl;
    cin >> N;
    while (N >= BB){
        BB*=3;
        K++;
    }
    cout << K << endl;
}

void f4(){
    float A, sum=0;
    int K=1;
    cout << "Введите число" << endl;
    cin >> A;
    while(sum<=A){
        sum+=1.0/K;
        K++;
    }
    K--;
    cout<<"Наименьшее число: "<<K<<endl;
}

void f5(){
    int K=0;
    float S=1000, P=0;
    cout << "Введите процентную ставку" << endl;
    cin >> P;
    P /= 1200;
    while (S <= 1100){
        S *= (1+P);
        K++;
    }
    cout << "Через " << K << " месяцев вклад будет составлять " << S << " рублей" << endl;
}

void f6(){
    int A, B, C;
    cout << "Введите положительные числа A и B:" << endl;
    cin >> A >> B;
    while (B != 0){
        C = B;
        B = A % B;
        A = C;
    }
    cout << "НОД: " << C << endl;
}

void f7(){
    int F1=1, F2=1, F3, N;
    cout << "Введите число N, входящее в последовательность Фибоначчи: " << endl;
    cin >> N;
    int i;
    while (F2 != N){
        F3=F1+F2;
        F1=F2;
        F2=F3;
    }
    F3=F2+F1;
    cout << "Предыдущее: " << F1 << "\nСледующее: " << F3 << endl;
}

void f8(){
    int K = 2;
	float A = 2.5, A_prev = 2, E;
	cout << "Введите число E (E > 0): ";
	cin >> E;
	while (fabs(A-A_prev) >= E)
	{
		A = 2 + 1/A;
		A_prev = 1 / (A - 2);
		K++;
	}
    cout << "K=" << K << "\nA(k-1)=" << A_prev << "\nAk=" << A << endl;
}

int main()
{
    int i;
    cout << "Куракин Н.А., группа 2.6" << endl;
    cout << "Дата: 16.10.2024" << endl;
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
            default:
                exit(0);
        }
    }
}
