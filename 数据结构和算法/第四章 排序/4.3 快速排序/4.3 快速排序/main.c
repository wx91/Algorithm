//
//  main.c
//  4.3 快速排序
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

int Division(int a[],int left,int right)
{
    int base = a[left];     //基准元素
    while (left<right){
        while (left<right&&a[right]>base) {
            --right;        //从右向左爪第一个比基准小的元素
        }
        a[left]=a[right];
        while (left<right&&a[left]<base) {
            ++left;         //从左向右爪第一个比基准小的元素
        }
        a[right]=a[left];
    }
    a[left]=base;
    return left;
}

void QuickSort(int a[],int left,int right)
{
    int i;
    if (left<right) {
        i = Division(a, left, right);
        QuickSort(a, left, i-1);
        QuickSort(a, i+1, right);
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
    QuickSort(a, 0, ARRAYLEN-1);
    printf("排序后：");
    for (i=0; i<ARRAYLEN; i++) {
        printf("%d  ",a[i]);
    }
    printf("\n");
    
    
    
    return 0;
}
