/**
 * @file transact.c
 * @author 260213 (devswarupmohanty@gmail.com)
 * @brief Withdraw or deposit money in account
 * @version 0.1
 * @date 2021-04-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<stdio.h>
#include"transact.h"
#include"database.h"
#include"menu.h"
#include"close.h"
#include<string.h>
void transact (void)
{
    int option,flag = 0,choice=0;
    FILE *ptrold,*ptrnew;
    ptrold = fopen("record.dat","r");
    ptrnew = fopen("new_record.dat","w");

    printf("Enter the account number of the customer: ");
    scanf("%d",&trans.acc_no);
    while (fscanf(ptrold,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if(add.acc_no==trans.acc_no)
        {
            flag = 1;
            if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
            {
                printf("\a\a\a\n\n\nYOU CANNOT DEPOSIT OR WITHDRAW MONEY IN FIXED TYPE ACCOUNTS !!!");
                menu();
            }
            printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
            scanf("%d",&option);
            if(option == 1)
            {
                printf("Enter the amount you want to deposit: Rs.");
                    scanf("%f",&trans.amt);
                    add.amt+=trans.amt;
                    fprintf(ptrnew,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nDeposited successfully!");
                    printf("New Balance is Rs. ",add.amt);
            }
            else
            {
                printf("Enter the amount you want to withdraw: Rs.");
                scanf("%f",&trans.amt);
                if(trans.amt>add.amt)
                {
                    printf("\n\t\t\tCannot be withdrawn due to insufficient balance!!!");

                }
                else
                {
                    add.amt-=trans.amt;
                    fprintf(ptrnew,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nWithdrawn successfully!");
                    printf("\nRemaining balance id Rs. %d",add.amt);
                }
            }

        }
        else
        {
            fprintf(ptrnew,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
        }
    }
    fclose(ptrold);
    fclose(ptrnew);
    remove("record.dat");
    rename("new_record.dat","record.dat");
    if(flag!=1)
    {
        printf("\n\nRecord not found!!");
        trans_inv:
        printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&choice);
        if (choice==0)
        {
            transact();
        }
        else if(choice==1)
        {
            menu();
        }
        else
        {
            printf("\nInvalid choice");
            goto trans_inv;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&choice);
        if(choice==1)
        {
            menu();
        }
        else
        {
            close();
        }
    }

}