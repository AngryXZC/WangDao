#define MaxSize 10 // static link list maxsize
typedef struct Node
{
    int data;
    int next;
} SLinkList[MaxSize];
// Init a[0]->next=-1 空闲节点设置为标记值（-2）
// queryO(n)
// Insert
