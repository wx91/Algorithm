//
//  main.c
//  lec01-exam-1-12
//
//  Created by 王享 on 16/4/17.
//  Copyright © 2016年 王享. All rights reserved.
//

#include <stdio.h>
void Powerset(char list[],int n);
int main(int argc, const char * argv[]) {
    char list[]={'a','b','c'};
    Powerset(list,2);
    return 0;
}
void Powerset(char list[],int n){
    for (int i= 1; i<=n; i++) {
        char pow[i];
        pow[i]=list[i];
        printf("%s\n",pow);
    }
    
}

