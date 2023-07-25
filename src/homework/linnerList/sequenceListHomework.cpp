#include "../../linerList/staticSequenceList.cpp"
/**
 * @file sequenceListHomework.cpp
 * @author xzc (xingzhicheng@imudges.com)
 * @brief 关于顺序表的一王道课后习题
 * @version 0.1
 * @date 2023-07-25
 *
 * @copyright Copyright (c) 2023
 *
 */
/*2.2.3 综合应用题
    01．从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。空出的位
        置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行。
*/
bool deleteMinEle(SqList &L, int &element)
{
    if (L.length == 0)
    {
        printf("Error:you can not execute delete operation on this list,because this list is empty!");
        return false;
    }
    int min = L.data[0], minIndex = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (min > L.data[i])
        {
            min = L.data[i];
            minIndex = i;
        }
    }
    element = min;
    L.data[minIndex] = L.data[L.length - 1];
    L.length--;
    return true;
}
void sol_2_2_3_01()
{
    printf("sol_2_2_3_01\n");
    SqList L;
    InitList(L);
    // Insert random data into the sequence list.
    for (int i = 0; i < 5; i++)
    {
        ListInsert(L, i + 1, 5 - i);
    }

    PrintList(L);
    int e = -1;
    deleteMinEle(L, e);
    printf("the minimum data is %d \n", e);
    printf("the list is as follows:\n");
    PrintList(L);
}
/*
02. 设计一个高效算法，将顺序表L 的所有元素逆置，要求算法的空间复杂度为O(1)。
*/
void inverseList(SqList &L)
{
    int temp = -1;
    for (int i = 0; i < L.length / 2; i++)
    {
        temp = L.data[i];
        L.data[i] = L.data[L.length - 1 - i];
        L.data[L.length - 1 - i] = temp;
    }
}
void sol_2_2_3_02()
{
    printf("sol_2_2_3_02\n");
    SqList L;
    InitList(L);
    // Insert random data into the sequence list.
    for (int i = 0; i < 5; i++)
    {
        ListInsert(L, i + 1, 5 - i);
    }
    printf("Initial list is as follows:\n");
    PrintList(L);
    inverseList(L);
    printf("Inverse list is as follows:\n");
    PrintList(L);
}

/*
03.对长度为n的顺序表L，编写一个时间复杂度为O（n）、空间复杂度为O（1）的算法，该算法删除线性表中所有值为x的数据元素。
*/
void deleteAllXEle(SqList &L, int e)
{
    int mark = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (mark != 0)
        {
            L.data[i - mark] = L.data[i];
        }
        if (L.data[i] == e)
        {
            mark++;
        }
    }
    L.length -= mark;
}
void sol_2_2_3_03()
{
    printf("sol_2_2_3_03\n");
    SqList L;
    InitList(L);

    for (int i = 0; i < 5; i++)
    {
        ListInsert(L, i + 1, (i) % 2);
    }
    printf("Initial list is as follows:\n");
    PrintList(L);
    deleteAllXEle(L, 0);
    printf("The list after deleting all elements with 0  is as follows:\n");
    PrintList(L);
}
/*
04．从有序顺序表中删除其值在给定值s与t之间（要求s＜t）的所有元素，若s或t不合理或顺序表为空，则显示出错信息并退出运行。
*/
bool deleteEllBetweenSAndT(SqList &L, int s, int t)
{
    if (L.length <= 0)
    {
        printf("Error:The list is empty and it do not support deleting operation!\n");
        return false;
    }
    if (s >= t)
    {
        printf("Error: The value of s must be smaller than the value of t!\n");
        return false;
    }
    int mark = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (mark != 0)
        {
            L.data[i - mark] = L.data[i];
        }
        if (L.data[i] < t && L.data[i] > s)
        {
            mark++;
        }
    }
    return true;
}
void sol_2_2_3_04()
{
    printf("sol_2_2_3_04\n");
    SqList L;
    InitList(L);

    for (int i = 0; i < 5; i++)
    {
        ListInsert(L, i + 1, i + 1);
    }
    printf("Initial list is as follows:\n");
    PrintList(L);
    if (deleteEllBetweenSAndT(L, 3, 5))
    {
        printf("The list after removing a range of values looks like this.\n");
        PrintList(L);
    }
}
int main()
{
    sol_2_2_3_04();

    return 0;
}