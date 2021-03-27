D [0-9]
L [a-zA-Z]
%%
{D}+            begin
                  yylval.yymyString:=yytext;
				  returni(num);
				end;

"select"		begin
                  yylval.yymyString:=yytext;
				  returni(select_t);
				end;
"from"			begin
                  yylval.yymyString:=yytext;
				  returni(from_t);
				end;
"where"			begin
                  yylval.yymyString:=yytext;
				  returni(where_t);
				end;
"or"			begin
                  yylval.yymyString:=yytext;
				  returni(or_t);
				end;
"and"			begin
                  yylval.yymyString:=yytext;
				  returni(and_t);
				end;

{L}({L}|{D})*   begin
                  yylval.yymyString:=yytext;
				  returni(id);
				end;


\<		returnc('<');
\>		returnc('>');
\=		returnc('=');
\,		returnc(',');

" "    	;
%%
end. 