//
//  print.c
//  xunluo-x
//
//  Created by Ludwig on 11/7/14.
//  Copyright (c) 2014 Ludwig123. All rights reserved.
//

#include <stdio.h>
#include "xunluo.h"


void print_class(void)
{
    
    for(int i=0;i < line; i++){
        for(int j = 0; j < row; j++)
            printf("%d\t",xunluo[i][j]);
        printf("\n");
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