#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"link_stack.h"


//�ַ��ͽ�ƥ��
//��д��������� ��������ƥ������ 

//*******************************
//ɨ���ַ��� ��������ջ  �ȵ������ų���  ����ʱ��ջ�������Ƿ�Ϊ������  ���������ų�ջ��ƥ��ɹ�  ����ƥ��ʧ��

typedef struct MYCHAR
{
	link_stackNode node;
	char* address;
	int index;
}mychar;


int isleft(char c)
{
	return c == '(';
}
int isright(char c)
{
	return c == ')';
}

mychar* create_mychar(char* p,int index)
{
	mychar* tmp = (mychar*)malloc(sizeof(mychar));
	tmp->address = p;//������mychar  ָ��������ַ��� *p
	tmp->index = index;//�����ַ��� ���ַ�λ�ü�¼
}

void showerror(char* str, int pos)
{
	printf("%s\n", str);
	for (int i = 0; i < pos; i++)
	{
		printf(" ");
	}
	printf("A");
}
int main()
{
	//�����洢ջ
	link_stack* stack = init_linkstack();
	char* str = "1+2+6(dsf)dfdflp((sdfs)";
	char* p = str;
	int index = 0;
	while (*p != '\0')
	{
		if (isleft(*p))//��������� ���ջ
		{
			push_linkstack(stack, (link_stackNode*)create_mychar(p,index));
		}
		if (isright(*p)&&size_linkstack(stack)>0)//���������
		{
			mychar* tmp=(mychar*)top_linkstack(stack);//������ǰջ��Ԫ��  ���жϵ����Ƿ�Ϊƥ���������
			if (isleft(*(tmp->address)))
			{
				pop_linkstack(stack);
				free(tmp);
			}
			else
			{
				printf("������û��ƥ���������\n");
				showerror(str, index);
			}
		}
		p++;
		index++;
	}

	while (size_linkstack(stack) > 0)
	{
		mychar* tmp = (mychar*)top_linkstack(stack);
		printf("������û��ƥ���������\n");//��������������ȫ����ջ  û�м����������� ��û�������Ŵ�ջ�� ��ջ ֱ��ȫ���������� ƥ��ʧ��
		showerror(str,tmp->index);
		pop_linkstack(stack);
		free(tmp);
	}
	system("pause");
	return 0;
}