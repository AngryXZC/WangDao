#include "stdio.h"
#include "stdlib.h"
typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;
// 初始化双链表
bool InitDlinkList(DLinkList &L);
// 判断双链表是否为空
bool Empty(DLinkList L);
// 在P结点之后插入s结点
bool InsertNextDNode(DNode *p, DNode *s);
// Destroy a double LinkedList
void DestroyList(DLinkList &L);