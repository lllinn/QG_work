/***************************************************************************************
 *	File Name				:	duLinkedList.h
 *	CopyRight				:	2020 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2020.3.28
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/

#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED

/**************************************************************
*	Macro Define Section
**************************************************************/

#define OVERFLOW -1

/**************************************************************
*	Struct Define Section
**************************************************************/

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct DuLNode {
	ElemType data;
	struct DuLNode* prior, * next;
} DuLNode, * DuLinkedList;

// define status
typedef enum Status {
	ERROR,
	SUCCESS,
} Status;


/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList* L);

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList* L);

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q);

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q);

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode* p, ElemType* e);

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e));

/**************************************************************
*	Additional Plus Functions
**************************************************************/

/**
 *  @name        : void menu(void)
 *	@description : 菜单
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
void menu(void);

/**
 *  @name        : int EnterInteger(void)
 *	@description : Enter an integer
 *	@param		 : Node
 *	@return		 : int
 *  @notice      : None
 */
int EnterInteger(void);

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : 创建一个新的链表
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
Status CreateduList(DuLinkedList* L);

/**
 *  @name        : Status printList_DuL(DuLinkedList L)
 *	@description : Outputs a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
Status printList_DuL(DuLinkedList L);

/**
 *  @name        : Status print(DuLinkedList L)
 *	@description : Outputs a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
Status print(DuLinkedList L);

/**
 *  @name        : Status InsertBefore(DuLinkedList *L)
 *	@description : insert node q before node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertBefore(DuLinkedList* L);

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertAfter(DuLinkedList* L);

/**
 *  @name        : SStatus Delete(DuLinkedList* p)
 *	@description : 删除节点 p 之后的第一个节点，并将其值分配给 e
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
Status Delete(DuLinkedList* L);

/**
 *  @name        : void visit(ElemType e)
 *	@description : print e
 *	@param		 : e
 *	@return		 : None
 *  @notice      : None
 */
void visitElem(ElemType e);

/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
