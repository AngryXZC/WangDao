#include "stdio.h"
#include "stdlib.h"
typedef struct LNode
{
    int data;           // Data Area
    struct LNode *next; // Pointer Field
} LNode, *LinkList;
// 初始化单链表
// 不带头节点
bool InitListNoHeadNode(LinkList &L);
// 判断链表是否为空
bool NoHeadNodeIsEmpty(LinkList &L);
// 带头结点
bool InitListWithHeadNode(LinkList &L);
// 判断链表是否为空
bool WithHeadNodeIsEmpty(LinkList &L);
// 求表长
int Length(LinkList L);
// Find By element
LNode *LocateElem(LinkList L, int e);
// Find by position with headNode
LNode *GetElem(LinkList L, int i);
// Insert a element at the position of i
bool ListInsertWithHeadNode(LinkList &L, int i, int e);
bool ListInsertNoHeadNode(LinkList &L, int i, int e);
// Delete a element at the position of i after this action return the removed element
bool ListDelete(LinkList &L, int i, int &e);
// // Output operator
// void PrintList(SeqList L);
// // Judge whether the liner list is empty
// bool Empty(SeqList L);
// // Destroy the liner list
// void DestroyList(SeqList &L);
// // Increase the dynamic array length
// void IncreaseSize(SeqList &L, int len);
// 后插操作：在p结点之后插入元素e
bool InsertNextNode(LNode *p, int e);
// 前插操作:在P结点之前插入元素 e
bool InsertPriorNode(LNode *p, int e);
// 删除指定结点
bool DeleteNode(LNode *p);
// 尾插法建立单链表
LinkList List_TailInsert(LinkList &L);
// 头插法建立单链表
LinkList List_HeadInsert(LinkList $L);
// 删除P结点的后继结点
bool DeleteNextDNode(DNode *p);