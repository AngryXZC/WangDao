#include <stdio.h>
// #include "../src/linerList/sequenceList/staticSequenceList.cpp"
// #include "../src/linerList/sequenceList/dynamicSequenList.cpp"
// #include "../src/linerList/linkedList/singleList.cpp"
#include "../src/linerList/linkedList/doubleLinkedList.cpp"
using namespace std;
// void testStaticSequenceList()
// {
// 	// 静态顺序表初探
// 	SqList L;
// 	InitList(L);
// 	for (int i = 0; i < 5; i++)
// 	{
// 		L.data[i] = i;
// 	}
// 	L.length = 5;
// 	// ListInsert(L, 3, 34);
// 	int e = 0;
// 	ListDelete(L, 3, e);
// }

// void testDynamicSequenceList()
// {
// 	// // 动态顺序表
// 	// SeqList L;
// 	// InitList(L);
// 	// //....往顺序表中随便加几个元素...
// 	// for (int i = 0; i < 5; i++)
// 	// {
// 	// 	L.data[i] = i;
// 	// }
// 	// L.length = 5;
// 	// IncreaseSize(L, 5);

// 	// 动态顺序表插入
// 	SeqList L;
// 	InitList(L);
// 	for (int i = 0; i < 5; i++)
// 	{
// 		L.data[i] = i;
// 	}
// 	L.length = 5;
// 	for (int i = 0; i < L.length; i++)
// 	{
// 		printf("Initial array index of %d,data is %d \n", i, L.data[i]);
// 	}

// 	ListInsert(L, 3, 34);
// 	for (int i = 0; i < L.length; i++)
// 	{
// 		printf("after Insert array index of %d,data is %d\n", i, L.data[i]);
// 	}
// }
// 测试单链表
// void testLinkedList()
// {
// 	LinkList L;
// 	// 初始化一个空表
// 	L = List_TailInsert(L);
// 	printf("%d", Length(L));
// }
// 测试双链表
void testDLinkList()
{
	DLinkList L;
	InitDlinkList(L);
}
int main(int argc, char *argv[])
{
	// 测试静态顺序表
	// testStaticSequenceList();
	// 测试动态顺序表
	//  testDynamicSequenceList();
	testDLinkList();
	return 0;
}
