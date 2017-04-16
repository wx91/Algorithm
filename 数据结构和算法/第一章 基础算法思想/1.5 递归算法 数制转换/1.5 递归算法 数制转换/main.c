//
//  main.c
//  1.5 递归算法 数制转换
//
//  Created by wangx on 2017/4/16.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void convto(char *s,int n,int b){
    char bit[]="0123456789ABCDEF";
    int len;
    if (n==0) {
        strcpy(s, "");
        return;
    }
    convto(s, n/b, b);
    len = strlen(s);
    s[len]=bit[n%b];
    s[len+1]='\0';
}

int main(int argc, const char * argv[]) {
    char s[80];
    int i,base,old;
    printf("请输入十进制数：");
    scanf("%d",&old);
    printf("请输入转换的进制：");
    scanf("%d",&base);
    convto(s, old, base);
    printf("%s\n",s);
    return 0;
}
