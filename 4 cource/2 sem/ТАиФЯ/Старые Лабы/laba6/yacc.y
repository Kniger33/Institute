%{ unit yacc;
interface
uses lexlib, yacclib, Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs;

type 
	myString=string[255];

var 
	Table,Attributes: TStringList;
	tableErr,attrErr,attrFoundFlag: boolean; 
	part,table_str: string;
	f:TextFile;	i,j:integer;
	
%}

%token <myString> num
%token <myString> select_t
%token <myString> from_t
%token <myString> where_t
%token <myString> or_t
%token <myString> and_t
%token <myString> id

%type <myString> sql
%type <myString> select
%type <myString> from
%type <myString> where
%type <myString> field_list
%type <myString> condition_list
%type <myString> boolterm
%type <myString> condition
%type <myString> value
%type <myString> eopr
%%

goal : sql {    
    attrErr:=false;
	for i:=0 to Attributes.Count-1 do
    begin
	  attrFoundFlag:=false;
	  for j:=1 to Table.Count-1 do 
	    if Attributes[i] = Table[j] then 
		  begin
		    attrFoundFlag:=true;
			break;
		  end;	
	  if not attrFoundFlag then
        begin
          attrErr:=true;
		  break;
		end;		
	end;
	
	if (not tableErr) and (not attrErr) 
	  then showmessage('Успех! Операция реляционной алгебры: '+$1);
	if tableErr then showmessage('Ошибка! Не найдена таблица в базе данных!');
	if attrErr then showmessage('Ошибка! Не найдены указанные атрибуты таблицы!');
	Table.Destroy;
	Attributes.Destroy;
}

sql : select from where {$$:=$1+'('+$3+'('+$2+'))';}
	| select from {$$:=$1+'('+$2+')';}
	
select : select_t field_list {$$:='π '+$2;}
from : from_t id {
    tableErr:=false;
	$$:=$2;	
	Table:=TStringList.Create;
	AssignFile(f,'D:\users\61-вт\laba6v2\database\db.txt');
	Reset(f);
	while not eof(f) do
	  begin
	    Readln(f,table_str);
	    for i:=1 to Length(table_str) do
	      if table_str[i] = ' ' then
	        begin
	   	      Table.Add(part);
	 	      part:='';
	        end
	 	  else if i = Length(table_str) then
	 	    begin
	 	  	  part:=part+table_str[i];
	 	      Table.Add(part);
	 	  	  part:='';
	 	   end
	 	  else part:=part+table_str[i];
	    if Table[0] = $2 
		  then break
		  else Table.clear;
	  end;
    CloseFile(f);
	if Table.Count = 0 then tableErr:=true;
}
where : where_t condition_list {$$:='σ '+$2;}

field_list : field_list ',' id {
    $$:=$1+','+$3;
	Attributes.Add($3);
}
		   | id {
	$$:=$1;
	Attributes:=TStringList.Create;
	Attributes.Add($1);
}
		
condition_list : condition_list or_t boolterm {$$:=$1+' '+'∨'+' '+$3;} 
			   | boolterm
			   
boolterm : boolterm and_t condition {$$:=$1+' '+'∧'+' '+$3;} 
		 | condition		
		
condition : value eopr value {  
	$$:=$1+' '+$2+' '+$3;
	Attributes.Add($1);
	Attributes.Add($3);
} 

eopr : '<' {$$:='<';}
	 | '>' {$$:='>';} 
	 | '=' {$$:='=';}	
	 
value : id 
      | num				   
	 	 
%%	

(*$I SELECT_L.pas*)

end.