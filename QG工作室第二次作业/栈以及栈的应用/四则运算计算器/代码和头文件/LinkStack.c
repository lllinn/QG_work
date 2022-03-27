#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkStack.h"

//初始化栈
Status initCLStack(CLinkStack* s)
{
	s->top = NULL;//指向空指针
	s->count = 0;//初始化数值
	return SUCCESS;
}

//判断栈是否为空
//返回0 表栈不为空
//返回1 表栈为空
Status isEmptyCLStack(CLinkStack* s)
{
	if (s->count)  //栈不为空
		return 0;
	else          //栈为空
		return 1;
}

//得到栈顶元素
Status getTopCLStack(CLinkStack* s, CElemType* e)
{
	if (isEmptyCLStack(s))  //栈为空
	{
		return ERROR;
	}
	*e = s->top->data;  //将数据传给e
	return SUCCESS;
}

//入栈
Status pushCLStack(CLinkStack* s, CElemType data)
{
	CLinkStackPtr p = (CLinkStackPtr)malloc(sizeof(CStackNode)); //开辟一个新的空间
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
Status popCLStack(CLinkStack* s, CElemType* data)
{
	if (isEmptyCLStack(s))  //栈为空
	{
		return ERROR;
	}
	CLinkStackPtr p = s->top; //p指向栈顶
	*data = s->top->data;    //获取数据
	s->top = s->top->next;   //栈顶指向下一个结点
	s->count--;              //数量减1
	free(p);                 //释放空间
	return SUCCESS;
}



//初始化栈
Status initDLStack(DLinkStack* s)
{
	s->top = NULL;//指向空指针
	s->count = 0;//初始化数值
	return SUCCESS;
}

//判断栈是否为空
//返回0 表栈不为空
//返回1 表栈为空
Status isEmptyDLStack(DLinkStack* s)
{
	if (s->count)  //栈不为空
		return 0;
	else          //栈为空
		return 1;
}

//得到栈顶元素
Status getTopDLStack(DLinkStack* s, DElemType* e)
{
	if (isEmptyDLStack(s))  //栈为空
	{
		return ERROR;
	}
	*e = s->top->data;  //将数据传给e
	return SUCCESS;
}

//入栈
Status pushDLStack(DLinkStack* s, DElemType data)
{
	DLinkStackPtr p = (DLinkStackPtr)malloc(sizeof(DStackNode)); //开辟一个新的空间
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
Status popDLStack(DLinkStack* s, DElemType* data)
{
	if (isEmptyDLStack(s))  //栈为空
	{
		return ERROR;
	}
	DLinkStackPtr p = s->top; //p指向栈顶
	*data = s->top->data;    //获取数据
	s->top = s->top->next;   //栈顶指向下一个结点
	s->count--;              //数量减1
	free(p);                 //释放空间
	return SUCCESS;
}
