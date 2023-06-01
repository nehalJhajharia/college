%{
#include <stdio.h>
void yyerror(char *);
int yylex(void);
%}

%token A B EOL

%%
input:
    line EOL input
    | line EOL
    ;

line:
    A B { printf("Valid string\n"); }
    ;

%%

void yyerror(char *s) {
    printf("%s\n", s);
}

int main(void) {
    yyparse();
    return 0;
}
