#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"link_stack.h"


//��׺ת��׺  
//����ֱ�����
//���ڷ���;:
//��1�������� ����ջ
//��2��������ţ���ջ�����Ž������ȼ��Ƚ�
//               ��ջ���������ȼ��ͣ��˷��Ž�ջ��Ĭ��ջ�����������ţ����������ȼ���ͣ�
//               ��ջ���������ȼ����ͣ���ջ�����ŵ����������֮���ջ
//��3�������ţ���ջ�����ŵ����������ֱ��ƥ��������
//��4��������������ջ�����з��ŵ��������
//*******************************
//8+(3-1)*5  ----------->  8 3 1 - 5 * +
typedef struct MYCHAR
{
	link_stackNode node;
	char* address;
	//int index;
}mychar;

int isnum(char c)
{
	return c > '0'&&c < '9';
}

int isleft(char c)
{
	return c == '(';
}
int isright(char c)
{
	return c == ')';
}
int isoperator(char c)//�ж��Ƿ������������
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}
//����mychar
mychar* create_mychar(char* p)
{
	mychar* tmp = (mychar*)malloc(sizeof(mychar));
	tmp->address = p;//������mychar  ָ��������ַ��� *p
	
	return tmp;
}
//�������ȼ�
int get_priority(char c)
{
	if (c == '*' || c == '/')
		return 2;
	if (c == '+' || c == '-')
		return 1;
	return 0;
}
//��ֵ����
void num_print(char* p)
{
	printf("%c", *p);
}
//�����Ų���
void leftoperator(link_stack* stack,char* p)
{
	push_linkstack(stack,(link_stackNode*)create_mychar(p));

}
//�����Ų���
void rightoperator(link_stack* stack)
{
	while (size_linkstack(stack) > 0)
	{
		mychar* tmp = (mychar*)top_linkstack(stack);//����ջ������ ȷ���Ƿ�Ϊ������
		//���ƥ�䵽������
		if (isleft(*tmp->address))
		{
			pop_linkstack(stack);//ջ�� ��ջ
			break;
		}
		//�������������  ����ҵ���ֱ������
		printf("%c", *(tmp->address));
		pop_linkstack(stack);
		free(tmp);
	}
}
//���������
void operator_math(link_stack* stack, char* p)
{
	//��ȡ��ջ������ �Ƚ����ȼ�
	mychar* tmp = (mychar*)top_linkstack(stack);
	if (tmp== NULL)//��ջΪ�� ��ǰ����ֱ����ջ
	{
		push_linkstack(stack,(link_stackNode*)create_mychar(p));
		return;
	}
	//���ջ���������ȼ����ڵ�ǰ�������ȼ� ��ǰ����ֱ����ջ
	if (get_priority(*(tmp->address)) < get_priority(*p))
	{
		push_linkstack(stack,(link_stackNode*)create_mychar(p));
		return;
	}
	//������ȼ����Ų���
	else 
	{
		while (size_linkstack(stack) > 0)
		{
			mychar* tmp2 = (mychar*)top_linkstack(stack);//����ջ������ ȷ���Ƿ�Ϊ������
		//���ƥ�䵽������
			if (isleft(*tmp2->address))
			{
				pop_linkstack(stack);//ջ�� ��ջ
				break;
			}
			//���
			printf("%c",*(tmp2->address));
			//����
			pop_linkstack(stack);
			//�ͷ�
			free(tmp2);
		}
	}
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
	char* str = "8+(3-1)*5";
	char* p = str;
	//int index = 0;
	while (*p != '\0')
	{
		if (isnum(*p))
		{
			num_print(p);
		}
		if (isleft(*p))//������  ֱ�ӽ�ջ
		{
			leftoperator(stack, p);
		}
		if (isright(*p))//������
		{
			rightoperator(stack);
		}
		if (isoperator(*p))
		{
			operator_math(stack, p);
		}
		/*
		if (isleft(*p))//��������� ���ջ
		{
			push_linkstack(stack, (link_stackNode*)create_mychar(p, index));
		}
		if (isright(*p) && size_linkstack(stack) > 0)//���������
		{
			mychar* tmp = (mychar*)top_linkstack(stack);//������ǰջ��Ԫ��  ���жϵ����Ƿ�Ϊƥ���������
			if (isleft(*(tmp->address)))
			{
				pop_linkstack(stack);
				free(stack);
			}
			else
			{
				printf("������û��ƥ���������");
				showerror(str, index);
			}
		}
		p++;
		index++;*/
		p++;
	}

	while (size_linkstack(stack) > 0)
	{
		mychar* tmp = (mychar*)top_linkstack(stack);
		printf("%c",*(tmp->address));//���ջ��ʣ�����
		pop_linkstack(stack);
		free(tmp);
	}
	system("pause");
	return 0;
}