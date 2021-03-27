unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls, Grids;

type
  TForm1 = class(TForm)
    StringGrid1: TStringGrid;
    StringGrid2: TStringGrid;
    Label1: TLabel;
    Label2: TLabel;
    Edit1: TEdit;
    Label3: TLabel;
    RadioGroup1: TRadioGroup;
    RadioGroup2: TRadioGroup;
    StringGrid3: TStringGrid;
    Label4: TLabel;
    Button1: TButton;
    Button2: TButton;
    procedure FormShow(Sender: TObject);
    procedure StringGrid1KeyPress(Sender: TObject; var Key: Char);
    procedure Edit1KeyPress(Sender: TObject; var Key: Char);
    procedure Button1Click(Sender: TObject);
    function shuffle_string(s:string; pos:array of Integer):string;
    function pn(s,e:string):string;
    function loop(s:string):String;
    function f1_v2(s:string):string;
    function f2_v2(s:string):string;
    function f1_v3(s:string):string;
    function f2_v3(s:string):string;
    function gpc1:string;
    function gpc2:string;
    function sum(s:string):string;
    procedure Button2Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

const
  k11_v2:array [0..10] of Integer = (1,3,5,7,9,11,10,8,4,6,2);
  k11_v3:array [0..10] of Integer = (2,4,6,10,7,8,3,5,1,9,11);
  k7_v2:array [0..6] of Integer = (3,5,7,1,4,2,6);
  k7_v3:array [0..6] of Integer = (3,5,7,2,4,1,6);

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.FormShow(Sender: TObject);
var i:Integer;
begin
  for i:=0 to 10 do
    stringgrid1.cells[i,0]:=inttostr(i+1);
  for i:=0 to 6 do
    stringgrid2.cells[i,0]:=inttostr(i+1);
end;

procedure TForm1.StringGrid1KeyPress(Sender: TObject; var Key: Char);
begin
  if not (Key in ['0','1',#8]) then key:=#0;
end;

procedure TForm1.Edit1KeyPress(Sender: TObject; var Key: Char);
begin
 if not (Key in ['0'..'9',#8]) then key:=#0;
end;

procedure TForm1.Button1Click(Sender: TObject);
var n,i:integer;
begin
  n:=strtoint(Edit1.Text);
  StringGrid3.ColCount:=n;
  for i:=0 to n-1 do
   StringGrid3.Cells[i,0]:=IntToStr(i+1);

  case RadioGroup1.ItemIndex of
    0: for i:=0 to n-1 do
        StringGrid3.Cells[i,1]:=gpc1;
    1: for i:=0 to n-1 do
        StringGrid3.Cells[i,1]:=gpc2;
  end;
end;

function TForm1.shuffle_string(s: string; pos: array of Integer): string;
var i:Integer;
begin
 result:=s;
 for i:=0 to Length(s)-1 do
   Result[i+1]:=s[Pos[i]];
end;

function TForm1.loop(s: string): String;
begin
 result:=s;
 Delete(Result,1,1);
 Result:=Result+inttostr(strtoint(s[1]) xor strtoint(s[9]));
end;

function TForm1.f1_v2(s: string): string;
begin
  result:=IntToStr(strtoint(s[1]) or strtoint(s[10]) xor strtoint(s[2]) or strtoint(s[5]) and strtoint(s[6]) xor strtoint(s[11]));
end;

function TForm1.f1_v3(s: string): string;
begin
  result:=IntToStr(strtoint(s[2]) or strtoint(s[10]) xor strtoint(s[7]) or strtoint(s[5]) and strtoint(s[6]) xor strtoint(s[11]));
end;

function TForm1.f2_v2(s: string): string;
begin
  result:=IntToStr(strtoint(s[1]) and strtoint(s[6]) xor strtoint(s[4]) and strtoint(s[5]));
end;

function TForm1.f2_v3(s: string): string;
begin
  result:=IntToStr(strtoint(s[2]) and strtoint(s[6]) xor strtoint(s[4]) and strtoint(s[7]));
end;

function TForm1.gpc1: string;
var i:Integer; buf:string;
begin
  buf:='';

  for i:=0 to 10 do
    buf:=buf+stringgrid1.Cells[i,1];

  buf:=loop(buf);

  for i:=0 to 10 do
    stringgrid1.Cells[i,1]:=buf[i+1];

  case RadioGroup2.ItemIndex of
    0:
      begin
        buf:=shuffle_string(buf,k11_v2);
        buf:=f1_v2(buf);
      end;
    1:
      begin
        buf:=shuffle_string(buf,k11_v3);
        buf:=f1_v3(buf);
      end;
  end;

  result:=buf;
end;

//Стандартные значения
procedure TForm1.Button2Click(Sender: TObject);
begin
  Edit1.Text:='16';
  StringGrid1.Cells[0,1]:='1';
  StringGrid1.Cells[1,1]:='1';
  StringGrid1.Cells[2,1]:='1';
  StringGrid1.Cells[3,1]:='0';
  StringGrid1.Cells[4,1]:='0';
  StringGrid1.Cells[5,1]:='0';
  StringGrid1.Cells[6,1]:='0';
  StringGrid1.Cells[7,1]:='1';
  StringGrid1.Cells[8,1]:='0';
  StringGrid1.Cells[9,1]:='1';
  StringGrid1.Cells[10,1]:='0';

  StringGrid2.Cells[0,1]:='1';
  StringGrid2.Cells[1,1]:='0';
  StringGrid2.Cells[2,1]:='1';
  StringGrid2.Cells[3,1]:='0';
  StringGrid2.Cells[4,1]:='1';
  StringGrid2.Cells[5,1]:='0';
  StringGrid2.Cells[6,1]:='1';
end;

function TForm1.gpc2: string;
var i:Integer; buf,e:string;
begin
  buf:='';

  for i:=0 to 10 do
    buf:=buf+stringgrid1.Cells[i,1];

  buf:=loop(buf);

  for i:=0 to 10 do
    stringgrid1.Cells[i,1]:=buf[i+1];

  case RadioGroup2.ItemIndex of
    0:
      begin
        e:=sum(buf);
        buf:='';
        for i:=0 to 6 do
          buf:=buf+stringgrid2.Cells[i,1];
        buf:=pn(buf,e);
        for i:=0 to 6 do
          stringgrid2.Cells[i,1]:=buf[i+1];
        buf:=shuffle_string(buf,k7_v2);
        buf:=f2_v2(buf);
      end;
    1:
      begin
        e:=sum(buf);
        buf:='';
        for i:=0 to 6 do
          buf:=buf+stringgrid2.Cells[i,1];
        buf:=pn(buf,e);
        for i:=0 to 6 do
          stringgrid2.Cells[i,1]:=buf[i+1];
        buf:=shuffle_string(buf,k7_v3);
        buf:=f2_v3(buf);
      end;
  end;

  result:=buf;
end;

function TForm1.sum(s: string): string;
begin
  result:=IntToStr(StrToInt(s[1]) xor StrToInt(s[2]) xor StrToInt(s[3]) xor StrToInt(s[4]) xor StrToInt(s[5]) xor StrToInt(s[6]) xor StrToInt(s[7]) xor StrToInt(s[8]) xor StrToInt(s[9]) xor StrToInt(s[10]) xor StrToInt(s[11]));
end;

function TForm1.pn(s, e: string): string;
begin
 result:=s;
 Delete(Result,1,1);
 Result:=Result+e;
end;

end.
 
