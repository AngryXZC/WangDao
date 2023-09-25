#include "stdio.h"
#include "stdlib.h"
typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
} LinkNode;
typedef struct
{ // 链式队列
    LinkNode *front, *rear;
} LinkQueue;
// 初始化(带头节点)
void InitQueue(LinkQueue &Q);
// 判断是否为空
bool IsEmpty(LinkQueue Q);
// 新元素入队
void EnQueue(LinkQueue &Q, int x);
// 队头元素出队
bool DeQueue(LinkQueue &Q, int &X);
// 练习双端队列
// 和共享栈