//栈的顺序存储
//利用一组地址连续的存储单元依次存放自栈底到栈顶的数据元素
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"seqstack.h"


//初始化栈
seqStack* init_seqstack()
{
	seqStack* stack = (seqStack*)malloc(sizeof(seqStack));
	for (int i = 0; i < MAX_SIZE; i++)
	{
		stack->data[i] = NULL;
	}
	stack->size = 0;

}

//入栈
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
	stack->data[stack->size] = data;//数组末尾作为栈入口(栈顶)  压栈到尾部
	stack->size++;
}


//返回栈顶元素
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
	return stack->data[stack->size - 1];//数组模拟 注意数组index从0开始
}

//出栈
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

//是否为空
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

//返回栈元素个数
int size_seqstack(seqStack*stack)
{
	return stack->size;
}

//清空栈元素
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
//释放销毁
void free_seqstack(seqStack*stack)
{
	if (stack == NULL)
	{
		return;
	}
	free(stack);
}