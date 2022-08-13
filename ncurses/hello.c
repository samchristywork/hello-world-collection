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

  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);

  int c = 0;
  while (c != 'q') {

    color_set(1, NULL);
    move(3, 3);
    printw("Hello, World!");

    color_set(2, NULL);
    move(4, 3);
    printw("Key: %d  ", c);

    refresh();
    c = getch();
  }

  delwin(w);
  endwin();
  refresh();
}
