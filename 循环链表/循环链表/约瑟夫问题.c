#include"circle_list.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define M 8
#define N 3
typedef struct num {
	circle_listnode node;
	int value;
}num;

//打印回调函数
void myprint(circle_listnode*data)
{
	num* p = (num*)data;//数据强转
	printf("%d\t", p->value);
}

int mycompare(circle_listnode*data1, circle_listnode*data2)
{
	num*p1 = (num*)data1;
	num*p2 = (num*)data2;

	if (p1->value == p2->value)
	{
		return circle_TRUE;
	}
	return circle_FALSE;
}

int main()
{
	//创建循环链表
	circle_linklist* list= init_circlelinklist();
	//插入数据
	num n[M];
	for (int i = 0; i < M; i++)
	{
		n[i].value = i + 1;
		insert_circlelinklist(list,i,(circle_listnode*)&n[i]);
	}
	print_circlelinklist(list,myprint);


	//约瑟夫问题  8人围坐 循环报数：123-123-123... 是3的人退出
	int index = 1;
	circle_listnode* pcurrent = list->head.next;
	while (size_circlelinklist(list) > 1)
	{
		if (index == N)
		{
			num* tmp = (num*)pcurrent;//此时找到对于指针指向的节点  数据转换后输出
			printf("%d",tmp->value);

			// 退出队列  即删除  缓存待删除节点的下一节点
			circle_listnode* pnext = pcurrent->next;
			//根据值删除
			removebyvalue_circlelinklist(list, pcurrent, mycompare);
			pcurrent = pnext;

			//循环链表判断是否指向头结点(多次循环 跳过头结点)
			if (pcurrent = &(list->head))
			{
				pcurrent = pcurrent->next;
			}
			index = 1;
		}
		pcurrent = pcurrent->next;
		if (pcurrent = &(list->head))
		{
			pcurrent = pcurrent->next;
		}
		index++;
	}

	free_circlelinklist(list);
	return 0;
}