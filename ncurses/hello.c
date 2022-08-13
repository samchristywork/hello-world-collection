#include <curses.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

void signal_handler(int sig) {
  endwin();
  clear();
  refresh();
}

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

  struct sigaction act;
  bzero(&act, sizeof(struct sigaction));
  act.sa_handler = signal_handler;
  sigaction(SIGWINCH, &act, NULL);

  int c = 0;
  while (c != 'q') {

    color_set(1, NULL);
    move(3, 3);
    printw("Hello, World!");

    color_set(2, NULL);
    move(4, 3);
    printw("Key: %d  ", c);

    /*
     * Get window dimensions.
     */
    int width;
    int height;
    getmaxyx(w, height, width);

    /*
     * Print an "X" in the middle of the screen.
     */
    color_set(0, NULL);
    move(height / 2, width / 2);
    printw("X");

    /*
     * Draw a horizontal line.
     */
    move(0, 0);
    hline('-', width);

    /*
     * Refresh and get user input.
     */
    refresh();
    c = getch();
  }

  delwin(w);
  endwin();
  refresh();
}
