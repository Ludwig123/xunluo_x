//
//  xunluo.h
//  xunluo-x
//
//  Created by Ludwig on 11/7/14.
//  Copyright (c) 2014 Ludwig123. All rights reserved.
//

#ifndef xunluo_x_xunluo_h
#define xunluo_x_xunluo_h


#endif


#define standby 0

#define total_times 0
#define total_dayclass_1 1
#define total_dayclass_2 2
#define total_dayclass_3 3

#define total_nightclass 4
#define status 5
#define dayclass_1_limits 6
#define dayclass_2_limits 7
#define dayclass_3_limits 8
#define nightclass_limits 9

//定义 class_type 的宏
#define dayclass_1 2  //上午班
#define dayclass_2 3  //下午班
#define dayclass_3 0  //上半夜班
#define nightclass 1



#define YES 1
#define line 16  //定义条件表的行数
#define row 10    //定义条件表的列数



int choose_team(int);
int change_status(int,int);
int print_array(int xunluo[line][row]);
void print_class(void);

extern int xunluo[line][row];
extern int class_type;