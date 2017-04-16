//
//  main.c
//  1.3 递推算法 逆推法
//
//  Created by wangx on 2017/4/15.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include <stdio.h>
#define FETCH 1000
#define RATE 0.0171

int main(int argc, const char * argv[]) {
    double corpus[49];
    int i;
    corpus[48]=(double)FETCH;
    for (i=47; i>0;i--) {
        corpus[i]=(corpus[i+1]+FETCH)/(1+RATE/12);
    }
    for (i=48; i>0; i--) {
        printf("第%d月末本息合计：%.2f",i,corpus[i]);
    }
    return 0;
}
