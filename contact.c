    #include<stdio.h>

    //#include<conio.h>

    #include<string.h>

   // #include<process.h>

    #include<stdlib.h>

   // #include<dos.h>

     

     

     

     

    struct contact

    {

    char ph[100];

    char name[20],addr[100],email_id[50];

    }list;

     char a[20];int count=0, q,j,temp,c;

    char cho ,query[20],name[20];

    FILE *fp, *ft;

    int i,n,ch,l,found;

     

    int main()

    {

     

     

     

     

    main:

    
	system("clear");    	
	/* ************Main menu ***********************  */	

	printf("\n\t **** Welcome to a0 contact Manager ****");

    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a newContact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[4] Edit a Contact\n\t\t[5] Delete a Contact\n\t\t[0] Exit\n\t\t=================\n\t\t");

    printf("Enter the choice:");

    scanf("%d",&ch);

     

    switch(ch)

    {

    case 0:

    printf("\n\n\t\tAre you sure u want to exit?");

    break;

    /* *********************add new contacts************  */

    case 1:

     
    system("clear");

    fp=fopen("contact2.txt","a");

    	 fflush(stdin);
	
    fflush(stdin);

    //printf("\n\n..::Editing '%s'\n\n",name);

    printf("..::Name(Use identical):");

    scanf("%s",&list.name);

    fflush(stdin);

    printf("..::Phone:");

    scanf("%s",&list.ph);

    fflush(stdin);

    printf("..::address:");

    scanf("%s",&list.addr);

    fflush(stdin);

    printf("..::email address:");

    scanf("%s",&list.email_id);

    printf("\n");

    fwrite(&list,sizeof(list),1,fp);

    fclose(fp);


     
    

    break;


    

     

    /* *********************list of contacts*************************  */

    case 2:

    system("clear");

    printf("\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n\n");

     

    fp=fopen("contact2.txt","r");
        while(fread(&list,sizeof(list),1,fp))
        {
            a[count]=list.name;
            count++;
        }
        c=count;
        for(q=0;q<count-1;q++){
		for(j=q+1;j<count;j++)
            	{
                	if (strcmp(a[j], a[j + 1]) > 0) {
            temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
            	}
        }
      /*  printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<SORTED_DATA>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");*/
                printf(" Name\t|  phone no\t| Address\t| email ID\t|\n");

        count=c;
        for(q=0;q<count;q++){
		rewind(fp);
            	while(fread(&list,sizeof(list),1,fp)==1){
                	if(a[q]==list.name)
                  		printf("\n|%-10s| %-10s| %-10s\t| %-10s|\n",list.name,list.ph,list.addr ,list.email_id);
	    	}

	}

    break;

     

     

     

    /* *******************search contacts**********************  */

    case 3:

    system("clear");

    do

    {

    found=0;

    printf("\n\n\t..::CONTACT SEARCH\n\t===========================\n\t..::Name of  contact to search: ");

    fflush(stdin);

    scanf("%s",&query);

    l=strlen(query);

    fp=fopen("contact2.txt","r");

     

    system("clear");

    printf("\n\n..::Search result for '%s' \n===================================================\n",query);

    while(fread(&list,sizeof(list),1,fp)==1)

    {

    for(i=0;i<=l;i++)

    name[i]=list.name[i];

    name[l]='\0';

    if(strcmp(name,query)==0)

    {

    printf("\n..::Name\t: %s\n..::Phone\t: %s\n..::Address\t: %s\n..::Email\t:%s\n",list.name,list.ph,list.addr,list.email_id);

    found++;

    if (found%4==0)

    {

    printf("..::Press any key to continue...");

    return 0;
    }

    }

    }

     

    if(found==0)

    printf("\n..::No match found!");

    else

    printf("\n..::%d match(s) found!",found);

    fclose(fp);

    printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

    scanf("%d",&ch);

    }while(ch==1);

    break;

     

     

    /* *********************edit contacts************************/

    case 4:

    system("clear");

    fp=fopen("contact2.txt","r");

    ft=fopen("temp.txt","w");

    fflush(stdin);

    printf("..::Edit contact\n===============================\n\n\t..::Enter the name of contact to edit:");

    scanf("%s",name);

    while(fread(&list,sizeof(list),1,fp)==1)

    {

    if(strcmp(name,list.name)!=0)

    fwrite(&list,sizeof(list),1,ft);

    }

    fflush(stdin);

    printf("\n\n..::Editing '%s'\n\n",name);

    printf("..::Name(Use identical):");

    scanf("%s",&list.name);

    fflush(stdin);

    printf("..::Phone:");

    scanf("%s",&list.ph);

    fflush(stdin);

    printf("..::address:");

    scanf("%s",&list.addr);

    fflush(stdin);

    printf("..::email address:");

    scanf("%s",&list.email_id);

    printf("\n");

    fwrite(&list,sizeof(list),1,ft);

    fclose(fp);

    fclose(ft);

    remove("contact2.txt");

    rename("temp.txt","contact2.txt");

    break;

     

     

    /* ********************delete contacts**********************/

    case 5:

    system("clear");

    fflush(stdin);

    printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of contact to delete:");

    scanf("%s",&name);

    fp=fopen("contact2.txt","r");
    ft=fopen("temp.txt","w");

    while(fread(&list,sizeof(list),1,fp)!=0)

    if (strcmp(name,list.name)!=0)

    fwrite(&list,sizeof(list),1,ft);

    fclose(fp);

    fclose(ft);

    remove("contact2.txt");

    rename("temp.txt","contact2.txt");

    break;

     

    default:

    printf("Invalid choice");

    break;

    }

     

     

    printf("\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");

    scanf("%d",&ch);

    switch (ch)

    {

    case 1:

    goto main;

     

     

    case 0:

    break;

     

    default:

    printf("Invalid choice");

    break;

    }

     

    return 0;

    }
