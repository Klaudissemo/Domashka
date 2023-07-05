
       
    struct User
    {
        char lname[15];
        char fname[15];
        char mname[15];
        char phone[15];
        
    } user[99] ;  

void deleteusers(int a){
    int delptemp;
    if (a == 0){
        printf("\nThe list is empty.\n");
    }

    int y = a;
    for(int i=0; i<y; i++){
        printf("№[%d]Name: %s %s %s | phone: %s\n\n", i+1,user[i].lname, user[i].fname, user[i].mname, user[i].phone);
    }
    printf("Select the user number to delete: ");
    scanf("%d", &delptemp);
    int tempusers=delptemp-1; 
    printf("%d", tempusers);
    printf("%d", delptemp);
    printf("%d", y);
    for(tempusers=delptemp;tempusers<=y;tempusers++)
    {
        *user[tempusers].lname=*user[tempusers+1].lname;
        *user[tempusers].fname=*user[tempusers+1].fname;
        *user[tempusers].mname=*user[tempusers+1].mname;
        *user[tempusers].phone=*user[tempusers+1].phone;
    }
    printf("_____________");
}

char search(int a, char *text){
    char *textsearch=text;
    printf("%s", textsearch);
    printf("\n -%d-\n", a);
    int y = a;
    for(int i=0; i<y; i++){
        if(strcmp("%s",textsearch) == strcmp("%s", user[i].lname))
        {
            printf("№[%d]Name: %s %s %s | phone: %s\n\n", i+1,user[i].lname, user[i].fname, user[i].mname, user[i].phone);
            return 0;
        }else if(strcmp("%s",textsearch)== strcmp("%s", user[i].lname))
        {
            printf("№[%d]Name: %s %s %s | phone: %s\n\n", i+1,user[i].lname, user[i].fname, user[i].mname, user[i].phone);
            return 0;
        }else if(strcmp("%s",textsearch) == strcmp("%s", user[i].lname))
        {
            printf("№[%d]Name: %s %s %s | phone: %s\n\n", i+1,user[i].lname, user[i].fname, user[i].mname, user[i].phone);
            return 0;
        }else if(strcmp("%s",textsearch) == strcmp("%s", user[i].phone)){
            printf("№[%d]Name: %s %s %s | phone: %s\n\n", i+1,user[i].lname, user[i].fname, user[i].mname, user[i].phone);
            return 0;
        }
    }
    printf ("\nThere is no such user.\n");
    return 0;
}

char listusers (int a){
    if (a == 0){
        printf("\nThe list is empty.\n");
    }
    int y = a;
    for(int i=0; i<y; i++){
        printf("№[%d]Name: %s %s %s | phone: %s\n\n", i+1,user[i].lname, user[i].fname, user[i].mname, user[i].phone);
    }
    return 0;
}

void adduser(int a){
    int i = a;

                printf("Enter full name:\n");
                printf("\n -%d-\n", i);
                scanf("%s", user[i].lname);
                scanf("%s", user[i].fname);
                scanf("%s", user[i].mname);
                printf("Enter a phone:\n");
                scanf("%s", user[i].phone);

                printf("№[%d]Name: %s %s %s | phone: %s\n\n", i+1,user[i].lname, user[i].fname, user[i].mname, user[i].phone);
                //printf("\n -%d-\n", i);
    
    //return 0;
}
