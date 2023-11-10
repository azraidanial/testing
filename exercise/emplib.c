#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "emplibex.h"

struct employee 
{
char name[32];
int pers_id;
long salary;
};

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

int employee_set_name(EMPLOYEE *employee, char *name)
{
 int rc;

 rc = 0;
 if(employee == NULL)
 {
  printf("Invalid parameter\n");
  rc = 1;
  goto COMMON_EXIT;
 }
 strcpy(employee->name, name);

 COMMON_EXIT:
 return rc;
}

int employee_get_name(EMPLOYEE *employee, char *name)
{
 int rc;

 rc = 0;
 if((employee == NULL) || (name == NULL))
 {
  printf("Invalid parameter\n");
  rc = 1;
  goto COMMON_EXIT;
 }
 strcpy(name, employee->name);

 COMMON_EXIT:
 return rc;
}

int employee_set_pers_id(EMPLOYEE *employee, int pers_id)
{
 int rc;

 rc = 0;
 if(employee == NULL)
 {
  printf("Invalid parameter\n");
  rc = 1;
  goto COMMON_EXIT;
 }
 employee->pers_id =  pers_id;

COMMON_EXIT:
 return rc;
}

int employee_get_pers_id(EMPLOYEE *employee, int *pers_id)
{
 int rc;

 rc = 0;
 if((employee == NULL) || (pers_id == NULL))
 {
  printf("Invalid parameter\n");
  rc = 1;
  goto COMMON_EXIT;
 }
 *pers_id =  employee->pers_id;

COMMON_EXIT:
 return rc;
}
int employee_set_salary(EMPLOYEE *employee, long salary)
{
 int rc;

 rc = 0;
 if(employee == NULL)
 {
  printf("Invalid parameter\n");
  rc = 1;
  goto COMMON_EXIT;
 }
 employee->salary =  salary;

COMMON_EXIT:
  return rc;
}

int employee_get_salary(EMPLOYEE *employee, long *salary)
{
 int rc;

 rc = 0;
 if((employee == NULL) || (salary == NULL))
 {
  printf("Invalid parameter\n");
  rc = 1;
  goto COMMON_EXIT;
 }
 *salary =  employee->salary;

COMMON_EXIT:
  return rc;
}
