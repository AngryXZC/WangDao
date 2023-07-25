#include <stdlib.h>
#include <stdio.h>
/**
 * @brief
 * 动态顺序表
 *
 */
// Default size
#define InitSize 10
typedef struct
{
    int *data;   // 指示动态分配的指针
    int MaxSize; // 顺序表的最大容量
    int length;  // 顺序表的当前长度
} SeqList;
// 初始化线性表
void InitList(SeqList &L);
// 求表长
int Length(SeqList L);
// Find By element
int LocateElem(SeqList L, int e);
// Find by position
int GetElem(SeqList L, int i);
// Insert a element at the position of i
bool ListInsert(SeqList &L, int i, int e);
// Delete a element at the position of i after this action return the removed element
bool ListDelete(SeqList &L, int i, int &e);
// Output operator
void PrintList(SeqList L);
// Judge whether the liner list is empty
bool Empty(SeqList L);
// Destroy the liner list
void DestroyList(SeqList &L);
// Increase the dynamic array length
void IncreaseSize(SeqList &L, int len);