#define _CRT_SECURE_NO_WARNINGS 1
#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *  @name        : void menu(void)
 *	@description : �˵�
 *	@param		 : None
 *	@return		 : None
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
	printf("\t\t\t\t  |           ������ϵͳ���ܲ˵�             |\n");
	printf("\t\t\t\t  |__________________________________________|\n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | 1.����������            2.�����½��     |\n");
	printf("\t\t\t\t  |__________________________________________|\n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | 3.ɾ�����              4.��������       |\n");
	printf("\t\t\t\t  |__________________________________________|\n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | 5.��ѯ����              6.�ҵ������е�   |\n");
	printf("\t\t\t\t  |__________________________________________|\n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | 7.�ж��Ƿ�ɻ�          8.��ż����       |\n");
	printf("\t\t\t\t  |__________________________________________|\n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | 9.��ת����(�ǵݹ�)      10.��ת����(�ݹ�)|\n");
	printf("\t\t\t\t  |__________________________________________|\n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  |              11.ɾ������                 |\n");
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
 *  @name        : Status ListEmpty(LinkedList L)
 *	@description : �ж��Ƿ�Ϊ������
 *	@param		 : L(the head node)
 *	@return		 : int
 *  @notice      : None
 */
int ListEmpty(LinkedList L)
{
	if (L->next)   /*�Ѵ���������*/
		return 1;
	else
		return 0;
}

/**
 *  @name        : Status printList(LinkedList L)
 *	@description : ��ӡ����
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status printList(LinkedList L)
{
	if (ListEmpty(L) == 0)   /*δ��������*/
	{
		printf("NULL\n");
		return ERROR;
	}
	LinkedList La;
	La = L->next;
	while (La)
	{
		printf("%d->", La->data);
		La = La->next;
	}
	printf("NULL\n");
	return SUCCESS;
}

/**
 *  @name        : Status print(LinkedList L)
 *	@description : �������
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status print(LinkedList L)
{
	system("cls");
	printf("���������:");
	printList(L);
	system("pause");
	return SUCCESS;
}


/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : ��ʼ����������ͷ���
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList* L)
{
	*L = (LinkedList)malloc(sizeof(LNode));
	if ((*L) == NULL)   /*���ٿռ�ʧ��*/
	{
		printf("%s\n", strerror(errno));
		return ERROR;
	}
	(*L)->next = NULL;
	return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : ���������ͷ����нڵ�
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList* L)
{
	system("cls");
	if (!ListEmpty(*L))
	{
		printf("δ��������\n");
		system("pause");
		return ;
	}
	LinkedList La, Lb;
	La = (*L)->next;           /*pָ���һ�����*/
	while (La)                /* �ͷſռ�*/
	{
		Lb = La->next;
		free(La);
		La = Lb;
	}
	(*L)->next = NULL;        /*ָ���ָ��*/
	printf("ɾ������ɹ�\n");
	system("pause");
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : ��q�ŵ�p��  ����q������������ݷŵ�q��
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode* p, LNode* q)
{
	q->next = p->next;/*q->nextָ��p����һ��Ԫ��*/
	p->next = q;      /*p->nextָ��qԪ��*/
	return SUCCESS;
}

/**
 *  @name        : Status Insert(LinkedList* L)
 *	@description : ����Ҫ���������,�������λ��
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status Insert(LinkedList* L)
{
	LNode* p, * q;
	ElemType pdata, qdata;
	LinkedList La = (*L)->next;
	system("cls");
	if (!ListEmpty(*L))
	{
		printf("δ��������\n");
		system("pause");
		return ERROR;
	}
	if (ListEmpty(*L))   /*�Ѵ���������*/
	{
		printf("����ǰ������: ");
		printList(*L);
	}
	printf("������Ҫ�����λ�õ�ǰһ����������:");
	pdata = EnterInteger();  /*��ȡ����*/
	printf("������Ҫ���������:");
	qdata = EnterInteger();    /*��ȡ����*/
	while (La)            /*Ѱ��Ҫ�������λ��*/
	{
		if (La->data == pdata)   /*�ҵ�Ҫ�������λ��*/
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
	p = La;
	q = (LNode*)malloc(sizeof(LNode));/*����һ���ռ�*/
	if (q == NULL)
	{
		printf("%s\n", strerror(errno));
		return ERROR;
	}
	q->data = qdata;                  /*�����ݴ�ŵ�q����*/
	q->next = NULL;
	InsertList(p, q);
	printf("����������: ");
	printList(*L);
	system("pause");
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : ɾ���ڵ� p ֮��ĵ�һ���ڵ㣬b��ɾ���Ľ�㲢����ֵ����� e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
DeleteList(LNode* p, ElemType* e)
{
	if (p->next == NULL)     /*pָ�����һ��Ԫ��Ϊ��ָ��*/
	{
		return ERROR;
	}
	*e = p->next->data;          /*��e��ֵɾ����������*/
	p->next = p->next->next;     /*p����һ��Ԫ��ָ���һ��Ԫ��*/
	return SUCCESS;
}

/**
 *  @name        : Status delete(LinkedList* L)
 *	@description : ����Ҫɾ���Ľ������,����ȡ��Ҫɾ���Ľ�������
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status Delete(LinkedList* L)
{
	ElemType data;
	ElemType e = 0;
	LNode* p =NULL;
	system("cls");
	if (!ListEmpty(*L))
	{
		printf("δ��������\n");
		system("pause");
		return ERROR;
	}
	LinkedList La = (*L);
	if (ListEmpty(*L))   /*�Ѵ���������*/
	{
		printf("ɾ��ǰ������: ");
		printList(*L);
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
	DeleteList(p, &e);  /*ɾ����Ӧ�Ľ��*/
	printf("ɾ���������: ");
	printList(*L);
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
	printf("%d->",e);
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
	system("cls");
	if (!ListEmpty(L))
	{
		printf("δ��������\n");
		system("pause");
		return ;
	}
	printf("���������Ϊ��");
	L = L->next;
	while (L)
	{
		visit(L->data);
		L = L->next;
	}
	printf("NULL\n");
	system("pause");
}


/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : �������в�ѯ��һ������e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e)
{
	LinkedList p;
	int NodeNum = 1;
	p = L->next;
	while (p)
	{
		if (p->data == e)
		{
			printf("��ѯ�ɹ�,�������ڵ�%d�����\n", NodeNum);
			return SUCCESS;
		}
		p = p->next;
		NodeNum++;
	}
	printf("������û�и�����\n");
	return ERROR;
}

/**
 *  @name        : Status Found(LinkedList L)
 *	@description : ��������Ҫ���ҵ�����
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status Search(LinkedList L)
{
	ElemType data;
	system("cls");
	if (!ListEmpty(L))
	{
		printf("δ��������\n");
		system("pause");
		return ERROR;
	}
	printf("������Ҫ��ѯ������:>");
	data = EnterInteger();  /*��ȡ����*/
	SearchList(L, data);
	system("pause");
	return SUCCESS;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : ��ת����
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList* L)
{
	LinkedList p1, p2, p3;
	system("cls");
	if (!ListEmpty(*L))
	{
		printf("δ��������\n");
		system("pause");
		return ERROR;
	}
	p1 = NULL;
	printf("��תǰ������:");
	printList(*L);
	p2 = (*L)->next;
	while (p2)   /*��ת����*/
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	(*L)->next = p1; /*ͷ���ָ���һ��Ԫ��*/
	printf("��ת����ɹ�\n");
	printf("��ת�������:");
	printList(*L);
	system("pause");
	return SUCCESS;

}

/**
 *  @name        : LinkedList ReverseRec(LinkedList L)
 *	@description : �ݹ鷴ת����
 *	@param		 : L(the head node)
 *	@return		 : LinkedList
 *  @notice      : None
 */
LinkedList ReverseRec(LinkedList L)
{
	if (L == NULL || L->next == NULL) /*�ݹ��������*/
		return L;
	else
	{
		LinkedList p = ReverseRec(L->next);/*�ȷ�ת���������,�Ӻ���ǰ��ת*/
		L->next->next = L;/*����һ�����ָ��ǰһ�����*/
		L->next = NULL;/*��ԭ������ǰһ�����ָ���һ������ָ���ϵ�Ͽ�*/
		return p;
	}
}

/**
 *  @name        : LinkedList ReverseRec(LinkedList L)
 *	@description : �ݹ鷴ת����
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseRecLink(LinkedList* L)
{
	system("cls");
	if (!ListEmpty(*L))
	{
		printf("δ��������\n");
		system("pause");
		return ERROR;
	}
	if (ListEmpty(*L))   /*�Ѵ���������*/
	{
		printf("��תǰ������: ");
		printList(*L);
	}
	LinkedList head = (*L)->next;
	head = ReverseRec(head);
	(*L)->next = head;
	printf("��ת����ɹ�\n");
	printf("��ת�������: ");
	printList(*L);
	system("pause");
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : �ж��Ƿ�ɻ�
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L)
{
	system("cls");
	if (!ListEmpty(L))
	{
		printf("δ��������\n");
		system("pause");
		return ERROR;
	}
	LinkedList La = L->next, Lb = L->next;
	while (Lb)   /*��Lb�ߵ�β*/
	{
		Lb = Lb->next;
		if (La == Lb)
		{
			printf("����ɻ�\n");
			system("pause");
			return SUCCESS;
		}
	}
	printf("����δ�ɻ�\n");
	system("pause");
	return SUCCESS;
}

void ChangeLink(LinkedList* L, int OddLocate, int EvenLocate)
{
	LinkedList p = (*L)->next;
	LinkedList pOdd = NULL, pEven = NULL;
	int i = 0;
	ElemType temp;
	for (i = 1; (i <= OddLocate) || (i <= EvenLocate); i++)
	{
		if (i == OddLocate)
		{
			pOdd = p;
		}
		if (i == EvenLocate)
		{
			pEven = p;
		}
		p = p->next;
	}
	if (pOdd && pEven)
	{
		temp = pOdd->data;
		pOdd->data = pEven->data;
		pEven->data = temp;
	}
}
/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : ��ż����, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList* L)
{
	system("cls");
	if (!ListEmpty(*L))
	{
		printf("δ��������\n");
		system("pause");
		return ERROR;
	}
	printf("��ż����ǰ������ ");
	printList(*L);
	LinkedList La, p, Lb, Lhead;
	int OddLocate = 1, EvenLocate =1;
	p = (*L)->next;
	InitList(&La);  /*��ʼ��La*/
	Lhead = La;  /*Lhead�洢La��ͷ���*/
	while (p)   /*����L��La*/
	{
		Lb = (LinkedList)malloc(sizeof(LNode));
		if (Lb == NULL)
		{
			printf("%s\n", strerror(errno));
			return NULL;
		}
		Lb->next = NULL;   /*Lbָ���ָ��*/
		La->next = Lb;     /*La��nextָ��Lb*/
		Lb->data = p->data; /*Lb�洢p������*/
		La = La->next;     /*Laָ��Lb*/
		p = p->next;
	}
	p = (*L);  /*ָ��ͷ���*/
	Lhead = Lhead->next; /*ָ���ƺ������ͷ���*/
	La = Lhead;   /*Laָ���һ��Ԫ��*/
	Lb = Lhead;   /*Lbָ���һ��Ԫ��*/
	while (La && Lb)
	{
		while (La)  /*Ѱ������ֵ*/
		{
			if (La->data % 2 == 1) /*�ҵ�����*/
			{	
				break;
			}
			OddLocate++;
			La = La->next;
		}
		while (Lb)  /*Ѱ��ż��ֵ*/
		{
			if (Lb->data % 2 == 0) /*�ҵ�ż��*/
			{	
				break;
			}
			EvenLocate++;
			Lb = Lb->next;
		}
		if (La && Lb)   /*����ż������*/
		{
			ChangeLink(&p, OddLocate, EvenLocate);
			La = La->next;
			Lb = Lb->next;
			OddLocate++;
			EvenLocate++;
		}
	}
	printf("��ż����������� ");
	printList(*L);
	system("pause");
	return (*L);
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : Ѱ���м���
 *	@param		 : L(the head node)
 *	@return		 : LNode�����м���
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList* L)
{
	system("cls");
	if (ListEmpty(*L))   /*�Ѵ���������*/
	{
		printf("�Ѵ���������: ");
		printList(*L);
	}
	else
	{
		printf("δ��������\n");
		system("pause");
		return NULL;
	}
	LinkedList La = (*L)->next, Lb = (*L)->next;
	while (Lb)
	{
		Lb = Lb->next;
		if (Lb == NULL)
		{
			break;
		}
		Lb = Lb->next;
		if (Lb == NULL)
		{
			break;
		}
		La = La->next;
	}
	if (La == NULL)
		return ERROR;
	printf("�м��������Ϊ:%d\n", La->data);
	system("pause");
	return La;
}

/**
 *  @name        : Status CreateList(LinkedList* L)
 *	@description : ����һ������
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status CreateList(LinkedList* L)
{
	int i, NodeNum = 0;
	system("cls");
	InitList(L);
	LinkedList La, Ltail = *L;
	printf("��������Ҫ�����Ľ����:>");
	while ((NodeNum = EnterInteger()) < 0) /*�����ֵС��0*/
	{
		printf("�����ֵС��0,��Ч\n");
		printf("����������:>");
	}
	/*β�巨*/
	for (i = 0; i < NodeNum; i++)         /*��ȡ����Ԫ������*/
	{
		La = (LinkedList)malloc(sizeof(LNode));  /*����һ���µĽ��*/
		if (La == NULL) /*���ٿռ�ʧ��*/
		{
			printf("%s\n", strerror(errno));
			return ERROR;
		}
		printf("�������%d����������:>", i + 1);
		La->data = EnterInteger();      /*��ȡ����*/
		La->next = NULL;
		Ltail->next = La;
		Ltail = La;
	}
	system("pause");
	return SUCCESS;
}

