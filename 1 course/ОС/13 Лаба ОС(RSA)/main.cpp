#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include <math.h>
#include "../WinNTL-11_0_0/include/NTL/ZZ.h"

using namespace std;

// Функция нахождения НОД
long long int NOD(long int n1, long long int n2)
{
  long long int div;
  if (n1 == n2)   // если числа равны, НОД найден
    return n1;
  long long int d = n1 - n2; // Находим разность чисел
  if (d < 0)       // если разность отрицательная,
  {
    d = -d;     // меняем знак
    div = NOD(n1, d); // вызываем функцию NOD() для двух наименьших чисел
  }
  else      // если разность n1-n2 положительная
  {
    div = NOD(n2, d); // вызываем функцию NOD() для двух наименьших чисел
  }
  return div;
}

unsigned long long int myPow(unsigned long long int smb, int n){
    for(int i = 0; i < n; i++){
        smb*=smb;
    }
    return smb;
}

int main()
{
    srand(time(NULL));

    int simpleNumbers[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 73, 83, 89, 97};

    int p = simpleNumbers[rand() % (24 + 1)];
    int q = simpleNumbers[rand() % (24 + 1)];

    //произведение p и q
    long long int n;
    long long int pqminus;
    unsigned long long int ed;

    long int d;
    long int e = 0;

    string message;

    d = 1 + rand() % ((100 + 1) - 1);

    n = p*q;
    pqminus = (q - 1)*(p - 1);

    cout << p << " " << q << endl;
    cout << pqminus << endl;
    cout << "n: " << n << endl;
    system("pause");

    while (NOD(d, pqminus) != 1) {
        d = 1 + rand() % ((100 + 1) - 1);
    }

    cout << d << endl;
    system("pause");

    e = 1 + rand() % ((100 + 1) - 1);
    ed = e * d;
    cout << pqminus << endl;
    cout << e << " * " << d << " = " << ed << endl;
    system("pause");

    while ((ed) % pqminus != 1){
        e = 1 + rand() % ((100 + 1) - 1);
        ed = e * d;
        cout << (ed) % pqminus << endl;
    }

    cout << "E: " << e << endl;

    cout << "Write message: ";
    getline(cin, message);

    unsigned long long int secretMessage[message.size()];

    for (int i = 0; i < message.size(); i++){
        cout << (int)message[i] << " ";
        secretMessage[i] = (myPow((int)message[i], e) % n);
    }

    cout << "Secret: ";
    for (int i = 0; i < message.size(); i++){
        cout << secretMessage[i] << " ";
    }
    return 0;
}
