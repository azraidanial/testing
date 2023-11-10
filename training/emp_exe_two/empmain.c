#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "emplib.h"

int main(int argc, char *argv[])
{    
    int rc;
    EMPDATA *employee;

    rc = init_employee(&employee);
    if(rc != 0)
    {
       printf("init_employee() failed\n");
       rc = 1;
       goto  COMMON_EXIT;
    }

    employee->emp_id = 999;
    strcpy(employee->last_name, "Azrai");
    employee->salary = 100000;

    printf("\nEmployee ID: %d\n", employee->emp_id);
    printf("Employee Last Name: %s\n", employee->last_name);
    printf("Employee Salary: %d\n", employee->salary);

    fini_employee(employee);
    employee = NULL;

COMMON_EXIT:
    return 0;
}
