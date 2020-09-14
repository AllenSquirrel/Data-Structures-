#pragma once
#ifndef SEQQUEUE_H
#define SEQQUEUE_H

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 1024

//˳����нṹ��

typedef struct SEQQUEUE {
	void* data[MAX_SIZE];
	int size;
}seqqueue;


//��ʼ��
seqqueue* init_queue();

//���
void push_queue(seqqueue* queue, void* data);

//���ض�ͷԪ��
void* front_queue(seqqueue* queue);

//����
void pop_queue(seqqueue* queue);

//���ض�βԪ��
void* back_queue(seqqueue* queue);

//���ش�С
int size_queue(seqqueue* queue);

//��ն���
void clear_queue(seqqueue* queue);

//����
void free_queue(seqqueue* queue);
#endif // !SEQQUEUE_H
