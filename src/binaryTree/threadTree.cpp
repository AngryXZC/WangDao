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
//==========================================在中序线索二叉树找中序后继=======================================================
// 找到以p为根的子树中，第一个被中序遍历的结点
ThreadNode *FirstNode(ThreadNode *p)
{
    // 循环找到最左下的结点（不一定是叶子结点）
    while (p->ltag == 0)
    {
        p = p->lchild;
    }
    return p;
}
// 在中序线索二叉树中找到结点p的后继结点
ThreadNode *NextNode(ThreadNode *p)
{
    if (p->rtag == 0)
    {
        return FirstNode(p->rchild);
    }
    else
    {
        return p->rchild; // rtag==1时，直接返回后继线索
    }
}
// 对中序线索二叉树进行中序遍历（利用线索实现非递归算法）
void InOrder(ThreadTree T)
{
    for (ThreadNode *p = FirstNode(T); p != NULL; p = NextNode(p))
    {
        visit(p);
    }
}
//==========================================在中序线索二叉树找中序前驱=======================================================
// 找到以p为根的子树中，最后一个被中序遍历的结点
ThreadNode *LastNode(ThreadNode *p)
{
    // 循环找到最右下的结点（不一定是叶子结点）
    while (p->rtag == 0)
    {
        p = p->rchild;
    }
    return p;
}
// 在中序线索二叉树中找到结点p的前驱结点
ThreadNode *PreNode()
{
    // 左子树中最右下的节点
    if (p->ltag == 0)
    {
        return LastNode(p->lchild);
    }
    else
    {
        return p->lchild;
    }
}
// 对中序线索二叉树进行逆向中序遍历（利用线索实现非递归算法）
void ReInOrder(ThreadTree T)
{
    for (ThreadNode *p = LastNode(T); p != NULL; p = PreNode(p))
    {
        visit(p);
    }
}
// 先序线索和后序线索二叉树不可以直接找到前驱和后继
// 可以使用三叉链表