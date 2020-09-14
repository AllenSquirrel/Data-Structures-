#ifndef LINKSTACK_H
#define LINKSTACK_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//��ʽջ�ڵ�  ��ҵ��ʽ�ṹ
typedef struct LINK_STACKNODE 
{
	struct LINK_STACKNODE* next;
}link_stackNode;

//��ʽջ
typedef struct LINKSTACK
{
	link_stackNode head;
	int size;
}link_stack;

//��ʼ������
link_stack* init_linkstack();

//��ջ
void push_linkstack(link_stack* stack,link_stackNode* data);

//��ջ
void pop_linkstack(link_stack* stack);

//����ջ��Ԫ��
link_stackNode* top_linkstack(link_stack* stack);

//����ջԪ�ظ���
int size_linkstack(link_stack* stack);

//���ջԪ��
void clear_linkstack(link_stack* stack);

//����
void free_linkstack(link_stack* stack);


#endif // !LINK_STACK_H
