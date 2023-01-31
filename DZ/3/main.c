#include <stdio.h>
#include <stdlib.h>

void print_array(int **array, int N)
{
    int K = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", array[i][j]);
            K++;
        }
        printf("\n");
    }
    printf("\n");
}


int main(int argc, char *argv[])
{
    int **array;
    int N;

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
    
    array = (int**)malloc(N*N * sizeof(int));
    for(int i = 0; i < N; ++i)
    {
        array[i] = (int*)malloc(N * sizeof(int));
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i < N-j && j < N-i) 
            {
                array[i][j] = 1;
            }
            else 
            {
                array[i][j] = 0;
            }
        }
    }
    print_array(array, N);  

    for (int i = 0; i < N; i++) 
    {
        free(array[i]);
    }
    free(array);

    return 0;
}
