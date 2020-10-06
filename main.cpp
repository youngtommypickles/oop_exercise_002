#include "FazzyNumber.hpp"//подключаем библиотеку FazzyNumber, где описан класс и заданы функции
using namespace std;

void print_menu(){//меню для работы с числами
    cout << "______________________________" << endl;
    cout << "|                            |" << endl;
    cout << "|            МЕНЮ            |" << endl;
    cout << "|____________________________|" << endl;
    cout << "|                            |" << endl;
    cout << "|1  - ВЫВЕСТИ ЧИСЛО          |" << endl;
    cout << "|2  - ИЗМЕНИТЬ ЧИСЛО         |" << endl;
    cout << "|3  - СЛОЖЕНИЕ ЧИСЕЛ         |" << endl;
    cout << "|4  - ВЫЧИТАНИЕ ЧИСЕЛ        |" << endl;
    cout << "|5  - УМНОЖЕНИЕ ЧИСЕЛ        |" << endl;
    cout << "|6  - ДЕЛЕНИЕ ЧИСЕЛ          |" << endl;
    cout << "|7  - ОБРАТНОЕ ЧИСЛО         |" << endl;
    cout << "|8  - СРАВНЕНИЕ ЧИСЕЛ        |" << endl;
    cout << "|0  - КОНЕЦ                  |" << endl;
    cout << "|____________________________|" << endl;
}

FazzyNumber operator"" _faz(const char *faz, size_t){//пользовательский литерал
    char * sz;
    double nvalue = strtod(faz,&sz);
    double evalue = strtod(sz,nullptr);
    return FazzyNumber(nvalue, evalue);
}

int main(){
    FazzyNumber tmp(0, 0);
    FazzyNumber n1 = "0 0"_faz;//пример реализация пользовательского литерала
    FazzyNumber n2 = "0 0"_faz;//пример реализация пользовательского литерала3
    double nvalue, evalue;
    int option, n;
    print_menu();
    for(;;){
        cin >> option;
        switch(option){
            case 1:
                cout <<"ВЫБИРИТЕ ЧИСЛО(1 ИЛИ 2): "<< endl;
                cin >> n;
                if(n == 1){
                    n1.print();
                    break;
                }else if(n == 2){
                    n2.print();
                    break;
                } else{
                    cout << "НЕВЕРНО ВВЕДЕН НОМЕР ВЕКТОРА!" << endl;
                    break;
                }
            case 2:
                cout <<"ВЫБИРИТЕ ЧИСЛО(1 ИЛИ 2): "<< endl;
                cin >> n;
                if(n == 1){
                    cout <<"ЧИСЛО n:";
                    cin >> nvalue;
                    cout <<"ЧИСЛО e:";
                    cin >> evalue;
                    FazzyNumber res(nvalue, evalue);
                    n1 = res;
                    break;
                }else if(n == 2){
                    cout <<"ЧИСЛО n:";
                    cin >> nvalue;
                    cout <<"ЧИСЛО e:";
                    cin >> evalue;
                    FazzyNumber res(nvalue, evalue);
                    n2 = res;
                    break;
                } else{
                    cout << "НЕВЕРНО ВВЕДЕН НОМЕР ВЕКТОРА!" << endl;
                    break;
                }  
            case 3:
                tmp = n1+n2;
                tmp.print();
                break;
            case 4:
                tmp = n1-n2;
                tmp.print();
                break;
            case 5:
                tmp = n1*n2;
                tmp.print();
                break; 
            case 6:
                tmp = n1/n2;
                tmp.print();
                break;   
            case 7:
                cout <<"ВЫБИРИТЕ ЧИСЛО(1 ИЛИ 2): "<< endl;
                cin >> n;
                if(n == 1){
                    tmp = n1.reverse();
                    tmp.print();
                    break;
                }else if(n == 2){
                    cout <<"ЧИСЛО = ";
                    tmp = n2.reverse();
                    tmp.print();
                    break;
                } else{
                    cout << "НЕВЕРНО ВВЕДЕН НОМЕР ВЕКТОРА!" << endl;
                    break;
                }
            case 8:
                n1==n2;
                break;
            case 0:
                return 1;
            default:
                cout << "ОШИБКА. ТАКОГО ПУНКТА В МЕНЮ НЕТ" << endl;
                break;              
        }
    }
    return 0;
}