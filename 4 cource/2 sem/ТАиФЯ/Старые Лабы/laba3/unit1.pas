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
    function goal():boolean;
    function section():boolean;
    function decloration():boolean;
    function var_decloration():boolean;
    function var_decl_instr():boolean;
    function id_decl():boolean;
    function implementation_instr():boolean;
    function list_inctruction():boolean;
    function assigment_inctruction():boolean;
    function expr():boolean;
    function expr1():boolean;
    function term():boolean;
    function term1():boolean;
    function factor():boolean;
    function read_inctruction():boolean;
    function write_inctruction():boolean;
    function branch_inctruction():boolean;
    function condition():boolean;
    function condition1():boolean;
    function boolexpr():boolean;
    function boolexpr1():boolean;
    function boolterm():boolean;
    function boolop():boolean;
    function consequence():boolean;
    function consequence1():boolean;
    function elsecons():boolean;
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
  if goal then showmessage('Успех!')
          else showmessage('Неудача!');

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
      dec: memo2.Lines.Add('Десятичное число: '+yytext);
      id: memo2.Lines.Add('Идентификатор: '+yytext);
      string_term: memo2.Lines.Add('Строка: '+yytext);
      var_term: memo2.Lines.Add('Служебное слово: '+yytext);
      type_term: memo2.Lines.Add('Тип : '+yytext);
      if_term: memo2.Lines.Add('Служебное слово: '+yytext);
      then_term: memo2.Lines.Add('Служебное слово: '+yytext);
      else_term: memo2.Lines.Add('Служебное слово: '+yytext);
      begin_term: memo2.Lines.Add('Служебное слово: '+yytext);
      end_term: memo2.Lines.Add('Служебное слово: '+yytext);
      and_term: memo2.Lines.Add('Логическая операция: '+yytext);
      or_term: memo2.Lines.Add('Логическая операция: '+yytext);
      round_term: memo2.Lines.Add('Операция округления: '+yytext);
      mod_term: memo2.Lines.Add('Операция mod: '+yytext);
      div_term: memo2.Lines.Add('Операция div: '+yytext);
      boolop_term: memo2.Lines.Add('Логический оператор: '+yytext);

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

function TForm1.goal: boolean;
begin
  result := section;
end;

function TForm1.section: boolean;
begin
  result := decloration and implementation_instr;
end;

function TForm1.decloration: boolean;
begin
  if token = var_term
     then
        begin
           token:=yylex;
           if var_decl_instr and (token = ord(';'))
              then
                 begin
                    token:=yylex;
                    result := var_decloration
                 end
              else result := false;
        end
     else result := false;
end;

function TForm1.var_decloration: boolean;
var res: boolean;
begin
  case token of
    id:
      begin
        if var_decl_instr and (token = ord(';'))
           then
              begin
                 token:=yylex;
                 result := var_decloration();
              end
           else result := false;
      end;
    else result := true;  //Эпсилон (var_decloration -> E)
  end;
end;

function TForm1.var_decl_instr: boolean;
begin
  if token = id then
    begin
      token := yylex;
      if id_decl then
        begin
          if token = ord(':') then
            begin
               token:=yylex;
                 if token = type_term then
                   begin
                     token := yylex;
                     result := true;
                   end
                 else result := false;
            end
          else result := false;
        end
      else result := false;
    end
  else result := false;
end;

function TForm1.id_decl:boolean;
begin
  if token = ord(',') then
    begin
      token := yylex;
      if token = id then
        begin
          token := yylex;
          result := id_decl();
        end
      else result := false;
    end
  else result:=true;  //Эпсилон (id_decl -> E)
end;

function TForm1.implementation_instr: boolean;
begin
  if (token = begin_term) and list_inctruction and (token = end_term) //добавить точку
     then result := true
     else result := false;
end;

function TForm1.list_inctruction: boolean;
begin
  token:=yylex;
  case token of
    id:begin
      if assigment_inctruction and (token = ord(';')) and list_inctruction()
        then result := true
        else result := false;
    end;
    read_term:begin
      if read_inctruction and (token = ord(';')) and list_inctruction()
        then result := true
        else result := false;
    end;
    write_term:begin
      if write_inctruction and (token = ord(';')) and list_inctruction()
        then result := true
        else result := false;
    end;
    if_term:begin
      if branch_inctruction and (token = ord(';')) and list_inctruction()
        then result := true
        else result := false;
    end;
  else result := true; //Эпсилон (list_inctruction -> E)
  end;
end;

{===============================АРИФМЕТИЧЕСКИЕ ВЫРАЖЕНИЯ===============================}
function TForm1.assigment_inctruction: boolean;
begin
  if (yylex = ord(':')) and (yylex = ord('='))         //!!!! заменить : и = на оператор :=
    then
      begin
        token:=yylex;
        result:=expr();
      end
    else result:=false;
end;

function TForm1.expr: boolean;
begin
  if term and expr1
    then result:=true
    else result:=false;
end;

function TForm1.expr1: boolean;
begin
  case token of
    ord('+'):begin
      token:=yylex;
      if term and expr1()
        then result:=true
        else result:=false;
    end;
    ord('-'):begin
      token:=yylex;
      if term and expr1()
        then result:=true
        else result:=false;
    end;
  else result:=true;   //Эпсилон (expr1 -> E)
  end;
end;

function TForm1.term: boolean;
begin
  if factor and term1
    then result:=true
    else result:=false;
end;

function TForm1.term1: boolean;
begin
  case token of
    ord('*'):begin
      token:=yylex;
      if factor and term1()
        then result:=true
        else result:=false;
    end;
    ord('/'):begin
      token:=yylex;
      if factor and term1()
        then result:=true
        else result:=false;
    end;
    div_term:begin
      token:=yylex;
      if factor and term1()
        then result:=true
        else result:=false;
    end;
    mod_term:begin
      token:=yylex;
      if factor and term1()
        then result:=true
        else result:=false;
    end;
  else result:=true;   //Эпсилон (term1 -> E)
  end;
end;

function TForm1.factor: boolean;
begin
  case token of
    num:begin
      result:=true
    end;
    dec:begin
      result:=true
    end;
    id:begin
      result:=true
    end;
    round_term:begin
      if (yylex = ord('('))
        then
          begin
            token:=yylex;
            result:=expr and (token = ord(')'))
          end
        else result:=false;
    end;
    ord('('):begin
      token:=yylex;
      result := expr() and (token = ord(')'));
    end;
  else result:=false;
  end;
  token:=yylex;
end;
{=======================================================================================}
function TForm1.read_inctruction: boolean;
begin
  token:=yylex;
  if token = ord('(')
    then
      begin
        token:=yylex;
        if (token = id)
          then
            begin
              result:=(yylex = ord(')'));
              token:=yylex;
            end
          else result:=false;
      end
    else result:= false;
end;
{=======================================================================================}
function TForm1.write_inctruction: boolean;
begin
  token:=yylex;
  if token = ord('(')
    then
      begin
        token:=yylex;
        if (token = id)
          then
            begin
              result:=(yylex = ord(')'));
            end
        else if (token = ord(','))
          then
            begin
              token:=yylex;
              if (token = id) then
                begin
                  result:=(yylex = ord(',')) and (yylex = ord(')'));
                end
              else
              if (token = string_term) then
                begin
                  result:=(yylex = ord(',')) and (yylex = ord(')'));
                end
              else result:=false;
            end
        else result:=false;
        token:=yylex;
      end
    else result:= false;
end;

{=======================================================================================}
{=======================================ВЕТВЛЕНИЕ=======================================}
function TForm1.branch_inctruction: boolean;
begin
  token:=yylex;
  if condition and consequence
    then result := true
    else result := false;
end;

function TForm1.condition: boolean;
begin
  if (token = ord('('))
    then
      begin
        result := boolexpr and condition1;
      end
    else
      begin
        result := expr and boolop and expr;
      end;
end;

function TForm1.condition1: boolean;
begin
  if (token = or_term) then
    begin
      token:=yylex;
      if boolexpr and condition1
        then result := true
        else result := false
    end
  else result := true; //Эпсилон (condition1 -> E)
end;

function TForm1.boolexpr: boolean;
begin
  if boolterm and boolexpr1
    then result := true
    else result := false
end;

function TForm1.boolexpr1: boolean;
begin
  if (token = and_term) then
    begin
      token:=yylex;
      if boolterm and boolexpr1
        then result := true
        else result := false
    end
  else result := true;  //Эпсилон (boolexpr1 -> E)
end;

function TForm1.boolterm: boolean;
begin
  if (token = ord('('))
    then
      begin
        token:=yylex;
        if (token = ord('(')) then
          begin
            result := condition;
          end
        else result := expr and boolop and expr and (token = ord(')'));
        token:=yylex;
      end
    else result:=false;
end;

function TForm1.boolop: boolean;
begin
  case token of
    ord('='):begin
      result:=true
    end;
    ord('<'):begin
      result:=true
    end;
    ord('>'):begin
      result:=true
    end;
    boolop_term:begin
      result:=true
    end;
  else result:=false;
  end;
  token:=yylex;
end;

function TForm1.consequence: boolean;
begin
  if token = then_term then
    begin
      token:=yylex;
      result:=consequence1 and elsecons;
    end
  else result:=false;
end;

function TForm1.consequence1: boolean;
begin
  case token of
    id:begin
      result:=assigment_inctruction;
    end;
    read_term:begin
      result:=read_inctruction;
    end;
    write_term:begin
      result:=write_inctruction;
    end;
    if_term:begin
      result:=branch_inctruction;
    end;
    begin_term:begin
      if list_inctruction and (token=end_term)
        then
          begin
            token:=yylex;
            result:=true;
          end
        else result:=false;
    end;
  else result := false;
  end;
end;

function TForm1.elsecons: boolean;
begin
  if token = else_term then
    begin
      token:=yylex;
      result:=consequence1;
    end
  else result:=true;       //Эпсилон (elsecons -> E)
end;

{=======================================================================================}

end.

