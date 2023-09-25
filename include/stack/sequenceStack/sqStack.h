#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int top;
} SqStack;
// 初始化栈
void InitStack(SqStack &S);
// 判断栈空
bool StackEmpty(SqStack S);
// 新元素入栈
bool Push(SqStack &S, int x);
// 出栈操作
bool Pop(SqStack &S, int &x); // 返回x
// 读栈顶元素
bool GetTop(SqStack S, int &x);
// 后续共享栈的没实现了