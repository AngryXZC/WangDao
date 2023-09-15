#include "../../../include/linerList/linkedList/singleList.h"

// 不带头节点
bool InitListNoHeadNode(LinkList L)
{
    return (L == NULL);
}
bool NoHeadNodeIsEmpty(LinkList &L)
{
    return (L == NULL);
}
bool InitListWithHeadNode(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}
bool WithHeadNodeIsEmpty(LinkList &L)
{
    return (L->next == NULL);
}
bool ListInsertWithHeadNode(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;
    LNode *p;  // 指针p指向当前扫描的节点
    int j = 0; // 当前节点
    p = L;
    while (p != NULL && j < i - 1) // 找到前一个节点。这处可以这么理解：循环退出时j=i-1;而这个p=p-next已经执行所以是前面的节点
    {
        p = p->next;
        j++;
    }
    if (p = NULL) // i值不合法
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
bool ListInsertNoHeadNode(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;
    if (i == 1)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;
        return true;
    }
    LNode *p;
    int j = 1;
    while (p != NULL && j < i - 1)
    {
        p - p->next;
        j++;
    }
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
bool InsertNextNode(LNode *p, int e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
bool InsertPriorNode(LNode *p, int e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
        return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}
bool ListDelete(LinkList &L, int i, int &e)
{
    if (i < 1)
        return false;
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;    // 值不合法
    if (p->next == NULL) // 第i-1个结点之后已经没有其他结点
        return false;
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}
bool DeleteNode(LNode *p)
{
    if (p = NULL)
        return false;
    LNode *q = p->next;
    p->data = p->next->data;
    p->next = q->next;
    free(q);
    return true;
}
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
        return NULL;
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}
LNode *LocateElem(LinkList L, int e)
{
    LNode *p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p; // 返回空或者NULL
}
int Length(LinkList L)
{
    int len = 0;
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}
LinkList List_TailInsert(LinkList &L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}
LinkList List_HeadInsert(LinkList &L)
{
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}