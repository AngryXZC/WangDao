#include "../../../include/linerList/sequenList/staticSequenceList.h"
// 初始化线性表
void InitList(SqList &L)
{
    L.length = 0;
    for (int i = 0; i < MAXSIZE; i++)
    {
        L.data[i] = 0;
    }
}
// 插入元素
bool ListInsert(SqList &L, int i, int e)
{
    // Judge i is vialed
    if (i < 1 || i > L.length + 1)
        return false;
    // Judge whether current storage space is full or not
    if (L.length >= MAXSIZE)
        return false;
    // 逻辑结构上位序从一开始，而数组从0开始
    // 在逻辑结构的第i个位置插入元素，需要进行（l.length-i）+1次移动
    // 所以这里有等于号
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e; // 对应数组下标比线性表小一个数
    L.length++;
    return true;
}
// 删除元素
bool ListDelete(SqList &L, int i, int &e)
{
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}
// 按位查找
int GetElem(SqList L, int i)
{
    if (i < 1 || i > L.length)
        return -1;
    return L.data[i - 1];
}
// 按值查找
int LocateElem(SqList L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i + 1; // 返回位序与数组下标不同
        }
    }
    return 0;
}
int Length(SqList L)
{
    return L.length;
}
void PrintList(SqList L)
{
    if (L.length <= 0)
    {
        printf("This list is empty!");
    }
    for (int i = 0; i < L.length; i++)
    {
        printf("index of %d is %d \n", i + 1, L.data[i]);
    }
}
bool Empty(SqList L)
{
    if (L.length == 0)
    {
        return false;
    }
    else
        return true;
}
void DestroyList(SqList &L)
{
    L.length = 0;
    free(L.data);
}