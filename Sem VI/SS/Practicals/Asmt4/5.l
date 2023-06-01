%{ 
#include<stdio.h>
%}
%%
"+91"[0-9]+ {
    if(yyleng == 13) 
    printf("Is a valid phone number.\n");
    } 
[a-zA-Z0-9.]+\@[a-z]+[.][a-z.]+ {
    printf("Is a valid email address.\n");
} 
[a-zA-Z0-9.]+ printf("Not a valid phone number or email address.\n");
%%
int main() {
yylex();
}