/**
 * @file erase.c
 * @author 260213 (devswarupmohanty@gmail.com)
 * @brief erases a record
 * @version 0.1
 * @date 2021-04-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<stdio.h>
#include"erase.h"
#include"database.h"
#include"close.h"
#include"menu.h"

void erase()
{
    FILE *ptrold,*ptrnew;
    int flag=0,option;
    ptrold=fopen("record.dat","r");
    ptrnew=fopen("new_rec.dat","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(ptrold,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(ptrnew,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {flag++;
            printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(ptrold);
   fclose(ptrnew);
   remove("record.dat");
   rename("new_rec.dat","record.dat");
   if(flag==0)
        {
            printf("\nRecord not available!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&option);

                 if (option==1)
                    menu();
                else if (option==2)
                    close();
                else if(option==0)
                    erase();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&option);
        
        if (option==1)
            menu();
        else
            close();
        }

}
