/*
 * Scanner for mysql subset
 * $Header: /usr/home/johnl/flnb/RCS/ch04.tr,v 1.7 2009/05/19 18:28:27 johnl Exp $
 */

%option noyywrap nodefault yylineno case-insensitive

%{

#include "pmysql.tab.h"
#include <stdarg.h>
#include <string.h>
void yyerror(char *s, ...);
int oldstate;

%}

%x COMMENT
%s BTWMODE
%%

 /* keywords */
ADD { return ADD; }
ALL { return ALL; }
ALTER { return ALTER; }
ANALYZE { return ANALYZE; }
 /* Hack for BETWEEN ... AND ...
 * return special AND token if BETWEEN seen
 */
<BTWMODE>AND { BEGIN INITIAL; return AND; }
AND { return ANDOP; }
ANY { return ANY; }
AS { return AS; }
ASC { return ASC; }
AUTO_INCREMENT { return AUTO_INCREMENT; }
BEFORE { return BEFORE; }
BETWEEN { BEGIN BTWMODE; return BETWEEN; }
INT8|BIGINT { return BIGINT; }
BINARY { return BINARY; }
BIT { return BIT; }
BLOB { return BLOB; }
BOTH { return BOTH; }
BY { return BY; }
CALL { return CALL; }
CASCADE { return CASCADE; }
CASE { return CASE; }
CHANGE { return CHANGE; }
CHAR(ACTER)? { return CHAR; }
CHECK { return CHECK; }
COLLATE { return COLLATE; }
COLUMN { return COLUMN; }
COMMENT { return COMMENT; }
CONDITION { return CONDITION; }
CONSTRAINT { return CONSTRAINT; }
CONTINUE { return CONTINUE; }
CONVERT { return CONVERT; }
CREATE { return CREATE; }
86 | Chapter 4: Parsing SQL
Download at Boykma.Com
CROSS { return CROSS; }
CURRENT_DATE { return CURRENT_DATE; }
CURRENT_TIME { return CURRENT_TIME; }
CURRENT_TIMESTAMP { return CURRENT_TIMESTAMP; }
CURRENT_USER { return CURRENT_USER; }
CURSOR { return CURSOR; }
DATABASE { return DATABASE; }
DATABASES { return DATABASES; }
DATE { return DATE; }
DATETIME { return DATETIME; }
DAY_HOUR { return DAY_HOUR; }
DAY_MICROSECOND { return DAY_MICROSECOND; }
DAY_MINUTE { return DAY_MINUTE; }
DAY_SECOND { return DAY_SECOND; }
NUMERIC|DEC|DECIMAL { return DECIMAL; }
DECLARE { return DECLARE; }
DEFAULT { return DEFAULT; }
DELAYED { return DELAYED; }
DELETE { return DELETE; }
DESC { return DESC; }
DESCRIBE { return DESCRIBE; }
DETERMINISTIC { return DETERMINISTIC; }
DISTINCT { return DISTINCT; }
DISTINCTROW { return DIS
INFILE { return INFILE; }
INNER { return INNER; }
INOUT { return INOUT; }
INSENSITIVE { return INSENSITIVE; }
INSERT { return INSERT; }
INT4?|INTEGER { return INTEGER; }
INTERVAL { return INTERVAL; }
INTO { return INTO; }
IS { return IS; }
ITERATE { return ITERATE; }
JOIN { return JOIN; }
INDEX|KEY { return KEY; }
KEYS { return KEYS; }
KILL { return KILL; }
LEADING { return LEADING; }
LEAVE { return LEAVE; }
LEFT { return LEFT; }
LIKE { return LIKE; }
LIMIT { return LIMIT; }
LINES { return LINES; }
LOAD { return LOAD; }
LOCALTIME { return LOCALTIME; }
LOCALTIMESTAMP { return LOCALTIMESTAMP; }
LOCK { return LOCK; }
LONG { return LONG; }
LONGBLOB { return LONGBLOB; }
LONGTEXT { return LONGTEXT; }
LOOP { return LOOP; }
LOW_PRIORITY { return LOW_PRIORITY; }
MATCH { return MATCH; }
MEDIUMBLOB { return MEDIUMBLOB; }
MIDDLEINT|MEDIUMINT { return MEDIUMINT; }
MEDIUMTEXT { return MEDIUMTEXT; }
MINUTE_MICROSECOND { return MINUTE_MICROSECOND; }
MINUTE_SECOND { return MINUTE_SECOND; }
MOD { return MOD; }
MODIFIES { return MODIFIES; }
NATURAL { return NATURAL; }
NOT { return NOT; }
NO_WRITE_TO_BINLOG { return NO_WRITE_TO_BINLOG; }
NULL { return NULLX; }
NUMBER { return NUMBER; }
ON { return ON; }
ON[ \t\n]+DUPLICATE { return ONDUPLICATE; } /* hack due to limited lookahead */
OPTIMIZE { return OPTIMIZE; }
OPTION { return OPTION; }
OPTIONALLY { return OPTIONALLY; }
OR { return OR; }
ORDER { return ORDER; }
OUT { return OUT; }
OUTER { return OUTER; }
OUTFILE { return OUTFILE; }
PRECISION { return PRECISION; }
PRIMARY { return PRIMARY; }
PROCEDURE { return PROCEDURE; }
88 | Chapter 4: Parsing SQL
Download at Boykma.Com
PURGE { return PURGE; }
QUICK { return QUICK; }
READ { return READ; }
READS { return READS; }
REAL { return REAL; }
REFERENCES { return REFERENCES; }
REGEXP|RLIKE { return REGEXP; }
RELEASE { return RELEASE; }
RENAME { return RENAME; }
REPEAT { return REPEAT; }
REPLACE { return REPLACE; }
REQUIRE { return REQUIRE; }
RESTRICT { return RESTRICT; }
RETURN { return RETURN; }
REVOKE { return REVOKE; }
RIGHT { return RIGHT; }
ROLLUP { return ROLLUP; }
SCHEMA { return SCHEMA; }
SCHEMAS { return SCHEMAS; }
SECOND_MICROSECOND { return SECOND_MICROSECOND; }
SELECT { return SELECT; }
SENSITIVE { return SENSITIVE; }
SEPARATOR { return SEPARATOR; }
SET { return SET; }
SHOW { return SHOW; }
INT2|SMALLINT { return SMALLINT; }
SOME { return SOME; }
SONAME { return SONAME; }
SPATIAL { return SPATIAL; }
SPECIFIC { return SPECIFIC; }
SQL { return SQL; }
SQLEXCEPTION { return SQLEXCEPTION; }
SQLSTATE { return SQLSTATE; }
SQLWARNING { return SQLWARNING; }
SQL_BIG_RESULT { return SQL_BIG_RESULT; }
SQL_CALC_FOUND_ROWS { return SQL_CALC_FOUND_ROWS; }
SQL_SMALL_RESULT { return SQL_SMALL_RESULT; }
SSL { return SSL; }
STARTING { return STARTING; }
STRAIGHT_JOIN { return STRAIGHT_JOIN; }
TABLE { return TABLE; }
TEMPORARY { return TEMPORARY; }
TERMINATED { return TERMINATED; }
TEXT { return TEXT; }
THEN { return THEN; }
TIME { return TIME; }
TIMESTAMP { return TIMESTAMP; }
INT1|TINYINT { return TINYINT; }
TINYTEXT { return TINYTEXT; }
TO { return TO; }
TRAILING { return TRAILING; }
TRIGGER { return TRIGGER; }
UNDO { return UNDO; }
UNION { return UNION; }
UNIQUE { return UNIQUE; }
The Lexer | 89
Download at Boykma.Com
UNLOCK { return UNLOCK; }
UNSIGNED { return UNSIGNED; }
UPDATE { return UPDATE; }
USAGE { return USAGE; }
USE { return USE; }
USING { return USING; }
UTC_DATE { return UTC_DATE; }
UTC_TIME { return UTC_TIME; }
UTC_TIMESTAMP { return UTC_TIMESTAMP; }
VALUES? { return VALUES; }
VARBINARY { return VARBINARY; }
VARCHAR(ACTER)? { return VARCHAR; }
VARYING { return VARYING; }
WHEN { return WHEN; }
WHERE { return WHERE; }
WHILE { return WHILE; }
WITH { return WITH; }
WRITE { return WRITE; }
XOR { return XOR; }
YEAR { return YEAR; }
YEAR_MONTH { return YEAR_MONTH; }
ZEROFILL { return ZEROFILL; }

/* numbers */
-?[0-9]+ { yylval.intval = atoi(yytext); return INTNUM; }
-?[0-9]+"."[0-9]* |
-?"."[0-9]+ |
-?[0-9]+E[-+]?[0-9]+ |
-?[0-9]+"."[0-9]*E[-+]?[0-9]+ |
-?"."[0-9]+E[-+]?[0-9]+ { yylval.floatval = atof(yytext) ;
 return APPROXNUM; }

 /* booleans */
TRUE { yylval.intval = 1; return BOOL; }
UNKNOWN { yylval.intval = -1; return BOOL; }
FALSE { yylval.intval = 0; return BOOL; }


/* operators */
[-+&~|^/%*(),.;!] { return yytext[0]; }
"&&" { return ANDOP; }
"||" { return OR; }
"=" { yylval.subtok = 4; return COMPARISON; }
"<=>" { yylval.subtok = 12; return COMPARISON; }
">=" { yylval.subtok = 6; return COMPARISON; }
">" { yylval.subtok = 2; return COMPARISON; }
"<=" { yylval.subtok = 5; return COMPARISON; }
"<" { yylval.subtok = 1; return COMPARISON; }
"!=" |
"<>" { yylval.subtok = 3; return COMPARISON; }
"<<" { yylval.subtok = 1; return SHIFT; }
">>" { yylval.subtok = 2; return SHIFT; }
":=" { return ASSIGN; }

/* functions */
SUBSTR(ING)?/"(" { return FSUBSTRING; }
TRIM/"(" { return FTRIM; }
DATE_ADD/"(" { return FDATE_ADD; }
DATE_SUB/"(" { return FDATE_SUB; }

 /* check trailing context manually */
COUNT { int c = input(); unput(c);
 if(c == '(') return FCOUNT;
 yylval.strval = strdup(yytext);
 return NAME; }

 /* names */
[A-Za-z][A-Za-z0-9_]* { yylval.strval = strdup(yytext);
 return NAME; }
`[^`/\\.\n]+` { yylval.strval = strdup(yytext+1);
 yylval.strval[yyleng-2] = 0;
 return NAME; }
`[^`\n]*$ { yyerror("unterminated quoted name %s", yytext); }

 /* user variables */
@[0-9a-z_.$]+ |
@\"[^"\n]+\" |
@`[^`\n]+` |
@'[^'\n]+' { yylval.strval = strdup(yytext+1); return USERVAR; }
@\"[^"\n]*$ |
@`[^`\n]*$ |
@'[^'\n]*$ { yyerror("unterminated quoted user variable %s", yytext); }

 /* strings */
'(\\.|''|[^'\n])*' |
\"(\\.|\"\"|[^"\n])*\" { yylval.strval = strdup(yytext); return STRING; }
'(\\.|[^'\n])*$ { yyerror("Unterminated string %s", yytext); }
\"(\\.|[^"\n])*$ { yyerror("Unterminated string %s", yytext); }

 /* hex strings */
X'[0-9A-F]+' |
0X[0-9A-F]+ { yylval.strval = strdup(yytext); return STRING; }

 /* bit strings */
0B[01]+ |
B'[01]+' { yylval.strval = strdup(yytext); return STRING; }

 /* comments */
#.* ;
"--"[ \t].* ;
"/*" { oldstate = YY_START; BEGIN COMMENT; }
<COMMENT>"*/" { BEGIN oldstate; }
<COMMENT>.|\n ;
<COMMENT><<EOF>> { yyerror("unclosed comment"); }

 /* everything else */
[ \t\n] /* whitespace */
. { yyerror("mystery character '%c'", *yytext); }
%%

