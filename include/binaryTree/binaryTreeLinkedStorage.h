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

struct ElemType
{
    int value;
};

typedef struct BiTNode
{
    ElemType data;
    struct BiNode *lchild, *rchild;
} BiTNode, *BiTree;
// 定义一课空树
void test();