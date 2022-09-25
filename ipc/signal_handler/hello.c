#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void sig_term_handler(int signum, siginfo_t *info, void *ptr) {
  puts("\nSignal handler triggered. Press ctrl-\\ to quit.\n");
}

int main() {
  struct sigaction act;
  bzero(&act, sizeof(struct sigaction));
  act.sa_sigaction = sig_term_handler;
  act.sa_flags = SA_SIGINFO;
  sigaction(SIGINT, &act, NULL);

  while(1) {
    usleep(1000*1000); /* Do nothing */
  }
}
