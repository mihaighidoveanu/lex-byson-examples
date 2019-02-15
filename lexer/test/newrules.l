
COMMENT " "{10}
ID [_a-zA-Z][_a-zA-Z0-9]* 
%%
COMMENT 	printf("A comment : %s\n",yytext);
ID 			printf("An identifier: %s",yytext);
. /**/

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




              