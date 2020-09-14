#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
��1�������ȷ����㷨��FCFS��
�����̵�����ʹ�������ȷ����㷨ʱ��ÿ�ε����ǴӾ����Ľ��̶�����ѡ��һ�����Ƚ���ö��еĽ��̣���������ҵ�����Ⱥ�Ĵ��������е��ȣ�Ϊ֮���䴦�����ʹ֮Ͷ�����С��ý���һֱ���е���ɻ���ĳ�¼��������󣬽��̵��ȳ���Ž������������������̡�
��2������ҵ�����㷨��SJF��
	 ����ҵ�����㷨������ҵ�ĳ������������ȼ�����ҵԽ�̣������ȼ�Խ�ߡ���ҵ�ĳ���������ҵ��Ҫ�������ʱ���������ġ������ڽ��̵���ʱ���Ӿ���������ѡ��һ����ҵʱ����̵Ľ��̣�Ϊ֮���䴦�����ʹ֮Ͷ�����С�
��3�����ȼ������㷨��PSA��
	 ���ȼ������㷨�У��ǻ�����ҵ�Ľ��ȳ̶ȣ����ⲿ������ҵ��Ӧ�����ȼ��������㷨�Ǹ��ݸ����ȼ����е��ȵġ������ڽ��̵���ʱ���Ӿ���������ѡ��һ�����ȼ��ߵĽ��̣�Ϊ֮���䴦�����ʹ֮���С�

*/


#define N 5
typedef struct _DATA
{
	char name[20];
	float give_time;//�ύʱ��
	float run_time;//����ʱ��
	float start_time;//��ʼʱ��
	float end_time;//���ʱ��
	float use_time;//��תʱ��
	float ave_use_time;//��Ȩ��תʱ��
}DATA;

typedef struct __DATA
{
	char name[20];
	float give_time;//�ύʱ��
	float run_time;//����ʱ��
	int first;//���ȼ�
	float start_time;//��ʼʱ��
	float end_time;//���ʱ��
	float use_time;//��תʱ��
	float ave_use_time;//��Ȩ��תʱ��
}DATA2;

void show(DATA *su, float sum)
{
	float ave = sum / N;
	printf("���̺� �ύʱ�� ����ʱ�� ��ʼʱ�� ���ʱ�� ��תʱ�� ��Ȩ��תʱ��\n");
	for (int k = 0; k < N; k++)
	{
		printf("%s  %f  %f  %f  %f  %f  %f\n", su[k].name, su[k].give_time, su[k].run_time, su[k].start_time, su[k].end_time, su[k].use_time, su[k].ave_use_time);
	}
	printf("ƽ����Ȩ��ת:%f\n", ave);
}
void FCFS()
{
	DATA su[N];
	int i = 0;
	float sum = 0;
	while (i < N)//���������Ϣ
	{
		char buff[20];
		printf(buff, "����%d", i + 1);
		strcpy(su[i].name, buff);
		fflush(stdin);
		printf("������%d�ύʱ�䣺", i + 1);
		scanf("%f", &su[i].give_time);
		fflush(stdin);
		printf("������%d����ʱ�䣺", i + 1);
		scanf("%f", &su[i].run_time);
		fflush(stdin);
		i++;
	}
	for (int y = 0; y < N; y++)//�Խ����ύʱ���������
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

	for (int j = 0; j < N; j++)//���㿪ʼʱ�䣬���ʱ�䣬��תʱ��
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
	while (i < N)//���������Ϣ
	{
		char buff[20];
		sprintf(buff, "����%d", i + 1);
		strcpy(su[i].name, buff);
		fflush(stdin);
		printf("������%d�ύʱ�䣺", i + 1);
		scanf("%f", &su[i].give_time);
		fflush(stdin);
		printf("������%d����ʱ�䣺", i + 1);
		scanf("%f", &su[i].run_time);
		fflush(stdin);
		i++;
	}

	for (int j = 0; j < N; j++)//�Խ����ύʱ���������
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
		if (su[i].give_time == su[i + 1].give_time)//�������絽����м��������һ����ֱ�Ӽ���
		{
			count++;
		}
		else
		{
			break;
		}
		i++;
	}
	if (count == 0)//���ֻ��һ�������ύʱ��
	{
		su[0].start_time = su[0].give_time;
		su[0].end_time = su[0].run_time;
		su[0].use_time = su[0].end_time - su[0].give_time;
		su[0].ave_use_time = su[0].use_time / su[0].run_time;
		sum = sum + su[0].ave_use_time;
	}
	else
	{
		for (int j = 0; j < count; j++)//�Խ�������ʱ���������
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
		while (su[m].end_time > su[s].give_time && s < N)//�ҳ��м����ڵ�һ�μ���󣬵���Ľ���
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
	while (i < N)//���������Ϣ
	{
		char buff[20];
		printf(buff, "����%d", i + 1);
		strcpy(su[i].name, buff);
		fflush(stdin);
		printf("������%d�ύʱ�䣺", i + 1);
		scanf("%f", &su[i].give_time);
		fflush(stdin);
		printf("������%d����ʱ�䣺", i + 1);
		scanf("%f", &su[i].run_time);
		fflush(stdin);
		printf("������%d���ȼ���", i + 1);
		scanf("%d", &su[i].first);
		i++;
	}
	for (int j = 0; j < N; j++)//�Խ����ύʱ���������
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
		if (su[i].give_time == su[i + 1].give_time)//�������絽����м��������һ����ֱ����
		{
			count++;
		}
		else
		{
			break;
		}
		i++;
	}
	if (count == 0)//���ֻ��һ�������ύʱ��
	{
		su[0].start_time = su[0].give_time;
		su[0].end_time = su[0].run_time;
		su[0].use_time = su[0].end_time - su[0].give_time;
		su[0].ave_use_time = su[0].use_time / su[0].run_time;
		sum = sum + su[0].ave_use_time;
	}
	else
	{
		for (int j = 0; j < count; j++)//�Խ�������ʱ���������
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
		while (su[m].end_time > su[s].give_time && s < N)//�ҳ��м����ڵ�һ�μ���󣬵���Ľ���
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
	printf("���̺� �ύʱ�� ����ʱ�� ���ȼ� ��ʼʱ�� ���ʱ�� ��תʱ�� ��Ȩ��תʱ��\n");
	for (int k = 0; k < N; k++)
	{
		printf("%s  %f  %f    %d    %f  %f  %f  %f\n", su[k].name, su[k].give_time, su[k].run_time, su[k].first, su[k].start_time, su[k].end_time, su[k].use_time, su[k].ave_use_time);
	}
	printf("ƽ����Ȩ��ת:%f\n", ave);
}

void main_page()
{
	char ch;
	while (1)
	{
		printf("������Ҫѡ��ĵ����㷨��ţ�");
		fflush(stdin);
		ch = getchar();
		fflush(stdin);
		switch (ch)
		{
		case 'a':
			FCFS();//�����ȷ���
			break;
		case 'b':
			SJF();//����ҵ����
			break;
		case 'c':
			PSA();//���ȼ�
			break;
		case 'q':
			exit(0);
		default:
			printf("��������,����������\n");

		}
	}
}
void show_main_page()
{
	printf("**************************\n");
	printf("a------�����ȷ������\n");
	printf("b------����ҵ���ȵ���\n");
	printf("c------���ȼ�����\n");
	printf("**************************\n");
	main_page();
}
int main()
{
	show_main_page();
	return 0;
}
