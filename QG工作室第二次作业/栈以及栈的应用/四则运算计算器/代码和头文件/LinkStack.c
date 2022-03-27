#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkStack.h"

//��ʼ��ջ
Status initCLStack(CLinkStack* s)
{
	s->top = NULL;//ָ���ָ��
	s->count = 0;//��ʼ����ֵ
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
//����0 ��ջ��Ϊ��
//����1 ��ջΪ��
Status isEmptyCLStack(CLinkStack* s)
{
	if (s->count)  //ջ��Ϊ��
		return 0;
	else          //ջΪ��
		return 1;
}

//�õ�ջ��Ԫ��
Status getTopCLStack(CLinkStack* s, CElemType* e)
{
	if (isEmptyCLStack(s))  //ջΪ��
	{
		return ERROR;
	}
	*e = s->top->data;  //�����ݴ���e
	return SUCCESS;
}

//��ջ
Status pushCLStack(CLinkStack* s, CElemType data)
{
	CLinkStackPtr p = (CLinkStackPtr)malloc(sizeof(CStackNode)); //����һ���µĿռ�
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
Status popCLStack(CLinkStack* s, CElemType* data)
{
	if (isEmptyCLStack(s))  //ջΪ��
	{
		return ERROR;
	}
	CLinkStackPtr p = s->top; //pָ��ջ��
	*data = s->top->data;    //��ȡ����
	s->top = s->top->next;   //ջ��ָ����һ�����
	s->count--;              //������1
	free(p);                 //�ͷſռ�
	return SUCCESS;
}



//��ʼ��ջ
Status initDLStack(DLinkStack* s)
{
	s->top = NULL;//ָ���ָ��
	s->count = 0;//��ʼ����ֵ
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
//����0 ��ջ��Ϊ��
//����1 ��ջΪ��
Status isEmptyDLStack(DLinkStack* s)
{
	if (s->count)  //ջ��Ϊ��
		return 0;
	else          //ջΪ��
		return 1;
}

//�õ�ջ��Ԫ��
Status getTopDLStack(DLinkStack* s, DElemType* e)
{
	if (isEmptyDLStack(s))  //ջΪ��
	{
		return ERROR;
	}
	*e = s->top->data;  //�����ݴ���e
	return SUCCESS;
}

//��ջ
Status pushDLStack(DLinkStack* s, DElemType data)
{
	DLinkStackPtr p = (DLinkStackPtr)malloc(sizeof(DStackNode)); //����һ���µĿռ�
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
Status popDLStack(DLinkStack* s, DElemType* data)
{
	if (isEmptyDLStack(s))  //ջΪ��
	{
		return ERROR;
	}
	DLinkStackPtr p = s->top; //pָ��ջ��
	*data = s->top->data;    //��ȡ����
	s->top = s->top->next;   //ջ��ָ����һ�����
	s->count--;              //������1
	free(p);                 //�ͷſռ�
	return SUCCESS;
}
