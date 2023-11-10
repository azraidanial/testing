#include <stdio.h>
#include <stdlib.h>
#include "testfuncex.h"

int main (int argc, char *argv[])
{
 int i;

 print_hello();

 for(i=0; i<120; i++)
 {
  printf("i = %d\n", i);
  sleep(1);
 }

 return 0;

}
