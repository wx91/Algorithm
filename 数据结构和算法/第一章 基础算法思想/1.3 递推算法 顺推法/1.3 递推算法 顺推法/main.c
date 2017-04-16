//
//  main.c
//  1.3 递推算法 顺推法
//
//  Created by wangx on 2017/4/15.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include <stdio.h>
#define NUM 13
int main(int argc, const char * argv[]) {
    
    int i;
    long fib[NUM] ={1,1};
    for (i=2; i<NUM; i++) {
        fib[i]=fib[i-1]+fib[i-2];
    }
    for (i=0; i<NUM; i++) {
        printf("%d月兔子综述：%ld\n",i,fib[i]);
    }
    
    return 0;
}
