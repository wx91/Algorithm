//
//  main.c
//  4.5 堆排序
//
//  Created by wangx on 2017/5/26.
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
//构成堆
void HeadAdjust(int a[],int s,int n)
{
    int j = 0,t;
    //第s个节点有右子树
    while (2*s+1<n) {
        if ((j+1)<n) {
            if (a[j]<a[j+1]) {//左子树小于右子树，则需要比较右子树
                j++;//序号增加1，指向右子树
            }
        }
        if (a[s]<a[j]) {//比较s与j为序号的数据
            t=a[s];//交换数据
            a[s]=a[j];
            a[j]=t;
            s=j;//堆被破环，需要重新调整
        }
        else //比较左右孩子均大雨则堆破环，不在需要调整
            break;
    }
}

void HeadSort(int a[],int n)
{
    int t,i;
    for (i=n/2-1; i>=0; i--) {
        HeadAdjust(a, i, n);
    }
    for (i=n-1; i>0; i--) {
        t=a[0];
        a[0]=a[i];
        a[i]=t;
        HeadAdjust(a, 0, i);
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
    HeadSort(a, ARRAYLEN);
    printf("排序后：");
    for (i=0; i<ARRAYLEN; i++) {
        printf("%d  ",a[i]);
    }
    printf("\n");
    return 0;
    return 0;
}
