#include <stdlib.h>
#include <stdio.h>
/**
 * @brief
 * 静态顺序表
 *
 */
#define MAXSIZE 10
typedef struct
{
    int data[MAXSIZE];
    int length;
} SqList;
// 初始化线性表
void InitList(SqList &L);
// 求表长
int Length(SqList L);
// Find By element
int LocateElem(SqList L, int e);
// Find by position
int GetElem(SqList L, int i);
// Insert a element at the position of i
bool ListInsert(SqList &L, int i, int e);
// Delete a element at the position of i after this action return the removed element
bool ListDelete(SqList &L, int i, int &e);
// Output operator
void PrintList(SqList L);
// Judge whether the liner list is empty
bool Empty(SqList L);
// Destroy the liner list
void DestroyList(SqList &L);
