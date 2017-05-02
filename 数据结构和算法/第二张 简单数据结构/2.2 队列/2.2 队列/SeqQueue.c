//
//  SeqQueue.c
//  2.2 队列
//
//  Created by wangx on 2017/5/1.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include "SeqQueue.h"

SeqQueue *SeqQueueInit(){
    SeqQueue *q;
    if (q==(SeqQueue *)malloc(sizeof(SeqQueue))) {
        q->head = 0;//设置队头
        q->tail = 0;//设置队尾
        return q;
    }else{
        return NULL;//返回空
    }
}
void SeqQueueFree(SeqQueue *q){ //释放队列
    if(q!=NULL){
        free(q);
    }
}
int SeqQueueIsEmpty(SeqQueue *q){
    return (q->head == q->tail);
}
int SeqQueueIsFull(SeqQueue *q){
    return (q->tail == QUEUEMAX);
}
int SeqQueueLen(SeqQueue *q){
    return (q->tail-q->tail);
}
//顺序队列入队函数
int SeqQueueIn(SeqQueue *q ,DATA data){
    if (q->tail == QUEUEMAX) {
        printf("队列已满！\n");
        return 0  ;
    }else{
        q->data[q->tail++]=data;
        return 1;
    }
}

DATA *SeqQueueOut(SeqQueue *q){
    if (q->head == q->tail) {
        printf("\n队列已空!\n");
        return 0;
    }else{
        return &(q->data[q->head++]);
    }
}
//获取对头的元素
DATA *SeqQueuePeek(SeqQueue *q){
    if (SeqQueueIsEmpty(q)) {
        printf("\n队列为空\n");
        return NULL;
    }else{
        return &(q->data[q->head]);
    }
}
