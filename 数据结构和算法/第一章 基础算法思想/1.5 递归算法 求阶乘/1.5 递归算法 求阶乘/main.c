//
//  main.c
//  1.5 递归算法 求阶乘
//
//  Created by wangx on 2017/4/16.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include <stdio.h>
int fact(int n);


int main(int argc, const char * argv[]) {
    int i ;
    printf("请输入要求阶乘的一个整数：");
    scanf("%d",&i);
    printf("%d的阶乘结果为：%d\n",i,fact(i));
    return 0;
}
int fact(int n){
    if (n<=1) {
        return 1;
    }else{
        return n*fact(n-1);
    }
}
