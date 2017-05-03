//
//  main.c
//  2.3 栈算数表达式
//
//  Created by wangx on 2017/5/3.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "SeqStack.h"
#define SIZE 50;

//检查字符是否为运算符
int IsOperator(char c){
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
        case '=':
            return 1;
            break;
        default:
            return 0;
            break;
    }
}
//判断两个运算符夫人优先级
int PRI(char oper1,char oper2){
    //oper1>oper2 返回1
    //oper1<oper2 返回-1
    //oper1=oper2 返回0
    int pri = 0;
    switch (oper2) {
        case '+':
        case '-':
            if (oper1=='('||oper1=='=') {
                return -1;
            }else{
                pri=1;
            }
            break;
        case '*':
        case '/':
            if (oper1=='*'||oper1=='/'||oper1==')') {
                pri = 1;
            }else{
                return -1;
            }
            break;
        case '(':
            if (oper1 ==')') {//右括号的右侧不能立马出现左括号
                printf("语法错误!\n");
                exit(0);
            }else{
                pri=-1;
            }
            break;
        case ')':
            if (oper1=='(') {
                pri=0;
            }else if (oper1=='='){
                printf("括号不匹配!\n");
                exit(0);
            }else{
                pri=1;
            }
            break;
        case '=':
            if (oper1=='(') {
                printf("括号不匹配!\n");
                exit(0);
            }else if (oper1=='='){
                pri=0;
            }else{
                pri=1;
            }
            break;
    }
    return pri;
}


int Calc(int a,int oper,int b){
    if (oper == '+') {
        return a+b;
    }else if(oper=='-'){
        return a-b;
    }else if (oper=='*'){
        return a*b;
    }else{
        if (b!=0) {
            return a/b;
        }else{
            printf("除以0溢出!\n");
            exit(0);
        }
    }
}

int CalcExp(char exp[]){
    SeqStack *stackOper,*stackData;
    int i = 0,flag=0;
    DATA a,b,c,q,x,t,oper;
    stackOper = SeqStackInit();
    stackData = SeqStackInit();
    q=0;
    x='=';
    //首先将等号(=)进入操作符栈
    SeqStackPush(stackOper, x);
    x=SeqStackPeek(stackOper);
    c=exp[i++];
    while (c!='='||x!='=') {
        //若输入的是运算法
        if (IsOperator(c)) {
            if (flag) {
                //将操作数入栈
                SeqStackPush(stackData, q);
                q=0;
                flag=0;
            }
            switch (PRI(x, c)) {
                case -1:
                    //运算符进栈
                    SeqStackPush(stackOper, c);
                    c=exp[i++];
                    break;
                case 0:
                    //运算符出栈
                    c=SeqStackPop(stackOper);
                    c=exp[i++];
                    break;
                case 1:
                    oper =SeqStackPop(stackOper);
                    b=SeqStackPop(stackData);//两个操纵数出栈
                    a=SeqStackPop(stackData);
                    t=Calc(a, oper, b);
                    SeqStackPush(stackData, t);//将运算结果入栈
                    break;
            }
        }else if (c>='0'&&c<='9'){
            c-='0';
            q=q*10+c;
            c=exp[i++];
            flag=1;
        }else{
            printf("输入错误!\n");
            exit(0);
        }
        //取栈顶的运算符
        x=SeqStackPeek(stackOper);
    }
    q=SeqStackPop(stackData);
    SeqStackFree(stackOper);
    SeqStackFree(stackData);
    return q;
}


int main(int argc, const char * argv[]) {
    char exp[80];
    printf("请输入要计算的表达式（以=结束）");
    scanf("%s",exp);
    printf("%s%d\n",exp,CalcExp(exp));
    
    return 0;
}
