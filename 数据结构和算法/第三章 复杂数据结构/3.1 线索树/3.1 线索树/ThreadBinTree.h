//
//  ThreadBinTree.h
//  3.1 线索树
//
//  Created by wangx on 2017/5/20.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define QUEUE_MAXSIZE 50
typedef char DATA;  //定义元素类型

typedef enum {
    SubTree,
    Thread
}NodeFlag;  //枚举值SubTree(子树)和Thread（线索）分别为0,1
typedef struct ThreadTree{
    DATA data;                  //元素数据
    NodeFlag lflag;             //左标志
    NodeFlag rflag;             //右标志
    struct ThreadTree *left;    //左子树节点指针
    struct ThreadTree *right;   //右子树节点指针
}ThreadBinTree;
//初始化二叉树节点
ThreadBinTree *BinTreeInit(ThreadBinTree *node);
//添加数据到二叉树
int BinTreeAddNode(ThreadBinTree *bt,ThreadBinTree *node,int n);

ThreadBinTree *BinTreeLeft(ThreadBinTree *bt);

ThreadBinTree *BinTreeRight(ThreadBinTree *bt);
//检查二叉树是否为空，为空则返回1 否则返回0
int BinTreeIsEmpty(ThreadBinTree *bt);

//求二叉树的深度
int BinTreeDept(ThreadBinTree *bt);

//在二叉树中查找值为data的结点
ThreadBinTree *BinTreeFind(ThreadBinTree *bt,DATA data);

void BinTreeClear(ThreadBinTree *bt);

//先序遍历
void BinTree_DLR(ThreadBinTree *bt,void (*oper)(ThreadBinTree *));
//中序遍历
void BinTree_LDR(ThreadBinTree *bt,void (*oper)(ThreadBinTree *));

void BinTree_LRD(ThreadBinTree *bt,void (*oper)(ThreadBinTree *));

void BinTree_Level(ThreadBinTree *bt ,void (*oper)(ThreadBinTree *));
//二叉树按中序线索化
void BinTreeThreading_LDR(ThreadBinTree *bt);

ThreadBinTree *BinTreeNext_LDR(ThreadBinTree *bt);

ThreadBinTree *BinTreePrevious_LDR(ThreadBinTree *bt);

void ThreadBinTree_LDR(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p));

