 unit test;
 interface
 const num=257; dec=258; id=259; int_term=260; char_term=261; create_table_term = 262; null_term = 263; not_null_term = 264; pkey_term = 265; fkey_term = 266; references_term = 267;  
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

"int"			returni(int_term);
"char"			returni(char_term);

"create table"	returni(create_table_term);
"null"			returni(null_term);
"not null"		returni(not_null_term);
"primary key"	returni(pkey_term);
"foreign key"	returni(fkey_term);
"references"	returni(references_term);
{L}({L}|{D})*   returni(id);

\(				returnc('(');
\)				returnc(')');
\,				returnc(',');

" "     		;
.       		returni(lex_error);
%%
end. 