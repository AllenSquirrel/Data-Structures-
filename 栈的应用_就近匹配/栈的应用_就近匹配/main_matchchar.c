#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"link_stack.h"


//字符就近匹配
//重写编译器检查 代码括弧匹配问题 

//*******************************
//扫描字符串 左括号入栈  等到右括号出现  检查此时从栈顶弹出是否为左括号  是则左括号出栈，匹配成功  否则匹配失败

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
	tmp->address = p;//创建新mychar  指向检索的字符串 *p
	tmp->index = index;//检索字符串 的字符位置记录
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
	char* str = "1+2+6(dsf)dfdflp((sdfs)";
	char* p = str;
	int index = 0;
	while (*p != '\0')
	{
		if (isleft(*p))//如果左括号 则进栈
		{
			push_linkstack(stack, (link_stackNode*)create_mychar(p,index));
		}
		if (isright(*p)&&size_linkstack(stack)>0)//如果右括号
		{
			mychar* tmp=(mychar*)top_linkstack(stack);//弹出当前栈顶元素  并判断弹出是否为匹配的左括号
			if (isleft(*(tmp->address)))
			{
				pop_linkstack(stack);
				free(tmp);
			}
			else
			{
				printf("右括号没有匹配的左括号\n");
				showerror(str, index);
			}
		}
		p++;
		index++;
	}

	while (size_linkstack(stack) > 0)
	{
		mychar* tmp = (mychar*)top_linkstack(stack);
		printf("左括号没有匹配的右括号\n");//检索到的左括号全部入栈  没有检索到右括号 则没有左括号从栈顶 出栈 直至全部检索结束 匹配失败
		showerror(str,tmp->index);
		pop_linkstack(stack);
		free(tmp);
	}
	system("pause");
	return 0;
}