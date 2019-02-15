%option yylineno
%{
	#include <stdio.h>
	#include <string.h>

%}

	/*Link to Python lexical analysis reference
	https://docs.python.org/3/reference/lexical_analysis.html
	*/

	/* Identifiers */
SYSTEM_DEFINED_ID __[_a-zA-Z0-9]+__
PRIVATE_ID __[_a-zA-Z0-9]*
ID [_a-zA-Z][_a-zA-Z0-9]* 
                                       
	/*Literals */	
	/* String */
STRING_LITERAL ({STRING_PREFIX}?){SHORTSTRING}
LONGSTRING_LITERAL ({STRING_PREFIX}?){LONGSTRING}

COMMENT ^([ ]{9}).{1,31}$
STRING_PREFIX "r"|"u"|"R"|"U"|"f"|"F"|"fr"|"Fr"|"fR"|"FR"|"rf"|"rF"|"Rf"|"RF"
SHORTSTRING ('({SHORTSTRING_CHAR}|{STRINGESCAPE})*')|(\"({SHORTSTRING_CHAR}|{STRINGESCAPE})*\")
LONGSTRING ('''({LONGSTRING_CHAR}|{STRINGESCAPE})*''')|(\"\"\"({LONGSTRING_CHAR}|{STRINGESCAPE})*\"\"\")
LONGSTRING_CHAR [^\\\"]
SHORTSTRING_CHAR [^\\\n'"]
STRINGESCAPE \\(['"abfnrtv]|({OCTALDIGIT}{1,3})|(x({HEXDIGIT}{2}))|(u(HEXDIGIT{4}))|(U(HEXDIGIT{8}))) 		


	/* Integers */ 
INTEGER {DECINT}|{BININT}|{OCTINT}|{HEXINT}|{ZERO}

DECINT {DIGIT_NONZERO}((_?{DIGIT})*|(0+(_?0)*))
BININT 0[bB](_?{BINARYDIGIT})+
OCTINT 0[oO](_?{OCTALDIGIT})+
HEXINT 0[xX](_?{HEXDIGIT})+
DIGIT_NONZERO [1-9]
ZERO [0]*
DIGIT [0-9]
BINARYDIGIT [0-1]
OCTALDIGIT [0-7]
HEXDIGIT {DIGIT}|[a-fA-F]

	/* Floats */
FLOAT {FLOAT_POINT}|{FLOAT_EXP}
FLOAT_POINT ({DIGITPART}?{FRACTION})|{DIGITPART}"."
FLOAT_EXP ({DIGITPART}|{FLOAT_POINT}){EXP}
EXP [eE][+-]{DIGITPART}
DIGITPART {DIGIT}(_?{DIGIT})*
FRACTION "."{DIGIT}

	/* Bytes */ 
BYTES_LITERAL {BYTES_PREFIX}({SHORTSTRING}|{LONGSTRING})
BYTES_PREFIX "b"|"B"|"br"|"Br"|"bR"|"BR"|"rb"|"rB"|"Rb"|"RB"

	/*Imaginary numbers */

IMAGINARY_NUMBER ({FLOAT}|{DIGITPART})[jJ]

	/* Format String */
F_STRING           ({LITERAL_CHAR}|"{{"|"}}"|{REPLACEMENT_FIELD})*
REPLACEMENT_FIELD   "{"{F_EXPRESSION}(!{CONVERSION})?(:{FORMAT_SPEC}?)"}"
F_EXPRESSION        ({CONDITIONAL_EXPRESSION})|(("*"OR_EXPR)((,{CONDITIONAL_EXPRESSION})|(,"*"{OR_EXPR}))*,?)|{YIELD_EXPRESSION}
CONVERSION          [sra]
FORMAT_SPEC         ({LITERAL_CHAR}|{REPLACEMENT_FIELD})*
LITERAL_CHAR        [^{}]
	
	/* Operators */ 
OPERATOR0 {ARITH_OPERATOR}|{BITWISE_OPERATOR}|{COMP_OPERATOR}|{ASSIGN_OPERATOR} 
OPEARTOR1 {MEMBERSHIP_OPERATOR}|{IDENTITY_OPERATOR}|{LOGICAL_OPERATOR}|{EQ}|{DOT}

ARITH_OPERATOR "+"|"-"|"*"|"/"|"%"|"**"|"//"|"++"|"--"|"@"	
BITWISE_OPERATOR "|"|"&"|"~"|"^"|"<<"|">>"
COMP_OPERATOR "<"|">"|"<="|">="|"=="|"!="
ASSIGN_OPERATOR "="|"+="|"-="|"*="|"/="|"%="|"**="|"//="|"@="
EQ "="
DOT "."
MEMBERSHIP_OPERATOR in|not([ ]+)in
IDENTITY_OPERATOR is|not([ ]+)is
LOGICAL_OPERATOR not|or|and

	/* Separators */
SEPARATOR ";"|":"|","|{OPEN_CURLY}|{CLOSE_CURLY}|{OPEN_SQUARE}|{ClOSE_SQUARE}|{OPEN_PARAN}|{CLOSE_PARAN}|{UNDERSCORE}
OPEN_CURLY "{"
CLOSE_CURLY "}"
OPEN_SQUARE "["
ClOSE_SQUARE "]"
OPEN_PARAN "("
CLOSE_PARAN ")"
UNDERSCORE "_"

	/*Keywords */
KEYWORD0 False|class|finally|is|return|None|continue|for|lambda|try|True 
KEYWORD1 def|from|nonlocal|while|and|del|global|not|with|as|elif 
KEYWORD2 if|or|yield|assert|else|import|pass|break|except|in|raise

%%
	/*Operators*/
{OPERATOR0}|{OPEARTOR1}  printf( "%d: An operator: %s\n", yylineno, yytext );
	/*Keywords*/
{KEYWORD0}|{KEYWORD1}|{KEYWORD2}	printf( "%d: A keyword: %s\n", yylineno, yytext );		
	/*Identifiers*/
{ID}|{SYSTEM_DEFINED_ID}|{PRIVATE_ID}	printf( "%d: An identifier: %s\n", yylineno, yytext );
	/*Literals*/
{INTEGER}	  		printf( "%d: An integer literal: %s\n", yylineno, yytext );
{FLOAT}	   			printf( "%d: A floating point literal: %s\n", yylineno, yytext );
{IMAGINARY_NUMBER} 	printf( "%d: An Imaginary number literal: %s\n", yylineno, yytext ); 
	/* String literals can be concatenated with space or tabs*/
	/*{F_STRING} printf("%d: A format string: %s\n",yylineno,yytext); format string don't work yet*/
{COMMENT} printf("%d: A comment !!!!!!!!: %s\n",yylineno,yytext);
{BYTES_LITERAL} printf( "%d : A byte literal: %s\n", yylineno, yytext);
({STRING_LITERAL}[ \t]*)+ printf("%d: A string literal: %s\n",yylineno,yytext);
{LONGSTRING_LITERAL} {

	int lineCount = 0;
	int lineSize = 0;
	char* line = NULL;
	char* lineBeginning = yytext;

	while((*yytext) != '\0')
	{
		++lineSize;

		if ((*yytext) == '\n')
		{	
			++lineCount;
			if(lineCount == 1)
			{
				//alloc or realloc the line
				if(!line)
				{
					line = malloc(sizeof(char) * (lineSize - 1));
				}
				else
				{
					line = realloc(line,sizeof(char) * (lineSize - 1));
				}

				// if allocation was succesfull, copy it from the string pointer
				if(!line)
				{
					printf("Eroare la preluarea liniei din string");
				}
				else
				{
					strncpy(line,lineBeginning,lineSize - 1);
					line[strlen(line)] = '\0';
				}

				//print to output the first line
				printf("A multiline string : From line %d: %s\n",yylineno,line);
			}

			// reinitialize the variables for next loop
			lineSize = 0;	
			lineBeginning = (++yytext);
		}	
		else
		{
			++yytext;
		}
	}
	if(!line)
	{
		line = malloc(sizeof(char) * (lineSize - 1));
	}
	else
	{
		line = realloc(line,sizeof(char) * (lineSize - 1));
	}

	// if allocation was succesfull, copy it from the string pointer
	if(!line)
	{
		printf("Eroare la preluarea liniei din string");
	}
	else
	{
		strncpy(line,lineBeginning,lineSize - 1);
	}
	printf(" ....... %s (line %d)\n",line,yylineno + lineCount); 
}

	/*Separators*/
{SEPARATOR}  printf( "%d: A separator: %s\n", yylineno, yytext );
	/*comment*/
"#".*[\n\r]?  /*one line comment  	*/
[ \t]+	/*printf("%d Whitespace \n",yylineno);*/
[\n\r]*	/*asdas*/
. printf( "%d: Unrecognized character: %s\n", yylineno, yytext );

%%
int main(int argc, char **argv )
{
	++argv, --argc;  /* skip over program name */
	
	if ( argc > 0 )
		yyin = fopen( argv[0], "r" );
	else
		yyin = stdin;
	
	yylex();
}
