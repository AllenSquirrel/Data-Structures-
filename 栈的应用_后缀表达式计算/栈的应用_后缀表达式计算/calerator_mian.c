#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"link_stack.h"

//后缀运算式计算

//对于数字：进栈

//对于符号：
//(1)从栈中弹出右操作数
//(2)从栈中弹出左操作数
//（3）根据符号进行运算
//（4）将运算结果压栈

//遍历结束：栈中唯一数字为计算结果
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
	//创建存储栈
	link_stack* stack = init_linkstack();
	char* str = "831-5*+";
	char* p = str;
	
	while (*p != '\0')
	{
		if (isnum(*p))//如果数字 则进栈
		{
			mynum* num = (mynum*)malloc(sizeof(mynum));
			num->val = *p - '0';
			push_linkstack(stack, (link_stackNode*)num);
		}
		else
		{
			mynum* right = (mynum*)top_linkstack(stack);
			//遇到符号  先从栈中弹出栈顶数据作为 右操作数
			int right_num= right->val;
			pop_linkstack(stack);//弹出立即丢掉栈顶数据  以便下一数据上移作为栈顶
			free(right);

			mynum* left = (mynum*)top_linkstack(stack);
			//再从栈中弹出栈顶数据作为 左操作数
			int left_num = left->val;
			pop_linkstack(stack);//弹出立即丢掉栈顶数据  以便下一数据上移作为栈顶
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
		printf("运算结果：%d\n",tmp->val);
		pop_linkstack(stack);
		//free(tmp);
	}
	free_linkstack(stack);
	system("pause");
	return 0;
}