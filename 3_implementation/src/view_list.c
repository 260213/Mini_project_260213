/**
 * @file view_list.c
 * @author 260213 (devswarupmohanty@gmail.com)
 * @brief Function displays all the recorded data
 * @version 0.1
 * @date 2021-04-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>

#include<string.h>
#include"database.h"
#include"close.h"
#include"menu.h"
void view_list()
{
    FILE *list;
    list = fopen("record.dat","r");
    int flag = 0,option;
    printf("\nACCOUNT NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

    while(fscanf(list,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF);
    {
        printf("\n%6d\t%10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
        flag++;
    }
    fclose(list);
    if(flag==0)
    {
        printf("\nERROR!!\n");
    }

    view_inv:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    
    scanf("%d",&option);
    if(option==1)
    {
        menu();
    }
    else if(option==0)
    {
        close();
    }
    else{
        printf("\nInvalid\n");
        goto view_inv;
    }
}