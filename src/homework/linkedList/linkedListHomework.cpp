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
/*
05．试编写算法将带头结点的单链表就地逆置，所谓“就地”是指辅助空间复杂度为O（1）。
*/
void inverseTheLinkedList(LinkList L)
{
    // 空表或者只有一个元素没必要转置
    if (L->next == NULL || L->next->next == NULL)
        return;
    LNode *p = L;
    while (p != NULL)
    {
        L->next->next = p->next;
        p->next = L->next;
        L->next = p;
        p = p->next;
    }
}
/*06．有一个带头结点的单链表L，设计一个算法使其元素递增有序。*/

void sortLinked(LinkList &L)
{
    LNode *p = L->next, *pre;
    LNode *r = p->next;
    p->next = NULL;
    p = r;
    while (p != NULL)
    {
        r = p->next;
        pre = L;
        while (pre->next != NULL && pre->next->data < p->data)
            pre = pre->next;
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
}
/*07．设在一个带表头结点的单链表中所有元素结点的数据值无序，
试编写一个函数，删除表中所有介于给定的两个值（作为函数参数给出）之间的元素的元素（若存在）。*/
void deleteMiddleBetweenTwoNumber(LinkList &L, int min, int max)
{
    LNode *p = L->next;
    LNode *q = L;
    while (p != NULL)
    {
        if (p->data < max && p->data > min)
        {
            // delete这个节点
            q->next = p->next;
            free(p);
            p = p->next;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
}
/*08．给定两个单链表，编写算法找出两个链表的公共结点。*/
void findSameNodeInTwoList(LinkList &L1, LinkList &L2)
{
    // 默认res为初始化好头节点的链表
    LNode *firstListNode = L1->next, *secondListNode = L2->next, *res;
    int firstLen = -0, secondLen = -0;
    while (firstListNode != NULL)
    {
        firstLen++;
        firstListNode = firstListNode->next;
    }
    while (secondListNode != NULL)
    {
        secondLen++;
        secondListNode = secondListNode->next;
    }
    if (firstLen > secondLen)
    {
        firstListNode = L1->next;
        secondListNode = L2->next;
        for (int i = 0; i < firstLen - secondLen; i++)
        {
            firstListNode = firstListNode->next;
        }
        for (int i = 0; i < secondLen; i++)
        {
            if (firstListNode == secondListNode)
            {
                res = firstListNode;
                return;
            }
            firstListNode = firstListNode->next;
            secondListNode = secondListNode->next;
        }
    }
    else
    {
        firstListNode = L1->next;
        secondListNode = L2->next;
        for (int i = 0; i < secondLen - firstLen; i++)
        {
            secondListNode = secondListNode->next;
        }
        for (int i = 0; i < firstLen; i++)
        {
            if (firstListNode == secondListNode)
            {
                res = firstListNode;
                return;
            }
            firstListNode = firstListNode->next;
            secondListNode = secondListNode->next;
        }
    }
    res = NULL;
}
/*09.给定一个带表头结点的单链表，设head为头指针，结点结构为(data,next),data为整型元素，next为指针，
试写出算法：按递增次序输出单链表中各结点的数据元素，
并释放结点所占的存储空间（要求：不允许使用数组作为辅助空间）。*/
void printListDataFollowOrder(LinkList &H)
{
    LNode *p = H->next;
    while (p != NULL) // 直到链表删为空结束
    {
        p = H->next;                  // 遍历指针
        LNode *minNode = p, *pre = H; // 最小节点指针和前一个指针
        while (p != NULL)
        {
            if (p->data < minNode->data)
                minNode = p;
            p = p->next;
            pre = p;
        }
        printf("%d \n", minNode->data);
        pre->next = minNode->next;
        free(minNode);
    }
}
/*
10.将一个带头结点的单链表A分解为两个带头结点的单链表A和B,
使得A表中含有原表中序号为奇数的元素，
而B表中含有原表中序号为偶数的元素，
且保持其相对顺序不变。
*/
void splitList(LinkList &A, LinkList &B)
{
    bool isOdd = false;
    LNode *p = A->next, *pre = A; // 遍历指针;pre为p前一个指针
    LNode *tail = B;              // B表尾指针
    while (p != NULL)
    {
        if (isOdd)
        {
            // A表抛弃偶数节点
            LNode *delNode = p;
            pre->next = delNode->next;
            p = delNode->next;
            // B表尾插法
            tail->next = delNode;
            delNode->next = NULL;
            tail = delNode;
        }
        else
        {
            pre = p;
            p = p->next;
        }
        isOdd = !isOdd;
    }
}
int main()
{
    printf("%s", "kkkk");
    return 0;
}