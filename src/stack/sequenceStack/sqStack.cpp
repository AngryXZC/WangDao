#include "../../../include/stack/sequenceStack/sqStack.h"
void InitStack(SqStack &S)
{
    S.top = -1;
}
bool StackEmpty(SqStack S)
{
    if (S.top == -1)
        return true;
    else
        return false;
}
bool Push(SqStack &S, int x)
{
    if (S.top == MaxSize - 1)
        return false;
    S.data[++S.top] = x;
    return true;
}
bool Pop(SqStack &S, int &x)
{
    if (S.top == -1)
        return false;
    x = S.data[S.top--];
    return true;
}
bool GetTop(SqStack S, int &x)
{
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}