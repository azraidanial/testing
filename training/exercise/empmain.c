#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "emplibex.h"

int main()
{
 int rc;
 int rc1;
 EMPLOYEE *employee;
 char local_name[32];
 int local_pers_id;
 long local_salary;

 rc1 = 0;

 rc = employee_init(&employee);
 
 if(rc != 0)
 {
  printf("Init failed.\n");
  rc1 = 123;
  goto COMMON_EXIT;
 }
 
 rc = employee_set_name(employee, "DANIAL");
 
 if(rc != 0)
 {
  printf("Set name failed.\n");
  rc1 = 124;
  goto COMMON_EXIT;
 }
 
 rc = employee_get_name(employee, local_name);
 
 if(rc != 0)
 {
  printf("Get name failed.\n");
  rc1 = 125;
  goto COMMON_EXIT;
 }
 rc = employee_set_pers_id(employee, 1234);
 
 if(rc != 0)
 {
  printf("Set pers_id failed.\n");
  rc1 = 126;
  goto COMMON_EXIT;
 }
 
 rc = employee_get_pers_id(employee, &local_pers_id);
 
 if(rc != 0)
 {
  printf("Get pers_id failed.\n");
  rc1 = 127;
  goto COMMON_EXIT;
 }
 
 rc = employee_set_salary(employee, 30000);
 
 if(rc != 0)
 {
  printf("Set salary failed.\n");
  rc1 = 128;
  goto COMMON_EXIT;
 }
 
 rc = employee_get_salary(employee, &local_salary);
 
 if(rc != 0)
 {
  printf("Get salary failed.\n");
  rc1 = 129;
  goto COMMON_EXIT;
 }
  
 printf("Name: %s\n", local_name);
 printf("Pers ID: %d\n", local_pers_id);
 printf("Salary: %ld\n", local_salary);
 
COMMON_EXIT:
 
 if(employee != NULL)
 {
  employee_fini(employee);
 }
 return rc1;
}
