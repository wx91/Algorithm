//
//  main.c
//  2.3 栈
//
//  Created by wangx on 2017/5/2.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include <stdio.h>
#include "SeqStack.h"

#define SIZE 50

int main(int argc, const char * argv[]) {
    
    SeqStack *stack;
    DATA data,data1;
    stack = SeqStackInit();
    printf("入栈操作:\n");
    printf("请输入姓名 年龄进行入栈操作:");
    scanf("%s%d",data.name,&data.age);
    SeqStackPush(stack, data);
    printf("请输入姓名 年龄进行入栈操作:");
    scanf("%s%d",data.name,&data.age);
    SeqStackPush(stack, data);
    printf("\n出栈操作：\n按任意键进行出栈操作：");
    getchar();
    data1= SeqStackPop(stack);
    printf("出栈的数据是(%s,%d)\n",data1.name,data1.age);
    printf("再按任意键进行出栈操作:");
    getchar();
    data1 = SeqStackPop(stack);
    printf("出栈的数据是(%s,%d)\n",data1.name,data1.age);
    SeqStackFree(stack);
    
}
