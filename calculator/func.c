#include <stdio.h>

void clean_stdin(void)
{
    int c;
    while (c != '\n' && c != EOF) 
    {
        c = getchar();
    }
}

float calculation (int k, float a, float b) 
{
    float x;
    switch (k)
        {   
            case 1:
            x = a+b;
            //system("clear");
            printf("\nAmount %.0f+%.0f=%.0f\n\n", a, b, x);
            break;
            case 2:
            x = a-b;
            //system("clear");
            printf("\nAmount %.0f-%.0f=%.0f\n\n", a, b, x);
            break;
            case 3:
            x = a*b;
            //system("clear");
            printf("\nAmount %.0f*%.0f=%.0f\n\n", a, b, x);
            break;
            case 4:
            x = a/b;
            //system("clear");
            printf("\nAmount %.0f:%.0f=%.2f\n\n", a, b, x);
            break;
            default:
            //system("clear");
            printf("\nUnsupported action\n\n");
            break;
        }
        return x;
}