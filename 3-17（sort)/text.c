#include"Sort.h"
//��Եݹ�����ջ������⣬������ʱ����Ҫʹ�÷ǵݹ鷽�������п�������
//ʹ��ջ���Խ��������⡣ջ������ǵݹ�����
/*
 ���ŵķǵݹ�ʵ��
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


//��Ϊ��ʱ������������ģ���ʱ�����keyֵѡ�Ĳ��ã�����ɺܴ��ʱ�临�Ӷȣ����͵��˷���ʱ��Ч�ʣ�
//������Ҫһ�ַ�ʽ��ѡȡkey��ֵ�������ṩһ�ֽ�������ȡ�з�
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