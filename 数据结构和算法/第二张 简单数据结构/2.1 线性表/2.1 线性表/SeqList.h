//
//  SeqList.h
//  2.1 线性表
//
//  Created by wangx on 2017/4/16.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define MAXSIZE 100 //定义线性表的最大长度

typedef struct
{
    char key[15];//节点的关键字
    char name[20];
    int age;
} DATA; //定义节点类型，可以定义为简单类型，也定义为结构

typedef struct
{
    DATA ListData[MAXSIZE+1];   //保存顺序表的数组
    int ListLen;                //顺序表已存节点的数量
} SeqListType ;

//初始化顺序表
void SeqListInit(SeqListType *SL);
//反馈顺序表的元素数量
int SeqListLength(SeqListType *SL);
//向顺序表中添加元素
int SeqListAdd(SeqListType *SL,DATA data);
//向顺序表中插入元素
int SeqListInsert(SeqListType *SL,int n,DATA data);
//删除顺序表中的数据元素
int SeqListDelete(SeqListType *SL,int n);
//根据序号返回元素
DATA *SeqListFindByNum(SeqListType *SL,int n);
//按照关键子查找
int SeqListFindByCont(SeqListType *SL,char *key);
//遍历顺序表中的内容
int SeqListAll(SeqListType *SL);

