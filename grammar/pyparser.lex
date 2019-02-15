

%{

#include "heading.h"
#include "tok.h"
int yyerror(char *s);


%}

 /* %option 8bit reentrant bison-bridge */
%option warn
%option nodefault
%option yylineno
%option noyywrap

 /*%option debug*/

	/* Ids */
int_const	{digit}+
system_defined_id __[_a-zA-Z0-9]+__
private_id __[_a-zA-Z0-9]*
id [_a-zA-Z][_a-zA-Z0-9]* 

NAME {system_defined_id}|{private_id}|{id}
	
	/* Numbers */
integer {decint}|{binint}|{octint}|{hexint}|{zero}
decint {digit_nonzero}((_?{digit})*|(0+(_?0)*))
binint 0[bb](_?{binarydigit})+
octint 0[oo](_?{octaldigit})+
hexint 0[xx](_?{hexdigit})+
digit_nonzero [1-9]
zero [0]*
digit [0-9]
binarydigit [0-1]
octaldigit [0-7]
hexdigit {digit}|[a-fa-f]

float {float_point}|{float_exp}
float_point ({digitpart}?{fraction})|{digitpart}"."
float_exp ({digitpart}|{float_point}){exp}
exp [ee][+-]{digitpart}
digitpart {digit}(_?{digit})*
fraction "."{digit}

bytes_literal {bytes_prefix}({shortstring}|{longstring})
bytes_prefix "b"|"b"|"br"|"br"|"br"|"br"|"rb"|"rb"|"rb"|"rb"

imaginary_number ({float}|{digitpart})[jj]

NUMBER {integer}|{float}|{bytes_literal}|{imaginary_number}

		/* Operators */ 
OPERATOR {operator0}|{operator1}
operator0 {arith_operator}|{bitwise_operator}|{comp_operator}|{assign_operator} 
operator1 {membership_operator}|{identity_operator}|{logical_operator}|{eq}|{dot}

arith_operator "+"|"-"|"*"|"/"|"%"|"**"|"//"|"++"|"--"|"@"	
bitwise_operator "|"|"&"|"~"|"^"|"<<"|">>"
comp_operator "<"|">"|"<="|">="|"=="|"!="
assign_operator "="|"+="|"-="|"*="|"/="|"%="|"**="|"//="|"@="
eq "="
dot "."
membership_operator in|not([ ]+)in
identity_operator is|not([ ]+)is
logical_operator not|or|and

	/* separators */
SEPARATOR ";"|":"|","|{open_curly}|{close_curly}|{open_square}|{close_square}|{open_paran}|{close_paran}|{underscore}
open_curly "{"
close_curly "}"
open_square "["
close_square "]"
open_paran "("
close_paran ")"
underscore "_"

	/*keywords */
KEYWORD {keyword0}|{keyword1}|{keyword2}
keyword0 false|class|finally|is|return|none|continue|for|lambda|try|true 
keyword1 def|from|nonlocal|while|and|del|global|not|with|as|elif 
keyword2 if|or|yield|assert|else|import|pass|break|except|in|raise

	/* Strings */
string_literal ({string_prefix}?){shortstring}
longstring_literal ({string_prefix}?){longstring}

string_prefix "r"|"u"|"r"|"u"|"f"|"f"|"fr"|"fr"|"fr"|"fr"|"rf"|"rf"|"rf"|"rf"
shortstring ('({shortstring_char}|{stringescape})*')|(\"({shortstring_char}|{stringescape})*\")
longstring ('''({longstring_char}|{stringescape})*''')|(\"\"\"({longstring_char}|{stringescape})*\"\"\") 
longstring_char [^\\\"]
shortstring_char [^\\\n'"]
stringescape \\(['"abfnrtv]|({octaldigit}{1,3})|(x({hexdigit}{2}))|(u(hexdigit{4}))|(u(hexdigit{8}))) 		
	
STRING {string_literal}|{longstring_literal}

	/* whitespaces */
NEWLINE [\r\n]

	/* Keywords */
ASYNC "async"
AWAIT "await"
%%

{NEWLINE}    { /*g_current_line_indent = 0; indent_caller = YY_START; BEGIN(indent);*/ return NEWLINE;}
{NAME} {return NEWLINE;}
{STRING} {return STRING;}
{NUMBER} {return NUMBER;}
{ASYNC} {return ASYNC;}
{AWAIT} {return AWAIT;}
{KEYWORD}|{OPERATOR}|{SEPARATOR} {cout<<"Found " << *yytext<<"\n";return *yytext;}


	/*(.|\n)  { std::cerr /*<< g_current_filename << ":" << yylineno << ":" << yycolumn << ": Unexpected character: " << yytext << std::endl; exit(1); }*/


.		{ return *yytext;}

%%
