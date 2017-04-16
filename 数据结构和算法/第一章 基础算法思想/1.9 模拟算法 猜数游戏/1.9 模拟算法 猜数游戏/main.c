//
//  main.c
//  1.9 模拟算法 猜数游戏
//
//  Created by wangx on 2017/4/16.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include <stdio.h>
#include <time.h>
int main(int argc, const char * argv[]) {
    int n,m,i=0;
    n = rand()%100+1;
    do{
        printf("输入所猜数字：");
        scanf("%d",&m);
        i++;
        if (m>n) {
            printf("错误！所猜数太大了！\n");
        }else if(m<n) {
            printf("错误！所猜数太小了！\n");
        }
    }while (m!=n);
    printf("答对了！\n");
    printf("共猜测了%d次。\n",i);
    if (i<=5) {
        printf("你太聪明了，这么快就猜出来了！\n");
    }else if (i>5){
        printf("还需改进方法，以便更快猜出来！\n");
    }
    
    
    return 0;
}
