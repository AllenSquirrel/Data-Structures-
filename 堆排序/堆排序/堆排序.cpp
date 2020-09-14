#include<iostream>

using namespace std;

void heap_swap(int arr[],int a, int b)
{
	int tmp;
	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}
//堆调整
void heap_adjust(int arr[], int index, int len)
{
	int max = index;//记录当前节点序号为max
	//根据完全二叉树性质  左子树 2*i  右子树 2*i+1  记录左右孩子下标
	int lchild = index * 2 + 1;//数组从0计数 需加一
	int rchild = index * 2 + 2;

	//判断
	if (lchild<len&&arr[lchild]>arr[max])
	{
		max = lchild;
	}
	if (rchild<len&&arr[rchild]>arr[max])
	{
		max = rchild;
	}
	if (max != index)//需要交换
	{
		heap_swap(arr, max, index);
		heap_adjust(arr, max, len);//递归  继续调整新子树 交换后满足大顶堆
	}
}

//堆排序

void heap_sort(int arr[], int length)
{
	//（1）初始化堆  大顶堆（最后交换）从小到大
	for (int i = length / 2 - 1; i >= 0; i--) //调整为大顶堆的过程中，根据完全二叉树特性 从中间元素（len/2）开始调整
	{
		heap_adjust(arr,i,length);
	}
	//（2）交换堆顶和最后一个元素  并对不满足大顶堆进行再调整 从堆顶到倒数第i个元素
	for (int i = length - 1; i >= 0; i--)
	{
		heap_swap(arr, 0, i);
		heap_adjust(arr,0,i);
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
int main()
{
	int myarr[] = { 4,2,8,0,5,7,1,3,9 };
	int len = sizeof(myarr) / sizeof(int);
	print_array(myarr, len);
	heap_sort(myarr,len);
	print_array(myarr, len);
	system("pause");
	return 0;
}


