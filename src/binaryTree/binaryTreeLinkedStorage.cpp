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

// 非递归实现中序遍历
void InOrder2(BiTree T)
{
    SqStack S;
    InitStack(S);              // 初始化栈
    BiTree p = T;              // P是遍历指针
    while (p || StackEmpty(S)) // 栈不空P不空时循环
    {
        if (p) // 一路向左
        {
            Push(S, p->data); // 并入栈
            p = p->lchild;    // 左孩子不空，一直向左走
        }
        else // 栈顶元素出栈，并转向出栈节点的右子树
        {
            Pop(S, p);
            visit(p);      // 栈顶元素出栈 访问出栈节点
            p = p->rchild; // 向右子树走，p赋值为当前结点的右子树
        }                  // 返回while循环继续进入if-else语句
    }
}
// 非递归实现先序遍历
void PreOrder2(BiTree T)
{
    SqStack S;
    InitStack(S);              // 初始化栈
    BiTree p = T;              // P是遍历指针
    while (p || StackEmpty(S)) // 栈不空P不空时循环
    {
        if (p) // 一路向左
        {
            visit(p);         // 访问当前节点
            Push(S, p->data); // 并入栈
            p = p->lchild;    // 左孩子不空，一直向左走
        }
        else // 栈顶元素出栈，并转向出栈节点的右子树
        {
            Pop(S, p);     // 栈顶元素出栈
            p = p->rchild; // 向右子树走，p赋值为当前结点的右子树
        }                  // 返回while循环继续进入if-else语句
    }
}
// 后序遍历非递归实现
void PostOrder2(BiTree T)
{
    SqStack S;
    InitStack(S);
    BiTNode *p = T, *r = NULL;
    while (p || IsEmpty(S))
    {
        if (p)
        { // 走到最左边
            Push(S, p);
            p = p->lchild;
        }
        else
        {                 // 向右
            GetTop(S, p); // 取栈顶元素
            if (p->rchild && p->rchild != r)
            {                  // 若右子树存在且未被访问
                p = p->rchild; // 转向右
            }
            else
            {
                Pop(S, p); // 栈顶元素出栈
                visit(p);  // 访问出栈节点
                r = p;     // 记录最近访问过的节点
                p = NULL;  // p置空，下次循环取栈顶元素
            }
        }
    }
}