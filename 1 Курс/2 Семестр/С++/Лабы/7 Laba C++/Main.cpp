//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//#include "Product.h"
#include <vector>
#include "Add.h"
#include "FindWord.h"
#include "FindCost.h"
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

using namespace std;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Application->CreateForm(__classid(TForm2), &Form2);
	Form2->ShowModal();
	Form2->Free();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
	StringGrid1->ColWidths[0] = 50;
	for(int i = 1; i < 4; i++){StringGrid1->ColWidths[i] = 100;}
	StringGrid1->ColWidths[4] = 265;

	StringGrid1->Cells[0][0] = "���";
	StringGrid1->Cells[1][0] = "��������";
	StringGrid1->Cells[2][0] = "�����";
	StringGrid1->Cells[3][0] = "����";
	StringGrid1->Cells[4][0] = "����������";

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	char symb;
	int countOfNames = 0;
	for(int i = 0; i < prodVect.size(); i++)	{
		symb = prodVect[i].FirstSymbolOfName();
		if (symb == '�' || symb == '�' || symb == 'k' || symb == 'K')
		countOfNames++;
	}
	Label2->Caption = "���������� ������� �� ����� \"K\": " + IntToStr(countOfNames);

	int countOfProducts = 0;
	for (int i = 0; i < prodVect.size(); i++){if (prodVect[i].getCost() > 1000){countOfProducts++;}}
	Label3->Caption = "���������� ������� ���������� ������ 1000: " + IntToStr(countOfProducts);
	//Label3->Caption = "������ �������: " + UIntToStr(prodVect.size());

	StringGrid1->RowCount = prodVect.size() + 1;
	if(prodVect.size() != 0){
		for(int i = 0; i < prodVect.size(); i++){
		StringGrid1->Cells[0][i + 1] = prodVect[i].getId();
		StringGrid1->Cells[1][i + 1] = prodVect[i].getName().c_str();
		StringGrid1->Cells[2][i + 1] = prodVect[i].getDep().c_str();
		StringGrid1->Cells[3][i + 1] = prodVect[i].getCost();
		StringGrid1->Cells[4][i + 1] = prodVect[i].getInfo().c_str();
		//StringGrid1->Cells[j][i] = IntToStr(i) + " " +  IntToStr(j);
		}
	}
	else {ShowMessage("������ ����!");}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Application->CreateForm(__classid(TForm3), &Form3);
	Form3->ShowModal();
	Form3->Free();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	Application->CreateForm(__classid(TForm4), &Form4);
	Form4->ShowModal();
	Form4->Free();
}
//---------------------------------------------------------------------------

