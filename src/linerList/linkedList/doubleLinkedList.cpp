#include "../../../include/linerList/linkedList/doubleLinkedList.h"
bool InitDlinkList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    L->prior = NULL;
    L->next = NULL;
    return true;
}
bool Empty(DLinkList L)
{
    if (L->next == NULL)
    {
        return true;
    }
    else
        return false;
}
bool InsertNextDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL)
    {
        return false;
    }
    s->next = p->next;
    if (p->next != NULL)
        p->next->prior = s;
    s->prior = p;
    p->next = s;
}
bool DeleteNextDNode(DNode *p)
{
    if (p == NULL)
        return false;
    DNode *q = p->next;
    if (q = NULL)
        return false;
    p->next = q->next;
    if (q->next != NULL)
        q->next->prior = p;
    free(q);
    return true;
}
void DestroyList(DLinkList &L)
{
    // 循环释放各个数据结点
    while (L->next != NULL)
    {
        DeleteNextDNode(L);
    }
    free(L);
    L = NULL;
}