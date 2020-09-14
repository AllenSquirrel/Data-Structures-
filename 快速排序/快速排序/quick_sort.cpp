#include<iostream>

using namespace std;

void quick_sort(int arr[], int start, int end)
{
	int i = start;
	int j = end;
	int temp = arr[start];//��׼��
	if (i < j)
	{
		while (i < j)
		{
			//��������  �ұȻ�׼��С��
			while (i < j&&arr[j] >= temp)
			{
				j--;
			}
			//���
			if (i < j)
			{
				arr[i] = arr[j];
				i++;
			}
			//��������  �ұȻ�׼�����
			while (i < j&&arr[i] < temp)
			{
				i++;
			}
			//���
			if (i < j)
			{
				arr[j] = arr[i];
				j--;
			}
		}
		//�ѻ�׼���ŵ�iλ��
		arr[i] = temp;
		//����벿�ֿ���
		quick_sort(arr, start, i - 1);

		//���Ұ벿�ֿ���
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