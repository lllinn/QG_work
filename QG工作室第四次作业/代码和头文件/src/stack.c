#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"

//初始化栈
Status initLStack(LinkStack* s)
{
	s->top = NULL;//指向空指针
	s->count = 0;//初始化数值
	return SUCCESS;
}

//判断栈是否为空
//返回0 表栈不为空
//返回1 表栈为空
Status isEmptyLStack(LinkStack* s)
{
	if (s->count)  //栈不为空
		return 0;
	else          //栈为空
		return 1;
}

//得到栈顶元素
StackElemType getTopLStack(LinkStack* s)
{
	if (isEmptyLStack(s))  //栈为空
	{
		return	NULL;
	}
	return s->top->data;
}


//清空栈
Status clearLStack(LinkStack* s)
{
	LinkStackPtr p, q;
	p = s->top;  //指向栈顶
	while (p)
	{
		q = p->next; //指向下一个结点
		free(p);
		p = q;
	}
	s->top = NULL;  //指向空指针
	s->count = 0;   //清空计数
	return SUCCESS;
}

//销毁栈
Status destroyLStack(LinkStack* s)
{
	if (isEmptyLStack(s))  //栈为空
	{
		return ERROR;
	}
	LinkStackPtr p, q;
	p = s->top;  //指向栈顶
	while (p)
	{
		q = p->next; //指向下一个结点
		free(p);
		p = q;
	}
	s->top = NULL;  //指向空指针
	s->count = 0;   //清空计数
	return SUCCESS;
}

//检测栈长度
Status LStackLength(LinkStack* s, int* length)
{
	*length = s->count;//传递个数
	return SUCCESS;
}

//入栈
Status pushLStack(LinkStack* s, StackElemType data)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode)); //开辟一个新的空间
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
		return ERROR;
	}
	p->next = s->top; //p的next指向栈顶
	p->data = data;   //获取数据
	s->top = p;       //p改为栈顶
	s->count++;       //数量加1
	return SUCCESS;
}

//出栈
StackElemType popLStack(LinkStack* s)
{
	if (isEmptyLStack(s))  //栈为空
	{
		return NULL;
	}
	LinkStackPtr p = s->top; //p指向栈顶
	StackElemType temp = p->data;
	s->top = s->top->next;   //栈顶指向下一个结点
	s->count--;              //数量减1
	free(p);                 //释放空间
	return temp;
}

