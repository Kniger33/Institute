#include <iostream>
#include <string>
using namespace std;
class Product{
private:
    int id;
    string name;
    string department;
    int cost;
	string information;
public:
    //�����������
	Product(int i, string n, string d, int c, string inf);
	string getDep();
	string getName();
	string getInfo();
	char FirstSymbolOfName();
	int getCost();
	int getId();
};
