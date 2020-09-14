//ջ��˳��洢
//����һ���ַ�����Ĵ洢��Ԫ���δ����ջ�׵�ջ��������Ԫ��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"seqstack.h"


//��ʼ��ջ
seqStack* init_seqstack()
{
	seqStack* stack = (seqStack*)malloc(sizeof(seqStack));
	for (int i = 0; i < MAX_SIZE; i++)
	{
		stack->data[i] = NULL;
	}
	stack->size = 0;

}

//��ջ
void push_seqstack(seqStack*stack, void*data)
{
	if (stack == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	if (stack->size == MAX_SIZE)
	{
		return;
	}
	stack->data[stack->size] = data;//����ĩβ��Ϊջ���(ջ��)  ѹջ��β��
	stack->size++;
}


//����ջ��Ԫ��
void* top_seqstack(seqStack*stack)
{
	if (stack == NULL)
	{
		return;
	}
	if (stack->size == 0)
	{
		return;
	}
	return stack->data[stack->size - 1];//����ģ�� ע������index��0��ʼ
}

//��ջ
void pop_seqstack(seqStack*stack)
{
	if (stack == NULL)
	{
		return;
	}
	if (stack->size == 0)
	{
		return;
	}
	stack->data[stack->size - 1] = NULL;
	stack->size--;
}

//�Ƿ�Ϊ��
int isempty_seqstack(seqStack*stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	if (stack->size == 0)
	{
		return SEQSTACK_TRUE;
	}
	return SEQSTACK_FALSE;
}

//����ջԪ�ظ���
int size_seqstack(seqStack*stack)
{
	return stack->size;
}

//���ջԪ��
void clear_seqstack(seqStack*stack)
{
	if (stack == NULL)
	{
		return;
	}
	for (int i = 0; i < MAX_SIZE; i++)
	{
		stack->data[i] = NULL;
	}
	stack->size = 0;
}
//�ͷ�����
void free_seqstack(seqStack*stack)
{
	if (stack == NULL)
	{
		return;
	}
	free(stack);
}