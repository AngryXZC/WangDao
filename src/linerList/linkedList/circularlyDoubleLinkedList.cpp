#include "../../../include/linerList/linkedList/circularlyDoubleLinkedList.h"
bool InitDLinkList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L = NULL)
        return false;
    L->next = L;
    L->prior = L;
    return true;
}
bool Empty(DLinkList L)
{
    if (L->next == L)
        return true;
    else
        return false;
}
bool IsTail(DLinkList L, DNode *p)
{
    if (p->next == L)
        return true;
    else
        return false;
}
bool InsertNextDNode(DNode *p, DNode *s)
{
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
}
bool DeleteNextDNode(DNode *p)
{
    if (p == NULL)
        return false;
    DNode *q = p->next;
    p->next = q->next;
    q->next->prior = p;
    free(q);
    return true;
}