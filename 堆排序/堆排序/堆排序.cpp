#include<iostream>

using namespace std;

void heap_swap(int arr[],int a, int b)
{
	int tmp;
	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}
//�ѵ���
void heap_adjust(int arr[], int index, int len)
{
	int max = index;//��¼��ǰ�ڵ����Ϊmax
	//������ȫ����������  ������ 2*i  ������ 2*i+1  ��¼���Һ����±�
	int lchild = index * 2 + 1;//�����0���� ���һ
	int rchild = index * 2 + 2;

	//�ж�
	if (lchild<len&&arr[lchild]>arr[max])
	{
		max = lchild;
	}
	if (rchild<len&&arr[rchild]>arr[max])
	{
		max = rchild;
	}
	if (max != index)//��Ҫ����
	{
		heap_swap(arr, max, index);
		heap_adjust(arr, max, len);//�ݹ�  �������������� ����������󶥶�
	}
}

//������

void heap_sort(int arr[], int length)
{
	//��1����ʼ����  �󶥶ѣ���󽻻�����С����
	for (int i = length / 2 - 1; i >= 0; i--) //����Ϊ�󶥶ѵĹ����У�������ȫ���������� ���м�Ԫ�أ�len/2����ʼ����
	{
		heap_adjust(arr,i,length);
	}
	//��2�������Ѷ������һ��Ԫ��  ���Բ�����󶥶ѽ����ٵ��� �ӶѶ���������i��Ԫ��
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


