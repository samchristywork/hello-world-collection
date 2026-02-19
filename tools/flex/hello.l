%{
#include <stdio.h>
%}

%%
"Hello"     { printf("GREETING_WORD: %s\n", yytext); }
"World"     { printf("NOUN: %s\n", yytext); }
[,!]        { printf("PUNCTUATION: %s\n", yytext); }
[ \t\n]+    { /* skip whitespace */ }
.           { printf("UNKNOWN: %s\n", yytext); }
%%

int yywrap(void) { return 1; }

int main(void) {
  yylex();
  return 0;
}
