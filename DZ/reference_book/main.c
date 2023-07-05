#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include"func.h"
/*struct struser
{
    name[50];
    phone[25];
};
*/
int main()
{
    char searchtext;
    int countusers=0;
    int num;
    int i;
    while (i == 0)
    {
        printf("\nSelect an item from the menu\n");
        printf("Menu\n\n"
                "(1)Create a user\n"
                "(2)Show the entire list\n"
                "(3)Search\n"
                "(4)Edit a user\n"
                "(5)Delete a user\n"
                "(6)Exit\n\n");
        scanf("%d", &num);
        if( 1 >= num || num <= 6 ){
            switch (num)
            {
            case 1:
            printf("\n-%d-\n", countusers);
                adduser(countusers);
                countusers++;
                break;
            
            case 2:
                listusers(countusers);
                break;
            
            case 3:
                scanf("%s", &searchtext);
                search(countusers, &searchtext);
                break;
            
            case 4:
                deleteusers(countusers);
                countusers--;
                break;
            
            case 5:
                
                break;
            
            case 6:
                i = 1;
                break;
            }
        }

}



return 0;
}