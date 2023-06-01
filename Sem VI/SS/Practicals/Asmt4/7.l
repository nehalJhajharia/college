%{
#include <stdio.h>
int flag = 0;
%}
%%
" and "|" or "|" but " flag = 1; 
%%
int main() {
yylex();
if(flag == 1) {
printf("Compound sentence.\n"); 
} else {
printf("Simple sentence.\n");
}
}