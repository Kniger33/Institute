/*В программе определить класс «Товар» с полями: код, название, отдел,
стоимость, описание. Класс должен содержать несколько конструкторов, в
том числе конструктор копирования. Разработать соответствующие методы.
Информацию о товарах хранить в массиве объектов.
Разработать подпрограммы:
1)поиска информации о товарах, в
названии которых присутствует указанное слово или словосочетание; 
2)поиска информации о товарах со стоимостью 200-300 руб. из указанного
отдела; 
3)отображения информации о товарах в виде таблицы;
4)определения количества товаров с названием на букву «К»;
5)определения количества товаров со стоимостью более 1000 руб.*/
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
    //КОНСТРУКТОР
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
    ~Product(){cout << "Все очищено!" << endl;}
};

///////////////========================== ВЫВОД ТАБЛИЦЕЙ ==========================///////////////
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
    cout << "Введите размер массива объектов: ";
    cin >> obj_size;

    // Выделяется память для объектов класса Product в количестве obj_size
    //Product *pr = (Product*) operator new (sizeof(Product) * obj_size);

///////////////========================== ЗАПОЛНЕНИЕ ОБЪЕКТОВ ==========================///////////////
    for(int i = 0; i < obj_size; i++)
    {
        cout << endl << "Товар номер " << i + 1 << ":" << endl << endl;

        cout << "Код товара: ";
        cin >> enter_id;
        cout << "Название товара: ";
        getF();
        getline(cin,enter_name);
        cout << "Отдел товара: ";
        //getF();
        getline(cin,enter_department);
        cout << "Цена товара: ";
        cin >> enter_cost;
        cout << "Информация о товаре: ";
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

        cout << ">>Выберите номер задания: " << endl << endl;
        cout << ">>Поиск названия товара, в котором есть слово/словосочетание - 1" << endl;
        cout << ">>Поиск информации о товарах со стоимостью 200-300 р. из указанного отдела - 2" << endl;
        cout << ">>Отображение информации о товарах в виде таблицы - 3" << endl;
        cout << ">>Определение количества товаров с названием  на букву \"К\" - 4" << endl;
        cout << ">>Определение количества товаров со стоимостью более 1000р. - 5" << endl << endl;
        cout << ">>Выход - 0" << endl << endl;
        cout << ">>Ваш выбор: ";
        cin >> user_choise;

        switch(user_choise){
///////////////======  ПОИСК НАЗВАНИЯ ТОВАРА, В КОТОРОМ  ЕСТЬ СЛОВО/СЛОВОСОЧЕТАНИЕ
        case '1':{
                system("cls");
                string curName;
                string cmpCurName;
                bool rez = false;
                bool rez2 = false;
                cout << "Введите критерий поиска(слово/словосочетание): ";
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
///////////////======  ПОИСК ИНФОРМАЦИИ О ТОВАРАХ СО СТОИМОСТЬЮ 200-300Р. ИЗ УКАЗАННОГО ОТДЕЛА
        case '2':
            {
                system("cls");
                string curDepartment;
                string cmpDep;
                bool rez = false;
                cout << "Введите нужный отдел: ";
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
///////////////======  ОТОБРАЖЕНИЕ ИНФОРМАЦИИ О ТОВАРАХ В ВИДЕ ТАБЛИЦЫ
        case '3':
            {
                system("cls");
                for(int i = 0; i < 87; i++)
                {
                    cout << "_";
                }
                cout << endl << "|" << setw(10) << left << "Код товара" << "|" << setw(20) << left << "Название товара" << "|" << setw(20) << left << "Отдел товара";
                cout << "|" << setw(11) << left << "Цена товара" << "|" << setw(20) << left << "Информация о товаре" << "|" << endl;
                for(int i = 0; i < obj_size; i++)
                {
                    cout_table(prodVect[i].getId(), prodVect[i].getName(), prodVect[i].getDep(), prodVect[i].getCost(), prodVect[i].getInfo());
                }

                system("pause");
                break;
            }
///////////////======  ОПРЕДЕЛЕНИЕ КОЛИЧЕСТВА ТОВАРОВ С НАЗВАНИЕМ НА БУКВУ "К"
        case '4':
            {
                char symb;
                int countOfNames = 0;
                for(int i = 0; i < obj_size; i++)
                {
                    symb = prodVect[i].FirstSymbolOfName();
                    if (symb == 'к' || symb == 'К' || symb == 'k' || symb == 'K')
                        countOfNames++;
                }
                cout << endl << "Количество товаров с названием на букву \"К\": " << countOfNames  << endl << endl;
                system("pause");
                break;
            }
///////////////======  ОПРЕДЕЛЕНИЕ КОЛИЧЕСТВА ТОВАРОВ СО СТОИМОСТЬЮ БОЛЕЕ 1000Р.
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
                cout << endl << "Количество товаров со стоимостью более 1000р.: " << countOfProducts << endl << endl;
                system("pause");
                break;
            }
///////////////======  ВЫХОД ==========================///////////////
        case '0':
            {
                cout << "До свидания!" << endl;
                exit = 0;
                break;
            }
        default:
            {
                cout << "Нет такой команды" << endl;
                system("pause");
                break;
            }

        }
    }

    //Удаление элементов
    for(int i = 0; i < obj_size; i++)
    {
        prodVect[i].~Product();
    }
    //Удаление начального указателя
    //operator delete (pr);

    return 0;
}
