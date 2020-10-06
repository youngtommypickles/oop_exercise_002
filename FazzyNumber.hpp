#ifndef FAZZY_NUMBER
#define FAZZY_NUMBER
#define N 0.00000000001

#include <iostream>//подключение библиотек
#include <string>
using namespace std;

class FazzyNumber{//класс
    private:
        double n, nl, nr, e;

    public:

    FazzyNumber(){//конструктор
        e = 0;
        n = 0;
        nl = n - e;
        nr = n + e;
    }

    FazzyNumber(double a, double b){//конструктор
        e = b;
        n = a;
        nl = n - e;
        nr = n + e;
    }   

    FazzyNumber reverse(){//обратное число
        FazzyNumber res(0, 0);
        if(n == 0){
            res.n = 1/N;
        } else{
            res.n = 1/n;
        }
        if(nl == 0){
            res.nl = 1/N;
        } else{
            res.nl = 1/nl;
        }
        if(nr == 0){
            res.nr = 1/N;
        } else{
            res.nr = 1/nr;
        }
        return res;
    }

    void print(){//вывод числа
        cout << "НЕЧЕТКОЕ ЧИСЛО: (" << nl << "," << n << "," << nr << ")" << endl;
    }

    FazzyNumber operator+(const FazzyNumber& rv){//перегрузка оператора +
        FazzyNumber res(0, 0);
        res.n = this->n + rv.n;
        res.nl = this->nl + rv.nl;
        res.nr = this->nr + rv.nr;
        return res;
    }

    FazzyNumber operator-(const FazzyNumber& rv){//перегрузка оператора -
        FazzyNumber res(0, 0);
        res.n = this->n - rv.n;
        res.nl = this->nl - rv.nl;
        res.nr = this->nr - rv.nr;
        return res;
    }

    FazzyNumber operator*(const FazzyNumber& rv){//перегрузка оператора *
        FazzyNumber res(0, 0);
        res.n = n*rv.n;
        res.nl = n*rv.n + e*rv.e - n*rv.e - rv.n*e;
        res.nr = n*rv.n + e*rv.e + n*rv.e + rv.n*e;
        return res;
    }

    FazzyNumber operator/(const FazzyNumber& rv){//перегрузка оператора /
        FazzyNumber res(0, 0);
        if(rv.n == 0){
            res.n = n/N;
        } else{
            res.n = n/rv.n;
        }
        if(rv.nl == 0){
            res.nl = nl/N;
        } else{
            res.nl = nl/rv.nl;
        }
        if(rv.nr == 0){
            res.nr = nr/N;
        } else{
            res.nr = nr/rv.nr;
        }
        return res;
    }

    void operator==(const FazzyNumber& rv){//перегрузка оператора =
        if(n == rv.n && nl == rv.nl && nr == rv.nr){
            cout <<  "Да, числа равны." << endl;
        }  else{
            cout <<  "Нет, числа не равны." << endl;
        }
    }
};

#endif //FAZZY_NUMBER