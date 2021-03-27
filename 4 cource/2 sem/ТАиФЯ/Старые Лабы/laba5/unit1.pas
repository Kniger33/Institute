unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  lexlib, TEST, Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, StdCtrls;

type

  action_in_cell = (Shift, Reduce, Accept, Error);

  state = (S0,S1,S2,S3,S4,S5,S6,S7,S8,S9,S10,S11,S12,S13,S14,S15,
           S16,S17,S18,S19,S20,S21,S22,S23,S24,S25,S26,S27,S_er);

  symb = (SQL1,SQL,SELECT,FROM,WHERE,FIELD_LIST,CONDITION_LIST,
          BOOLTERM,CONDITION,EOPR,VALUE,select_term,from_term,where_term,comma,or_term,
          and_term,id_t,num_t,less_term,more_term,equal_term,eof);

  gramm_type = record
    noterm: symb;
    basic_length: integer;
  end;

  stack_type = record
    stack_state: state;
    stack_symb: symb;
  end;

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
    procedure push(value_state: state; value_symb: symb);
    procedure actionProd(cell: string; var aType: action_in_cell; var aValue: string);
    procedure pop;
    function strtostate(value:string):state;
    function lextosymb(value:integer):symb;
  private
    { private declarations }
  public
    { public declarations }
  end;

  const

  gramm: array[1..18] of gramm_type =(
  (noterm: SQL1; basic_length:1),
  (noterm: SQL; basic_length: 3),
  (noterm: SQL; basic_length: 2),
  (noterm: SELECT; basic_length: 2),
  (noterm: FROM; basic_length: 2),
  (noterm: WHERE; basic_length: 2),
  (noterm: FIELD_LIST; basic_length: 3),
  (noterm: FIELD_LIST; basic_length: 1),
  (noterm: CONDITION_LIST; basic_length: 3),
  (noterm: CONDITION_LIST; basic_length: 1),
  (noterm: BOOLTERM; basic_length: 3),
  (noterm: BOOLTERM; basic_length: 1),
  (noterm: CONDITION; basic_length: 3),
  (noterm: EOPR; basic_length: 1),
  (noterm: EOPR; basic_length: 1),
  (noterm: EOPR; basic_length: 1),
  (noterm: VALUE; basic_length: 1),
  (noterm: VALUE; basic_length: 1));

  action_: array[S0..S27, select_term..eof] of string =
  (
      ('shift 6','er','er','er','er','er','er','er','er','er','er','er'),                     //0
      ('er','er','er','er','er','er','er','er','er','er','er','accept'),                      //1
      ('er','shift 3','er','er','er','er','er','er','er','er','er','er'),                     //2
      ('er','er','er','er','er','er','shift 4','er','er','er','er','er'),                     //3
      ('er','er','reduce 5','er','er','er','er','er','er','er','er','reduce 5'),              //4
      ('er','reduce 3','shift 12','er','er','er','er','er','er','er','er','reduce 3'),        //5
      ('er','er','er','er','er','er','shift 7','er','er','er','er','er'),                     //6
      ('er','reduce 8','er','reduce 8','er','er','er','er','er','er','er','er'),              //7
      ('er','reduce 4','er','shift 9','er','er','er','er','er','er','er','er'),               //8
      ('er','er','er','er','er','er','shift 10','er','er','er','er','er'),                    //9
      ('er','reduce 7','er','reduce 7','er','er','er','er','er','er','er','er'),              //10
      ('er','er','er','er','er','er','er','er','er','er','er','reduce 2'),                    //11
      ('er','er','er','er','er','er','shift 13','shift 14','er','er','er','er'),              //12
      ('er','er','er','er','reduce 17','reduce 17','er','er','reduce 17','reduce 17','reduce 17','reduce 17'),//13
      ('er','er','er','er','reduce 18','reduce 18','er','er','reduce 18','reduce 18','reduce 18','reduce 18'),//14
      ('er','er','er','er','reduce 12','reduce 12','er','er','er','er','er','reduce 12'),     //15
      ('er','er','er','er','er','er','er','er','shift 17','shift 18','shift 19','er'),        //16
      ('er','er','er','er','er','er','reduce 14','reduce 14','er','er','er','er'),            //17
      ('er','er','er','er','er','er','reduce 15','reduce 15','er','er','er','er'),            //18
      ('er','er','er','er','er','er','reduce 16','reduce 16','er','er','er','er'),            //19
      ('er','er','er','er','er','er','reduce 13','shift 14','er','er','er','er'),             //20
      ('er','er','er','er','reduce 13','reduce 13','er','er','er','er','er','reduce 13'),     //21
      ('er','er','er','er','shift 26','er','er','er','er','er','er','reduce 6'),              //22
      ('er','er','er','er','reduce 10','shift 24','er','er','er','er','er','reduce 10'),      //23
      ('er','er','er','er','er','er','shift 13','shift 14','er','er','er','er'),              //24
      ('er','er','er','er','reduce 11','reduce 11','er','er','er','er','er','reduce 11'),     //25
      ('er','er','er','er','er','er','shift 13','shift 14','er','er','er','er'),              //26
      ('er','er','er','er','reduce 9','shift 24','er','er','er','er','er','reduce 9')        //27
  );


  goto_: array[S0..S27, SQL..VALUE] of state =
  (
      (S1,S2,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er),         //0
      (S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er),     //1
      (S_er,S_er,S5,S_er,S_er,S_er,S_er,S_er,S_er,S_er),       //2
      (S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er),     //3
      (S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er),     //4
      (S_er,S_er,S_er,S11,S_er,S_er,S_er,S_er,S_er,S_er),      //5
      (S_er,S_er,S_er,S_er,S8,S_er,S_er,S_er,S_er,S_er),       //6
      (S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er),     //7
      (S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er),     //8
      (S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er),     //9
      (S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er),     //10
      (S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er),     //11
      (S_er,S_er,S_er,S_er,S_er,S22,S23,S15,S_er,S_er),        //12
      (S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er),     //13
      (S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er),     //14
      (S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er),     //15
      (S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er),     //16
      (S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S20,S_er),      //17
      (S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er),     //18
      (S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er),     //19
      (S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S21),      //20
      (S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er),     //21
      (S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er),     //22
      (S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er),     //23
      (S_er,S_er,S_er,S_er,S_er,S_er,S_er,S25,S_er,S16),       //24
      (S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er),     //25
      (S_er,S_er,S_er,S_er,S_er,S_er,S27,S15,S_er,S16),        //26
      (S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er)      //27
  );

var
  Form1: TForm1;
  stack: array[1..100] of stack_type;
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

      select_t: memo2.Lines.Add('Селект: '+yytext);
      from_t: memo2.Lines.Add('Откуда: '+yytext);
      where_t: memo2.Lines.Add('Где: '+yytext);
      or_t: memo2.Lines.Add('Логическое или: '+yytext);
      and_t: memo2.Lines.Add('Логическое и: '+yytext);
      ord('<'): memo2.Lines.Add('Меньше: ' + yytext);
      ord('>'): memo2.Lines.Add('Больше: ' + yytext);
      ord('='): memo2.Lines.Add('Равно: ' + yytext);
      ord(','): memo2.Lines.Add('Запятая: ' + yytext);
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
var i,length: integer;
    er_flag: boolean;
    cur_prod: gramm_type;
    cur_state: state;
    action_type: action_in_cell;
    action_value: string;
begin
  er_flag:=false;
  push(S0,eof);
  token:=lextosymb(yylex);
  repeat
    actionProd(action_[stack[p_s].stack_state, token], action_type, action_value);
    if action_type = shift then
      begin
        push(strtostate(action_value),token);
        token:=lextosymb(yylex);
      end
    else if action_type = reduce then
      begin
        for i:=0 to gramm[strtoint(action_value)].basic_length-1 do pop();
        push(goto_[stack[p_s].stack_state,gramm[strtoint(action_value)].noterm],
             gramm[strtoint(action_value)].noterm);
      end
    else if (strtostate(action_value) = S_er) or (action_type = error) then
      begin
        showmessage('Неудача!');
        er_flag:=true;
        break;
      end;
  until action_type = accept;
  if not er_flag then showmessage('Успех');
end;

procedure TForm1.push(value_state: state; value_symb: symb);
var t:symb;
begin
 p_s:=p_s+1;
 stack[p_s].stack_state:=value_state;
 stack[p_s].stack_symb:=value_symb;
end;

procedure TForm1.actionProd(cell: string; var aType: action_in_cell;
  var aValue: string);
begin
  if cell = 'accept' then aType:=Accept
  else
    case Copy(cell, 1, Pos(' ',cell)-1) of
      'shift':begin
        aType:=Shift;
      end;
      'reduce':begin
        aType:=Reduce;
      end;
      else aType:=Error;
    end;
  if cell <> 'er'
    then aValue:=Copy(cell, Pos(' ',cell)+1, Length(cell)-Pos(' ',cell))
    else aValue:=cell;
end;

procedure TForm1.pop;
begin
  p_s:=p_s-1;
end;

function TForm1.strtostate(value: string): state;
begin
  case value of
    '0': result:=S0;
    '1': result:=S1;
    '2': result:=S2;
    '3': result:=S3;
    '4': result:=S4;
    '5': result:=S5;
    '6': result:=S6;
    '7': result:=S7;
    '8': result:=S8;
    '9': result:=S9;
    '10': result:=S10;
    '11': result:=S11;
    '12': result:=S12;
    '13': result:=S13;
    '14': result:=S14;
    '15': result:=S15;
    '16': result:=S16;
    '17': result:=S17;
    '18': result:=S18;
    '19': result:=S19;
    '20': result:=S20;
    '21': result:=S21;
    '22': result:=S22;
    '23': result:=S23;
    '24': result:=S24;
    '25': result:=S25;
    '26': result:=S26;
    '27': result:=S27;
    'er': result:=S_er;
  end;
end;

function TForm1.lextosymb(value:integer): symb;
begin
  case value of
    select_t: result:=select_term;
    from_t: result:=from_term;
    where_t: result:=where_term;
    or_t: result:=or_term;
    and_t: result:=and_term;
    num: result:=num_t;
    id: result:=id_t;
    ord('<'): result:=less_term;
    ord('>'): result:=more_term;
    ord('='): result:=equal_term;
    ord(','): result:=comma;
    0: result:=eof;
  end;
end;


end.

