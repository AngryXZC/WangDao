#include "../../include/bunch/bunch.h"
// 比较操作
int StrCompare(SString S, SString T)
{
    for (int i = 0; i < = S.length && i <= T.length; i++)
    {
        if (S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    }
    return S.length - T.length;
}
int Index(SString S, SString T)
{
    int i = 1, n = StrLength(s), m = StrLength(T);
    SString sub; // 暂存子串
    while (i <= n - m + 1)
    {
        SubString(sub, S, i, m);
        if (StrCompare(sub, T) != 0)
            ++i;
        else
            return i // 返回子串在主串中的位置
    }
    return 0; // S中不存在和T相等的子串
}

int IndexWithoutBaseOp(SString S, SString T)
{
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length)
    {
        if (S.ch[i] == T.ch[i])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T.length)
        return i - T.length;
    else
        return 0;
}
int Index_KMP(SString S, SString T, int next[])
{
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length)
    {
        if (j == 0 || S.ch[i] == T.ch[j])
        {
            ++i;
            ++j; // 继续比较后继字符
        }
        else
        {
            j = next[j]; // 模式串向右移动
        }
        if (j > T.length)
            return i - T.length; // 匹配成功
    }
}
void NextVal(SString T, int next[])
{
    int nextval[5];
    nextval[1] = 0;
    for (int j = 0; j < T.length; j++)
    {
        if (T.ch[next[j]] == T.ch[j])
            nextval[j] = nextval[next[j]];
        else
            nextval[j] = next[j];
    }
}