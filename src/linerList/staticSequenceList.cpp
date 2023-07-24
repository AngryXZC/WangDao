#include "../../include/linerList/staticSequenceList.h"
// 初始化线性表
void InitList(SqList &L)
{
    L.length = 0;
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
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e; // 对应数组下标比线性表小一个数
    L.length++;
    return true;
}