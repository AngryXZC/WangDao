/**
 * @brief
 * 动态顺序表
 *
 */
// Default size
#define InitSize 10
typedef struct
{
    int *data;   // 指示动态分配的指针
    int MaxSize; // 顺序表的最大容量
    int length;  // 顺序表的当前长度
} SeqList;
// 初始化线性表
void InitList(SeqList &L);
// // 求表长
// int Length(SqList L);
// // Find By element
// int LocateElem(SqList L, int e);
// // Find by position
// int GetElem(SqList L, int e);
// // Insert a element at the position of i
// bool ListInsert(SqList &L, int i, int e);
// // Delete a element at the position of i after this action return the removed element
// int ListDelete(SqList &L, int i, int e);
// // Output operator
// void PrintList(SqList L);
// // Judge whether the liner list is empty
// bool Empty(SqList L);
// // Destroy the liner list
// void DestroyList();
// Increase the dynamic array length
void IncreaseSize(SeqList &L, int len);