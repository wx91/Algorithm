//
//  main.c
//  2.1 单向链表
//
//  Created by wangx on 2017/4/16.
//  Copyright © 2017年 wangx. All rights reserved.
//

#include <stdio.h>
#include "ChainList.h"

int main(int argc, const char * argv[]) {
    ChainListType *node,*head = NULL;
    DATA data;
    char key[15],findkey[15];
    
    printf("输入链表中的数据，包括关键字，姓名，年龄 关键字输入0则退出：\n");
    do {
        fflush(stdin);
        scanf("%s",data.key);
        if (strcmp(data.key, "0")==0) {
            break;
        }
        scanf("%s%d",data.name,&data.age);
        head = ChainListAddEnd(head, data);//在链表尾部添加节点数据
    } while (1);
    printf("该链表共有%d个节点\n",ChainListLength(head));//返回节点数量
    //显示所有节点
    ChainListAll(head);
    
    printf("\n插入节点，输入插入位置的关键字:");
    scanf("%s",findkey);
    printf("输入插入节点的数据(关键字 姓名 年龄：)");
    scanf("%s%s%d",data.key,data.name,&data.age);
    //调用插入函数
    head = ChainListInsert(head, findkey, data);
    
    //显示所有节点
    ChainListAll(head);
    
    printf("\n在链表中查找，输入查找关键字:");
    fflush(stdin);
    scanf("%s",key);//输入查找关键字
    //调用查找函数，返回节点指针
    node = ChainListFind(head, key);
    if(node){
        data = node->data;
        printf("关键字%s对应的节点数据为(%s,%s,%d)",key,data.key,data.name,data.age);
    }else{
        printf("在链表中未找到关键字为%s的节点!\n",key);
    }
    printf("\n 在链表中删除节点，输入要删除的关键字：");
    fflush(stdin);//清空输入缓存区
    scanf("%s",key);//输入删除节点关键字
    ChainListDelete(head, key);
    
    ChainListAll(head);
    
    
    return 0;
}
