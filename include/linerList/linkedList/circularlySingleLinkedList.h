#include "stdlib.h"
#include "stdio.h"
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;
// Init a circularly single linked list
bool InitList(LinkList &L);
// Judge  the list is empty or not
bool Empty(LinkList L);
// Judge if p node is the tail if the L linked list
bool IsTail(LinkList L, LNode *p);