//
//  HuffmanTree.c
//  3.1 赫夫曼树编码
//
//  Created by wangx on 2017/5/21.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include "HuffmanTree.h"
//从1～x个节点中选择parent节点为0，权重最小的两个节点
void SelectNode(HuffmanTree *ht,int n,int *bt1,int *bt2)
{
    int i;
    HuffmanTree *ht1,*ht2,*t;
    ht1=ht2=NULL;               //初始化两个节点为空
    for (i=1; i<=n; ++i) {      //循环处理1～n个节点（包括叶节点和非叶节点）
        if (!ht[i].parent) {    //父节点为空(节点为parent为0)
            if (ht1 ==NULL) {   //节点指针1为空
                ht1=ht+i;       //指向第i个节点
                continue;
            }
            if (ht2==NULL) {    //节点指针2为空
                ht2=ht+i;       //指向第i个节点
                //比较两个节点的权重，使ht1指向的节点
                if (ht1->weight>ht2->weight) {
                    t=ht2;
                    ht2=ht1;
                    ht1=t;
                }
                continue ;//继续循环
            }
            if (ht1&&ht2) {//若ht1，ht2两个指针都有效
                //第i个节点权重小于ht1指向的节点
                if (ht[i].weight<=ht1->weight) {
                    ht2=ht1;//ht2保存ht1，因为这时ht1指向的节点成为第2小的
                    ht1=ht+i;//ht1指向第i个节点
                }else if (ht[i].weight<ht2->weight){
                     //第i个节点权重小于ht2指向的节点
                    ht2=ht+i;//ht2指向第i个节点
                }
            }
        }
    }
    if (ht1>ht2) {//增加比较，使二叉树左侧为叶节点
        *bt2=ht1-ht;
        *bt2=ht2-ht;
    }else{
        *bt1=ht1-ht;
        *bt2=ht2-ht;
    }
}

void CreateTree(HuffmanTree *ht,int n,int *w)
{
    int i,m=2*n-1;          //总节点数
    int bt1,bt2;            //二叉树节点序号
    if (n<=1) {             //只有一个节点，无法创建
        return;
    }
    for (i=1; i<=n; ++i)    //初始化叶节点
    {
        ht[i].weight=w[i-1];
        ht[i].parent=0;
        ht[i].left=0;
        ht[i].right=0;
    }
    for (; i<=m; ++i) {     //初始化后续节点
        ht[i].weight=0;
        ht[i].parent=0;
        ht[i].left=0;
        ht[i].right=0;
    }
    for (i=n+1; i<=m; ++i) {    //逐个计算非叶节点，创建HuffmanTree
        //从1～i-1个节点选择parent节点为0，权重最小的两个节点
        SelectNode(ht, i-1, &bt1, &bt2);
        ht[bt1].parent=i;
        ht[bt2].parent=i;
        ht[i].left=bt1;
        ht[i].right=bt2;
        ht[i].weight=ht[bt1].weight+ht[bt2].weight;
    }
}
void HuffmanCoding(HuffmanTree *ht,int n, HuffmanCode *hc)
{
    char *cd;
    int start,i;
    int current,parent;
    cd=(char *)malloc(sizeof(char)*n);
    cd[n-1]='\0';//设置字符串结束标志
    for (i=1; i<=n; i++) {
        start=n-1;
        current=i;
        parent=ht[current].parent;//获取当前节点的父节点
        while (parent) {
            if (current==ht[parent].left) {//若该节点是父节点的左子树
                cd[--start]='0';//编码为0
            }else{//若结点是父节点的右子树
                cd[--start]='1';//编号为1
            }
            current=parent;//设置当前节点指向父节点
            parent=ht[parent].parent;//获取当前及诶单的父节点序号
        }
        //分配保存编码的内存
        hc[i-1]=(char *)malloc(sizeof(char)*(n-start));
        strcpy(hc[i-1], &cd[start]);//复制生成的编码
    }
    free(cd);//释放编码占用的内存
}

void Encode(HuffmanCode *hc, char *alphabet,char *str,char *code)
{
    //将一个字符串转换为Huffman编码
    //hc为Huffman编码表，alphabet为对应的字母表，str为序号转换的字符串，code返回转换的结果
    int len=0,i=0,j;
    code[0]='\0';
    while (str[i]) {
        j=0;
        while (alphabet[j]!=str[i]) {
            j++;
        }
        //将对应的字母的Huffman编码复制到code指定的位置
        strcpy(code+len, hc[j]);
        len=len+strlen(hc[j]);//累加字符串长度
        i++;
    }
    code[len]='\0';
}

void Decode(HuffmanTree *ht,int m,char *code, char *alphabet,char *decode)
{
    //将一个Huffman编码组成的字符串转换为明文字符串
    //ht为Huffman二叉树，m为字符串数量，alphabet为对应的字母表，str为需要转换的字符串，decode为解码之后的字符串
    int position=0,i,j=0;
    m=2*m-1;
    while (code[position]) {//字符未结束
        //在Huffman树中查找左右子树
        for (i=m; ht[i].left&&ht[i].right; position++) {
            if(code[position]=='0'){//编码为0
                i=ht[i].left;
            }else{
                i=ht[i].right;
            }
        }
        decode[j]=alphabet[i-1];
        j++;
    }
    decode[j]='\0';
}







































