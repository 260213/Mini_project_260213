/**
 * @file edit.c
 * @author 260213 (devswarupmohanty@gmail.com)
 * @brief Let's admin edit the details of the customer
 * @version 0.1
 * @date 2021-04-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<stdio.h>
#include "new_acc.h"
#include"database.h"
#include"edit.h"
#include"close.h"
#include"menu.h"

void edit(void)

{
    int number,test = 0, main = 0;
    FILE *ptrold,*ptrnew;
    ptrold = fopen("record.dat","r");
    ptrnew = fopen("new.dat","w");
    tag:
    printf("\nEnter the account no. of the customer whose details are to be changed: ");
    scanf("%d",&upd.acc_no);
    while(fscanf(ptrold,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if(add.acc_no==upd.acc_no)
        {
            test = 1;
            printf("\nWhich detail is to be changed?\n1.Address\n2.Phone\n\nEnter your choice(1 for Address and 2 for Phone)");
            scanf("%d",&number);
            if(number==1)
            {
                printf("Enter updated address: ");
                scanf("%s",&upd.address);
                fprintf(ptrnew,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                printf("\nAddress Updated!");

            }
            else if(number==2)
            {
                printf("Enter updated phone number: ");
                scanf("%s",&upd.phone);
                fprintf(ptrnew,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                printf("\nPhone number Updated!");
            }
        }
        else{
            fprintf(ptrnew,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
        }
    }
    fclose(ptrold);
    fclose(ptrnew);
    remove("record.dat");
    rename("new.dat","record.dat");

    if(test!=1)
    {
        printf("\nRecord not availabe!!");
        edit_NA:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit");
        scanf("%d",&main);
        if(main==1)
        {
            menu();
        }
        else if(main==2)
        {
            close();
        }
        else if(main==0)
        {
            goto tag;
        }
        else
        {
            printf("\nInvalid");
            goto edit_NA;
        }

    }
    else{
        printf("\n\n\nEnter 1 to go to main menu and 0 to exit:");
        scanf("%d",&main);
        if(main==1)
        {
            menu();
        }
        else{
            close();
        }
    }
}