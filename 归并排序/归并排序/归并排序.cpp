#include<iostream>

using namespace std;
//合并
void Merge(int arr[], int start, int end, int mid, int* temp)
{
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;

	//表示辅助空间有多少个元素 temp为辅助空间
	int length = 0;
	//合并两个有序序列  先找出两个序列中的较小数 先安排在辅助空间存储  后续将两个序列剩余元素放入辅助空间
	while (i_start < i_end&&j_start < j_end)
	{
		if (arr[i_start] < arr[j_start])
		{
			temp[length] = arr[i_start];
			length++;
			i_start++;
		}
		else
		{
			temp[length] = arr[j_start];
			length++;
			j_start++;
		}
	}
	//剩余放入  i序列
	while (i_start <= i_end)
	{
		temp[length] = arr[i_start];
		length++;
		i_start++;
	}
	//剩余放入  j序列
	while (j_start <= j_end)
	{
		temp[length] = arr[j_start];
		length++;
		j_start++;
	}

	//辅助空间覆盖原空间
	for (int i = 0; i < length; i++)
	{
		arr[start + i] = temp[i]; // start+i 为了保证每次覆盖都不是从头0 开始
	}
}
//归并排序
void merge_sort(int arr[], int start, int end,int* temp)
{
	if (start >= end)
	{
		return;
	}
	int mid = (start + end) / 2;
	//分组
	//左半边
	merge_sort(arr,start,mid,temp);
	//右半边
	merge_sort(arr,mid+1,end,temp);
	//合并
	Merge(arr,start,end,mid,temp);
}

void print_array(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(void)
{
	int myarr[] = { 4,2,8,0,5,7,1,3,9 };
	int len = sizeof(myarr) / sizeof(int);
	print_array(myarr, len);

	//开辟辅助空间存储
	int* tmp = (int*)malloc(sizeof(int)*len);
	merge_sort(myarr, 0, len - 1, tmp);
	print_array(myarr, len);

	system("pause");
	return 0;
}