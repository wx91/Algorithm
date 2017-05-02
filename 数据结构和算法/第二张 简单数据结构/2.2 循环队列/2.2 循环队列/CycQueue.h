//
//  CycQueue.h
//  2.2 循环队列
//
//  Created by wangx on 2017/5/2.
//  Copyright © 2017年 wangx. All rights reserved.
//




#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUEUEMAX 15

typedef struct {
    int num;//顾客编号
    long time;//进入队列的时间
    
} DATA;

typedef struct {
    DATA data[QUEUEMAX];
    int head;
    int tail;
    
}CycQueue;

CycQueue *CycQueueInit();

void CycQueueFree(CycQueue *q);
int CycQueueIsEmpty(CycQueue *q);
//判断队列是否已满
int CycQueueIsFull(CycQueue *q);
int CycQueueIn(CycQueue *q,DATA data);

DATA *CycQueueOut(CycQueue *q);

int CycQueueLen(CycQueue *q);
DATA *CycQueuePeek(CycQueue *q);

