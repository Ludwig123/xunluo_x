//
//  check.c
//  xunluo-x
//
//  Created by Ludwig on 11/7/14.
//  Copyright (c) 2014 Ludwig123. All rights reserved.
//

#include <stdio.h>
#include "xunluo.h"




int choose_team(int man)  //选取班组
{
    if (xunluo[man][status] > standby)  //第一步，查看是否待命，不待命，直接排除，选出执勤的人员
        return -1;
    else if (class_type == dayclass_1 && xunluo[man][total_dayclass_1] < xunluo[man][dayclass_1_limits] )
        return 1;//如果是上午班，且还没上满
    else if (class_type == dayclass_2 && xunluo[man][total_dayclass_2] < xunluo[man][dayclass_2_limits] )
        return 1;//如果是下午班，且还没上满
    else if (class_type == dayclass_3 && xunluo[man][total_dayclass_3] < xunluo[man][dayclass_3_limits] )
        return 1;//如果是上半夜，且还没上满
    else if (class_type == nightclass && xunluo[man][total_nightclass] < xunluo[man][nightclass_limits] )
        return 1;//如果是晚班，且晚班还没上满
    else {
        printf("糟糕，%d班不能上白班和晚班啊！\n",man);
        return -1;
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


