#pragma once
#ifndef CIRCLE_LIST
#define CIRCLE_LIST

//链表小节点  ..照顾头结点  入循环链表
typedef struct CIRCLE_LISTNODE
{
	struct CIRCLE_LISTNODE* next;
}circle_listnode;

typedef struct CIRCLE_LINKLIST
{
	circle_listnode head;
	int size;
}circle_linklist;
//比较回调
typedef int(*COMPARENODE)(circle_listnode*, circle_listnode*);
//打印回调
typedef void(*PRINTNODE)(circle_listnode*);
#define circle_TRUE 1
#define circle_FALSE 0
//初始化
circle_linklist* init_circlelinklist();
//插入
void insert_circlelinklist(circle_linklist* clist,int pos, circle_listnode* data);
//位置删除
void removebypos_circlelinklist(circle_linklist* clist, int pos);
//值删除
void removebyvalue_circlelinklist(circle_linklist* clist,circle_listnode* data,COMPARENODE compare);
//判断是否为空
int isempty_circlelinklist(circle_linklist* clist);
//获得链表长度
int size_circlelinklist(circle_linklist* clist);
//查找
int find_circlelinklist(circle_linklist* clist, circle_listnode* data, COMPARENODE compare);
//打印
void print_circlelinklist(circle_linklist* clist,PRINTNODE print);
//释放
void free_circlelinklist(circle_linklist* clist);
#endif // !CIRCLE_LIST
