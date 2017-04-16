//
//  ChainList.c
//  2.1 单向链表
//
//  Created by wangx on 2017/4/16.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include "ChainList.h"

//添加节点到链表末尾
ChainListType *ChainListAddEnd(ChainListType *head,DATA data){
    ChainListType *node,*h;
    if (!(node=(ChainListType *)malloc(sizeof(ChainListType)))) {
        printf("为保存节点数据申请内存失败！\n");
        return NULL;        //分配内存失败
    }
    node->data = data;//保存数据
    node->next = NULL;//设置及节点指针为空，即为表尾
    if (head == NULL) {//是头指针
        head=node;
        return head;
    }
    h=head;
    while (h->next != NULL) {//查询链表的末尾
        h=h->next;
    }
    h->next=node;
    return head;
}
//添加节点到链表首部
ChainListType *ChainListAddFirst(ChainListType *head,DATA data){
    ChainListType *node;
    if (!(node=(ChainListType *)malloc(sizeof(ChainListType)))) {
        printf("为保存节点数据申请内存失败！\n");
        return NULL;        //分配内存失败
    }
    node->data=data; //保存数据
    node->next = head;//指向头指针所指即诶单
    head=node;//头指针指向新增节点
    return head;
}
//插入节点
ChainListType *ChainListInsert(ChainListType *head,char *findkey, DATA data){
    ChainListType *node,*node1;
    if (!(node=(ChainListType *)malloc(sizeof(ChainListType)))) {
        printf("为保存节点数据申请内存失败！\n");
        return NULL;        //分配内存失败
    }
    node->data = data;
    node1 = ChainListFind(head,findkey);
    if (node1) {//若找到要插入的即诶单
        node->next=node1->next;
        node1->next = node;
    }else{
        free(node);//释放内存
        printf("未找到节点位置!\n");
    }
    return head;
}

//按关键字在链表中查找内容
ChainListType *ChainListFind(ChainListType *head,char *key){
    ChainListType *h;
    h=head;//保存链表的头指针
    while (h){//若即诶单有效，则进行查找
        if(strcmp(h->data.key, key) ==0){//若节点关键字与传入关键字相同
            return h;//返回该节点指针
        }
        h=h->next;//处理下一个节点
    }
    return NULL;
    
}

//删除指定关键字的节点
int ChainListDelete(ChainListType *head,char *key){
    ChainListType *node,*h;
    node = h = head;
    while (h) {
         if(strcmp(h->data.key, key) ==0){//若节点关键字与传入关键字相同
             node->next = h->next;//使前一个节点指向当前节点的下一个节点
             free(h);//释放内存
             return 1;
         }else{
             node=h;//指向当前节点
             h=h->next;//指向下一个节点
         }
    }
    return 0;//未删除
}
//获取链表节点数量
int ChainListLength(ChainListType *head){
    ChainListType *h;
    int i = 0;
    h=head;
    while (h) {     //遍历整个链表
        i++;        //累加节点数量
        h=h->next;  //处理下一个节点
    }
    return i;       //返回节点数量
}
//遍历链表
void ChainListAll(ChainListType *head){
    ChainListType *h;
    DATA data;
    h = head;
    printf("链表所有数据如下：\n");
    while (h) { //循环处理链表每个节点
        data = h->data;//获取节点数据
        printf("(%s,%s,%d)\n",data.key,data.name,data.age);
        h=h->next;
    }
    return ;
}
