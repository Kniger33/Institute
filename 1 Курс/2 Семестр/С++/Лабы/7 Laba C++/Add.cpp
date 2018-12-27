//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Add.h"
#include "Main.h"
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
using namespace std;
int CurId;
string CurName;
string CurDepartment;
int CurCost;
string CurInformation;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit1Change(TObject *Sender)
{
	   CurId = StrToInt(Edit1->Text);
}
//---------------------------------------------------------------------------


void __fastcall TForm2::FormShow(TObject *Sender)
{
//Label1->Caption = CurName.c_str();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
	AnsiString  ansiString  = Edit2->Text;
	CurId = StrToInt(Edit1->Text);
	CurName = ansiString.c_str();
	ansiString = Edit3->Text;
	CurDepartment = ansiString.c_str();
	CurCost = StrToInt(Edit4->Text);
	ansiString = Edit5->Text;
	CurInformation = ansiString.c_str();
	Form2->Close();
	Form1->prodVect.push_back(Product(CurId, CurName, CurDepartment, CurCost, CurInformation));

}
//---------------------------------------------------------------------------


void __fastcall TForm2::Edit4KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if (Key == VK_RETURN)
		{Edit1Change(Sender);}
	if  ( (( Key <= '0') && ( Key >= '9'))
		|| Key == '-' || Key == '+'
		|| Key == '*' || Key == '/'
		|| Key == '=' || Key == '.'
		|| Key == ',' || Key == '?'
		)
	{
		ShowMessage("� ���� ����������� ������ �����");
		Key = 0;
		Edit1->Clear();
		Edit1->SetFocus();
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
	if (Key == VK_RETURN)
		{Edit1Change(Sender);}
	if  ( (( Key <= '0') && ( Key >= '9'))
		|| Key == '-' || Key == '+'
		|| Key == '*' || Key == '/'
		|| Key == '=' || Key == '.'
		|| Key == ',' || Key == '?'
		)
	{
		ShowMessage("� ������ ����������� ������ �����");
		Key = 0;
		Edit1->Clear();
		//Edit1->SetFocus();
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit4Change(TObject *Sender)
{
	 //��
}
//---------------------------------------------------------------------------

