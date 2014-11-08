//
//  main.c
//  xunluo-x
//
//  Created by Ludwig on 14-9-30.
//  Copyright (c) 2014年 Ludwig123. All rights reserved.
//

#include <stdio.h>
#include "xunluo.h"





int xunluo[line][row]={
{0,0,0,0,0,0,7,7,7,7},   /*total*/
{0,0,0,0,0,0,0,0,0,0},    /*xunluo_12  卢银初*/
{0,0,0,0,0,0,1,0,0,1},    /*xunluo_13  刘辉辉*/
{0,0,0,0,0,0,1,0,0,1},    /*xunluo_14  周彬*/
{0,0,0,0,0,0,1,0,0,0},    /*xunluo_15  张金华*/
    
{0,0,0,0,0,0,0,0,0,1},    /*xunluo_1  华振勋*/
{0,0,0,0,0,0,0,0,5,1},    /*xunluo_2  胡现龙*/
{0,0,0,0,0,0,0,0,5,1},    /*xunluo_3  金权*/
{0,0,0,0,0,0,0,0,5,1},    /*xunluo_4  方健*/
{0,0,0,0,0,0,5,0,0,1},    /*xunluo_5  杨振*/
{0,0,0,0,0,0,4,0,0,2},    /*xunluo_6  贺靖*/
    
{0,0,0,0,0,0,3,0,0,1},    /*xunluo_7  凌春伟*/
{0,0,0,0,0,0,3,0,0,1},    /*xunluo_8  李锋*/
{0,0,0,0,0,0,3,0,0,1},    /*xunluo_9  孙苏恒*/
    
{0,0,0,0,0,0,1,0,0,1},    /*xunluo_10  姚晓峰*/
{0,0,0,0,0,0,1,0,0,1},    /*xunluo_11  谭蜀湘*/
};

int class_type; //1是凌晨班，2是上午班，3是下午班，0是上班夜班



int main(void)
{
	   //初始化二维数组
    
    /****************************************************************************
 *total_times total_dayclass_1/_2/_3 total_nightclass status dayclass_1_limits dayclass_2_limits dayclass_3_limits  nightclass_limits
* total
* xunluo_1    0        1/2/3                  4          5            6                7                   8       9           
* xunluo_2
* xunluo_3
* xunluo_4
* xunluo_5
*
     *****************************************************************************/
    /*初始化表格*/
    /*总共42个白班，14个凌晨班*/
    
    int count_1 = 0;
    for(int i=1;i<line; i++)
        count_1 = count_1 + xunluo[i][dayclass_1_limits] + xunluo[i][dayclass_2_limits] + xunluo[i][dayclass_3_limits];
    printf("now the dayclass is%d\n",count_1);//显示当前白班数
    
    int count_2 = 0;
    for(int i = 1; i < line;i++)
        count_2 += xunluo[i][nightclass_limits];
    printf("now the nightclass is%d\n",count_2);//显示当前凌晨班数
/***********************************************/
    
    int sch[56]={0};//记录班表顺序
    int j=0;
    
    for(int list = 0; list < 28;list++ ){
     
        class_type = (list % 4) == 0 ; //判断是什么班次
        int i = 1;
        for( ; choose_team(i) != YES ;i++ )  //查看第一个有空的人
            ;
        printf("%d\n",change_status(i,list)); //显示改变状态是否成功
         sch[j++]=i;
        
        for( ; choose_team(i) != YES ;i++ )  //查看第二个有空的人
            ;
        printf("%d\n",change_status(i,list)); //显示改变状态是否成功
        sch[j++]=i;             //记录班表顺序
        print_class();

    }
    
    
    for(int i = 0;i<60;i++)//打印班表
    {printf("%.4d",sch[i]);
        if(i%8 == 7)
            printf("\n");
            }
    
    getchar();
    
}



