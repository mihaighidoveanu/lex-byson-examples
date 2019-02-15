

%{

#include "heading.h"
#include "tok.h"
int yyerror(char *s);


#include <stack>
#include <iostream>

/* globals to track current indentation */
unsigned int g_current_line_indent = 0;   /* indentation of the current line */
std::stack<size_t> g_indent_levels;
int g_is_fake_outdent_symbol = 0;

static const unsigned int TAB_WIDTH = 2;



#define YYSTYPE int


#define YY_USER_INIT { \
        g_indent_levels.push(0); \
        BEGIN(initial); \
    }

int yycolumn = 1;
void set_yycolumn(int val){

}
/*void set_yycolumn(int val) {
    yycolumn = val;
    yylloc.first_column = yycolumn;
    yylloc.last_column = yycolumn + yyleng - 1;
}

#define YY_USER_ACTION { \
    yylloc.first_line = yylloc.last_line = yylineno; \
    set_yycolumn(yycolumn); \
    yycolumn += yyleng; \
}*/

%}

%x initial
%x indent
%s normal

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
	/* Indentation tracking */	
	unsigned int indent_caller = normal;

 /* This helps to keep track of the column number.
  * Note that it won't work if you have a rule which includes a newline and is
  * longer than one character because in that case that rule will be favored
  * and this one here won't get called.
  * TL;DR: If you have a rule which includes \n and more, you need to reset
  *        yycolumn inside that rule!
  */
 /*<*>\n { yylineno--; REJECT; }*/

 /* Everything runs in the  mode and enters the <indent> mode
    when a newline symbol is encountered.
    There is no newline symbol before the first line, so we need to go
    into the <indent> mode by hand there.
 */
<initial>.  { indent_caller = normal; yyless(0); BEGIN(indent); }
<initial>\n { indent_caller = normal; yyless(0); BEGIN(indent); }

 /* The following are the rules that keep track of indentation. */
<indent>" "     { g_current_line_indent++; }
<indent>\t      { g_current_line_indent = (g_current_line_indent + TAB_WIDTH) & ~(TAB_WIDTH-1); }
<indent>\n      { g_current_line_indent = 0; /* ignoring blank line */ }
<indent><<EOF>> {
                    // When encountering the end of file, we want to emit an
                    // outdent for all indents currently left.
                    if(g_indent_levels.top() != 0) 
                    {
                        g_indent_levels.pop();

                        // See the same code below (<indent>.) for a rationale.
                        if(g_current_line_indent != g_indent_levels.top()) 
                        {
                            unput('\n');
                            for(size_t i = 0 ; i < g_indent_levels.top() ; ++i) 
                            {
                                unput(' ');
                           	}
                        } 
                        else 
                        {
                            BEGIN(indent_caller);
                        }

                        return DEDENT;
                    }
                    else 
                    {
                        yyterminate();
                    }
                }

<indent>.       {
                    if(!g_is_fake_outdent_symbol) 
                    {
                        unput(*yytext);
                    }
                    g_is_fake_outdent_symbol = 0;

                    // Indentation level has increased. It can only ever
                    // increase by one level at a time. Remember how many
                    // spaces this level has and emit an indentation token.
                    if(g_current_line_indent > g_indent_levels.top()) 
                    {
                        g_indent_levels.push(g_current_line_indent);
                        BEGIN(indent_caller);
                        return INDENT;
                    }
                    else 
                    	if(g_current_line_indent < g_indent_levels.top()) 
                    	{
	                        // Outdenting is the most difficult, as we might need to
	                        // outdent multiple times at once, but flex doesn't allow
	                        // emitting multiple tokens at once! So we fake this by
	                        // 'unput'ting fake lines which will give us the next
	                        // outdent.
	                        g_indent_levels.pop();

	                        if(g_current_line_indent != g_indent_levels.top()) 
	                        {
	                            // Unput the rest of the current line, including the newline.
	                            // We want to keep it untouched.
	                            for(size_t i = 0 ; i < g_current_line_indent ; ++i) 
	                            {
	                                unput(' ');
	                            }
	                            unput('\n');
	                            // Now, insert a fake character indented just so
	                            // that we get a correct outdent the next time.
	                            unput('.');
	                            // Though we need to remember that it's a fake one
	                            // so we can ignore the symbol.
	                            g_is_fake_outdent_symbol = 1;
	                            for(size_t i = 0 ; i < g_indent_levels.top() ; ++i) 
	                            {
	                                unput(' ');
	                            }
	                            unput('\n');
	                        } 
	                        else 
	                        {
	                            BEGIN(indent_caller);
	                        }

	                        return DEDENT;
       		            } 
       		            else 
	                    {
	                        // No change in indentation, not much to do here...
	                        BEGIN(indent_caller);
	                    }
                	}

{NEWLINE}    { g_current_line_indent = 0; indent_caller = YY_START; BEGIN(indent); return NEWLINE;}
{NAME} {return NEWLINE;}
{STRING} {return STRING;}
{NUMBER} {return NUMBER;}
{ASYNC} {return ASYNC;}
{AWAIT} {return AWAIT;}
{KEYWORD}|{OPERATOR}|{SEPARATOR} {cout<<"Found " << *yytext<<"\n";return *yytext;}


	/*(.|\n)  { std::cerr /*<< g_current_filename << ":" << yylineno << ":" << yycolumn << ": Unexpected character: " << yytext << std::endl; exit(1); }*/


.		{ std::cerr << "SCANNER "; yyerror((char*)""); exit(1);}

%%
