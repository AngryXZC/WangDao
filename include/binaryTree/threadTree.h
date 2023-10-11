/**
 * @file threadTree.h
 * @author your name (you@domain.com)
 * @brief 线索二叉树
 * @version 0.1
 * @date 2023-10-11
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "stdlib.h"
#include "stdio.h"
struct ElemType
{
    int value;
};

typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    // 线索二叉树
    int ltag, rtag; // 左右线索标记
} ThreadNode, *ThreadTree;

ThreadNode *pre = NULL; // 全局指向当前访问结点的前驱
// 线索访问二叉树
void ClueVisit(ThreadNode *N);
/// 先序遍历建立线索二叉树
void PreThread(ThreadTree T);

// 中序遍历建立线索二叉树
void InThread(ThreadTree T);

// 后序线索化
void PostHead(ThreadTree T);

// 先序线索二叉树
void CreatePreThread(ThreadTree T);
// 中序线索化二叉树T
void CreateInThread(ThreadTree T);
// 后序线索二叉树
void CreatePostHead(ThreadTree T)
