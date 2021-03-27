unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  lexlib, TEST, Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, StdCtrls;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Memo1: TMemo;
    Memo2: TMemo;
    Memo3: TMemo;
    Memo4: TMemo;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
  private
    { private declarations }
  public
    { public declarations }
  end;

var
  Form1: TForm1;
  token: integer;

implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.Button1Click(Sender: TObject);
var i:integer;
begin
  yyclear;
  yymemoinit(Memo1,Memo2,Memo3,Memo4);
  yylineno:=0;
  token:=yylex;
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
  Memo1.Lines.Clear;
  Memo2.Lines.Clear;
end;

procedure TForm1.Button3Click(Sender: TObject);
var i:integer;
begin
  yyclear;
  yymemoinit(Memo1,Memo2,Memo3,Memo4);
  yylineno:=0;
  repeat
    i:=yylex;
    case i of
      num: memo2.Lines.Add('Целое число: '+yytext);
      dec: memo2.Lines.Add('Дробное число: '+yytext);
      id: memo2.Lines.Add('Идентификатор: '+yytext);

      int_term: memo2.Lines.Add('Целочисленный тип: '+yytext);
      char_term: memo2.Lines.Add('Символьный тип: '+yytext);
      create_table_term: memo2.Lines.Add('Терм создания таблицы: '+yytext);
      null_term: memo2.Lines.Add('Терм нул: '+yytext);
      not_null_term: memo2.Lines.Add('Терм не нул: '+yytext);
      pkey_term: memo2.Lines.Add('Терм первичного кдюча: '+yytext);
      fkey_term: memo2.Lines.Add('Терм внешний ключа: '+yytext);
      references_term: memo2.Lines.Add('Терм ссылки: '+yytext);

      ord(','): memo2.Lines.Add('Запятая: ' + yytext);
      ord('('): memo2.Lines.Add('Открытая скобка: ' + yytext);
      ord(')'): memo2.Lines.Add('Закрытая скобка: ' + yytext);
      lex_error: begin
                   memo2.Lines.Add('Лексическая ошибка!');
                   raise exception.Create('Лексическая ошибка!');
                 end;
      end;
  until i=0;
end;

{=======================================================================================}

end.

