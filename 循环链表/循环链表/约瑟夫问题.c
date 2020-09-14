#include"circle_list.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define M 8
#define N 3
typedef struct num {
	circle_listnode node;
	int value;
}num;

//��ӡ�ص�����
void myprint(circle_listnode*data)
{
	num* p = (num*)data;//����ǿת
	printf("%d\t", p->value);
}

int mycompare(circle_listnode*data1, circle_listnode*data2)
{
	num*p1 = (num*)data1;
	num*p2 = (num*)data2;

	if (p1->value == p2->value)
	{
		return circle_TRUE;
	}
	return circle_FALSE;
}

int main()
{
	//����ѭ������
	circle_linklist* list= init_circlelinklist();
	//��������
	num n[M];
	for (int i = 0; i < M; i++)
	{
		n[i].value = i + 1;
		insert_circlelinklist(list,i,(circle_listnode*)&n[i]);
	}
	print_circlelinklist(list,myprint);


	//Լɪ������  8��Χ�� ѭ��������123-123-123... ��3�����˳�
	int index = 1;
	circle_listnode* pcurrent = list->head.next;
	while (size_circlelinklist(list) > 1)
	{
		if (index == N)
		{
			num* tmp = (num*)pcurrent;//��ʱ�ҵ�����ָ��ָ��Ľڵ�  ����ת�������
			printf("%d",tmp->value);

			// �˳�����  ��ɾ��  �����ɾ���ڵ����һ�ڵ�
			circle_listnode* pnext = pcurrent->next;
			//����ֵɾ��
			removebyvalue_circlelinklist(list, pcurrent, mycompare);
			pcurrent = pnext;

			//ѭ�������ж��Ƿ�ָ��ͷ���(���ѭ�� ����ͷ���)
			if (pcurrent = &(list->head))
			{
				pcurrent = pcurrent->next;
			}
			index = 1;
		}
		pcurrent = pcurrent->next;
		if (pcurrent = &(list->head))
		{
			pcurrent = pcurrent->next;
		}
		index++;
	}

	free_circlelinklist(list);
	return 0;
}