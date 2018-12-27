/*������� 25
����������� ����� List (���������������� ������). � �������� ����������� ����� ������������ �������������, ������������ �
���������� ����. ��� ����������������� ���� ������������ ����� �� ������������ ������ � 3. ����������� ��������� ��������:
1) ���������� �������� � ������ ������ (list + item);
2) �������� �������� �� ������ ������ (--list);
3) �������� �� ����������� ������� (!=).*/

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
    T someValue;          //��������
    Node* m_next;         //��������� �� ��������� ����
    Node(): m_next(NULL){};
    Node(const T& t) : someValue(t), m_next(NULL){};
};
    Node* m_head;         // ������ ������������ ������

public:
    List();
    ~List();
    //���������� ���� � ������
    void Add( const T& t );
    //void Add( const T& t);
    //�������� ���������� ������������ ���� �� ������
    void Remove();
    //������ ������
    size_t MySize() const;
    //T GTV(){return T::Node->someValue;}
    void cmp(List, List);

    class Iterator {
    private:
        Node* m_node;
    public:
        Iterator (Node* node): m_node(node){};
        // �������� �� ���������
        bool operator==( const Iterator& other ) const {
            if( this == &other ) {
                return true;
            }
            return m_node == other.m_node;
        }

        // �������� �� �����������
        bool operator!=( const Iterator& other ) const {
            return !operator==( other );
        }

        // ��������� �������� �������� ����
        T operator*() const {
            if( m_node ) {
                return m_node->m_t;
            } // ����� ��������� ����� ������
            cout << "����� ������" << endl;
            return T();
        }

        // ������� � ���������� ����
        void operator++() {
            if( m_node ) {
                m_node = m_node->m_next;
            } // ����� ��������� ����� ������.
            cout << "����� ������" << endl;
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
            node->m_next = m_head;          //����� ���� ������������� � ������� ��������� ��������
            m_head = node;                  // ����� ���� ��� ���������� �������� ���������
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
        if(m_head){          //���� �� ����
        Node* newHead = m_head->m_next;          // ��������� ��������� �� ������ ����, ������� ������ ����� �������� ���������
        delete m_head;                           // ����������� ������, ���������� ��� ���������� ��������� ��������
        m_head = newHead;                        // ��������� ����� �������� �������
    }
    else cout << "������ ����!" << endl;
    }

};

template <typename T>
List <T>:: List(): m_head(NULL){};

template <typename T>
void List <T>:: Add(const T &t){
    if(Node* node = new Node(t)){
        node->m_next = m_head;          //����� ���� ������������� � ������� ��������� ��������
        m_head = node;                  // ����� ���� ��� ���������� �������� ���������
    }
}

template <typename T>
void List <T>:: Remove(){
    if(m_head){          //���� �� ����
        Node* newHead = m_head->m_next;          // ��������� ��������� �� ������ ����, ������� ������ ����� �������� ���������
        delete m_head;                           // ����������� ������, ���������� ��� ���������� ��������� ��������
        m_head = newHead;                        // ��������� ����� �������� �������
    }
    else cout << "������ ����!" << endl;
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
    //�����������
    Product(){};
	Product(const Product &some_obj);
    string getDep(){return department;}
    string getName(){return name;}
    string getInfo(){return information;}
    char FirstSymbolOfName(){return name[0];}
    int getCost(){return cost;}
    int getId(){return id;}
    void ShowInfo(){
        cout << "|����� - " << id << endl;
        cout << "|�������� - " << name << endl;
        cout << "|����� - " << department << endl;
        cout << "|���� - " << cost << endl;
        cout << "|���������� � ������ - " << information << endl;
    }
    void SetInfo(){
        int i;
        string n,d, inf;
        int c;
        cout << "������� ����� - "; cin >> i;
        id = i;
        cout << "������� �������� - "; cin >> n;
        name = n;
        cout << "������� ����� - "; cin >> d;
        department = d;
        cout << "������� ���� - "; cin >> c;
        cost = c;
        cout << "������� ���������� � ������ - "; cin >> inf;
        information = inf;
        }
    ~Product(){cout << "��� �������!" << endl;}
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

        cout << "�������� ��������: " << endl;
        cout << ">>���������� �������� � ������ ������ - 1" << endl;
        cout << ">>�������� �������� �� ������ ������ - 2" << endl;
        cout << ">>�������� �� ����������� ������� - 3" << endl << endl;
        cout << ">>����� ������ - 4" << endl << endl;
        cout << ">>����� - 0" << endl << endl;
        cout << "��� �����: ";
        cin >> userChoise;

        switch(userChoise)
        {
        case'1':
            {
                system("cls");
                char curChoise;
                cout << "�������� ��������: " << endl;
                cout << ">>���������� �������� � ������ ������ INT - 1" << endl;
                cout << ">>���������� �������� � ������ ������ DOUBLE - 2" << endl;
                cout << ">>���������� �������� � ������ ������ CHAR - 3" << endl;
                //cout << ">>���������� �������� � ������ ������ PRODUCT - 4" << endl << endl;
                cout << ">>����� - 0" << endl << endl;
                cout << "��� �����: ";
                cin >> curChoise;

                switch(curChoise)
                {
                case '1':
                    {
                        system("cls");
                        int a;
                        cout << "������� �����: ";
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
                        cout << "������� �����: ";
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
                        cout << "������� ������: ";
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
                cout << "�������� ��������: " << endl;
                cout << ">>�������� �������� �� ������ ������ INT - 1" << endl;
                cout << ">>�������� �������� �� ������ ������ DOUBLE - 2" << endl;
                cout << ">>�������� �������� �� ������ ������ CHAR - 3" << endl;
                //cout << ">>�������� �������� �� ������ ������ PRODUCT - 4" << endl << endl;
                cout << ">>����� - 0" << endl << endl;
                cout << "��� �����: ";
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
                cout << "���������� ������� �����:" << endl;
                IntList + 123;
                IntList + 456;
                IntList + 789;
                IntList.ShowInfo();cout << endl;
                cout << "���������� ������� �����:" << endl;
                IntList2.ShowInfo();cout << endl;
                if ((IntList != IntList2) == 0){cout << "������ �� �����!" << endl;}
                else if ((IntList != IntList2) == 1){cout << "������ �����!" << endl;}
                //IntList.cmp(IntList, IntList2);
                system("pause");
                break;
            }
        case '4':
            {
                system("cls");
                char curChoise;
                cout << "�������� ��������: " << endl;
                cout << ">>�������� ������ INT - 1" << endl;
                cout << ">>�������� ������ DOUBLE - 2" << endl;
                cout << ">>�������� ������ CHAR - 3" << endl;
               // cout << ">>�������� ������ PRODUCT - 4" << endl << endl;
                cout << ">>����� - 0" << endl << endl;
                cout << "��� �����: ";
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
