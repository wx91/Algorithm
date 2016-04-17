//
//  main.c
//  lec01-exam-1-7
//
//  Created by 王享 on 16/4/17.
//  Copyright © 2016年 王享. All rights reserved.
//

#include <stdio.h>
int Factorial1(int n);
int Factorial2(int n);
int main(int argc, const char * argv[]) {
    int result = Factorial2(5);
    printf("%d\n",result);
    return 0;
}

int Factorial1(int n){
    int result = 1;
    for (int i = 1; i<=n; i++) {
        result= i*result;
    }
    return  result;
}
int Factorial2(int n){
    if (n == 1) {
        return 1;
    }else{
        return n*Factorial2(n-1);
    }
}
