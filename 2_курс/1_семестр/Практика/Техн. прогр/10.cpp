#include <iostream>
using namespace std;


void f1(){
    int N, x, min=61, max=19, N_min=0, N_max=0;
    cout << "Введите кол-во чисел" << endl;
    cin >> N;
    cout << "---------" << endl;
    int i=0;
    for (;N>0;N--){
        i++;
        x=rand()%21+20;
        cout << x << endl;
        if (x < min){
            min = x;
            N_min = i;
        }
        if (x > max){
            max = x;
            N_max = i;
        }
    }
    cout << "Минимальное число: " << min << "      Его номер:" << N_min << endl;
    cout << "Максимальное число: " << max << "      Его номер:" << N_max << endl;
}

void f2(){
    int B, C, x, count=1, max=19, N_max=0;
    cout << "Введите 2 числа (второе больше первого)" << endl;
    cin >> B >> C;
    cout << "----------" << endl;
    while (count <=10){
        x=rand()%21+20;
        cout << x << endl;
        if (x>=B){
            if (x<=C){
                if (x > max){
                    max = x;
                    N_max = count;
                }
            }
        }
        count++;
    }
    cout << "----------" << endl;
    if (N_max==0){
        cout << "Нужные числа не попались" << endl;
    }
    else{
        cout << "Максимальное число " << max << "        Его номер: " << N_max << endl;
    }
}

void f3(){
    int N, x, N_ext, max=-1000, min=1000;
    cout << "Введите кол-во чисел" << endl;
    cin >> N;
    cout << "---------" << endl;
    int i=0;
    for (;N>0;N--){
        i++;
        x=rand()%21+20;
        cout << x << endl;
        if (x < min){
            N_ext = i;
            min=x;
        }
        if (x > max){
            N_ext = i;
            max=x;
        }
        
    }
    cout << "Номер экстремального числа: " << N_ext << endl;
}

void f4(){
    float a, S=0;
    int N, i=1;
    cout << "Введите чило N: " << endl;
    cin >> N;
    while (i <= N){
        a=(i+1)/(2.0*i);
        S+=a;
        i++;
    }
    cout << "Сумма ряда: " << S << endl;
}

void f5(){
    int N, A, D;
    float mas[15], b;
    cout << "Введите число N (<10)" << endl;
    cin >> N;
    cout << "Введите числа A и D" << endl;
    cin >> A >> D;
    cout << "--------" << endl;
    int i=0;
    b=A*1.0;
    for (;i<15;i++){
        mas[i]=b;
        b /= D;
    }
    for (i=0; i<N;i++){
        cout << mas[i] << endl;
    }
}

void f6(){
    int N1, N2, F1=1, F2=1, K=3;
    float mas[20], FK=0;
    cout << "Введите с какого по какой члены массива вывести" << endl;
    cin >> N1 >> N2;
    cout << "---------" << endl;
    while (K < 23){
        FK=(F2+F1)*1.0;
        F1=F2;
        F2=FK;
        mas[K-3]=FK/K;
        if ((K-3) <= N2){
            if ((K-3) >= N1){
                cout << mas[K-3] << endl;
            }
        }
        K++;
    }
}

void f7(){
   int i=1;
   float X[10], sum=0;
   cout << "-------" << endl;
   for (;i<=10;i++){
       X[i]=4*i/5.0;
       cout << X[i] << endl;
       sum+=X[i];
   }
   cout << "Сумма: " << sum << endl;
}

void f8(){
    int i=1, sign=1;
    float X[10], sum=1;
    X[0]=1;
    cout << X[0] << endl;
    for (;i<10;i++){
        X[i]=sign*X[i-1]/3;
        sign = -sign;
        cout << X[i] << endl;
        sum+=X[i];
    }
    cout << "Сумма: " << sum << endl;
}

int main()
{
    int i;
    cout << "Куракин Н.А., группа 2.6" << endl;
    cout << "Дата: 23.10.2024" << endl;
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
