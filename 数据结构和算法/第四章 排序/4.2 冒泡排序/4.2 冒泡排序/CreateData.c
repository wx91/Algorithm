//
//  CreateData.c
//  4.2 冒泡排序
//
//  Created by wangx on 2017/5/25.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include "CreateData.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int CreateDate(int arr[],int n,int min,int max){
    int i,j,flag;
    srand((unsigned)time(NULL));
    if(max-min+1<n){
        return 0;
    }
    for(i=0;i<n;i++){
        do{
            arr[i]=rand()%max+min;
            flag=0;
            for(j=0;j<i;j++){
                if(arr[i]==arr[j]){
                    flag=1;
                }
            }
        }while(flag);
    }
    return 1;
}
