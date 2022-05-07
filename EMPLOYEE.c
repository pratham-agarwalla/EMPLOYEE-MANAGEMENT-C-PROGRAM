#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>  // FOR COORDINATES
#include <string.h>
COORD coord = {0,0};
void gotoxy(int x,int y)     //ALIGNING ON THE MAIN SCREEN
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int main()
{
    FILE *fp, *ft;  // FILE POINTER VARIABLES FP- EMP AND FT-TEMP        WE MADE TEMP FILE FOR DELETING PURPOSE
    char another, choice, choice2;
    struct emp    //STRUCTURE
    {
        char code[10];
        char fname[40];
        char lname[40];
        char desg[40];
        int age;
        float bs;
        char deg[25];
        int exp;
        char ph[15];
    };
    struct emp e;  // DEFINED USING e
    char empcode[10];  // TO GET INPUT FROM USER
    long int recsize;
    fp = fopen("EMP.DAT","r+"); //OPENING EMP FILE FOR READING AND MODIFICATION
    if(fp == NULL)
    {
        fp = fopen("EMP.DAT","w+"); //OPENING EMP FILE FOR WRITING AND MODIFICATION
        if(fp == NULL)
        {
            printf("Connot open file"); // IF NO EMP.DAT FILE
            exit(1);
        }
    }
    recsize = sizeof(e);
    while(1)
    {
        system("cls");
        gotoxy(30,6);
        printf("WELCOME TO EMPLOYEE MANAGEMENT SYSTEM");
        gotoxy(36,7);
        printf("CREATED BY TEAM TECHNO");
        gotoxy(38,10);
        printf("1. Add Record");
        gotoxy(38,12);
        printf("2. List Records");
        gotoxy(38,14);
        printf("3. List Specific Record");
        gotoxy(38,16);
        printf("4. Modify Complete Record");
        gotoxy(38,18);
        printf("5. Modify Specific Record");
        gotoxy(38,20);
        printf("6. Delete Record");
        gotoxy(38,22);
        printf("7. Exit");
        gotoxy(30,24);
        printf("Your Choice: ");
        fflush(stdin);
        choice  = getche();
        switch(choice)
        {
            //ADD RECORDS
        case '1':
            system("cls");
            fseek(fp,0,SEEK_END);
            another = 'y';
            while(another == 'y')
            {
                printf("\nEnter Employee Code: ");
                scanf("%s",e.code);
                printf("\nEnter First Name: ");
                scanf("%s",e.fname);
                printf("\nEnter Last Name: ");
                scanf("%s",e.lname);
                printf("\nEnter Designation: ");
                scanf("%s",e.desg);
                printf("\nEnter Age: ");
                scanf("%d", &e.age);
                printf("\nEnter Basic Salary: ");
                scanf("%f", &e.bs);
                printf("\nEnter Qualification: ");
                scanf("%s",e.deg);
                printf("\nEnter Experience: ");
                scanf("%d",&e.exp);
                printf("\nEnter Contact Number: ");
                scanf("%s",e.ph);
                fwrite(&e,recsize,1,fp);
                printf("\nPRESS ANY KEY TO GO BACK TO MAIN SCREEN");
                fflush(stdin);
                another = getche();
            }
            break;
            //LIST RECORDS (ENTIRE)
        case '2':
            system("cls"); // CLEARING THE SCREEN
            rewind(fp);
            printf("EMPLOYEE DETAILS:\n");
            while(fread(&e,recsize,1,fp)==1)
            {
                printf("\nEMPLOYEE CODE: %s\nNAME: %s %s\nDESIGNATION: %s\nAGE: %d YEARS\nBASIC SALARY: Rs. %.2f\nQUALIFICATION: %s\nEXPERIENCE: %d YEARS\nCONTACT NUMBER: %s\n",e.code,e.fname,e.lname,e.desg,e.age,e.bs,e.deg,e.exp,e.ph);
            }
            getch();
            break;
            //LIST SPECIFIC RECORD BASED ON EMP CODE
            case '3':
            system("cls"); // CLEARING THE SCREEN
            another = 'y';
            while(another == 'y')
            {
                printf("Enter the EMPLOYEE CODE to list details: ");
                scanf("%s", empcode);
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1)
                {
                    if(strcmp(e.code,empcode) == 0)
                    {
                        printf("\nEMPLOYEE CODE: %s\nNAME: %s %s\nDESIGNATION: %s\nAGE: %d YEARS\nBASIC SALARY: Rs. %.2f\nQUALIFICATION: %s\nEXPERIENCE: %d YEARS\nCONTACT NUMBER: %s\n",e.code,e.fname,e.lname,e.desg,e.age,e.bs,e.deg,e.exp,e.ph);
                        fseek(fp,-recsize,SEEK_CUR);
                        fwrite(&e,recsize,1,fp);
                        break;
                    }
                }
                printf("\nPRESS ANY KEY TO GO BACK TO MAIN SCREEN");
                fflush(stdin);
                another = getche();
            }
            break;
            //MODIFY ENTIRE RECORD BASED ON EMP CODE
        case '4':
            system("cls");  //CLEARING SCREEN
            another = 'y';
            while(another == 'y')
            {
                printf("Enter the EMPLOYEE CODE to modify: ");
                scanf("%s", empcode);
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1)
                {
                    if(strcmp(e.code,empcode) == 0)
                    {
                        printf("\nEnter First Name: ");
                        scanf("%s",e.fname);
                        printf("\nEnter Last Name: ");
                        scanf("%s",e.lname);
                        printf("\nEnter Designation: ");
                        scanf("%s",e.desg);
                        printf("\nEnter Age: ");
                        scanf("%d", &e.age);
                        printf("\nEnter Basic Salary: ");
                        scanf("%f", &e.bs);
                        printf("\nEnter Qualification: ");
                        scanf("%s",e.deg);
                        printf("\nEnter Experience: ");
                        scanf("%d",&e.exp);
                        printf("\nEnter Contact Number: ");
                        scanf("%s",e.ph);
                        fseek(fp,-recsize,SEEK_CUR);
                        fwrite(&e,recsize,1,fp);
                        break;
                    }
                }
                printf("SUCCESSFULLY MODIFIED THE EMPLOYEE DETAILS!!");
                printf("\nPRESS ANY KEY TO GO BACK TO MAIN SCREEN");
                fflush(stdin);
                another = getche();
            }
            break;
            //MODIFY SPECIFIC RECORD OF EMP
            case '5':
            system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("Enter the EMPLOYEE CODE to modify: ");
                scanf("%s", empcode);
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1)
                {
                    if(strcmp(e.code,empcode) == 0)
                    {
                        printf("\n1.MODIFY NAME");
                        printf("\n2.MODIFY DESIGNATION");
                        printf("\n3.MODIFY AGE");
                        printf("\n4.MODIFY BASIC SALARY");
                        printf("\n5.MODIFY QUALIFICATION");
                        printf("\n6.MODIFY EXPERIENCE");
                        printf("\n7.MODIFY CONTACT NUMBER");
                        printf("\nYour Choice: ");
                        fflush(stdin);
                        choice2  = getche();
                        switch(choice2)
                        {
                            case '1':    //MODIFY NAME
                                system("cls");
                                printf("ENTER FIRST NAME:");
                                scanf("%s",e.fname);
                                printf("ENTER LAST NAME:");
                                scanf("%s",e.lname);
                                fseek(fp,-recsize,SEEK_CUR);
                                fwrite(&e,recsize,1,fp);
                                break;
                            case '2':   //MODIFY DESIGNATION
                                system("cls");
                                printf("ENTER DESIGNATION:");
                                scanf("%s",e.desg);
                                fseek(fp,-recsize,SEEK_CUR);
                                fwrite(&e,recsize,1,fp);
                                break;
                            case '3':  //MODIFY AGE
                                system("cls");
                                printf("ENTER AGE:");
                                scanf("%d",&e.age);
                                fseek(fp,-recsize,SEEK_CUR);
                                fwrite(&e,recsize,1,fp);
                                break;
                            case '4':  //MODIFY SALARY
                                system("cls");
                                printf("ENTER SALARY:");
                                scanf("%f",&e.bs);
                                fseek(fp,-recsize,SEEK_CUR);
                                fwrite(&e,recsize,1,fp);
                                break;
                            case '5':  //MODIFY QUALIFICATION
                                system("cls");
                                printf("ENTER QUALIFICATION:");
                                scanf("%s",e.deg);
                                fseek(fp,-recsize,SEEK_CUR);
                                fwrite(&e,recsize,1,fp);
                                break;
                            case '6':  //MODIFY EXPERIENCE
                                system("cls");
                                printf("ENTER EXPERIENCE:");
                                scanf("%d",&e.exp);
                                fseek(fp,-recsize,SEEK_CUR);
                                fwrite(&e,recsize,1,fp);
                                break;
                            case '7':  //MODIFY CONTACT NUMBER
                                system("cls");
                                printf("ENTER CONTACT NUMBER:");
                                scanf("%s",e.ph);
                                fseek(fp,-recsize,SEEK_CUR);
                                fwrite(&e,recsize,1,fp);
                                break;
                                }
                                break;
                }}
                printf("SUCCESSFULLY MODIFIED THE EMPLOYEE DETAILS!!");
                printf("\nPRESS ANY KEY TO GO BACK TO MAIN SCREEN");
                fflush(stdin);
                another = getche();
            }
            break;
            //DELETE RECORDS BASED ON EMP CODE
        case '6':
            system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("\nEnter EMPLOYEE CODE of Employee to be deleted: ");
                scanf("%s",empcode);
                ft = fopen("Temp.dat","w"); // TEMP FILE FOR DELETING THE RECORD
                rewind(fp);
                while(fread(&e,recsize,1,fp) == 1)
                {
                    if(strcmp(e.code,empcode) != 0) // COMPARING E.CODE WITH EMP CODE
                    {
                        fwrite(&e,recsize,1,ft);
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("EMP.DAT");  //EMP.DAT FILE IS REMOVED
                rename("Temp.dat","EMP.DAT");  //TEMP.DAT FILE IS RENAMED TO EMP.DAT
                fp = fopen("EMP.DAT", "r+");
                printf("SUCCESSFULLY DELETED THE EMPLOYEE DETAILS!!");
                printf("\nPRESS ANY KEY TO GO BACK TO MAIN SCREEN");
                fflush(stdin);    // FLUSH THE OUTPUT LIKE STDOUT
                another = getche();
            }
            break;
            //EXIT
        case '7':
            gotoxy(30,25);
            printf("\nTHANKS FOR USING THE SYSTEM");
            fclose(fp);
            exit(0);
            break;
        default:
            gotoxy(34,26);
            printf("SORRY! WRONG INPUT");
            gotoxy(34,27);
            printf("PLEASE TRY AGAIN!!");
            getch();
            break;
        }
        }
    return 0;
}
