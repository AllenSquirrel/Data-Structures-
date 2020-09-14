#include<stdio.h>
#include<stdlib.h>

#define OK 0
#define ERROR -1


//�����ڵ����ݽṹ ͨ���ṹָ������������
typedef struct Node {
	ElemType data;//������
	struct Node* next;//ָ����
}Node;
typedef struct Node* linklist;//����������
//*****************************************************************************
//Tencent������
//��������δ֪���ȵ������֮��ڵ�

//��ͨ�������ȱ���һ�鵥������ȷ����������L���ٴδ�ͷ�ڵ����ѭ��L/2���ҵ���������м�ڵ�
//�㷨���Ӷȣ�O(L+L/2)=O(3L/2)

//�߼����������ÿ���ָ��
//��������ָ��*search��*mid����ָ�������ͷ�ڵ� ����*search���ƶ��ٶ���*mid��2��  ��*searchָ��ĩβ�ڵ��ʱ��mid�������м�.

status GetMidNode(linklist L, ElemType *e)
{
	linklist search, mid;
	mid = search = L;//*search��*mid����ָ�������ͷ�ڵ�
	while (search->next != NULL)
	{
		if (search->next->next != NULL)//*search���ƶ��ٶ���*mid��2��
		{
			search = search->next->next;
			mid = mid->next;
		}
		else
		{
			search = search->next;
		}

	}
	*e = mid->data;
	return OK;
}