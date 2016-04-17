//
//  main.c
//  lec01-1-7
//
//  Created by 王享 on 16/4/16.
//  Copyright © 2016年 王享. All rights reserved.
//

#include <stdio.h>
#define COMPARA(x,y) ((x)>(y)?-1:((x)=(y)?0:1))

int compare(int x,int y);
int binsearch(int list[],int searchnum,int left,int right);
int main(int argc, const char * argv[]) {
    int list[] = {2,3,4,5,6};
    int searchnum = 3;
    int result = binsearch(list, searchnum, 0, 4);
    printf("%d\n",result);
    printf("%d\n",list[result]);
    return 0;
}
int compare(int x,int y){
    if (x<y) {
        return  -1;
    }else if (x==y){
        return 0;
    }else{
        return 1;
    }
}
int binsearch(int list[],int searchnum,int left,int right){
    int middle ;
    if (left <= right) {
        middle = (left+right)/2;
        int result = compare(list[middle], searchnum);
        if (result == -1) {
            return binsearch(list, searchnum, middle+1, right);
        }else if (result == 0){
            return middle;
        }else{
            return binsearch(list, searchnum, left, middle-1);
        }
    }else{
        return -1;
    }
}
