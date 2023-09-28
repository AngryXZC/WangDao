/**
 * @file queue.cpp
 * @author your name (you@domain.com)
 * @brief 队列课后编程题
 * @version 0.1
 * @date 2023-09-27
 * 3.2.5
 * @copyright Copyright (c) 2023
 *
 */
#include "../../../include/queue/sequenceQueue.h"
#include "../../../include/stack/sequenceStack/sqStack.h"
/*
01.若希望循环队列中的元素都能得到利用，则需设置一个标志域tag,并以tag的值为0或1来区分队头指针front和队尾指针rear相同时的队列状态是“空”还是“满”。
试编写与此结构相应的入队和出队算法。
*/
// 入队
void enqueue(SqQueue *q, int x)
{
    if (q->front == q->rear && q->tag == 1)
    {
        // 队列满
        return;
    }

    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % MaxSize;
    q->tag = 1; // 置非空标志
}

// 出队
int dequeue(SqQueue *q)
{
    if (q->front == q->rear && q->tag == 0)
    {
        // 队列空
        return -1;
    }

    int x = q->data[q->front];
    q->front = (q->front + 1) % MaxSize;
    if (q->front == q->rear)
    {
        q->tag = 0; // 置空标志
    }

    return x;
}
/*
02.Q是一个队列，S是一个空栈，实现将队列中的元素逆置的算法。
*/
SqQueue reverse(SqQueue Q, SqStack S)
{

    while (!QueueEmpty(Q))
    {
        int x = -1;
        DeQueue(Q, x);
        Push(S, x);
    }

    while (!StackEmpty(S))
    {
        int y = -1;
        Pop(S, y);
        EnQueue(Q, y);
    }

    return Q;
}
/*
03.利用两个栈S1和S2来模拟一个队列，已知栈的4个运算定义如下：
    Push (S,x);//元素x入栈S
    Pop(S,x);//S出栈并将出栈的值赋给x
    StackEmpty(S);//判断栈是否为空
    StackOverflow(S);//判断栈是否满
如何利用栈的运算来实现该队列的3个运算（形参由读者根据要求自己设计）？
    Enqueue;//将元素×入队
    Dequeue;//出队，并将出队元素存储在×中
    QueueEmpty;//判断队列是否为空
*/

// 入队
void Enqueue(SqStack S1, SqStack S2, int x)
{
    Push(S1, x);
}

// 出队
void Dequeue(SqStack S1, SqStack S2, int *x)
{
    if (StackEmpty(S2))
    {
        while (!StackEmpty(S1))
        {
            int y;
            Pop(S1, y);
            Push(S2, y);
        }
    }
    Pop(S2, *x);
}

// 判空
bool QueueEmpty(SqStack S1, SqStack S2)
{
    if (StackEmpty(S1) && StackEmpty(S2))
    {
        return true;
    }
    else
    {
        return false;
    }
}
/*
04.【2019统考真题】请设计一个队列，
要求满足：
    ①初始时队列为空；
    ②入队时，允许增加队列占用空间；
    ③出队后，出队元素所占用的空间可重复使用，即整个队列所占用的空间只增不减；
    ④入队操作和出队操作的时间复杂度始终保持为O(1)。请回答下列问题：
1)该队列是应选择链式存储结构，还是应选择顺序存储结构？
2)画出队列的初始状态，并给出判断队空和队满的条件
3)画出第一个元素入队后的队列状态。
4)给出入队操作和出队操作的基本过程。
*/
/**
 * 1）链式存储（允许增加队列空间）
 * 2）
 *              ————————
 *              |        |
 *              V
 *       front->  【data,next】<-rear
 *      队空条件：front=rear
 *      队满条件：rear->next=front;
 *
 *
 * 3)    front->  【data,next】->【data,next】<-rear
 *                  ^                   ^
 *                  |                   |
 *                   ———————————————————
 * 4)入队：
 *      if(队满)
 *              新建节点
 *              放在rear后
 *              构建环
 *      else
 *              rear->next->data修改为入队的值
 *              rear=rear->next

需要注意的是，无需关心队列满的条件，因为链式存储结构可以根据需要动态增加节点，不会发生队列满的情况。
*/