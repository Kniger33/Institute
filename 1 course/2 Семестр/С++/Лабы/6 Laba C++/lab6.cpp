#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <vector>
#include <iterator> 
#include <stdexcept>

using namespace std;

template <class type> class Queue {
	vector <type> queue;
	int size_;
public:
	Queue(){
		size_ = 0;
	}
	~Queue(){
		queue.clear();
	}
	Queue operator +(const type &obj){
		queue.push_back(obj);
		size_ = queue.size();
		return *this;
	}
	Queue operator --(int){
		if (size_ == 0){
			cout << "Очередь пуста" << endl << endl;
			return *this;
		}
		cout << queue.front() << endl;
		queue.erase(queue.begin());
		size_ = queue.size();
		return *this;
	}
	Queue operator --(){
		if (size_ == 0){
			cout << "Очередь пуста";
			return *this;
		}
		cout << queue.front() << endl;
		queue.erase(queue.begin());
		size_ = queue.size();
		return *this;
	}
	bool operator<(const Queue &r){
		if (size_ < r.size_)
			return true;
		return false;
	}
};

class Participant {
private:
	int id_;
	string name_;
	string gender_;
	int pointOne_, 
		pointTwo_, 
		pointThree_;
	int birthDay_,
		birthMonth_,
		birthYear_;
	int64_t mobilePhone_;
public:
	Participant(){
		setParticipant();
	}
	Participant(const Participant & object){}
	~Participant(){}
	void setParticipant(){
		cout << "Введите id участника олимпиады:";
		cin >> id_;
		cout << "Введите ФИО участника:";
		cin.get();
		getline(cin, name_);
		cout << "Введите пол участника(м/ж):";
		getline(cin, gender_);
		cout << "Введите балл за задание №1:";
		cin >> pointOne_;
		cout << "Введите балл за задание №2:";
		cin >> pointTwo_;
		cout << "Введите балл за задание №3:";
		cin >> pointThree_;
		cout << "Введите дату рождения участника в формате дд.мм.гггг:";
		cin >> setw(2) >> birthDay_;
		cin.ignore();
		cin >> setw(2) >> birthMonth_;
		cin.ignore();
		cin >> setw(4) >> birthYear_;
		cout << "Введите мобильный телефон участника:";
		cin >> mobilePhone_;
		system("clear");
	}
	friend ostream& operator <<(ostream& os, Participant p);
	void getName(){
		cout << name_ ;
	}
	int cntPoint(){
		int sum;
		sum = pointOne_ + pointTwo_ + pointThree_;
		return sum;
	}
	int getBirthYear(){
		return birthYear_;
	}
	int getAge(){
		int age;
		age = 2018 - birthYear_;
		if (birthMonth_ > 4)
			age--;
		return age;
	}
	int getGender(){
		if (strcmp(gender_.c_str(), "Мужской") == 0)
			 return 1;
		return 0;
	}
};
ostream& operator <<(ostream& os, Participant p){
	cout << p.id_;
		if (strlen(p.name_.c_str()) > 44)
			cout <<"\t" << p.name_;
		else
			cout <<"\t" << p.name_ << "\t";
		if (p.birthDay_ < 10){
			if (p.birthMonth_< 10)
				cout<<"\t" << "0" << p.birthDay_<<"." << "0" << p.birthMonth_ << "." << p.birthYear_;
			else
				cout << "\t"<<"0" << p.birthDay_<<"." << p.birthMonth_ << "." << p.birthYear_;
		}
		else{
			if (p.birthMonth_< 10)
				cout <<"\t" <<p.birthDay_<<"." << "0" << p.birthMonth_ << "." << p.birthYear_;
			else
				cout << "\t"<< p.birthDay_<<"." << p.birthMonth_ << "." << p.birthYear_;
		}
		cout << "\t"<< p.gender_;
		cout << "\t" << p.pointOne_;
		cout << "\t" << p.pointTwo_;
		cout << "\t" << p.pointThree_;
		cout << "\t" << p.mobilePhone_;
}

int main(){
	Queue <int> integerType;
	Queue <int> integerType2;
	Queue <double> doubleType;
	Queue <char> charType;
	Queue <Participant> Participants;

	int a;
	double b;
	char c;

	system("clear");
	while(1){
		int number;
		cout << "1.integerType + объект" << endl << "2.integerType2 + объект" << endl << "3.doubleType + объект" << endl << "4.charType + объект" <<
		endl << "5.Participants + объект" << endl << endl<< "6.integerType--"<< endl <<"7.integerType2--" << endl << "8.doubleType--" << endl << "9.charType--" << endl <<
		"10.Participants--" << endl << "11.Сравнение integerType и integerType2" << endl << endl<< "0.Выход" << endl << endl << "Выберите: ";
		cin >> number;
		system("clear");
		switch(number){
			case 1:
				cout << "Введите элемент:";
				cin >> a;
				integerType + a;
				break;
			case 2:
				cout << "Введите элемент:";
				cin >> a;
				integerType2 + a;
				break;
			case 3:
				cout << "Введите элемент:";
				cin >> b;
				doubleType + b;
				break;
			case 4:
				cout << "Введите элемент:";
				cin >> c;
				charType + c;
				break;
			case 5:
				{
					cout << "Введите элемент:";
					Participant d;
					Participants + d;
					break;
				}
			case 6:
				integerType--;
				break;
			case 7:
				integerType2--;
				break;
			case 8:
				doubleType--;
				break;
			case 9:
				charType--;
				break;
			case 10:
				Participants--;
				break;
			case 11:
				if (integerType < integerType2)
					cout << "integerType < integerType2" << endl;
				else
					cout << "integerType !< integerType2" << endl;
				break;
			case 0:
				exit(0);
				break;
			default:
				break;
		}
	}
	return 0;

}