//����ѭ������ 
//key��  ����жϱ��������Ƿ����
// (1)�ж�next�ǲ��ǵ���ͷ���
//��2��size�ж�
#include"circle_list.h"
#include<stdio.h>
#include<stdlib.h>

//��ʼ��
circle_linklist* init_circlelinklist()
{
	circle_linklist* list = (circle_linklist*)malloc(sizeof(circle_linklist));
	list->head.next = &(list->head);//ͷ���ָ���Լ�  ����ѭ���������ṹ
	list->size = 0;

	return list;
}
//����
void insert_circlelinklist(circle_linklist* clist, int pos, circle_listnode* data)
{
	if (clist == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	if (pos<0 || pos>clist->size)
	{
		pos = clist->size;
	}
	//��������ָ��  ������ѯλ��
	circle_listnode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	data->next = pCurrent->next;
	pCurrent->next = data;
	clist->size++;
}
//λ��ɾ��
void removebypos_circlelinklist(circle_linklist* clist, int pos)
{
	if (clist == NULL)
	{
		return;
	}
	
	if (pos<0 || pos>clist->size)
	{
		return;
	}
	//��������ָ��  ������ѯλ��
	circle_listnode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	circle_listnode* pNext = pCurrent->next;//���� �нӺ��������

	clist->size--;
}
//ֵɾ��
void removebyvalue_circlelinklist(circle_linklist* clist, circle_listnode* data, COMPARENODE compare)
{
	if (clist == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	circle_listnode* pPrev = &(clist->head);//˫�ڵ���Ʋ�ѯ
	circle_listnode* pCurrent = pPrev->next;
	for (int i = 0; i < clist->size; i++)
	{
		if (compare(pCurrent, data) == circle_TRUE)
		{
			pPrev->next = pCurrent->next;
			break;
		}
		pPrev = pCurrent;
		pCurrent = pPrev->next;
	}
}
//�ж��Ƿ�Ϊ��
int isempty_circlelinklist(circle_linklist* clist)
{
	if (clist->size == 0)
	{
		return circle_TRUE;
	}
	return circle_FALSE;
}
//���������
int size_circlelinklist(circle_linklist* clist)
{
	return clist->size;
}
//����
int find_circlelinklist(circle_linklist* clist, circle_listnode* data, COMPARENODE compare)
{
	if (clist == NULL)
	{
		return -1;
	}
	if (data == NULL)
	{
		return -1;
	}
	
	circle_listnode* pCurrent = clist->head.next;//�������ݵĿ�ʼ
	int flag = -1;
	for (int i = 0; i < clist->size; i++)
	{
		if (compare(pCurrent, data) == circle_TRUE)
		{
			flag = i;
			break;
		}
		pCurrent = pCurrent->next;
	}
	return flag;
}
//��ӡ
void print_circlelinklist(circle_linklist* clist,PRINTNODE print)
{
	if (clist == NULL)
	{
		return ;
	}
	
	circle_listnode* pCurrent = clist->head.next;//�������ݵĿ�ʼ
	int flag = -1;
	for (int i = 0; i < clist->size*2; i++)
	{
		if (pCurrent == &(clist->head))
		{
			pCurrent = pCurrent->next;
		}
		print(pCurrent);
		pCurrent = pCurrent->next;
	}
	
}
//�ͷ�
void free_circlelinklist(circle_linklist* clist)
{
	if (clist == NULL)
	{
		return;
	}
	free(clist);
}
