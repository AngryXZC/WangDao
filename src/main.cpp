#include <stdio.h>
#include "../src/linerList/staticSequenceList.cpp"
// #include "../src/linerList/dynamicSequenList.cpp"
using namespace std;
void testStaticSequenceList()
{
	// 静态顺序表初探
	SqList L;
	InitList(L);
	for (int i = 0; i < 5; i++)
	{
		L.data[i] = i;
	}
	L.length = 5;
	// ListInsert(L, 3, 34);
	int e = 0;
	ListDelete(L, 3, e);
}

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
int main(int argc, char *argv[])
{
	// 测试静态顺序表
	testStaticSequenceList();
	// 测试动态顺序表
	//  testDynamicSequenceList();
	return 0;
}
