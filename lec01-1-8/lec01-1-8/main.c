//
//  main.c
//  lec01-1-8
//
//  Created by 王享 on 16/4/16.
//  Copyright © 2016年 王享. All rights reserved.
//

#include <stdio.h>
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
void perm(char *list,int i,int n);
int main(int argc, const char * argv[]) {
    char list[]={'a','b'};
    perm(list, 0, 1);
    return 0;
}

void perm(char *list,int i,int n){
    int j,temp;
    if (i == n) {
        for (j = 0; j<=n; j++) {
            printf("%c",list[j]);
        }
        printf("    ");
    }else{
        for (j=i; j<=n; j++) {
            SWAP(list[i], list[j], temp);
            perm(list, i+1, n);
            SWAP(list[i], list[j], temp);
        }
    }
}
