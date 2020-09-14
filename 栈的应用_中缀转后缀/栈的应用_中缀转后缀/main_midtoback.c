#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"link_stack.h"


//中缀转后缀  
//数字直接输出
//对于符号;:
//（1）左括号 ：进栈
//（2）运算符号：与栈顶符号进行优先级比较
//               若栈顶符号优先级低：此符号进栈（默认栈顶若是左括号，左括号优先级最低）
//               若栈顶符号优先级不低：将栈顶符号弹出并输出，之后进栈
//（3）右括号：将栈顶符号弹出并输出，直到匹配左括号
//（4）遍历结束：将栈中所有符号弹出并输出
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
int isoperator(char c)//判断是否是算术运算符
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}
//创建mychar
mychar* create_mychar(char* p)
{
	mychar* tmp = (mychar*)malloc(sizeof(mychar));
	tmp->address = p;//创建新mychar  指向检索的字符串 *p
	
	return tmp;
}
//返回优先级
int get_priority(char c)
{
	if (c == '*' || c == '/')
		return 2;
	if (c == '+' || c == '-')
		return 1;
	return 0;
}
//数值操作
void num_print(char* p)
{
	printf("%c", *p);
}
//左括号操作
void leftoperator(link_stack* stack,char* p)
{
	push_linkstack(stack,(link_stackNode*)create_mychar(p));

}
//右括号操作
void rightoperator(link_stack* stack)
{
	while (size_linkstack(stack) > 0)
	{
		mychar* tmp = (mychar*)top_linkstack(stack);//返回栈顶符号 确认是否为左括号
		//如果匹配到左括号
		if (isleft(*tmp->address))
		{
			pop_linkstack(stack);//栈顶 出栈
			break;
		}
		//如果不是左括弧  输出且弹出直至结束
		printf("%c", *(tmp->address));
		pop_linkstack(stack);
		free(tmp);
	}
}
//运算符操作
void operator_math(link_stack* stack, char* p)
{
	//先取出栈顶符号 比较优先级
	mychar* tmp = (mychar*)top_linkstack(stack);
	if (tmp== NULL)//若栈为空 当前符号直接入栈
	{
		push_linkstack(stack,(link_stackNode*)create_mychar(p));
		return;
	}
	//如果栈顶符号优先级低于当前符号优先级 则当前符号直接入栈
	if (get_priority(*(tmp->address)) < get_priority(*p))
	{
		push_linkstack(stack,(link_stackNode*)create_mychar(p));
		return;
	}
	//如果优先级符号不低
	else 
	{
		while (size_linkstack(stack) > 0)
		{
			mychar* tmp2 = (mychar*)top_linkstack(stack);//返回栈顶符号 确认是否为左括号
		//如果匹配到左括号
			if (isleft(*tmp2->address))
			{
				pop_linkstack(stack);//栈顶 出栈
				break;
			}
			//输出
			printf("%c",*(tmp2->address));
			//弹出
			pop_linkstack(stack);
			//释放
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
	//创建存储栈
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
		if (isleft(*p))//左括号  直接进栈
		{
			leftoperator(stack, p);
		}
		if (isright(*p))//右括号
		{
			rightoperator(stack);
		}
		if (isoperator(*p))
		{
			operator_math(stack, p);
		}
		/*
		if (isleft(*p))//如果左括号 则进栈
		{
			push_linkstack(stack, (link_stackNode*)create_mychar(p, index));
		}
		if (isright(*p) && size_linkstack(stack) > 0)//如果右括号
		{
			mychar* tmp = (mychar*)top_linkstack(stack);//弹出当前栈顶元素  并判断弹出是否为匹配的左括号
			if (isleft(*(tmp->address)))
			{
				pop_linkstack(stack);
				free(stack);
			}
			else
			{
				printf("右括号没有匹配的左括号");
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
		printf("%c",*(tmp->address));//输出栈中剩余符号
		pop_linkstack(stack);
		free(tmp);
	}
	system("pause");
	return 0;
}