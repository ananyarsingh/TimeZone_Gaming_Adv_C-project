//including header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//defining global variables
int i,j,main_exit;

//declaring functions
void menu();
void new_entry();
void view_list();
void see();
void closer();
float games();

//defining structures
struct date{
    int month,day,year;
};
struct {

    char name[60];
    int age;
    char passw[60];
    char city[60];
    char mail_id[30];
    int phone;
    char id[10];
    float price;
    struct date dob;
    }add,check;

//--------------------------------------------------------------------------------------------------------------------
//main function
int main()
{
  menu();
  return 0;
}

float games()
{
int game_i;
printf("The following Games are there to Play\n\n");
printf("1.Bowling\n\n2.Snooker\n\n3.Ice Air Hockey\n\n4.Roadrash\n\n5.Kung Fu Panda\n\n6.Sweet Land \n\n7.Bumper Car\n\n8.Mario\n\n9.Dancing Steps\n\n10.Waliking Dead\n\n");
printf("Enter the game you want to play!");
scanf("%d",&game_i);
float amt=0.00;
switch(game_i)
        {
                case 1: amt=110.00;
                return(amt);
                break;
                case 2: amt=130.00;
                return(amt);
                break;
                case 3: amt=170.00;
                return(amt);
                break;
                case 4: amt=910.00;
                return(amt);
                break;
                case 5: amt=90.00;
                return(amt);
                break;
                case 6: amt=340.00;
                return(amt);
                break;
                case 7: amt=110.00;
                return(amt);
                break;
                case 8: amt=1160.00;
                return(amt);
                break;
                case 9: amt=170.00;
                return(amt);
                break;
                case 10: amt=11.00;
                return(amt);
                break;
                default:
                        printf(" \n");
        }

}
//menu function
void menu()
{
system("CLS");
    int choice;
    printf("\n\n\t\t\tTime Zone Games!!!");
    printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1>> Register\n\t\t2>> Check the details of existing account\n\t\t3>> View all users\n\t\t4>> Play a game\n\t\t5>> Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    switch(choice)
    {

        case 1:new_entry();
        break;
        case 2:see();
        break;
        case 3:view_list();
        break;
        case 4:play();
        case 5:closer();
        break;
        default:menu();
    }
}

//------------------------------------------------------------------------------------------------------------------
//function to display all students of a hostel
//new entry function
void new_entry()
{
	system("CLS");
    int choice;
    FILE *ptr,*hostel;

    ptr=fopen("record98.dat","a+");
    id:

    printf("\t\t\t\xB2\xB2\xB2 ADD USER DATA  \xB2\xB2\xB2\xB2");
    printf("\nEnter your id:");
    scanf("%s",check.id);
    printf("\nEnter your password:");
    scanf("%s",check.passw);

    while(fscanf(ptr,"%s %s %s %d/%d/%d %d %s %d %s %f",add.id,add.passw, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id,&add.price)!=EOF)
    {
        if (strcmp(check.id,add.id)==0)
            {printf("This id is already in use!\n");
             goto id;
        }
        else if (strcmp(check.passw,add.passw)==0)
            {printf("This id is already in use!\n");
             goto id;
        }
    }

    strcpy(add.id,check.id);
    strcpy(add.passw,check.passw);
    printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the city:");
    scanf("%s",add.city);
    printf("\nEnter the phone number: ");
    scanf("%d",&add.phone);
    printf("\n Enter your email id :");
    scanf("%s",add.mail_id);
    printf("\nAdd money to your account: ");
    scanf("%f",&add.price);

        fprintf(ptr,"%s %s %s %d/%d/%d %d %s %d %s %f\n",add.id,add.passw, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id,add.price);

		//adding student roll no. to hostels' list

		hostel=fopen("BH-98.dat","a+");
		fprintf(hostel, "%s\n", add.id);
		fprintf(hostel, "%s\n", add.passw);
		fclose(hostel);

		//----------------------------------------

    fclose(ptr);
    printf("\nRegistration successfull!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);

    if (main_exit==1)

        menu();
    else if(main_exit==0)
            closer();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}

//------------------------------------------------------------------------------------------------------------------
// to view all students
void view_list()
{
	system("CLS");
    FILE *view;
    view=fopen("record98.dat","r");
    int test=0;

    printf("\nID\tNAME\t\t\tCITY\t\t\tPHONE\t\t\tBALANCE\n");

    while(fscanf(view,"%s %s%s %d/%d/%d %d %s %d %s %f \n",add.id,add.passw,add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, &add.city, &add.phone, &add.mail_id,&add.price)!=EOF)
       {
           printf("\n%s\t%s\t\t\t%s\t\t\t%d\t\t\t%f\n",add.id,add.name,add.city,add.phone,add.price);
           test++;
       }
    fclose(view);

    if (test==0)
        {
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);

        if (main_exit==1)
            menu();
        else if(main_exit==0)
            closer();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}

//------------------------------------------------------------------------------------------------------------------
//function to view all data of 1 student

void see()
{

	system("CLS");
    FILE *ptr;
    int test=0;
    int choice;
    ptr=fopen("record98.dat","r");
    printf("Do you want to check by\n1.ID\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("\n\nEnter the ID:");
        scanf("%s",check.id);

        while (fscanf(ptr,"%s %s %s %d/%d/%d %d %s %d %s %f\n",add.id,add.passw, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id,&add.price)!=EOF)
        {
            if(strcmp(add.id,check.id)==0)
            {
                test=1;

                printf("\nID:%s \nPassword:%s\nName:%s \nDOB:%d/%d/%d \nAge:%d \ncity:%s \nPhone number:%d \nE-Mail id:%s \nBalance:%f",add.id,add.passw, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id,add.price);
            }
        }
    }
    else if (choice==2)
    {   printf("\n\nEnter the name:");
        scanf("%s",check.name);
        while (fscanf(ptr,"%s %s %s %d/%d/%d %d %s %d %s %f\n",add.id,add.passw, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id,&add.price)!=EOF)
        {
            if(strcmp(add.id,check.id)==0)
            {
                test=1;

                printf("\nID:%s \nPassword:%s\nName:%s \nDOB:%d/%d/%d \nAge:%d \ncity:%s \nPhone number:%d \nE-Mail id:%s \nBalance:%f",add.id,add.passw, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id,add.price);
            }
        }
    }

    fclose(ptr);
     if(test!=1)
     	printf("\nRecord not found!!\a\a\a");
    see_invalid:
        printf("\n1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            closer();
        else if(main_exit==0)
            printf("");
        else
        {
        	printf("\nInvalid!\a");
            goto see_invalid;
		}

}
void play()
{
	system("CLS");
    FILE *ptr;
    int test1=0;
    ptr=fopen("record98.dat","r");
     printf("\n\nEnter the ID:");
    scanf("%s",check.id);
 	printf("\n\nEnter the password:");
	scanf("%s",check.passw);


        while (fscanf(ptr,"%s %s %s %d/%d/%d %d %s %d %s %f\n",add.id,add.passw, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id,&add.price)!=EOF)
        {
            if(strcmp(add.id,check.id)==0 && strcmp(add.passw,check.passw)==0)
            {
                test1=1;
                system("CLS");
                float money;
                money=games();
                printf("\nMoney for this game is :  %f",money);
                add.price=add.price-money;
                printf("\nBalance in your account after deduction is : %f",add.price);
            }
        }

    fclose(ptr);
     if(test1!=1)
     	printf("\nRecord not found!!\a\a\a");
    see_invalid:
        printf("\n1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            closer();
        else if(main_exit==0)
            printf("  ");
        else
        {
        	printf("\nInvalid!\a");
            goto see_invalid;
		}

}
//-------------------------------------------------------------------------------------------------------------
//function displaying developer credits
void closer()
{
	system("CLS");
    printf("\n\n\n\nProject Done BY:\n Ananya Singh\n");
}



