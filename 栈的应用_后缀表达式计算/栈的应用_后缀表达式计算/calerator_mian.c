#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"link_stack.h"

//��׺����ʽ����

//�������֣���ջ

//���ڷ��ţ�
//(1)��ջ�е����Ҳ�����
//(2)��ջ�е����������
//��3�����ݷ��Ž�������
//��4����������ѹջ

//����������ջ��Ψһ����Ϊ������
typedef struct MYNUM
{
	link_stackNode node;
	int val;
}mynum;


int isnum(char c)
{
	return c > '0'&&c < '9';
}

int calculate(int left, int right, char c)
{
	int ret = 0;
	switch (c)
	{
	case '+':
		ret = left + right;
		break;
	case '-':
		ret = left - right;
		break;
	case '*':
		ret = left * right;
		break;
	case '/':
		ret = left / right;
		break;
	default:
		break;
	}
	return ret;
}

int main()
{
	//�����洢ջ
	link_stack* stack = init_linkstack();
	char* str = "831-5*+";
	char* p = str;
	
	while (*p != '\0')
	{
		if (isnum(*p))//������� ���ջ
		{
			mynum* num = (mynum*)malloc(sizeof(mynum));
			num->val = *p - '0';
			push_linkstack(stack, (link_stackNode*)num);
		}
		else
		{
			mynum* right = (mynum*)top_linkstack(stack);
			//��������  �ȴ�ջ�е���ջ��������Ϊ �Ҳ�����
			int right_num= right->val;
			pop_linkstack(stack);//������������ջ������  �Ա���һ����������Ϊջ��
			free(right);

			mynum* left = (mynum*)top_linkstack(stack);
			//�ٴ�ջ�е���ջ��������Ϊ �������
			int left_num = left->val;
			pop_linkstack(stack);//������������ջ������  �Ա���һ����������Ϊջ��
			free(left);

			int ret = calculate(left_num,right_num,*p);
			mynum* num = (mynum*)malloc(sizeof(mynum));
			num->val = ret;
			push_linkstack(stack,(link_stackNode*)num);


		}
		p++;
	}

	if(size_linkstack(stack) ==1)
	{
		mynum* tmp = (mynum*)top_linkstack(stack);
		printf("��������%d\n",tmp->val);
		pop_linkstack(stack);
		//free(tmp);
	}
	free_linkstack(stack);
	system("pause");
	return 0;
}