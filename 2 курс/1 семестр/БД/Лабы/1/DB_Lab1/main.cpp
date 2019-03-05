#define _CRT_SECURE_NO_WARNINGS

#include "bits/stdc++.h"
#include <Windows.h>

using namespace std;

FILE *file;
string fileName;


struct Zap {
	int studentId = -1;
	char secondName[30];
	char firstName[20];
	char midName[30];
	int groupId = -1;
};


struct Block {
	Zap records[5];
};


void CreateFile() {
	if ((file = fopen(fileName.c_str(), "rb+")) == NULL) {
		if ((file = fopen(fileName.c_str(), "wb+")) == NULL) {
			cout << "Cant create and open the file" << endl;
			system("pause");
			exit(-1);
		}

		fclose(file);

		if ((file = fopen(fileName.c_str(), "rb+")) == NULL) {
			cout << "Cant create and open the file" << endl;
			system("pause");
			exit(-1);
		}
	}
}


void ShowZap(Zap &zap) {
	cout << "Student ID: " << zap.studentId << endl
         << "Second Name:  " << zap.secondName << endl
		 << "First Name:  " << zap.firstName << endl
		 << "Mid Name:  " << zap.midName << endl
		 << "Group ID:  " << zap.groupId << endl << endl;
}


int SearchStudentInDB(int inStudentId, Block &blk, uint64_t &offset) {
	fseek(file, 0, SEEK_SET);
	offset = 0;
	while (fread(&blk, sizeof(Block), 1, file)) {
		for (int i = 0; i < 5; i++) {
			if (blk.records[i].studentId == inStudentId) {
				return i;
			}
		}
		offset = ftell(file);
	}
	return -1;
}


bool ShowDB() {
	bool isDBExist = false;
	Block blk;
	fseek(file, 0, SEEK_SET);
	while (fread(&blk, sizeof(Block), 1, file)) {
		for (int i = 0; i < 5; i++) {
			if (blk.records[i].studentId != -1) {
				ShowZap(blk.records[i]);
				isDBExist = true;
			}
		}
	}
	return isDBExist;
}


void AddStudentInDB() {
	Block blk;
	Zap curStudentZap;

	system("cls");
	cout << "Enter student id: ";
	cin >> curStudentZap.studentId;
	cout << "Second name: ";
	cin >> curStudentZap.secondName;
	cout << "First name: ";
	cin >> curStudentZap.firstName;
	cout << "Mid name: ";
	cin >> curStudentZap.midName;
	cout << "Group id: ";
	cin >> curStudentZap.groupId;
	cout << endl << endl;

	uint64_t t_off;
	if (SearchStudentInDB(curStudentZap.studentId, blk, t_off) != -1) {
		cout << "This student id already exist" << endl;
		system("pause");
		return;
	}

	fseek(file, -(long long int)sizeof(Block), SEEK_END);
	fread(&blk, sizeof(Block), 1, file);

	if (blk.records[4].studentId != -1) {
		blk = Block();
		blk.records[0] = curStudentZap;
		fseek(file, 0, SEEK_END);
	}
	else {
		int i = -1;
		while (blk.records[++i].studentId > -1);
		blk.records[i] = curStudentZap;
		fseek(file, -(long long int)sizeof(Block), SEEK_END);
	}

	fwrite(&blk, sizeof(Block), 1, file);
	fclose(file);
	file = fopen(fileName.c_str(), "rb+");

	cout << "Record was successfully added!" << endl;
	system("pause");
}


void EditStudent() {
	int studentIdSearching;
	Block blk;
	uint64_t offset;

	system("cls");
	if (!ShowDB()) {
		system("cls");
		cout << "Data Base is empty!" << endl;
		system("pause");
		return;
	}
	cout << endl;
	cout << "Enter Student ID for editing:" << endl;
	cin >> studentIdSearching;
	system("cls");

	int posOfModyfStud = SearchStudentInDB(studentIdSearching, blk, offset);
	if (posOfModyfStud == -1) {
		cout << "This Student ID is not found" << endl;
		system("pause");
		return;
	}

	int userChoice;
	Block t_blk;
	uint64_t t_off;
	while (true)
	{
		system("cls");

		cout << "Edit Student: " << endl << endl;
		ShowZap(blk.records[posOfModyfStud]);
		cout << endl;
		cout << "What you want to edit:" << endl;
		cout << "1) Student ID" << endl;
		cout << "2) Second name" << endl;
		cout << "3) First name" << endl;
		cout << "4) Mid name" << endl;
		cout << "5) Group ID" << endl << endl;
		cout << "0) Back" << endl << endl;

		cin >> userChoice;

		system("cls");

		switch (userChoice)
		{
		case 1:
			int newId;
			cout << "Enter new student ID:" << endl;
			cin >> newId;
			if (SearchStudentInDB(newId, t_blk, t_off) != -1) {
				cout << "This Student ID already exists" << endl;
				system("pause");
			}
			else {
				blk.records[posOfModyfStud].studentId = newId;
			}
			break;
		case 2:
			char newSecondName[30];
			cout << "Enter new second name:" << endl;
			cin >> newSecondName;
			strcpy(blk.records[posOfModyfStud].secondName, newSecondName);
			break;
		case 3:
			char newFirstName[20];
			cout << "Enter new first name:" << endl;
			cin >> newFirstName;
			strcpy(blk.records[posOfModyfStud].firstName, newFirstName);
			break;
		case 4:
			char newMidName[30];
			cout << "Enter new third name:" << endl;
			cin >> newMidName;
			strcpy(blk.records[posOfModyfStud].midName, newMidName);
			break;
		case 5:
			int newGroupID;
			cout << "Enter new group ID:" << endl;
			cin >> newGroupID;
			blk.records[posOfModyfStud].groupId = newGroupID;
			break;
		case 0:
			fseek(file, offset, SEEK_SET);
			fwrite(&blk, sizeof(Block), 1, file);
			return;
			break;
		default:
			break;
		}
	}
}


void DeleteStudent() {
	int studentIdSearching;
	Block blk;
	uint64_t offset;

	system("cls");
	if (!ShowDB()) {
		system("cls");
		cout << "Data Base is empty!" << endl;
		system("pause");
		return;
	}
	cout << endl;
	cout << "Enter Student ID for deleting:" << endl;
	cin >> studentIdSearching;
	system("cls");

	int posOfDelStud = SearchStudentInDB(studentIdSearching, blk, offset);
	if (posOfDelStud == -1) {
		cout << "This Student ID is not found" << endl;
		system("pause");
		return;
	}
	Block lastBlock;
	uint64_t lastOffset;
	fseek(file, -(long)sizeof(Block), SEEK_END);
	lastOffset = ftell(file);
	fread(&lastBlock, sizeof(Block), 1, file);

	if (lastOffset == offset) {
		if (posOfDelStud == 4 || blk.records[posOfDelStud + 1].studentId == -1) {
			blk.records[posOfDelStud] = Zap();
		}
		else {
			int i = 1;
			while (posOfDelStud + i < 4 && blk.records[posOfDelStud + i + 1].studentId != -1) {
				i++;
			}
			blk.records[posOfDelStud] = blk.records[posOfDelStud + i];
			blk.records[posOfDelStud + i] = Zap();
		}
		lastBlock = blk;
	}
	else {
		int i = 0;
		while (lastBlock.records[i + 1].studentId != -1 && i < 4) {
			i++;
		}
		blk.records[posOfDelStud] = lastBlock.records[i];
		lastBlock.records[i] = Zap();
		fseek(file, lastOffset, SEEK_SET);
		fwrite(&lastBlock, sizeof(Block), 1, file);
	}
	fseek(file, offset, SEEK_SET);
	fwrite(&blk, sizeof(Block), 1, file);
	fclose(file);
	file = fopen(fileName.c_str(), "rb+");

	if (lastBlock.records[0].studentId == -1) {
		fclose(file);
		HANDLE hFile = CreateFile(fileName.c_str(), GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_FLAG_RANDOM_ACCESS, NULL);
		if (hFile == INVALID_HANDLE_VALUE) {
			cout << "Can't delete block from file!" << endl;
			system("pause");
			exit(-1);
		}
		SetFilePointer(hFile, lastOffset, 0, FILE_BEGIN);
		SetEndOfFile(hFile);
		CloseHandle(hFile);
		CreateFile();
	}
}


int SearchStudentByAnyInfo(string &infoForSearching) {
	Block blk;
	int find = -1;
	fseek(file, 0, SEEK_SET);
	while (fread(&blk, sizeof(Block), 1, file)) {
		for (int i = 0; i < 5; i++) {
			if (to_string(blk.records[i].studentId) == infoForSearching || blk.records[i].secondName == infoForSearching
				|| blk.records[i].firstName == infoForSearching || blk.records[i].midName == infoForSearching
				|| to_string(blk.records[i].groupId) == infoForSearching) {
                    ShowZap(blk.records[i]);
                    find = 1;
			}
		}
	}
	return find;
}

int main() {
	cout << "Enter filename:" << endl;
	cin >> fileName;
	CreateFile();

	string inInfo;
	int userChoice;
	while (true)
	{
		system("cls");

		cout << "Main Menu: " << endl << endl;
		cout << "1) Add student" << endl;
		cout << "2) Modify student" << endl;
		cout << "3) Delete student" << endl;
		cout << "4) Find student" << endl;
		cout << "5) Show all students" << endl << endl;
		cout << "0) Exit" << endl << endl;

		cin >> userChoice;

		system("cls");

		switch (userChoice)
		{
		case 1:
			AddStudentInDB();
			break;
		case 2:
			EditStudent();
			break;
		case 3:
			DeleteStudent();
			break;
		case 4:
			cout << "Enter information for searching:" << endl;
			cin >> inInfo;
			system("cls");
			if (SearchStudentByAnyInfo(inInfo) == -1) {
				cout << "The entered information is incorrect or the student with such information doesn't exist!" << endl;
			}
			system("pause");
			break;
		case 5:
			if (!ShowDB()) {
				system("cls");
				cout << "Data Base is empty!" << endl;
			}
			system("pause");
			break;
		case 0:
			fclose(file);
			exit(0);
			break;
		default:
			break;
		}
	}
	return 0;
}
