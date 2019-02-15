%{

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
void yyerror(char *s, ...);
void emit(char *s, ...);

%}

%union {
 int intval;
 double floatval;
 char *strval;
 int subtok;
}

 /* names and literal values */
%token <strval> NAME
%token <strval> STRING
%token <intval> INTNUM
%token <intval> BOOL
%token <floatval> APPROXNUM

 /* user @abc names */
%token <strval> USERVAR

 /* operators and precedence levels */
%right ASSIGN
%left OR
%left XOR
%left ANDOP
%nonassoc IN IS LIKE REGEXP
%left NOT '!'
%left BETWEEN
%left <subtok> COMPARISON /* = <> < > <= >= <=> */
%left '|'
%left '&'
%left <subtok> SHIFT /* << >> */
%left '+' '-'
%left '*' '/' '%' MOD
%left '^'
%nonassoc UMINUS

%token ADD
%token ALL
 ...
%token ESCAPED
%token <subtok> EXISTS /* NOT EXISTS or EXISTS */
 ...
 
 /* functions with special syntax */
%token FSUBSTRING
%token FTRIM
%token FDATE_ADD FDATE_SUB
%token FCOUNT