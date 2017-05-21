//
//  main.c
//  2.1 二叉树
//
//  Created by wangx on 2017/5/17.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "ThreadBinTree.h"

void oper(ThreadBinTree *p){
    printf("%c",p->data);
    return ;
}


ThreadBinTree *InitRoot(){
    ThreadBinTree *node;
    if ((node=(ThreadBinTree *)malloc(sizeof(ThreadBinTree)))) {
        printf("\n输入根节点数据:");
        scanf("%s",&node->data);
        node->left = NULL;
        node->right = NULL;
//        return Thread(node);
    }
    return NULL;
}

void AddNode(ThreadBinTree *bt){
    ThreadBinTree *node , *parent;
    DATA data;
    char select;
    if ((node = (ThreadBinTree *)malloc(sizeof(ThreadBinTree)))) {
        printf("\n输入二叉树节点数据:");
        fflush(stdin);
        scanf("%s",&node->data);
        node->left=NULL;
        node->right=NULL;
        printf("输入父节点数据:");
        fflush(stdin);
        scanf("%s",&data);
        parent = BinTreeFind(bt, data);
        if (!parent) {
            printf("未找到父节点\n");
            free(node);
            return ;
        }
        printf("1.添加到左子树\n 2.添加到右子树\n");
        do {
            select = getchar();
            select -='0';
            if (select ==1||select==2) {
                BinTreeAddNode(bt, node, select);
            }
        } while (select!=1&&select !=2);
    }
    return ;
}

int main(int argc, const char * argv[]) {
    ThreadBinTree *root = NULL;
    char select;
    void (*oper1)();//指向函数的指针
    oper1 =oper;//指向具体操作的函数
    printf("\n 1.设置二叉树根元素   2.添加二叉树节点\n");
    printf("\n 3.先序遍历   4.中序遍历\n");
    printf("\n 5.后序遍历   6.按层遍历\n");
    printf("\n 7.二叉树深度  0.退出\n");
    do {
        select = getchar();
        switch (select) {
            case '1'://设置根元素
                root = InitRoot();
                break;
            case '2':
                AddNode(root);
                break;
            case '3':
                printf("\n先序遍历的结果为:");
                BinTree_DLR(root, oper1);
                printf("\n");
                break;
            case '4':
                printf("\n中序遍历的结果为:");
                BinTree_LDR(root, oper1);
                printf("\n");
                break;
            case '5':
                printf("\n后序遍历的结果为:");
                BinTree_LRD(root, oper1);
                printf("\n");
                break;
            case '6':
                printf("\n按层遍历的结果为:");
                BinTree_Level(root, oper1);
                printf("\n");
                break;
            case '7':
                printf("\n二叉树深度为%d\n",BinTreeDept(root));
                break;
            case '0':
                break;
            default:
                break;
        }
    } while (select!='0');
    BinTreeClear(root);
    root =NULL;
    
    return 0;
}
