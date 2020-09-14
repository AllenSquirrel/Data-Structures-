#include<string.h>
#include"seq_queue.h"

//初始化
seqqueue* init_queue()
{
	seqqueue* queue = (seqqueue*)malloc(sizeof(seqqueue));
	for (int i = 0; i < MAX_SIZE; i++)
	{
		queue->data[i] = NULL;
	}
	queue->size = 0;
	return queue;
}

//入队
void push_queue(seqqueue* queue, void* data)
{
	//数组左边 默认为队头 
	if (queue == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	if (queue->size == MAX_SIZE)
	{
		return;
	}
	queue->data[queue->size] = data;//数组末尾作为队入口  队尾
	queue->size++;
}

//返回队头元素
void* front_queue(seqqueue* queue)
{
	if (queue == NULL)
	{
		return;
	}
	if (queue->size == 0)
	{
		return;
	}
	return queue->data[0];
}

//出队
void pop_queue(seqqueue* queue)
{
	//从队尾进  队头出
	//需要移动元素
	if (queue == NULL)
	{
		return;
	}
	if (queue->size == 0)
	{
		return;
	}
	for (int i = 0; i < queue->size; i++)
	{
		queue->data[i] = queue->data[i + 1];
	}
	queue->size--;
}

//返回队尾元素
void* back_queue(seqqueue* queue)
{
	if (queue == NULL)
	{
		return;
	}
	if (queue->size == 0)
	{
		return;
	}
	return queue->data[queue->size - 1];
}

//返回大小
int size_queue(seqqueue* queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	return queue->size;
}

//清空队列
void clear_queue(seqqueue* queue)
{
	if (queue == NULL)
	{
		return;
	}
	for (int i = 0; i < queue->size; i++)
	{
		queue->data[i] = NULL;//置空  此项可选可不选  队列读取主要通过size决定
	}
	queue->size=0;
}

//销毁
void free_queue(seqqueue* queue)
{
	if (queue == NULL)
	{
		return;
	}
	free(queue);
}