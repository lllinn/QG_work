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



//��ջ
Status initLStack(LinkStack* s);//��ʼ��ջ
Status isEmptyLStack(LinkStack* s);//�ж�ջ�Ƿ�Ϊ��
StackElemType getTopLStack(LinkStack* s);//�õ�ջ��Ԫ��
Status clearLStack(LinkStack* s);//���ջ
Status destroyLStack(LinkStack* s);//����ջ
Status LStackLength(LinkStack* s, int* length);//���ջ����
Status pushLStack(LinkStack* s, StackElemType data);//��ջ
StackElemType popLStack(LinkStack* s);//��ջ



#endif 
