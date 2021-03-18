#include"Sort.h"
//针对递归会造成栈溢出问题，所以有时候需要使用非递归方法来进行快速排序
//使用栈可以解决这个问题。栈来代替非递归问题
/*
 快排的非递归实现
void prevSortnod(int* a, int begin,int end)
{
	stack st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);
	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);
		int keyindex = PrevSort(a, left, right);
		if (left < keyindex - 1)
		{
			StackPush(&st, left);
			StackPush(&st, keyindex - 1);
		}
		if (keyindex + 1 < end)
		{
			StackPush(&st, keyindex+1);
			StackPush(&st, end);
		}
	}
}
*/


//因为有时候数据是有序的，这时候如果key值选的不好，会造成很大的时间复杂度，极低的浪费了时间效率，
//所以需要一种方式来选取key的值，这里提供一种叫做三数取中法
/*
int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) >> 1;
	if (a[begin] > a[mid])
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return end;
		}
		else         //a[end]>a[begin]
		{
			return begin;
		}
	}
	else             //a[begin]<a[mid]
	{
		if (a[begin] > a[end])
		{
			return begin;
		}
		else if (a[a[end] > a[mid]])
		{
			return mid;
		}
		else              //a[end]<a[mid]
		{
			return end;
		}
	}
}
*/



int main()
{
	int a[10] = { 4,4,3,6,3,8,8,7,1,0 };
	
	//InsertSort(a, sizeof(a) / sizeof(a[0]));
	print(a, sizeof(a)/sizeof(a[0]));


	//ShellSort(a, sizeof(a)/sizeof(a[0]));
	//print(a, sizeof(a) / sizeof(a[0]));

	//SelectSort(a, 10, 0, 9);
	//print(a, sizeof(a) / sizeof(a[0]));



	//HeapSort(a,10);
	//print(a, sizeof(a) / sizeof(a[0]));

	//ButtleSort(a, 10);
	//print(a, sizeof(a) / sizeof(a[0]));

	
	//QuickMethod(a, 0, 9);
	//print(a, sizeof(a) / sizeof(a[0]));

	//MergeSort(a,sizeof(a)/sizeof(a[0]));
	//print(a, sizeof(a) / sizeof(a[0]));


	CountSort(a, sizeof(a)/sizeof(a[0]));
	print(a, sizeof(a) / sizeof(a[0]));



	return 0;
}