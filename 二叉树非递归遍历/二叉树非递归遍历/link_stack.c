#include<string.h>
#include"link_stack.h"

//初始化函数
link_stack* init_linkstack()
{
	link_stack* stack = (link_stack*)malloc(sizeof(link_stack));
	stack->head.next = NULL;
	stack->size = 0;
	return stack;
}

//入栈
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
	data->next = stack->head.next;//头插 以链表头作为栈顶
	stack->head.next = data;

	stack->size++;
}

//出栈
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

//返回栈顶元素
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

//返回栈元素个数
int size_linkstack(link_stack* stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	return stack->size;
}

//清空栈元素
void clear_linkstack(link_stack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	stack->head.next = NULL;
	stack->size = 0;
}

//销毁
void free_linkstack(link_stack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	free(stack);
}
