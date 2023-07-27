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
bool deleteEleBetweenSAndTInOrderList(SqList &L, int s, int t)
{
    // 删除有序顺序表L中值在给定值s与t之间的所有元素
    int i, j;
    if (s > t || L.length == 0)
        return false;
    for (i = 0; i < L.length && L.data[i] <= s; i++)
        ; // 找到第一个>s的第一个元素
    if (i >= L.length)
    {
        return false; // 没找到
    }
    for (j = i; j < L.length && L.data[j] < t; j++)
        ; // 找到第一个>t的元素
    for (; j < L.length; i++, j++)
    {
        L.data[i] = L.data[j];
    }
    L.length = i;
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
    if (deleteEleBetweenSAndTInOrderList(L, 1, 4))
    {
        printf("The list after removing a range of values looks like this.\n");
        PrintList(L);
    }
}

/*
05．从顺序表中删除其值在给定值s与t之间（要求s＜t）的所有元素，若s或t不合理或顺序表为空，则显示出错信息并退出运行。
*/
bool deleteEleBetweenSAndT(SqList &L, int s, int t)
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
void sol_2_2_3_05()
{
    printf("sol_2_2_3_05\n");
    SqList L;
    InitList(L);

    for (int i = 0; i < 5; i++)
    {
        ListInsert(L, i + 1, i + 1);
    }
    printf("Initial list is as follows:\n");
    PrintList(L);
    if (deleteEleBetweenSAndT(L, 3, 5))
    {
        printf("The list after removing a range of values looks like this.\n");
        PrintList(L);
    }
}

/*
06. 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
*/
bool deleteRepeatedElementsInList(SqList &L)
{
    if (L.length <= 1)
    {
        printf("该表没有重复元素！");
        return false;
    }
    int temp = L.data[0], mark = 0;
    for (int i = 1; i < L.length; i++)
    {
        if (mark > 0)
        {
            L.data[i - mark] = L.data[i];
        }
        if (L.data[i] == temp)
        {
            mark++;
        }
        else
        {
            temp = L.data[i];
        }
    }
    L.length = L.length - mark;
    return true;
}

void sol_2_2_3_06()
{
    printf("sol_2_2_3_06\n");
    SqList L;
    InitList(L);

    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 3);
    ListInsert(L, 4, 3);
    ListInsert(L, 5, 4);
    ListInsert(L, 6, 4);
    ListInsert(L, 7, 4);
    ListInsert(L, 8, 5);
    printf("Initial list is as follows:\n");
    PrintList(L);
    if (deleteRepeatedElementsInList(L))
    {
        printf("The list after removing a range of values looks like this.\n");
        PrintList(L);
    }
}

/*
07．将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表。

*/
bool merge(SqList LA, SqList LB, SqList &LC)
{
    if (LA.length + LB.length > MAXSIZE)
        return false;
    int i = 0, j = 0, k = 0;
    while (i < LA.length && j < LB.length)
    {
        if (LA.data[i] < LB.data[j])
        {
            LC.data[k++] = LA.data[i++];
        }
        else
        {
            LC.data[k++] = LB.data[j++];
        }
    }
    while (i < LA.length)
    {
        LC.data[k++] = LA.data[i++];
    }
    while (j < LB.length)
    {
        LC.data[k++] = LB.data[j++];
    }
    LC.length = k;
    return true;
}

void sol_2_2_3_07()
{
    printf("sol_2_2_3_07\n");
    SqList LA, LB, LC;
    InitList(LA);
    InitList(LB);
    InitList(LC);

    ListInsert(LA, 1, 1);
    ListInsert(LA, 2, 2);
    ListInsert(LA, 3, 5);
    ListInsert(LA, 4, 8);

    ListInsert(LB, 1, 3);
    ListInsert(LB, 2, 7);

    printf("Initial list is as follows:\n");
    PrintList(LC);
    if (merge(LA, LB, LC))
    {
        printf("The list after removing a range of values looks like this.\n");
        PrintList(LC);
    }
}

/*
08．已知在一维数组A［m＋n］中依次存放两个线性表（a1，a2，a3，，am）和（b1，b2，b3，，bn）。编写一
个函数，将数组中两个顺序表的位置互换，即将（b1，b2，b3，···，bn）放在（a1，a2，a3，···，am）的前面。
书上这个reverse不可以出现偶数
*/
//(AB)
typedef int DataType;
void reverse(DataType A[], int left, int right, int arraySize)
{
    // 逆转从left-right逆转这个序列
    if (left >= right || right >= arraySize)
        return;
    int mid = (left + right) / 2;
    for (int i = 0; i <= mid - left; i++)
    {
        DataType temp = A[left + i];
        A[left + i] = A[right - i];
        A[right - i] = temp;
    }
}
// 用到了02题中的逆置思想
void exchange(DataType A[], int m, int n, int arraySIze)
{
    reverse(A, 0, m + n - 1, arraySIze);

    printf("\n");
    reverse(A, 0, n - 1, n);
    printf("\n");
    reverse(A, n, m + n - 1, m);
    printf("\n");
}
void sol_2_2_3_08()
{
    SqList LA;
    InitList(LA);
    int m = 3, n = 4;
    for (int i = 0; i < m; i++)
    {
        ListInsert(LA, i + 1, i + 1);
    }
    for (int i = 0; i < n; i++)
    {
        ListInsert(LA, i + m + 1, i + m + 1);
    }
    PrintList(LA);
    exchange(LA.data, m, n, m + n);
    printf("+++++++++++++++++++\n");
    PrintList(LA);
}
/*
09．线性表（a1，a2，a3，，an）中的元素递增有序且按顺序存储于计算机内。要求设计一个算法，

完成用最少时间在表中查找数值为x的元素，若找到，则将其与后继元素位置相交换，若找不到，则将其插入表中并使表中元素仍递增有序。
1.二分查找然后插入
2.查找过程中找第一个比x大的值；如果发现有x的存在则交互该值与前一位；找不到则插到该值的前面；
3.这个题撸完二分查找的算法再来搞
*/
void searchExchangeInsert(DataType A[], DataType x, int n)
{
    int low = 0, high = n - 1, mid;
    // 二分查找
    while (low < high)
    {
        mid = (low + high) / 2;
        if (A[mid] == x)
            break;
        else if (A[mid] < x)
            low = mid + 1;
        else
            high = mid + 1;
    }
    // 若顺序表中有和x相等的元素
    if (A[mid] == x && mid != n - 1)
    {
        int t = A[mid];
        A[mid] = A[mid] + 1;
        A[mid + 1] = t;
    }
    // 若顺序表中没有和x相等的元素
    if (low > high)
    {
        for (int i = n - 1; i > high; i--)
        {
            A[i + 1] = A[i];
        }
        A[x + 1] = x;
    }
}
void sol_2_2_3_09()
{
    /*
    code-data
    */
}
/*
10．【2010统考真题】设将n（n＞1）个整数存放到一维数组R中。设计一个在时间和空间

两方面都尽可能高效的算法。将R中保存的序列循环左移p（0＜p＜n）个位置，即将R中的数据由（Xo，X1，，Xn-1）变换为（Xp，Xp＋1，，Xn-1，Xo，X1，···，Xp-1）。要求： 1）给出算法的基本设计思想。

2）根据设计思想，采用C或C＋＋或Java语言描述算法，关键之处给出注释。3）说明你所设计算法的时间复杂度和空间复杂度。
*/
void ringShiftLeft(DataType A[], int p, int n)
{
    reverse(A, 0, n - 1, sizeof(A) - 1);
    reverse(A, 0, n - 1 - p, sizeof(A) - 1);
    reverse(A, n - p, n - 1, sizeof(A) - 1);
}
void sol_2_2_3_10()
{
    SqList LA;
    InitList(LA);
    int m = 3;
    for (int i = 0; i < m; i++)
    {
        ListInsert(LA, i + 1, i + 1);
    }
    for (int i = 0; i < 4; i++)
    {
        ListInsert(LA, i + m + 1, i + m + 1);
    }
    PrintList(LA);
    ringShiftLeft(LA.data, 3, LA.length);
    printf("++++++++++++++\n");
    PrintList(LA);
}

/*
11．【2011统考真题】一个长度为L（L≥1）的升序序列S，处在第［L／2](向上取整函数)个位置的数称为S的中位数。
例如，若序列S1＝（11，13，15，17，19），则S1的中位数是15，两个序列的中位数是含它们所有元素的升序序列的中位数。
例如，若S2＝（2，4，6，8，20），则S1和S2的中位数是11。现在有两个等长升序序列A和B，试设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列A和B的中位数。
要求：
1）给出算法的基本设计思想。
2）根据设计思想，采用C或C＋＋或Java语言描述算法，关键之处给出注释。3）说明你所设计算法的时间复杂度和空间复杂度。
*/
// TODO
int main()
{
    sol_2_2_3_10();

    return 0;
}