%{
#include <stdio.h>
int posInt = 0, negInt = 0, posFrac = 0, negFrac = 0;
%}
%%
[0-9]+ posInt++;
[-][0-9]+ negInt++;
[0-9]*\.[0-9]* posFrac++;
[-][0-9]*\.[0-9]* negFrac++;
%%
int main() {
yylex();
printf("Positive integers count = %d, Negative integers count = %d\n Positive fractions count = %d, Negative fractions count = %d\n", posInt, negInt, posFrac, negFrac);
}