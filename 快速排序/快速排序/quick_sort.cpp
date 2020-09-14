#include<iostream>

using namespace std;

void quick_sort(int arr[], int start, int end)
{
	int i = start;
	int j = end;
	int temp = arr[start];//基准数
	if (i < j)
	{
		while (i < j)
		{
			//从右向左  找比基准数小的
			while (i < j&&arr[j] >= temp)
			{
				j--;
			}
			//填坑
			if (i < j)
			{
				arr[i] = arr[j];
				i++;
			}
			//从左向右  找比基准数大的
			while (i < j&&arr[i] < temp)
			{
				i++;
			}
			//填坑
			if (i < j)
			{
				arr[j] = arr[i];
				j--;
			}
		}
		//把基准数放到i位置
		arr[i] = temp;
		//对左半部分快排
		quick_sort(arr, start, i - 1);

		//对右半部分快排
		quick_sort(arr, i + 1, end);
	}

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
	int myarr[] = {4,2,8,0,5,7,1,3,9};
	int len = sizeof(myarr) / sizeof(int);
	print_array(myarr,len);

	quick_sort(myarr,0,len-1);

	print_array(myarr,len);

	system("pause");
	return 0;
}