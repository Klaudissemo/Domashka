#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_array(int *array, int N)
{
    for (int i = 0; i < N; i++)
    {
       printf("%d ", array[i]);
    }
    printf("\n");
}



int main(int argc, char* argv[])
{
    int* array;
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
    

    array = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        array[i] = i+1;
    }
    print_array(array, N);


    for (int i = 0; i < N/2; i++)
    {
        swap(&array[i], &array[N-(i+1)]);
    }

    print_array(array, N);

    free(array);


    return 0;


}