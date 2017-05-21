//
//  HuffmanTree.h
//  3.1 赫夫曼树编码
//
//  Created by wangx on 2017/5/21.
//  Copyright © 2017年 wangx. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int weight;     //权值
    int parent;     //父节点序号
    int left;       //左子树序号
    int right;      //右子树序号
}HuffmanTree;

typedef char *HuffmanCode;      //Huffman编码

void SelectNode(HuffmanTree *ht,int n,int *bt1,int *bt2);


void CreateTree(HuffmanTree *ht,int n,int *w);

void HuffmanCoding(HuffmanTree *ht,int n, HuffmanCode *hc);

void Encode(HuffmanCode *hc, char *alphabet,char *str,char *code);

void Decode(HuffmanTree *ht,int m,char *code, char *alphabet,char *decode);

