//
//  AdjMatrixGraph.h
//  3.2 图
//
//  Created by wangx on 2017/5/21.
//  Copyright © 2017年 wangx. All rights reserved.
//


#include <stdio.h>

#define VERTEX_MAX 26
#define MAXVALUE   32767

typedef struct
{
    char Vertex[VERTEX_MAX];
    int Edges[VERTEX_MAX][VERTEX_MAX];
    int isTrav[VERTEX_MAX];
    int VertexNum;
    int EdgeNum;
    int GraphType;
}MatrixGraph;
























