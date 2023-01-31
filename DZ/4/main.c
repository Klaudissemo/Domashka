#include <stdio.h>
#include <stdlib.h>

void print_array(int **array, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d\t", array[i][j]);
        }
        printf("\n\n");
    }
    printf("\n");
}

void snail_array(int **array, int N)
{
    int j_start = 0, j_end = N-1;
    int i_start = 0, i_end = N-1;
    int j, i, val = 1;
    while (val <= N*N)
    {
        for (j = j_start; j <= j_end; j++)//right
        {
            array[i_start][j] = val;
            val++;
        }
        i_start++;
        
        for(i = i_start; i <= i_end; i++)//down
        {
            array[i][j_end] = val;
            val++;
        }
        j_end--;
        
        for(j = j_end; j >= j_start; j--)//left
        {
            array[i_end][j] = val;
            val++;
        }
        i_end--;
        
        for(i = i_end; i >= i_start; i--)//up
        {
            array[i][j_start] = val;
            val++;
        }
        j_start++;
            
    }

}

int main(int argc, char *argv[])
{
    int **array;
    int N;
    int i;
    
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
    
    array = (int**)malloc(N * sizeof(int*));
    for(i = 0; i < N; i++)
    {
        array[i] = (int*)malloc(N * sizeof(int));
    }
    
    snail_array(array, N);
    print_array(array, N);
    
    free(array);
    
    return 0;
}