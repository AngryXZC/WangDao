#include "stdlib.h"
#include "stdio.h"
typedef struct DNode
{
    int data;
    struct DNode *next, *prior;

} DNode, *DLinkList;
// Init an empty circularly double linked list!
bool InitDLinkList(DLinkList &L);
// Judge whether the link list is empty
bool Empty(DLinkList L);
// Judge whether the node is the tail of the circularly double list!
bool IsTail(DLinkList L, DNode *p);
// Insert s node after p node!
bool InsertNextDNode(DNode *p, DNode *s);
// Delete the node after p node!
bool DeleteNextDNode(DNode *p);