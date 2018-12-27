//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FindWord.h"
#include "Main.h"
#include <string>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
using namespace std;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormShow(TObject *Sender)
{
	StringGrid1->ColWidths[0] = 50;
	for(int i = 1; i < 4; i++){StringGrid1->ColWidths[i] = 100;}
	StringGrid1->ColWidths[4] = 245;

	StringGrid1->Cells[0][0] = "Код";
	StringGrid1->Cells[1][0] = "Название";
	StringGrid1->Cells[2][0] = "Отдел";
	StringGrid1->Cells[3][0] = "Цена";
	StringGrid1->Cells[4][0] = "Информация";
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
	AnsiString  ansiString  = Edit1->Text;
	string curName = ansiString.c_str();
	string cmpCurName;
	bool rez = false;
	bool rez2 = false;
	for (int i = 0; i < Form1->prodVect.size(); i++)
	{
		cmpCurName = Form1->prodVect[i].getName();
		if (cmpCurName.length() == curName.length()){
			for(int j = 0; j < cmpCurName.length(); j++){
				if((char)tolower(cmpCurName[j]) == (char)tolower(curName[j])){rez = true;}
				else{rez = false;}
			}
		}
		else{
			for(int j = 0; j < cmpCurName.length(); j++){
				if (cmpCurName.find(curName) != string::npos){rez2 = true;}
			}
		}
		if (rez == true || rez2 == true){
			StringGrid1->RowCount = Form1->prodVect.size() + 1;
			if(Form1->prodVect.size() != 0){
				//for(int j = 0; j < Form1->prodVect.size(); j++){
				StringGrid1->Cells[0][i + 1] = Form1->prodVect[i].getId();
				StringGrid1->Cells[1][i + 1] = Form1->prodVect[i].getName().c_str();
				StringGrid1->Cells[2][i + 1] = Form1->prodVect[i].getDep().c_str();
				StringGrid1->Cells[3][i + 1] = Form1->prodVect[i].getCost();
				StringGrid1->Cells[4][i + 1] = Form1->prodVect[i].getInfo().c_str();
				//StringGrid1->Cells[j][i] = IntToStr(i) + " " +  IntToStr(j);
			   //	j = Form1->prodVect.size() + 1;
				//}
			}
			else {ShowMessage("Вектор пуст!");}

		}
		//else if (rez == false || rez2 == false){ShowMessage("Совпадений не найдено!");}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
	 for(int i = 0; i < StringGrid1->ColCount; i++) {
		for(int j = 1; j < StringGrid1->RowCount; j++) {
			StringGrid1->Cells[i][j] = "";
		}
	 }
}
//---------------------------------------------------------------------------
