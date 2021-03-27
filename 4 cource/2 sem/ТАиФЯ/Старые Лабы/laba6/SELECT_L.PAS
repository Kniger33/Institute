
(* lexical analyzer template (TP Lex V3.0), V1.0 3-2-91 AG *)

(* global definitions: *)

function yylex : Integer;

procedure yyaction ( yyruleno : Integer );
  (* local definitions: *)
begin
  (* actions: *)
  case yyruleno of
  1:
                begin
                  yylval.yymyString:=yytext;
				  returni(num);
				end;

  2:
        		begin
                  yylval.yymyString:=yytext;
				  returni(select_t);
				end;
  3:
      			begin
                  yylval.yymyString:=yytext;
				  returni(from_t);
				end;
  4:
       			begin
                  yylval.yymyString:=yytext;
				  returni(where_t);
				end;
  5:
    			begin
                  yylval.yymyString:=yytext;
				  returni(or_t);
				end;
  6:
     			begin
                  yylval.yymyString:=yytext;
				  returni(and_t);
				end;

  7:
                begin
                  yylval.yymyString:=yytext;
				  returni(id);
				end;


  8:
  		returnc('<');
  9:
  		returnc('>');
  10:
  		returnc('=');
  11:
  		returnc(',');

  12:
       	;
  end;
end(*yyaction*);

(* DFA table: *)

type YYTRec = record
                cc : set of Char;
                s  : Integer;
              end;

const

yynmarks   = 32;
yynmatches = 32;
yyntrans   = 61;
yynstates  = 29;

yyk : array [1..yynmarks] of Integer = (
  { 0: }
  { 1: }
  { 2: }
  1,
  { 3: }
  7,
  { 4: }
  7,
  { 5: }
  7,
  { 6: }
  7,
  { 7: }
  7,
  { 8: }
  7,
  { 9: }
  8,
  { 10: }
  9,
  { 11: }
  10,
  { 12: }
  11,
  { 13: }
  12,
  { 14: }
  7,
  { 15: }
  7,
  { 16: }
  7,
  { 17: }
  5,
  7,
  { 18: }
  7,
  { 19: }
  7,
  { 20: }
  7,
  { 21: }
  7,
  { 22: }
  6,
  7,
  { 23: }
  7,
  { 24: }
  3,
  7,
  { 25: }
  7,
  { 26: }
  7,
  { 27: }
  4,
  7,
  { 28: }
  2,
  7
);

yym : array [1..yynmatches] of Integer = (
{ 0: }
{ 1: }
{ 2: }
  1,
{ 3: }
  7,
{ 4: }
  7,
{ 5: }
  7,
{ 6: }
  7,
{ 7: }
  7,
{ 8: }
  7,
{ 9: }
  8,
{ 10: }
  9,
{ 11: }
  10,
{ 12: }
  11,
{ 13: }
  12,
{ 14: }
  7,
{ 15: }
  7,
{ 16: }
  7,
{ 17: }
  5,
  7,
{ 18: }
  7,
{ 19: }
  7,
{ 20: }
  7,
{ 21: }
  7,
{ 22: }
  6,
  7,
{ 23: }
  7,
{ 24: }
  3,
  7,
{ 25: }
  7,
{ 26: }
  7,
{ 27: }
  4,
  7,
{ 28: }
  2,
  7
);

yyt : array [1..yyntrans] of YYTrec = (
{ 0: }
  ( cc: [ ' ' ]; s: 13),
  ( cc: [ ',' ]; s: 12),
  ( cc: [ '0'..'9' ]; s: 2),
  ( cc: [ '<' ]; s: 9),
  ( cc: [ '=' ]; s: 11),
  ( cc: [ '>' ]; s: 10),
  ( cc: [ 'A'..'Z','b'..'e','g'..'n','p'..'r','t'..'v',
            'x'..'z' ]; s: 8),
  ( cc: [ 'a' ]; s: 7),
  ( cc: [ 'f' ]; s: 4),
  ( cc: [ 'o' ]; s: 6),
  ( cc: [ 's' ]; s: 3),
  ( cc: [ 'w' ]; s: 5),
{ 1: }
  ( cc: [ ' ' ]; s: 13),
  ( cc: [ ',' ]; s: 12),
  ( cc: [ '0'..'9' ]; s: 2),
  ( cc: [ '<' ]; s: 9),
  ( cc: [ '=' ]; s: 11),
  ( cc: [ '>' ]; s: 10),
  ( cc: [ 'A'..'Z','b'..'e','g'..'n','p'..'r','t'..'v',
            'x'..'z' ]; s: 8),
  ( cc: [ 'a' ]; s: 7),
  ( cc: [ 'f' ]; s: 4),
  ( cc: [ 'o' ]; s: 6),
  ( cc: [ 's' ]; s: 3),
  ( cc: [ 'w' ]; s: 5),
{ 2: }
  ( cc: [ '0'..'9' ]; s: 2),
{ 3: }
  ( cc: [ '0'..'9','A'..'Z','a'..'d','f'..'z' ]; s: 8),
  ( cc: [ 'e' ]; s: 14),
{ 4: }
  ( cc: [ '0'..'9','A'..'Z','a'..'q','s'..'z' ]; s: 8),
  ( cc: [ 'r' ]; s: 15),
{ 5: }
  ( cc: [ '0'..'9','A'..'Z','a'..'g','i'..'z' ]; s: 8),
  ( cc: [ 'h' ]; s: 16),
{ 6: }
  ( cc: [ '0'..'9','A'..'Z','a'..'q','s'..'z' ]; s: 8),
  ( cc: [ 'r' ]; s: 17),
{ 7: }
  ( cc: [ '0'..'9','A'..'Z','a'..'m','o'..'z' ]; s: 8),
  ( cc: [ 'n' ]; s: 18),
{ 8: }
  ( cc: [ '0'..'9','A'..'Z','a'..'z' ]; s: 8),
{ 9: }
{ 10: }
{ 11: }
{ 12: }
{ 13: }
{ 14: }
  ( cc: [ '0'..'9','A'..'Z','a'..'k','m'..'z' ]; s: 8),
  ( cc: [ 'l' ]; s: 19),
{ 15: }
  ( cc: [ '0'..'9','A'..'Z','a'..'n','p'..'z' ]; s: 8),
  ( cc: [ 'o' ]; s: 20),
{ 16: }
  ( cc: [ '0'..'9','A'..'Z','a'..'d','f'..'z' ]; s: 8),
  ( cc: [ 'e' ]; s: 21),
{ 17: }
  ( cc: [ '0'..'9','A'..'Z','a'..'z' ]; s: 8),
{ 18: }
  ( cc: [ '0'..'9','A'..'Z','a'..'c','e'..'z' ]; s: 8),
  ( cc: [ 'd' ]; s: 22),
{ 19: }
  ( cc: [ '0'..'9','A'..'Z','a'..'d','f'..'z' ]; s: 8),
  ( cc: [ 'e' ]; s: 23),
{ 20: }
  ( cc: [ '0'..'9','A'..'Z','a'..'l','n'..'z' ]; s: 8),
  ( cc: [ 'm' ]; s: 24),
{ 21: }
  ( cc: [ '0'..'9','A'..'Z','a'..'q','s'..'z' ]; s: 8),
  ( cc: [ 'r' ]; s: 25),
{ 22: }
  ( cc: [ '0'..'9','A'..'Z','a'..'z' ]; s: 8),
{ 23: }
  ( cc: [ '0'..'9','A'..'Z','a','b','d'..'z' ]; s: 8),
  ( cc: [ 'c' ]; s: 26),
{ 24: }
  ( cc: [ '0'..'9','A'..'Z','a'..'z' ]; s: 8),
{ 25: }
  ( cc: [ '0'..'9','A'..'Z','a'..'d','f'..'z' ]; s: 8),
  ( cc: [ 'e' ]; s: 27),
{ 26: }
  ( cc: [ '0'..'9','A'..'Z','a'..'s','u'..'z' ]; s: 8),
  ( cc: [ 't' ]; s: 28),
{ 27: }
  ( cc: [ '0'..'9','A'..'Z','a'..'z' ]; s: 8),
{ 28: }
  ( cc: [ '0'..'9','A'..'Z','a'..'z' ]; s: 8)
);

yykl : array [0..yynstates-1] of Integer = (
{ 0: } 1,
{ 1: } 1,
{ 2: } 1,
{ 3: } 2,
{ 4: } 3,
{ 5: } 4,
{ 6: } 5,
{ 7: } 6,
{ 8: } 7,
{ 9: } 8,
{ 10: } 9,
{ 11: } 10,
{ 12: } 11,
{ 13: } 12,
{ 14: } 13,
{ 15: } 14,
{ 16: } 15,
{ 17: } 16,
{ 18: } 18,
{ 19: } 19,
{ 20: } 20,
{ 21: } 21,
{ 22: } 22,
{ 23: } 24,
{ 24: } 25,
{ 25: } 27,
{ 26: } 28,
{ 27: } 29,
{ 28: } 31
);

yykh : array [0..yynstates-1] of Integer = (
{ 0: } 0,
{ 1: } 0,
{ 2: } 1,
{ 3: } 2,
{ 4: } 3,
{ 5: } 4,
{ 6: } 5,
{ 7: } 6,
{ 8: } 7,
{ 9: } 8,
{ 10: } 9,
{ 11: } 10,
{ 12: } 11,
{ 13: } 12,
{ 14: } 13,
{ 15: } 14,
{ 16: } 15,
{ 17: } 17,
{ 18: } 18,
{ 19: } 19,
{ 20: } 20,
{ 21: } 21,
{ 22: } 23,
{ 23: } 24,
{ 24: } 26,
{ 25: } 27,
{ 26: } 28,
{ 27: } 30,
{ 28: } 32
);

yyml : array [0..yynstates-1] of Integer = (
{ 0: } 1,
{ 1: } 1,
{ 2: } 1,
{ 3: } 2,
{ 4: } 3,
{ 5: } 4,
{ 6: } 5,
{ 7: } 6,
{ 8: } 7,
{ 9: } 8,
{ 10: } 9,
{ 11: } 10,
{ 12: } 11,
{ 13: } 12,
{ 14: } 13,
{ 15: } 14,
{ 16: } 15,
{ 17: } 16,
{ 18: } 18,
{ 19: } 19,
{ 20: } 20,
{ 21: } 21,
{ 22: } 22,
{ 23: } 24,
{ 24: } 25,
{ 25: } 27,
{ 26: } 28,
{ 27: } 29,
{ 28: } 31
);

yymh : array [0..yynstates-1] of Integer = (
{ 0: } 0,
{ 1: } 0,
{ 2: } 1,
{ 3: } 2,
{ 4: } 3,
{ 5: } 4,
{ 6: } 5,
{ 7: } 6,
{ 8: } 7,
{ 9: } 8,
{ 10: } 9,
{ 11: } 10,
{ 12: } 11,
{ 13: } 12,
{ 14: } 13,
{ 15: } 14,
{ 16: } 15,
{ 17: } 17,
{ 18: } 18,
{ 19: } 19,
{ 20: } 20,
{ 21: } 21,
{ 22: } 23,
{ 23: } 24,
{ 24: } 26,
{ 25: } 27,
{ 26: } 28,
{ 27: } 30,
{ 28: } 32
);

yytl : array [0..yynstates-1] of Integer = (
{ 0: } 1,
{ 1: } 13,
{ 2: } 25,
{ 3: } 26,
{ 4: } 28,
{ 5: } 30,
{ 6: } 32,
{ 7: } 34,
{ 8: } 36,
{ 9: } 37,
{ 10: } 37,
{ 11: } 37,
{ 12: } 37,
{ 13: } 37,
{ 14: } 37,
{ 15: } 39,
{ 16: } 41,
{ 17: } 43,
{ 18: } 44,
{ 19: } 46,
{ 20: } 48,
{ 21: } 50,
{ 22: } 52,
{ 23: } 53,
{ 24: } 55,
{ 25: } 56,
{ 26: } 58,
{ 27: } 60,
{ 28: } 61
);

yyth : array [0..yynstates-1] of Integer = (
{ 0: } 12,
{ 1: } 24,
{ 2: } 25,
{ 3: } 27,
{ 4: } 29,
{ 5: } 31,
{ 6: } 33,
{ 7: } 35,
{ 8: } 36,
{ 9: } 36,
{ 10: } 36,
{ 11: } 36,
{ 12: } 36,
{ 13: } 36,
{ 14: } 38,
{ 15: } 40,
{ 16: } 42,
{ 17: } 43,
{ 18: } 45,
{ 19: } 47,
{ 20: } 49,
{ 21: } 51,
{ 22: } 52,
{ 23: } 54,
{ 24: } 55,
{ 25: } 57,
{ 26: } 59,
{ 27: } 60,
{ 28: } 61
);


var yyn : Integer;

label start, scan, action;

begin

start:

  (* initialize: *)

  yynew;

scan:

  (* mark positions and matches: *)

  for yyn := yykl[yystate] to     yykh[yystate] do yymark(yyk[yyn]);
  for yyn := yymh[yystate] downto yyml[yystate] do yymatch(yym[yyn]);

  if yytl[yystate]>yyth[yystate] then goto action; (* dead state *)

  (* get next character: *)

  yyscan;

  (* determine action: *)

  yyn := yytl[yystate];
  while (yyn<=yyth[yystate]) and not (yyactchar in yyt[yyn].cc) do inc(yyn);
  if yyn>yyth[yystate] then goto action;
    (* no transition on yyactchar in this state *)

  (* switch to new state: *)

  yystate := yyt[yyn].s;

  goto scan;

action:

  (* execute action: *)

  if yyfind(yyrule) then
    begin
      yyaction(yyrule);
      if yyreject then goto action;
    end
  else if not yydefault and yywrap then
    begin
      yyclear;
      returni(0);
    end;

  if not yydone then goto start;

  yylex := yyretval;

end(*yylex*);


end. 
