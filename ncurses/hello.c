#include <curses.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

int main() {

  WINDOW *w;
  if ((w = initscr()) == NULL) {
    fprintf(stderr, "Error initializing ncurses.\n");
    exit(EXIT_FAILURE);
  }

  noecho();
  curs_set(0);
  keypad(w, TRUE);

  int c = 0;
  while (c != 'q') {

    move(3, 3);
    printw("Hello, World!");

    move(4, 3);
    printw("Key: %d  ", c);

    refresh();
    c = getch();
  }

  delwin(w);
  endwin();
  refresh();
}
