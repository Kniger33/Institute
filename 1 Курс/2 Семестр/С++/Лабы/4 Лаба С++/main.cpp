/*�������� ������� ����� ����� � ����������� ������ ����������, ������, ����������.
��� ����������� ������� ����������� ������������ � ������� ������������ �������� ������.
�������������� ��������������� ������ (��������, ����� �Show� ��� ����������� ����������).
������� ������ �������� �������� ������ � ��������� ��� ��������� ����������� �������.
����������� ������������:
1)	����������� ���������� �� ������;
2)	�������� ���������� �������� � ������ ���������;
3)	����������� ���������� ������ �� ��������� ����������, ������ ��� ����������.
*/

#include <iostream>
#include <windows.h>
#include <iomanip>
#include <vector>

using namespace std;

/////////////////LESSON/////////////////////
class Lesson
{
protected:
    string type;
    int typeLes;
public:
    Lesson(string t, int tl){type = t; typeLes = tl;}

    virtual void Show()
    {
        cout << "���: " << type << endl;
    }

    string getType(){return type;}
    int getTypeLes() {return typeLes;}
};

/////////////////ART////////////////////////
class Art : public Lesson
{
    string teacher;
    string smthAboutArt;
    string classType;

public:
    Art (string CT, string T, int TL, string TEACHER, string SAA): Lesson(T, TL)
    {
        teacher = TEACHER;
        smthAboutArt = SAA;
        classType = CT;
    }
    void Show()
    {
        cout << "�������: " << classType << endl;
        Lesson :: Show();
        cout << "�������������: "<< teacher << endl;
        cout << "�����-�� ����������: " << smthAboutArt << endl << endl;
    }

    string getTeacher(){return teacher;}
    string getSmthAboutArt(){return smthAboutArt;}
};

/////////////////SINGING////////////////////
class Singing : public Lesson
{
    string teacher;
    string song;
    string smthAboutSinging;
    string classType;

public:

    Singing(string CT, string T, int TL, string TEACHER, string SONG, string SAS):Lesson(T, TL)
    {
        teacher = TEACHER;
        song = SONG;
        smthAboutSinging = SAS;
    }

    void Show()
    {
        cout << "�������: " << classType << endl;
        Lesson :: Show();
        cout << "�������������: " << teacher << endl;
        cout << "�����: " << song << endl;
        cout << "�����-�� ����������: " << smthAboutSinging << endl << endl;
    }

    string getTeacher(){return teacher;}
    string getSong(){return song;}
    string getSmthAboutSinging(){return smthAboutSinging;}
};

/////////////////BIOLOGY////////////////////
class Biology : public Lesson
{
    string teacher;
    string smthAboutBiology;
    string classType;

public:

    Biology(string CT, string T, int TL, string TEACHER, string SAB):Lesson(T, TL)
    {
        teacher = TEACHER;
        smthAboutBiology = SAB;
    }

    void Show()
    {
        cout << "�������: " << classType << endl;
        Lesson :: Show();
        cout << "�������������: "<< teacher << endl;
        cout << "�����-�� ����������: " << smthAboutBiology << endl << endl;
    }

    string getTeacher(){return teacher;}
    string getSmthAboutBiology(){return smthAboutBiology;}
};

void cinGet()
{
    cin.get();
}

/////////////////MAIN///////////////////////
int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int exit = 1;
    char userChoise;
    int artCount = 0;
    int singingCount = 0;
    int biologyCount = 0;

    /*vector <Art> artVect;
    vector <Singing> singVect;
    vector <Biology> biolVect;*/
    vector <Lesson*> lesVect;


    //Lesson *mas[3];

    /*mas[0] = artVect.data();
    mas[1] = singVect.data();
    mas[2] = biolVect.data();*/


    while (exit)
    {
        system("cls");

        /*for(int i = 0; i < 3; i++)
        {
            cout << "Mas[" << i << "]= " << mas[i] << endl;;
        }*/


        cout << ">>���������� ������� �� ���������: " << artCount << endl;
        cout << ">>���������� ������� �� �����: " << singingCount << endl;
        cout << ">>���������� ������� �� ��������: " << biologyCount << endl << endl;
        cout << "�������� ��������: " << endl;
        cout << ">>���������� ���������� �� ����� - 1" << endl;
        cout << ">>����������� ���������� �� ������ - 2" << endl;
        cout << ">>����������� ���������� �� ���������� - 3" << endl << endl;
        cout << ">>����� - 0" << endl << endl;
        cout << "��� �����: ";
        cin >> userChoise;

        switch(userChoise)
        {
        //////���������� ���������� �� �����//////////
        case '1':
            {
                system("cls");
                char curUserChoise;
                cout << "�������� ������ ����:" << endl;
                cout << ">>��������� - 1" << endl;
                cout << ">>����� - 2" << endl;
                cout << ">>�������� - 3" << endl << endl;
                cout << ">>����� - 9" << endl << endl;
                cout << "��� �����: ";
                cin >> curUserChoise;

                switch(curUserChoise)
                {
                ///////���������� ���������///////////////
                case'1':
                    {
                        system("cls");

                        string curType;
                        string curTeacher;
                        string curInfo;

                        cout << "������� ����������: " << endl;
                        cout << "���: ";
                        cin.get();
                        getline(cin, curType);
                        cout << endl << "�������������: ";
                        //cinGet();
                        getline(cin, curTeacher);
                        cout << endl << "��������� ����������: ";
                        //cinGet();
                        getline(cin, curInfo);
                        lesVect.push_back(new Art("���������", curType, 1, curTeacher, curInfo));
                        artCount++;
                        system("pause");
                        break;
                    }
                ///////���������� �����///////////////
                case'2':
                    {
                        system("cls");
                        string curType;
                        string curTeacher;
                        string curSong;
                        string curInfo;

                        cout << "������� ����������: " << endl;
                        cout << "���: ";
                        cin.get();
                        getline(cin, curType);
                        cout << endl << "�������������: ";
                        //cinGet();
                        getline(cin, curTeacher);
                        cout << endl << "�����: ";
                        getline(cin, curSong);
                        cout << endl << "��������� ����������: ";
                        //cinGet();
                        getline(cin, curInfo);
                        lesVect.push_back(new Singing("�����", curType, 2, curTeacher, curSong, curInfo));
                        singingCount++;
                        system("pause");
                        break;
                    }
                ///////���������� ��������///////////////
                case '3':
                    {
                        system("cls");
                        string curType;
                        string curTeacher;
                        string curInfo;

                        cout << "������� ����������: " << endl;
                        cout << "���: ";
                        cin.get();
                        getline(cin, curType);
                        cout << endl << "�������������: ";
                        //cinGet();
                        getline(cin, curTeacher);
                        cout << endl << "��������� ����������: ";
                        //cinGet();
                        getline(cin, curInfo);
                        lesVect.push_back(new Biology("��������", curType, 3, curTeacher, curInfo));
                        biologyCount++;
                        system("pause");
                        break;
                    }
                ///////////////�����/////////////////////
                case '9':break;
                }
                break;
            }
        ///////////����������� ���������� �� ������/////////
        case '2':
            {
                system("cls");
                for (int i = 0; i < lesVect.size(); i++)
                {
                    lesVect[i]->Show();
                }
                system("pause");
                break;
            }
        /////////����������� ���������� �� ����������////////
        case '3':
            {
                system("cls");

                char curUserChoise;
                cout << "�������� ������ ����:" << endl;
                cout << ">>��������� - 1" << endl;
                cout << ">>����� - 2" << endl;
                cout << ">>�������� - 3" << endl << endl;
                cout << ">>����� - 9" << endl << endl;
                cout << "��� �����: ";
                cin >> curUserChoise;

                switch(curUserChoise)
                {
                /////////����� ���������/////////
                case '1':
                    {
                        for(int i = 0; i < lesVect.size(); i++)
                        {
                            if (lesVect[i]->getTypeLes() == 1)
                            {
                                lesVect[i]->Show();
                            }
                        }
                        break;
                    }
                /////////����� �����/////////
                case '2':
                    {
                        for(int i = 0; i < lesVect.size(); i++)
                        {
                            if (lesVect[i]->getTypeLes() == 2)
                            {
                                lesVect[i]->Show();
                            }
                        }
                        break;
                    }
                /////////����� ��������/////////
                case '3':
                    {
                        for(int i = 0; i < lesVect.size(); i++)
                        {
                            if (lesVect[i]->getTypeLes() == 3)
                            {
                                lesVect[i]->Show();
                            }
                        }
                        break;
                    }
                /////////////�����/////////////
                case '9':
                    {
                        break;
                    }
                }

                system("pause");
                break;
            }
        /////�����/////
        case'0':
            {
                exit = 0;
                break;
            }
        default:
            cout << "��� ����� �������" << endl;
            system("pause");
            break;
        }

    }

    lesVect.clear();

    return 0;
}
