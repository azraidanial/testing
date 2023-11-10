#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adabasx.h"

#define RECORD_BUFFER_SIZE (256)

int main(int argc, const char **argv) {
    int dbid;    
    int return_value;
    int from_isn;
    int to_isn;
    int i;
    int rc = 0;
    ACBX cbx;
    char fb[] = "AC,AE.";
    char rb[RECORD_BUFFER_SIZE];

    ABD  *abd_array[2];
    ABD  fbabd;
    ABD  rbabd;

    if (argc < 4) {
      printf("Input are not sufficient!\n");
      printf("Usage:\n");
      printf("    %s <dbid> <from_isn> <to_isn>\n", argv[0]);
      rc = 1;
	    goto COMMON_EXIT;
    }

    dbid = atoi(argv[1]);
    from_isn = atoi(argv[2]);
    to_isn = atoi(argv[3]);

    // OPEN COMMAND
    SETACBX(&cbx);
    cbx.acbxdbid = dbid;
    cbx.acbxcmd[0] = 'O';
    cbx.acbxcmd[1] = 'P';

    return_value = adabasx(&cbx, 0, (ABD **) NULL);
    printf("Adabas OP return %d, returned %d\n", cbx.acbxrsp, return_value);
    printf("ADD2: %s\n", cbx.acbxadd2);
    printf("ERRRC: %d\n", cbx.acbxerrc); 

    // L1 COMMAND
    memset(rb, 0, sizeof(rb));

    SETACBX(&cbx);
    cbx.acbxdbid = dbid;
    cbx.acbxfnr = 11;
    cbx.acbxcmd[0] = 'L';
    cbx.acbxcmd[1] = '1';

    SETABD(&fbabd);
    fbabd.abdid     = ABDQFB;
    fbabd.abdloc    = ABDQIND;
    fbabd.abdsize   = strlen(fb);
    fbabd.abdsend   = strlen(fb);
    fbabd.abdaddr   = &fb;

    SETABD(&rbabd);
    rbabd.abdid     = ABDQRB;
    rbabd.abdloc    = ABDQIND;
    rbabd.abdsize   = RECORD_BUFFER_SIZE;
    rbabd.abdsend   = RECORD_BUFFER_SIZE;
    rbabd.abdaddr   = &rb;

    abd_array [0] = &rbabd;
    abd_array [1] = &fbabd;

    for(i = from_isn; i <= to_isn; i++)
    {
      cbx.acbxisn = i;
      return_value = adabasx(&cbx, 2, abd_array);
      if(cbx.acbxrsp != 0)
      {
        printf("Adabas L1 return %d, returned %d\n", cbx.acbxrsp, return_value);
        printf("ADD2: %c %c %c %c\n", cbx.acbxadd2[0], cbx.acbxadd2[1], cbx.acbxadd2[2], cbx.acbxadd2[3]);
        printf("ERRRC: %d\n", cbx.acbxerrc);
        rc = 2;
        goto CLOSE_EXIT;
      }
      else{
        printf("Value read (ISN:%d): %s\n", i, rb);
      }

    }


CLOSE_EXIT:
    // CLOSE COMMAND
    SETACBX(&cbx);
    cbx.acbxdbid = dbid;
    cbx.acbxcmd[0] = 'C';
    cbx.acbxcmd[1] = 'L';

    return_value = adabasx(&cbx, 0, (ABD **) NULL);
    printf("Adabas CL return %d, returned %d\n", cbx.acbxrsp, return_value);
    printf("ADD2: %s\n", cbx.acbxadd2);
    printf("ERRRC: %d\n", cbx.acbxerrc);
    rc = 0;

COMMON_EXIT:
    return rc;
}
