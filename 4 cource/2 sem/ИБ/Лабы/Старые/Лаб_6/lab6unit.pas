unit Lab6Unit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, StdCtrls,
  Grids, Math;

const
  m = 4;
  n = 6;


type

  { TLab6Form }

  TLab6Form = class(TForm)
    EncodeButton: TButton;
    FindKeyButton: TButton;
    StringGrid1: TStringGrid;
    StringGrid2: TStringGrid;
    StringGrid3: TStringGrid;
    StringGrid4: TStringGrid;
    procedure EncodeButtonClick(Sender: TObject);
    procedure FindKeyButtonClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private
    { private declarations }
  public
    { public declarations }
  end;

  tip1 = record
    q1: integer;
    q2: integer;
  end;

  zap = record
    fl, fl1: boolean;
    Kluch: array [1..m] of byte;
  end;

var
  Lab6Form: TLab6Form;

implementation

{$R *.lfm}

{ TLab6Form }

function ixor(i1, i2: integer): integer;
begin
  result:=Integer(i1<>i2);
end;

function convertIntToMas(k: integer): string;
begin
  result:='';
  while k>1 do
  begin
    result:=result+IntToStr(k mod 2);
    k:=k div 2;
  end;
  result:=result+IntToStr(k);
end;

function ConvertBinToInt(s: string; l: integer): integer;
var
  i: integer;
begin
  result:=0;
  for i:=1 to l do
     result:=result+StrToInt(s[i])*round(power(2,i-1));
end;


procedure TLab6Form.EncodeButtonClick(Sender: TObject);
var
  K: array [1..m, 1..n] of byte;
  a1, a2, a3: array [1..n] of byte;
  i, j, l: integer;
  s: string;
begin
  StringGrid3.RowCount:=1;
  k[1,1]:=0;k[1,2]:=1;k[1,3]:=1;k[1,4]:=0;k[1,5]:=1;k[1,6]:=1;    //54
  k[2,1]:=1;k[2,2]:=0;k[2,3]:=0;k[2,4]:=0;k[2,5]:=1;k[2,6]:=0;    //17
  k[3,1]:=1;k[3,2]:=0;k[3,3]:=1;k[3,4]:=1;k[3,5]:=0;k[3,6]:=0;    //13
  k[4,1]:=0;k[4,2]:=1;k[4,3]:=0;k[4,4]:=1;k[4,5]:=0;k[4,6]:=0;    //10
  for i :=0 to stringGrid1.RowCount-1 do
  begin
    s:=StringGrid1.Cells[0,i];
    for l:=1 to n do
      a1[l]:=StrtoInt(s[l]);
    s:=StringGrid1.Cells[1,i];
    for l:=1 to n do
      a2[l]:=StrtoInt(s[l]);
    for l :=1 to m do
    begin
      for j :=1 to n do
      begin
        if j-3<1 then
          a3[j-3+6]:=ixor(a2[j],k[l,j])
        else
          a3[j-3]:=ixor(a2[j],k[l,j]);
      end;
      for j :=1 to n do
      begin
        a3[j]:=ixor(a3[j],a1[j]);
        a1[j]:=a2[j];
        a2[j]:=a3[j];
      end;
    end;
    s:='';
    for l:=1 to n do
      s:=s+IntToStr(a1[l]);
    StringGrid2.Cells[0,i]:=s; s:='';
    for l:=1 to n do
      s:=s+IntToStr(a2[l]);
    StringGrid2.Cells[1,i]:=s;
  end;
end;

procedure TLab6Form.FindKeyButtonClick(Sender: TObject);
var
  mas: array [0..63,0..63] of zap;
  a1, a2, a3: array [1..n] of integer;
  i, j, l, i1: integer;
  q1, q2: integer;
  s, s2: string;
begin
  StringGrid3.RowCount:=1;StringGrid4.RowCount:=1;
  //for i :=0 to stringGrid1.RowCount-1 do begin
  s:='';
  s:=StringGrid1.Cells[0,0];
  for l:=1 to n do
    if not TryStrtoInt(s[l], a1[l]) then
      exit;
  s:=StringGrid1.Cells[1,0];
  for l:=1 to n do
    if not TryStrtoInt(s[l], a2[l]) then
      exit;
  for l :=0 to 63 do
    for j :=0 to 63 do
    begin
      mas[l,j].fl:=false;
      mas[l,j].fl1:=false;
    end;
    // подбор ключей 1,2
    for q1 :=0 to 63 do
    begin
      for q2 :=0 to 63 do
      begin
        s:='';
        s:=StringGrid1.Cells[0,0];
        for l:=1 to n do
          a1[l]:=StrtoInt(s[l]);
        s:=StringGrid1.Cells[1,0];
        for l:=1 to n do
          a2[l]:=StrtoInt(s[l]);
        s:=convertIntToMas(q1);
        if Length(s)<6 then
          for i1:=Length(s) to n-1 do
            s:=s+'0';
        for j :=1 to n do
        begin
          if j-3<1 then
            a3[j-3+6]:=ixor(a2[j],StrToInt(s[j]))
          else
            a3[j-3]:=ixor(a2[j],StrToInt(s[j]));
        end;
        for j :=1 to n do
        begin
          a3[j]:=ixor(a3[j],a1[j]);
          a1[j]:=a2[j];
          a2[j]:=a3[j];
        end;
        s:=convertIntToMas(q2);
        if Length(s)<6 then
          for i1:=Length(s) to n-1 do
            s:=s+'0';
        for j:=1 to n do
        begin
          if j-3<1 then
            a3[j-3+6]:=ixor(a2[j],StrToInt(s[j]))
          else
            a3[j-3]:=ixor(a2[j],StrToInt(s[j]));
        end;
        for j :=1 to n do begin
          a3[j]:=ixor(a3[j],a1[j]);
          a1[j]:=a2[j];
          a2[j]:=a3[j];
        end;
        s:='';
        for l:=1 to n do
          s:=s+IntToStr(a2[l]);
        i:= ConvertBinToInt(s,6);
        s:='';
        for l:=1 to n do
          s:=s+IntToStr(a1[l]);
        j:=ConvertBinToInt(s,6);
        mas[j,i].fl:=true;
        mas[j,i].Kluch[1]:=q1;
        mas[j,i].Kluch[2]:=q2;
      end;
    end;
    // подбор ключей 3,4
    for q1 :=0 to 63 do
    begin
      for q2 :=0 to 63 do
      begin
        s:=StringGrid2.Cells[1,0];
        for l:=1 to n do
          a1[l]:=StrtoInt(s[l]);
        s:=StringGrid2.Cells[0,0];
        for l:=1 to n do
          a2[l]:=StrtoInt(s[l]);
        s:='';
        s:=convertIntToMas(q2);
        if Length(s)<6 then
          for i1:=Length(s) to n-1 do
            s:=s+'0';
        for j :=1 to n do
        begin
          if j-3<1 then
            a3[j-3+6]:=ixor(a2[j],StrToInt(s[j]))
          else
            a3[j-3]:=ixor(a2[j],StrToInt(s[j]));
        end;
        for j :=1 to n do
        begin
          a3[j]:=ixor(a3[j],a1[j]);
          a1[j]:=a2[j];
          a2[j]:=a3[j];
        end;
        s:=convertIntToMas(q1);
        if Length(s)<6 then
          for i1:=Length(s) to n-1 do
          s:=s+'0';
        for j :=1 to n do
        begin
          if j-3<1 then
            a3[j-3+6]:=ixor(a2[j],StrToInt(s[j]))
          else
            a3[j-3]:=ixor(a2[j],StrToInt(s[j]));
        end;
        for j :=1 to n do
        begin
          a3[j]:=ixor(a3[j],a1[j]);
          a1[j]:=a2[j];
          a2[j]:=a3[j];
        end;
        s:='';
        for l:=1 to n do
          s:=s+IntToStr(a2[l]);
        j:=ConvertBinToInt(s,6);
        s:='';
        for l:=1 to n do
          s:=s+IntToStr(a1[l]);
        i:=ConvertBinToInt(s,6);
        if mas[j,i].fl then
        begin
          mas[j,i].fl1:=true;
          mas[j,i].Kluch[3]:=q1;
          mas[j,i].Kluch[4]:=q2;
        end;
      end;
    end;
    // отбраковка ключей
    for q1:=0 to 63 do
    begin
      for q2:=0 to 63 do
      begin
        if (mas[q1,q2].fl and mas[q1,q2].fl1) then
        begin
          for i :=1 to stringGrid1.RowCount-1 do
          begin
            s:=StringGrid1.Cells[0,i];
            for l:=1 to n do
              a1[l]:=StrtoInt(s[l]);
            s:=StringGrid1.Cells[1,i];
            for l:=1 to n do
              a2[l]:=StrtoInt(s[l]);
            s:='';
            for l :=1 to m do
            begin
              s:=convertIntToMas(mas[q1,q2].Kluch[l]);
              if Length(s)<6 then
                for i1:=Length(s) to n-1 do
                  s:=s+'0';
              if mas[q1,q2].Kluch[1]=54 then
                StringGrid4.Cells[l-1,StringGrid4.RowCount-1]:=s;
              for j :=1 to n do
              begin
                if j-3<1 then
                  a3[j-3+6]:=ixor(a2[j],StrToInt(s[j]))
                else
                  a3[j-3]:=ixor(a2[j],StrToInt(s[j]));
              end;
              for j :=1 to n do
              begin
                a3[j]:=ixor(a3[j],a1[j]);
                a1[j]:=a2[j];
                a2[j]:=a3[j];
              end;
            end;
            s:='';
            for l:=1 to n do
              s:=s+IntToStr(a1[l]);
           s2:=StringGrid2.Cells[0,i];
           if s2=s then
           begin
             s:='';
             for l:=1 to n do
               s:=s+IntToStr(a2[l]);
             s2:=StringGrid2.Cells[1,i];
             if s2<>s then
               mas[q1,q2].fl:=false;
           end
           else
           begin
             mas[q1,q2].fl:=false;
           end;
         end;
         if mas[q1,q2].Kluch[1]=54 then
           StringGrid4.RowCount:=StringGrid4.RowCount+1;
       end;
     end;
  end;
  //вывод результата
  for q1 :=0 to 63 do
  begin
    for q2 :=0 to 63 do
    begin
      if (mas[q1,q2].fl and mas[q1,q2].fl1) then
      begin
        s:=convertIntToMas(mas[q1,q2].Kluch[1]);
        if Length(s)<6 then
          for i1:=Length(s) to n-1 do
            s:=s+'0';
        StringGrid3.Cells[0,StringGrid3.RowCount-1]:=s;
        s:=convertIntToMas(mas[q1,q2].Kluch[2]);
        if Length(s)<6 then
          for i1:=Length(s) to n-1
            do s:=s+'0';
        StringGrid3.Cells[1,StringGrid3.RowCount-1]:=s;
        s:=convertIntToMas(mas[q1,q2].Kluch[3]);
        if Length(s)<6 then
          for i1:=Length(s) to n-1 do
            s:=s+'0';
        StringGrid3.Cells[2,StringGrid3.RowCount-1]:=s;
        s:=convertIntToMas(mas[q1,q2].Kluch[4]);
        if Length(s)<6 then
          for i1:=Length(s) to n-1 do
            s:=s+'0';
        StringGrid3.Cells[3,StringGrid3.RowCount-1]:=s;
        StringGrid3.RowCount:=StringGrid3.RowCount+1;
      end;
    end;
  end;
end;

procedure TLab6Form.FormCreate(Sender: TObject);
begin
  StringGrid1.Cells[0,0]:='101010';
  StringGrid1.Cells[1,0]:='001101';
  StringGrid1.Cells[0,1]:='111011';
  StringGrid1.Cells[1,1]:='011011';
  StringGrid1.Cells[0,2]:='110010';
  StringGrid1.Cells[1,2]:='110101';
end;

end.

