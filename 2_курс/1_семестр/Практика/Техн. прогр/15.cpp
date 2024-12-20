#include <iostream>
#include <math.h>
using namespace std;
typedef string str;

str f1(str l1, str l2){
    return l1 + l2;
}


str f2(str st, char cha){
    str line;
    int len = st.length();
    
    for (int i = 0; i < len; i++) {
		line += st[i];
		if (st[i] == cha)
		{
			line += cha;
		}
	}
	
	return line;
}

bool f3(str St, char Cha, int& firstt, int& lastt, int& countt){
    int len = St.length();
    bool ret = 0;
    
    for (int i = 0; i < len; i++) {
		if (St[i] == Cha)
		{
			countt++;
			if (firstt == -1){
			    firstt = i;
			    ret = 1;
			}
			else{
			    lastt = i;
			}
		}
	}
	if (firstt == -1){
	    firstt = 0;
	}
	
	return ret;
}

str f4(str st1, str st2, int N){
    str st3 = "";
    int len = st1.length();
    
    if(N <= 0){
        return st2 + st1;
    }
    else if(N >= len){
        return st1 + st2;
    }
    else{
        for (int i = 0; i < len; i++){
            st3 += st1[i];
            if (i == N-2){
                st3 += st2;
            }
        }
        
        return st3;
    }
}

str f5(str st, int num){
    str st2 = st;
    int len = st.length();
    
    if (len == num){
        return st2;
    }
    else if (len > num){
        
        st2.erase(num);
        return st2;
    }
    else{
        int razn = num - len;
        str dots = "";
        for (int i = 0; i < razn; i++){
            dots.append(".");
        }
        
        st2.insert(0, dots);
        return st2;
    }
}

str f6(int num1, int num2, str st1, str st2){
    str st3 = "";
    
    st1.erase(num1);
    st2.erase(0, num2);
    st3 = st1 + st2;
    
    return st3;
}

bool f7(str st, str st0){
    int index = st.find(st0);
    
    if (index == -1){
        return 0;
    }
    return 1;
}

int f8(str st, str st0){
    int count = 0, len = st.length(), len0 = st0.length();
    bool what = 1;
    
    for (int i = 0; i < len; i++) {
		if (st[i] == st0[0]) {
		    what = 1;
			for (int j = 0; j < len0; j++) {
				if (st[i+j] != st0[j]) {
					what = 0;
				}
			}
			if (what == 1){
			    count++;
			}
		}
	}
	
    return count;
}

int main()
{
    int i;
    
    cout << "Куракин Н.А., группа 2.6" << endl;
    cout << "Дата: 04.12.2024" << endl;
    
    while (i!=-1){
    cout << "Введите номер задачи: " << endl;
    cin >> i;
        switch(i){
            case 1:
            {
                str line1, line2, line3;
                
                cout << "Введите строку 1" << endl;
                cin >> line1;
                cout << "Введите строку 2" << endl;
                cin >> line2;
                line3 = f1(line1, line2);
            
                cout << line3 << endl;
                
                break;
            }
            case 2:
            {
                str S, line;
                char C;
                
                cout << "Введите строку" << endl;
                cin >> S;
                cout << "Введите символ" << endl;
                cin >> C;
                
                line = f2(S, C);
                
                cout << line << endl;
                
                break;
            }
            case 3:
            {
                str S;
                char C;
                int first=-1, last=0, count=0;
                bool B;
                
                cout << "Введите строку" << endl;
                cin >> S;
                cout << "Введите символ" << endl;
                cin >> C;
                
                B = f3(S, C, first, last, count);
                
                cout << "Данных символов в строке: " << count << endl;
                cout << "Первый: " << first << endl;
                cout << "Последний: " << last << endl;
                
                break;
            }
            case 4:
            {
                str S1, S2, S3;
                int N1;
                
                cout << "Введите строку 1" << endl;
                cin >> S1;
                cout << "Введите строку 2" << endl;
                cin >> S2;
                cout << "Введите число" << endl;
                cin >> N1;
                
                S3 = f4(S1, S2, N1);
                cout << S3 << endl;
                
                break;
            }
            case 5:
            {
                str S, S2;
                int N=0;
                
                cout << "Введите строку" << endl;
                cin >> S;
                while (N <=0){
                    cout << "Введите число (N > 0)" << endl;
                    cin >> N;
                }
                
                S2 = f5(S, N);
                cout << S2 << endl;
                
                
                break;
            }
            case 6:
            {
                str S1, S2, S3;
                int N1, N2;
                
                cout << "Введите строку 1" << endl;
                cin >> S1;
                cout << "Введите строку 2" << endl;
                cin >> S2;
                cout << "Введите число 1" << endl;
                cin >> N1;
                cout << "Введите число 2" << endl;
                cin >> N2;
                
                S3 = f6(N1, N2, S1, S2);
                
                cout << S3 << endl;
                break;
            }
            case 7:
            {
                str S, S0;
                bool TF = 0;
                
                cout << "Введите строку 1" << endl;
                cin >> S;
                cout << "Введите строку 2" << endl;
                cin >> S0;
                
                TF = f7(S, S0);
                
                cout << TF << endl;
                break;
            }
            case 8:
            {
                str S, S0;
                int count = 0;
                
                cout << "Введите строку 1" << endl;
                cin >> S;
                cout << "Введите строку 2" << endl;
                cin >> S0;
                
                count = f8(S, S0);
                
                cout << count << endl;
                break;
            }
            default:
                exit(0);
        }
    }
}