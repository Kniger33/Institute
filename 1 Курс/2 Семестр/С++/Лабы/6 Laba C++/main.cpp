/*Вариант 25
Разработать класс List (однонаправленный список). В качестве стандартных типов использовать целочисленный, вещественный и
символьный типы. Для пользовательского типа использовать класс из лабораторной работы № 3. Перегрузить следующие операции:
1) добавление элемента в начало списка (list + item);
2) удаление элемента из начала списка (--list);
3) проверка на неравенство списков (!=).*/

#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <cctype>
#include <vector>

using namespace std;

template <class T>
class List
{

struct Node
{
    T someValue;          //Значение
    Node* m_next;         //Указатель на следующий узел
    Node(): m_next(NULL){};
    Node(const T& t) : someValue(t), m_next(NULL){};
};
    Node* m_head;         // Голова односвязного списка

public:
    List();
    ~List();
    //Добавление узла в список
    void Add( const T& t );
    //void Add( const T& t);
    //Удаление последнего добавленного узла из списка
    void Remove();
    //Размер списка
    size_t MySize() const;
    //T GTV(){return T::Node->someValue;}
    void cmp(List, List);

    class Iterator {
    private:
        Node* m_node;
    public:
        Iterator (Node* node): m_node(node){};
        // Проверка на равенство
        bool operator==( const Iterator& other ) const {
            if( this == &other ) {
                return true;
            }
            return m_node == other.m_node;
        }

        // Проверка на неравенство
        bool operator!=( const Iterator& other ) const {
            return !operator==( other );
        }

        // Получение значения текущего узла
        T operator*() const {
            if( m_node ) {
                return m_node->m_t;
            } // Иначе достигнут конец списка
            cout << "Конец списка" << endl;
            return T();
        }

        // Переход к следующему узлу
        void operator++() {
            if( m_node ) {
                m_node = m_node->m_next;
            } // Иначе достигнут конец списка.
            cout << "Конец списка" << endl;
        }
    };

    void ShowInfo(){
        Node *temp = m_head;
        while(temp != NULL){
            cout << "Some value - " << temp->someValue << endl;
            temp = temp->m_next;
        }
    }

    void operator+(const T &t){
        if(Node* node = new Node(t)){
            node->m_next = m_head;          //Новый узел привязывается к старому головному элементу
            m_head = node;                  // Новый узел сам становится головным элементом
        }
    }


    //void operator+(Product p)
    bool operator !=(List &t){
        Node *temp = this->m_head;
        Node *temp2 = t.m_head;
        int c = 0;
        if(t.MySize() != this->MySize()){return 0;}
        else {
            for( Node* n = m_head; n != NULL; n = n->m_next ) {
                if(temp->someValue == temp2->someValue){c++;}
            }
        }
        if(c == t.MySize()){return 1;}
        else {return 0;}
    }

    List& operator--(){
        if(m_head){          //Если не пуст
        Node* newHead = m_head->m_next;          // Сохраняем указатель на второй узел, который станет новым головным элементом
        delete m_head;                           // Освобождаем память, выделенную для удаляемого головного элемента
        m_head = newHead;                        // Назначаем новый головной элемент
    }
    else cout << "Список пуст!" << endl;
    }

};

template <typename T>
List <T>:: List(): m_head(NULL){};

template <typename T>
void List <T>:: Add(const T &t){
    if(Node* node = new Node(t)){
        node->m_next = m_head;          //Новый узел привязывается к старому головному элементу
        m_head = node;                  // Новый узел сам становится головным элементом
    }
}

template <typename T>
void List <T>:: Remove(){
    if(m_head){          //Если не пуст
        Node* newHead = m_head->m_next;          // Сохраняем указатель на второй узел, который станет новым головным элементом
        delete m_head;                           // Освобождаем память, выделенную для удаляемого головного элемента
        m_head = newHead;                        // Назначаем новый головной элемент
    }
    else cout << "Список пуст!" << endl;
}

template< typename T >
List< T >::~List() {
    while( m_head ) {
        Remove();
    }
}

template< typename T >
size_t List< T >::MySize() const {
    size_t s = 0;
    for( Node* n = m_head; n != NULL; n = n->m_next ) {
        ++s;
    }
    return s;
}

class Product
{
    int id;
    string name;
    string department;
    int cost;
    string information;
public:
    //КОНСТРУКТОР
    Product(){};
	Product(const Product &some_obj);
    string getDep(){return department;}
    string getName(){return name;}
    string getInfo(){return information;}
    char FirstSymbolOfName(){return name[0];}
    int getCost(){return cost;}
    int getId(){return id;}
    void ShowInfo(){
        cout << "|Номер - " << id << endl;
        cout << "|Название - " << name << endl;
        cout << "|Отдел - " << department << endl;
        cout << "|Цена - " << cost << endl;
        cout << "|Информация о товаре - " << information << endl;
    }
    void SetInfo(){
        int i;
        string n,d, inf;
        int c;
        cout << "Введите номер - "; cin >> i;
        id = i;
        cout << "Введите название - "; cin >> n;
        name = n;
        cout << "Введите отдел - "; cin >> d;
        department = d;
        cout << "Введите цену - "; cin >> c;
        cost = c;
        cout << "Введите информацию о товаре - "; cin >> inf;
        information = inf;
        }
    ~Product(){cout << "Все очищено!" << endl;}
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int exit = 1;
    char userChoise;

    List <int> IntList;
    List <int> IntList2;
    List <double> DoubleList;
    List <char> CharList;
    List <Product> ProductList;
    //Product p;

    IntList2 + 123;
    IntList2 + 456;
    IntList2 + 789;

    while(exit)
    {
        system("cls");

        cout << "Выберите действие: " << endl;
        cout << ">>Добавление элемента в начало списка - 1" << endl;
        cout << ">>Удаление элемента из начала списка - 2" << endl;
        cout << ">>Проверка на неравенство списков - 3" << endl << endl;
        cout << ">>Вывод списка - 4" << endl << endl;
        cout << ">>Выход - 0" << endl << endl;
        cout << "Ваш выбор: ";
        cin >> userChoise;

        switch(userChoise)
        {
        case'1':
            {
                system("cls");
                char curChoise;
                cout << "Выберите действие: " << endl;
                cout << ">>Добавление элемента в начало списка INT - 1" << endl;
                cout << ">>Добавление элемента в начало списка DOUBLE - 2" << endl;
                cout << ">>Добавление элемента в начало списка CHAR - 3" << endl;
                //cout << ">>Добавление элемента в начало списка PRODUCT - 4" << endl << endl;
                cout << ">>Выход - 0" << endl << endl;
                cout << "Ваш выбор: ";
                cin >> curChoise;

                switch(curChoise)
                {
                case '1':
                    {
                        system("cls");
                        int a;
                        cout << "Введите число: ";
                        cin >> a;
                        IntList + a;
                        IntList.ShowInfo();
                        system("pause");
                        break;
                    }
                case '2':
                    {
                        system("cls");
                        double a;
                        cout << "Введите число: ";
                        cin >> a;
                        DoubleList + a;
                        DoubleList.ShowInfo();
                        system("pause");
                        break;
                    }
                case '3':
                    {
                        system("cls");
                        char a;
                        cout << "Введите символ: ";
                        cin >> a;
                        CharList + a;
                        CharList.ShowInfo();
                        system("pause");
                        break;
                    }
                case '4':
                    {
                        system("cls");

                        //ProductList + Product p;
                        //ProductList.ShowInfo();
                        system("pause");
                        break;
                    }
                case '0':{break;}
                }

                break;
            }
        case'2':
            {
                system("cls");
                char curChoise;
                cout << "Выберите действие: " << endl;
                cout << ">>Удаление элемента из начала списка INT - 1" << endl;
                cout << ">>Удаление элемента из начала списка DOUBLE - 2" << endl;
                cout << ">>Удаление элемента из начала списка CHAR - 3" << endl;
                //cout << ">>Удаление элемента из начала списка PRODUCT - 4" << endl << endl;
                cout << ">>Выход - 0" << endl << endl;
                cout << "Ваш выбор: ";
                cin >> curChoise;

                switch(curChoise)
                {
                    case '1':{--IntList;IntList.ShowInfo();system("pause");break;}
                    case '2':{--DoubleList;DoubleList.ShowInfo();system("pause");break;}
                    case '3':{--CharList;CharList.ShowInfo();system("pause");break;}
                    //case '4':{--ProductList;ProductList.ShowInfo();break;}
                    case '0':{break;}
                }
                break;
            }
        case'3':
            {
                system("cls");
                cout << "Содержимое первого листа:" << endl;
                IntList + 123;
                IntList + 456;
                IntList + 789;
                IntList.ShowInfo();cout << endl;
                cout << "Содержимое второго листа:" << endl;
                IntList2.ShowInfo();cout << endl;
                if ((IntList != IntList2) == 0){cout << "Списки не равны!" << endl;}
                else if ((IntList != IntList2) == 1){cout << "Списки равны!" << endl;}
                //IntList.cmp(IntList, IntList2);
                system("pause");
                break;
            }
        case '4':
            {
                system("cls");
                char curChoise;
                cout << "Выберите действие: " << endl;
                cout << ">>Просмотр списка INT - 1" << endl;
                cout << ">>Просмотр списка DOUBLE - 2" << endl;
                cout << ">>Просмотр списка CHAR - 3" << endl;
               // cout << ">>Просмотр списка PRODUCT - 4" << endl << endl;
                cout << ">>Выход - 0" << endl << endl;
                cout << "Ваш выбор: ";
                cin >> curChoise;

                switch(curChoise)
                {
                    case '1':{IntList.ShowInfo();system("pause");break;}
                    case '2':{DoubleList.ShowInfo();system("pause");break;}
                    case '3':{CharList.ShowInfo();system("pause");break;}
                    //case '4':{ProductList.ShowInfo();system("pause");break;}
                    case '0':{break;}
                }
                break;
            }
        case'0':{exit = 0;break;}
        }
    }

    return 0;
}
