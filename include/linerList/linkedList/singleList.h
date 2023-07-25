typedef struct
{
    int data;    // Data Area
    LNode *next; // Pointer Field
} LNode, *LinkList;
// // 初始化线性表
// void InitList(SeqList &L);
// // 求表长
// int Length(SeqList L);
// // Find By element
// int LocateElem(SeqList L, int e);
// // Find by position
// int GetElem(SeqList L, int i);
// // Insert a element at the position of i
// bool ListInsert(SeqList &L, int i, int e);
// // Delete a element at the position of i after this action return the removed element
// bool ListDelete(SeqList &L, int i, int &e);
// // Output operator
// void PrintList(SeqList L);
// // Judge whether the liner list is empty
// bool Empty(SeqList L);
// // Destroy the liner list
// void DestroyList(SeqList &L);
// // Increase the dynamic array length
// void IncreaseSize(SeqList &L, int len);