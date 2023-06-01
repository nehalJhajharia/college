%{
#include <stdio.h>
int lineCount = 0, charCount = 0, wordCount = 0;
%}
%%
[^ \t\n]+ wordCount++; charCount += yyleng;
\n lineCount++; charCount++;
%%
int main() {
yylex();
printf("line count = %d, word count = %d and char count = %d\n",lineCount, wordCount, charCount);
}
