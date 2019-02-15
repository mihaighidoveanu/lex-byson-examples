/* Mini Calculator */
/* calc.y */

%{
  /*Prologue section */
#include "heading.h"

// stuff from flex that bison needs to know about:
int yylex(void);
int yyerror(char *s);

extern "C" FILE *yyin;

#define YYSTYPE int
%}
  
  /*Bison declarations*/

%union{
  int		int_val;
  string*	op_val;
}

%start  file_input 

%token ASYNC
%token AWAIT
%token DEDENT
%token INDENT
%token NEWLINE
%token ENDMARKER
%token NAME
%token NUMBER
%token STRING

%left "**"
%nonassoc '~' 
%left '/' '%' "//"
%left '+' '-'
%left ">>" "<<"
%left '&'
%left '^' '|'
%left "<=" '>' '<' ">="
%left "<>" "==" "!="
%left '=' "%=" "/=" "//=" "-=" "+=" '=' "*="
%left "is" "is not"

  /*%left "**"
  %left '~' '+' '-' 
  %left '/' '%' "//"
  %left - 
  %left >> << 
  %left & 
  %left ^ | 
  %left <= < > >= 
  %left <> == != 
  %left = %= /= //= -= += = *= 
  %left is is not 
  %left in not in 
  %left not or and */

%%
  /*Grammar rules*/

/*# Grammar for Python

# NOTE WELL: You should also follow all the steps listed at
# https://devguide.python.org/grammar/

# Start symbols for the grammar:
#       single_input is a single interactive statement;
#       file_input is a module or sequence of commands read from an input file;
#       eval_input is the input for the eval() functions.
# NB: compound_stmt in single_input is followed by extra NEWLINE!*/

single_input: NEWLINE | simple_stmt | compound_stmt NEWLINE ;

file_content : NEWLINE 
  | stmt
  | file_content NEWLINE
  | file_content stmt
  ;
file_input: ENDMARKER 
  | file_content ENDMARKER
  ;


newlines_star: %empty
  | newlines_star NEWLINE  /*# NEWLINE**/
  ;
eval_input: testlist newlines_star ENDMARKER ;

decorator: '@' dotted_name NEWLINE
  | '@' dotted_name '(' ')' NEWLINE
  | '@' dotted_name '(' arglist ')' NEWLINE
  ;

decorators: decorator 
  | decorators decorator /*#decorator+*/
  ;

decorated: decorators classdef 
  | decorators funcdef 
  | decorators async_funcdef
  ;

async_funcdef: ASYNC funcdef ;
funcdef: "def" NAME parameters ':' suite 
  | "def" NAME parameters "->" test ':' suite
  ;
parameters: '(' ')'
  | '(' typedargslist ')'
  ;
/*
# typedargslist: (tfpdef ['=' test] (',' tfpdef ['=' test])* [',' [
#         '*' [tfpdef] (',' tfpdef ['=' test])* [',' ["**" tfpdef [',']]]
#       | "**" tfpdef [',']]]
#   | '*' [tfpdef] (',' tfpdef ['=' test])* [',' ["**" tfpdef [',']]]
#   | "**" tfpdef [','])
*/
typedargslist: typedarg
  | typedarg ','
  | typedargslist ',' typedarg
  ;
typedarg: tfpdef
  | tfpdef '=' test
  ;
tfpdef: NAME 
  | NAME ':' test
  ;
/*
# varargslist: (vfpdef ['=' test] (',' vfpdef ['=' test])* [',' [
#         '*' [vfpdef] (',' vfpdef ['=' test])* [',' ["**" vfpdef [',']]]
#       | "**" vfpdef [',']]]
#   | '*' [vfpdef] (',' vfpdef ['=' test])* [',' ["**" vfpdef [',']]]
#   | "**" vfpdef [',']
# )*/
varargslist: vararg
  | vararg ','
  | varargslist ',' vararg
  ;
vararg: vfpdef
  | vfpdef '=' test
  ;
vfpdef: NAME ;

stmt: simple_stmt | compound_stmt ;

small_stmts_star: %empty
  | small_stmts_star ';' small_stmt
  ;
simple_stmt: small_stmt small_stmts_star NEWLINE
  | small_stmt small_stmts_star ';' NEWLINE
  ;

small_stmt: expr_stmt | del_stmt | pass_stmt | flow_stmt |
             import_stmt | global_stmt | nonlocal_stmt | assert_stmt ;
expr_aux: '=' yield_expr
  | '=' testlist_star_expr
  ;
expr_aux_star: %empty
  | expr_aux_star expr_aux
  ;
expr_stmt:  testlist_star_expr annassign
  | testlist_star_expr augassign yield_expr
  | testlist_star_expr augassign testlist
  | testlist_star_expr expr_aux_star
  ;
annassign: ':' test 
  | ':' test '=' test
  ;
testlist_star_expr: test 
  | star_expr
  | testlist_star_expr ',' test
  | testlist_star_expr ',' star_expr
  | testlist_star_expr ','
  ;
augassign: "+="
  | "-="
  | "*="
  | "@="
  | "/="
  | "%="
  | "&="
  | "|="
  | "^=" 
  | "<<="
  | ">>=" 
  | "**="
  | "//="
  ;

/*# For normal and annotated assignments, additional restrictions enforced by the interpreter*/
del_stmt: "del" exprlist ;
pass_stmt: "pass" ;
flow_stmt: break_stmt | continue_stmt | return_stmt | raise_stmt | yield_stmt ;
break_stmt: "break" ;
continue_stmt: "continue" ;
return_stmt: "return" 
  | "return" testlist
  ;
yield_stmt: yield_expr ;
raise_stmt: "raise" 
  | "raise" test 
  | "raise" test "from" test
  ;
import_stmt: import_name | import_from ;
import_name: "import" dotted_as_names ;

/*# note below: the ('.' | "...") is necessary because "..." is tokenized as ELLIPSIS*/
import_points_plus: '.' 
  | "..."
  | import_points_plus '.'
  | import_points_plus "..."
  ;
import_points_star: %empty
  | import_points_star  '.'
  | import_points_star  "..."
  ;
import_from: "from" import_points_star dotted_name "import" '*'
  | "from" import_points_star dotted_name  "import" '(' import_as_names ')'
  | "from" import_points_star dotted_name "import" import_as_names
  | "from" import_points_plus "import" '*'
  | "from" import_points_plus  "import" '(' import_as_names ')'
  | "from" import_points_plus "import" import_as_names
  ;
import_as_name: NAME
  | NAME "as" NAME
  ;
dotted_as_name: dotted_name 
  | dotted_name "as" NAME
  ;
import_as_names: import_as_name ','
  | import_as_names ',' import_as_name
  | import_as_names ',' import_as_name ','
  ;
dotted_as_names: dotted_as_name
  | dotted_as_names ',' dotted_as_name
  ;
dotted_name: NAME
  |  dotted_name '.' NAME
  ;
global_stmt: "global" NAME
  | global_stmt ',' NAME  
  ;
nonlocal_stmt: "nonlocal" NAME 
  | nonlocal_stmt ',' NAME
  ;
assert_stmt: "assert" test
  | "assert" test ',' test
  ;

compound_stmt: if_stmt | while_stmt | for_stmt | try_stmt | with_stmt | funcdef | classdef | decorated | async_stmt ;
async_stmt: ASYNC funcdef
  | ASYNC with_stmt
  | ASYNC for_stmt
  ;
if_stmt: "if" test ':' suite 
  | "if" test ':' suite 
  ;
while_stmt: "while" test ':' suite 
  | "while" test ':' suite "else" ':' suite
  ;
for_stmt: "for" exprlist "in" testlist ':' suite 
  | "for" exprlist "in" testlist ':' suite "else" ':' suite
  ;
except_clause_plus: except_clause ':' suite
  | except_clause_plus except_clause ':' suite
  ;
try_stmt:  "try" ':' suite except_clause_plus
  | "try" ':' suite except_clause_plus "else" ':' suite 
  | "try" ':' suite except_clause_plus "finally" ':' suite 
  | "try" ':' suite except_clause_plus "else" ':' suite "finally" ':' suite 
  | "try" ':' suite "finally" ':' suite
  ;
with_item_star: %empty
  | with_item_star ',' with_item
  ;
with_stmt: "with" with_item with_item_star ':' suite ;
with_item: test 
  | test "as" expr
  ;

/*# NB compile.c makes sure that the default except clause is last*/
except_clause: "except" 
  | "except" test 
  | "except" test "as" NAME
  ;
stmt_plus: stmt
  | stmt_plus stmt 
  ;
suite: simple_stmt | NEWLINE INDENT stmt_plus DEDENT;

test: or_test
  | or_test "if" or_test "else" test
  | lambdef
  ;
test_nocond: or_test | lambdef_nocond ;
lambdef: "lambda" ':' test
  | "lambda" varargslist ':' test
  ;
lambdef_nocond: "lambda" ':' test_nocond
  | "lambda" varargslist ':' test_nocond
  ;
or_test: and_test 
  | or_test "or" and_test 
  ;
and_test: not_test 
  | and_test "and" not_test
  ;
not_test: "not" not_test | comparison ;
comparison: expr 
  | comparison comp_op expr
  ;
/*# <> isn't actually a valid comparison operator in Python. It's here for the
# sake of a __future__ import described in PEP 401 (which really works :-)*/

comp_op: '<'|'>'|"=="|">="|"<="|"<>"|"!="|"in"|"not" "in"|"is"|"is" "not";
star_expr: '*' expr;
expr: xor_expr 
  | expr '|' xor_expr
  ;
xor_expr: and_expr 
  | xor_expr '^' and_expr
  ;
and_expr: shift_expr 
  | and_expr '&' shift_expr
  ;
shift_expr: arith_expr 
  | shift_expr "<<" arith_expr
  | shift_expr ">>" arith_expr
  ;
arith_expr: term 
  | arith_expr '+' term
  | arith_expr '-' term
  ;
term: factor 
  | term '*' factor
  | term '@' factor
  | term '/' factor
  | term '%' factor
  | term "//" factor
  ;
factor:  '+' factor
  | '-' factor
  | '~' factor
  | power
  ;
power: atom_expr
  | atom_expr "**" factor
  ;
atom_expr: AWAIT atom 
  | atom
  | atom_expr trailer
  ;
string_plus : STRING
  | string_plus STRING
  ;
atom: '(' ')'
  | '(' yield_expr ')' 
  | '(' testlist_comp ')'
  | '[' ']' 
  | '[' testlist_comp ']'
  | '{' '}'
  | '{' dictorsetmaker '}'
  | NAME | NUMBER | string_plus 
  | "..." | "None" | "True" | "False"
  ;
testlist_comp_aux: ',' test
  | ',' star_expr
  | testlist_comp ',' test 
  | testlist_comp ',' star_expr
  ;
testlist_comp: test comp_for 
  | test testlist_comp_aux ','
  | test testlist_comp_aux 
  | star_expr comp_for
  | star_expr testlist_comp_aux ','
  | star_expr testlist_comp_aux 
  ;
trailer: '(' ')' 
  | '(' arglist ')' 
  | '[' subscriptlist ']' 
  | '.' NAME
  ;

subscript_star: %empty
  | subscript_star ',' subscript
  ;
subscriptlist: subscript subscript_star 
  | subscript subscript_star ','
  ;
subscript: test 
  | test ':' 
  | test ':' test 
  | test ':' test sliceop
  | ':' test 
  | ':' test sliceop
  | sliceop
  ;

sliceop: ':'
  | ':' test
  ;
exprlist_aux: expr
  | star_expr
  | exprlist_aux ',' expr
  | exprlist_aux ',' star_expr
  ;
exprlist: exprlist_aux 
  | exprlist_aux ','
  ;
testlist_aux: test
  | testlist_aux ',' test
  ;
testlist: testlist_aux ','
  | testlist_aux
  ;
dictorsetmaker_aux: ',' test ':' test
  | ','  "**" expr 
  | dictorsetmaker_aux ',' test ':' test
  | dictorsetmaker_aux ',' "**" expr
  ;
dictorsetmaker_aux2: ',' test 
  | ',' star_expr
  | dictorsetmaker_aux2 ',' test
  | dictorsetmaker_aux2 ',' star_expr
  ;
dictorsetmaker:  test ':' test comp_for
  | test ':' test dictorsetmaker_aux
  | test ':' test dictorsetmaker_aux ','
  | "**" expr comp_for
  | "**" expr dictorsetmaker_aux
  | "**" expr dictorsetmaker_aux ','
  | test comp_for
  | star_expr comp_for
  | test dictorsetmaker_aux2 ','
  | test dictorsetmaker_aux2 
  | star_expr dictorsetmaker_aux2 ','
  | star_expr dictorsetmaker_aux2
  ;

classdef: "class" NAME ':' suite
  | "class" NAME '(' ')' ':' suite 
  | "class" NAME '(' arglist ')' ':' suite 
  ;

arglist_aux: argument
  | arglist_aux ',' argument
  ;
arglist: arglist_aux ','
  | arglist_aux
  ;

/*
# The reason that keywords are test nodes instead of NAME is that using NAME
# results in an ambiguity. ast.c makes sure it's a NAME.
# "test '=' test" is really "keyword '=' test", but we have no such token.
# These need to be in a single rule to avoid grammar that is ambiguous
# to our LL(1) parser. Even though 'test' includes '*expr' in star_expr,
# we explicitly match '*' here, too, to give it proper precedence.
# Illegal combinations and orderings are blocked in ast.c:
# multiple (test comp_for) arguments are blocked; keyword unpackings
# that precede iterable unpackings are blocked; etc. */
argument:  test 
  | test comp_for
  | test '=' test 
  | "**" test 
  | '*' test 
  ;

comp_iter: comp_for 
  | comp_if
  ;
comp_for: "for" exprlist "in" or_test
  | ASYNC "for" exprlist "in" or_test
  | "for" exprlist "in" or_test comp_iter
  | ASYNC "for" exprlist "in" or_test comp_iter
  ;
comp_if: "if" test_nocond 
  | "if" test_nocond comp_iter
  ;

/*# not used in grammar, but may appear in "node" passed from Parser to Compiler*/
encoding_decl: NAME ;

yield_expr: "yield"
  | "yield" yield_arg
  ;

yield_arg: "from" test 
  | testlist
  ;




%%
  /*Epilogue */

int yyerror(string s)
{
  extern int yylineno;	// defined and maintained in lex.c
  extern char *yytext;	// defined and maintained in lex.c
  
  cerr << "ERROR: " << s << " at symbol \"" << yytext;
  cerr << "\" on line " << yylineno << endl;
  exit(1);
}

int yyerror(char *s)
{
  return yyerror(string(s));
}


