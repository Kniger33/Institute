#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

using namespace std;

class Polynomial{
private:
    int sl;
    vector<float> coefficient;
public:
    Polynomial(int s){
        sl = s;
        for (int i = 0; i < sl; i++){
            coefficient.push_back(0);
        }
    }
    int GetSize(){
        return coefficient.size();
    }

    //Вывод в консоль
    friend ostream& operator<< (ostream &stream, const Polynomial &pl){
        for (int i = pl.coefficient.size() - 1; i > 0; i--){
            if (pl.coefficient[i] != 0){
                stream << pl.coefficient[i] << "*X^(" << i << ") + ";
            }
        }
        stream << pl.coefficient[0];
    }

    //Ввод из консоли
    friend istream& operator>> (istream &stream,  Polynomial &pl){
        for (int i = 0; i < pl.coefficient.size(); i++){
            cout << "Write coefficient X^(" << i << "): ";
            stream >> pl.coefficient[i];
        }
    }

    //Вывод в файл
    friend ofstream& operator<< (ofstream &stream, const Polynomial &pl){
        stream << pl.coefficient.size() << " ";
        for (int i = 0; i < pl.coefficient.size(); i++){
            stream << pl.coefficient[i] << " ";
        }
        stream << endl;
    }

    //Ввод из файла
    friend ifstream& operator>> (ifstream &stream, Polynomial &pl){
        for (int i = 0; i < pl.coefficient.size(); i++){
            stream >> pl.coefficient[i];
        }
    }

    //Префиксный инкремент
    Polynomial operator++ (){
        for (int i = 0; i < coefficient.size(); i++){
            ++coefficient[i];
        }
    }

    //Постфиксный инкремент
     Polynomial operator++ (int){
        for (int i = 0; i < coefficient.size(); i++){
            coefficient[i]++;
        }
    }

    //Комбинированное вычитание
    Polynomial operator-= (const Polynomial& right){
        if (coefficient.size() < right.coefficient.size()){
            for (int i = 0; i < right.coefficient.size() - coefficient.size() + 1; i++){
                coefficient.push_back(0);
            }
        }
        for (int i = 0; i < right.coefficient.size(); i++){
            coefficient[i] -= right.coefficient[i];
        }
    }

    //Вычитание
    Polynomial operator- (const Polynomial& right){
        Polynomial res(sl);
        if (res.coefficient.size() < right.coefficient.size()){
            for (int i = 0; i < right.coefficient.size() - res.coefficient.size() + 1; i++){
                res.coefficient.push_back(0);
            }
        }
        for (int i = 0; i < right.coefficient.size(); i++){
            res.coefficient[i] = coefficient[i] - right.coefficient[i];
        }
        return res;
    }

    //Приведение к int
    operator int() const {
        int res = 0;
        for (int i = 0; i < coefficient.size(); i++){
            res += (int)coefficient[i];
        }
        return res;
    }

    //Приведение к float
    operator float() const {
        float res = 0;
        for (int i = 0; i < coefficient.size(); i++){
            res += coefficient[i];
        }
        return res;
    }
};

int main(){
    int i, sl, action, cnt, l, r;
    bool active = true;
    string path = "Polynomial.txt";

    vector<Polynomial> plnm;

    ifstream fin(path.c_str());
    //fin >> cnt;
    if (fin.read((char*)&cnt, sizeof(int))) {
        for (i = 0; i < cnt; i++){
            fin >> sl;
            plnm.push_back(Polynomial(sl));
            fin >> plnm[i];
        }
    }
    else {
        cnt = 0;
    }
    fin.close();


    do {
        system("cls");
        cout << "Count of polynomial: " << cnt << endl << endl;
        if (cnt > 0){
            cout << "List of polynomial: " << endl;
            for (i = 0; i < cnt; i++){
            cout << i << ") " << plnm[i] << endl;
            }
        }
        cout << endl << "1 - Add polynomial" << endl;
        cout << "2 - Sub polynomial" << endl;
        cout << "3 - Sub polynomial with create new" << endl;
        cout << "4 - Increment polynomial" << endl;
        cout << "5 - Polynomial to float" << endl;
        cout << "6 - Polynomial to int" << endl << endl;
        cout << "Write the command: ";
        cin >> action;
        switch(action){
            case 1:
                cout << "Write senior level: ";
                cin >> sl;
                plnm.push_back(Polynomial(sl + 1));
                cin >> plnm[plnm.size() - 1];
                cnt++;
                break;

            case 2:
                cout << "Write number of first polynomial: ";
                cin >> l;
                cout << "Write number of second polynomial: ";
                cin >> r;
                cout << endl << "   " << plnm[l] << endl << " -" << endl << "    " << plnm[r];
                plnm[l]-=plnm[r];
                cout << endl << " =" << endl << "   " << plnm[l] << endl << endl;
                system("pause");
                break;

            case 3:
                cout << "Write number of first polynomial: ";
                cin >> l;
                cout << "Write number of second polynomial: ";
                cin >> r;
                cout << endl << "   " << plnm[l] << endl << " -" << endl << "    " << plnm[r];
                if (plnm[l].GetSize() >= plnm[r].GetSize()){
                    plnm.push_back(Polynomial(plnm[l].GetSize()));
                }
                else{
                    plnm.push_back(Polynomial(plnm[r].GetSize()));
                }
                plnm[plnm.size() - 1] = plnm[l] - plnm[r];
                cnt++;
                cout << endl << " =" << endl << "   " << plnm[plnm.size() - 1] << endl << endl;
                system("pause");
                break;

            case 4:
                cout << "Write number of polynomial: ";
                cin >> l;
                plnm[l]++;
                cout << endl << "Result: " << plnm[l] << endl << endl;
                system("pause");
                break;

            case 5:
                cout << "Write number of the polynomial: ";
                cin >> l;
                cout << endl << plnm[l] << endl;
                float a;
                a = static_cast <float> (plnm[l]);
                cout << endl << "Result: " << a << endl << endl;
                system("pause");
                break;

            case 6:
                cout << "Write number of the polynomial: ";
                cin >> l;
                cout << endl << plnm[l] << endl;
                int b;
                b = static_cast <int> (plnm[l]);
                cout << endl << "Result: " << b << endl << endl;
                system("pause");
                break;

            case 9:
                active = false;
                break;
        }
    } while(active);

    ofstream fout(path.c_str());
    //fout << cnt << endl;
    fout.write((char*)&cnt, sizeof(int));
    fout << endl;
    for (i = 0; i < cnt; i++) {
        fout << plnm[i] << endl;
    }
    fout.close();

    return 0;
}
