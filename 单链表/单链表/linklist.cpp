#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
/*
#define OK 1
#define ERROR 0

typedef int Status;


//*****************************************************************************
// (1)������ִ�в��Ҳ���  ������ʽ�ṹ  ����ǰ���ڵ�ͺ��ָ�����β���  ʱ�临�Ӷ�O��n��
//��2��������ִ�в���/ɾ������  ��ֱ�Ӳ��룬���ܿռ�����   ʱ��ΪO��1��

//�ռ�洢������ҪԤ�ȷ���洢�ռ� Ԫ�ظ�����������

//*****************************************************************************


//�����ڵ����ݽṹ ͨ���ṹָ������������
typedef struct Node {
	void* data;//������
	struct Node* next;//ָ����
}Node;
typedef struct Node* linklist;//����������ʼͷ���
//*****************************************************************************

//��������ҵ�iԪ�ز���
//�����ҵ���Ԫ�ظ�ֵ��e�洢
Status GetElem(linklist L, int i, void*e)
{
	int j=1;
	linklist p;//��ʱpΪһ���ƶ�ָ��
	p = L->next;
	while (p&&j < i)
	{
		p = p->next;//ֻҪpָ��ΪNULL����������ƶ�
		++j;
	}
	if (!p || j > i)
	{
		return ERROR;
	}
	e = p->data;  //��ʱpָ���ҵ���iԪ��
}
//*****************************************************************************
//��������뵽��iλ�ò���
//�����뵽��Ԫ��ͨ��e����ֵ��Ϊdataֵ
Status list_insert(linklist *L, int i, void *e)
{
	int j=1;
	linklist p, s;
	p = *L;
	while (p&&j < i)
	{
		p = p->next;//ֻҪpָ��ΪNULL����������ƶ�
		++j;
	}
	if (!p || j > i)
	{
		return ERROR;
	}
	s = (linklist)malloc(sizeof(Node));
	s->data = e;

	s->next = p->next;
	p->next = s;   //�ؼ���  p��Ϊ�ƶ�ָ�� ���ҵ���iλ�� p->next��ʾ ָ����Ҫ�����iλ�ú�ĵ�һ��Ԫ�� ��Ҫ����������s�ϣ���s->nextָ��
	               //        �ٽ�s�ڵ����p->next  ��ʾ��������Ԫ�������ڲ����iλ��ǰһ��Ԫ����
	return OK;
}

//*****************************************************************************
//������ɾ����iλ��Ԫ�ز���
//��ɾ��Ԫ��ͨ��e�����淵��
Status list_delete(linklist *L, int i, void *e)
{
	int j = 1;
	linklist p, q;
	p = *L;
	while (p&&j < i)
	{
		p = p->next;//ֻҪpָ��ΪNULL����������ƶ�
		++j;
	}
	if (!p || j > i)
	{
		return ERROR;
	}
	q = p->next;//��ʱͨ��q��ɾ���ĵ�iλ�ú��Ԫ���� ��q��������  �������ɾ����ʧ
	p->next = q->next;
	
	//��Ҫע��һ�� ��free(q)��ʱ�䣨ʲôʱ��free �������ܷ���ֱ��ɾ�������ӣ���
	//ͬʱ��������м��� q���ɾ��  ��������ɾ�����ᶪʧ����Ԫ��
	e = q->next;
	free(q);
	return OK;
}

//*****************************************************************************
//������ͷ�巨����

void createlistHead(linklist *L, int n)
{
	linklist p;
	int i;
	srand(time(0));//��ʼ�����������

	*L= (linklist)malloc(sizeof(Node));
	(*L)->next = NULL;   //��������һ��ͷ�Ŀ�����

	for (i = 0; i < n; i++)
	{
		p = (linklist)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;   
		//ע�� �Ⱥ��ұ�  (*L)->next��ʾָ��������һ���ڵ�
		//     �Ⱥ����  (*L)->next��ʾָ���������ָ����
	}
}

//*****************************************************************************
//��������ղ���

Status clearlist(linklist *L)
{
	linklist p, q;
	p = (*L)->next;
	while (p)
	{
		q = p->next;
		free(q);
		//ע��  �������д���λ�ò��ɻ���  ��������ڵ㶪ʧ����������������
		p = q;

	}
	(*L)->next = NULL; //��ʱ�ƶ�ָ�� ����ȫ�� ȫ��������� ������ֵNULL
	return OK;
}
int main()
{
	return 0;
}
*/

//*****************************************************************************
//*****************************************************************************


//�����ڵ����ݽṹ ͨ���ṹָ������������
typedef struct Node {
	void* data;//������
	struct Node* next;//ָ����
}linknode;
//����������
typedef struct LINKLIST {
	linknode* head;
	int size;
}linklist;

typedef void(*PRINTLINKNODE)(void*);
//��ʼ������
linklist* init_list()
{
	linklist* list = (linklist*)malloc(sizeof(linklist));//��������
	list->size = 0;//��ʼ������Ϊ0
	list->head = (linknode*)malloc(sizeof(linknode));//����ͷ���
	list->head->data = NULL;//��ʼ��ͷ��� ���洢����
	list->head->next = NULL;//��һ��ͷ���
}

//ָ��λ�ò���
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
	//�����½ڵ� ��������
	linknode* newnode = (linknode*)malloc(sizeof(linknode));
	newnode->data = data;
	newnode->next = NULL;

	//�ƶ�ָ��  ����pos
	linknode* PCurrent = list->head;
	for (int i = 0; i < pos; i++)
	{
		PCurrent = PCurrent->next;
	}
	//�����½ڵ�
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
	//����ɾ���ڵ��ǰһ�ڵ�
	linknode* PCurrent = list->head;
	for (int i = 0; i < pos; i++)
	{
		PCurrent = PCurrent->next;
	}
	//ɾ���ڵ� 
	//PCurrent->next = PCurrent->next->next;
	linknode * pdel = PCurrent->next;
	PCurrent->next = pdel->next;
	//�ͷ�
	free(pdel);
	list->size--;
}
//�������ĳ���
int size_linklist(linklist* list)
{
	return list->size;
}
//���� ����λ�����
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
	//��������
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
//����ͷ������һ�ڵ�
void* front_linklist(linklist* list)
{
	if (list == NULL)
	{
		return;
	}
	return list->head->next;

}
//��ӡ�б�
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
//�ͷ�����
void freespace_linklist(linklist* list)
{
	if (list == NULL)
	{
		return;
	}
	linknode* PCurrent = list->head;
	while (PCurrent != NULL)
	{
		 // ѭ���ͷ������нڵ�
		linknode* pnext = PCurrent->next;
		free(PCurrent);
		PCurrent = pnext;
	}

	//�ͷ������ڴ�
	list->size = 0;
	free(list);
}
//*****************************************************************************






//****************************************************************************
//��ҵ������   
//ÿһ�ڵ�洢��������ΪLINKNODE*
//�ڵ� �ҿ�ʽ ֱ������
//
typedef struct LINKNODE
{
	struct LINKNODE* next;
}LinkNode;

typedef struct LINKLIST
{
	LinkNode head;//�˴���Ҫע�� ����headΪʵ�� ����ָ��
	int size;
}LinkList;
//��������ָ��
typedef void(*PRINTNODE)(LinkNode*);
//�ȽϺ���ָ��
typedef int(*COMPARENODE)(LinkNode*, LinkNode*);
//��ʼ������
LinkList* init_linklist()
{
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));//��������
	list->size = 0;//��ʼ������Ϊ0
	list->head.next = NULL;
	return list;
}
//����
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

	//�ƶ�ָ��  ����pos
	LinkNode* PCurrent = &(list->head);
	for (int i = 0; i < pos; i++)
	{
		PCurrent = PCurrent->next;
	}
	//�����½ڵ�
	data->next = PCurrent->next;
	PCurrent->next = data;
	list->size++;
}
//ָ��λ��ɾ��
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
	//����ɾ���ڵ��ǰһ�ڵ�
	LinkNode* PCurrent = &(list->head);
	for (int i = 0; i < pos; i++)
	{
		PCurrent = PCurrent->next;
	}
	//ɾ���ڵ� 
	PCurrent->next = PCurrent->next->next;
	
	list->size--;
}
//����
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
	//��������
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
//���������С
int size_linklist(LinkList*list)
{
	return list->size;
}
//��ӡ����
void print_linklist(LinkList*list, PRINTNODE print) //PRINTNODE��ӡ�ص�����
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
//�ͷ������ڴ�
void free_linklist(LinkList*list)
{
	if (list == NULL)
	{
		return;
	}
	free(list);
}
//***********************************************
//**����**
//������������ �������ṹ
typedef struct person {
	LinkNode node;
	char name[64];
	int age;
}Person;
//�����ӡ�ص�����(����ָ��)
void myprint(LinkNode* data)
{
	Person* p = (Person*)data;
	printf("Name:%s,Age:%d",p->name,p->age);
}
//�����ӡ�ص�����(����ָ��)
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