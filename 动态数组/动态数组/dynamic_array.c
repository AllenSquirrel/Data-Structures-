#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dynamic_array.h>

//��̬�����ʼ��
Dynamic_array* Init_array()
{
	Dynamic_array* myarray = (Dynamic_array*)malloc(sizeof(Dynamic_array));//���ٵ�ַ�ռ�
	myarray->size = 0;//��ǰԪ������Ϊ0
	myarray->cap = 20;//Ĭ��������������Ϊ20
	myarray->pAddr = (int*)malloc(sizeof(int)*myarray->cap);//�����׵�ַ�ռ�

	return NULL;
}
//����
void pushback_array(Dynamic_array* arr, int value)
{
	if (arr == NULL)
	{
		return;
	}
	if (arr->size == arr->cap)//������Ԫ��  �ռ䲻��
	{
		//��һ�� ����һ����������Ŀռ�  �¿ռ��Ǿɿռ��2��
		int* newspace = (int*)malloc(sizeof(int)*arr->cap * 2);
		//�ڶ��� �������ݵ��¿ռ�
		memcpy(newspace,arr->pAddr,arr->cap*sizeof(int));
		//������ �ͷžɿռ��ڴ�
		free(arr->pAddr);

		//�������� ��ַ�ռ�
		arr->cap = arr->cap * 2;
		arr->pAddr = newspace;
	}
	//��ʼ����--β��
	arr->pAddr[arr->size] = value;//�����0��ʼ
	arr->size++;
}
//ɾ��ĳһλ��ֵ
void removebypos_array(Dynamic_array* arr, int pos)
{
	if (arr == NULL)
	{
		return;
	}
	if (pos<0 || pos>arr->size)
	{
		return;
	}
	for (int i = pos; i < arr->size - 1; i++)//ɾ��posλ��  ����Ԫ��ǰ��
	{
		arr->pAddr[i] = arr->pAddr[i + 1]; //��ʱ���һ��Ԫ�� ǰ�ƹ�������Ҫע�⵽arr->size��������Ϊ��
	}
	arr->size--;
}

//����ֵɾ��
void removebyval_array(Dynamic_array* arr, int value)
{
	int pos = -1;
	if (arr == NULL)
	{
		return ;
	}
	//����ɾ��ֵ��λ��
	pos = find_array(arr, value);
	/*for (int i = 0; i < arr->size; i++)
	{
		if (arr->pAddr[i] == value)
		{
			pos = i;
			break;
		}
	}*/
	//����λ��ɾ������
	removebypos_array(arr, pos);
}
//����
int find_array(Dynamic_array* arr, int value)
{
	int pos = -1;
	if (arr == NULL)
	{
		return -1;
	}
	for (int i = 0; i < arr->size; i++)
	{
		if (arr->pAddr[i] == value)
		{
			pos = i;
			break;
		}
	}
	return pos;
}
//�ͷ�
void freespace_array(Dynamic_array* arr)
{
	if (arr == NULL)
	{
		return;
	}
	if (arr->pAddr != NULL)
	{
		free(arr->pAddr);
	}
	free(arr);
}
//��ӡ��̬����Ԫ��
void print_array(Dynamic_array* arr)
{
	if (arr == NULL)
	{
		return;
	}
	for (int i = 0; i < arr->size; i++)
	{
		printf("%d ",arr->pAddr[i]);
	}
	printf("\n");
}
//�������
void clear_array(Dynamic_array* arr)
{
	if (arr == NULL)
	{
		return;
	}
	arr->size = 0;//ֱ������size=0��������Ԫ�� Ҳ���Ա�����������д����
}
//��ö�̬��������
int cap_array(Dynamic_array* arr)
{
	if (arr == NULL)
	{
		return -1;
	}
	return arr->cap;
}
//��ö�̬���鵱ǰԪ�ظ���
int size_array(Dynamic_array* arr)
{
	if (arr == NULL)
	{
		return -1;
	}
	return arr->size;
}
//����λ�û�ø�λ��Ԫ��
int at_array(Dynamic_array* arr, int pos)
{
	if (arr == NULL)
	{
		return -1;
	}
	return arr->pAddr[pos];
}