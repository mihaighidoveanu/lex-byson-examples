/* main.cc */

#include "heading.h"

// prototype of bison-generated parser function
int yyparse();

int main(int argc, char **argv)
{
  if ((argc > 1) && (freopen(argv[1], "r", stdin) == NULL))
  {
    cerr << argv[0] << ": File " << argv[1] << " cannot be opened.\n";
    exit( 1 );
  }
  
  yyparse();

  return 0;
}

/*
int main(int argc, char* argv[]) {
    yyin = stdin;
#if YYDEBUG
    yydebug = 1;
#endif
    if(argc == 2) {
        yyin = fopen(argv[1], "r");
        // g_current_filename = argv[1];
        if(!yyin) {
            perror(argv[1]);
            return 1;
        }
    }
    // parse through the input until there is no more:
    do {
        yyparse();
    } while (!feof(yyin));
    // Only in newer versions, apparently.
    // yylex_destroy();
}*/
