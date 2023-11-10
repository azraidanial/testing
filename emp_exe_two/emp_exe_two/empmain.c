#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "emplib.h"

int main(int argc, char *argv[])
{    
    int rc;
    EMPDATA *employee;
    int local_id;
    int local_salary;
    char local_name[LAST_NAME_SIZE];

    rc = init_employee(&employee);
    if(rc != 0)
    {
       printf("init_employee() failed\n");
       rc = 1;
       goto  COMMON_EXIT;
    }

    set_employee_id(employee, 999);
    set_employee_name(employee, "Azrai");
    set_employee_salary(employee, 10000);

    get_employee_id(employee, &local_id);
    get_employee_name(employee, &local_name[0]);
    get_employee_salary(employee, &local_salary);

    printf("\nEmployee ID: %d\n", local_id);
    printf("Employee Last Name: %s\n", &local_name[0]);
    printf("Employee Salary: %d\n", local_salary);

    fini_employee(employee);
    employee = NULL;

COMMON_EXIT:
    return 0;
}
