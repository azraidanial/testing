typedef struct employee EMPLOYEE;

int employee_init(EMPLOYEE **);
void employee_fini(EMPLOYEE *);
int employee_set_name(EMPLOYEE *, char *);
int employee_get_name(EMPLOYEE *, char *);
int employee_set_pers_id(EMPLOYEE *, int);
int employee_get_pers_id(EMPLOYEE *, int *);
int employee_set_salary(EMPLOYEE *, long);
int employee_get_salary(EMPLOYEE *, long *);
