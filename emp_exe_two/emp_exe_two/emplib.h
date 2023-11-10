#define LAST_NAME_SIZE (32)

typedef struct empdata
{
    int emp_id;
    int salary;
    char last_name[LAST_NAME_SIZE];
}EMPDATA;

int init_employee(EMPDATA **);
int fini_employee(EMPDATA *);

int set_employee_id(EMPDATA *, int);
int set_employee_name(EMPDATA *, char *);
int set_employee_salary(EMPDATA *, int);

int get_employee_id(EMPDATA *, int *);
int get_employee_name(EMPDATA *, char *);
int get_employee_salary(EMPDATA *, int *);
