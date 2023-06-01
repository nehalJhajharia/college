
%{
#include <stdio.h>
int vowels = 0, consonants = 0;
%}
%%
[aeiou] vowels++;
[bcdfghjklmnpqrstvwxyz] consonants++;
%%
int main() {
yylex();
printf("vowel count = %d, consonant count = %d\n", vowels, consonants); 
}