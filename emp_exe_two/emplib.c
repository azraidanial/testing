#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "emplib.h"

int init_employee(EMPDATA **emp)
{
    if(emp == NULL)
    {
        printf("Invalid parameter\n");
        return 2;
    }

    *emp = malloc(sizeof(EMPDATA));
    if(*emp == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    return 0;
}

int fini_employee(EMPDATA *emp)
{
    if(emp == NULL)
    {
        printf("Invalid parameter\n");
        return 1;
    }
    free(emp);
    return 0;
}
