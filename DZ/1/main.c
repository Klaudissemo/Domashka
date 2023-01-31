#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, int N)
{
    int K = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d\t", array[K]);
            K++;
        }
        printf("\n\n");
    }
    printf("\n");
}


int main(int argc, char* argv[])
{
    int* array;
    int N;
    int K = 0;

    if (argc > 1)
    {
        N = atoi(argv[1]);
        printf("N = %d\n", N);
    }
    else
    {
        printf("No arguments, exit\n");
        return 0;
    }
    
    array = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            array[K] = K+1;
            K++;
        }
    }
    print_array(array, N);  

    free(array);

    return 0;
}
