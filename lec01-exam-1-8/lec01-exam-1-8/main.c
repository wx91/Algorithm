//
//  main.c
//  lec01-exam-1-8
//
//  Created by 王享 on 16/4/17.
//  Copyright © 2016年 王享. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int result = Fibonacci(7);
    //0 1 2 3 4 5 6 7
    //0 1 1 2 3 5 8 13
    printf("%d\n",result);
    return 0;
}
int Fibonacci(n){
    if (n == 0 ) {
        return 0;
    }else if (n ==1 ){
        return 1;
    }else{
        return Fibonacci(n-1)+Fibonacci(n-2);
    }
}
//int Fibonacci(n){
//    int list[n];
//    list[0]=0,list[1]=1;
//    for (int i = 2; i<=n ; i++) {
//        list[i]=list[i-1]+list[i-2];
//        printf("%d,",list[i]);
//    }
//    return list[n];
//}