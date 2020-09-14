#pragma once
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include<stdio.h>
#include<stdlib.h>

typedef struct DYNAMIC_ARRAY
{
	int* pAddr;//������ݵ�ַ
	int size;//��¼��ǰ�ж��ٸ�Ԫ��
	int cap;//���� ��ǰ�ܹ����������Ԫ��

}Dynamic_array;

//����API����
//��ʼ��
Dynamic_array* Init_array();
//����
void pushback_array(Dynamic_array* arr,int value);
//ɾ��ĳһλ��ֵ
void removebypos_array(Dynamic_array* arr, int pos);
//����ֵɾ��
void removebyval_array(Dynamic_array* arr, int value);
//����
int find_array(Dynamic_array* arr, int value);
//�ͷŶ�̬�����ڴ�
void freespace_array(Dynamic_array* arr);
//��ӡ��̬����Ԫ��
void print_array(Dynamic_array* arr);
//�������
void clear_array(Dynamic_array* arr);
//��ö�̬��������
int cap_array(Dynamic_array* arr);
//��ö�̬���鵱ǰԪ�ظ���
int size_array(Dynamic_array* arr);
//����λ�û�ø�λ��Ԫ��
int at_array(Dynamic_array* arr,int pos);
#endif // !DYNAMIC_ARRAY_H
