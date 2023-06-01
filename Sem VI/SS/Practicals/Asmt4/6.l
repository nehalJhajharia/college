%{ 
#include<stdio.h> 
char op = ' '; 
int a, b; 
void cal();
%}
%%
[0-9]+ {cal();}
"+" op='+';
"-" op='-';
"*" op='*';
"/" op='/';
%%
void cal() {
if( op == ' ' ) {
a = atoi(yytext);
} else {
b = atoi(yytext); 
switch(op) {
case '+':
printf("%d + %d = %d\n", a, b, a+b); break;
case '-':
printf("%d - %d = %d\n", a, b, a-b); break;
case '*':
printf("%d * %d = %d\n", a, b, a*b); break;
case '/':
printf("%d / %d = %d\n", a, b, a/b); break;
default:
printf("Invalid input.\n");
break;
}
op = ' ';
}
}
int main() {
yylex();
}