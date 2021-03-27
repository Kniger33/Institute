unit Unit1;

{$IFDEF FPC}
  {$MODE Delphi}
{$ENDIF}

interface

uses
{$IFnDEF FPC}
  Windows,
{$ELSE}
  LCLIntf, LCLType, LMessages,
{$ENDIF}
  Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ComCtrls,StrUtils,DES;

type
  TForm1 = class(TForm)
    PageControl1: TPageControl;
    TabSheet1: TTabSheet;
    TabSheet2: TTabSheet;
    TabSheet3: TTabSheet;
    TabSheet4: TTabSheet;
    Edit1: TEdit;
    Edit2: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Edit3: TEdit;
    Button1: TButton;
    Label3: TLabel;
    Label4: TLabel;
    Edit4: TEdit;
    Label5: TLabel;
    Edit5: TEdit;
    Edit6: TEdit;
    Button2: TButton;
    Label6: TLabel;
    Button3: TButton;
    Button4: TButton;
    Button5: TButton;
    Edit7: TEdit;
    Label7: TLabel;
    Label8: TLabel;
    Edit8: TEdit;
    Label9: TLabel;
    Edit9: TEdit;
    Label10: TLabel;
    Edit10: TEdit;
    Label11: TLabel;
    Edit11: TEdit;
    Label12: TLabel;
    Edit12: TEdit;
    Label13: TLabel;
    Edit13: TEdit;
    Label14: TLabel;
    Edit14: TEdit;
    Label15: TLabel;
    Edit15: TEdit;
    Button6: TButton;
    Button7: TButton;
    procedure Button1Click(Sender: TObject);
    function XorStr(Stri, Strk: String): String;
    function encode(st,k:string):string;
    function decode(st, k: string): string;
    procedure Edit1KeyPress(Sender: TObject; var Key: Char);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Button7Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

function TForm1.XorStr(Stri, Strk: String): String;
var
    Longkey: string;
    I: Integer;
    Next: char;
begin
    for I := 0 to (Length(Stri) div Length(Strk)) do
    Longkey := Longkey + Strk;
    for I := 1 to length(Stri) do
    begin
        Next := chr((ord(Stri[i]) xor ord(Longkey[i])));
        Result := Result + Next;
    end;
end;

procedure TForm1.Edit1KeyPress(Sender: TObject; var Key: Char);
begin
  if not (Key in ['0'..'9']) then Key:=#0;
end;

function TForm1.encode(st, k: string): string;
var i,j:byte; buf:string; res:string;
begin
  res:='';
  while Length(k)<=Length(st) do
  begin
    buf:=Copy(st,1,Length(k));
    delete(st,1,Length(k));
    for I := 1 to length(k) do
      res:=res+buf[strtoint(k[i])];
  end;
  result:=res;
end;

function TForm1.decode(st, k: string): string;
var i,j:byte; buf:string; res,s:string;
begin
  res:='';
  s:='';
  for i:=1 to Length(k) do s:=s+' ';

  while Length(k)<=Length(st) do
  begin
    buf:=Copy(st,1,Length(k));
    delete(st,1,Length(k));
    for I := 1 to length(k) do
      s:=StuffString(s,strtoint(k[i]),1,buf[i]);
    res:=res+s;
  end;
  result:=res;
end;

procedure TForm1.Button1Click(Sender: TObject);
begin
  Edit3.Text:=XorStr(Edit2.Text,Edit1.Text);
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
  Edit6.text:=encode(XorStr(Edit5.Text,Edit4.Text),Edit4.Text);
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
  Edit6.text:=XorStr(decode(Edit5.Text,Edit4.Text),Edit4.Text);
end;

procedure TForm1.Button5Click(Sender: TObject);
var Data:TBitString; I:Integer; S:String;
begin
  while (Length(Edit7.Text) mod 8) <> 0 do Edit7.Text:=Edit7.Text+' ';
  while (Length(Edit8.Text) mod 8) <> 0 do Edit8.Text:=Edit8.Text+' ';

  SetLength(Data,0);
  I:=1;
  While I<=Length(Edit8.Text) Do
    Begin
     S:=Copy(Edit8.Text,I,8);
     Data:=ConcatBits([Data,DESEncode(S,Edit7.Text)]);
     I:=I+8;
    End;
  Edit9.Text:=BinToAnsiStr(Data);
end;

procedure TForm1.Button4Click(Sender: TObject);
var I:Integer; Data:TBitString; S:String;
begin
  Edit8.text:=Edit9.text;
  SetLength(Data,0);
  I:=1;
  While I<=Length(Edit8.Text) Do
    Begin
     S:=Copy(Edit8.Text,I,8);
     Data:=ConcatBits([Data,DESDecode(s,Edit7.Text)]);
     I:=I+8;
    End;
  Edit9.Text:=BinToAnsiStr(Data);
end;

procedure TForm1.Button6Click(Sender: TObject);
begin
  Edit15.Text:=XorStr(XorStr(XorStr(XorStr(Edit14.Text,Edit10.Text),Edit11.Text),edit12.text),Edit13.Text);
end;

procedure TForm1.Button7Click(Sender: TObject);
begin
  Edit15.Text:=XorStr(XorStr(XorStr(XorStr(Edit14.Text,Edit13.Text),Edit12.Text),edit11.text),Edit10.Text);
end;

end.
