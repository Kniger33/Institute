 unit test;
 interface
 const num=257; dec=258; id=259; _var=260; _if=261; _then=262; _else=263; _begin=264; _end=265;        _and=266; _or=267; _round=268; lex_error=404;
 function yylex: Integer;
 implementation
 uses lexlib;
D [0-9]
L [a-zA-Z]
S ['.'',']
%%
"var"		returni(_var);
"if"		returni(_if);
"then"		returni(_then);
"else"		returni(_else);
"begin"		returni(_begin);
"end"		returni(_end);
"and"		returni(_and);
"or"		returni(_or);
"round"		returni(_round);

{D}+            returni(num);
({D}+{S}){D}+	returni(dec);
{L}({L}|{D})*   returni(id);

\+              returnc('+');
\-		returnc('-');
\*		returnc('*');
\/		returnc('/');
\<		returnc('<');
\>		returnc('>');
\=		returnc('=');
\;		returnc(';');
\:		returnc(':');
\(		returnc('(');
\)		returnc(')');
" "             ;
.               returni(lex_error);
%%
end. 