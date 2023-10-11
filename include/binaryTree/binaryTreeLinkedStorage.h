/**
 * @file binaryTreeLinkedStorage.h
 * @author xzc (xingzhicheng@imudges.com)
 * @brief 链式存储二叉树
 * @version 0.1
 * @date 2023-10-10
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "stdlib.h"
#include "stdio.h"
#include "../queue/linkedQueue.h"
struct ElemType
{
    int value;
};

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 定义一课空树
void test();
// 访问节点
void visit(BiTNode *N);

// 每个节点都路过三次
// 先序在第一次路过的时候就访问
// 中序在第二次路过时访问
// 后序在第三次路过时访问
//  先序遍历
void PreOrder(BiTree T);
// 中序遍历
void InOrder(BiTree T);
// 后续遍历
void PostOrder(BiTree T);
// 二叉树层次遍历
void LevelOrder(BiTree T);
