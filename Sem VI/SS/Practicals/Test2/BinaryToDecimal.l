%{
#include "y.tab.h"
%}
int yylex(void);


%%
[01]    { yylval = yytext[0] - '0'; return DIGIT; }
\n     { return '\n'; }
.      { printf("Invalid character: %s\n", yytext); }
%%

int yywrap() {
    return 1;
}
