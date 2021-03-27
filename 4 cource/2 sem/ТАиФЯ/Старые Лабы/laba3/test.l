 unit test;
 interface
 const string_term=256; num=257; dec=258; id=259; var_term=260; if_term=261; then_term=262; else_term=263; begin_term=264; end_term=265; and_term=266; or_term=267; 
	   round_term=268; integer_term=269; real_term=270; stringtype_term=271; char_term=272; bool_term=273; type_term=274; boolop_term=275; div_term=276; mod_term=277; read_term=278; write_term=279; assigment_term=280;
	   lex_error=404;
 function yylex: Integer;
 implementation
 uses lexlib;
D [0-9]
L [a-zA-Z]
S ['.'',']
%%
"var"		returni(var_term);
"if"		returni(if_term);
"then"		returni(then_term);
"else"		returni(else_term);
"begin"		returni(begin_term);
"end"		returni(end_term);
"and"		returni(and_term);
"or"		returni(or_term);
"round"		returni(round_term);
"div"		returni(div_term);
"mod"		returni(mod_term);
"read"		returni(read_term);
"write"		returni(write_term);

"integer"	returni(type_term);
"real"		returni(type_term);
"string"	returni(type_term);
"char"		returni(type_term);
"boolean" 	returni(type_term);	

{D}+            returni(num);
({D}+{S}){D}+	returni(dec);
{L}({L}|{D})*   returni(id);
({L}|{D})+	returni(string_term);

\+      	returnc('+');
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
\.		returnc('.');
\,		returnc(',');

"<="	returni(boolop_term);	
">="	returni(boolop_term);	
"=<"	returni(boolop_term);	
"=>"	returni(boolop_term);	
"<>"	returni(boolop_term);	

" "     ;
.       returni(lex_error);
%%
end. 