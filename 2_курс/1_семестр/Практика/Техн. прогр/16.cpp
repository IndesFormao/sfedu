#include <iostream>
#include <math.h>
using namespace std;
typedef string str;

str f1(str way){
    str ret1 = "", ret2 = "";
    int k = -1;
    for (int i = 0; i < way.length()-1; i++){
        if (way[i] == '\\'){
            if (way[i-1] != ':'){
                k = i;
                break;
            }
        }
    }
    if (k == -1){
        return "\\";
    }
    for (int i = k-1; i >= 0; i--){
        if (way[i] == '\\'){
            break;
        }
        ret1 += way[i];
    }
    for(int i = ret1.length() - 1; i >= 0; i--){
        ret2 += ret1[i];
    }
    return ret2;
}


str f2(str nocryp, int shifted){
    str crypt = "";
    
    int n = nocryp.length();
    for (int i = 0; i < n; i++){
        crypt += (char)((int)nocryp[i]+shifted);
        if (crypt[i] > 'z'){
            crypt[i] = (char)((int)crypt[i] - 26);
        }
    }
    return crypt;
}

str f3(str nodecryp, int shifted_back){
    str decrypt = "";
    int n = nodecryp.length();
    for (int i = 0; i < n; i++){
        decrypt += (char)((int)nodecryp[i]-shifted_back);
        if (decrypt[i] < 'a'){
            decrypt[i] = (char)((int)decrypt[i] + 26);
        }
    }
    return decrypt;
}


bool f4(str pal){
    if (pal == ""){
        return 1;
    }
    int n = pal.length();
    int loop = n/2;
    for (int i = 0; i < loop; i++){
        if (pal[i] != pal[n-1-i]){
            return 0;
        }
    }
    return 1;
}

int main()
{
    int i = 0;
    
    cout << "Куракин Н.А., группа 2.6" << endl;
    cout << "Дата: 11.12.2024" << endl;
    
    while (i!=-1){
        cout << "Введите номер задачи: " << endl;
        cin >> i;
        switch(i){
            case 1:
            {
                str file, catalog;
                
                cout << "Введите путь к файлу" << endl;
                cin >> file;
                
                catalog = f1 (file);
                cout << catalog << endl;
                
                break;
            }
            case 2:
            {
                str nocrypt, crypted;
                int K = 0;
                
                cout << "Введите строку" << endl;
                cin >> nocrypt;
                while (K < 1 || K > 9){
                    cout << "Введите число от 1 до 9" << endl;
                    cin >> K;
                }
                
                crypted = f2(nocrypt, K);
                
                cout << crypted << endl;
                
                break;
            }
            case 3:
            {
                str nodecrypt, decrypted;
                int K = 0;
                
                cout << "Введите строку" << endl;
                cin >> nodecrypt;
                while (K < 1 || K > 9){
                    cout << "Введите число от 1 до 9" << endl;
                    cin >> K;
                }
                
                decrypted = f3(nodecrypt, K);
                
                cout << decrypted << endl;
                
                break;
            }
            case 4:
            {
                str palindrome;
                bool TF;
                
                cout << "Введите строку " << endl;
                cin >> palindrome;
                
                TF = f4(palindrome);
                
                cout << TF << endl;
                
                break;
            }
            case 5:
            {
                str nocrypt, crypted, decrypted;
                int K = 0;
                
                cout << "Введите строку" << endl;
                cin >> nocrypt;
                while (K < 1 || K > 9){
                    cout << "Введите число от 1 до 9" << endl;
                    cin >> K;
                }
                
                crypted = f2(nocrypt, K);
                cout << crypted << endl;
                
                decrypted = f3(crypted, K);
                cout << decrypted << endl;
                
                break;
            }
            default:
                exit(0);
        }
    }
}