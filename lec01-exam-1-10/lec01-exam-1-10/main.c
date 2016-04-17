//
//  main.c
//  lec01-exam-1-10
//
//  Created by 王享 on 16/4/17.
//  Copyright © 2016年 王享. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int result = Ackerman(1, 0);
    printf("%d\n",result);
    return 0;
}
int Ackerman(int n,int m){
    if (m == 0) {
        return n=n+1 ;
    }else if(n==0){
        return Ackerman(m-1,1);
    }else{
        return Ackerman(m-1, Ackerman(m, n-1));
    }
}
