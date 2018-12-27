#include <iostream>
#include <clocale>
#include <string>
#include <math.h>
#include <fstream>
#include <ctype.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	ifstream inputFile("input.txt");
	uint64_t m, q, r, phys_addr = 0, count_of_fault = 0;
	uint64_t addr[64], mpl4[9];
	uint64_t currentMpl4 = 0, physic = 0, value = 0;
	uint64_t directory_ptr_ = 0;
	uint64_t currentValue = 0;
	uint64_t currentTable = 0;
	uint64_t currentOffset = 0;
	uint64_t directory_ = 0;
	uint64_t size = 0;
	uint64_t count_of_physical = 0;

	ofstream outputFile("output.txt");
	cout << "Write your m, q, r: ";
	inputFile >> m >> q >> r;
	uint64_t paddr_array[m][2];

	cout << "Write your paddr and value: " << endl;

	for (uint64_t i = 0; i < m; i++){
		for (uint64_t j = 0; j < 2; j++){
			inputFile >> paddr_array[i][j];
		}
	}

    //ЗАПОЛНЯЕМ МАССИВ ЛОГИЧЕСКИХ АДРЕСОВ
	uint64_t logical_addres[q];
	cout << "Write your logical address:" << endl;
	for (uint64_t i = 0; i < q; i++){
		inputFile >> logical_addres[i];
	}

	cout << endl;

	for (uint64_t k = 0; k < q; k++){
		currentMpl4 = 0;
		physic = 0;
		value = 0;
		directory_ptr_ = 0;
		currentValue = 0;
		currentTable = 0;
		currentOffset = 0;
		directory_ = 0;
		size = 0;
		count_of_physical = 0;

		//ПЕРЕВОДИМ ЛОГИЧЕСКИЙ АДРЕС В ДВОИЧНУЮ СИСТЕМУ
		uint64_t logic = logical_addres[k];
		for (int j = 0; logic != 0; j++){
			addr[j] = logic % 2;
			logic /= 2;
			size++;
		}
		for (int i = size; i < 64; i++){
			addr[i] = 0;
		}

		//ВЫДЕЛЯЕМ 9 БИТ СООТВЕТСТВУЮЩИЕ mpl4
		for (int i = 39, j = 0; i <= 47; i++, j++){
			mpl4[j] = addr[i];
		}
		for (int i = 0; i < 9; i++){
			if (mpl4[i] == 1)
				currentMpl4 += pow(2, i);
		}

		//НАХОДИМ ЗНАЧЕНИЕ И ИЩЕМ ЕГО В ТАБЛИЦЕ ФИЗИЧЕСКИХ АДРЕСОВ
		physic = r + currentMpl4 * 8;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < 2; j++){
				if (physic == paddr_array[i][0]){
					value = paddr_array[i][1];
					count_of_physical = 1;
					break;
				}
			}
		}
		if (count_of_physical == 0){
			count_of_fault++;
		}

		//ВЫДЕЛЯЕМ ФИЗИЧЕСКИЙ АДРЕС ИЗ value
		int value_phys_addr[64];
		if (value % 2 == 0){
			count_of_fault++;
		}
		else{
			for (int i = 0; i < 64; i++){
				value_phys_addr[i] = 0;
			}
			for (int i = 0; value != 0; i++){
				value_phys_addr[i] = value % 2;
				value /= 2;
			}
			for (int i = 0; i < 12; i++){
				value_phys_addr[i] = 0;
			}
			for (int i = 52; i < 64; i++){
				value_phys_addr[i] = 0;
			}
		}
		currentValue = 0;
		for (int i = 12; i < 52; i++){
			if (value_phys_addr[i] == 1)
				currentValue += pow(2, i);
		}

		//ВЫДЕЛЯЕМ Directory_Ptr
		int directory_ptr[9];
		directory_ptr_ = 0;
		for (int i = 30, j = 0; i <= 38; i++, j++){
			directory_ptr[j] = addr[i];
		}
		for (int i = 0; i < 9; i++){
			if (directory_ptr[i] == 1)
				directory_ptr_ += pow(2, i);
		}

		//НАХОДИМ ЗНАЧЕНИЕ ФИЗИЧЕСКОГО АДРЕСА И ИЩЕМ ЕГО В ТАБЛИЦЕ
		physic = currentValue + directory_ptr_ * 8;
		count_of_physical = 0;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < 2; j++){
				if (physic == paddr_array[i][0]){
					value = paddr_array[i][1];
					count_of_physical = 1;
					break;
				}
			}
		}
		if (count_of_physical == 0){
			count_of_fault++;
		}

		//ВЫДЕЛЯЕМ ФИЗИЧЕСКИЙ АДРЕС ИЗ value
		if (value % 2 == 0){
			count_of_fault++;
		}
		else{
			for (int i = 0; i < 64; i++){
				value_phys_addr[i] = 0;
			}
			for (int i = 0; value != 0; i++){
				value_phys_addr[i] = value % 2;
				value /= 2;
			}
			for (int i = 0; i < 12; i++){
				value_phys_addr[i] = 0;
			}
			for (int i = 52; i < 64; i++){
				value_phys_addr[i] = 0;
			}
		}

		//ВЫДЕЛЯЕМ directory

		currentValue = 0;

		//ВЫДЕЛЯЕМ ФИЗИЧЕСКИЙ АДРЕС ИЗ  value
		for (int i = 12; i < 52; i++){
			if (value_phys_addr[i] == 1)
				currentValue += pow(2, i);
		}
		uint64_t directory[9];
		directory_ = 0;
		for (int i = 21, j = 0; i <= 29; i++, j++){
			directory[j] = addr[i];
		}
		for (int i = 0; i < 9; i++){
			if (directory[i] == 1){
				directory_ += pow(2, i);
			}
		}
		physic = currentValue + directory_ * 8;
		count_of_physical = 0;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < 2; j++){
				if (physic == paddr_array[i][0]){
					value = paddr_array[i][1];
					count_of_physical = 1;
					break;
				}
			}
		}
		if (count_of_physical == 0){
			count_of_fault++;
		}

		//ВЫДЕЛЯЕМ ФИЗИЧЕСКИЙ АДРЕС ИЗ value
		if (value % 2 == 0){
			count_of_fault++;
		}
		else{
			for (int i = 0; i < 64; i++){
				value_phys_addr[i] = 0;
			}
			for (int i = 0; value != 0; i++){
				value_phys_addr[i] = value % 2;
				value /= 2;
			}
			for (int i = 0; i < 12; i++){
				value_phys_addr[i] = 0;
			}
			for (int i = 52; i < 64; i++){
				value_phys_addr[i] = 0;
			}
		}
		currentValue = 0;
		for (int i = 12; i < 52; i++){
			if (value_phys_addr[i] == 1)
				currentValue += pow(2, i);
		}

		//ИЗВЛЕКАЕМ table_ptr
		int table[10];
		currentTable = 0;
		for (int i = 12, j = 0; i <= 20; i++, j++){
			table[j] = addr[i];
		}
		for (int i = 0; i < 9; i++){
			if (table[i] == 1)
				currentTable += pow(2, i);
		}
		physic = currentValue +  currentTable * 8;
		count_of_physical = 0;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < 2; j++){
				if (physic == paddr_array[i][0]){
					value = paddr_array[i][1];
					count_of_physical = 1;
					break;
				}
			}
		}
		if (count_of_physical == 0){
			count_of_fault++;
		}

		if (value % 2 == 0){
			count_of_fault++;
		}
		else{
			for (int i = 0; i < 64; i++){
				value_phys_addr[i] = 0;
			}
			for (int i = 0; value != 0; i++){
				value_phys_addr[i] = value % 2;
				value /= 2;
			}
			for (int i = 0; i < 12; i++){
				value_phys_addr[i] = 0;
			}
			for (int i = 52; i < 64; i++){
				value_phys_addr[i] = 0;
			}
		}

		//ВЫДЕЛЯЕМ ФИЗИЧЕСКИЙ АДРЕС ИЗ value
		currentValue = 0;
		for (int i = 12; i < 52; i++){
			if (value_phys_addr[i] == 1)
				currentValue += pow(2, i);
		}

		int offset[12];

		//НАХОДИМ offset
		currentOffset = 0;
		for (int i = 0; i < 12; i++){
			offset[i] = addr[i];
		}
		for (int i = 0; i < 12; i++){
			if (offset[i] == 1){
				currentOffset += pow(2, i);
			}
		} ;
		if (count_of_fault != 0)
			outputFile << "fault" << endl;
		else{
			physic = currentValue + currentOffset;
			outputFile << physic << endl;
		}
		count_of_fault = 0;
	}

	outputFile.close();

	return 0;
}
