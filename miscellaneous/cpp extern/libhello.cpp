#include <stdio.h>
#include <stdlib.h>

extern "C" {
   void hello();
}

void hello(){
  printf("Hello, World!\n");
}
