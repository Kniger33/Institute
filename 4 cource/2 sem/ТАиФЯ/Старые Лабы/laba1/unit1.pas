unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  lexlib, TEST, Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, StdCtrls;

//const num=257; id=258; lex_error=313;

//function yylex: integer;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Memo1: TMemo;
    Memo2: TMemo;
    Memo3: TMemo;
    Memo4: TMemo;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
  private
    { private declarations }
  public
    { public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.Button1Click(Sender: TObject);
var i: integer;
begin
  yyclear;
  yymemoinit(Memo1,Memo2,Memo3,Memo4);
  yylineno:=0;
  repeat
   i:=yylex;
   case i of
    num: memo2.Lines.Add('Целое число: '+yytext);
    dec: memo2.Lines.Add('Десятичное число: '+yytext);
    id: memo2.Lines.Add('Идентификатор: '+yytext);
    _var: memo2.Lines.Add('Служебное слово: '+yytext);
    _if: memo2.Lines.Add('Служебное слово: '+yytext);
    _then: memo2.Lines.Add('Служебное слово: '+yytext);
    _else: memo2.Lines.Add('Служебное слово: '+yytext);
    _begin: memo2.Lines.Add('Служебное слово: '+yytext);
    _end: memo2.Lines.Add('Служебное слово: '+yytext);
    _and: memo2.Lines.Add('Логическая операция: '+yytext);
    _or: memo2.Lines.Add('Логическая операция: '+yytext);
    _round: memo2.Lines.Add('Операция округления: '+yytext);

    ord('+'): memo2.Lines.Add('Знак операции: ' + yytext);
    ord('-'): memo2.Lines.Add('Знак операции: ' + yytext);
    ord('*'): memo2.Lines.Add('Знак операции: ' + yytext);
    ord('/'): memo2.Lines.Add('Знак операции: ' + yytext);
    ord('<'): memo2.Lines.Add('Знак сравнения: ' + yytext);
    ord('>'): memo2.Lines.Add('Знак сравнения: ' + yytext);
    ord('='): memo2.Lines.Add('Знак сравнения: ' + yytext);
    ord(';'): memo2.Lines.Add('Разделитель команд: ' + yytext);
    ord(':'): memo2.Lines.Add('Двоеточие: ' + yytext);
    ord('('): memo2.Lines.Add('Открытая скобка: ' + yytext);
    ord(')'): memo2.Lines.Add('Закрытая скобка: ' + yytext);
    lex_error: begin
                 memo2.Lines.Add('Лексическая ошибка!');
                 raise exception.Create('Лексическая ошибка!');
               end;
    end;
  until i=0;
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
  Memo1.Lines.Clear;
  Memo2.Lines.Clear;
end;

end.

