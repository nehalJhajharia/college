%{
#include <stdio.h>
#include <math.h>
%}


%token DIGIT

%%
input: /* empty */ | input line
line: binary '\n' { printf("%d\n", $1); }
binary: DIGIT { $$ = $1; }
      | binary DIGIT { $$ = 2 * $1 + $2; }
%%

int yyerror(char *s) {
    printf("Error: %s\n", s);
    return 0;
}

int main() {
    yyparse();
    return 0;
}
