#include "Sort.h"

//打印函数
void print(int* a, int n)
{
	for (int i = 0; i < n ; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//直接插入排序
void  InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end=i;
		int temp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > temp)
			{
				a[end + 1] = a[end ];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = temp;
	}
	
}


void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;

		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int temp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > temp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = temp;
		}
	}
}



void SelectSort(int* a,int n, int begin,int end)
{
	
	while (begin < end)
	{
		int mini = begin;
		int maxi = end;
		for (int i = begin; i <= end; i++)
		{
			if (a[mini] > a[i])
			{
				mini = i;
			}
			if (a[maxi] < a[i])
			{
				maxi = i;
			}
		}
		
		int temp1 = a[mini];
		a[mini] = a[begin];
		a[begin] = temp1;
		if (maxi == begin)
		{
			maxi=mini;
		}
		int temp2 = a[maxi];
		a[maxi] = a[end];
		a[end] = temp2;
		begin++;
		end--;
	}
}

void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child+1<n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			int temp = a[child];
			a[child] = a[parent];
			a[parent] = temp;
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}


void HeapSort(int* a, int n)
{
	//建堆
	for (int i =(n-2)/2 ; i >=0; i--)
	{
		AdjustDown(a, n, i);
	}
	//排序
	int end = n - 1;
	while (end>0)
	{
		int temp = a[end];
		a[end] = a[0];
		a[0] = temp;
		AdjustDown(a, end, 0);
		end--;
	}
}



void ButtleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
	}
}



int  HoareMethod(int* a,int begin,int end)
{
	int key = a[end];
	int keyindex = end;
	while (begin < end)
	{
		while (begin < end && a[begin] <=key)
		{
			begin++;
		}
		while (begin<end && a[end]>=key)
		{
			end--;
		}
		int temp = a[end];
		a[end] = a[begin];
		a[begin] = temp;
	}
	int temp1= a[keyindex];
	a[keyindex] = a[begin];
	a[begin] = temp1;
	return begin;
}

int HoleMethod(int* a, int begin, int end)
{
	int key = a[end];
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		
		a[end] = a[begin];
		
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		a[begin] = a[end];
	}

	a[begin] = key;
	return begin;
}


int PrevSort(int* a, int begin, int end)
{
	int cur = begin;
	int prev = begin - 1;
	int key = a[end];
	int keyindex = end;
	while (cur < end)
	{
		if (a[cur] < key&&++prev!=cur)
		{
			
			int temp = a[prev];
			a[prev] = a[cur];
			a[cur] = temp;
		}
		cur++;
	}
	prev++;
	int temp2 = a[keyindex];
	a[keyindex] = a[prev];
	a[prev] = temp2;
	return prev;
}

void  QuickMethod(int* a,  int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	//int index = HoareMethod(a, begin, end);
	int index = PrevSort(a, begin, end);
	QuickMethod(a, 0, index - 1);
	QuickMethod(a, index+1, end);

}


void _MergeSort(int* a, int begin, int end, int* temp)
{

	if (begin >= end)
	{
		return;
	}
	int mid = (begin + end) >> 1;//右移相当于除，左移相当于乘

	int i = begin;
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	_MergeSort(a, begin, mid, temp);
	_MergeSort(a, mid + 1, end2, temp);
	
	while (begin1 <= end1 && begin2 <= end)
	{
		if (a[begin1] > a[begin2])
		{
			temp[i++] = a[begin2++];
		}
		else
		{
			temp[i++] = a[begin1++];
		}
	}
	while (begin1 <= end1)
	{
		temp[i++] = a[begin1++];
	}
	while (begin2 <= end)
	{
		temp[i++] = a[begin2++];
	}
	memcpy(a+begin, temp+begin, sizeof(int) * (end - begin+1));
}



void MergeSort(int* a, int n)
{
	int* temp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, temp);
	free(temp);
}


void CountSort(int* a, int n)
{
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	int range = max - min + 1;
	int* CountArr = (int*)malloc(sizeof(int)*range);
	memset(CountArr, 0, sizeof(int) * range);
	if (CountArr == NULL)
	{
		exit(-1);
	}

	//统计每个数出现次数
	for (int i = 0; i < n; i++)
	{
		CountArr[a[i] - min]++;
	}
	//放回数组
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (CountArr[i]>0)
		{
			a[j++] = i + min;
			CountArr[i]--;
		}
	}
	free(CountArr);
}