//
//  main.c
//  1.4 枚举法 填数游戏
//
//  Created by wangx on 2017/4/15.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i1,i2,i3,i4,i5;
    long multi,result;
    for (i1=1; i1<=9; i1++) {
        for (i2=0; i2<=9; i2++) {
            for (i3=0; i3<=9; i3++) {
                for (i4=0; i4<=9; i4++) {
                    for (i5=0; i5<=9; i5++) {
                        multi=i1*10000+i2*1000+i3*100+i4*10+i5;
                        result=i5*100000+i5*10000+i5*1000+i5*100+i5*10+i5;
                        if (multi*i1 == result) {
                            printf("\n%5d%2d%2d%2d%2d\n",i1,i2,i3,i4,i5);
                            printf("X%12d\n",i1);
                            printf("_____________\n");
                            printf("%3d%2d%2d%2d%2d%2d\n",i5,i5,i5,i5,i5,i5);
                        }
                    }
                }
            }
        }
    }
    
    
    return 0;
}
