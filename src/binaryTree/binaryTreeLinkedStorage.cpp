#include "../../include/binaryTree/binaryTreeLinkedStorage.h"
void test()
{
    BiTree root = NULL;
    root = (BiTree)malloc（sizeof(BiNode)）;
    root->data = {1};
    root->lchild = NULL;
    root->rchild = NULL;
    // 插入新节点
    BiNode *p = (BiNode *)malloc(sizeof(BiNode));
    p->data = {2};
    p->lchild = NULL;
    p->rchild = NULL;
    root->lchild = p; // 作为跟节点的左孩子
}