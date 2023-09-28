/**
 * @file stackAndQueueApply.cpp
 * @author xzc (you@domain.com)
 * @brief 习题3.3.6栈和队列的应用
 * @version 0.1
 * @date 2023-09-28
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../../../include/queue/sequenceQueue.h"
#include "../../../include/stack/sequenceStack/sqStack.h"
/*
01.假设一个算术表达式中包含圆括号、
方括号和花括号3种类型的括号，
编写一个算法来判别表达式中的括号是否配对，以字符“\0”作为算术表达式的结束符。
*/
#include <stdio.h>

#define MAX_SIZE 100

// 栈定义
typedef struct
{
    char data[MAX_SIZE];
    int top;
} Stack;

// 初始化栈
void initStack(Stack *s)
{
    s->top = -1;
}

// 判断栈空
bool isEmpty(Stack *s)
{
    return s->top == -1;
}

// 入栈
void push(Stack *s, char c)
{
    s->data[++s->top] = c;
}

// 出栈
char pop(Stack *s)
{
    return s->data[s->top--];
}

// 检查括号匹配
bool match(char *exp)
{

    Stack s;
    initStack(&s);

    // 遍历表达式
    for (int i = 0; exp[i] != '\0'; i++)
    {

        // 左括号入栈
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(&s, exp[i]);
        }
        // 右括号出栈检查匹配
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (!isValid(pop(&s), exp[i]))
            {
                return false;
            }
        }
    }

    // 栈空则匹配成功
    return isEmpty(&s);
}

bool isValid(char left, char right)
{
    // 判断括号对应关系
    if (left == '(' && right == ')')
        return true;
    if (left == '{' && right == '}')
        return true;
    if (left == '[' && right == ']')
        return true;
    return false;
}

int main()
{

    char *exp = "{()[]}";

    if (match(exp))
    {
        printf("Matched!\n");
    }
    else
    {
        printf("Not Match!\n");
    }

    return 0;
}

/*
03 利用一个栈实现以下递归函数的非递归计算：P_n(x)=\begin{cases}

1,&\text{n=0}

\\

2x,&\text{n=1}

\\

2xP_{n-1}(x)-2(n-1)P_{n-2}(x),&\text{n>1}

\end{cases}
*/
#define MAX_SIZE 100

typedef struct
{
    double data[MAX_SIZE];
    int top;
} Stack;

double P_n(int n, double x)
{

    Stack s;
    initStack(&s);

    double p0 = 1;
    double p1 = 2 * x;

    push(&s, p0);
    push(&s, p1);

    for (int i = 2; i <= n; i++)
    {

        // 计算p_n
        double p_n = 2 * x * s.data[s.top] - 2 * (i - 1) * s.data[s.top - 1];

        // 弹出栈顶元素
        pop(&s);

        // 将p_n压入栈顶
        push(&s, p_n);
    }

    return s.data[s.top]; // 返回最终结果
}
/*
04.某汽车轮渡口，过江渡船每次能载10辆车过江。过江车辆分为客车类和货车类，
上渡船有如下规定：
    同类车先到先上船；
    客车先于货车上船，且每上4辆客车，才允许放上1辆货车；
    若等待客车不足4辆，则以货车代替；
    若无货车等待，允许客车都上船。
试设计一个算法模拟渡口管理。
*/

#include <stdio.h>
#define MAX_SIZE 10

// 队列结构
struct Queue
{
    int data[MAX_SIZE];
    int head, tail;
}

// 客车队列
struct Queue queue_car;

// 货车队列
struct Queue queue_truck;

// 初始化队列
void initQueue(struct Queue *q)
{
    q->head = 0;
    q->tail = 0;
}

// 入队
void enqueue(struct Queue *q, int x)
{
    // 入队逻辑
}

// 出队
int dequeue(struct Queue *q)
{
    // 出队逻辑
    return x;
}

void ferry()
{

    int count = queue_car.tail - queue_car.head;

    if (count >= 4)
    {
        // 取4辆客车上船
        for (int i = 0; i < 4; i++)
        {
            int car = dequeue(&queue_car);
        }
    }
    else
    {
        // 取所有客车上船
        for (int i = 0; i < count; i++)
        {
            int car = dequeue(&queue_car);
        }
    }

    // 取货车上船
    int remain = 4 - count;
    for (int i = 0; i < remain; i++)
    {
        if (queue_truck.tail > queue_truck.head)
        {
            int truck = dequeue(&queue_truck);
        }
    }

    // 额外载客车
    while (还有空位 && queue_car不空)
    {
        int car = dequeue(&queue_car);
    }

    // 渡船过江......

    // 入队新车辆
    enqueue(&queue_car, car);
    enqueue(&queue_truck, truck);
}

int main()
{

    initQueue(&queue_car);
    initQueue(&queue_truck);

    // 模拟循环载船
    while (1)
    {
        ferry();
    }

    return 0;
}