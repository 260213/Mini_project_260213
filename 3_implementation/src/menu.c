/**
 * @file menu.c
 * @author 260213(devswarupmohanty@gmail.com)
 * @brief Contains the list of operation that can be performed by the user
 * @version 0.1
 * @date 2021-04-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include "new_acc.h"
#include"database.h"
#include"edit.h"
#include"transact.h"
#include"close.h"
#include"view_list.h"
#include"erase.h"
#include"see.h"
void menu(void)
{
    
    int option;
    printf("\n\n\t\tCUSTOMER BANK MANAGEMENT SYSTEM");
    printf("\n\n\t\tWELCOME TO THE MAIN PAGE");
    printf("\n\n\t\t1.Create new account\n\t\t2.Update information of existing account\n\t\t3.For transactions\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.View customer's list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&option);

    //system("cls");
    switch(option)
    {
        case 1:
        new_acc();
        break;
        case 2:
        edit();
        break;
        case 3:
        transact();
        break;
        case 4:
        see();
        break;
        case 5:
        erase();
        break;
        case 6:
        view_list();
        break;
        case 7:
        close();
        break;
        
    }
}