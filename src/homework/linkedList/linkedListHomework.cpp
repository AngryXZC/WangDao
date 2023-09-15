/**
 * @file linkedListHomework.cpp
 * @author xzc (you@domain.com)
 * @brief 王道2.3.7综合应用题
 * @version 0.1
 * @date 2023-09-15
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "stdio.h"
#include "stdlib.h"
#include "../../../include/linerList/linkedList/singleList.h"
/*
01．设计一个递归算法，删除不带头结点的单链表L中所有值为x的结点。
*/
void deleteXNode(int x, LinkList L)
{
    if (L == NULL)
        return;
    LNode *q = L, *p;
    while (q->data != x && q != NULL)
    {
        p = q;
        q = L->next;
    }
    p->next = q->next; // 将新的列表置为x之后的列表
    if (q != NULL)
        free(q);
    p = p->next;
    return deleteXNode(x, p);
}
/*
02．在带头结点的单链表L中，删除所有值为x的结点，并释放其空间，假设值为x的结点不唯一，试编写算法以实现上述操作。
*/
void deleteXNodeWithHeadNode(LinkList L, int x)
{
    LNode *p = L;
    while (p->next != NULL)
    {
        if (p->next->data == x)
        {
            LNode *q = p->next;
            p->next = q->next;
            free(q);
        }
        p = p->next;
    }
    return;
}
/*03．设L为带头结点的单链表，编写算法实现从尾到头反向输出每个结点的值。*/
void invertedPrintList(LinkList &L)
{
    // 用数据模拟栈
    // 等把栈的数据结构构建出来再来搞
    // TODO
    int size = 100;
    LNode *a[100];
    LNode *q = L;
    int j = 0;
    while (q != NULL)
    {
        q = q->next;
        if (q != NULL)
            a[j] = q;
        j++;
    }
    for (int i = --j; i >= 0; i--)
    {

        printf("%d", a[i]->data);
    }
}
/* 04．试编写在带头结点的单链表L中删除一个最小值结点的高效算法（假设最小值结点是唯一的）。*/
void deleteMinElement(LinkList &L)
{
    int min = L->next->data;
    LNode *p = L, *q;
    while (p->next != NULL)
    {
        if (min > p->next->data)
        {
            min = p->next->data;
        }
        p = p->next;
    }
    q = q->next;
    free(q);
}
int main()
{
    printf("%s", "kkkk");
    return 0;
}