#include<stdio.h>
#include<stdlib.h>

#define OK 0
#define ERROR -1


//创建节点数据结构 通过结构指针描述单链表
typedef struct Node {
	ElemType data;//数据域
	struct Node* next;//指针域
}Node;
typedef struct Node* linklist;//创建单链表
//*****************************************************************************
//Tencent面试题
//快速扎到未知长度单链表的之间节点

//普通方法：先遍历一遍单链表以确定单链表长度L，再次从头节点出发循环L/2次找到单链表的中间节点
//算法复杂度：O(L+L/2)=O(3L/2)

//高级方法：利用快慢指针
//设置两个指针*search，*mid都是指向单链表的头节点 其中*search的移动速度是*mid的2倍  当*search指向末尾节点的时候，mid正好在中间.

status GetMidNode(linklist L, ElemType *e)
{
	linklist search, mid;
	mid = search = L;//*search，*mid都是指向单链表的头节点
	while (search->next != NULL)
	{
		if (search->next->next != NULL)//*search的移动速度是*mid的2倍
		{
			search = search->next->next;
			mid = mid->next;
		}
		else
		{
			search = search->next;
		}

	}
	*e = mid->data;
	return OK;
}