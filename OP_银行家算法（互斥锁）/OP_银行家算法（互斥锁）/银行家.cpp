#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
���м��㷨��Ϊ�˱����������������㷨��������������������Ԥ���Ĳ��ԣ������������Ȳ�ȡĳ�����ƵĴ�ʩ����������Դ��̬��������У���ֹϵͳ���벻��ȫ״̬���Ա��ⷢ��������
��1��inster_tail()���������������ǣ���������������Ϣ�Ľ�����ӵ������β�����γ�������Ϣ������֮���ͨ�������������ı����е���Ϣ�Լ���������Ϣ���Ӷ�����Ƿ��а�ȫ���У��Լ���ȫ���С�
��2��start()��������Ҫ����������Ϣ���Լ�ÿ����һ������Ҫ�����Ϣ��ͨ��insert_tail()�������������ӵ������У�ֱ������������ɡ�
��3��bank()��������Ҫ�ǽ��а�ȫ�Լ�飬���а�����roc *buff[M] = {0}ָ�����飬�������ڼ�¼�ҵ����Ͻ��̵���Ϣ����ָ������洢�������ڰ�ȫ���д��ڵ�����£�ͨ��ָ�������д洢��˳������д�ӡ��
��4��req()��������Ҫ�Ƕ���ĳ�����̽�����Դ�����󣬶����������������жϣ����������������Դ���Ƿ���������������������ͨ����Դ������֮���ʣ����Դ�����ý��̵�������Դ�����Լ��������Դ����

*/
#define M 20

int i = 0;//������
int m = 0; //��Դ��
int all[M] = { 0 };
int request[M] = { 0 };

typedef struct _Proc//������Ϣ
{
	char name[5];
	int max[M];//���������Դ
	int allocation[M];//������Դ
	int need[M];//������Դ
	int avaliable[M];//������Դ
	bool flag;
	struct _Proc *next;
}Proc;

void init(Proc *phead)//��ʼ������
{
	phead->next = NULL;
}

void insert_tail(Proc *p, Proc **q)//β�������
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
	printf("������    �������    ������Դ     ������Դ     ������Դ\n");
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
	printf("ʣ����Դ��\n");
	for (int i = 0; i < m; i++)
	{
		printf("%d  ", all[i]);
	}
	printf("\n");
}

void start(Proc *p)//������Ϣ
{
	int j = 0;
	printf("��������Ҫִ�еĽ�������\n");
	scanf("%d", &i);
	printf("��������Ҫִ�е���Դ����\n");
	scanf("%d", &m);
	printf("������Դ������\n");
	for (int k = 0; k < m; k++)
	{
		scanf("%d", &all[k]);
	}
	for (; j < i; j++)
	{
		Proc *node = (Proc *)malloc(sizeof(Proc));
		memset(node->name, 0, 10);
		node->next = NULL;
		printf("�����������\n");
		scanf("%s", node->name);
		fflush(stdin);
		printf("�������������Դ��\n");
		for (int k = 0; k < m; k++)//�������������Դ
		{
			scanf("%d", &node->max[k]);
			if (node->max[k] < 0)
			{
				printf("������������������\n");
				exit(0);
			}
		}
		printf("���������Դ��\n");
		for (int k = 0; k < m; k++)//���������Դ
		{
			scanf("%d", &node->allocation[k]);
			if (node->allocation[k] < 0 && node->allocation[k] > all[k] && node->allocation[k] > node->max[k])
			{
				printf("������������������\n");
				exit(0);
			}
		}
		for (int k = 0; k < m; k++)//���������Դ
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
		while (s != NULL)//��ͷ�����Һ��ʵĽ���
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
	for (int j = 0; j < i; j++)//�ж��Ƿ�ȫ��Ϊtrue
	{
		if (!s->flag)
		{
			printf("���㷨û�а�ȫ����\n\n\n");
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
	printf("\n\n\n���㷨�а�ȫ���У���������\n\n\n");
	printf("������    ʣ����Դ     ������Դ     ������Դ      ���\n");
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
	printf("��ȫ����Ϊ��");
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
		printf("������������Դ�Ľ������֣�\n");
		scanf("%s", buff);
		fflush(stdin);
		printf("������������Դ����\n");
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
						printf("������Դ�Ѿ����������������ֵ\n");
						return;
					}
				}
				for (int j = 0; j < m; j++)
				{
					if (request[j] > all[j])
					{
						printf("û���㹻��Դ\n");
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
			printf("�������������\n");
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
	printf("                ���м��㷨                    \n");
	printf("                                                           \n");
	printf("**********************************************\n\n\n\n\n\n\n\n");
	char ch;
	printf("   a.���д��㷨\n\n");
	printf("   b.�˳�\n\n\n");
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
				printf("�Ƿ��ĳ��Դ���������ǣ�������Y����������N,����q�˳�����\n");
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
					printf("�����������������\n");
					break;
				}
			}
			break;
		case 'b':
			exit(0);
		default:
			printf("�����������������\n");
		}
	}
}
int main()
{
	main_page();
	return 0;
}
