#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct emp_info {
char name[32];
int pers_id;
long salary;
} EMPLOYEE;

int employee_init(EMPLOYEE **);
void employee_fini(EMPLOYEE *);

int main()
{
 int rc;
 int rc1;
 EMPLOYEE *employee;

 rc1 = 0;

 rc = employee_init(&employee);
 
 if(rc != 0)
 {
  printf("Init failed.\n");
  rc1 = 123;
  goto COMMON_EXIT;
 }
 
 strcpy(employee->name, "DANIAL");
 employee->pers_id = 1234;
 employee->salary = 10000;

 printf("Name: %s\n", employee->name);
 printf("Personnel ID: %d\n", employee->pers_id);
 printf("Salary: RM%ld\n", employee->salary);

 employee_fini(employee);

COMMON_EXIT:
  return rc1;
}

int employee_init(EMPLOYEE **employee)
{
 int rc;
 EMPLOYEE *emp_ptr;

 rc = 0;

 emp_ptr = malloc(sizeof(EMPLOYEE));
 
 if(emp_ptr == NULL)
 {
  printf("Malloc failed\n");
  rc = 1;
  goto COMMON_EXIT;
 }

 *employee = emp_ptr;

 COMMON_EXIT:
  return rc;
}

void employee_fini(EMPLOYEE *employee)
{
 free(employee);
 return;
}
