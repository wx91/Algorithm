//
//  main.c
//  4.7 希尔排序
//
//  Created by wangx on 2017/5/26.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAYLEN 7

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
void ShellSort(int a[],int n)
{
    int d,i,j,x;
    d=n/2;
    while (d>=1) {//循环至增量为1时结束
        for (i=d; i<n; i++) {
            x=a[i];//获取序列中的下一个数据
            j=i-d;//获取序列前一个数据的序号
            while (j>=0&&a[j]>x) {//下一个数据大于前一个数
                a[j+d]=a[j];//将后一个数相前移动
                j=j-d;//修改序号，继续向前比较
            }
            a[j+d]=x;//保留数据
        }
        d/=2;//缩小增量
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
    ShellSort(a, ARRAYLEN);
    printf("排序后：");
    for (i=0; i<ARRAYLEN; i++) {
        printf("%d  ",a[i]);
    }
    printf("\n");
    return 0;
    return 0;
}
