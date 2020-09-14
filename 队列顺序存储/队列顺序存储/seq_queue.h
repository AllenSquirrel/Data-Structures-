#pragma once
#ifndef SEQQUEUE_H
#define SEQQUEUE_H

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 1024

//顺序队列结构体

typedef struct SEQQUEUE {
	void* data[MAX_SIZE];
	int size;
}seqqueue;


//初始化
seqqueue* init_queue();

//入队
void push_queue(seqqueue* queue, void* data);

//返回队头元素
void* front_queue(seqqueue* queue);

//出队
void pop_queue(seqqueue* queue);

//返回队尾元素
void* back_queue(seqqueue* queue);

//返回大小
int size_queue(seqqueue* queue);

//清空队列
void clear_queue(seqqueue* queue);

//销毁
void free_queue(seqqueue* queue);
#endif // !SEQQUEUE_H
