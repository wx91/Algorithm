//
//  main.c
//  1.9 模拟算法 掷骰子
//
//  Created by wangx on 2017/4/16.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include <stdio.h>
#include <time.h>

void play(int n){
    int i,m=0,t=0;
    for (i=0; i<n; i++) {
        t=rand()%6+1;
        m+=t;
        printf("\t第%d粒:%d;\n",i+1,t);
    }
    printf("\t总点数为：%d",m);
}

int main(int argc, const char * argv[]) {
    int c;//参赛的人数
    int n;//骰子的数量
    int i,m;
    do{
        printf("设置骰子数量（输入0退出）:");
        scanf("%d",&m);
        if (n==0) {
            break;//至少一个骰子
        }
        printf("\n输入本轮参数人数（输入0退出）:");
        scanf("%d",&c);
        if (c==0) {
            break;
        }
        for (i=0; i<c; i++) {
            printf("\n第%d位选手掷出的骰子位：\n",i+1);
            play(n);
        }
        printf("\n");
        
    }while (1);
    
    return 0;
}
