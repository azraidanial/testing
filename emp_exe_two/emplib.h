#define LAST_NAME_SIZE (32)

typedef struct empdata
{
    int emp_id;
    int salary;
    char last_name[LAST_NAME_SIZE];
}EMPDATA;

int init_employee(EMPDATA **);
int fini_employee(EMPDATA *);
