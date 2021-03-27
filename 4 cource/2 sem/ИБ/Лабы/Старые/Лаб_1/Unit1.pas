unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Grids, ComCtrls;

type
  TForm1 = class(TForm)
    PageControl1: TPageControl;
    TabSheet1: TTabSheet;
    TabSheet2: TTabSheet;
    TabSheet3: TTabSheet;
    TabSheet4: TTabSheet;
    TabSheet5: TTabSheet;
    StringGrid1: TStringGrid;
    Button1: TButton;
    Edit1: TEdit;
    Edit2: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Button2: TButton;
    Button3: TButton;
    Label3: TLabel;
    Edit3: TEdit;
    Label4: TLabel;
    Edit4: TEdit;
    Button4: TButton;
    StringGrid2: TStringGrid;
    StringGrid3: TStringGrid;
    Edit5: TEdit;
    Label5: TLabel;
    StringGrid4: TStringGrid;
    Button5: TButton;
    Edit6: TEdit;
    Label6: TLabel;
    Label7: TLabel;
    Edit7: TEdit;
    Label8: TLabel;
    Edit8: TEdit;
    Label9: TLabel;
    Edit9: TEdit;
    StringGrid5: TStringGrid;
    Button6: TButton;
    StringGrid6: TStringGrid;
    StringGrid7: TStringGrid;
    Label10: TLabel;
    Edit10: TEdit;
    Edit11: TEdit;
    Label11: TLabel;
    Button7: TButton;
    Button8: TButton;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Button7Click(Sender: TObject);
    procedure Button8Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1; last:Integer;

implementation

{$R *.dfm}

// Полибиан
// заполнить случайно
procedure TForm1.Button1Click(Sender: TObject);
const
  alf: array [0..25] of string = ('q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m');
var i,j,r:integer; p:array [0..25] of integer;
begin
  for i:=0 to 25 do
   p[i]:=0;
  for i:=0 to 4 do
    for j:=0 to 4 do
     begin
      r:= random(25);
      while p[r]<>0 do
        r:=random(25);
      stringgrid1.cells[i,j]:=alf[r];
      p[r]:=1;
     end;
   for i:=0 to 25 do
    if p[i]=0 then
     begin
       last:=p[i];
       break;
     end;
end;

//шифровать
procedure TForm1.Button2Click(Sender: TObject);
var s,res:string; i,j,l,i1,j1:integer; found:boolean;
begin
  if StringGrid1.Cells[0,0]='' then Button1.Click;
  res:='';
  if length(Edit1.text)=0 then exit;
  s:=AnsiLowerCase(Edit1.Text);
  s:=Edit1.text;
  for l:=1 to length(s) do
   begin
    found:=false;
    for i:=0 to 4 do
     for j:=0 to 4 do
      if stringgrid1.cells[i,j]=s[l] then
       begin
         i1:=i;
         j1:=j;
         found:=true;
         break;
       end;
    j1:=j1+1;
    if j1=5 then j1:=0;
    if found=false then res:=res+s[l] else
      res:=res+stringgrid1.cells[i1,j1];
   end;
  edit2.text:=res;
end;

//дешифровать
procedure TForm1.Button3Click(Sender: TObject);
var s,res:string; i,j,l,i1,j1:integer; found:boolean;
begin
  if StringGrid1.Cells[0,0]='' then Button1.Click;
  res:='';
  if length(Edit1.text)=0 then exit;
  s:=AnsiLowerCase(Edit1.Text);
  s:=Edit1.text;
  for l:=1 to length(s) do
   begin
    found:=false;
    for i:=0 to 4 do
     for j:=0 to 4 do
      if stringgrid1.cells[i,j]=s[l] then
       begin
         i1:=i;
         j1:=j;
         found:=true;
         break;
       end;
    j1:=j1-1;
    if j1=-1 then j1:=4;
    if found=false then res:=res+s[l] else
      res:=res+stringgrid1.cells[i1,j1];
   end;
  edit2.text:=res;
end;

// Перестановка по ключу
procedure TForm1.Button4Click(Sender: TObject);
var i,j,k:Integer; s1,s2:string; l:TStringList;
begin
 if Length(edit4.Text)< 7 then
  begin
    ShowMessage('ƒлина ключа должна равн€тьс€ 7!');
    Exit;
  end;
 l:=TStringList.Create;
 s1:=AnsiLowerCase(Edit4.Text);
 s2:=AnsiLowerCase(Edit3.Text);
 if (s1='') or (s2='') then Exit;
 for i:=0 to Length(s1)-1 do
   begin
     StringGrid2.Cells[i,0]:=s1[i+1];
     l.Add(s1[i+1])
   end;

 l.Sort;

 for i:=0 to Length(s1)-1 do
   begin
     k:=1;
     while s1[k]<>l[i] do Inc(k);
     s1[k]:=inttostr(i+1)[1];
   end;

 for i:=0 to Length(s1)-1 do
   begin
     StringGrid2.Cells[i,1]:=s1[i+1];
   end;

 k:=1;
 for i:=0 to StringGrid2.ColCount-1 do
   for j:=2 to StringGrid2.RowCount-1 do
    begin
     if k>Length(s2) then Break;
     while s2[k]=' ' do inc(k);
     StringGrid2.Cells[i,j]:=s2[k];
     inc(k);
    end;
 for i:=0 to StringGrid2.RowCount-1 do
  begin
    j:=0;
    while StringGrid2.Cells[j,1]<>inttostr(i+1) do Inc(j);
    StringGrid3.Cols[i]:=StringGrid2.Cols[j];
  end;
end;

//Метод биграмм
procedure TForm1.Button5Click(Sender: TObject);
var i,j,i1,i2,j1,j2,k,o:Integer; s1,s2,a,b:string; l:TStringList;  c:Char;
begin
 if Length(Edit5.Text) mod 2 <> 0 then
 begin
   ShowMessage('ƒлина исходного текста должна быть кратна 2!');
   Exit;
 end;
 l:=TStringList.Create;
 for c:='а' to '€' do
  if (c='ь') then l.Add('ы') else
   if (c='ы') then l.Add('ь') else
    if (c<>'ъ') and (c<>'й') then l.Add(c);
 s1:=AnsiLowerCase(Edit7.Text);
 s2:=AnsiLowerCase(Edit5.Text);

 s2:=StringReplace(s2,' ','',[rfreplaceall]);

 i:=1;
 while i<Length(s1)+1 do
  begin
    j:=i+1;
    while j<Length(s1)+1 do
     begin
      if s1[j]=s1[i] then s1[j]:=' ';
      Inc(j);
     end;
    Inc(i);
  end;

 s1:=StringReplace(s1,' ','',[rfreplaceall]);

 k:=1;
 for i:=0 to StringGrid4.RowCount-1 do
   for j:=0 to StringGrid4.ColCount-1 do
    if k<=Length(s1) then
     begin
      StringGrid4.Cells[j,i]:=s1[k];
      if l.IndexOf(s1[k])>-1 then
        l.Delete(l.IndexOf(s1[k]));
      Inc(k);
     end
    else
     begin
      StringGrid4.Cells[j,i]:=l[0];
      l.Delete(0);
     end;

 s1:='';
 k:=1;
 while k<Length(s2)+1 do
  begin
   a:=s2[k];
   inc(k);
   b:=s2[k];
   inc(k);

   i1:=-1;
   i2:=-1;
   j1:=-1;
   j2:=-1;

   for i:=0 to StringGrid4.RowCount-1 do
    for j:=0 to StringGrid4.ColCount-1 do
     begin
      if StringGrid4.Cells[j,i]=a then
       begin
        i1:=i;
        j1:=j;
       end;
      if StringGrid4.Cells[j,i]=b then
       begin
        i2:=i;
        j2:=j;
       end;
     end;

   if i1=i2 then
    begin
     inc(j1);
     Inc(j2);
     if j1=StringGrid4.ColCount then j1:=0;
     if j2=StringGrid4.ColCount then j2:=0;
    end else
   if j1=j2 then
    begin
     inc(i1);
     Inc(i2);
     if i1=StringGrid4.RowCount then i1:=0;
     if i2=StringGrid4.RowCount then i2:=0;
    end else
    begin
     o:=j1;
     j1:=j2;
     j2:=o;
    end;
   s1:=s1+stringgrid4.Cells[j1,i1]+stringgrid4.Cells[j2,i2]+' ';
  end;

  Edit6.Text:=s1;
end;

//трафаретный
procedure TForm1.Button6Click(Sender: TObject);
const m1: array [0..3,0..3] of string =(('#','#',' ','#'),
                                        ('#','#','#',' '),
                                        ('#',' ','#','#'),
                                        (' ','#','#','#'));
var i,j,k:Integer; s1:string; m2,m3:array[0..3,0..3] of string; str:array[0..3] of string;
begin
 for i:=0 to 3 do
  for j:=0 to 3 do
   m2[i,j]:=m1[i,j];

 s1:=AnsiLowerCase(Edit8.Text);
 while Length(s1)<16 do s1:=s1+' ';

 k:=1;
 for i:=0 to 3 do
  for j:=0 to 3 do
   if m2[i,j]=' ' then
    begin
     m3[i,j]:=s1[k];
     inc(k);
    end;

 for i:=0 to 3 do
   str[i]:=m2[0,i];
 for i:=0 to 3 do
   m2[0,i]:=m2[3,i];
 for i:=0 to 3 do
   m2[3,i]:=str[i];
 for i:=0 to 3 do
   str[i]:=m2[1,i];
 for i:=0 to 3 do
   m2[1,i]:=m2[2,i];
 for i:=0 to 3 do
   m2[2,i]:=str[i];

 for i:=0 to 3 do
  for j:=0 to 3 do
   if m2[i,j]=' ' then
    begin
     m3[i,j]:=s1[k];
     inc(k);
    end;

 for i:=0 to 3 do
   str[i]:=m1[0,i];
 for i:=0 to 3 do
   m2[0,i]:=m1[1,i];
 for i:=0 to 3 do
   m2[1,i]:=str[i];
 for i:=0 to 3 do
   str[i]:=m1[2,i];
 for i:=0 to 3 do
   m2[2,i]:=m1[3,i];
 for i:=0 to 3 do
   m2[3,i]:=str[i];

 for i:=0 to 3 do
  for j:=0 to 3 do
   if m2[i,j]=' ' then
    begin
     m3[i,j]:=s1[k];
     inc(k);
    end;

 for i:=0 to 3 do
   str[i]:=m1[0,i];
 for i:=0 to 3 do
   m2[0,i]:=m1[2,i];
 for i:=0 to 3 do
   m2[2,i]:=str[i];
 for i:=0 to 3 do
   str[i]:=m1[1,i];
 for i:=0 to 3 do
   m2[1,i]:=m1[3,i];
 for i:=0 to 3 do
   m2[3,i]:=str[i];

 for i:=0 to 3 do
  for j:=0 to 3 do
   if m2[i,j]=' ' then
    begin
     m3[i,j]:=s1[k];
     inc(k);
    end;

 for i:=0 to 3 do
  for j:=0 to 3 do
   StringGrid5.Cells[j,i]:=m3[i,j];

 Edit9.Text:='';
 for i:=0 to 3 do
  for j:=0 to 3 do
   Edit9.Text:=Edit9.Text+StringGrid5.Cells[j,i];
end;

//2 таблицы
procedure TForm1.Button7Click(Sender: TObject);
var i,j,i1,i2,j1,j2,k,o:Integer; s1,s2,a,b:string; c:char;
begin

 s1:=AnsiLowerCase(Edit10.Text);
 k:=1;
 while k<Length(s1)+1 do
  begin
   a:=s1[k];
   Inc(k);
   b:=s1[k];
   Inc(k);

   for i:=0 to 6 do
    for j:=0 to 4 do
     begin
      if stringgrid6.Cells[j,i]=a then
       begin
         i1:=i;
         j1:=j;
       end;
      if stringgrid7.Cells[j,i]=b then
       begin
         i2:=i;
         j2:=j;
       end;
     end;

     if i1<>i2 then
       begin
        o:=i2;
        i2:=i1;
        i1:=o;
       end
     else
       begin
        o:=j2;
        j2:=j1;
        j1:=o;
       end;
     a:=stringgrid6.Cells[j1,i1];
     b:=stringgrid7.Cells[j2,i2];
     s2:=s2+b+a+' ';
  end;

  Edit11.Text:=s2;
end;

procedure TForm1.Button8Click(Sender: TObject);
var l1,l2:TStringList; c:Char; i,j,k:Integer;
begin
 l1:=TStringList.Create;
 l2:=TStringList.Create;
 for c:='а' to '€' do
  if (c='ь') then l1.Add('ы') else
   if (c='ы') then l1.Add('ь') else
    if (c<>'й') then l1.Add(c);
 l1.Add(' ');
 l1.Add('.');
 l1.Add(',');
 l1.Add(':');

 for i:=0 to l1.Count-1 do
  l2.Add(l1[i]);
 for i:=0 to 6 do
  for j:=0 to 4 do
   begin
    k:=Random(l2.Count-1);
    stringgrid6.Cells[j,i]:=l2[k];
    l2.Delete(k);
   end;

 for i:=0 to l1.Count-1 do
  l2.Add(l1[i]);
 for i:=0 to 6 do
  for j:=0 to 4 do
   begin
    k:=Random(l2.Count-1);
    stringgrid7.Cells[j,i]:=l2[k];
    l2.Delete(k);
   end;
end;

end.
