//
//  main.c
//  1.7 贪婪算法 找零钱
//
//  Created by wangx on 2017/4/16.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include <stdio.h>
#define MAXN 9
int parvalue[MAXN]={10000,5000,1000,500,200,100,50,20,10};
int num[MAXN]={0};
int exchange(int n){
    int i;
    for (i=0; i<MAXN; i++) {
        if (n>parvalue[i]) {//找到比n小的最大面额
            break;
        }
    }
    while (n>0&&i<MAXN) {
        if (n>=parvalue[i]) {
            n-=parvalue[i];
            num[i]++;
        }else if (n<10&&n>5){
            num[MAXN-1]++;
            break;
        }else{
            i++;
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    int i;
    float m;
    printf("请输入找零的金额：");
    scanf("%f",&m);
    exchange((int)100*m);
    printf("\n%.2f元找零的组成:\n",m);
    for (i=0; i<MAXN; i++) {
        if (num[i]>0) {
            printf("%6.2f:  %d张\n",(float)parvalue[i]/100,num[i]);
        }
    }
    
    
    return 0;
}
