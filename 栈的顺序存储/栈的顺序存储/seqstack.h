#pragma once
#ifndef SEQSTACK_H
#define SEQSTACK_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//数组模拟栈顺序存储

#define MAX_SIZE 1024
#define SEQSTACK_TRUE 1
#define SEQSTACK_FALSE 0

typedef struct SEQSTACK {
	void* data[MAX_SIZE];
	int size;
}seqStack;

//初始化栈
seqStack* init_seqstack();

//入栈
void push_seqstack(seqStack*stack, void*data);

//返回栈顶元素
void* top_seqstack(seqStack*stack);

//出栈
void pop_seqstack(seqStack*stack);

//是否为空
int isempty_seqstack(seqStack*stack);

//返回栈元素个数
int size_seqstack(seqStack*stack);

//清空栈元素
void clear_seqstack(seqStack*stack);
//释放销毁
void free_seqstack(seqStack*stack);


#endif