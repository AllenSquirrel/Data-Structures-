#pragma once
#ifndef CIRCLE_LIST
#define CIRCLE_LIST

//����С�ڵ�  ..�չ�ͷ���  ��ѭ������
typedef struct CIRCLE_LISTNODE
{
	struct CIRCLE_LISTNODE* next;
}circle_listnode;

typedef struct CIRCLE_LINKLIST
{
	circle_listnode head;
	int size;
}circle_linklist;
//�Ƚϻص�
typedef int(*COMPARENODE)(circle_listnode*, circle_listnode*);
//��ӡ�ص�
typedef void(*PRINTNODE)(circle_listnode*);
#define circle_TRUE 1
#define circle_FALSE 0
//��ʼ��
circle_linklist* init_circlelinklist();
//����
void insert_circlelinklist(circle_linklist* clist,int pos, circle_listnode* data);
//λ��ɾ��
void removebypos_circlelinklist(circle_linklist* clist, int pos);
//ֵɾ��
void removebyvalue_circlelinklist(circle_linklist* clist,circle_listnode* data,COMPARENODE compare);
//�ж��Ƿ�Ϊ��
int isempty_circlelinklist(circle_linklist* clist);
//���������
int size_circlelinklist(circle_linklist* clist);
//����
int find_circlelinklist(circle_linklist* clist, circle_listnode* data, COMPARENODE compare);
//��ӡ
void print_circlelinklist(circle_linklist* clist,PRINTNODE print);
//�ͷ�
void free_circlelinklist(circle_linklist* clist);
#endif // !CIRCLE_LIST
