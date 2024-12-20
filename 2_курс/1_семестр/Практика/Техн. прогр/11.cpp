#include <iostream>
using namespace std;


void f1(){
    int arr[10], K, L, sum=0;
    float aver;
    cout << "Массив:" << endl;
    for (int i = 0; i < 10; i++){
        arr[i] = rand()%21; // от 0 до 20
        cout << arr[i] << endl;
    }
    cout << "---------------" << endl;
    cout << "Введите 2 числа (второе больше первого): " << endl;
    cin >> K >> L;
    for (int j = K; j <= L; j++){
        sum += arr[j-1];
    }
    aver = (float)sum / (L - K + 1);
    
    cout << "Сумма: " << sum << endl;
    cout << "Среднее арифметическое: " << aver << endl;
}

void f2(){
    int arr[10], loc_min=0;
    cout << "Массив:" << endl;
    for (int i = 0; i < 10; i++){
        arr[i] = rand()%21;
        cout << arr[i] << endl;
    }
    cout << "---------------" << endl;
    
    if (arr[0] < arr[1]){
        loc_min = arr[0];
    }
    for (int j = 1; j < 9; j++){
        if (loc_min < arr[j]){
            if (arr[j] < arr[j+1]){
                if (arr[j] < arr[j-1]){
                    loc_min = arr[j];
                }
            }
        }
    }
    if (loc_min < arr[9]){
        if (arr[8] > arr[9]){
            loc_min = arr[9];
        }
    }
    cout << "Максимальный локальный минимум: " << loc_min << endl;
}

void f3(){
    int arr[10], R, clo = 30, abss, num;
    cout << "Массив:" << endl;
    for (int i=0; i<10; i++){
        arr[i] = rand()%21;
        cout << arr[i] << endl;
    }
    cout << "---------------" << endl;
    cout << "Введите число R: " << endl;
    cin >> R;
    for (int j = 0; j < 10; j++){
        abss = abs(arr[j]-R);
        if (abss < clo){
            clo = abss;
            num = j+1;
        }
    }
    cout << "Ближайший член последовательности к числу R имеет номер " << num << endl;
    cout << "Его значение: " << arr[num-1] << endl;
}

void f4(){
    int arr[10];
    float B[10];
    cout << "Массив A:" << endl;
    for (int i = 0; i < 10; i++){
        arr[i] = rand()%21;
        cout << arr[i] << endl;
    }
    cout << "---------------" << endl;
    cout << "Массив B:" << endl;
    for (int j = 0; j < 10; j++){
        if (arr[j] < 5){
            B[j] = arr[j] * 2;
        }
        else{
            B[j] = arr[j] / 2.0;
        }
        cout << B[j] << endl;
    }
}

void f5(){
    int arr[10], B[10], sum=0;
    cout << "Массив A:" << endl;
    for (int i=0; i<10; i++){
        arr[i] = rand()%21;
        cout << arr[i] << endl;
    }
    cout << "---------------" << endl;
    cout << "Массив B:" << endl;
    for (int j = 0; j < 10; j++){
        sum += arr[j];
        B[j] = sum;
        cout << B[j] << endl;
    }
}

void f6(){
    int arr[10], A0, A1;
    cout << "Исходный массив:" << endl;
    for (int i = 0; i < 10; i++){
        arr[i] = rand()%21;
        cout << arr[i] << endl;
    }
    cout << "---------------" << endl;
    for (int j = 9; j >= 0; j--){
        A1 = arr[j];
        A0 = arr[j-1];
        arr[j] = arr[j-1];
    }
    arr[0]=0;
    cout << "Полученный массив:" << endl;
    for(int k = 0; k < 10; k++){
        cout << arr[k] << endl;
    }
}

void f7(){
    int arr[10], N = 10, max;
    cout << "Исходный массив:" << endl; // создание массива
    for (int i = 0; i < 10; i++){
        arr[i] = rand()%21;
        cout << arr[i] << endl;
    }
    cout << "---------------" << endl;
    
    for (int i = 0; i < 10; i++){ // сортировка массива
        for (int j = 0; j < N; j++){
            if (arr[j] > arr[j+1]){ // > возрастание; < убывание
                max = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = max;
            }
        }
        N--;
        
        cout << "Массив в " << i+1 << " цикле" << endl; // вывод массива после цикла
        for (int k = 0; k < 10; k++){
            cout << arr[k] << endl;
        }
        cout << "------------" << endl;
    }
}

void f8(){
    int arr[10], N = 10, max, num, exch;
    cout << "Исходный массив:" << endl;     // создание массива
    for (int i = 0; i < 10; i++){
        arr[i] = rand()%21;
        cout << arr[i] << endl;
    }
    cout << "---------------" << endl;
    
    for (int i = 0; i < 10; i++){           // сортировка массива
    max = 0;
        for (int j = 0; j < N; j++){
            if (arr[j] > max){              // > возрастание; < убывание
                max = arr[j];
                num = j;
            }
        }
        exch = arr[N-1];
        arr[N-1] = arr[num];
        arr[num] = exch;
        N--;
        
        cout << "Массив в " << i+1 << " цикле" << endl; // вывод массива после цикла
        for (int k = 0; k < 10; k++){
            cout << arr[k] << endl;
        }
        cout << "------------" << endl;
    }
}

int main()
{
    int i;
    cout << "Куракин Н.А., группа 2.6" << endl;
    cout << "Дата: 30.10.2024" << endl;
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
