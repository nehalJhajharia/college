%{
#include "abn.tab.h"
%}

%%
a    { return A; }
b    { return B; }
\n   { return EOL; }
.    { yyerror("Invalid character"); }
%%

int yywrap() {
    return 1;
}
