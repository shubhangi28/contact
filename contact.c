#include<stdio.h>
#include<string.h>
#include<stdlib.h>

   





struct contact

    {

    long ph;

    char name[20],addr[100],email_id[50];

    }list;

     

    char cho ,query[20],name[20];

    FILE *fp, *ft;

    int i,n,ch,l,found;




void listcontacts();
void addcontacts();
void search();

int main(){

   system("clear");    /* ************Main menu ***********************  */

    printf("\n\t **** Welcome to a0 contact Manager ****");

    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new   Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[0] Exit\n\t\t=================\n\t\t");

    printf("Enter the choice:");

    scanf("%d",&ch);

     

    switch(ch)

    {
	//char chr;
    case 0:

    printf("\n\n\t\tAre you sure u want to exit?");

    break;
	
	
	case 1: 
  	addcontacts();
	break;
case 2:

	listcontacts();
	break;

case 3:

	search();
	break;
default:

    printf("Invalid choice");

    break;

    }
return 0;
}




void addcontacts(){
system("clear");

    fp=fopen("contacts.txt","a");

    for (;;)

    { fflush(stdin);

    printf("enter the name input:");

    scanf("%s",&list.name);

   // if(strcmp(list.name,"")==0 || strcmp(list.name,"")==0)

   // break;

    fflush(stdin);

    printf("Phone:");

    scanf("%ld",&list.ph);

    fflush(stdin);

    printf("address:");

    scanf("%s",&list.addr);

    fflush(stdin);

    printf("email address:");

    scanf("%s",&list.email_id);
	
	fwrite(&list,sizeof(list),1,fp);
	printf("saved");
fclose(fp);

return;
   // printf("\n");

	/*fflush(stdin);
     printf("do you want to continue?(y/n):");
	scanf("%c",&cho);
		if(cho=='y' || cho=='Y')
	
	if(cho=='N' || cho=='n') */



	//return;

    }

    
    
}

void listcontacts()
{

system("clear");

    printf("\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n\nName\t\tPhone No\t Address\t\tE-mail ad.\n================================================================\n\n");

     

    for(i=97;i<=122;i=i+1)

    {

     

    fp=fopen("contacts.txt","r");

    fflush(stdin);

    found=0;

    while(fread(&list,sizeof(list),1,fp)==1)

    {

    if(list.name[0]==i || list.name[0]==i-32)

    {

    printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n",list.name, list.ph,list.addr,list.email_id);

    found++;

    }

    }

    if(found!=0)

    {printf("=========================================================== [%c]-(%d)\n\n",i-32,found);

    return ;}

    fclose(fp);

     

    }

     

    

}



void search()
{


system("clear");

    do

    {

    found=0;

    printf("\n\n\t..::CONTACT SEARCH\n\t===========================\n\t..::Name of  contact to search: ");

    fflush(stdin);

    scanf("%s",&query);

    l=strlen(query);

    fp=fopen("contacts.txt","r");

     

    system("clear");

    printf("\n\n..::Search result for '%s' \n===================================================\n",query);

    while(fread(&list,sizeof(list),1,fp)==1)

    {

    for(i=0;i<=l;i++)

    name[i]=list.name[i];

    name[l]='\0';

    if(strcmp(name,query)==0)

    {

    printf("\n..::Name\t: %s\n..::Phone\t: %ld\n..::Address\t: %s\n..::Email\t:%s\n",list.name,list.ph,list.addr,list.email_id);

    found++;

    if (found%4==0)

    {

    printf("..::Press any key to continue...");

    return ;
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

    

}
