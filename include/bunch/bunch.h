
#include "stdlib.h"
#include "stdio.h"
#define MAXLEN 255 // 预定义最大串长为255
typedef struct
{
    char ch[MAXLEN];
    int length;
} SString;

typedef struct
{
    char *ch;
    int length;
} HString;
// 链式存储
typedef struct StringNode
{
    char ch[4]; // 每个结点存一个字符
    struct StringNode *next;
} StringNode, *String;
// 求长度
int StrLength(SString S);
// 截取字符串
void SubString(SString &sub, SString S, int i, int m);
int StrCompare(SString S, SString T);
// 定位操作（其实就是朴素匹配算法）
int Index(SString S, SString T);

// 朴素匹配模式算法
// 最坏的时间复杂度为O((n-m+1)m)=O(nm)
int IndexWithoutBaseOp(SString S, SString T);
// KMP算法
// 最坏的时间复杂度为O(m+n)
int Index_KMP(SString S, SString T, int next[]);
// 根据next数组求nextval数组
void NextVal(SString T, int next[]);