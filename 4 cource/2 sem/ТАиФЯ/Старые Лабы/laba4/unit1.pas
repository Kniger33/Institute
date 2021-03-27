unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  lexlib, TEST, Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, StdCtrls;

type

  symb = (goal,sql_create_table,sql_statement,field_decloration,field_decloration1,field,ftype,
          null_value,keys_decloration,primary_key_decl,field_list,field_list1,foreign_key_decl,
          foreign_key,ref_table,bracket1,bracket2,
          t_crt,t_id,t_num,t_bracket1,t_bracket2,t_comma,t_int,t_char,t_null,t_nnull,t_pkey,t_fkey,t_ref,eof);

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
    procedure FormCreate(Sender: TObject);
    procedure Parse;
    procedure pushRightProd(production: string);
    procedure push(value: symb);
    procedure pop;
    function strtosymb(value:string):symb;
    function lextosymb(value:integer):symb;
  private
    { private declarations }
  public
    { public declarations }
  end;

  const
  MTable: array[goal..bracket2, t_crt..eof] of string =
  (
      ('sql_create_table','er','er','er','er','er','er','er','er','er','er','er','er','er'),
      ('t_crt t_id sql_statement','er','er','er','er','er','er','er','er','er','er','er','er','er'),
      ('er','er','er','( field_decloration keys_decloration )','er','er','er','er','er','er','er','er','er','er'),
      ('er','field field_decloration1','er','er','er','er','er','er','er','er','er','er','er','er'),
      ('er','field field_decloration1','er','er','er','er','er','er','er','er','','er','er','er'),
      ('er','t_id ftype null_value ,','er','er','er','er','er','er','er','er','er','er','er','er'),
      ('er','er','er','er','er','er','t_int','t_char ( t_num )','er','er','er','er','er','er'),
      ('er','er','er','er','er','er','er','er','t_null','t_nnull','er','er','er','er'),
      ('er','er','er','er','er','er','er','er','er','er','primary_key_decl foreign_key_decl','er','er','er'),
      ('er','er','er','er','er','er','er','er','er','er','t_pkey field_list','er','er','er'),
      ('er','er','er','( t_id field_list1 )','er','er','er','er','er','er','er','er','er','er'),
      ('er','er','er','er','',', t_id field_list1','er','er','er','er','er','er','er','er'),
      ('er','er','er','er','',', foreign_key foreign_key_decl','er','er','er','er','er','er','er','er'),
      ('er','er','er','er','er','er','er','er','er','er','er','t_fkey field_list t_ref ref_table','er','er'),
      ('er','t_id field_list','er','er','er','er','er','er','er','er','er','er','er','er'),
      ('er','er','er','(','er','er','er','er','er','er','er','er','er','er'),
      ('er','er','er','er',')','er','er','er','er','er','er','er','er','er')
  );

var
  Form1: TForm1;
  stack: array[1..100] of symb;
  p_s: integer;
  token: symb;

implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.Button1Click(Sender: TObject);
var i:integer;
begin
  yyclear;
  yymemoinit(Memo1,Memo2,Memo3,Memo4);
  yylineno:=0;
  parse;
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
      pkey_term: memo2.Lines.Add('Терм первичного ключа: '+yytext);
      fkey_term: memo2.Lines.Add('Терм внешнего ключа: '+yytext);
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

procedure TForm1.FormCreate(Sender: TObject);
begin
  p_s:=0;
end;

procedure TForm1.Parse;
var prod: string;
    er_flag: boolean;
begin
  er_flag:=false;
  push(eof);
  push(goal);
  token:=lextosymb(yylex);
  repeat
    if stack[p_s] in [t_crt..t_ref] then  //вершина стека - терминал
      if token = stack[p_s] then
        begin
          pop;
          token:=lextosymb(yylex);
        end
      else
       begin
         showmessage('Ошибка');
         er_flag:=true;
         break;
       end
    else if stack[p_s] in [goal..bracket2] then  //вершина стека - нетерминал
      if MTable[stack[p_s],token] <> 'er' then
        begin
          prod:=MTable[stack[p_s],token];
          pop;
          if prod <> '' then pushRightProd(prod); //разбивает правую часть продукции на термы и заносит в стек в обратном порядке
        end
      else
        begin
         showmessage('Ошибка');
         er_flag:=true;
         break;
       end
    else //в стеке посторонний символ
      begin
         showmessage('Ошибка');
         er_flag:=true;
         break;
      end;
  until stack[p_s] = eof;
  if not er_flag then
     if token <> eof then showmessage('Ошибка')
                     else showmessage('Успех!');
end;

procedure TForm1.pushRightProd(production: string);
var i:integer;
    term:string;
begin
  for i:=length(production) downto 1 do
    begin
      if (production[i] = ' ') then
        begin
          push(strtosymb(term));
          term:='';
        end
      else insert(production[i],term,1);
    end;
  push(strtosymb(term)); //после цикла последний терм не будет добавлен стек, поэтому добавляем
end;

procedure TForm1.push(value: symb);
var t:symb;
begin
 p_s:=p_s+1;
 stack[p_s]:=value;
end;

procedure TForm1.pop;
begin
  p_s:=p_s-1;
end;

function TForm1.strtosymb(value:string): symb;
begin
  case value of
    //НЕТЕРМИНАЛЫ
    'goal': result:=goal;
    'sql_create_table': result:=sql_create_table;
    'sql_statement': result:=sql_statement;
    'field_decloration': result:=field_decloration;
    'field_decloration1': result:=field_decloration1;
    'field': result:=field;
    'ftype': result:=ftype;
    'null_value': result:=null_value;
    'keys_decloration': result:=keys_decloration;
    'primary_key_decl': result:=primary_key_decl;
    'field_list': result:=field_list;
    'field_list1': result:=field_list1;
    'foreign_key_decl': result:=foreign_key_decl;
    'foreign_key': result:=foreign_key;
    'ref_table': result:=ref_table;
    'bracket1': result:=bracket1;
    'bracket2': result:=bracket2;
    //ТЕРМИНАЛЫ
    't_num': result:=t_num;
    't_id': result:=t_id;
    't_int': result:=t_int;
    't_char': result:=t_char;
    't_crt': result:=t_crt;
    't_null': result:=t_null;
    't_nnull': result:=t_nnull;
    't_pkey': result:=t_pkey;
    't_fkey': result:=t_fkey;
    't_ref': result:=t_ref;
    ',': result:=t_comma;
    '(': result:=t_bracket1;
    ')': result:=t_bracket2;
  end;
end;

function TForm1.lextosymb(value:integer): symb;
begin
  case value of
    num: result:=t_num;
    id: result:=t_id;

    int_term: result:=t_int;
    char_term: result:=t_char;
    create_table_term: result:=t_crt;
    null_term: result:=t_null;
    not_null_term: result:=t_nnull;
    pkey_term: result:=t_pkey;
    fkey_term: result:=t_fkey;
    references_term: result:=t_ref;

    ord(','): result:=t_comma;
    ord('('): result:=t_bracket1;
    ord(')'): result:=t_bracket2;

    0: result:=eof;
  end;
end;


end.

