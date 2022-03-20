#define _CRT_SECURE_NO_WARNINGS 1
#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *  @name        : void menu(void)
 *	@description : 菜单
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
	printf("\t\t\t\t  |           单链表系统功能菜单             |\n");
	printf("\t\t\t\t  |__________________________________________|\n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | 1.创建新链表            2.插入新结点     |\n");
	printf("\t\t\t\t  |__________________________________________|\n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | 3.删除结点              4.遍历链表       |\n");
	printf("\t\t\t\t  |__________________________________________|\n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | 5.查询数据              6.找到链表中点   |\n");
	printf("\t\t\t\t  |__________________________________________|\n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | 7.判断是否成环          8.奇偶调换       |\n");
	printf("\t\t\t\t  |__________________________________________|\n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | 9.反转链表(非递归)      10.反转链表(递归)|\n");
	printf("\t\t\t\t  |__________________________________________|\n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  |              11.删除链表                 |\n");
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
 *  @name        : Status ListEmpty(LinkedList L)
 *	@description : 判断是否为空链表
 *	@param		 : L(the head node)
 *	@return		 : int
 *  @notice      : None
 */
int ListEmpty(LinkedList L)
{
	if (L->next)   /*已创建好链表*/
		return 1;
	else
		return 0;
}

/**
 *  @name        : Status printList(LinkedList L)
 *	@description : 打印链表
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status printList(LinkedList L)
{
	if (ListEmpty(L) == 0)   /*未创建链表*/
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
 *	@description : 输出链表
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status print(LinkedList L)
{
	system("cls");
	printf("链表的数据:");
	printList(L);
	system("pause");
	return SUCCESS;
}


/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : 初始化链表，带有头结点
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList* L)
{
	*L = (LinkedList)malloc(sizeof(LNode));
	if ((*L) == NULL)   /*开辟空间失败*/
	{
		printf("%s\n", strerror(errno));
		return ERROR;
	}
	(*L)->next = NULL;
	return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : 销毁链表，释放所有节点
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList* L)
{
	system("cls");
	if (!ListEmpty(*L))
	{
		printf("未创建链表\n");
		system("pause");
		return ;
	}
	LinkedList La, Lb;
	La = (*L)->next;           /*p指向第一个结点*/
	while (La)                /* 释放空间*/
	{
		Lb = La->next;
		free(La);
		La = Lb;
	}
	(*L)->next = NULL;        /*指向空指针*/
	printf("删除链表成功\n");
	system("pause");
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : 将q放到p后  输入q并将输入的数据放到q后
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode* p, LNode* q)
{
	q->next = p->next;/*q->next指向p的下一个元素*/
	p->next = q;      /*p->next指向q元素*/
	return SUCCESS;
}

/**
 *  @name        : Status Insert(LinkedList* L)
 *	@description : 输入要插入的数据,及插入的位置
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
		printf("未创建链表\n");
		system("pause");
		return ERROR;
	}
	if (ListEmpty(*L))   /*已创建好链表*/
	{
		printf("插入前的链表: ");
		printList(*L);
	}
	printf("请输入要插入的位置的前一个结点的数据:");
	pdata = EnterInteger();  /*获取数据*/
	printf("请输入要插入的数据:");
	qdata = EnterInteger();    /*获取数据*/
	while (La)            /*寻找要插入结点的位置*/
	{
		if (La->data == pdata)   /*找到要插入结点的位置*/
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
	p = La;
	q = (LNode*)malloc(sizeof(LNode));/*开辟一个空间*/
	if (q == NULL)
	{
		printf("%s\n", strerror(errno));
		return ERROR;
	}
	q->data = qdata;                  /*将数据存放到q里面*/
	q->next = NULL;
	InsertList(p, q);
	printf("插入后的链表: ");
	printList(*L);
	system("pause");
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : 删除节点 p 之后的第一个节点，b把删除的结点并将其值分配给 e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
DeleteList(LNode* p, ElemType* e)
{
	if (p->next == NULL)     /*p指向的下一个元素为空指针*/
	{
		return ERROR;
	}
	*e = p->next->data;          /*给e赋值删除结点的数据*/
	p->next = p->next->next;     /*p的下一个元素指向后一个元素*/
	return SUCCESS;
}

/**
 *  @name        : Status delete(LinkedList* L)
 *	@description : 输入要删除的结点数据,并读取将要删除的结点的数据
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
		printf("未创建链表\n");
		system("pause");
		return ERROR;
	}
	LinkedList La = (*L);
	if (ListEmpty(*L))   /*已创建好链表*/
	{
		printf("删除前的链表: ");
		printList(*L);
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
	DeleteList(p, &e);  /*删除对应的结点*/
	printf("删除后的链表: ");
	printList(*L);
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
		printf("未创建链表\n");
		system("pause");
		return ;
	}
	printf("链表的数据为：");
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
 *	@description : 在链表中查询第一个出现e
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
			printf("查询成功,该数据在第%d个结点\n", NodeNum);
			return SUCCESS;
		}
		p = p->next;
		NodeNum++;
	}
	printf("链表中没有该数据\n");
	return ERROR;
}

/**
 *  @name        : Status Found(LinkedList L)
 *	@description : 用来输入要查找的数据
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
		printf("未创建链表\n");
		system("pause");
		return ERROR;
	}
	printf("请输入要查询的数据:>");
	data = EnterInteger();  /*获取数据*/
	SearchList(L, data);
	system("pause");
	return SUCCESS;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : 反转链表
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
		printf("未创建链表\n");
		system("pause");
		return ERROR;
	}
	p1 = NULL;
	printf("反转前的链表:");
	printList(*L);
	p2 = (*L)->next;
	while (p2)   /*反转链表*/
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	(*L)->next = p1; /*头结点指向第一个元素*/
	printf("反转链表成功\n");
	printf("反转后的链表:");
	printList(*L);
	system("pause");
	return SUCCESS;

}

/**
 *  @name        : LinkedList ReverseRec(LinkedList L)
 *	@description : 递归反转链表
 *	@param		 : L(the head node)
 *	@return		 : LinkedList
 *  @notice      : None
 */
LinkedList ReverseRec(LinkedList L)
{
	if (L == NULL || L->next == NULL) /*递归结束条件*/
		return L;
	else
	{
		LinkedList p = ReverseRec(L->next);/*先反转后面的链表,从后往前反转*/
		L->next->next = L;/*将后一个结点指向前一个结点*/
		L->next = NULL;/*将原链表中前一个结点指向后一个结点的指向关系断开*/
		return p;
	}
}

/**
 *  @name        : LinkedList ReverseRec(LinkedList L)
 *	@description : 递归反转链表
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseRecLink(LinkedList* L)
{
	system("cls");
	if (!ListEmpty(*L))
	{
		printf("未创建链表\n");
		system("pause");
		return ERROR;
	}
	if (ListEmpty(*L))   /*已创建好链表*/
	{
		printf("反转前的链表: ");
		printList(*L);
	}
	LinkedList head = (*L)->next;
	head = ReverseRec(head);
	(*L)->next = head;
	printf("反转链表成功\n");
	printf("反转后的链表: ");
	printList(*L);
	system("pause");
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : 判断是否成环
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L)
{
	system("cls");
	if (!ListEmpty(L))
	{
		printf("未创建链表\n");
		system("pause");
		return ERROR;
	}
	LinkedList La = L->next, Lb = L->next;
	while (Lb)   /*让Lb走到尾*/
	{
		Lb = Lb->next;
		if (La == Lb)
		{
			printf("链表成环\n");
			system("pause");
			return SUCCESS;
		}
	}
	printf("链表未成环\n");
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
 *	@description : 奇偶调换, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList* L)
{
	system("cls");
	if (!ListEmpty(*L))
	{
		printf("未创建链表\n");
		system("pause");
		return ERROR;
	}
	printf("奇偶调换前的链表： ");
	printList(*L);
	LinkedList La, p, Lb, Lhead;
	int OddLocate = 1, EvenLocate =1;
	p = (*L)->next;
	InitList(&La);  /*初始化La*/
	Lhead = La;  /*Lhead存储La的头结点*/
	while (p)   /*复制L到La*/
	{
		Lb = (LinkedList)malloc(sizeof(LNode));
		if (Lb == NULL)
		{
			printf("%s\n", strerror(errno));
			return NULL;
		}
		Lb->next = NULL;   /*Lb指向空指针*/
		La->next = Lb;     /*La的next指向Lb*/
		Lb->data = p->data; /*Lb存储p的内容*/
		La = La->next;     /*La指向Lb*/
		p = p->next;
	}
	p = (*L);  /*指向头结点*/
	Lhead = Lhead->next; /*指向复制后链表的头结点*/
	La = Lhead;   /*La指向第一个元素*/
	Lb = Lhead;   /*Lb指向第一个元素*/
	while (La && Lb)
	{
		while (La)  /*寻找奇数值*/
		{
			if (La->data % 2 == 1) /*找到奇数*/
			{	
				break;
			}
			OddLocate++;
			La = La->next;
		}
		while (Lb)  /*寻找偶数值*/
		{
			if (Lb->data % 2 == 0) /*找到偶数*/
			{	
				break;
			}
			EvenLocate++;
			Lb = Lb->next;
		}
		if (La && Lb)   /*奇数偶数调换*/
		{
			ChangeLink(&p, OddLocate, EvenLocate);
			La = La->next;
			Lb = Lb->next;
			OddLocate++;
			EvenLocate++;
		}
	}
	printf("奇偶调换后的链表： ");
	printList(*L);
	system("pause");
	return (*L);
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : 寻找中间结点
 *	@param		 : L(the head node)
 *	@return		 : LNode返回中间结点
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList* L)
{
	system("cls");
	if (ListEmpty(*L))   /*已创建好链表*/
	{
		printf("已创建的链表: ");
		printList(*L);
	}
	else
	{
		printf("未创建链表\n");
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
	printf("中间结点的数据为:%d\n", La->data);
	system("pause");
	return La;
}

/**
 *  @name        : Status CreateList(LinkedList* L)
 *	@description : 创建一个链表
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
	printf("请输入你要创建的结点数:>");
	while ((NodeNum = EnterInteger()) < 0) /*输入的值小于0*/
	{
		printf("输入的值小于0,无效\n");
		printf("请重新输入:>");
	}
	/*尾插法*/
	for (i = 0; i < NodeNum; i++)         /*获取各个元素数据*/
	{
		La = (LinkedList)malloc(sizeof(LNode));  /*生成一个新的结点*/
		if (La == NULL) /*开辟空间失败*/
		{
			printf("%s\n", strerror(errno));
			return ERROR;
		}
		printf("请输入第%d个结点的数据:>", i + 1);
		La->data = EnterInteger();      /*获取数据*/
		La->next = NULL;
		Ltail->next = La;
		Ltail = La;
	}
	system("pause");
	return SUCCESS;
}

