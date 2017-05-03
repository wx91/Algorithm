//
//  SeqStack.c
//  2.3 栈
//
//  Created by wangx on 2017/5/2.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include "SeqStack.h"


SeqStack *SeqStackInit(){
    SeqStack *s;
    if ( s = (SeqStack *)malloc(sizeof(SeqStack))) {
        s->top = 0;
        return s;
    }
    return NULL;
}
int SeqStackIsEmpty(SeqStack *s){
    return (s->top == 0);
}
void SeqStackFree(SeqStack *s){
    if (s != NULL) {
        free(s);
    }
}

void SeqStackClear(SeqStack *s){
    s->top = 0;
}
int SeqStackIsFull(SeqStack *s){
    return (s->top == SIZE);
}
//入栈
int SeqStackPush(SeqStack *s,DATA data){
    if ((s->top+1)>SIZE) {
        printf("栈溢出!\n");
        return 0;
    }
    s->data[++s->top] = data;
    return 1;
}
//出栈操作
DATA SeqStackPop(SeqStack *s){
    if (s->top == 0) {
        printf("栈为空!\n");
        exit(0);
    }
    return (s->data[s->top--]);
}
//读栈顶数据
DATA SeqStackPeek(SeqStack *s){
    if (s->top == 0) {
        printf("栈为空!\n");
        exit(0);
    }
    return (s->data[s->top]);
}


