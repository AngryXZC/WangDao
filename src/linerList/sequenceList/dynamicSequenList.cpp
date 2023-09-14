#include "../../include/linerList/sequenList/dynamicSequenList.h"
void InitList(SeqList &L)
{
    L.data = (int *)malloc(InitSize * sizeof(int));
    for (int i = 0; i < InitSize; i++)
    {
        L.data[i] = 0;
    }

    L.length = 0;
    L.MaxSize = InitSize;
}
void IncreaseSize(SeqList &L, int len)
{
    int *p = L.data;
    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i <= L.length; i++)
    {
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    free(p);
}
bool ListInsert(SeqList &L, int i, int e)
{
    // Judge i is vialed
    if (i < 1 || i > L.length + 1)
        return false;
    // Judge whether current storage space is full or not
    if (L.length >= L.MaxSize)
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
bool ListDelete(SeqList &L, int i, int &e)
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
int GetElem(SeqList L, int i)
{
    if (i < 1 || i > L.length)
        return -1;
    return L.data[i - 1];
}
// 按值查找
int LocateElem(SeqList L, int e)
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
int Length(SeqList L)
{
    return L.length;
}
void PrintList(SeqList L)
{

    for (int i = 0; i < L.length; i++)
    {
        printf("index if %d is %d", i + 1, L.data[i]);
    }
}
bool Empty(SeqList L)
{
    if (L.length == 0)
    {
        return false;
    }
    else
        return true;
}
void DestroyList(SeqList &L)
{
    L.length = 0;
    free(L.data);
}