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
	ListInsert(L, 3, 34);
}

// void testDynamicSequenceList(){
// 	// 动态顺序表
// 	SeqList L;
// 	InitList(L);
// 	//....往顺序表中随便加几个元素...
// 	IncreaseSize(L, 5);
// }
int main(int argc, char *argv[])
{
	testStaticSequenceList();
	return 0;
}
