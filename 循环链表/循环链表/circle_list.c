//单向循环链表 
//key：  如何判断遍历链表是否结束
// (1)判断next是不是等于头结点
//（2）size判断
#include"circle_list.h"
#include<stdio.h>
#include<stdlib.h>

//初始化
circle_linklist* init_circlelinklist()
{
	circle_linklist* list = (circle_linklist*)malloc(sizeof(circle_linklist));
	list->head.next = &(list->head);//头结点指向自己  符合循环链表创建结构
	list->size = 0;

	return list;
}
//插入
void insert_circlelinklist(circle_linklist* clist, int pos, circle_listnode* data)
{
	if (clist == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	if (pos<0 || pos>clist->size)
	{
		pos = clist->size;
	}
	//借助辅助指针  遍历查询位置
	circle_listnode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	data->next = pCurrent->next;
	pCurrent->next = data;
	clist->size++;
}
//位置删除
void removebypos_circlelinklist(circle_linklist* clist, int pos)
{
	if (clist == NULL)
	{
		return;
	}
	
	if (pos<0 || pos>clist->size)
	{
		return;
	}
	//借助辅助指针  遍历查询位置
	circle_listnode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	circle_listnode* pNext = pCurrent->next;//缓存 承接后面的链表

	clist->size--;
}
//值删除
void removebyvalue_circlelinklist(circle_linklist* clist, circle_listnode* data, COMPARENODE compare)
{
	if (clist == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	circle_listnode* pPrev = &(clist->head);//双节点后移查询
	circle_listnode* pCurrent = pPrev->next;
	for (int i = 0; i < clist->size; i++)
	{
		if (compare(pCurrent, data) == circle_TRUE)
		{
			pPrev->next = pCurrent->next;
			break;
		}
		pPrev = pCurrent;
		pCurrent = pPrev->next;
	}
}
//判断是否为空
int isempty_circlelinklist(circle_linklist* clist)
{
	if (clist->size == 0)
	{
		return circle_TRUE;
	}
	return circle_FALSE;
}
//获得链表长度
int size_circlelinklist(circle_linklist* clist)
{
	return clist->size;
}
//查找
int find_circlelinklist(circle_linklist* clist, circle_listnode* data, COMPARENODE compare)
{
	if (clist == NULL)
	{
		return -1;
	}
	if (data == NULL)
	{
		return -1;
	}
	
	circle_listnode* pCurrent = clist->head.next;//从有数据的开始
	int flag = -1;
	for (int i = 0; i < clist->size; i++)
	{
		if (compare(pCurrent, data) == circle_TRUE)
		{
			flag = i;
			break;
		}
		pCurrent = pCurrent->next;
	}
	return flag;
}
//打印
void print_circlelinklist(circle_linklist* clist,PRINTNODE print)
{
	if (clist == NULL)
	{
		return ;
	}
	
	circle_listnode* pCurrent = clist->head.next;//从有数据的开始
	int flag = -1;
	for (int i = 0; i < clist->size*2; i++)
	{
		if (pCurrent == &(clist->head))
		{
			pCurrent = pCurrent->next;
		}
		print(pCurrent);
		pCurrent = pCurrent->next;
	}
	
}
//释放
void free_circlelinklist(circle_linklist* clist)
{
	if (clist == NULL)
	{
		return;
	}
	free(clist);
}
