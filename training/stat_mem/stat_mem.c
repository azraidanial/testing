#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_SIZE (100)

int main(int argc, char *argv[])
{
    int input;
    int rc;
    int i;
    int int_array[DIM_SIZE];

    if(argc < 2)
    {
        printf("Insufficient input!\n");
        printf("Usage:\n");
        printf("       %s <input>\n", argv[0]);
        exit (1);
    }
 
    input = atoi(argv[1]);

    if(input >= DIM_SIZE)
    {
        printf("Input should be lower than %d\n", DIM_SIZE);
        exit (2);
    }

    for(i = 0; i < input; i++)
    {
        int_array[i] = i * i;
    }
    for(i = 0; i < input; i++)
    {
        printf("result : %d\n", int_array[i]);
    }
      
    return 0;
}
