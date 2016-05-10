//
//  main.c
//  lec2-2-1
//
//  Created by 王享 on 16/4/18.
//  Copyright © 2016年 王享. All rights reserved.
//

#include <stdio.h>
#define MAX_SIZE 100

float sum(float [],int );
float input[MAX_SIZE],answer;
int main(int argc, const char * argv[]) {
    for (int i = 0; i<MAX_SIZE; i++) {
        input[i]=i;
    }
    answer = sum(input, MAX_SIZE);
    printf("The sum is : %f",answer);
    return 0;
}
float sum(float list[],int n){
    float tempsum = 0;
    for (int i=0; i<n; i++) {
        tempsum+=list[i];
    }
    return tempsum;
}
