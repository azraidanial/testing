#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int square_of(int, int *);

int main(int argc, char *argv[])
{
    int input;
    int result;
    int rc;

    if(argc < 2)
    {
        printf("Insufficient input!\n");
        printf("Usage:\n");
        printf("       %s <input>\n", argv[0]);
        exit (1);
    }
 
    input = atoi(argv[1]);
    rc = square_of(input, &result);

    printf("result of square of %d = %d\n", input, result);
    printf("result of square of %d = 0x%lx\n", input, &result);
    printf("result of square of %d = %p\n", input, &result);
    
    return 0;
}

int square_of(int input, int *res)
{
    *res = input * input;
    printf("res = %d\n", *res);
    printf("res = 0x%lx\n", res);
    printf("res = %p\n", res);
    return 0;
}
