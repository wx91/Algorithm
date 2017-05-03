//
//  CycQueue.c
//  2.2 循环队列
//
//  Created by wangx on 2017/5/2.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include "CycQueue.h"

CycQueue *CycQueueInit(){
    CycQueue *q;
    //申请保存队列的内存
    if (q=(CycQueue *)malloc(sizeof(CycQueue))) {
        //设置队头
        q->head = 0;
        //设置队尾
        q->tail = 0;
        return q;
    }else{
        return NULL;
    }
}

void CycQueueFree(CycQueue *q){
    if(q!=NULL){
        free(q);
    }
}
int CycQueueIsEmpty(CycQueue *q){
    return (q->head == q->tail);
}
//判断队列是否已满
int CycQueueIsFull(CycQueue *q){
    return ((q->tail+1)%QUEUEMAX==q->head);
}
int CycQueueIn(CycQueue *q,DATA data){
    if ((q->tail+1)%QUEUEMAX == q->tail) {
        printf("队列已满\n");
        return 0;
    }else{
        //求列尾序号
        q->tail =(q->tail+1)%QUEUEMAX;
        q->data[q->tail]=data;
        return 1;
    }
}

DATA *CycQueueOut(CycQueue *q){
    if (q->head ==q->tail) {
        printf("队列已空！\n");
        return NULL;
    }else{
        q->head =((q->head+1)%QUEUEMAX);
        return &(q->data[q->head]);
    }
}

int CycQueueLen(CycQueue *q){
    int n ;
    n=q->tail-q->head;
    if (n<0) {
        n=QUEUEMAX+n;
    }
    return n;
}
DATA *CycQueuePeek(CycQueue *q){
    if (q->head == q->tail) {
        printf("队列已经为空!\n");
        return NULL;
    }else{
        return &(q->data[(q->head+1)%QUEUEMAX]);
    }
}




