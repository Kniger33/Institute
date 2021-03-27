unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  lexlib, yacc, Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, StdCtrls;

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
begin
  yymemoinit(Memo1,Memo2,Memo3,Memo4);
  yyclear;
  yylineno:=0;
  yyparse;
  {
  select studid, studname, studgruop
  from student
  where studid < studname and
        studname > studgruop or
        studid = studgruop
  }
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
  Memo1.Lines.Clear;
  Memo2.Lines.Clear;
end;

end.

