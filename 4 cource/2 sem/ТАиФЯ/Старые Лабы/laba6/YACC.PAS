
(* Yacc parser template (TP Yacc V3.0), V1.2 6-17-91 AG *)

(* global definitions: *)
 unit yacc;
interface
uses lexlib, yacclib, Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs;

type 
	myString=string[255];

var 
	Table,Attributes: TStringList;
	tableErr,attrErr,attrFoundFlag: boolean; 
	part,table_str: string;
	f:TextFile;	i,j:integer;
	
const num = 257;
const select_t = 258;
const from_t = 259;
const where_t = 260;
const or_t = 261;
const and_t = 262;
const id = 263;

type YYSType = record case Integer of
                 1 : ( yymyString : myString );
               end(*YYSType*);

var yylval : YYSType;

function yyparse : Integer;


implementation

function yylex : Integer; forward;
function yyparse : Integer;

var yystate, yysp, yyn : Integer;
    yys : array [1..yymaxdepth] of Integer;
    yyv : array [1..yymaxdepth] of YYSType;
    yyval : YYSType;

procedure yyaction ( yyruleno : Integer );
  (* local definitions: *)
begin
  (* actions: *)
  case yyruleno of
   1 : begin
         
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
         	  then showmessage('Успех! Операция реляционной алгебры: '+yyv[yysp-0].yymyString);
         	if tableErr then showmessage('Ошибка! Не найдена таблица в базе данных!');
         	if attrErr then showmessage('Ошибка! Не найдены указанные атрибуты таблицы!');
         	Table.Destroy;
         	Attributes.Destroy;
         
       end;
   2 : begin
         yyval.yymyString:=yyv[yysp-2].yymyString+'('+yyv[yysp-0].yymyString+'('+yyv[yysp-1].yymyString+'))';
       end;
   3 : begin
         yyval.yymyString:=yyv[yysp-1].yymyString+'('+yyv[yysp-0].yymyString+')';
       end;
   4 : begin
         yyval.yymyString:='π '+yyv[yysp-0].yymyString;
       end;
   5 : begin
         
         tableErr:=false;
         	yyval.yymyString:=yyv[yysp-0].yymyString;	
         	Table:=TStringList.Create;
         	AssignFile(f,'E:\Inst\db.txt');
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
         	    if Table[0] = yyv[yysp-0].yymyString 
         		  then break
         		  else Table.clear;
         	  end;
         CloseFile(f);
         	if Table.Count = 0 then tableErr:=true;
         
       end;
   6 : begin
         yyval.yymyString:='σ '+yyv[yysp-0].yymyString;
       end;
   7 : begin
         
         yyval.yymyString:=yyv[yysp-2].yymyString+','+yyv[yysp-0].yymyString;
         	Attributes.Add(yyv[yysp-0].yymyString);
         
       end;
   8 : begin
         
         	yyval.yymyString:=yyv[yysp-0].yymyString;
         	Attributes:=TStringList.Create;
         	Attributes.Add(yyv[yysp-0].yymyString);
         
       end;
   9 : begin
         yyval.yymyString:=yyv[yysp-2].yymyString+' '+'∨'+' '+yyv[yysp-0].yymyString;
       end;
  10 : begin
         yyval := yyv[yysp-0];
       end;
  11 : begin
         yyval.yymyString:=yyv[yysp-2].yymyString+' '+'∧'+' '+yyv[yysp-0].yymyString;
       end;
  12 : begin
         yyval := yyv[yysp-0];
       end;
  13 : begin
         
         	yyval.yymyString:=yyv[yysp-2].yymyString+' '+yyv[yysp-1].yymyString+' '+yyv[yysp-0].yymyString;
         	Attributes.Add(yyv[yysp-2].yymyString);
         	Attributes.Add(yyv[yysp-0].yymyString);
         
       end;
  14 : begin
         yyval.yymyString:='<';
       end;
  15 : begin
         yyval.yymyString:='>';
       end;
  16 : begin
         yyval.yymyString:='=';
       end;
  17 : begin
         yyval := yyv[yysp-0];
       end;
  18 : begin
         yyval := yyv[yysp-0];
       end;
  end;
end(*yyaction*);

(* parse table: *)

type YYARec = record
                sym, act : Integer;
              end;
     YYRRec = record
                len, sym : Integer;
              end;

const

yynacts   = 29;
yyngotos  = 17;
yynstates = 29;
yynrules  = 18;

yya : array [1..yynacts] of YYARec = (
{ 0: }
  ( sym: 258; act: 4 ),
{ 1: }
  ( sym: 0; act: 0 ),
{ 2: }
  ( sym: 259; act: 6 ),
{ 3: }
{ 4: }
  ( sym: 263; act: 8 ),
{ 5: }
  ( sym: 260; act: 10 ),
  ( sym: 0; act: -3 ),
{ 6: }
  ( sym: 263; act: 11 ),
{ 7: }
  ( sym: 44; act: 12 ),
  ( sym: 259; act: -4 ),
{ 8: }
{ 9: }
{ 10: }
  ( sym: 257; act: 17 ),
  ( sym: 263; act: 18 ),
{ 11: }
{ 12: }
  ( sym: 263; act: 19 ),
{ 13: }
  ( sym: 60; act: 21 ),
  ( sym: 61; act: 22 ),
  ( sym: 62; act: 23 ),
{ 14: }
{ 15: }
  ( sym: 262; act: 24 ),
  ( sym: 0; act: -10 ),
  ( sym: 261; act: -10 ),
{ 16: }
  ( sym: 261; act: 25 ),
  ( sym: 0; act: -6 ),
{ 17: }
{ 18: }
{ 19: }
{ 20: }
  ( sym: 257; act: 17 ),
  ( sym: 263; act: 18 ),
{ 21: }
{ 22: }
{ 23: }
{ 24: }
  ( sym: 257; act: 17 ),
  ( sym: 263; act: 18 ),
{ 25: }
  ( sym: 257; act: 17 ),
  ( sym: 263; act: 18 ),
{ 26: }
{ 27: }
{ 28: }
  ( sym: 262; act: 24 ),
  ( sym: 0; act: -9 ),
  ( sym: 261; act: -9 )
);

yyg : array [1..yyngotos] of YYARec = (
{ 0: }
  ( sym: -12; act: 1 ),
  ( sym: -3; act: 2 ),
  ( sym: -2; act: 3 ),
{ 1: }
{ 2: }
  ( sym: -4; act: 5 ),
{ 3: }
{ 4: }
  ( sym: -6; act: 7 ),
{ 5: }
  ( sym: -5; act: 9 ),
{ 6: }
{ 7: }
{ 8: }
{ 9: }
{ 10: }
  ( sym: -10; act: 13 ),
  ( sym: -9; act: 14 ),
  ( sym: -8; act: 15 ),
  ( sym: -7; act: 16 ),
{ 11: }
{ 12: }
{ 13: }
  ( sym: -11; act: 20 ),
{ 14: }
{ 15: }
{ 16: }
{ 17: }
{ 18: }
{ 19: }
{ 20: }
  ( sym: -10; act: 26 ),
{ 21: }
{ 22: }
{ 23: }
{ 24: }
  ( sym: -10; act: 13 ),
  ( sym: -9; act: 27 ),
{ 25: }
  ( sym: -10; act: 13 ),
  ( sym: -9; act: 14 ),
  ( sym: -8; act: 28 )
{ 26: }
{ 27: }
{ 28: }
);

yyd : array [0..yynstates-1] of Integer = (
{ 0: } 0,
{ 1: } 0,
{ 2: } 0,
{ 3: } -1,
{ 4: } 0,
{ 5: } 0,
{ 6: } 0,
{ 7: } 0,
{ 8: } -8,
{ 9: } -2,
{ 10: } 0,
{ 11: } -5,
{ 12: } 0,
{ 13: } 0,
{ 14: } -12,
{ 15: } 0,
{ 16: } 0,
{ 17: } -18,
{ 18: } -17,
{ 19: } -7,
{ 20: } 0,
{ 21: } -14,
{ 22: } -16,
{ 23: } -15,
{ 24: } 0,
{ 25: } 0,
{ 26: } -13,
{ 27: } -11,
{ 28: } 0
);

yyal : array [0..yynstates-1] of Integer = (
{ 0: } 1,
{ 1: } 2,
{ 2: } 3,
{ 3: } 4,
{ 4: } 4,
{ 5: } 5,
{ 6: } 7,
{ 7: } 8,
{ 8: } 10,
{ 9: } 10,
{ 10: } 10,
{ 11: } 12,
{ 12: } 12,
{ 13: } 13,
{ 14: } 16,
{ 15: } 16,
{ 16: } 19,
{ 17: } 21,
{ 18: } 21,
{ 19: } 21,
{ 20: } 21,
{ 21: } 23,
{ 22: } 23,
{ 23: } 23,
{ 24: } 23,
{ 25: } 25,
{ 26: } 27,
{ 27: } 27,
{ 28: } 27
);

yyah : array [0..yynstates-1] of Integer = (
{ 0: } 1,
{ 1: } 2,
{ 2: } 3,
{ 3: } 3,
{ 4: } 4,
{ 5: } 6,
{ 6: } 7,
{ 7: } 9,
{ 8: } 9,
{ 9: } 9,
{ 10: } 11,
{ 11: } 11,
{ 12: } 12,
{ 13: } 15,
{ 14: } 15,
{ 15: } 18,
{ 16: } 20,
{ 17: } 20,
{ 18: } 20,
{ 19: } 20,
{ 20: } 22,
{ 21: } 22,
{ 22: } 22,
{ 23: } 22,
{ 24: } 24,
{ 25: } 26,
{ 26: } 26,
{ 27: } 26,
{ 28: } 29
);

yygl : array [0..yynstates-1] of Integer = (
{ 0: } 1,
{ 1: } 4,
{ 2: } 4,
{ 3: } 5,
{ 4: } 5,
{ 5: } 6,
{ 6: } 7,
{ 7: } 7,
{ 8: } 7,
{ 9: } 7,
{ 10: } 7,
{ 11: } 11,
{ 12: } 11,
{ 13: } 11,
{ 14: } 12,
{ 15: } 12,
{ 16: } 12,
{ 17: } 12,
{ 18: } 12,
{ 19: } 12,
{ 20: } 12,
{ 21: } 13,
{ 22: } 13,
{ 23: } 13,
{ 24: } 13,
{ 25: } 15,
{ 26: } 18,
{ 27: } 18,
{ 28: } 18
);

yygh : array [0..yynstates-1] of Integer = (
{ 0: } 3,
{ 1: } 3,
{ 2: } 4,
{ 3: } 4,
{ 4: } 5,
{ 5: } 6,
{ 6: } 6,
{ 7: } 6,
{ 8: } 6,
{ 9: } 6,
{ 10: } 10,
{ 11: } 10,
{ 12: } 10,
{ 13: } 11,
{ 14: } 11,
{ 15: } 11,
{ 16: } 11,
{ 17: } 11,
{ 18: } 11,
{ 19: } 11,
{ 20: } 12,
{ 21: } 12,
{ 22: } 12,
{ 23: } 12,
{ 24: } 14,
{ 25: } 17,
{ 26: } 17,
{ 27: } 17,
{ 28: } 17
);

yyr : array [1..yynrules] of YYRRec = (
{ 1: } ( len: 1; sym: -12 ),
{ 2: } ( len: 3; sym: -2 ),
{ 3: } ( len: 2; sym: -2 ),
{ 4: } ( len: 2; sym: -3 ),
{ 5: } ( len: 2; sym: -4 ),
{ 6: } ( len: 2; sym: -5 ),
{ 7: } ( len: 3; sym: -6 ),
{ 8: } ( len: 1; sym: -6 ),
{ 9: } ( len: 3; sym: -7 ),
{ 10: } ( len: 1; sym: -7 ),
{ 11: } ( len: 3; sym: -8 ),
{ 12: } ( len: 1; sym: -8 ),
{ 13: } ( len: 3; sym: -9 ),
{ 14: } ( len: 1; sym: -11 ),
{ 15: } ( len: 1; sym: -11 ),
{ 16: } ( len: 1; sym: -11 ),
{ 17: } ( len: 1; sym: -10 ),
{ 18: } ( len: 1; sym: -10 )
);


const _error = 256; (* error token *)

function yyact(state, sym : Integer; var act : Integer) : Boolean;
  (* search action table *)
  var k : Integer;
  begin
    k := yyal[state];
    while (k<=yyah[state]) and (yya[k].sym<>sym) do inc(k);
    if k>yyah[state] then
      yyact := false
    else
      begin
        act := yya[k].act;
        yyact := true;
      end;
  end(*yyact*);

function yygoto(state, sym : Integer; var nstate : Integer) : Boolean;
  (* search goto table *)
  var k : Integer;
  begin
    k := yygl[state];
    while (k<=yygh[state]) and (yyg[k].sym<>sym) do inc(k);
    if k>yygh[state] then
      yygoto := false
    else
      begin
        nstate := yyg[k].act;
        yygoto := true;
      end;
  end(*yygoto*);

label parse, next, error, errlab, shift, reduce, accept, abort;

begin(*yyparse*)

  (* initialize: *)

  yystate := 0; yychar := -1; yynerrs := 0; yyerrflag := 0; yysp := 0;

{$ifdef yydebug}
  yydebug := true;
{$else}
  yydebug := true;
{$endif}

parse:

  (* push state and value: *)

  inc(yysp);
  if yysp>yymaxdepth then
    begin
      yyerror('yyparse stack overflow');
      goto abort;
    end;
  yys[yysp] := yystate; yyv[yysp] := yyval;

next:

  if (yyd[yystate]=0) and (yychar=-1) then
    (* get next symbol *)
    begin
      yychar := yylex; 
      yyDbgMemo.lines.add('������ ������ '+inttostr(yychar)); 
      if yychar<0 then yychar := 0;
    end;

  if yydebug then { writeln('state ', yystate, ', char ', yychar); }
//     yyDbgMemo.lines.add('state '+ IntToStr(yystate) + //', char ' + IntToStr(yychar));
     yyDbgMemo.lines.add('������� ��������� '+IntToStr(yystate));
 
  (* determine parse action: *)

  yyn := yyd[yystate];
  if yyn<>0 then goto reduce; (* simple state *)

  (* no default action; search parse table *)

  if not yyact(yystate, yychar, yyn) then goto error
  else if yyn>0 then                      goto shift
  else if yyn<0 then                      goto reduce
  else                                    goto accept;

error:

  (* error; start error recovery: *)

  if yyerrflag=0 then yyerror('syntax error');

errlab:

  if yyerrflag=0 then inc(yynerrs);     (* new error *)

  if yyerrflag<=2 then                  (* incomplete recovery; try again *)
    begin
      yyerrflag := 3;
      (* uncover a state with shift action on error token *)
      while (yysp>0) and not ( yyact(yys[yysp], _error, yyn) and
                               (yyn>0) ) do
        begin
          if yydebug then
            if yysp>1 then
               { writeln('error recovery pops state ', yys[yysp], ', uncovers ',
                      yys[yysp-1])}
               yyErrMemo.lines.add('error recovery pops state '+ IntToStr(yys[yysp])+
                                   ', uncovers ' + IntToStr(yys[yysp-1]))
            else
              { writeln('error recovery fails ... abort'); }
              yyErrMemo.lines.add('error recovery fails ... abort');
          dec(yysp);
        end;
      if yysp=0 then goto abort; (* parser has fallen from stack; abort *)
      yystate := yyn;            (* simulate shift on error *)
      goto parse;
    end
  else                                  (* no shift yet; discard symbol *)
    begin
      if yydebug then { writeln('error recovery discards char ', yychar); }
          yyErrMemo.lines.add('error recovery discards char '+ IntToStr(yychar));
      if yychar=0 then goto abort; (* end of input; abort *)
      yychar := -1; goto next;     (* clear lookahead char and try again *)
    end;

shift:

  (* go to new state, clear lookahead character: *)
  
  yystate := yyn; yychar := -1; yyval := yylval;
  yyDbgMemo.lines.add('shift '+inttostr(yystate));
  if yyerrflag>0 then dec(yyerrflag);

  goto parse;

reduce:

  (* execute action, pop rule from stack, and go to next state: *)

  if yydebug then { writeln('reduce ', -yyn); }
      yyDbgMemo.lines.add('reduce ' + IntToStr(-yyn));
  yyflag := yyfnone; yyaction(-yyn);
  dec(yysp, yyr[-yyn].len);
  if yygoto(yys[yysp], yyr[-yyn].sym, yyn) then yystate := yyn;

  (* handle action calls to yyaccept, yyabort and yyerror: *)

  case yyflag of
    yyfaccept : goto accept;
    yyfabort  : goto abort;
    yyferror  : goto errlab;
  end;

  goto parse;

accept:

  yyparse := 0; 
  yydbgmemo.lines.add('accept');
  exit;

abort:

  yyparse := 1; exit;

end(*yyparse*);
	

(*$I SELECT_L.pas*)

end.
