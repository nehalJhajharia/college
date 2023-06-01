%{
#include <stdio.h>
int pos_count = 0;
int neg_count = 0;
int nat_count = 0;
%}

%%
[+-]?[0-9]+ {
    int num = atoi(yytext);
    if(num > 0) {
        pos_count++;
    } else if(num < 0) {
        neg_count++;
    } else {
        nat_count++;
    }
}
. ;

%%

int yywrap() {
    return 1;
}


int main(void) {
    yylex();
    printf("Positive numbers: %d\n", pos_count);
    printf("Negative numbers: %d\n", neg_count);
    printf("Natural numbers: %d\n", nat_count);
    return 0;
}
