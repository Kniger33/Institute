#define _CRT_SECURE_NO_WARNINGS

#include "bits/stdc++.h"
#include <Windows.h>


using namespace std;

FILE *file;
string fileName;

struct ZeroBlock {
	char relation_scheme[255] = "StudID SecondName FirstName MidName GroupID";
	int catalog[4] = { NULL };
} zeroBlk;

struct Zap {
	int studentId = -1;
	char secondName[30];
	char firstName[20];
	char midName[30];
	int groupId = -1;
};

struct Block {
	Zap zap_block[5];
	uint64_t nextBlock = NULL;
	uint64_t prevBlock = NULL;
};

int hashFunction(int &id) {
	return id % 4;
}

void CreateFile() {

	if ((file = fopen(fileName.c_str(), "rb+")) == NULL) {
		if ((file = fopen(fileName.c_str(), "wb+")) == NULL) {
			cout << "Cant create and open the file" << endl;
			system("pause");
			exit(-1);
		}

		fwrite(&zeroBlk, sizeof(ZeroBlock), 1, file);

		fclose(file);

		if ((file = fopen(fileName.c_str(), "rb+")) == NULL) {
			cout << "Cant create and open the file" << endl;
			system("pause");
			exit(-1);
		}
	}
	else {
		fread(&zeroBlk, sizeof(ZeroBlock), 1, file);
	}
}

void ShowZap(Zap &zap) {
	cout << "Student ID: " << zap.studentId << endl
		<< "Second name: " << zap.secondName << endl
		<< "First name: " << zap.firstName << endl
		<< "Mid name: " << zap.midName << endl
		<< "Group ID: " << zap.groupId << endl;
}

int SearchStudentInDB(int id, Block &blk, uint64_t &offset) {
	offset = zeroBlk.catalog[hashFunction(id)];

	while (offset != NULL) {
		fseek(file, offset, SEEK_SET);
		fread(&blk, sizeof(Block), 1, file);

		for (int i = 0; i < 5; i++) {
			if (blk.zap_block[i].studentId == id) {
				return i;
			}
		}
		offset = blk.nextBlock;
	}
	return -1;
}

int SearchStudentByAnyInfo(string &textForSearching) {
	Block blk;
	int find = -1;

	for (int i = 0; i < 4; i++) {
		uint64_t offset = zeroBlk.catalog[i];

		while (offset != NULL) {
			fseek(file, offset, SEEK_SET);
			fread(&blk, sizeof(Block), 1, file);

			for (int j = 0; j < 5; j++) {
				if (to_string(blk.zap_block[j].studentId) == textForSearching || blk.zap_block[j].secondName == textForSearching
					|| blk.zap_block[j].firstName == textForSearching || blk.zap_block[j].midName == textForSearching
					|| to_string(blk.zap_block[j].groupId) == textForSearching) {
					ShowZap(blk.zap_block[j]);
					find = 1;
				}
			}
			offset = blk.nextBlock;
		}
	}
	return find;
}

bool ShowDB() {
	bool isDBExists = false;
	Block blk;

	for (int i = 0; i < 4; i++) {
		uint64_t offset = zeroBlk.catalog[i];

		while (offset != NULL) {
			fseek(file, offset, SEEK_SET);
			fread(&blk, sizeof(Block), 1, file);

			for (int j = 0; j < 5; j++) {
				if (blk.zap_block[j].studentId != -1) {
					ShowZap(blk.zap_block[j]);
					isDBExists = true;
				}
			}
			offset = blk.nextBlock;
		}
	}
	return isDBExists;
}

void AddStudentInDB() {
	Block blk;
	Zap studentZap;

	system("cls");
	cout << "Enter information: " << endl;
	cout << "Student id: ";
	cin >> studentZap.studentId;
	cout << "Second name: ";
	cin >> studentZap.secondName;
	cout << "First name: ";
	cin >> studentZap.firstName;
	cout << "Mid name: ";
	cin >> studentZap.midName;
	cout << "Group id: ";
	cin >> studentZap.groupId;
	cout << endl << endl;
	system("cls");

	uint64_t t_off;
	if (SearchStudentInDB(studentZap.studentId, blk, t_off) != -1) {
		cout << "This student ID already exist" << endl;
		system("pause");
		return;
	}

	t_off = zeroBlk.catalog[hashFunction(studentZap.studentId)];

	if (t_off == NULL) {
		fseek(file, 0, SEEK_END);
		t_off = ftell(file);

		fseek(file, 0, SEEK_SET);
		zeroBlk.catalog[hashFunction(studentZap.studentId)] = t_off;
		fwrite(&zeroBlk, sizeof(ZeroBlock), 1, file);

		blk.zap_block[0] = studentZap;

		fseek(file, t_off, SEEK_SET);
	}
	else {
		while (t_off != NULL) {
			fseek(file, t_off, SEEK_SET);
			fread(&blk, sizeof(Block), 1, file);
			t_off = blk.nextBlock;
		}

		fseek(file, -(long long int)sizeof(Block), SEEK_CUR);

		if (blk.zap_block[4].studentId != -1) {
			uint64_t prevOffset = ftell(file);

			fseek(file, 0, SEEK_END);
			t_off = ftell(file);

			blk.nextBlock = t_off;
			fseek(file, prevOffset, SEEK_SET);
			fwrite(&blk, sizeof(Block), 1, file);

			blk = Block();
			blk.zap_block[0] = studentZap;
			blk.prevBlock = prevOffset;

			fseek(file, t_off, SEEK_SET);
		}
		else {
			int i = -1;
			while (blk.zap_block[++i].studentId > -1);
			blk.zap_block[i] = studentZap;
		}
	}

	fwrite(&blk, sizeof(Block), 1, file);

	fclose(file);
	file = fopen(fileName.c_str(), "rb+");
}

void EditStudent() {
	int idSearching;
	Block blk;
	uint64_t offset;

	system("cls");
	cout << zeroBlk.relation_scheme << endl;
	if (!ShowDB()) {
		system("cls");
		cout << "Data Base is empty!" << endl;
		system("pause");
		return;
	}
	cout << endl;
	cout << "Enter Student ID for editing:" << endl;
	cin >> idSearching;
	system("cls");

	int pos = SearchStudentInDB(idSearching, blk, offset);
	if (pos == -1) {
		cout << "This Student ID is not found" << endl;
		system("pause");
		return;
	}

	int choice;
	Block t_blk;
	uint64_t t_off;
	while (true)
	{
		system("cls");

		cout << "Edit Student: " << endl;
		ShowZap(blk.zap_block[pos]);
		cout << endl;
		cout << "1) Second name" << endl;
		cout << "2) First name" << endl;
		cout << "3) Mid name" << endl;
		cout << "4) Group ID" << endl << endl;
		cout << "0) Back" << endl << endl;

		cin >> choice;

		system("cls");

		switch (choice)
		{
		case 1:
			char newSecondName[30];
			cout << "Enter new second name:" << endl;
			cin >> newSecondName;
			strcpy(blk.zap_block[pos].secondName, newSecondName);
			break;
		case 2:
			char newFirstName[20];
			cout << "Enter new first name:" << endl;
			cin >> newFirstName;
			strcpy(blk.zap_block[pos].firstName, newFirstName);
			break;
		case 3:
			char newMidName[30];
			cout << "Enter new mid name:" << endl;
			cin >> newMidName;
			strcpy(blk.zap_block[pos].midName, newMidName);
			break;
		case 4:
			int newGroupID;
			cout << "Enter new group ID:" << endl;
			cin >> newGroupID;
			blk.zap_block[pos].groupId = newGroupID;
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
	int idSearching;
	Block blk;
	uint64_t offset;

	system("cls");
	cout << zeroBlk.relation_scheme << endl;
	if (!ShowDB()) {
		system("cls");
		cout << "Data Base is empty!" << endl;
		system("pause");
		return;
	}
	cout << endl;
	cout << "Enter Student ID for deleting:" << endl;
	cin >> idSearching;
	system("cls");

	int pos = SearchStudentInDB(idSearching, blk, offset);
	if (pos == -1) {
		cout << "This Student ID is not found" << endl;
		system("pause");
		return;
	}

	Block lastBlkBucket = blk;
	uint64_t lastOffsetBucket = offset;

	while (lastBlkBucket.nextBlock != NULL) {
		fseek(file, lastBlkBucket.nextBlock, SEEK_SET);
		lastOffsetBucket = ftell(file);
		fread(&lastBlkBucket, sizeof(Block), 1, file);
	}

	if (lastOffsetBucket == offset) {
		if (pos == 4 || blk.zap_block[pos + 1].studentId == -1) {
			blk.zap_block[pos] = Zap();
		}
		else {
			int i = 1;
			while (pos + i < 4 && blk.zap_block[pos + i + 1].studentId != -1) {
				i++;
			}
			blk.zap_block[pos] = blk.zap_block[pos + i];
			blk.zap_block[pos + i] = Zap();
		}
		lastBlkBucket = blk;
	}
	else {
		int i = 0;
		while (lastBlkBucket.zap_block[i + 1].studentId != -1 && i < 4) {
			i++;
		}
		blk.zap_block[pos] = lastBlkBucket.zap_block[i];
		lastBlkBucket.zap_block[i] = Zap();
		fseek(file, lastOffsetBucket, SEEK_SET);
		fwrite(&lastBlkBucket, sizeof(Block), 1, file);
	}
	fseek(file, offset, SEEK_SET);
	fwrite(&blk, sizeof(Block), 1, file);

	if (lastBlkBucket.zap_block[0].studentId == -1) {
		Block t_blk;
		uint64_t lastOffset;
		if (lastBlkBucket.prevBlock == NULL) {
			zeroBlk.catalog[hashFunction(idSearching)] = NULL;
			fseek(file, 0, SEEK_SET);
			fwrite(&zeroBlk, sizeof(ZeroBlock), 1, file);
		}
		else {
			fseek(file, lastBlkBucket.prevBlock, SEEK_SET);
			fread(&t_blk, sizeof(Block), 1, file);
			t_blk.nextBlock = NULL;
			fseek(file, lastBlkBucket.prevBlock, SEEK_SET);
			fwrite(&t_blk, sizeof(Block), 1, file);
		}

		fseek(file, -(long long int)sizeof(Block), SEEK_END);
		lastOffset = ftell(file);

		if (lastOffset != lastOffsetBucket) {
			fread(&t_blk, sizeof(Block), 1, file);

			fseek(file, lastOffsetBucket, SEEK_SET);
			fwrite(&t_blk, sizeof(Block), 1, file);

			if (t_blk.prevBlock != NULL) {
				fseek(file, t_blk.prevBlock, SEEK_SET);
				fread(&lastBlkBucket, sizeof(Block), 1, file);
				lastBlkBucket.nextBlock = lastOffsetBucket;
				fseek(file, t_blk.prevBlock, SEEK_SET);
				fwrite(&lastBlkBucket, sizeof(Block), 1, file);
			}
			else {
				zeroBlk.catalog[hashFunction(t_blk.zap_block[0].studentId)] = lastOffsetBucket;
				fseek(file, 0, SEEK_SET);
				fwrite(&zeroBlk, sizeof(ZeroBlock), 1, file);
			}

			if (t_blk.nextBlock != NULL) {
				fseek(file, t_blk.nextBlock, SEEK_SET);
				fread(&lastBlkBucket, sizeof(Block), 1, file);
				lastBlkBucket.prevBlock = lastOffsetBucket;
				fseek(file, t_blk.nextBlock, SEEK_SET);
				fwrite(&lastBlkBucket, sizeof(Block), 1, file);
			}
		}

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

int main() {

	cout << "Enter filename:" << endl;
	cin >> fileName;
	CreateFile();

	string text;
	int choice;
	while (true)
	{
		system("cls");

		cout << "Main Menu: " << endl << endl;
		cout << "1) Add student" << endl;
		cout << "2) Modify student" << endl;
		cout << "3) Delete student" << endl;
		cout << "4) Find student" << endl;
		cout << "5) Show all records" << endl << endl;
		cout << "0) Exit" << endl << endl;

		cin >> choice;

		system("cls");

		switch (choice)
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
			cout << "Enter text for searching:" << endl;
			cin >> text;
			system("cls");
			if (SearchStudentByAnyInfo(text) == -1) {
				cout << "404 Not found!" << endl;
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
