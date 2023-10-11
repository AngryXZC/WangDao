#include "../../include/binaryTree/threadTree.h"
// 线索访问二叉树
void ClueVisit(ThreadNode *q)
{
    if (q->lchild == NULL) // 左子树为空,建立前驱线索
    {
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL) // pre结点右子树为空，建立后续线索
    {
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
}

// 先序线索化
void PreThread(ThreadTree T)
{
    if (T != NULL)
    {
        ClueVisit(T);
        if (T->ltag = 0)
            PreThread(T->lchild);
        PreThread(T->rchild);
    }
}
//  中序线索化
void InThread(ThreadTree T)
{
    if (T != NULL)
    {
        InThread(T->lchild);
        ClueVisit(T);
        InThread(T->rchild);
    }
}
// 后序线索化
void PostHead(ThreadTree T)
{
    if (T != NULL)
    {
        PostHead(T->lchild);
        PostHead(T->rchild);
        ClueVisit(T);
    }
}
// 先序线索二叉树
void CreatePreThread(ThreadTree T)
{
    pre = NULL;
    PreThread(T);
    if (pre->rchild == NULL) // 处理最后一个结点
    {
        pre->rtag = 1;
    }
}
// 中序线索二叉树
void CreateInThread(ThreadTree T)
{
    pre = NULL;
    if (T != NULL)
    {
        InThread(T);
        if (pre->rchild == NULL)
        {
            pre->rtag = 1;
        }
    }
}
// 后序线索二叉树
void CreatePostHead(ThreadTree T)
{
    pre = NULL;
    if (T != NULL)
    {
        PostHead(T);
        if (pre->rchild == NULL)
        {
            pre->rtag = 1;
        }
    }
}
