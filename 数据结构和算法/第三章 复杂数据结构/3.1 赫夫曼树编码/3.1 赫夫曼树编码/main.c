//
//  main.c
//  3.1 赫夫曼树编码
//
//  Created by wangx on 2017/5/21.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include <stdio.h>
#include "HuffmanTree.h"

int main(int argc, const char * argv[]) {
    int i,n=4,m;
    char test[]="DBDBDABDCDADBDADACDBDBD";
    char code[100],code1[100];
    char alphabet[] ={'A','B','C','D'};
    int w[] ={5,7,2,13};
    HuffmanTree *ht;
    HuffmanCode *hc;
    m=2*n-1;
    ht=(HuffmanTree *)malloc((m+1)*sizeof(HuffmanTree));
    if (!ht) {
        printf("内存分配失败!\n");
        exit(0);
    }
    hc = (HuffmanCode *)malloc(n*sizeof(char *));
    if (!hc) {
        printf("内存分配失败!\n");
        exit(0);
    }
    CreateTree(ht, n, w);//创建赫夫曼树
    HuffmanCoding(ht, n, hc);//根据赫夫曼树生成赫夫曼树编码
    for (i=1; i<=n; i++) {
        printf("字母:%c,权重:%d,编码为%s\n",alphabet[i-1],ht[i].weight,hc[i-1]);
    }
    Encode(hc, alphabet, test, code);
    printf("\n字符串:\n%s\n转换后为：\n%s\n",test,code);
    
    Decode(ht, n, code, alphabet, code1);
    printf("\n字符串:\n%s\n转换后为：\n%s\n",code,code1);
    return 0;
}





























