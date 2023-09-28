/**
 * @file stack.cpp
 * @author your name (you@domain.com)
 * @brief 3.1.4栈和队列习题编程
 * @version 0.1
 * @date 2023-09-26
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "../../../include/linerList/linkedList/singleList.h"
/*
04.设单链表的表头指针为L,结点结构由data和next两个域构成，其中data域为字符型试设计算法判断该链表的全部n个字符是否中心对称。
例如yx、yyx都是中心对称
*/
// 判断字符序列链表是否对称
bool isSymmetric(LinkList head)
{

    // 快慢指针初始化指向头节点
    LNode *fast = head;
    LNode *slow = head;

    // 快指针移动2步,慢指针移动1步
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    // slow指向中间节点
    LNode *p = slow;

    // q指向头节点
    LNode *q = head;

    // 两指针向中间遍历比较
    while (p != q)
    {

        // 两节点值不相等,非对称
        if (p->data != q->data)
        {
            return false;
        }

        // p、q指针同步移动
        p = p->next;
        q = q->next;
    }

    // p、q指针重合,序列对称
    return true;
}
/*
05.设有两个栈s1、s2都采用顺序栈方式，
并共享一个存储区[0,...maxsize-1],为了尽量利用空间，减少溢出的可能，可采用栈顶相向、迎面增长的存储方式。
试设计S1、s2有关入栈和出栈的操作算法。

*/
#define MAXSIZE 100 // 存储区最大长度

int data[MAXSIZE]; // 共享存储区

int top1 = -1;      // s1栈顶指针
int top2 = MAXSIZE; // s2栈顶指针

// s1入栈
void push1(int element)
{
    if (top1 == top2 - 1)
    { // 栈满
        printf("Stack overflow");
        return;
    }
    top1++;
    data[top1] = element;
}

// s1出栈
int pop1()
{
    if (top1 == -1)
    { // 栈空
        printf("Stack underflow");
        return 0;
    }
    int element = data[top1];
    top1--;
    return element;
}

// s2入栈
void push2(int element)
{
    if (top2 == top1 + 1)
    { // 栈满
        printf("Stack overflow");
        return;
    }
    top2--;
    data[top2] = element;
}

// s2出栈
int pop2()
{
    if (top2 == MAXSIZE)
    { // 栈空
        printf("Stack underflow");
        return 0;
    }
    int element = data[top2];
    top2++;
    return element;
}