//
//  main.c
//  xunluo-x
//
//  Created by Ludwig on 14-9-30.
//  Copyright (c) 2014年 Ludwig123. All rights reserved.
//

#include <stdio.h>

#define standby 0

#define total_times 0
#define total_dayclass 1
#define total_nightclass 2
#define status 3
#define dayclass_limits 4
#define nightclass_limits 5
#define YES 1
#define line 16
#define row 6


int choose_team(int);
int change_status(int,int);
int print_array(int xun[16][6]);
void print_class(void);

int xunluo[line][row]={
{0,0,0,0,21,7},   /*total*/
{0,0,0,0,0,0},    /*xunluo_12  卢银初*/
{0,0,0,0,1,1},    /*xunluo_13  刘辉辉*/
{0,0,0,0,1,1},    /*xunluo_14  周彬*/
{0,0,0,0,1,0},    /*xunluo_15  张金华*/
    
{0,0,0,0,4,1},    /*xunluo_1  华振勋*/
{0,0,0,0,5,1},    /*xunluo_2  胡现龙*/
{0,0,0,0,5,1},    /*xunluo_3  金权*/
{0,0,0,0,5,1},    /*xunluo_4  方健*/
{0,0,0,0,5,1},    /*xunluo_5  杨振*/
{0,0,0,0,4,2},    /*xunluo_6  贺靖*/
    
{0,0,0,0,3,1},    /*xunluo_7  凌春伟*/
{0,0,0,0,3,1},    /*xunluo_8  李锋*/
{0,0,0,0,3,1},    /*xunluo_9  孙苏恒*/
    
{0,0,0,0,1,1},    /*xunluo_10  姚晓峰*/
{0,0,0,0,1,1},    /*xunluo_11  谭蜀湘*/
    

};
int class_type;



int main(void)
{
	   //初始化二维数组
    
    /****************************************************************************
     *              total_times    total_dayclass    total_nightclass    status    dayclass_limits   nightclass_limits
     * total
     * xunluo_1       0                  0                0                 0              6                   2
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
        count_1 +=xunluo[i][dayclass_limits];
    printf("now the dayclass is%d\n",count_1);//显示当前白班数
    
    int count_2 = 0;
    for(int i = 1; i < line;i++)
        count_2 += xunluo[i][nightclass_limits];
    printf("now the nightclass is%d\n",count_2);//显示当前凌晨班数
/***********************************************/
    
    int sch[56]={0};//记录班表顺序
    int j=0;
    
    for(int list = 0; list < 28;list++ ){
     
        class_type = ((list % 4) == 0) ? total_nightclass : total_dayclass ; //判断是白班还是凌晨班
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


void print_class(void)
{

    for(int i=0;i < line; i++){
        for(int j = 0; j < row; j++)
            printf("%d\t",xunluo[i][j]);
        printf("\n");
    }
}

int change_status(int i,int list)
{
    list = list % 4;
    xunluo[i][status] = (4 - list);//改变需要休息的时间
    xunluo[i][total_times]++;  //该小组的上班总次数加一
    xunluo[0][total_times]++;  //全局统计一栏的总班次加一
   
    for(int j = 1 ;j < line; j++)
        xunluo[j][status]--;//所有班次的休息时间减1

        
        if(list == 0)//如果是凌晨班
        {
            xunluo[i][total_nightclass]++;
            xunluo[0][total_nightclass]++;
            xunluo[i][status]++; //防止同一个班组连续上两个凌晨班
        }
        else {
            xunluo[i][total_dayclass]++;
            xunluo[0][total_dayclass]++;
        }
    return 1;       //成功！
    
}

int choose_team(int man)  //选取班组
{
          if (xunluo[man][status] > standby)  //第一步，查看是否待命，不待命，直接排除，选出执勤的人员
              return -1;
    else if (class_type == total_dayclass && xunluo[man][total_dayclass] < xunluo[man][dayclass_limits] )
        return 1;//如果是白班，且白班还没上满
    else if (class_type == total_nightclass && xunluo[man][total_nightclass] < xunluo[man][nightclass_limits] )
        return 1;//如果是晚班，且晚班还没上满
    else {
        printf("糟糕，%d班不能上白班和晚班啊！\n",man);
           return -1;
         }
}


int a,b;
int print_array(int xun[a][b])
{
    int i,j;
    for(i = 0;i < a;i++){
        for(i = 0;j < b;j++)
            printf("%d\t",xun[i][j]);
        printf("\n");}
    return 0;
    }