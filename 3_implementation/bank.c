/**
 * @file bank.c
 * @author 260213 (devswarupmohanty@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include<string.h>
#include"menu.h"
#include"close.h"


void fordelay(int j)
{
    int i,k;
    for(i=0;i<j;i++)
    {
        k=i;
    }
}
int main()
{
    char pass[10],password[10]="123456";
    int i=0,option;
    try:
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s",pass);
    
    if (strcmp(pass,password)==0)
        {printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
            
            menu();
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&option);
            if (option==1)
                    {
                        goto try;
                    }

            else if (option==0)
                    {
                        close();
                    }
            else
                    {
                    printf("\nInvalid!");
                    fordelay(1000000000);
                    
                    goto login_try;
                    }

        }
        return 0;
}