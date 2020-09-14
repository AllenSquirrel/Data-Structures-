#pragma once
#ifndef SEQSTACK_H
#define SEQSTACK_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//����ģ��ջ˳��洢

#define MAX_SIZE 1024
#define SEQSTACK_TRUE 1
#define SEQSTACK_FALSE 0

typedef struct SEQSTACK {
	void* data[MAX_SIZE];
	int size;
}seqStack;

//��ʼ��ջ
seqStack* init_seqstack();

//��ջ
void push_seqstack(seqStack*stack, void*data);

//����ջ��Ԫ��
void* top_seqstack(seqStack*stack);

//��ջ
void pop_seqstack(seqStack*stack);

//�Ƿ�Ϊ��
int isempty_seqstack(seqStack*stack);

//����ջԪ�ظ���
int size_seqstack(seqStack*stack);

//���ջԪ��
void clear_seqstack(seqStack*stack);
//�ͷ�����
void free_seqstack(seqStack*stack);


#endif