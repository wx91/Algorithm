//
//  BinTree.h
//  3.1 二叉树
//
//  Created by wangx on 2017/5/18.
//  Copyright © 2017年 wangx. All rights reserved.
//


#include <stdio.h>

#define QUEUE_MAXSIZE 50
typedef char DATA;

typedef struct ChainTree //定义二叉树节点类型
{
    DATA data;//元素数据
    struct ChainTree *left;//左子树节点指针
    struct ChainTree *right;//右子树节点指针
}ChainBinTree;


//初始化二叉树根节点
ChainBinTree *BinTreeInit(ChainBinTree *node);

//bt为父节点，node为子节点，n=1表示添加左子树，n=2表示右子树
int BinTreeAddNode(ChainBinTree *bt,ChainBinTree *node,int n);

//获取节点左子树
ChainBinTree *BinTreeLeft(ChainBinTree *bt);

//获取节点的右子树
ChainBinTree *BinTreeRight(ChainBinTree *bt);

//检查二叉树是否为空，为空则返回1 否则返回0
int BinTreeIsEmpty(ChainBinTree *bt);

//求二叉树的深度
int BinTreeDept(ChainBinTree *bt);

//在二叉树中查找值为data的结点
ChainBinTree *BinTreeFind(ChainBinTree *bt,DATA data);

//清除二叉树
void BinTreeClear(ChainBinTree *bt);

//先序遍历
void BinTree_DLR(ChainBinTree *bt,void (*oper)(ChainBinTree *));

//中序遍历
void BinTree_LDR(ChainBinTree *bt,void (*oper)(ChainBinTree *));
//后续遍历
void BinTree_LRD(ChainBinTree *bt,void (*oper)(ChainBinTree *));
//按层遍历
void BinTree_Level(ChainBinTree *bt ,void (*oper)(ChainBinTree *));
