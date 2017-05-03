//
//  SeqStack.h
//  2.3 栈
//
//  Created by wangx on 2017/5/2.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define SIZE 15

typedef struct {
    char name[15];
    int age;
}DATA;
typedef struct {
    //数据元素
    DATA data[SIZE+1];
    int top;//栈顶
}SeqStack;

SeqStack *SeqStackInit();

int SeqStackIsEmpty(SeqStack *s);

void SeqStackFree(SeqStack *s);

void SeqStackClear(SeqStack *s);

int SeqStackIsFull(SeqStack *s);
//入栈
int SeqStackPush(SeqStack *s,DATA data);
//出栈操作
DATA SeqStackPop(SeqStack *s);
//读栈顶数据
DATA SeqStackPeek(SeqStack *s);



