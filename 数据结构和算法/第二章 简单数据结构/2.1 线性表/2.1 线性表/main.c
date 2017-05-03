//
//  main.c
//  2.1 线性表
//
//  Created by wangx on 2017/4/16.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include <stdio.h>
#include "SeqList.h"

int main(int argc, const char * argv[]) {
    int i;
    SeqListType SL;     //定义顺序表变量
    DATA data,*data1;    //定义节点保存类型变量和指针变量
    char key[15];       //保存关键字
    
    SeqListInit(&SL);   //初始化顺序表
    do {
        printf("请输入添加的节点（学号  姓名  年龄）：");
        fflush(stdin);
        scanf("%s%s%d",data.key,data.name,&data.age);
        if (data.age) {
            if (!SeqListAdd(&SL, data)) {
                break;
            }
        }else{
            break;
        }
        
    } while (1);
    printf("\n顺序表中的节点顺序为：\n");
    SeqListAll(&SL);//显示所有节点数
    
    fflush(stdin);//清空输入缓冲区
    printf("\n要取出即节点的序号：");
    scanf("%d",&i);     //输入节点序号
    data1=SeqListFindByNum(&SL, i);     //按序号查找节点
    if(data1){
        printf("第%d个节点为:(%s%s%d)\n",i,data1->key,data1->name,data1->age);
    }
    fflush(stdin);//清空输入缓冲区
    printf("\n要查找节点的关键字：");
    scanf("%s",key);     //输入节点序号
    i=SeqListFindByCont(&SL, key);     //按关键字查找节点
    data1 = SeqListFindByNum(&SL, i);
    if(data1){      //若返回的不为NULL
        printf("第%d个节点为:(%s%s%d)\n",i,data1->key,data1->name,data1->age);
    }
    
    
    return 0;
}
