#include<iostream>

using namespace std;
//�ϲ�
void Merge(int arr[], int start, int end, int mid, int* temp)
{
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;

	//��ʾ�����ռ��ж��ٸ�Ԫ�� tempΪ�����ռ�
	int length = 0;
	//�ϲ�������������  ���ҳ����������еĽ�С�� �Ȱ����ڸ����ռ�洢  ��������������ʣ��Ԫ�ط��븨���ռ�
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
	//ʣ�����  i����
	while (i_start <= i_end)
	{
		temp[length] = arr[i_start];
		length++;
		i_start++;
	}
	//ʣ�����  j����
	while (j_start <= j_end)
	{
		temp[length] = arr[j_start];
		length++;
		j_start++;
	}

	//�����ռ串��ԭ�ռ�
	for (int i = 0; i < length; i++)
	{
		arr[start + i] = temp[i]; // start+i Ϊ�˱�֤ÿ�θ��Ƕ����Ǵ�ͷ0 ��ʼ
	}
}
//�鲢����
void merge_sort(int arr[], int start, int end,int* temp)
{
	if (start >= end)
	{
		return;
	}
	int mid = (start + end) / 2;
	//����
	//����
	merge_sort(arr,start,mid,temp);
	//�Ұ��
	merge_sort(arr,mid+1,end,temp);
	//�ϲ�
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

	//���ٸ����ռ�洢
	int* tmp = (int*)malloc(sizeof(int)*len);
	merge_sort(myarr, 0, len - 1, tmp);
	print_array(myarr, len);

	system("pause");
	return 0;
}