#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    int i = 0;
    while (i == 0 )
    {
        char k;
        float a, b;
        printf("№1: Summation(+) \n"
        "№2: Subtraction(-) \n"
        "№3: Multiplication(*) \n"
        "№4: Divided(:) \n"
        "№5: Exit \n"
        "Select an action (№) ");
        scanf("%c", &k);
        k = atoi(&k);
        
        if (k<=4&&k>=1)
        {
            printf("\nFirst value = ");
            scanf("%f", &a);
            printf("\nSecond value = ");
            scanf("%f", &b);  
        }
        if (k == 5){
            i++;
        } else {
            calculation(k, a, b);
        }

        clean_stdin();
        
    }

    return 0;
}