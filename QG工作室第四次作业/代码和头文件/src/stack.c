#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"

//��ʼ��ջ
Status initLStack(LinkStack* s)
{
	s->top = NULL;//ָ���ָ��
	s->count = 0;//��ʼ����ֵ
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
//����0 ��ջ��Ϊ��
//����1 ��ջΪ��
Status isEmptyLStack(LinkStack* s)
{
	if (s->count)  //ջ��Ϊ��
		return 0;
	else          //ջΪ��
		return 1;
}

//�õ�ջ��Ԫ��
StackElemType getTopLStack(LinkStack* s)
{
	if (isEmptyLStack(s))  //ջΪ��
	{
		return	NULL;
	}
	return s->top->data;
}


//���ջ
Status clearLStack(LinkStack* s)
{
	LinkStackPtr p, q;
	p = s->top;  //ָ��ջ��
	while (p)
	{
		q = p->next; //ָ����һ�����
		free(p);
		p = q;
	}
	s->top = NULL;  //ָ���ָ��
	s->count = 0;   //��ռ���
	return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack* s)
{
	if (isEmptyLStack(s))  //ջΪ��
	{
		return ERROR;
	}
	LinkStackPtr p, q;
	p = s->top;  //ָ��ջ��
	while (p)
	{
		q = p->next; //ָ����һ�����
		free(p);
		p = q;
	}
	s->top = NULL;  //ָ���ָ��
	s->count = 0;   //��ռ���
	return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack* s, int* length)
{
	*length = s->count;//���ݸ���
	return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack* s, StackElemType data)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode)); //����һ���µĿռ�
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
		return ERROR;
	}
	p->next = s->top; //p��nextָ��ջ��
	p->data = data;   //��ȡ����
	s->top = p;       //p��Ϊջ��
	s->count++;       //������1
	return SUCCESS;
}

//��ջ
StackElemType popLStack(LinkStack* s)
{
	if (isEmptyLStack(s))  //ջΪ��
	{
		return NULL;
	}
	LinkStackPtr p = s->top; //pָ��ջ��
	StackElemType temp = p->data;
	s->top = s->top->next;   //ջ��ָ����һ�����
	s->count--;              //������1
	free(p);                 //�ͷſռ�
	return temp;
}

