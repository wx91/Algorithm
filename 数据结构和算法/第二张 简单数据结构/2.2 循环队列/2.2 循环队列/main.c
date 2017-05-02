//
//  main.c
//  2.2 循环队列
//
//  Created by wangx on 2017/5/2.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include <stdio.h>
#include "CycQueue.h"
int num;//顾客编号
//新增顾客排队
void add(CycQueue *q){
    DATA data;
    if (!CycQueueIsFull(q)) {
        data.num=++num;
        data.time = time(NULL);
        CycQueueIn(q, data);
    }else{
        printf("\n排队的人太多了，请稍候在排");
    }
}
//通知下一个顾客准备
void next(CycQueue *q){
    DATA *data;
    //若队列不为空
    if (!CycQueueIsEmpty(q)) {
        data=CycQueueOut(q);
        printf("\n请编号为%d的顾客办理业务!\n",data->num);
    }
    if (!CycQueueIsEmpty(q)) {
        //取队列中指定位置的数据
        data = CycQueuePeek(q);
        printf("请编号为%d的顾客准备，马上将为您办理业务\n",data->num);
    }
}

int main(int argc, const char * argv[]) {
    CycQueue *queue1;
    char select;
    num = 0;
    queue1 =CycQueueInit();
    if (queue1 == NULL) {
        printf("创建队列出错！\n");
        return 0;
    }
    
    printf("\n请选择具体的操作：\n");
    printf("1.新到顾客\n");
    printf("2.下一个顾客\n");
    printf("0.退出\n");
    do {
        fflush(stdin);
        scanf("%c",&select);
        switch (select) {
            case '1':
                add(queue1);
                printf("\n现在共有%d位顾客在等待!\n",CycQueueLen(queue1));
                break;
            case '2':
                next(queue1);
                printf("\n现在共有%d位顾客在等待!\n",CycQueueLen(queue1));
                break;
            case '0':
                break;
            default:
                break;
        }
    } while (select!='0');
    CycQueueFree(queue1);
    
    return 0;
}


