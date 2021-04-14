/**
 * @file interest.c
 * @author 260213 (devswarupmohanty@gmail.com)
 * @brief Calculate the amount you will get in your fixed deposit account
 * @version 0.1
 * @date 2021-04-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include<stdio.h>
#include"interest.h"

float interest(float t,float amt,int rate)
{
    float SI;
    SI = (rate*t*amt)/100.0;
    return (SI);
}