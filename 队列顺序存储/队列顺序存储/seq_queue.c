#include<string.h>
#include"seq_queue.h"

//��ʼ��
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

//���
void push_queue(seqqueue* queue, void* data)
{
	//������� Ĭ��Ϊ��ͷ 
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
	queue->data[queue->size] = data;//����ĩβ��Ϊ�����  ��β
	queue->size++;
}

//���ض�ͷԪ��
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

//����
void pop_queue(seqqueue* queue)
{
	//�Ӷ�β��  ��ͷ��
	//��Ҫ�ƶ�Ԫ��
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

//���ض�βԪ��
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

//���ش�С
int size_queue(seqqueue* queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	return queue->size;
}

//��ն���
void clear_queue(seqqueue* queue)
{
	if (queue == NULL)
	{
		return;
	}
	for (int i = 0; i < queue->size; i++)
	{
		queue->data[i] = NULL;//�ÿ�  �����ѡ�ɲ�ѡ  ���ж�ȡ��Ҫͨ��size����
	}
	queue->size=0;
}

//����
void free_queue(seqqueue* queue)
{
	if (queue == NULL)
	{
		return;
	}
	free(queue);
}