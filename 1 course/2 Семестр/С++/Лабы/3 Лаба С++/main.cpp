/*� ��������� ���������� ����� ������ � ������: ���, ��������, �����,
���������, ��������. ����� ������ ��������� ��������� �������������, �
��� ����� ����������� �����������. ����������� ��������������� ������.
���������� � ������� ������� � ������� ��������.
����������� ������������:
1)������ ���������� � �������, �
�������� ������� ������������ ��������� ����� ��� ��������������; 
2)������ ���������� � ������� �� ���������� 200-300 ���. �� ����������
������; 
3)����������� ���������� � ������� � ���� �������;
4)����������� ���������� ������� � ��������� �� ����� �ʻ;
5)����������� ���������� ������� �� ���������� ����� 1000 ���.*/
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <cctype>
#include <vector>

using namespace std;

class Product
{
    int id;
    string name;
    string department;
    int cost;
    string information;
public:
    //�����������
    Product(int i, string n, string d, int c, string inf)
    {
        id = i;
        name = n;
        department = d;
        cost = c;
        information = inf;
    }
	Product(const Product &some_obj);
    string getDep(){return department;}
    string getName(){return name;}
    string getInfo(){return information;}
    char FirstSymbolOfName(){return name[0];}
    int getCost(){return cost;}
    int getId(){return id;}
    ~Product(){cout << "��� �������!" << endl;}
};

///////////////========================== ����� �������� ==========================///////////////
void cout_table(int curId, string curName, string curDepartment, int curCost, string curInformation)
{
    for(int i = 0; i < 87; i++)
    {
        cout << "_";
    }
    cout << endl;
    cout << "|" << setw(10) << left << curId << "|" << setw(20) << left << curName << "|" << setw(20) << left << curDepartment;
    cout << "|" << setw(11) << left << curCost << "|" << setw(20) << left << curInformation << "|" << endl;
    for(int i = 0; i < 87; i++)
    {
        cout << "_";
    }
    cout << endl;
}

void getF()
{
    cin.get();
}
///////////////========================== MAIN ==========================///////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int enter_id;
    string enter_name;
    string enter_department;
    int enter_cost;
    string enter_information;
    vector <Product> prodVect;

    int obj_size;
    cout << "������� ������ ������� ��������: ";
    cin >> obj_size;

    // ���������� ������ ��� �������� ������ Product � ���������� obj_size
    //Product *pr = (Product*) operator new (sizeof(Product) * obj_size);

///////////////========================== ���������� �������� ==========================///////////////
    for(int i = 0; i < obj_size; i++)
    {
        cout << endl << "����� ����� " << i + 1 << ":" << endl << endl;

        cout << "��� ������: ";
        cin >> enter_id;
        cout << "�������� ������: ";
        getF();
        getline(cin,enter_name);
        cout << "����� ������: ";
        //getF();
        getline(cin,enter_department);
        cout << "���� ������: ";
        cin >> enter_cost;
        cout << "���������� � ������: ";
        getF();
        getline(cin,enter_information);
        prodVect.push_back(Product(enter_id, enter_name, enter_department, enter_cost, enter_information));

        //new(&pr[i] ) Product(enter_id, enter_name, enter_department, enter_cost, enter_information);
        //new(&pr[i] ) Product(1, "Name Name", "DeP", 250, "information");
    }

    char user_choise;
    int exit = 1;

    while (exit)
    {
        system("cls");

        cout << ">>�������� ����� �������: " << endl << endl;
        cout << ">>����� �������� ������, � ������� ���� �����/�������������� - 1" << endl;
        cout << ">>����� ���������� � ������� �� ���������� 200-300 �. �� ���������� ������ - 2" << endl;
        cout << ">>����������� ���������� � ������� � ���� ������� - 3" << endl;
        cout << ">>����������� ���������� ������� � ���������  �� ����� \"�\" - 4" << endl;
        cout << ">>����������� ���������� ������� �� ���������� ����� 1000�. - 5" << endl << endl;
        cout << ">>����� - 0" << endl << endl;
        cout << ">>��� �����: ";
        cin >> user_choise;

        switch(user_choise){
///////////////======  ����� �������� ������, � �������  ���� �����/��������������
        case '1':{
                system("cls");
                string curName;
                string cmpCurName;
                bool rez = false;
                bool rez2 = false;
                cout << "������� �������� ������(�����/��������������): ";
                getF();
                getline(cin, curName);
                for (int i = 0; i < obj_size; i++)
                {
                    cmpCurName = prodVect[i].getName();
                    if (cmpCurName.length() == curName.length()){
                        for(int i = 0; i < cmpCurName.length(); i++){
                            if((char)tolower(cmpCurName[i]) == (char)tolower(curName[i])){rez = true;}
                            else{rez = false;}
                        }
                    }
                    else{
                        for(int i = 0; i < cmpCurName.length(); i++){
                            if (cmpCurName.find(curName) != string::npos){rez2 = true;}
                        }
                    }
                    if (rez == true || rez2 == true){
                        cout_table(prodVect[i].getId(), prodVect[i].getName(), prodVect[i].getDep(), prodVect[i].getCost(), prodVect[i].getInfo());
                        i = obj_size + 1;
                    }
                }
                system("pause");
                break;
            }
///////////////======  ����� ���������� � ������� �� ���������� 200-300�. �� ���������� ������
        case '2':
            {
                system("cls");
                string curDepartment;
                string cmpDep;
                bool rez = false;
                cout << "������� ������ �����: ";
                cin.get();
                getline(cin, curDepartment);
                for(int i = 0; i < obj_size; i++)                {
                    cmpDep = prodVect[i].getDep();
                    for(int i = 0; i < cmpDep.length(); i++)
                    {
                        if((char)tolower(cmpDep[i]) == (char)tolower(curDepartment[i])){rez = true;}
                        else{rez = false;}
                    }
                    if (rez == true && prodVect[i].getCost() >= 200 && prodVect[i].getCost() <= 300)                    {
                        cout_table(prodVect[i].getId(), prodVect[i].getName(), prodVect[i].getDep(), prodVect[i].getCost(), prodVect[i].getInfo());
                    }
                }
                cout << endl;
                system("pause");
                break;
            }
///////////////======  ����������� ���������� � ������� � ���� �������
        case '3':
            {
                system("cls");
                for(int i = 0; i < 87; i++)
                {
                    cout << "_";
                }
                cout << endl << "|" << setw(10) << left << "��� ������" << "|" << setw(20) << left << "�������� ������" << "|" << setw(20) << left << "����� ������";
                cout << "|" << setw(11) << left << "���� ������" << "|" << setw(20) << left << "���������� � ������" << "|" << endl;
                for(int i = 0; i < obj_size; i++)
                {
                    cout_table(prodVect[i].getId(), prodVect[i].getName(), prodVect[i].getDep(), prodVect[i].getCost(), prodVect[i].getInfo());
                }

                system("pause");
                break;
            }
///////////////======  ����������� ���������� ������� � ��������� �� ����� "�"
        case '4':
            {
                char symb;
                int countOfNames = 0;
                for(int i = 0; i < obj_size; i++)
                {
                    symb = prodVect[i].FirstSymbolOfName();
                    if (symb == '�' || symb == '�' || symb == 'k' || symb == 'K')
                        countOfNames++;
                }
                cout << endl << "���������� ������� � ��������� �� ����� \"�\": " << countOfNames  << endl << endl;
                system("pause");
                break;
            }
///////////////======  ����������� ���������� ������� �� ���������� ����� 1000�.
        case '5':
            {
                int countOfProducts = 0;
                for (int i = 0; i < obj_size; i++)
                {
                    if (prodVect[i].getCost() > 1000)
                    {
                        countOfProducts++;
                    }
                }
                cout << endl << "���������� ������� �� ���������� ����� 1000�.: " << countOfProducts << endl << endl;
                system("pause");
                break;
            }
///////////////======  ����� ==========================///////////////
        case '0':
            {
                cout << "�� ��������!" << endl;
                exit = 0;
                break;
            }
        default:
            {
                cout << "��� ����� �������" << endl;
                system("pause");
                break;
            }

        }
    }

    //�������� ���������
    for(int i = 0; i < obj_size; i++)
    {
        prodVect[i].~Product();
    }
    //�������� ���������� ���������
    //operator delete (pr);

    return 0;
}
