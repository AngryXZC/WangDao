/**
 * @file linkedListHomework.cpp
 * @author xzc (you@domain.com)
 * @brief 王道2.3.7综合应用题
 * @version 0.1
 * @date 2023-09-15
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "stdio.h"
#include "stdlib.h"
#include "../../../include/linerList/linkedList/singleList.h"
#include "../../../include/linerList/linkedList/circularlyDoubleLinkedList.h"
#include "../../../include/linerList/linkedList/circularlySingleLinkedList.h"
/*
01．设计一个递归算法，删除不带头结点的单链表L中所有值为x的结点。
*/
void deleteXNode(int x, LinkList L)
{
    if (L == NULL)
        return;
    LNode *q = L, *p;
    while (q->data != x && q != NULL)
    {
        p = q;
        q = L->next;
    }
    p->next = q->next; // 将新的列表置为x之后的列表
    if (q != NULL)
        free(q);
    p = p->next;
    return deleteXNode(x, p);
}
/*
02．在带头结点的单链表L中，删除所有值为x的结点，并释放其空间，假设值为x的结点不唯一，试编写算法以实现上述操作。
*/
void deleteXNodeWithHeadNode(LinkList L, int x)
{
    LNode *p = L;
    while (p->next != NULL)
    {
        if (p->next->data == x)
        {
            LNode *q = p->next;
            p->next = q->next;
            free(q);
        }
        p = p->next;
    }
    return;
}
/*03．设L为带头结点的单链表，编写算法实现从尾到头反向输出每个结点的值。*/
void invertedPrintList(LinkList &L)
{
    // 用数据模拟栈
    // 等把栈的数据结构构建出来再来搞
    // TODO
    int size = 100;
    LNode *a[100];
    LNode *q = L;
    int j = 0;
    while (q != NULL)
    {
        q = q->next;
        if (q != NULL)
            a[j] = q;
        j++;
    }
    for (int i = --j; i >= 0; i--)
    {

        printf("%d", a[i]->data);
    }
}
/* 04．试编写在带头结点的单链表L中删除一个最小值结点的高效算法（假设最小值结点是唯一的）。*/
void deleteMinElement(LinkList &L)
{
    int min = L->next->data;
    LNode *p = L, *q;
    while (p->next != NULL)
    {
        if (min > p->next->data)
        {
            min = p->next->data;
        }
        p = p->next;
    }
    q = q->next;
    free(q);
}
/*
05．试编写算法将带头结点的单链表就地逆置，所谓“就地”是指辅助空间复杂度为O（1）。
*/
void inverseTheLinkedList(LinkList L)
{
    // 空表或者只有一个元素没必要转置
    if (L->next == NULL || L->next->next == NULL)
        return;
    LNode *p = L;
    while (p != NULL)
    {
        L->next->next = p->next;
        p->next = L->next;
        L->next = p;
        p = p->next;
    }
}
/*06．有一个带头结点的单链表L，设计一个算法使其元素递增有序。*/

void sortLinked(LinkList &L)
{
    LNode *p = L->next, *pre;
    LNode *r = p->next;
    p->next = NULL;
    p = r;
    while (p != NULL)
    {
        r = p->next;
        pre = L;
        while (pre->next != NULL && pre->next->data < p->data)
            pre = pre->next;
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
}
/*07．设在一个带表头结点的单链表中所有元素结点的数据值无序，
试编写一个函数，删除表中所有介于给定的两个值（作为函数参数给出）之间的元素的元素（若存在）。*/
void deleteMiddleBetweenTwoNumber(LinkList &L, int min, int max)
{
    LNode *p = L->next;
    LNode *q = L;
    while (p != NULL)
    {
        if (p->data < max && p->data > min)
        {
            // delete这个节点
            q->next = p->next;
            free(p);
            p = p->next;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
}
/*08．给定两个单链表，编写算法找出两个链表的公共结点。*/
void findSameNodeInTwoList(LinkList &L1, LinkList &L2)
{
    // 默认res为初始化好头节点的链表
    LNode *firstListNode = L1->next, *secondListNode = L2->next, *res;
    int firstLen = -0, secondLen = -0;
    while (firstListNode != NULL)
    {
        firstLen++;
        firstListNode = firstListNode->next;
    }
    while (secondListNode != NULL)
    {
        secondLen++;
        secondListNode = secondListNode->next;
    }
    if (firstLen > secondLen)
    {
        firstListNode = L1->next;
        secondListNode = L2->next;
        for (int i = 0; i < firstLen - secondLen; i++)
        {
            firstListNode = firstListNode->next;
        }
        for (int i = 0; i < secondLen; i++)
        {
            if (firstListNode == secondListNode)
            {
                res = firstListNode;
                return;
            }
            firstListNode = firstListNode->next;
            secondListNode = secondListNode->next;
        }
    }
    else
    {
        firstListNode = L1->next;
        secondListNode = L2->next;
        for (int i = 0; i < secondLen - firstLen; i++)
        {
            secondListNode = secondListNode->next;
        }
        for (int i = 0; i < firstLen; i++)
        {
            if (firstListNode == secondListNode)
            {
                res = firstListNode;
                return;
            }
            firstListNode = firstListNode->next;
            secondListNode = secondListNode->next;
        }
    }
    res = NULL;
}
/*09.给定一个带表头结点的单链表，设head为头指针，结点结构为(data,next),data为整型元素，next为指针，
试写出算法：按递增次序输出单链表中各结点的数据元素，
并释放结点所占的存储空间（要求：不允许使用数组作为辅助空间）。*/
void printListDataFollowOrder(LinkList &H)
{
    LNode *p = H->next;
    while (p != NULL) // 直到链表删为空结束
    {
        p = H->next;                  // 遍历指针
        LNode *minNode = p, *pre = H; // 最小节点指针和前一个指针
        while (p != NULL)
        {
            if (p->data < minNode->data)
                minNode = p;
            p = p->next;
            pre = p;
        }
        printf("%d \n", minNode->data);
        pre->next = minNode->next;
        free(minNode);
    }
}
/*
10.将一个带头结点的单链表A分解为两个带头结点的单链表A和B,
使得A表中含有原表中序号为奇数的元素，
而B表中含有原表中序号为偶数的元素，
且保持其相对顺序不变。
*/
void splitList(LinkList &A, LinkList &B)
{
    bool isOdd = false;
    LNode *p = A->next, *pre = A; // 遍历指针;pre为p前一个指针
    LNode *tail = B;              // B表尾指针
    while (p != NULL)
    {
        if (isOdd)
        {
            // A表抛弃偶数节点
            LNode *delNode = p;
            pre->next = delNode->next;
            p = delNode->next;
            // B表尾插法
            tail->next = delNode;
            delNode->next = NULL;
            tail = delNode;
        }
        else
        {
            pre = p;
            p = p->next;
        }
        isOdd = !isOdd;
    }
}
/*11.设C={a1,b1,2,b2,·,am,bn}为线性表，采用带头结点的单链表存放，
设计一个就地算法，将其拆分为两个线性表，
使得
    A={a1,a2,·,an},
    B={bn,…,b2,b1}。
 */
void splitOrderList(LinkList &A)
{
    bool oddFlag = false;
    LNode *p = A->next, *q = NULL, *r = A;
    // 初始化q为带头结点的列表
    q = (LNode *)malloc(sizeof(LNode));
    while (p != NULL)
    {
        // 偶数时连到q后面
        if (oddFlag)
        {
            LNode *temp = p;
            // 不带头节点
            r->next = p->next;
            p = p->next;
            // 将temp插入q
            q->next = temp;
            temp->next = q->next;
        }
        else
        {
            r = p;
            p = p->next;
        }
        oddFlag = !oddFlag;
    }
}
/*
12.在一个递增有序的线性表中，有数值相同的元素存在。
若存储方式为单链表，设计算法去掉数值相同的元素，
使表中不再有重复的元素，
例如(7,10,10,21,30,42,42,42,51,70)将变为(7,10,21,30,42,51,70)。
*/
void deleteDuplication(LinkList &L)
{
    LNode *p = L->next, *q = L;
    if (p->next == NULL)
        return;
    while (p->next != NULL)
    {
        if (q->data == p->data)
        {
            // 删除p
            LNode *r = p;
            q->next = p->next;
            p = p->next;
            free(r);
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
}
/*
13.假设有两个按元素值递增次序排列的线性表，均以单链表形式存储。
请编写算法将这两个单链表归并为一个按元素值递减次序排列的单链表，并要求利用原来两个单链表的结点存放归并后的单链表。
*/
void mergeList(LinkList &La, LinkList &Lb)
{
    LNode *r, *pa = La->next, *pb = Lb->next;
    La->next = NULL;
    while (pa && pb)
    {
        if (pa->data <= pb->data)
        {
            r = pa->next;
            pa->next = La->next;
            La->next = pa;
            pa = r;
        }
        else
        {
            r = pb->next;
            pb->next = La->next;
            La->next = pb;
            pb = r;
        }
    }
    if (pa)
        pb = pa;
    while (pb)
    {
        r = pb->next;
        pb->next = La->next;
        La->next = pb;
        pb = r;
    }
    free(Lb);
}
/*
14.设A和B是两个单链表（带头结点)，其中元素递增有序。设计一个算法从A和B中的公共元素产生单链表C,要求不破坏A、B的结点。
*/
// 寻找两个有序单链表的交集
LinkList intersection(LinkList A, LinkList B)
{

    // pA和pB分别指向A、B的首元素
    LNode *pA = A->next;
    LNode *pB = B->next;

    // 初始化结果链表C
    LNode *C = (LNode *)malloc(sizeof(LNode));
    C->next = NULL;

    // tail指向C的尾结点
    LNode *tail = C;

    // 同步遍历pA和pB
    while (pA != NULL && pB != NULL)
    {

        // 如果当前元素相等,则为交集
        if (pA->data == pB->data)
        {

            // 生成新节点,数据域为当前公共元素
            LNode *tmp = (LNode *)malloc(sizeof(LNode));
            tmp->data = pA->data;
            tmp->next = NULL;

            // 将新节点加入C表尾
            tail->next = tmp;
            tail = tmp;

            // pA和pB指针后移
            pA = pA->next;
            pB = pB->next;
        }

        // pA当前元素更小,pA后移
        else if (pA->data < pB->data)
        {
            pA = pA->next;
        }

        // pB当前元素更小,pB后移
        else
        {
            pB = pB->next;
        }
    }

    // 返回C的头指针
    return C->next;
}
/*
15.已知两个链表A和B分别表示两个集合，其元素递增排列。编制函数，求A与B的交集，并存放于A链表中
*/
// 求两个有序链表的交集,并将结果存储在A中
LinkList intersection(LinkList A, LinkList B)
{

    // 结果链表C初始化,复制A的头结点
    LNode *C = (LNode *)malloc(sizeof(LNode));
    C->data = A->data;
    C->next = NULL;

    // pA、pB分别指向A、B的首元素
    LNode *pA = A->next;
    LNode *pB = B->next;

    // pC为C的首元素,tail指向C的尾部
    LNode *pC = C;
    LNode *tail = pC;

    // 同步遍历pA和pB
    while (pA && pB)
    {

        // 当前元素相等,生成新节点加入C
        if (pA->data == pB->data)
        {

            LNode *tmp = (LNode *)malloc(sizeof(LNode));
            tmp->data = pA->data;

            tail->next = tmp; // 链接至C尾部
            tail = tmp;

            pA = pA->next;
            pB = pB->next;
        }

        // pA元素更小,pA指针后移
        else if (pA->data < pB->data)
        {
            pA = pA->next;
        }

        // pB元素更小,pB指针后移
        else
        {
            pB = pB->next;
        }
    }

    // C连接至A后,A即为交集
    A->next = C->next;

    // 释放C头结点
    free(C);

    return A;
}
/*
16.两个整数序列A=a1,a2,a3,…,am和B=b1,b2,b3,…,bn已经存入两个单链表中，设计一个算法，判断序列B是否是序列A的连续子序列。
*/
// 判断链表B是否为链表A的连续子序列
bool isSubsequence(LinkList A, LinkList B)
{

    // 分别定义指向A和B头节点的指针
    LNode *pA = A->next;
    LNode *pB = B->next;

    // 遍历链表A
    while (pA != NULL)
    {

        // 当前节点值相等,匹配成功
        if (pA->data == pB->data)
        {

            // pB指针后移
            pB = pB->next;

            // pB到达末尾,返回匹配成功
            if (pB == NULL)
                return true;
        }

        // pA指针继续遍历下一个节点
        pA = pA->next;
    }

    // pB未完全遍历,匹配失败
    return (pB == NULL);
}
/*
17.设计一个算法用于判断带头结点的循环双链表是否对称
*/
// 判断双链表是否对称
bool isSymmetric(DLinkList head)
{

    // p、q指针均指向头结点
    DNode *p = head;
    DNode *q = head;

    // 同时遍历p和q,直到重合
    while (p != q)
    {

        // 对应节点值不相等,非对称
        if (p->data != q->data)
        {
            return false;
        }

        // p下一节点,q上一节点
        p = p->next;
        q = q->prior;
    }

    // p、q重合说明对称
    return true;
}
/*
18.有两个循环单链表，链表头指针分别为h1和h2,编写一个函数将链表h2链接到链表1之后，要求链接后的链表仍保持循环链表形式
*/
// 连接两个循环单链表,返回连接后链表的头指针
LinkList connect(LinkList h1, LinkList h2)
{

    // p指向h1尾节点
    LNode *p = h1;
    while (p->next != h1)
    {
        p = p->next;
    }

    // h1尾节点连接h2头节点
    p->next = h2;

    // q指向h2尾节点
    LNode *q = h2;
    while (q->next != h2)
    {
        q = q->next;
    }

    // h2尾节点连接h1头节点
    q->next = h1;

    // 返回连接后的循环链表头指针
    return h1;
}
/*
19.设有一个带头结点的循环单链表，其结点值均为正整数。
设计一个算法，反复找出单链表中结点值最小的结点并输出，
然后将该结点从中删除，直到单链表空为止，再删除表头结点。
*/
// 从循环链表中重复找到最小节点并输出删除,直到为空
void deleteMin(LinkList head)
{

    // min指向头节点
    LNode *min = head;
    // pre指向头节点
    LNode *pre = head;

    // 循环直到min指向空表
    while (min != NULL)
    {

        // 初始化min和pre为头节点
        pre = min;
        min = min->next;

        // 寻找最小节点
        while (min != head)
        {
            if (min->data < pre->next->data)
            {
                pre = pre->next;
            }
            min = min->next;
        }

        // 输出最小节点值
        printf("%d ", pre->next->data);
        // 记录下要删除的节点
        LNode *temp = pre->next;

        // 删除节点
        min = temp->next;
        pre->next = min;

        // 释放被删除节点内存
        free(temp);
        // 重置min和pre为头指针
        min = pre = head;
    }

    // 删除头节点
    free(head);
}
/*
20.设头指针为L的带有表头结点的非循环双向链表，其每个结点中除有pre(前驱指针)、data(数据)和next（后继指针)域外，还有一个访问频度域freq。
在链表被启用前，其值均初始化为零。
每当在链表中进行一次工Locate(L,x)运算时，令元素值为x的结点中freq域的值增1，
并使此链表中结点保持按访问频度非增（递减)的顺序排列，
同时最近访问的结点排在频度相同的结点前面，
以便使频繁访问的结点总是靠近表头。
试编写符合上述要求的Locate(L,x)运算的算法，该运算为函数过程，返回找到结点的地址，类型为指针型。

*/
// 查找值为x的节点并调整位置
// 查找值为x的节点并调整位置
DNode *Locate(DLinkList L, int x)
{
    DNode *current = L->next;

    while (current != NULL)
    {
        if (current->data == x)
        {
            // 找到值为x的节点，增加freq
            current->freq++;

            // 调整节点位置，确保按照访问频度非增顺序排列
            while (current->prior != L && current->freq > current->prior->freq)
            {
                // 交换节点位置
                current->prior->next = current->next;
                if (current->next != NULL)
                {
                    current->next->prior = current->prior;
                }
                current->next = current->prior;
                current->prior = current->prior->prior;
                current->next->prior = current;
                if (current->prior == L)
                {
                    L->next = current;
                }
                else
                {
                    current->prior->next = current;
                }
            }

            return current;
        }

        current = current->next;
    }

    // 如果没有找到值为x的节点，返回NULL
    return NULL;
}
/*21 单链表有环，是指单链表的最后一个结点的指针指向了链表中的某个结点（通常单链表的最后一个结点的指针域是空的)。
试编写算法判断单链表是否存在环。
1)给出算法的基本设计思想。
2)根据设计思想，采用C或C++语言描述算法，关键之处给出注释*/
/**
 * @brief 判断单链表是否存在环的基本设计思想是使用两个指针，一个慢指针（通常每次前进一步）和一个快指针（通常每次前进两步）同时遍历链表。
 * 如果链表中存在环，
 * 那么快指针最终会追上慢指针，如果链表不存在环，
 * 快指针会提前到达链表尾部。
 */
// 判断单链表是否存在环
bool hasCycle(LinkList head)
{
    if (head == NULL || head->next == NULL)
    {
        // 空链表或只有一个节点的链表一定没有环
        return false;
    }

    LNode *slow = head;       // 慢指针，每次前进一步
    LNode *fast = head->next; // 快指针，每次前进两步

    while (slow != fast)
    {
        if (fast == NULL || fast->next == NULL)
        {
            // 如果快指针到达链表尾部，说明没有环
            return false;
        }

        slow = slow->next;       // 慢指针前进一步
        fast = fast->next->next; // 快指针前进两步
    }

    // 如果快指针追上了慢指针，说明链表存在环
    return true;
}
/*
22.【2009统考真题】
已知一个带有表头结点的单链表,结点结构为[data,link]假设该链表只给出了头指针list。
在不改变链表的前提下，
请设计一个尽可能高效的算法，
查找链表中倒数第k个位置上的结，点(k为正整数)。
若查找成功，算法输出该结点的data域的值，
并返回1;否则，只返回0。
要求：
1)描述算法的基本设计思想。
2)描述算法的详细实现步骤。
3)根据设计思想和实现步骤，采用程序设计语言描述算法（使用C、C++或Java语言）
*/
// 查找单链表中倒数第k个节点的数据域值
int findKthFromEnd(LinkList list, int k)
{
    if (list == NULL || k <= 0)
    {
        return 0; // 输入无效，返回0表示失败
    }

    LNode *fast = list->next; // 快指针
    LNode *slow = list->next; // 慢指针

    // 让快指针先走k步
    for (int i = 0; i < k; i++)
    {
        if (fast == NULL)
        {
            return 0; // k 大于链表长度，返回0表示失败
        }
        fast = fast->next;
    }

    // 同时移动快指针和慢指针，直到快指针到达链表末尾
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    // 此时慢指针所指的节点就是倒数第k个节点
    return slow->data;
}
/*
23.【2012统考真题】假定采用带头结点的单链表保存单词，
当两个单词有相同的后缀时，可共享相同的后缀存储空间，
例如，loading和being的存储映像如下图所示。
略
设str1和str2分别指向两个单词所在单链表的头结点，
链表结点结构为[data|next]
请设计一个时间上尽可能高效的算法，
找出由str1和st2所指向两个链表共同后缀的起始位置
要求：1)给出算法的基本设计思想。
2)根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释。
3)说明你所设计算法的时间复杂度。
*/
// 计算链表的长度
int getLength(LinkList list)
{
    int length = 0;
    LNode *current = list->next;
    while (current != NULL)
    {
        length++;
        current = current->next;
    }
    return length;
}

// 反转链表的函数
LNode *reverseList(LinkList list)
{
    LNode *prev = NULL;
    LNode *current = list->next;
    while (current != NULL)
    {
        LNode *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->next = prev;
    return list;
}

// 找出两个链表的共同后缀的起始位置
LNode *findCommonSuffixStart(LinkList str1, LinkList str2)
{
    str1 = reverseList(str1); // 反转str1链表
    str2 = reverseList(str2); // 反转str2链表

    int len1 = getLength(str1); // 计算str1的长度
    int len2 = getLength(str2); // 计算str2的长度

    LNode *p1 = str1->next; // 指向str1的第一个节点
    LNode *p2 = str2->next; // 指向str2的第一个节点

    // 将两个指针移动到长度相同的位置
    for (int i = 0; i < abs(len1 - len2); i++)
    {
        if (len1 > len2)
        {
            p1 = p1->next;
        }
        else
        {
            p2 = p2->next;
        }
    }

    // 逐个比较节点，找到第一个不相同的节点
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data != p2->data)
        {
            return p1->next; // 返回共同后缀的起始位置
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return NULL; // 没有共同后缀
}

/*24.【2015统考真题】
    用单链表保存m个整数结，点的结构为[data|link],且|data|≤n(n为正整数)。
    现要求设计一个时间复杂度尽可能高效的算法，对于链表中data的绝对值相等的结点，仅保留第一次出现的结点而删除其余绝对值相等的结点。
    例如，若给定的单链表head如下：
    略
    要求：
        1)给出算法的基本设计思想。
        2)使用C或C++语言，给出单链表结，点的数据类型定
        3)根据设计思想，采用C或C++语言描述算法，关键之处给出注释
        4)说明你所设计算法的时间复杂度和空间复杂度。
*/
// 移除单链表中数据绝对值相等的多余节点
LinkList removeDuplicateAbsoluteValues(LinkList head)
{
    if (head == NULL)
    {
        return NULL;
    }

    LinkList current = head; // 当前节点
    LinkList prev = NULL;    // 前一个节点
    LinkList result = head;  // 结果链表的头指针

    // 哈希表，用于存储已出现的绝对值
    int hashTable[10001] = {0}; // 假设数据的绝对值不超过10000

    while (current != NULL)
    {
        int absValue = abs(current->data);

        // 如果绝对值已经出现过，删除当前节点
        if (hashTable[absValue] == 1)
        {
            prev->next = current->next;
            free(current);
            current = prev->next;
        }
        else
        {
            hashTable[absValue] = 1; // 将绝对值加入哈希表
            prev = current;
            current = current->next;
        }
    }

    return result;
}
/*
25.【2019统考真题】设线性表L=(a,a2,a3,…,an-2,an-1,an)采用带头结点的单链表保存，
链表中的结点定义如下：
typedef struct node
{
    int data;           // Data Area
    struct node *next; // Pointer Field
} NODE;
请设计一个空间复杂度为O(1)且时间上尽可能高效的算法，重新排列L中的各结点，
得到线性表L'=(a,an,a2,an-1,a,an-2,)。
要求：
1)给出算法的基本设计思想。
2)根据设计思想，采用C或C++语言描述算法，关键之处给出注释。
3)说明你所设计的算法的时间复杂度。
*/
// 反转链表的函数
// 定义单链表节点结构体
typedef struct node
{
    int data;          // 数据域
    struct node *next; // 指针域
} NODE;
NODE *reverseList(NODE *head)
{
    NODE *prev = NULL;
    NODE *current = head;
    while (current != NULL)
    {
        NODE *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
// 重新排列链表的函数
void rearrangeList(NODE *head)
{
    if (head == NULL || head->next == NULL)
    {
        return; // 空链表或只有一个节点，无需重排
    }

    // 使用快慢指针找到链表的中间节点
    NODE *slow = head;
    NODE *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 反转后半部分的链表
    NODE *secondHalf = reverseList(slow->next);
    slow->next = NULL;

    // 合并前半部分和反转后的后半部分
    NODE *p1 = head;
    NODE *p2 = secondHalf;
    while (p2 != NULL)
    {
        NODE *temp1 = p1->next;
        NODE *temp2 = p2->next;
        p1->next = p2;
        p2->next = temp1;
        p1 = temp1;
        p2 = temp2;
    }
}

int main()
{
    printf("%s", "kkkk");
    return 0;
}