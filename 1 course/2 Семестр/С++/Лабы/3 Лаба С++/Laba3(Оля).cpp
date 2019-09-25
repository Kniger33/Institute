#include <iostream>
#include <string>
#include <iomanip>
#include <clocale>
#include <process.h>

using namespace std;

class Worker{
	private:
		int id;
		string first_name;
		string name;
		string second_name;
		string adress;
		int64_t phone_number;
		string sex;
		int birthyear;
		string work;
		int sum;
		bool vo;

	public:
		Worker(){}

		Worker(const Worker &some_object){}

		Worker(int ID, string FIRST_NAME, string NAME, string SECOND_NAME, string ADRESS, int64_t PHONE_NUMBER, string SEX, int BIRTHYEAR, string WORK, int SUM, bool VO){
			id = ID;
			first_name = FIRST_NAME;
			name = NAME;
			second_name = SECOND_NAME;
			adress = ADRESS;
			phone_number = PHONE_NUMBER;
			sex = SEX;
			birthyear = BIRTHYEAR;
			work = WORK;
			sum = SUM;
			vo = VO;
		}

		void setWorker(){
			cout << "Введите табельный номер сотрудника:" << endl;
			cin >> id;
			cout << "Введите Фамилию, Имя и Отчество сотрудника:" << endl;
			cin >> first_name >> name >> second_name;
			cout << "Введите адрес сотрудника:" << endl;
			cin >> adress;
			cout << "Введите телефонный номер сотрудника:" << endl;
			cin >> phone_number;
			cout << "Введите пол сотрудника:" << endl;
			cin >> sex;
			cout << "Введите год рождения сотрудника:" << endl;
			cin >> birthyear;
			cout << "Введите занимаемую должность сотрудника:" << endl;
			cin >> work;
			cout << "Введите оклад сотрудника:" << endl;
			cin >> sum;
			cout << "Введите наличие высшего образования:" << endl;
			cin >> vo;
		}

		int getID(){
			return id;
		}

		string getFirst_name(){
			return first_name;
		}

		string getName(){
			return name;
		}

		string getSecond_name(){
			return second_name;
		}

        string getWork(){
			return work;
		}

		string getSex(){
			return sex;
		}

		int getSum(){
            return sum;
		}

		int getBirthyear(){
            return birthyear;
		}

		bool getVO(){
            return vo;
		}

		void getInfo(){
			cout << "ID: " << id << endl;
			cout << "ФИО: " << first_name << " " << name << " " << second_name << endl;
			cout << "Адрес: " << adress << endl;
			cout << "Телефонный номер: " << phone_number << endl;
			cout << "Пол: " << sex << endl;
			cout << "Год рождения: " << birthyear << endl;
			cout << "Должность: " << work << endl;
			cout << "Оклад: " << sum << endl;
			cout << "Высшее образование: " << vo << endl;
		}

		~Worker(){}
};

void searchWorkersOfSum(Worker *workers, int workers_cnt){
    int sum_of_search;
    cout << "Введите сумму, которую должен превышать оклад: " << endl;
    cin >> sum_of_search;
    for (int i = 0; i < workers_cnt; i++){
        if (workers[i].getSum() <= sum_of_search){
            workers[i].getInfo();
        }
    }
}

void searchWorkersOfWorkAndEducation(Worker *workers, int workers_cnt){
    string work_of_search;
    cout << "Введите должность для поиска: " << endl;
    cin.get();
    getline(cin, work_of_search);
    for (int i = 0; i < workers_cnt; i++){
        if ((workers[i].getWork() == work_of_search) && (workers[i].getVO())){
            workers[i].getInfo();
        }
    }
}

void printTable(Worker *workers, int workers_cnt){
	cout << "ID" << " ФИО" << "                    Должность" << "   Пол" << endl;
	for (int i = 0; i < workers_cnt; i++){
		cout << workers[i].getID() << "  " << workers[i].getFirst_name() << " " << workers[i].getName() << " "
		<< workers[i].getSecond_name() << "           " << workers[i].getWork() << "            " << workers[i].getSex() << endl;
	}
}

void countOfMaleWorkers (Worker *workers, int workers_cnt){
    int age;
    cout << "Введите возраст, старше которого должны быть сотрудники:" << endl;
    cin >> age;
    for (int i = 0; i < workers_cnt; i++){
        if ((workers[i].getSex() == "Male") && ((2018 - workers[i].getBirthyear()) >= age)){
            workers[i].getInfo();
        }
    }
}

float AverageOfFemalWorkers(Worker *workers, int workers_cnt){
    int sum = 0, count = 0;
    for (int i = 0; i< workers_cnt; i++){
        if (workers[i].getSex() == "Female"){
            count++;
            int age = 2018 - workers[i].getBirthyear();
            sum = sum + age;
        }
    }
    float answer = sum / count;
    return answer;
}

int main(){
setlocale(LC_ALL, "Russian");

        int id;
		string first_name;
		string name;
		string second_name;
		string adress;
		int64_t phone_number;
		string sex;
		string birthyear;
		string work;
		int sum;
		bool vo;

    cout << "Создайте базу данных сотрудников" << endl;
	cout << "Введите кол-во сотрудников:" << endl;
	int workers_cnt;
	cin >> workers_cnt;
	Worker *workers =  new Worker[workers_cnt];
	for (int i = 0; i < workers_cnt; i++){
            cout << "Введите табельный номер сотрудника:" << endl;
			cin >> id;
			cout << "Введите Фамилию, Имя и Отчество сотрудника:" << endl;
			cin >> first_name >> name >> second_name;
			cout << "Введите адрес сотрудника:" << endl;
			cin >> adress;
			cout << "Введите телефонный номер сотрудника:" << endl;
			cin >> phone_number;
			cout << "Введите пол сотрудника:" << endl;
			cin >> sex;
			cout << "Введите год рождения сотрудника:" << endl;
			cin >> birthyear;
			cout << "Введите занимаемую должность сотрудника:" << endl;
			cin >> work;
			cout << "Введите оклад сотрудника:" << endl;
			cin >> sum;
			cout << "Введите наличие высшего образования:" << endl;
			cin >> vo;
	}

		while (1){
		char function_number;

		cout << "1- Поиск информации о сотрудниках, работающих на должностях с заданным окладом" << endl
		<< "2- Поиск информации о сотрудниках, работающих на заданной должности и имеющих высшее образование" << endl
	 	<< "3- Отображение информации о сотрудниках фирмы в виде таблицы" << endl
		<< "4- Определение количества сотрудников мужского пола, возраст которых более заданного" << endl
		<< "5- Определение среднего возраста сотрудников женского пола" << endl
		<< "0- выход" << endl << endl
		<< "Введите номер команды:" << endl;
		cin >> function_number;
		switch (function_number){
			case '1':
				searchWorkersOfSum(workers, workers_cnt);
				break;
			case '2':
				searchWorkersOfWorkAndEducation(workers, workers_cnt);
				break;
			case '3':
				printTable(workers, workers_cnt);
				break;
			case '4':
				countOfMaleWorkers(workers, workers_cnt);
				break;
			case '5':
				AverageOfFemalWorkers(workers, workers_cnt);
				break;
            case '0':
                return 0;
                break;
			default:
				break;
		}
	}

    for (int i = 0; i < workers_cnt; i++){
		workers[i].~Worker();
	}
	operator delete (workers);
	return 0;
}
