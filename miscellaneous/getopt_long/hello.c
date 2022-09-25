#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

void usage(char *argv[]) {
  fprintf(stderr,
          "Usage: %s [-f foo] [-b bar] [file(s)]\n"
          " -f,--foo      Some description goes here.\n"
          " -b,--bar      Another description.\n"
          " -h,--help     Print this usage message.\n"
          " -v,--verbose  Display additional logging information.\n"
          "",
          argv[0]);
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {

  int verbose = 0;

  int opt;
  int option_index = 0;
  char *optstring = "hps:v";
  static struct option long_options[] = {
      {"help", no_argument, 0, 'h'},
      {"print", no_argument, 0, 'p'},
      {"something", required_argument, 0, 's'},
      {"verbose", no_argument, 0, 'v'},
      {0, 0, 0, 0},
  };
  while ((opt = getopt_long(argc, argv, optstring, long_options, &option_index)) != -1) {
    if (opt == 'p') {
      printf("Hello, World!\n");
    } else if (opt == 'h') {
      usage(argv);
    } else if (opt == 'v') {
      verbose = 1;
    } else if (opt == '?') {
      usage(argv);
    } else {
      puts(optarg);
    }
  }

  if (optind < argc) {
    int i = optind;
    while (i < argc) {
      fprintf(stdout, "Got additional argument: %s\n", argv[i]);
      i++;
    }
  }
}
