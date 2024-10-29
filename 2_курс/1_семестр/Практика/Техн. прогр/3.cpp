
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>

using namespace std;

void f1(){
    int i;
    float flo;
    double doub;
    
    printf("Введите 3 числа");
    scanf("%d", &i);
    scanf("%f", &flo);
    scanf("%lf", &doub);
    printf("i= %d, flo = %f, doub = %lf", i, flo, doub);
}

void f2(){
    int i;
    float flo;
    double doub;
    
    printf("Введите 3 числа");
    scanf("%d %f %lf", &i, &flo, &doub);
    printf("i= %d, flo = %f, doub = %lf\n", i, flo, doub);
}

int main()
{
    int a;
    while(a!=0){
        cout << "Введите номер подзадачи" << endl;
        cin >> a;
        switch(a){
            case 1:
                f1();
                break;
            case 2:
                f2();
                break;
            
        }
    }
}
