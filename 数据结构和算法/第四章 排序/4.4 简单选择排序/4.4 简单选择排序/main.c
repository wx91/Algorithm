//
//  main.c
//  4.4 简单选择排序
//
//  Created by wangx on 2017/5/25.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAYLEN 6

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

void SelectSort(int a[],int n)
{
    int i,j,t,k;
    for (i=0; i<n-1; i++) {
        k=i;
        for (j=i+1; j<n; j++) {
            if (a[k]>a[j]) {
                k=j;
            }
            t=a[i];
            a[i]=a[k];
            a[k]=t;
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
    SelectSort(a, ARRAYLEN);
    printf("排序后：");
    for (i=0; i<ARRAYLEN; i++) {
        printf("%d  ",a[i]);
    }
    printf("\n");
    return 0;
}
