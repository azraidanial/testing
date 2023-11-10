#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LAST_NAME_SIZE (32)

typedef struct empdata
{
    int emp_id;
    int salary;
    char last_name[LAST_NAME_SIZE];
}EMPDATA;

int init_employee(EMPDATA **);
int fini_employee(EMPDATA *);

int main(int argc, char *argv[])
{    
    int rc;
    EMPDATA *employee;
    EMPDATA employee2;

    if(argc < 4)
    {
        printf("Insufficient input!\n");
        printf("Usage:\n");
        printf("       %s <Employee ID> <Employee Last Name> < Employee Salary>\n", argv[0]);
        goto COMMON_EXIT;
    }

    rc = init_employee(&employee);
    if(rc != 0)
    {
       printf("init_employee() failed\n");
       rc = 1;
       goto  COMMON_EXIT;
    }
    
    employee->emp_id = atoi(argv[1]);
    strcpy(employee->last_name, argv[2]);
    employee->salary = atoi(argv[3]);

    employee2.emp_id = 999;
    strcpy(employee2.last_name, "Mizan");
    employee2.salary = 100000;

    printf("Employee ID: %d\n", employee->emp_id);
    printf("Employee Last Name: %s\n", employee->last_name);
    printf("Employee Salary: %d\n", employee->salary);

    printf("Employee2 ID: %d\n", employee2.emp_id);
    printf("Employee2 Last Name: %s\n", employee2.last_name);
    printf("Employee2 Salary: %d\n", employee2.salary);
    fini_employee(employee);
    employee = NULL;
COMMON_EXIT:
    return 0;
}

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
