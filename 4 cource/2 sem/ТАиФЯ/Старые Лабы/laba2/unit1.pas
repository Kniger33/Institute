unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, StdCtrls;

type
  input_signal = (plus,dash,dot,com,L,D,colon,equality,space,other,endf);
  state = (S0,S1,S2,S3,S4,S5,S6,S7,S8,S9,S10,S11,S12,S13,S_er);
  lexeme_class = (digit,identifier,assignment,operation_mark,service_word);

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Edit1: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Memo1: TMemo;
    function state_machine: lexeme_class;
    function recognize: input_signal;
    function is_service_word: lexeme_class;
    procedure Button1Click(Sender: TObject);
  private
    { private declarations }
  public
    { public declarations }
  end;

const

  length_array = 3;

  service_word_array: array[0..length_array] of string = ('Begin','begin','End','end');

  next_state: array[S0..S9,plus..other] of state =
  ((S5,S1,S_er,S_er,S8,S2,S6,S_er,S_er,S_er),
   (S_er,S_er,S_er,S_er,S_er,S2,S_er,S_er,S11,S_er),
   (S_er,S_er,S3,S3,S_er,S2,S_er,S_er,S10,S_er),
   (S_er,S_er,S_er,S_er,S_er,S4,S_er,S_er,S_er,S_er),
   (S_er,S_er,S_er,S_er,S_er,S4,S_er,S_er,S10,S_er),
   (S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S11,S_er),
   (S_er,S_er,S_er,S_er,S_er,S_er,S_er,S7,S_er,S_er),
   (S_er,S_er,S_er,S_er,S_er,S_er,S_er,S_er,S12,S_er),
   (S_er,S_er,S_er,S_er,S9,S9,S_er,S_er,S13,S_er),
   (S_er,S_er,S_er,S_er,S9,S9,S_er,S_er,S13,S_er));

var
  Form1: TForm1;
  entry, lex_val: String;

implementation

{$R *.lfm}

{ TForm1 }

function TForm1.state_machine: lexeme_class;
var cur_state: state; cur_input: input_signal;
begin
  lex_val:=''; cur_state:=S0; cur_input:=recognize;
  while (cur_state <> S10) and (cur_state <> S11) and (cur_state <> S12) and (cur_state <> S13) and (cur_input <> endf) do
    begin
      cur_state:=next_state[cur_state,cur_input];
      if cur_state = S_er
        then raise exception.create('Лексическая ошибка!');
      if (cur_state <> S10) and (cur_state <> S11) and (cur_state <> S12) and (cur_state <> S13) then cur_input:=recognize;
    end;
  if (cur_state <> S10) and (cur_state <> S11) and (cur_state <> S12) and (cur_state <> S13) and (cur_input <> endf)
    then raise exception.create('Лексическая ошибка!')
    else
      case cur_state of
        S10: result:=digit;
        S11: result:=operation_mark;
        S12: result:=assignment;
        S13: result:=is_service_word;
      end;
end;

function TForm1.recognize: input_signal;
begin
  if entry = '' then result:=endf
  else
    begin
      case entry[1] of
        '+': result:=plus;
        '-': result:=dash;
        '.': result:=dot;
        ',': result:=com;
        ':': result:=colon;
        '=': result:=equality;
        ' ': result:=space;
        '0'..'9': result:=D;
        'a'..'z': result:=L;
        'A'..'Z': result:=L;
        else result:=other;
      end;
      lex_val:=lex_val+entry[1];
      entry:=copy(entry,2,length(entry)-1);
    end;
end;

function TForm1.is_service_word: lexeme_class;
var i: integer;
    lex: string;
    service_word_flag: boolean;
begin
  i:=0;
  lex:=TrimRight(lex_val);
  service_word_flag:=false;
  while (not service_word_flag) and (i <= length_array) do
    begin
      if lex = service_word_array[i] then service_word_flag:=true;
      inc(i);
    end;
  if service_word_flag
    then result:=service_word
    else result:=identifier;
end;

procedure TForm1.Button1Click(Sender: TObject);
begin
  entry:=TrimRight(edit1.Text) + ' ';
  while (entry <> '') do
    begin
      case state_machine of
        digit: Memo1.Lines.Add('Цифра: ' + lex_val);
        identifier: Memo1.Lines.Add('Идентификатор: ' + lex_val);
        assignment: Memo1.Lines.Add('Присвоение: ' + lex_val);
        operation_mark: Memo1.Lines.Add('Знак операции: ' + lex_val);
        service_word: Memo1.Lines.Add('Служебное слово: ' + lex_val);
      end;
    end;
  Memo1.Lines.Add('----------------------------------');
end;

end.

