#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ERROR   0
#define SUCCESS 1
#include "binary_sort_tree.h"

typedef NodePtr StackElemType;

typedef  struct StackNode
{
	StackElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;


typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;



//链栈
Status initLStack(LinkStack* s);//初始化栈
Status isEmptyLStack(LinkStack* s);//判断栈是否为空
StackElemType getTopLStack(LinkStack* s);//得到栈顶元素
Status clearLStack(LinkStack* s);//清空栈
Status destroyLStack(LinkStack* s);//销毁栈
Status LStackLength(LinkStack* s, int* length);//检测栈长度
Status pushLStack(LinkStack* s, StackElemType data);//入栈
StackElemType popLStack(LinkStack* s);//出栈



#endif 
