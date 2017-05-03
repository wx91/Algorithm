//
//  ChainList.h
//  2.1 单向链表
//
//  Created by wangx on 2017/4/16.
//  Copyright © 2017年 wangx. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char key[15];       //关键字
    char name[20];
    int age;
} DATA;

typedef struct Node{
    DATA data;
    struct Node *next;
} ChainListType;

//添加节点到链表末尾
ChainListType *ChainListAddEnd(ChainListType *head,DATA data);
//添加节点到链表首部
ChainListType *ChainListAddFirst(ChainListType *head,DATA data);
//插入节点
ChainListType *ChainListInsert(ChainListType *head,char *findkey, DATA data);
//按关键字在链表中查找内容
ChainListType *ChainListFind(ChainListType *head,char *findkey);

//删除指定关键字的节点
int ChainListDelete(ChainListType *head,char *key);
//获取链表节点数量
int ChainListLength(ChainListType *head);
//遍历链表
void ChainListAll(ChainListType *head);


