#include<string.h>
#include"link_stack.h"

//��ʼ������
link_stack* init_linkstack()
{
	link_stack* stack = (link_stack*)malloc(sizeof(link_stack));
	stack->head.next = NULL;
	stack->size = 0;
	return stack;
}

//��ջ
void push_linkstack(link_stack* stack, link_stackNode* data)
{
	if (stack == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	data->next = stack->head.next;//ͷ�� ������ͷ��Ϊջ��
	stack->head.next = data;

	stack->size++;
}

//��ջ
void pop_linkstack(link_stack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	if (stack->size == 0)
	{
		return;
	}
	link_stackNode* tmp = stack->head.next;
	stack->head.next = tmp->next;
	stack->size--;
}

//����ջ��Ԫ��
link_stackNode* top_linkstack(link_stack* stack)
{
	if (stack == NULL)
	{
		return NULL;
	}
	if (stack->size == 0)
	{
		return NULL;
	}
	return stack->head.next;
}

//����ջԪ�ظ���
int size_linkstack(link_stack* stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	return stack->size;
}

//���ջԪ��
void clear_linkstack(link_stack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	stack->head.next = NULL;
	stack->size = 0;
}

//����
void free_linkstack(link_stack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	free(stack);
}
