//
//  ThreadBinTree.c
//  3.1 线索树
//
//  Created by wangx on 2017/5/20.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include "ThreadBinTree.h"
//前驱节点指针
ThreadBinTree *Previous = NULL;
//初始化二叉树节点
ThreadBinTree *BinTreeInit(ThreadBinTree *node)
{
    if(node!=NULL){
        return node;
    }else{
        return NULL;
    }
}
//添加数据到二叉树
int BinTreeAddNode(ThreadBinTree *bt,ThreadBinTree *node,int n)
{
    if(bt == NULL){
        printf("父节点不存在，请先设置父节点");
        return 0;
    }
    if (n==1) {
        if (bt->left) {
            printf("左子树节点不为空！\n");
            return 0;
        }else{
            bt->left=node;
        }
    }else if (n==2){
        if (bt->right) {
            printf("右子树节点不为空！\n");
            return 0;
        }else{
            bt->right=node;
        }
    }else{
        printf("参数错误!\n");
        return 0;
    }
    return 1;
}
ThreadBinTree *BinTreeLeft(ThreadBinTree *bt)
{
    if (bt) {
        return bt->left;
    }else{
        return NULL;
    }
}
ThreadBinTree *BinTreeRight(ThreadBinTree *bt){
    if (bt) {
        return bt->right;
    }else{
        return NULL;
    }
}
//检查二叉树是否为空，为空则返回1 否则返回0
int BinTreeIsEmpty(ThreadBinTree *bt){
    if (bt) {
        return 0;
    }else{
        return 1;
    }
}
//求二叉树的深度
int BinTreeDept(ThreadBinTree *bt){
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
ThreadBinTree *BinTreeFind(ThreadBinTree *bt,DATA data){
    ThreadBinTree *p;
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

void BinTreeClear(ThreadBinTree *bt){
    if (bt) {
        BinTreeClear(bt->left);
        BinTreeClear(bt->right);
        free(bt);
        bt = NULL;
    }
    return;
}

//先序遍历
void BinTree_DLR(ThreadBinTree *bt,void (*oper)(ThreadBinTree *)){
    if (bt) {
        oper(bt);
        BinTree_DLR(bt->left, oper);
        BinTree_DLR(bt->right, oper);
    }
    return ;
}
//中序遍历
void BinTree_LDR(ThreadBinTree *bt,void (*oper)(ThreadBinTree *)){
    if (bt) {
        BinTree_LDR(bt->left, oper);
        oper(bt);//处理结点数据
        BinTree_LDR(bt->right, oper);
    }
}
void BinTree_LRD(ThreadBinTree *bt,void (*oper)(ThreadBinTree *)){
    if (bt) {
        BinTree_LRD(bt, oper);
        BinTree_LRD(bt, oper);
        oper(bt);
    }
    return;
}
void BinTree_Level(ThreadBinTree *bt ,void (*oper)(ThreadBinTree *)){
    ThreadBinTree *p;
    ThreadBinTree *q[QUEUE_MAXSIZE];
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
//二叉树按中序线索化
void BinTreeThreading_LDR(ThreadBinTree *bt)
{
    if (bt) {//节点非空时，当前访问节点
        //递归调用，将左子树线索化
        BinTreeThreading_LDR(bt->left);
        bt->lflag=(bt->left)?SubTree:Thread;
        bt->rflag=(bt->right)?SubTree:Thread;
        if (Previous) {//若当前节点的前驱Previous存在
            if (Previous->rflag ==Thread) {//若当前节点的前驱右标志为线索
                Previous->right=bt;//设置Previous的右线索指向后继
            }
            if (bt->lflag==Thread) {//若当前节点的左标志为线索
                bt->left=Previous;//设当前节点的左线索指向中序前驱
            }
        }
        Previous = bt;//让Previous保存刚访问的节点
        BinTreeThreading_LDR(bt->right);//递归调用，将右子树线索化
    }
}
ThreadBinTree *BinTreeNext_LDR(ThreadBinTree *bt)
{
    ThreadBinTree *nextNode;
    if (!bt) {
        return NULL;
    }
    if (bt->rflag == Thread) {
        return bt->right;
    }else{
        nextNode = bt->right;
        while (nextNode->lflag == SubTree) {
            nextNode = nextNode->left;
        }
        return nextNode;
    }
}
ThreadBinTree *BinTreePrevious_LDR(ThreadBinTree *bt)
{
    ThreadBinTree *preNode;
    if (!bt) {
        return NULL;
    }
    if (bt->lflag == Thread) {
        return bt->left;
    }else{
        preNode = bt->left;
        while (preNode->lflag == SubTree) {
            preNode = preNode->left;
        }
        return preNode;
    }
}
void ThreadBinTree_LDR(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p))
{
    if (bt) {
        while (bt->lflag == SubTree) {
            bt=bt->left;
        }
        do {
            oper(bt);
            bt=BinTreeNext_LDR(bt);
        } while (bt);
    }
}


