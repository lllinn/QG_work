#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

#define ERROR   0
#define SUCCESS 1


typedef int Status;
typedef char CElemType;//存放字符类型

typedef  struct CStackNode
{
	CElemType data;
	struct CStackNode* next;
}CStackNode, * CLinkStackPtr;


typedef  struct  CLinkStack
{
	CLinkStackPtr top;
	int	count;
}CLinkStack;

typedef double DElemType;//存放浮点类型

typedef  struct DStackNode
{
	DElemType data;
	struct DStackNode* next;
}DStackNode, * DLinkStackPtr;


typedef  struct  DLinkStack
{
	DLinkStackPtr top;
	int	count;
}DLinkStack;

//链栈
Status initCLStack(CLinkStack* s);//初始化栈
Status isEmptyCLStack(CLinkStack* s);//判断栈是否为空
Status getTopCLStack(CLinkStack* s, CElemType* e);//得到栈顶元素
Status pushCLStack(CLinkStack* s, CElemType data);//入栈
Status popCLStack(CLinkStack* s, CElemType* data);//出栈

Status initDLStack(DLinkStack* s);//初始化栈
Status isEmptyDLStack(DLinkStack* s);//判断栈是否为空
Status getTopDLStack(DLinkStack* s, DElemType* e);//得到栈顶元素
Status pushDLStack(DLinkStack* s, DElemType data);//入栈
Status popDLStack(DLinkStack* s, DElemType* data);//出栈


#endif 
