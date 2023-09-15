#include "../../../include/linerList/linkedList/circularlySingleLinkedList.h"
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L = NULL)
        return false;
    L->next = L;
    return true;
}
bool Empty(LinkList L)
{
    if (L->next == L)
        return true;
    else
        return false;
}
bool IsTail(LinkList L, LNode *p)
{
    if (p->next == L)
        return true;
    else
        return false;
}