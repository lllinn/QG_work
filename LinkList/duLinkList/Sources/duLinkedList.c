#define _CRT_SECURE_NO_WARNINGS 1
#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : 初始化仅包含头节点的空链表
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList* L)
{
	(*L) = (DuLinkedList)malloc(sizeof(DuLNode));  /*开辟空间*/
	if ((*L) == NULL)   /*开辟空间失败*/
	{
		printf("%s\n", strerror(errno));
		return ERROR;
	}
	(*L)->next = NULL;   /*指向空指针*/
	(*L)->prior = NULL;  /*指向空指针*/
	return SUCCESS;
}

/**
 *  @name        : void menu(void)
 *	@description : 菜单
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
	printf("\t\t\t\t  |           双链表系统功能菜单             |\n");
	printf("\t\t\t\t  |__________________________________________|\n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | 1.创建新链表            2.插入新结点(前) |\n");
	printf("\t\t\t\t  |__________________________________________|\n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | 3.插入新结点(后)        4.删除结点       |\n");
	printf("\t\t\t\t  |__________________________________________|\n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | 5.遍历链表              6.删除链表       |\n");
	printf("\t\t\t\t  |__________________________________________|\n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  |               0.退出系统                 |\n");
	printf("\t\t\t\t  |__________________________________________|\n");

	printf("\n");
	printf("请输入你要选择的功能:");
}

/**
 *  @name        : int EnterInteger(void)
 *	@description : 输入整数
 *	@param		 : Node
 *	@return		 : int
 *  @notice      : None
 */
int EnterInteger(void)
{
	int NodeNum = 0;
	char ch;
	//while ((!scanf("%d", &NodeNum)) || (getchar() != '\n'))  /*输入的数不为整数*/
	while ((!scanf("%d", &NodeNum)) || (ch = getchar(), ((ch != '\n') && (ch != '\t') && (ch != ' '))))  /*输入的数不为整数*/
	{
		printf("输入的数据不是整数,请重新输入正确的数据\n");
		while (getchar() != '\n');  /*将缓冲区的数读走*/
	}
	return NodeNum;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : 判断是否为空链表
 *	@param		 : L(the head node)
 *	@return		 : int
 *  @notice      : None
 */
int ListEmpty_DuL(DuLinkedList L)
{
	if (L->next)   /*已创建好链表*/
		return 1;
	else
		return 0;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : 销毁链表
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList* L)
{
	system("cls");
	if (!ListEmpty_DuL(*L))
	{
		printf("未创建链表\n");
		system("pause");
		return;
	}
	DuLinkedList La = (*L)->next, Lb;  /*La指向第一个结点*/
	while (La)
	{
		Lb = La;        /*存储La的位置*/
		La = La->next;  /*指向下一个结点*/
		free(Lb);       /*释放Lb*/
	}
	(*L)->next = NULL;  /*指向空指针*/
	printf("删除链表成功\n");
	system("pause");
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : 创建一个新的链表
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
Status CreateduList(DuLinkedList* L)
{
	int i, NodeNum = 0;
	system("cls");
	InitList_DuL(L);       /*初始化链表*/
	DuLinkedList La, Ltail = *L;
	printf("请输入你要创建的结点数:>");
	while ((NodeNum = EnterInteger()) < 0) /*输入的值小于0*/
	{
		printf("输入的值小于0,无效\n");
		printf("请重新输入:>");
	}
	/*尾插法*/
	for (i = 0; i < NodeNum; i++)
	{
		La = (DuLinkedList)malloc(sizeof(DuLNode));
		if (La == NULL) /*开辟空间失败*/
		{
			printf("%s\n", strerror(errno));
			return ERROR;
		}
		printf("请输入第%d个结点的数据:>", i + 1);
		La->data = EnterInteger();      /*获取数据*/
		La->next = NULL;                /*next指向NULL*/
		La->prior = Ltail;              /*prior指向前一个数据*/
		Ltail->next = La;               /*前一个数据指向La*/
		Ltail = La;                     /*Ltail指向尾部*/
	}
	system("pause");
	return SUCCESS;
}

/**
 *  @name        : Status printList_DuL(DuLinkedList L)
 *	@description : 输出链表
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
Status printList_DuL(DuLinkedList L)
{
	if (ListEmpty_DuL(L) == 0)   /*未创建链表*/
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
 *	@description : 输出链表
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
Status print(DuLinkedList L)
{
	system("cls");
	printf("链表的数据:");
	printList_DuL(L);
	system("pause");
	return SUCCESS;
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p将结点q插到p前
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)
{
	q->next = p;        /*q->next指向p*/
	q->prior = p->prior;/*q->prior指向p前一个结点*/
	p->prior->next = q; /*p前一个结点的next指向q*/
	p->prior = q;       /*p->prior指向q*/
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p 将q插到p后
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)
{
	q->prior = p;         /*q->prior指向p*/
	q->next = p->next;    /*q->next指向p的下一个结点*/
	if (p->next != NULL)  /*p的下一个结点不为空指针*/
	{
		p->next->prior = q; /*p的下一个结点的prior指向q*/
	}
	p->next = q;            /*p的next指向q*/
	return SUCCESS;
}

/**
 *  @name        : Status InsertBefore(DuLinkedList *L) 
 *	@description : insert node q before node p将结点q插到p前
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
		printf("未创建链表\n");
		system("pause");
		return ERROR;
	}
	if (ListEmpty_DuL(*L))   /*已创建好链表*/
	{
		printf("插入前的链表: ");
		printList_DuL(*L);
	}
	printf("请输入要插入的位置的后一个结点的数据:");
	pdata = EnterInteger();  /*获取数据*/
	printf("请输入要插入的数据:");
	qdata = EnterInteger();    /*获取数据*/
	while (La)     /*寻找要找的数据*/
	{
		if (La->data == pdata) /*找到该数据*/
		{
			break;
		}
		La = La->next;
	}
	if (La == NULL)
	{
		printf("未找到该位置\n");
		system("pause");
		return ERROR;
	}
	p = La;   /*将数据传给p*/
	q = (DuLNode*)malloc(sizeof(DuLNode));/*开辟一个空间*/
	if (q == NULL)
	{
		printf("%s\n", strerror(errno));
		return ERROR;
	}
	q->data = qdata;
	q->next = NULL;
	q->prior = NULL;
	InsertBeforeList_DuL(p, q);
	printf("插入后的链表: ");
	printList_DuL(*L);
	system("pause");
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p 将q插到p后
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
		printf("未创建链表\n");
		system("pause");
		return ERROR;
	}
	if (ListEmpty_DuL(*L))   /*已创建好链表*/
	{
		printf("插入前的链表: ");
		printList_DuL(*L);
	}
	printf("请输入要插入的位置的前一个结点的数据:");
	pdata = EnterInteger();  /*获取数据*/
	printf("请输入要插入的数据:");
	qdata = EnterInteger();    /*获取数据*/
	while (La)     /*寻找要找的数据*/
	{
		if (La->data == pdata) /*找到该数据*/
		{
			break;
		}
		La = La->next;
	}
	if (La == NULL)
	{
		printf("未找到该位置\n");
		system("pause");
		return ERROR;
	}
	p = La;   /*将数据传给p*/
	q = (DuLNode*)malloc(sizeof(DuLNode));/*开辟一个空间*/
	if (q == NULL)
	{
		printf("%s\n", strerror(errno));
		return ERROR;
	}
	q->data = qdata;
	q->next = NULL;
	q->prior = NULL;
	InsertAfterList_DuL(p, q);
	printf("插入后的链表: ");
	printList_DuL(*L);
	system("pause");
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : 删除节点 p 之后的第一个节点，并将其值分配给 e
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
 *	@description : 删除节点 p 之后的第一个节点，并将其值分配给 e
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
		printf("未创建链表\n");
		system("pause");
		return ERROR;
	}
	DuLinkedList La = (*L);
	if (ListEmpty_DuL(*L))   /*已创建好链表*/
	{
		printf("删除前的链表: ");
		printList_DuL(*L);
	}
	printf("请输入要删除结点的数据:");
	data = EnterInteger();  /*获取要删除的数据*/
	while (La)         /*寻找要删除的数据*/
	{
		if (La->data == data)  /*找到要删除的元素*/
		{

			break;
		}
		p = La;          /*保存上一个结点的数据*/
		La = La->next;   /*La指向下一个结点*/
	}
	if (La == NULL)  /*没有找到要删除的数据*/
	{
		printf("没有找到该结点,请检查输入的内容\n");
		system("pause");
		return ERROR;
	}
	DeleteList_DuL(p, &e);  /*删除对应的结点*/
	printf("删除后的链表: ");
	printList_DuL(*L);
	printf("被删除的数据是:%d\n", e);
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
 *	@description : 遍历链表
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
	system("cls");
	if (!ListEmpty_DuL(L))
	{
		printf("未创建链表\n");
		system("pause");
		return;
	}
	printf("链表的数据为：");
	L = L->next;
	while (L)
	{
		visitElem(L->data);
		L = L->next;
	}
	printf("NULL\n");
	system("pause");
}
