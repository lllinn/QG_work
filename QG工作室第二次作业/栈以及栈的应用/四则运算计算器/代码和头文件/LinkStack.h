#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

#define ERROR   0
#define SUCCESS 1


typedef int Status;
typedef char CElemType;//����ַ�����

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

typedef double DElemType;//��Ÿ�������

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

//��ջ
Status initCLStack(CLinkStack* s);//��ʼ��ջ
Status isEmptyCLStack(CLinkStack* s);//�ж�ջ�Ƿ�Ϊ��
Status getTopCLStack(CLinkStack* s, CElemType* e);//�õ�ջ��Ԫ��
Status pushCLStack(CLinkStack* s, CElemType data);//��ջ
Status popCLStack(CLinkStack* s, CElemType* data);//��ջ

Status initDLStack(DLinkStack* s);//��ʼ��ջ
Status isEmptyDLStack(DLinkStack* s);//�ж�ջ�Ƿ�Ϊ��
Status getTopDLStack(DLinkStack* s, DElemType* e);//�õ�ջ��Ԫ��
Status pushDLStack(DLinkStack* s, DElemType data);//��ջ
Status popDLStack(DLinkStack* s, DElemType* data);//��ջ


#endif 
