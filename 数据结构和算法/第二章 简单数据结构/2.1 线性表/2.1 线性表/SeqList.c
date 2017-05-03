//
//  SeqList.c
//  2.1 线性表
//
//  Created by wangx on 2017/4/16.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include "SeqList.h"

//初始化顺序表
void SeqListInit(SeqListType *SL){
    //初始化时，设置顺序表长度为0
    SL->ListLen = 0;
}
//反馈顺序表的元素数量
int SeqListLength(SeqListType *SL){
    return (SL->ListLen);
}
//向顺序表中添加元素
int SeqListAdd(SeqListType *SL,DATA data){
    if (SL->ListLen>=MAXSIZE) {//顺序表已满
        printf("顺序表已满，不能在添加节点了！\n");
        return 0;
    }
    SL->ListData[++SL->ListLen]=data;
    return 1;
}
//向顺序表中插入元素
int SeqListInsert(SeqListType *SL,int n,DATA data){
    int i;
    if (SL->ListLen>=MAXSIZE) {//顺序表节点数量已超过最大数量
        printf("顺序表已满，不能在添加节点了！");
        return 0;
    }
    if(n<1||n>SL->ListLen-1){//插入节点序号不正确
        printf("插入元素序号错误，不能插入元素了\n");
        return 0;
    }
    //将顺序表中的数据向后移动
    for (i=SL->ListLen; i>=n; i--) {
        SL->ListData[i+1]=SL->ListData[i];
    }
    SL->ListData[n]=data;//插入节点
    SL->ListLen++;  //顺序表节点数量增加1
    return 1;       //返回成功插入。
    
}
//删除顺序表中的数据元素
int SeqListDelete(SeqListType *SL,int n){
    int i;
    if (n<1||n>SL->ListLen+1) {//删除元素序号不正确
        printf("删除节点序号错误，不能删除节点！\n");
        return 0;
    }
    for (i=n; i<SL->ListLen; i++) {//将顺序表中的元素向前移动
        SL->ListData[i]=SL->ListData[i+1];
    }
    SL->ListLen--;
    return 1;
}
//根据序号返回元素
DATA *SeqListFindByNum(SeqListType *SL,int n){
    if (n<1||n>SL->ListLen+1) {//元素序号不正确
        printf("节点序号错误，不能返回节点！\n");
        return NULL;
    }
    return &(SL->ListData[n]);
}
//按照关键字查找
int SeqListFindByCont(SeqListType *SL,char *key){
    int i;
    for (i=1; i<SL->ListLen; i++) {
        if (strcmp(SL->ListData[i].key, key)==0) {//如果找到所需节点
            return i;//返回节点序号
        }
    }
    return 0;//遍历后仍没有找到，则返回0    
}
//遍历顺序表中的内容
int SeqListAll(SeqListType *SL){
    int i;
    for (i=0; i<SL->ListLen; i++) {
        printf("(%s,%s,%d)\n",SL->ListData[i].key,SL->ListData[i].name,SL->ListData[i].age);
    }
    return 1;
}

