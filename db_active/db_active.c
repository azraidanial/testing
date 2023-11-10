#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adabasx.h"

int main (int argc, char *argv[])
{
 int rc;
 CB_PAR cb;

 if(argc < 2)
 {
  printf("Input are not Suffcient!\n");
  printf("Usage:\n");
  printf("    %s <dbid>\n", argv[0]);
  return 1;
 }

 memset(&cb, 0, sizeof(CB_PAR));

 cb.cb_db_id = atoi(argv[1]);
 cb.cb_cmd_code[0] = 'C';
 cb.cb_cmd_code[1] = 'L';

 rc = adabas(&cb, NULL, NULL, NULL, NULL, NULL);
 printf("Hello World!\n");
 printf("Adabas returns %d(rc = %d)\n", cb.cb_return_code, rc);

 return 0;
}
