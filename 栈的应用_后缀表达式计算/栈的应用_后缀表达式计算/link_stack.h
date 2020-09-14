#ifndef LINKSTACK_H
#define LINKSTACK_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//链式栈节点  企业链式结构
typedef struct LINK_STACKNODE 
{
	struct LINK_STACKNODE* next;
}link_stackNode;

//链式栈
typedef struct LINKSTACK
{
	link_stackNode head;
	int size;
}link_stack;

//初始化函数
link_stack* init_linkstack();

//入栈
void push_linkstack(link_stack* stack,link_stackNode* data);

//出栈
void pop_linkstack(link_stack* stack);

//返回栈顶元素
link_stackNode* top_linkstack(link_stack* stack);

//返回栈元素个数
int size_linkstack(link_stack* stack);

//清空栈元素
void clear_linkstack(link_stack* stack);

//销毁
void free_linkstack(link_stack* stack);


#endif // !LINK_STACK_H
