//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FindCost.h"
#include "Main.h"
#include <string>
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button2Click(TObject *Sender)
{
	for(int i = 0; i < StringGrid1->ColCount; i++) {
	 	for(int j = 1; j < StringGrid1->RowCount; j++) {
			StringGrid1->Cells[i][j] = "";
		}
	 }
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormShow(TObject *Sender)
{
	StringGrid1->ColWidths[0] = 50;
	for(int i = 1; i < 4; i++){StringGrid1->ColWidths[i] = 150;}
	StringGrid1->ColWidths[4] = 170;

	StringGrid1->Cells[0][0] = "���";
	StringGrid1->Cells[1][0] = "��������";
	StringGrid1->Cells[2][0] = "�����";
	StringGrid1->Cells[3][0] = "����";
	StringGrid1->Cells[4][0] = "����������";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
	AnsiString  ansiString  = Edit1->Text;
	string curDepartment = ansiString.c_str();
	string cmpDep;
	bool rez = false;
	for(int i = 0; i < Form1->prodVect.size(); i++){
		cmpDep = Form1->prodVect[i].getDep();
		for(int i = 0; i < cmpDep.length(); i++)
		{
			if((char)tolower(cmpDep[i]) == (char)tolower(curDepartment[i])){rez = true;}
			else{rez = false;}
		}
		if (rez == true && Form1->prodVect[i].getCost() >= 200 && Form1->prodVect[i].getCost() <= 300){
			StringGrid1->RowCount = Form1->prodVect.size() + 1;
			if(Form1->prodVect.size() != 0){
				//for(int i = 0; i < Form1->prodVect.size(); i++){
				StringGrid1->Cells[0][i + 1] = Form1->prodVect[i].getId();
				StringGrid1->Cells[1][i + 1] = Form1->prodVect[i].getName().c_str();
				StringGrid1->Cells[2][i + 1] = Form1->prodVect[i].getDep().c_str();
				StringGrid1->Cells[3][i + 1] = Form1->prodVect[i].getCost();
				StringGrid1->Cells[4][i + 1] = Form1->prodVect[i].getInfo().c_str();
				//StringGrid1->Cells[j][i] = IntToStr(i) + " " +  IntToStr(j);
				//}
			}
			else {ShowMessage("������ ����!");}
		}
	}
}
//---------------------------------------------------------------------------
