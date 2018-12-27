#include <inttypes.h>
#include <cstdint>
#include <iostream>
#include <clocale>
#include <string>
#include <math.h>
#include <fstream>
#include <ctype.h>
using namespace std;

void BitSet(uint64_t &value, uint64_t &currentValue, uint64_t &countOfFault, int valuePhysicalAddres[64])
{
    if (value % 2 == 0){
			countOfFault++;
		}
		else{
			for (int i = 0; i < 64; i++){
				valuePhysicalAddres[i] = 0;
			}
			for (int i = 0; value != 0; i++){
				valuePhysicalAddres[i] = value % 2;
                value /= 2;
			}
			for (int i = 0; i < 12; i++){
				valuePhysicalAddres[i] = 0;
			}
			for (int i = 52; i < 64; i++){
				valuePhysicalAddres[i] = 0;
			}
		}
    currentValue = 0;
		for (int i = 12; i < 52; i++){
			if (valuePhysicalAddres[i] == 1)
				currentValue += pow(2, i);
		}

}

int main()
{
	ifstream fin("dataset.txt");
	uint64_t value = 0;
    uint64_t countOfFault = 0;
    uint64_t currentValue = 0;
	uint64_t m, q, r, phys_addr = 0;
	uint64_t addr[64], mpl4Massive[9];
	uint64_t currentMpl4 = 0, physic = 0;
	uint64_t directoryPtr = 0;
	uint64_t currentTable = 0;
	uint64_t currentOffset = 0;
	uint64_t directory_ = 0;
	uint64_t size = 0;
	uint64_t countOfPhysical = 0;

	ofstream fout("output.txt");
	cout << "Reading count..." << endl;
	fin >> m >> q >> r;
	uint64_t paddrArray[m][2];

	cout << "Reading paddr and value..." << endl;

	for (uint64_t i = 0; i < m; i++){
		for (uint64_t j = 0; j < 2; j++){
			fin >> paddrArray[i][j];
		}
	}

	uint64_t logicalAddresMassive[q];

	cout << "Read logical address..." << endl << endl;
	for (uint64_t i = 0; i < q; i++){
		fin >> logicalAddresMassive[i];
	}

	for (uint64_t k = 0; k < q; k++){
		currentMpl4 = 0;
		physic = 0;
		value = 0;
		directoryPtr = 0;
		currentValue = 0;
		currentTable = 0;
		currentOffset = 0;
		directory_ = 0;
		size = 0;
		countOfPhysical = 0;

		uint64_t logic = logicalAddresMassive[k];
		for (int j = 0; logic != 0; j++){
			addr[j] = logic % 2;
			logic /= 2;
			size++;
		}
		for (int i = size; i < 64; i++){
			addr[i] = 0;
		}

		for (int i = 39, j = 0; i <= 47; i++, j++){
			mpl4Massive[j] = addr[i];
		}
		for (int i = 0; i < 9; i++){
			if (mpl4Massive[i] == 1)
				currentMpl4 += pow(2, i);
		}

		physic = r + currentMpl4 * 8;

		for (int i = 0; i < m; i++){
			for (int j = 0; j < 2; j++){
				if (physic == paddrArray[i][0]){
					value = paddrArray[i][1];
					countOfPhysical = 1;
					break;
				}
			}
		}
		if (countOfPhysical == 0){
			countOfFault++;
		}

		int valuePhysicalAddres[64];

		BitSet(value, currentValue, countOfFault, valuePhysicalAddres);

		int directoryPtrMassive[9];

		directoryPtr = 0;

		for (int i = 30, j = 0; i <= 38; i++, j++){
			directoryPtrMassive[j] = addr[i];
		}
		for (int i = 0; i < 9; i++){
			if (directoryPtrMassive[i] == 1)
				directoryPtr += pow(2, i);
		}

		physic = currentValue + directoryPtr * 8;
		countOfPhysical = 0;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < 2; j++){
				if (physic == paddrArray[i][0]){
					value = paddrArray[i][1];
					countOfPhysical = 1;
					break;
				}
			}
		}
		if (countOfPhysical == 0){
			countOfFault++;
		}

		BitSet(value, currentValue, countOfFault, valuePhysicalAddres);

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
		countOfPhysical = 0;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < 2; j++){
				if (physic == paddrArray[i][0]){
					value = paddrArray[i][1];
					countOfPhysical = 1;
					break;
				}
			}
		}
		if (countOfPhysical == 0){
			countOfFault++;
		}

		BitSet(value, currentValue, countOfFault, valuePhysicalAddres);

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
		countOfPhysical = 0;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < 2; j++){
				if (physic == paddrArray[i][0]){
					value = paddrArray[i][1];
					countOfPhysical = 1;
					break;
				}
			}
		}
		if (countOfPhysical == 0){
			countOfFault++;
		}

		BitSet(value, currentValue, countOfFault, valuePhysicalAddres);

		int offsetMassive[12];

		currentOffset = 0;
		for (int i = 0; i < 12; i++){
			offsetMassive[i] = addr[i];
		}
		for (int i = 0; i < 12; i++){
			if (offsetMassive[i] == 1){
				currentOffset += pow(2, i);
			}
		}

		cout << "Writing physical address..." << endl;

		if (countOfFault != 0)
			fout << "fault" << endl;
		else{
			physic = currentValue + currentOffset;
			fout << physic << endl;
		}
		countOfFault = 0;
	}

	cout << endl << "Done!" << endl;

	fout.close();
	return 0;
}
