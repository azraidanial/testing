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

int set_employee_id(EMPDATA *emp, int id)
{
    if(emp == NULL)
    {
        printf("Invalid parameter\n");
        return 1;
    }

    emp->emp_id = id;
    return 0;
}

int set_employee_name(EMPDATA *emp, char *name)
{
    if(emp == NULL)
    {
        printf("Invalid parameter\n");
        return 1;
    }

    strcpy(emp->last_name, name);
    return 0;
}

int set_employee_salary(EMPDATA *emp, int salary)
{
    if(emp == NULL)
    {
        printf("Invalid parameter\n");
        return 1;
    }

    emp->salary = salary;
    return 0;
}

int get_employee_id(EMPDATA *emp, int *id)
{
    if(emp == NULL)
    {
        printf("Invalid parameter\n");
        return 1;
    }

    *id = emp->emp_id;
    return 0;
}

int get_employee_name(EMPDATA *emp, char *name)
{
    if(emp == NULL)
    {
        printf("Invalid parameter\n");
        return 1;
    }

    strcpy(name, emp->last_name);
    return 0;
}

int get_employee_salary(EMPDATA *emp, int *salary)
{
    if(emp == NULL)
    {
        printf("Invalid parameter\n");
        return 1;
    }

    *salary = emp->salary;
    return 0;
}
