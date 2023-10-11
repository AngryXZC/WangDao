#include "../../include/binaryTree/binaryTreeLinkedStorage.h"
void test()
{
    BiTree root = NULL;
    root = (BiTree)malloc(sizeof(BiTNode));
    root->data = {1};
    root->lchild = NULL;
    root->rchild = NULL;
    // 插入新节点
    BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
    p->data = {2};
    p->lchild = NULL;
    p->rchild = NULL;
    root->lchild = p; // 作为跟节点的左孩子
}
void visit(BiTNode *N)
{
    printf("结点值为：%d", N->data.value);
}
void PreOrder(BiTree T)
{
    if (T != NULL)
    {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
void InOrder(BiTree T)
{
    if (T != NULL)
    {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}
void PostOrder(BiTree T)
{
    if (T != NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}
// 这里需要补充出完整的队列定义
void LevelOrder(BiTree T)
{
    LinkQueue Q;
    InitQueue(Q);
    BiTNode *p;
    EnQueue(Q, T); // 根节点入队
    while (!IsEmpty(Q))
    {
        DeQueue(Q, p);
        visit(p); // 出队并访问元素
        if (p->lchild != NULL)
            EnQueue(Q, p->lchild); // 左孩子入队
        if (p->rchild != NULL)
            EnQueue(Q, p->rchild); // 右孩子入队
    }
}
