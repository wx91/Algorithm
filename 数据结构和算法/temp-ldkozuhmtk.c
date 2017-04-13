//
//  main.c
//  lec01-1-3
//
//  Created by 王享 on 16/4/16.
//  Copyright © 2016年 王享. All rights reserved.
//

#include <stdio.h>
#include <math.h>

#define MAX_SIZE 101
//交换定义为一个宏
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
/*selection sort*/
void sort(int [], int);
int main(int argc, const char * argv[]) {
    int i,n;
    int list[MAX_SIZE];
    printf("Enter the number of numbers to generate:\n");
    scanf("%d",&n);
    if (n<1||n>MAX_SIZE)
    {
        fprintf(stderr,"Improper value of n\n");
        exit(1);
    }
    for (i = 0; i < n; i++)
    {
        list[i] = rand()%1000;
        printf("%d,",list[i]);
    }
    sort(list,n);
    printf("\n Sorted array\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d\n", list[i]);
    }
    printf("\n");
    
    return 0;
}
//选择排序
void sort(int list[],int n){
    int i,j,temp;
    for (i=0; i<n-1; i++) {
        for (j=i+1; j<n; j++) {
            if (list[j]<list[i]) {
                temp = list[i];
                list[i]=list[j];
                list[j]=temp;
            }
        }
    }
}
