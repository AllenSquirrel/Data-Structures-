#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
（1）先来先服务算法（FCFS）
当进程调度中使用先来先服务算法时，每次调度是从就绪的进程队列中选择一个最先进入该队列的进程，即按照作业到达先后的次序来进行调度，为之分配处理机，使之投入运行。该进程一直运行到完成或发生某事件二堵塞后，进程调度程序才将处理机分配给其他进程。
（2）短作业优先算法（SJF）
	 短作业优先算法是以作业的长短来计算优先级，作业越短，其优先级越高。作业的长短是由作业所要求的运行时间来衡量的。当用于进程调度时，从就绪队列中选择一个作业时间最短的进程，为之分配处理机，使之投入运行。
（3）优先级调度算法（PSA）
	 优先级调度算法中，是基于作业的紧迫程度，由外部赋予作业相应的优先级，调度算法是根据该优先级进行调度的。其用于进程调度时，从就绪队列中选择一个优先级高的进程，为之分配处理机，使之运行。

*/


#define N 5
typedef struct _DATA
{
	char name[20];
	float give_time;//提交时间
	float run_time;//运行时间
	float start_time;//开始时间
	float end_time;//完成时间
	float use_time;//周转时间
	float ave_use_time;//带权周转时间
}DATA;

typedef struct __DATA
{
	char name[20];
	float give_time;//提交时间
	float run_time;//运行时间
	int first;//优先级
	float start_time;//开始时间
	float end_time;//完成时间
	float use_time;//周转时间
	float ave_use_time;//带权周转时间
}DATA2;

void show(DATA *su, float sum)
{
	float ave = sum / N;
	printf("进程号 提交时间 运行时间 开始时间 完成时间 周转时间 带权周转时间\n");
	for (int k = 0; k < N; k++)
	{
		printf("%s  %f  %f  %f  %f  %f  %f\n", su[k].name, su[k].give_time, su[k].run_time, su[k].start_time, su[k].end_time, su[k].use_time, su[k].ave_use_time);
	}
	printf("平均带权周转:%f\n", ave);
}
void FCFS()
{
	DATA su[N];
	int i = 0;
	float sum = 0;
	while (i < N)//输入进程信息
	{
		char buff[20];
		printf(buff, "进程%d", i + 1);
		strcpy(su[i].name, buff);
		fflush(stdin);
		printf("请输入%d提交时间：", i + 1);
		scanf("%f", &su[i].give_time);
		fflush(stdin);
		printf("请输入%d运行时间：", i + 1);
		scanf("%f", &su[i].run_time);
		fflush(stdin);
		i++;
	}
	for (int y = 0; y < N; y++)//对进程提交时间进行排序
	{
		for (int k = 0; k < N - y - 1; k++)
		{
			if (su[k].give_time > su[k + 1].give_time)
			{
				DATA tmp = su[k];
				su[k] = su[k + 1];
				su[k + 1] = tmp;
			}
		}
	}

	for (int j = 0; j < N; j++)//计算开始时间，完成时间，周转时间
	{
		if (j == 0)
		{
			su[j].start_time = su[j].give_time;
			su[j].end_time = su[j].run_time;
		}
		else
		{
			su[j].start_time = su[j - 1].end_time;
			su[j].end_time = su[j].start_time + su[j].run_time;
		}
		su[j].use_time = su[j].end_time - su[j].give_time;
		su[j].ave_use_time = su[j].use_time / su[j].run_time;
		sum = sum + su[j].ave_use_time;
	}

	show(su, sum);
}
void SJF()
{
	DATA su[N];
	int i = 0;
	float sum = 0;
	int count = 0;
	int s = 0;
	int m = 0;
	int index = 0;
	while (i < N)//输入进程信息
	{
		char buff[20];
		sprintf(buff, "进程%d", i + 1);
		strcpy(su[i].name, buff);
		fflush(stdin);
		printf("请输入%d提交时间：", i + 1);
		scanf("%f", &su[i].give_time);
		fflush(stdin);
		printf("请输入%d运行时间：", i + 1);
		scanf("%f", &su[i].run_time);
		fflush(stdin);
		i++;
	}

	for (int j = 0; j < N; j++)//对进程提交时间进行排序
	{
		for (int k = 0; k < N - j - 1; k++)
		{
			if (su[k].give_time > su[k + 1].give_time)
			{
				DATA tmp = su[k];
				su[k] = su[k + 1];
				su[k + 1] = tmp;
			}
		}
	}

	i = 0;
	while (i < N)
	{
		if (su[i].give_time == su[i + 1].give_time)//计算最早到达的有几个，如果一个，直接计算
		{
			count++;
		}
		else
		{
			break;
		}
		i++;
	}
	if (count == 0)//如果只有一个最早提交时间
	{
		su[0].start_time = su[0].give_time;
		su[0].end_time = su[0].run_time;
		su[0].use_time = su[0].end_time - su[0].give_time;
		su[0].ave_use_time = su[0].use_time / su[0].run_time;
		sum = sum + su[0].ave_use_time;
	}
	else
	{
		for (int j = 0; j < count; j++)//对进程运行时间进行排序
		{
			for (int k = 0; k < count - j - 1; k++)
			{
				if (su[k].run_time > su[k + 1].run_time)
				{
					DATA tmp = su[k];
					su[k] = su[k + 1];
					su[k + 1] = tmp;
				}
			}
		}
		su[0].start_time = su[0].give_time;
		su[0].end_time = su[0].run_time;
		su[0].use_time = su[0].end_time - su[0].give_time;
		su[0].ave_use_time = su[0].use_time / su[0].run_time;
		sum = sum + su[0].ave_use_time;
	}

	while (m < N)
	{
		s = m + 1;
		count = 0;
		while (su[m].end_time > su[s].give_time && s < N)//找出有几个在第一次计算后，到达的进程
		{
			index = s;
			count++;
			s++;
		}
		if (count == 1)
		{
			su[m + 1].start_time = su[m].end_time;
			su[m + 1].end_time = su[m + 1].start_time + su[m + 1].run_time;
			su[m + 1].use_time = su[m + 1].end_time - su[m + 1].give_time;
			su[m + 1].ave_use_time = su[m + 1].use_time / su[m + 1].run_time;
			sum = sum + su[m + 1].ave_use_time;
		}
		else if (index == N - 1)
		{
			for (int j = m + 1; j < N; j++)
			{
				for (int k = m + 1; k < N; k++)
				{
					if (su[k].run_time > su[k + 1].run_time)
					{
						DATA tmp = su[k];
						su[k] = su[k + 1];
						su[k + 1] = tmp;
					}
				}
			}
			while (m + 1 < N)
			{
				su[m + 1].start_time = su[m].end_time;
				su[m + 1].end_time = su[m + 1].start_time + su[m + 1].run_time;
				su[m + 1].use_time = su[m + 1].end_time - su[m + 1].give_time;
				su[m + 1].ave_use_time = su[m + 1].use_time / su[m + 1].run_time;
				sum = sum + su[m + 1].ave_use_time;

				m++;
			}
			break;
		}
		else
		{
			for (int j = m + 1; j < index; j++)
			{
				for (int k = m + 1; k < index; k++)
				{
					if (su[k].run_time > su[k + 1].run_time)
					{
						DATA tmp = su[k];
						su[k] = su[k + 1];
						su[k + 1] = tmp;
					}
				}
			}
			su[m + 1].start_time = su[m].end_time;
			su[m + 1].end_time = su[m + 1].start_time + su[m + 1].run_time;
			su[m + 1].use_time = su[m + 1].end_time - su[m + 1].give_time;
			su[m + 1].ave_use_time = su[m + 1].use_time / su[m + 1].run_time;
			sum = sum + su[m + 1].ave_use_time;
		}
		m++;
	}
	show(su, sum);
}


void PSA()
{
	DATA2 su[N];
	int i = 0;
	float sum = 0;
	int count = 0;
	int s = 0;
	int m = 0;
	int index = 0;
	while (i < N)//输入进程信息
	{
		char buff[20];
		printf(buff, "进程%d", i + 1);
		strcpy(su[i].name, buff);
		fflush(stdin);
		printf("请输入%d提交时间：", i + 1);
		scanf("%f", &su[i].give_time);
		fflush(stdin);
		printf("请输入%d运行时间：", i + 1);
		scanf("%f", &su[i].run_time);
		fflush(stdin);
		printf("请输入%d优先级：", i + 1);
		scanf("%d", &su[i].first);
		i++;
	}
	for (int j = 0; j < N; j++)//对进程提交时间进行排序
	{
		for (int k = 0; k < N - j - 1; k++)
		{
			if (su[k].give_time > su[k + 1].give_time)
			{
				DATA2 tmp = su[k];
				su[k] = su[k + 1];
				su[k + 1] = tmp;
			}
		}
	}
	i = 0;
	while (i < N)
	{
		if (su[i].give_time == su[i + 1].give_time)//计算最早到达的有几个，如果一个，直接算
		{
			count++;
		}
		else
		{
			break;
		}
		i++;
	}
	if (count == 0)//如果只有一个最早提交时间
	{
		su[0].start_time = su[0].give_time;
		su[0].end_time = su[0].run_time;
		su[0].use_time = su[0].end_time - su[0].give_time;
		su[0].ave_use_time = su[0].use_time / su[0].run_time;
		sum = sum + su[0].ave_use_time;
	}
	else
	{
		for (int j = 0; j < count; j++)//对进程运行时间进行排序
		{
			for (int k = 0; k < count - j - 1; k++)
			{
				if (su[k].first > su[k + 1].first)
				{
					DATA2 tmp = su[k];
					su[k] = su[k + 1];
					su[k + 1] = tmp;
				}
			}
		}
		su[0].start_time = su[0].give_time;
		su[0].end_time = su[0].run_time;
		su[0].use_time = su[0].end_time - su[0].give_time;
		su[0].ave_use_time = su[0].use_time / su[0].run_time;
		sum = sum + su[0].ave_use_time;
	}

	while (m < N)
	{
		s = m + 1;
		count = 0;
		while (su[m].end_time > su[s].give_time && s < N)//找出有几个在第一次计算后，到达的进程
		{
			index = s;
			count++;
			s++;
		}
		if (count == 1)
		{
			su[m + 1].start_time = su[m].end_time;
			su[m + 1].end_time = su[m + 1].start_time + su[m + 1].run_time;
			su[m + 1].use_time = su[m + 1].end_time - su[m + 1].give_time;
			su[m + 1].ave_use_time = su[m + 1].use_time / su[m + 1].run_time;
			sum = sum + su[m + 1].ave_use_time;
		}
		else if (index == N - 1)
		{
			for (int j = m + 1; j < N; j++)
			{
				for (int k = m + 1; k < N - j - 1; k++)
				{
					if (su[k].first > su[k + 1].first)
					{
						DATA2 tmp = su[k];
						su[k] = su[k + 1];
						su[k + 1] = tmp;
					}
				}
			}
			while (m + 1 < N)
			{
				su[m + 1].start_time = su[m].end_time;
				su[m + 1].end_time = su[m + 1].start_time + su[m + 1].run_time;
				su[m + 1].use_time = su[m + 1].end_time - su[m + 1].give_time;
				su[m + 1].ave_use_time = su[m + 1].use_time / su[m + 1].run_time;
				sum = sum + su[m + 1].ave_use_time;
				m++;
			}
			break;
		}
		else
		{
			for (int j = m + 1; j < index; j++)
			{
				for (int k = m + 1; k < index; k++)
				{
					if (su[k].first > su[k + 1].first)
					{
						DATA2 tmp = su[k];
						su[k] = su[k + 1];
						su[k + 1] = tmp;
					}
				}
			}
			su[m + 1].start_time = su[m].end_time;
			su[m + 1].end_time = su[m + 1].start_time + su[m + 1].run_time;
			su[m + 1].use_time = su[m + 1].end_time - su[m + 1].give_time;
			su[m + 1].ave_use_time = su[m + 1].use_time / su[m + 1].run_time;
			sum = sum + su[m + 1].ave_use_time;
		}
		m++;
	}
	float ave = sum / N;
	printf("进程号 提交时间 运行时间 优先级 开始时间 完成时间 周转时间 带权周转时间\n");
	for (int k = 0; k < N; k++)
	{
		printf("%s  %f  %f    %d    %f  %f  %f  %f\n", su[k].name, su[k].give_time, su[k].run_time, su[k].first, su[k].start_time, su[k].end_time, su[k].use_time, su[k].ave_use_time);
	}
	printf("平均带权周转:%f\n", ave);
}

void main_page()
{
	char ch;
	while (1)
	{
		printf("请输入要选择的调度算法序号：");
		fflush(stdin);
		ch = getchar();
		fflush(stdin);
		switch (ch)
		{
		case 'a':
			FCFS();//先来先服务
			break;
		case 'b':
			SJF();//短作业优先
			break;
		case 'c':
			PSA();//优先级
			break;
		case 'q':
			exit(0);
		default:
			printf("输入有误,请重新输入\n");

		}
	}
}
void show_main_page()
{
	printf("**************************\n");
	printf("a------先来先服务调度\n");
	printf("b------短作业优先调度\n");
	printf("c------优先级调度\n");
	printf("**************************\n");
	main_page();
}
int main()
{
	show_main_page();
	return 0;
}
