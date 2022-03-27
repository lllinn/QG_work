#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

#define ERROR   0
#define SUCCESS 1


typedef int Status;
typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
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
Status getTopLStack(LinkStack* s, ElemType* e);//�õ�ջ��Ԫ��
Status clearLStack(LinkStack* s);//���ջ
Status destroyLStack(LinkStack* s);//����ջ
Status LStackLength(LinkStack* s, int* length);//���ջ����
Status pushLStack(LinkStack* s, ElemType data);//��ջ
Status popLStack(LinkStack* s, ElemType* data);//��ջ

void menu(void); //�˵�
int EnterInteger(void);//��������
int Enter(void);//����һ������
Status print(LinkStack* s);//��ӡջ
Status Add(LinkStack* s);//���һ���µ�Ԫ��
Status Delete(LinkStack* s);//ɾ��һ��Ԫ��
Status GetTop(LinkStack* s);//��ȡջ��Ԫ��
Status GetLenghth(LinkStack* s);//ջ�ĳ���
#endif 
