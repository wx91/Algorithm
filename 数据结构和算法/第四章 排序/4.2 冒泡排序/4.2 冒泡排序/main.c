//
//  main.c
//  4.2 冒泡排序
//
//  Created by wangx on 2017/5/25.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include <stdio.h>
#include "CreateData.h"
#define ARRAYLEN 6

void BubbleSort(int a[],int n)
{
    int i,j,t;
    for (i=0; i<n-1; i++) {
        for (j=n-1; j>i; j--) {
            if (a[j-1]>a[j]) {
                t=a[j-1];
                a[j-1]=a[j];
                a[j]=t;
            }
        }
        printf("第%2d遍：",i+1);
        for (j=0; j<n; j++) {
            printf("%d  ",a[j]);
        }
        printf("\n");
    }
}

void BubbleSort1(int a[],int n){
    int i,j,t,flag=0;
    for (i=0; i<n-1; i++) {
        for (j=n-1; j>i; j--) {
            if (a[j-1]>a[j]) {
                t=a[j-1];
                a[j-1]=a[j];
                a[j]=t;
                flag=1;
            }
        }
        printf("第%2d遍：",i+1);
        for (j=0; j<n; j++) {
            printf("%d  ",a[j]);
        }
        printf("\n");
        if (flag==0) {
            break;
        }else{
            flag=0;
        }
    }
}

int main(int argc, const char * argv[]) {
    int i,a[ARRAYLEN];
    for (i=0; i<ARRAYLEN; i++) {
        a[i]=0;
    }
    if (!CreateDate(a, ARRAYLEN, 1, 100)) {
        printf("生成随机数不成功！\n");
        return 1;
    }
    printf("原数据：");
    for (i=0; i<ARRAYLEN; i++) {
        printf("%d  ",a[i]);
    }
    printf("\n");
    BubbleSort(a,ARRAYLEN);
    printf("排序后：");
    for (i=0; i<ARRAYLEN; i++) {
        printf("%d  ",a[i]);
    }
    printf("\n");
    
    
    return 0;
}
