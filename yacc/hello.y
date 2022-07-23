%{
#include <stdio.h>

#include "hello.h"

int yylex (void);
void yyerror (char const *);
%}

%define api.value.type union
%token WORD
%type <int> words

%%
input:
| input line
;

line:
  '\n' { printf("0\n"); }
| words '\n' { printf("%d\n", $1); }
| error '\n' { yyerrok; }
;

words:
  words WORD { $$ = $1 + 1; }
| WORD{ $$ = 1; }
;

%%

int yylex(void) {
  int c;

  while ((c = getchar()) == ' ' || c == '\t') {
  }

  if (c == '\n') {
    return c;
  }

  if (c == EOF) {
    return 0;
  }

  char i[256];
  scanf("%s", i);

  return WORD;
}

void yyerror(char const *s) { fprintf(stderr, "%s\n", s); }

int main(int argc, char const *argv[]) { return yyparse(); }
