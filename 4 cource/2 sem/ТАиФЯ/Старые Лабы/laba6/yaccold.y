%{ unit yacc;
interface
uses lexlib, yacclib, dialogs;
%}

%left '+' '-'
%left '*' '/'

%token <real> num

%type <real> expr

%%

goal : expr {showmessage(floattostr($1));}
expr : expr '+' expr {$$:=$1+$3;}
	 | expr '-' expr {$$:=$1-$3;}
	 | expr '*' expr {$$:=$1*$3;}
	 | expr '/' expr {$$:=$1/$3;}
	 | '(' expr ')' {$$:=$2;}
	 | num
	 
%%	 

(*$I test.pas*)
end.