#include<stdio.h>
#include<stdlib.h>

//���Ա��������������Ԫ�ص���������
//���ԣ���1��Ԫ�ؼ���˳�� (2)Ԫ�ظ������ޣ�3��Ԫ�����ͱ�����ͬ

//*****************************************************************************
// (1)˳��洢�ṹ �����Ա�ִ�в��Ҳ���  �ɸ�������ֱ�Ӳ���  ʱ�临�Ӷ�O��1��
//��2��˳��洢�ṹ �����Ա�ִ�в���/ɾ������  ��Ҫƽ���ƶ���һ���Ԫ��   ʱ��ΪO��n��

//�ռ�洢����ҪԤ�ȷ���洢�ռ�  �ִ�->�ռ��˷�, ��С->���

//�����Ա���ҪƵ�����ң����ٽ��в���ɾ���������˲���˳��洢�ṹ

//*****************************************************************************

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int status;

typedef struct Aarea
{
	float data;//������
	
}ElemType;

typedef struct Node {
	ElemType *data;//������
	int length; //����
}list;
//typedef struct Node* list;//�������Ա�


status GetElem(list L, int i, ElemType *e)//��ȡ���Ա�ֵ
{
	if (L.length == 0 || i<1 || i>L.length)
	{
		return ERROR;
	}
	*e = L.data(i - 1);//���Ա��1��n   ʵ�ʴ洢��0��n
	return OK;
}
//*****************************************************************************
status LocateElem(list LA, ElemType *e)//�Ƚ����Ա�ֵ
{
	int LA_len, i;
	ElemType e;
	LA_len = ListLength(*LA);//��ȡ���Ա���
	
	for (i = 1; i < LA_len; i++)
	{
		if (LA.data(i - 1) == *e)
			return OK;
	}
	return ERROR;
	
}
//*****************************************************************************
status ListInsert(list L, , int i, ElemType *e)
{
	int k;
	if (L.length == MAXSIZE)
	{
		return ERROR;
	}
	if (i<1 || i>L.length)
	{
		return ERROR;
	}
	if (i <= L.length)
	{
		for (k = L.length - 1; k > i - 1; k--)
		{
			L.data[k + 1] = L.data[k];//����λ�ú�����Ԫ�������һλ
		}
	}
	L.data[i - 1] = e;//��Ԫ�ز����iλ��  ���Ա�iλ�ö�Ӧ�洢data��i-1λ��
	L.length++;

	return OK;
}
//*****************************************************************************
status ListDelete(list L, , int i, ElemType *e)
{
	int k;
	if (L.length == 0) //�˴�0 ��Ϊ��С����  С��0 ���޷�ɾ��
	{
		return ERROR;
	}
	if (i<1 || i>L.length)
	{
		return ERROR;
	}
	*e = L.data[i - 1];
	free(*e);
	if (i <= L.length)
	{
		for (k = i; k<L.length; k++)
		{
			L.data[k -1 1] = L.data[k];//ɾ��λ�ú�����Ԫ����ǰ��һλ
		}
	}
	
	L.length--;

	return OK;
}
//*****************************************************************************
void UnionL(list LA,list LB)//�������Ա��� �󲢼�
{
	int LA_len,LB_len,i;
	ElemType e;
	LA_len = ListLength(*LA);//��ȡ���Ա���
	LB_len = ListLength(LB);

	for (i = 1; i < LB_len; i++)
	{
		GetElem(LB,i.&e);//��ȡ���Ա�LB�е�i��Ԫ��ֵ ����ֵ��e�б���
		if (!LocateElem(*LA, e))//��LA�в����Ƿ������e����ͬԪ��
		{
			ListInsert(LA,++LA_len,e);//�����ظ���Ԫ����ӽ�LA
		}
	}
}