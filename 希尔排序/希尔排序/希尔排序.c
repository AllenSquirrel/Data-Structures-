#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<sys/timeb.h>

#define MAX 1000

long getsystemTime()//���������
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
		if (arr[i] < arr[i - 1])//����������Ԫ��  ǰ������Ԫ��  ����������ǰ�� ��ǰ������ȴ�С С���ƶ� ���˲�������С����
		{
			int temp = arr[i];//�ƶ�ǰ �Ȼ��� ���ó�Ҫ���в����Ԫ��
			for (j = i - 1; j >= 0 && temp < arr[j]; j--)
			{
				arr[j + 1] = arr[j];//��Ƚϴ�С��Ԫ����Ҫ��������ڿ�λ��
			}
			arr[j + 1] = temp;//������Ӧλ��
		}
	}
}
//ϣ���������ڲ�������Ļ����Ͻ��з���֮����е�����
//�������  increasement = increasement /3+ 1;
//������η��� ֱ��increasement<=1����  ÿһ�η��鶼�����һ�β����������
void shellsort(int arr[],int length)
{
	int increasement = length;
	int i, j,k;

	do {
		//ȷ�����������
		increasement = increasement /3+ 1;
		for (i = 0; i < increasement; i++)
		{
			for (int j = i+increasement; i < length; j+=increasement)
			{
				if (arr[i] < arr[j-increasement])//����������Ԫ��  ǰ������Ԫ��  ����������ǰ�� ��ǰ������ȴ�С С���ƶ� ���˲�������С����
				{
					int temp = arr[j];//�ƶ�ǰ �Ȼ��� ���ó�Ҫ���в����Ԫ��
					for (k = j - increasement; k >= 0 && temp < arr[k]; k-=increasement)
					{
						arr[k + increasement] = arr[k];//��Ƚϴ�С��Ԫ����Ҫ��������ڿ�λ��
					}
					arr[k + increasement] = temp;//������Ӧλ��
				}
			}
		}
	} while (increasement > 1);
}

int main()
{
	//�����������  
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