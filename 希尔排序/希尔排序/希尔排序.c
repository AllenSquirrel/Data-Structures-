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
//希尔排序是在插入排序的基础上进行分组之后进行的排序
//分组规则  increasement = increasement /3+ 1;
//连续多次分组 直至increasement<=1结束  每一次分组都会调用一次插入排序规则
void shellsort(int arr[],int length)
{
	int increasement = length;
	int i, j,k;

	do {
		//确定分组的增量
		increasement = increasement /3+ 1;
		for (i = 0; i < increasement; i++)
		{
			for (int j = i+increasement; i < length; j+=increasement)
			{
				if (arr[i] < arr[j-increasement])//后面无序列元素  前面有序元素  后面数据往前插 与前面的数比大小 小了移动 大了不动（从小到大）
				{
					int temp = arr[j];//移动前 先缓存 即拿出要进行插入的元素
					for (k = j - increasement; k >= 0 && temp < arr[k]; k-=increasement)
					{
						arr[k + increasement] = arr[k];//与比较大小的元素需要后移填充腾空位置
					}
					arr[k + increasement] = temp;//插入相应位置
				}
			}
		}
	} while (increasement > 1);
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
	system("pause");
	return 0;
}