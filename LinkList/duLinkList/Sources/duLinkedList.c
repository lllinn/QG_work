#define _CRT_SECURE_NO_WARNINGS 1
#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : ��ʼ��������ͷ�ڵ�Ŀ�����
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList* L)
{
	(*L) = (DuLinkedList)malloc(sizeof(DuLNode));  /*���ٿռ�*/
	if ((*L) == NULL)   /*���ٿռ�ʧ��*/
	{
		printf("%s\n", strerror(errno));
		return ERROR;
	}
	(*L)->next = NULL;   /*ָ���ָ��*/
	(*L)->prior = NULL;  /*ָ���ָ��*/
	return SUCCESS;
}

/**
 *  @name        : void menu(void)
 *	@description : �˵�
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
void menu(void)
{
	system("cls");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t\t   __________________________________________\n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  |           ˫����ϵͳ���ܲ˵�             |\n");
	printf("\t\t\t\t  |__________________________________________|\n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | 1.����������            2.�����½��(ǰ) |\n");
	printf("\t\t\t\t  |__________________________________________|\n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | 3.�����½��(��)        4.ɾ�����       |\n");
	printf("\t\t\t\t  |__________________________________________|\n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | 5.��������              6.ɾ������       |\n");
	printf("\t\t\t\t  |__________________________________________|\n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  |               0.�˳�ϵͳ                 |\n");
	printf("\t\t\t\t  |__________________________________________|\n");

	printf("\n");
	printf("��������Ҫѡ��Ĺ���:");
}

/**
 *  @name        : int EnterInteger(void)
 *	@description : ��������
 *	@param		 : Node
 *	@return		 : int
 *  @notice      : None
 */
int EnterInteger(void)
{
	int NodeNum = 0;
	char ch;
	//while ((!scanf("%d", &NodeNum)) || (getchar() != '\n'))  /*���������Ϊ����*/
	while ((!scanf("%d", &NodeNum)) || (ch = getchar(), ((ch != '\n') && (ch != '\t') && (ch != ' '))))  /*���������Ϊ����*/
	{
		printf("��������ݲ�������,������������ȷ������\n");
		while (getchar() != '\n');  /*����������������*/
	}
	return NodeNum;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : �ж��Ƿ�Ϊ������
 *	@param		 : L(the head node)
 *	@return		 : int
 *  @notice      : None
 */
int ListEmpty_DuL(DuLinkedList L)
{
	if (L->next)   /*�Ѵ���������*/
		return 1;
	else
		return 0;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : ��������
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList* L)
{
	system("cls");
	if (!ListEmpty_DuL(*L))
	{
		printf("δ��������\n");
		system("pause");
		return;
	}
	DuLinkedList La = (*L)->next, Lb;  /*Laָ���һ�����*/
	while (La)
	{
		Lb = La;        /*�洢La��λ��*/
		La = La->next;  /*ָ����һ�����*/
		free(Lb);       /*�ͷ�Lb*/
	}
	(*L)->next = NULL;  /*ָ���ָ��*/
	printf("ɾ������ɹ�\n");
	system("pause");
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : ����һ���µ�����
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
Status CreateduList(DuLinkedList* L)
{
	int i, NodeNum = 0;
	system("cls");
	InitList_DuL(L);       /*��ʼ������*/
	DuLinkedList La, Ltail = *L;
	printf("��������Ҫ�����Ľ����:>");
	while ((NodeNum = EnterInteger()) < 0) /*�����ֵС��0*/
	{
		printf("�����ֵС��0,��Ч\n");
		printf("����������:>");
	}
	/*β�巨*/
	for (i = 0; i < NodeNum; i++)
	{
		La = (DuLinkedList)malloc(sizeof(DuLNode));
		if (La == NULL) /*���ٿռ�ʧ��*/
		{
			printf("%s\n", strerror(errno));
			return ERROR;
		}
		printf("�������%d����������:>", i + 1);
		La->data = EnterInteger();      /*��ȡ����*/
		La->next = NULL;                /*nextָ��NULL*/
		La->prior = Ltail;              /*priorָ��ǰһ������*/
		Ltail->next = La;               /*ǰһ������ָ��La*/
		Ltail = La;                     /*Ltailָ��β��*/
	}
	system("pause");
	return SUCCESS;
}

/**
 *  @name        : Status printList_DuL(DuLinkedList L)
 *	@description : �������
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
Status printList_DuL(DuLinkedList L)
{
	if (ListEmpty_DuL(L) == 0)   /*δ��������*/
	{
		printf("NULL\n");
		return ERROR;
	}
	DuLinkedList La;
	La = L->next;
	while (La)
	{
		printf("%d<--->", La->data);
		La = La->next;
	}
	printf("NULL\n");
	return SUCCESS;
}

/**
 *  @name        : Status print(DuLinkedList L)
 *	@description : �������
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
Status print(DuLinkedList L)
{
	system("cls");
	printf("���������:");
	printList_DuL(L);
	system("pause");
	return SUCCESS;
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p�����q�嵽pǰ
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)
{
	q->next = p;        /*q->nextָ��p*/
	q->prior = p->prior;/*q->priorָ��pǰһ�����*/
	p->prior->next = q; /*pǰһ������nextָ��q*/
	p->prior = q;       /*p->priorָ��q*/
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p ��q�嵽p��
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)
{
	q->prior = p;         /*q->priorָ��p*/
	q->next = p->next;    /*q->nextָ��p����һ�����*/
	if (p->next != NULL)  /*p����һ����㲻Ϊ��ָ��*/
	{
		p->next->prior = q; /*p����һ������priorָ��q*/
	}
	p->next = q;            /*p��nextָ��q*/
	return SUCCESS;
}

/**
 *  @name        : Status InsertBefore(DuLinkedList *L) 
 *	@description : insert node q before node p�����q�嵽pǰ
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertBefore(DuLinkedList *L) 
{
	DuLNode* p, * q;
	ElemType pdata, qdata;
	DuLinkedList La = (*L)->next;
	system("cls");
	if (!ListEmpty_DuL(*L))
	{
		printf("δ��������\n");
		system("pause");
		return ERROR;
	}
	if (ListEmpty_DuL(*L))   /*�Ѵ���������*/
	{
		printf("����ǰ������: ");
		printList_DuL(*L);
	}
	printf("������Ҫ�����λ�õĺ�һ����������:");
	pdata = EnterInteger();  /*��ȡ����*/
	printf("������Ҫ���������:");
	qdata = EnterInteger();    /*��ȡ����*/
	while (La)     /*Ѱ��Ҫ�ҵ�����*/
	{
		if (La->data == pdata) /*�ҵ�������*/
		{
			break;
		}
		La = La->next;
	}
	if (La == NULL)
	{
		printf("δ�ҵ���λ��\n");
		system("pause");
		return ERROR;
	}
	p = La;   /*�����ݴ���p*/
	q = (DuLNode*)malloc(sizeof(DuLNode));/*����һ���ռ�*/
	if (q == NULL)
	{
		printf("%s\n", strerror(errno));
		return ERROR;
	}
	q->data = qdata;
	q->next = NULL;
	q->prior = NULL;
	InsertBeforeList_DuL(p, q);
	printf("����������: ");
	printList_DuL(*L);
	system("pause");
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p ��q�嵽p��
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertAfter(DuLinkedList *L)
{
	DuLNode* p, * q;
	ElemType pdata, qdata;
	DuLinkedList La = (*L)->next;
	system("cls");
	if (!ListEmpty_DuL(*L))
	{
		printf("δ��������\n");
		system("pause");
		return ERROR;
	}
	if (ListEmpty_DuL(*L))   /*�Ѵ���������*/
	{
		printf("����ǰ������: ");
		printList_DuL(*L);
	}
	printf("������Ҫ�����λ�õ�ǰһ����������:");
	pdata = EnterInteger();  /*��ȡ����*/
	printf("������Ҫ���������:");
	qdata = EnterInteger();    /*��ȡ����*/
	while (La)     /*Ѱ��Ҫ�ҵ�����*/
	{
		if (La->data == pdata) /*�ҵ�������*/
		{
			break;
		}
		La = La->next;
	}
	if (La == NULL)
	{
		printf("δ�ҵ���λ��\n");
		system("pause");
		return ERROR;
	}
	p = La;   /*�����ݴ���p*/
	q = (DuLNode*)malloc(sizeof(DuLNode));/*����һ���ռ�*/
	if (q == NULL)
	{
		printf("%s\n", strerror(errno));
		return ERROR;
	}
	q->data = qdata;
	q->next = NULL;
	q->prior = NULL;
	InsertAfterList_DuL(p, q);
	printf("����������: ");
	printList_DuL(*L);
	system("pause");
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : ɾ���ڵ� p ֮��ĵ�һ���ڵ㣬������ֵ����� e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode* p, ElemType* e)
{
	*e = p->next->data;
	p->next = p->next->next;
	if (p->next != NULL)
	{
		(p->next)->prior = p;
	}
	return SUCCESS;
}

/**
 *  @name        : SStatus Delete(DuLinkedList* p)
 *	@description : ɾ���ڵ� p ֮��ĵ�һ���ڵ㣬������ֵ����� e
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
Status Delete(DuLinkedList* L)
{
	ElemType data;
	ElemType e = 0;
	DuLNode* p = NULL;
	system("cls");
	if (!ListEmpty_DuL(*L))
	{
		printf("δ��������\n");
		system("pause");
		return ERROR;
	}
	DuLinkedList La = (*L);
	if (ListEmpty_DuL(*L))   /*�Ѵ���������*/
	{
		printf("ɾ��ǰ������: ");
		printList_DuL(*L);
	}
	printf("������Ҫɾ����������:");
	data = EnterInteger();  /*��ȡҪɾ��������*/
	while (La)         /*Ѱ��Ҫɾ��������*/
	{
		if (La->data == data)  /*�ҵ�Ҫɾ����Ԫ��*/
		{

			break;
		}
		p = La;          /*������һ����������*/
		La = La->next;   /*Laָ����һ�����*/
	}
	if (La == NULL)  /*û���ҵ�Ҫɾ��������*/
	{
		printf("û���ҵ��ý��,�������������\n");
		system("pause");
		return ERROR;
	}
	DeleteList_DuL(p, &e);  /*ɾ����Ӧ�Ľ��*/
	printf("ɾ���������: ");
	printList_DuL(*L);
	printf("��ɾ����������:%d\n", e);
	system("pause");
	return SUCCESS;
}

/**
 *  @name        : void visit(ElemType e)
 *	@description : print e
 *	@param		 : e
 *	@return		 : None
 *  @notice      : None
 */
void visitElem(ElemType e)
{
	printf("%d<--->", e);
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : ��������
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
	system("cls");
	if (!ListEmpty_DuL(L))
	{
		printf("δ��������\n");
		system("pause");
		return;
	}
	printf("���������Ϊ��");
	L = L->next;
	while (L)
	{
		visitElem(L->data);
		L = L->next;
	}
	printf("NULL\n");
	system("pause");
}
