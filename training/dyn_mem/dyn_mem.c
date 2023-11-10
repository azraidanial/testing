#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_SIZE (100)

int allocate(size_t, int **);

int main(int argc, char *argv[])
{
    int input;
    int rc;
    int i;
    int *int_array;

    if(argc < 2)
    {
        printf("Insufficient input!\n");
        printf("Usage:\n");
        printf("       %s <input>\n", argv[0]);
        goto COMMON_EXIT;
    }
 
    input = atoi(argv[1]);
    rc = allocate(sizeof(int) * (input), &int_array);

    if(rc != 0)
    {
        printf("Memory allocation failed!\n");
       goto  COMMON_EXIT;
    }

    if(input >= DIM_SIZE)
    {
        printf("Input should be lower than %d\n", DIM_SIZE);
        goto COMMON_EXIT;
    }

    for(i = 0; i < input; i++)
    {
        int_array[i] = i * i;
    }
    for(i = 0; i < input; i++)
    {
        printf("result : %d\n", int_array[i]);
    }

    free(int_array);
    int_array = NULL;

COMMON_EXIT:
    return 0;
}

int allocate(size_t size, int **array)
{
    *array = malloc(size);
    if(array == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    return 0;
}
