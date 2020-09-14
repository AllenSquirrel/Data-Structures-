#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
/*
#define OK 1
#define ERROR 0

typedef int Status;


//*****************************************************************************
// (1)单链表执行查找操作  根据链式结构  根据前驱节点和后继指针依次查找  时间复杂度O（n）
//（2）单链表执行插入/删除操作  可直接插入，不受空间限制   时间为O（1）

//空间存储：不需要预先分配存储空间 元素个数不受限制

//*****************************************************************************


//创建节点数据结构 通过结构指针描述单链表
typedef struct Node {
	void* data;//数据域
	struct Node* next;//指针域
}Node;
typedef struct Node* linklist;//创建单链表开始头结点
//*****************************************************************************

//单链表查找第i元素操作
//将查找到的元素赋值给e存储
Status GetElem(linklist L, int i, void*e)
{
	int j=1;
	linklist p;//此时p为一个移动指针
	p = L->next;
	while (p&&j < i)
	{
		p = p->next;//只要p指向不为NULL，继续向后移动
		++j;
	}
	if (!p || j > i)
	{
		return ERROR;
	}
	e = p->data;  //此时p指针找到第i元素
}
//*****************************************************************************
//单链表插入到第i位置操作
//将插入到的元素通过e来赋值作为data值
Status list_insert(linklist *L, int i, void *e)
{
	int j=1;
	linklist p, s;
	p = *L;
	while (p&&j < i)
	{
		p = p->next;//只要p指向不为NULL，继续向后移动
		++j;
	}
	if (!p || j > i)
	{
		return ERROR;
	}
	s = (linklist)malloc(sizeof(Node));
	s->data = e;

	s->next = p->next;
	p->next = s;   //关键点  p作为移动指针 当找到第i位置 p->next表示 指向需要插入第i位置后的第一个元素 需要将其链接在s上，由s->next指向
	               //        再将s节点给与p->next  表示将插入新元素链接在插入第i位置前一个元素上
	return OK;
}

//*****************************************************************************
//单链表删除第i位置元素操作
//将删除元素通过e来储存返回
Status list_delete(linklist *L, int i, void *e)
{
	int j = 1;
	linklist p, q;
	p = *L;
	while (p&&j < i)
	{
		p = p->next;//只要p指向不为NULL，继续向后移动
		++j;
	}
	if (!p || j > i)
	{
		return ERROR;
	}
	q = p->next;//此时通过q将删除的第i位置后的元素先 由q进行连接  以免后续删除丢失
	p->next = q->next;
	
	//需要注意一点 ：free(q)的时间（什么时候free ，考虑能否先直接删除再链接？）
	//同时必须借助中间量 q完成删除  否则链表删除将会丢失后续元素
	e = q->next;
	free(q);
	return OK;
}

//*****************************************************************************
//单链表头插法操作

void createlistHead(linklist *L, int n)
{
	linklist p;
	int i;
	srand(time(0));//初始化随机数种子

	*L= (linklist)malloc(sizeof(Node));
	(*L)->next = NULL;   //创建仅有一个头的空链表

	for (i = 0; i < n; i++)
	{
		p = (linklist)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;   
		//注意 等号右边  (*L)->next表示指向它的下一个节点
		//     等号左边  (*L)->next表示指向它本身的指针域
	}
}

//*****************************************************************************
//单链表清空操作

Status clearlist(linklist *L)
{
	linklist p, q;
	p = (*L)->next;
	while (p)
	{
		q = p->next;
		free(q);
		//注意  以上两行代码位置不可互换  以免后续节点丢失，保持链接完整性
		p = q;

	}
	(*L)->next = NULL; //此时移动指针 遍历全表 全部数据清空 将链表赋值NULL
	return OK;
}
int main()
{
	return 0;
}
*/

//*****************************************************************************
//*****************************************************************************


//创建节点数据结构 通过结构指针描述单链表
typedef struct Node {
	void* data;//数据域
	struct Node* next;//指针域
}linknode;
//创建单链表
typedef struct LINKLIST {
	linknode* head;
	int size;
}linklist;

typedef void(*PRINTLINKNODE)(void*);
//初始化链表
linklist* init_list()
{
	linklist* list = (linklist*)malloc(sizeof(linklist));//创建链表
	list->size = 0;//初始化长度为0
	list->head = (linknode*)malloc(sizeof(linknode));//创建头结点
	list->head->data = NULL;//初始化头结点 不存储数据
	list->head->next = NULL;//仅一个头结点
}

//指定位置插入
void insert_linklist(linklist*list,int pos,void* data)
{
	if (list == NULL)
	{
		return;
	}
	if (data = NULL)
	{
		return;
	}
	if (pos<0 || pos>list->size)
	{
		pos = list->size;
	}
	//创建新节点 挂载链表
	linknode* newnode = (linknode*)malloc(sizeof(linknode));
	newnode->data = data;
	newnode->next = NULL;

	//移动指针  查找pos
	linknode* PCurrent = list->head;
	for (int i = 0; i < pos; i++)
	{
		PCurrent = PCurrent->next;
	}
	//挂载新节点
	newnode->next = PCurrent->next;
	PCurrent->next = newnode;
	list->size++;
}

void removbypos_linklist(linklist*list, int pos)
{
	if (list == NULL)
	{
		return;
	}
	if (pos<0 || pos>list->size)
	{
		return;
	}
	//查找删除节点的前一节点
	linknode* PCurrent = list->head;
	for (int i = 0; i < pos; i++)
	{
		PCurrent = PCurrent->next;
	}
	//删除节点 
	//PCurrent->next = PCurrent->next->next;
	linknode * pdel = PCurrent->next;
	PCurrent->next = pdel->next;
	//释放
	free(pdel);
	list->size--;
}
//获得链表的长度
int size_linklist(linklist* list)
{
	return list->size;
}
//查找 返回位置序号
int find_linklist(linklist* list,void *data)
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	//遍历查找
	int i;
	linknode* PCurrent = list->head->next;
	while(PCurrent!=NULL)
	{
		if (PCurrent->data==data)
		{
			break;
		}
		i++;
		PCurrent = PCurrent->next;
	}
	return i;
}
//返回头结点的下一节点
void* front_linklist(linklist* list)
{
	if (list == NULL)
	{
		return;
	}
	return list->head->next;

}
//打印列表
void print_linklist(linklist* list, PRINTLINKNODE print)
{
	if (list == NULL)
	{
		return;
	}
	linknode* PCurrent = list->head->next;
	while (PCurrent != NULL)
	{
		print(PCurrent->data);
		PCurrent = PCurrent->next;
	}
}
//释放链表
void freespace_linklist(linklist* list)
{
	if (list == NULL)
	{
		return;
	}
	linknode* PCurrent = list->head;
	while (PCurrent != NULL)
	{
		 // 循环释放链表中节点
		linknode* pnext = PCurrent->next;
		free(PCurrent);
		PCurrent = pnext;
	}

	//释放链表内存
	list->size = 0;
	free(list);
}
//*****************************************************************************






//****************************************************************************
//企业级链表   
//每一节点存储数据类型为LINKNODE*
//节点 挂扣式 直接连接
//
typedef struct LINKNODE
{
	struct LINKNODE* next;
}LinkNode;

typedef struct LINKLIST
{
	LinkNode head;//此处需要注意 定义head为实体 并非指针
	int size;
}LinkList;
//遍历函数指针
typedef void(*PRINTNODE)(LinkNode*);
//比较函数指针
typedef int(*COMPARENODE)(LinkNode*, LinkNode*);
//初始化链表
LinkList* init_linklist()
{
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));//创建链表
	list->size = 0;//初始化长度为0
	list->head.next = NULL;
	return list;
}
//插入
void insert_linklist(LinkList*list,int pos,LinkNode*data)
{
	if (list == NULL)
	{
		return;
	}
	if (data = NULL)
	{
		return;
	}
	if (pos<0 || pos>list->size)
	{
		pos = list->size;
	}

	//移动指针  查找pos
	LinkNode* PCurrent = &(list->head);
	for (int i = 0; i < pos; i++)
	{
		PCurrent = PCurrent->next;
	}
	//挂载新节点
	data->next = PCurrent->next;
	PCurrent->next = data;
	list->size++;
}
//指定位置删除
void removebypos_linklist(LinkList*list, int pos)
{
	if (list == NULL)
	{
		return;
	}
	if (pos<0 || pos>list->size)
	{
		return;
	}
	//查找删除节点的前一节点
	LinkNode* PCurrent = &(list->head);
	for (int i = 0; i < pos; i++)
	{
		PCurrent = PCurrent->next;
	}
	//删除节点 
	PCurrent->next = PCurrent->next->next;
	
	list->size--;
}
//查找
int find_list(LinkList*list, LinkNode*data, COMPARENODE compare)
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	//遍历查找
	int i;
	LinkNode* PCurrent = list->head.next;
	while (PCurrent != NULL)
	{
		if (compare(PCurrent,data)==0)
		{
			break;
		}
		i++;
		PCurrent = PCurrent->next;
	}
	return i;
}
//返回链表大小
int size_linklist(LinkList*list)
{
	return list->size;
}
//打印链表
void print_linklist(LinkList*list, PRINTNODE print) //PRINTNODE打印回调函数
{
	if (list == NULL)
	{
		return;
	}
	LinkNode* PCurrent = list->head.next;
	while (PCurrent != NULL)
	{
		print(PCurrent);
		PCurrent = PCurrent->next;
	}
}
//释放链表内存
void free_linklist(LinkList*list)
{
	if (list == NULL)
	{
		return;
	}
	free(list);
}
//***********************************************
//**测试**
//定义数据类型 链表单个结构
typedef struct person {
	LinkNode node;
	char name[64];
	int age;
}Person;
//定义打印回调函数(遍历指针)
void myprint(LinkNode* data)
{
	Person* p = (Person*)data;
	printf("Name:%s,Age:%d",p->name,p->age);
}
//定义打印回调函数(遍历指针)
int mycompare(LinkNode* node1, LinkNode* node2)
{
	Person* p1 = (Person*)node1;
	Person* p2 = (Person*)node2;
	if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age)
	{
		return 0;
	}
	return -1;
}