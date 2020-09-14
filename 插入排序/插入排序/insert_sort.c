#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<sys/timeb.h>

#define MAX 1000

long getsystemTime()//随机数种子
{
	struct timeb tb;
	ftime(&tb);
	return tb.time * 1000 + tb.millitm;
}

void swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void print_array(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
}

void insertsort(int arr[], int length)
{
	int j;
	for (int i = 1; i < length; i++)
	{
		if (arr[i] < arr[i - 1])//后面无序列元素  前面有序元素  后面数据往前插 与前面的数比大小 小了移动 大了不动（从小到大）
		{
			int temp = arr[i];//移动前 先缓存 即拿出要进行插入的元素
			for (j = i - 1; j >= 0 && temp < arr[j]; j--)
			{
				arr[j + 1] = arr[j];//与比较大小的元素需要后移填充腾空位置
			}
			arr[j + 1] = temp;//插入相应位置
		}
	}
}

int main()
{
	//随机创建序列  
	int arr[MAX];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++)
	{
		int randnum = rand() % MAX;
		arr[i] = randnum;
	}
	insertsort(arr,MAX);
	system("pause");
	return 0;
}