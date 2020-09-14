#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
银行家算法是为了避免死锁而产生的算法。避免死锁是属于事先预防的策略，但并不是事先采取某种限制的措施。它是在资源动态分配过程中，防止系统进入不安全状态，以避免发生死锁。
（1）inster_tail()函数，它的作用是：将包含有输入信息的结点连接到链表的尾部，形成输入信息的链表，之后可通过遍历链表来改变结点中的信息以及输出结点信息，从而输出是否有安全序列，以及安全序列。
（2）start()函数：主要是输入结点信息。以及每输入一个符合要求的信息后，通过insert_tail()函数，将其连接到链表中，直至链表连接完成。
（3）bank()函数：主要是进行安全性检查，其中包括有roc *buff[M] = {0}指针数组，它是用于记录找到符合进程的信息，由指针数组存储，最终在安全序列存在的情况下，通过指针数组中存储的顺序将其进行打印。
（4）req()函数：主要是对于某个进程进行资源的请求，对其限制条件进行判断，计算输入的请求资源数是否满足限制条件，并计算通过资源请求数之后的剩余资源数、该进程得所需资源数、以及分配的资源数。

*/
#define M 20

int i = 0;//进程数
int m = 0; //资源数
int all[M] = { 0 };
int request[M] = { 0 };

typedef struct _Proc//进程信息
{
	char name[5];
	int max[M];//最大需求资源
	int allocation[M];//分配资源
	int need[M];//需求资源
	int avaliable[M];//可用资源
	bool flag;
	struct _Proc *next;
}Proc;

void init(Proc *phead)//初始化链表
{
	phead->next = NULL;
}

void insert_tail(Proc *p, Proc **q)//尾插进链表
{
	if (p == NULL)
	{
		return;
	}
	Proc *s = p;
	while (s->next != NULL)
	{
		s = s->next;
	}
	s->next = *q;
}

void show(Proc *p)
{
	Proc *q = p->next;
	printf("进程名    最大需求    分配资源     需求资源     可用资源\n");
	while (q != NULL)
	{
		printf("%s", q->name);
		printf("         ");
		for (int i = 0; i < m; i++)
		{
			printf("%d  ", q->max[i]);
		}
		printf("       ");
		for (int i = 0; i < m; i++)
		{
			printf("%d  ", q->allocation[i]);
		}
		printf("       ");
		for (int i = 0; i < m; i++)
		{
			printf("%d  ", q->need[i]);
		}
		printf("        ");
		for (int i = 0; i < m; i++)
		{
			printf("%d  ", q->avaliable[i]);
		}
		printf("\n");
		q = q->next;
	}
	printf("剩余资源：\n");
	for (int i = 0; i < m; i++)
	{
		printf("%d  ", all[i]);
	}
	printf("\n");
}

void start(Proc *p)//输入信息
{
	int j = 0;
	printf("请输入所要执行的进程数：\n");
	scanf("%d", &i);
	printf("请输入所要执行的资源数：\n");
	scanf("%d", &m);
	printf("输入资源总数：\n");
	for (int k = 0; k < m; k++)
	{
		scanf("%d", &all[k]);
	}
	for (; j < i; j++)
	{
		Proc *node = (Proc *)malloc(sizeof(Proc));
		memset(node->name, 0, 10);
		node->next = NULL;
		printf("输入进程名：\n");
		scanf("%s", node->name);
		fflush(stdin);
		printf("输入最大需求资源：\n");
		for (int k = 0; k < m; k++)//输入最大需求资源
		{
			scanf("%d", &node->max[k]);
			if (node->max[k] < 0)
			{
				printf("输入有误，请重新输入\n");
				exit(0);
			}
		}
		printf("输入分配资源：\n");
		for (int k = 0; k < m; k++)//输入分配资源
		{
			scanf("%d", &node->allocation[k]);
			if (node->allocation[k] < 0 && node->allocation[k] > all[k] && node->allocation[k] > node->max[k])
			{
				printf("输入有误，请重新输入\n");
				exit(0);
			}
		}
		for (int k = 0; k < m; k++)//求出需求资源
		{
			node->need[k] = node->max[k] - node->allocation[k];
			node->avaliable[k] = all[k] - node->allocation[k];
			all[k] = all[k] - node->allocation[k];
		}
		node->flag = false;
		insert_tail(p, &node);
	}
	show(p);
}

void bank(Proc *p)
{
	int work[M];
	for (int j = 0; j < m; j++)
	{
		work[j] = all[j] - request[j];
	}
	Proc *buff[M] = { 0 };
	Proc *s = p->next;
	bool f = false;
	int count = 0;
	while (count < i)
	{
		while (s != NULL)//从头往后找合适的进程
		{
			if (s->flag)
			{
				s = s->next;
				continue;
			}
			f = true;
			for (int i = 0; i < m; i++)
			{
				if (work[i] < s->need[i])
				{
					f = false;
					break;
				}
			}
			if (f)
			{
				break;
			}
			s = s->next;
		}
		if (f)
		{
			for (int i = 0; i < m; i++)
			{
				s->avaliable[i] = work[i] + s->allocation[i];
				work[i] = s->avaliable[i];
			}
			s->flag = true;
			buff[count] = s;
			s = p->next;
		}
		count++;
	}
	s = p->next;
	for (int j = 0; j < i; j++)//判断是否全部为true
	{
		if (!s->flag)
		{
			printf("此算法没有安全序列\n\n\n");
			s = p->next;
			while (s != NULL)
			{
				if (s->flag)
				{
					for (int k = 0; k < m; k++)
					{
						s->avaliable[k] = s->avaliable[k] + s->allocation[k];
					}
				}
				s = s->next;
			}
			show(p);
			exit(0);
		}
		s = s->next;
	}
	printf("\n\n\n该算法有安全序列，序列如下\n\n\n");
	printf("进程名    剩余资源     需求资源     分配资源      结果\n");
	for (int j = 0; buff[j] != 0; j++)
	{
		printf("%s", buff[j]->name);
		printf("        ");
		for (int i = 0; i < m; i++)
		{
			printf("%d  ", buff[j]->avaliable[i]);
		}
		printf("        ");
		for (int i = 0; i < m; i++)
		{
			printf("%d  ", buff[j]->need[i]);
		}
		printf("        ");
		for (int i = 0; i < m; i++)
		{
			printf("%d  ", buff[j]->allocation[i]);
		}
		printf("        ");
		printf("%d", buff[j]->flag);
		printf("\n");
	}
	printf("安全序列为：");
	int j = 0;
	while (buff[j] != 0)
	{
		printf("%s  ", buff[j]->name);
		j++;
	}
	printf("\n");
}

void req(Proc *p)
{
	char buff[10] = { 0 };
	while (1)
	{
		printf("请输入请求资源的进程名字：\n");
		scanf("%s", buff);
		fflush(stdin);
		printf("请输入请求资源数：\n");
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &request[j]);
		}
		Proc *s = p->next;
		while (s != NULL)
		{
			if (strcmp(buff, s->name) == 0)
			{
				for (int j = 0; j < m; j++)
				{
					if (request[j] > s->need[j])
					{
						printf("所需资源已经超出所宣布的最大值\n");
						return;
					}
				}
				for (int j = 0; j < m; j++)
				{
					if (request[j] > all[j])
					{
						printf("没有足够资源\n");
						return;
					}
				}
				for (int j = 0; j < m; j++)
				{
					s->avaliable[j] = s->avaliable[j] - request[j];
					s->allocation[j] = s->allocation[j] + request[j];
					s->need[j] = s->need[j] - request[j];
				}
				break;
			}

			s = s->next;
		}
		if (s == NULL)
		{
			printf("进程名输入错误\n");
		}
		else
		{
			break;
		}
	}
}
void change(Proc *p)
{
	Proc *s = p->next;
	while (s != NULL)
	{
		s->flag = false;
		s = s->next;
	}
}

void main_page()
{
	Proc p;
	init(&p);
	printf("\n\n\n**********************************************\n");
	printf("                                                           \n");
	printf("                银行家算法                    \n");
	printf("                                                           \n");
	printf("**********************************************\n\n\n\n\n\n\n\n");
	char ch;
	printf("   a.进行此算法\n\n");
	printf("   b.退出\n\n\n");
	while (1)
	{
		scanf("%c", &ch);
		fflush(stdin);
		switch (ch)
		{
		case 'a':
			start(&p);
			while (1)
			{
				printf("是否对某资源进行请求？是：请输入Y，不是输入N,输入q退出程序\n");
				fflush(stdin);
				scanf("%c", &ch);
				fflush(stdin);
				switch (ch)
				{
				case 'Y':
					req(&p);
					change(&p);
					bank(&p);
					break;
					//exit(0);
				case 'N':
					change(&p);
					bank(&p);
					break;
				case 'q':
					exit(0);
				default:
					printf("输入错误，请重新输入\n");
					break;
				}
			}
			break;
		case 'b':
			exit(0);
		default:
			printf("输入错误，请重新输入\n");
		}
	}
}
int main()
{
	main_page();
	return 0;
}
