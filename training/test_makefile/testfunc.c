#include <stdio.h>
#include "testfuncex.h"

void print_hello(void)
{
 printf("Hello World\n");
 printf("Process ID: %d\n", getpid());
}
