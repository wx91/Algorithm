//
//  main.c
//  1.2 二分法
//
//  Created by wangx on 2017/4/15.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int oldprice,price = 0,i=0;
    printf("请首先设置商品的真实价格：");
    scanf("%d",&oldprice);
    printf("请输入试猜的价格：\n");
    while (oldprice != price) {
        i++;
        printf("参与者:");
        scanf("%d",&price);
        printf("主持人:");
        if (price>oldprice) {
            printf("高了\n");
        }else if (price<oldprice){
            printf("低了\n");
        }else{
            printf("恭喜你，答对了，该商品属于你了！\n\n你一共试猜了%d次\n",i);
        }
    }
    return 0;
}
