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
| words '\n' { printf("- %d\n", $1); }
| error '\n' { yyerrok; }
;

/*
 * One word by itself has the value of '1', otherwise just increment the counter.
 */
words:
  words WORD { $$ = $1 + 1; }
| WORD{ $$ = 1; }
;

%%

int yylex(void) {
  int c;

  /*
   * Consume all whitespace.
   */
  while ((c = getchar()) == ' ' || c == '\t') {
  }

  /*
   * Return the newline character on EOL.
   */
  if (c == '\n') {
    return c;
  }

  /*
   * Exit when the end of the input is reached.
   */
  if (c == EOF) {
    return 0;
  }

  /*
   * Consume one "string" worth of characters.
   */
  ungetc(c, stdin);
  char i[256];
  scanf("%s", i);
  printf("%s ", i);

  /*
   * If the control flow has reached here, then that means that the token that
   * was consumed was a word.
   */
  return WORD;
}

void yyerror(char const *s) { fprintf(stderr, "%s\n", s); }

int main(int argc, char const *argv[]) { return yyparse(); }
