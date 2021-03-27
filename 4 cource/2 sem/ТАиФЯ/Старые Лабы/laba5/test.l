 unit test;
 interface
 const num=257; dec=258; id=259; select_t=260; from_t=261; where_t=262; or_t=263; and_t=264;
       lex_error=404;
 function yylex: Integer;
 implementation
 uses lexlib;
D [0-9]
L [a-zA-Z]
S ['.'',']
%%
{D}+            returni(num);
({D}+{S}){D}+	returni(dec);

"select"	returni(select_t);
"from"		returni(from_t);
"where"		returni(where_t);
"or"		returni(or_t);
"and"		returni(and_t);
{L}({L}|{D})*   returni(id);


\<		returnc('<');
\>		returnc('>');
\=		returnc('=');
\,		returnc(',');

" "    		;
.      		returni(lex_error);
%%
end. 