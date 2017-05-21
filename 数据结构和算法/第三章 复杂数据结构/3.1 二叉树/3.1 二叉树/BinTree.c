//
//  BinTree.c
//  3.1 二叉树
//
//  Created by wangx on 2017/5/18.
//  Copyright © 2017年 wangx. All rights reserved.
//
#include "BinTree.h"
#include <stdio.h>
#include <stdlib.h>

//初始化二叉树根节点
ChainBinTree *BinTreeInit(ChainBinTree *node)
{
    //若二叉树节点不为空
    if (node!=NULL) {
        return node;
    }else{
        return NULL;
    }
}
//bt为父节点，node为子节点，n=1表示添加左子树，n=2表示右子树
int BinTreeAddNode(ChainBinTree *bt,ChainBinTree *node,int n)
{
    if(bt == NULL){
        printf("父节点不存在，请先设置父节点!\n");
        return 0;
    }
    if (n==1) {//添加左结点
        if (bt->left) {
            printf("左子树结点不为空!\n");
            return 0;
        }else{
            bt->left=node;
        }
    }else if (n==2){
        if (bt->right) {
            printf("右子树结点不为空!\n");
            return 0;
        }else{
            bt->right=node;
        }
    }else{
        printf("参数错误！\n");
        return 0;
    }
    return 0;
}
ChainBinTree *BinTreeLeft(ChainBinTree *bt)
{
    if (bt) {
        return bt->left;
    }else{
        return NULL;
    }
}
ChainBinTree *BinTreeRight(ChainBinTree *bt){
    if (bt) {
        return bt->right;
    }else{
        return NULL;
    }
}
//检查二叉树是否为空，为空则返回1 否则返回0
int BinTreeIsEmpty(ChainBinTree *bt){
    if (bt) {
        return 0;
    }else{
        return 1;
    }
}
//求二叉树的深度
int BinTreeDept(ChainBinTree *bt){
    int dep1,dep2;
    if (bt==NULL) {
        return 0;
    }else{
        dep1 = BinTreeDept(bt->left);
        dep2 = BinTreeDept(bt->right);
        if (dep1>dep2) {
            return dep1+1;
        }else{
            return dep2+1;
        }
    }
}
//在二叉树中查找值为data的结点
ChainBinTree *BinTreeFind(ChainBinTree *bt,DATA data){
    ChainBinTree *p;
    if (bt == NULL) {
        return NULL;
    }else{
        if (bt->data == data) {
            return bt;
        }else{//分别向左右子树递归查找
            if ((p=BinTreeFind(bt->left, data))) {
                return p;
            }else if ((p=BinTreeFind(bt->right, data))){
                return p;
            }else{
                return NULL;
            }
        }
    }
}
void BinTreeClear(ChainBinTree *bt){
    if (bt) {
        BinTreeClear(bt->left);
        BinTreeClear(bt->right);
        free(bt);
        bt = NULL;
    }
    return;
}
//先序遍历
void BinTree_DLR(ChainBinTree *bt,void (*oper)(ChainBinTree *)){
    if (bt) {
        oper(bt);
        BinTree_DLR(bt->left, oper);
        BinTree_DLR(bt->right, oper);
    }
    return ;
}
//中序遍历
void BinTree_LDR(ChainBinTree *bt,void (*oper)(ChainBinTree *)){
    if (bt) {
        BinTree_LDR(bt->left, oper);
        oper(bt);//处理结点数据
        BinTree_LDR(bt->right, oper);
    }
}
void BinTree_LRD(ChainBinTree *bt,void (*oper)(ChainBinTree *)){
    if (bt) {
        BinTree_LRD(bt, oper);
        BinTree_LRD(bt, oper);
        oper(bt);
    }
    return;
}

void BinTree_Level(ChainBinTree *bt ,void (*oper)(ChainBinTree *)){
    ChainBinTree *p;
    ChainBinTree *q[QUEUE_MAXSIZE];
    int head = 0,tail=0;
    if (bt) {
        tail =(tail+1)%QUEUE_MAXSIZE;
        q[tail] = bt;
    }
    while (head !=tail) {
        head = (head+1)%QUEUE_MAXSIZE;//计算循环队列的队首序号
        p=q[head];//获取首元素
        oper(p);//处理首元素
        if (p->left!=NULL) {
            //计算循环队列的队尾序号
            tail = (tail+1)%QUEUE_MAXSIZE;
            //将左子树指针进队
            q[tail] = p->left;
        }
        if (p->right!=NULL) {
            //计算循环队列的队尾序号
            tail = (tail+1)%QUEUE_MAXSIZE;
            //将右子树指针进队
            q[tail] = p->right;
        }
    }
    return ;
}


