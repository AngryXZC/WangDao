#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int front, rear; // 队头队尾
    // 如果不浪费任意一个元素的位置
    // size++和--可以区分队列是满的还是空的
    // 或者使用tag区分是插入还是删除导致的两个指针相同
    int size;
} SqQueue;
// 初始化队列
void InitQueue(SqQueue &Q);
// 判断队列是否为空
bool QueueEmpty(SqQueue Q);
// 入队
bool EnQueue(SqQueue &Q, int x);
// 出队
bool DeQueue(SqQueue &Q, int &x);
// 获得队头元素的值
bool GetHead(SqQueue Q, int &x);