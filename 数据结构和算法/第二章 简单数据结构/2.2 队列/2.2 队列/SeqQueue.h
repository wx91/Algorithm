//
//  SeqQueue.h
//  2.2 队列
//
//  Created by wangx on 2017/5/1.
//  Copyright © 2017年 wangx. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>

#define QUEUEMAX 15
typedef struct {
    
} DATA;

typedef struct {
    DATA data[QUEUEMAX];
    int head;       //队头
    int tail;       //队尾
} SeqQueue;


SeqQueue *SeqQueueInit();
//释放队列
void SeqQueueFree(SeqQueue *q);
int SeqQueueIsEmpty(SeqQueue *q);
int SeqQueueIsFull(SeqQueue *q);
int SeqQueueLen(SeqQueue *q);

//顺序队列入队函数
int SeqQueueIn(SeqQueue *q ,DATA data);

DATA *SeqQueueOut(SeqQueue *q);
//获取对头的元素
DATA *SeqQueuePeek(SeqQueue *q);





