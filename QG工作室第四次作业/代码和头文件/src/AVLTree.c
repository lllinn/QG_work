#define _CRT_SECURE_NO_WARNINGS 1
#include "AVLTree.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief 以p为根进行右旋操作
 *
 * @param p 
 */
void R_Rotate(BiTree* p)
{
	BiTree l = (*p)->left;//左孩子
	(*p)->left = l->right;//l的右孩子作为p的左孩子
	l->right = (*p);//l的右孩子指向p
	(*p) = l;//改变根节点位置
}

/**
 * @brief 以p为根进行左旋操作
 *
 * @param p
 */
void L_Rotate(BiTree* p)
{
	BiTree r = (*p)->right;//右孩子
	(*p)->right = r->left;// l的左孩子作为p的右孩子
	r->left = (*p);//l的左孩子指向p
	(*p) = r;//改变根节点位置
}

/*
* @brief 左平衡树,以bt为根节点进行左平衡
* 
* @patam bt
*/
void LeftBalance(BiTree* bt)
{
	BiTree lchild = (*bt)->left;//左孩子
	switch (lchild->bf)//判断左孩子的平衡情况
	{
	case 1://左左
		lchild->bf = 0;//平衡因子变为0
		(*bt)->bf = 0;
		R_Rotate(bt);//右旋
		break;
	case -1://左右
		BiTree lrchild = lchild->right;//左孩子的右孩子 
		switch (lrchild->bf)//判断平衡因子
		{
		case 0://不存在左右孩子
			(*bt)->bf = 0;
			lchild->bf = 0;
			break;
		case 1://存在一个左孩子
			(*bt)->bf = -1;
			lrchild->bf = 0;
			lchild->bf = 0;
			break;
		case -1:
			(*bt)->bf = 0;
			lchild->bf = 1;
			lrchild->bf = 0;
			break;
		}
		L_Rotate(&lchild);//先左旋
		R_Rotate(bt);//再右旋
		break;
	}
}

/*
* @brief 右平衡树,以bt为根节点进行右s平衡
*
* @patam bt
*/
void RightBalance(BiTree* bt)
{
	BiTree rchild = (*bt)->right;//右孩子
	switch (rchild->bf)//判断左孩子的平衡情况
	{
	case -1://右右
		rchild->bf = 0;//平衡因子变为0
		(*bt)->bf = 0;
		L_Rotate(bt);//左旋
		break;
	case 1://右左
		BiTree rlchild = rchild->left;//右孩子的左孩子 
		switch (rlchild->bf)//判断平衡因子
		{
		case 0://不存在左右孩子
			(*bt)->bf = 0;
			rchild->bf = 0;
			break;
		case -1://存在一个左孩子
			(*bt)->bf = 1;
			rlchild->bf = 0;
			rchild->bf = 0;
			break;
		case 1:
			(*bt)->bf = 0;
			rchild->bf = -1;
			rlchild->bf = 0;
			break;
		}
		R_Rotate(&rchild);//先右旋
		L_Rotate(bt);//再左旋
		break;
	}
}


/**
 * @brief 插入新节点, 同时平衡树
 *
 * @param p  根节点
 * @param data 插入的数据
 * @param flag 判断是否增高  1表增高1层  0表未增加层数
 */
Status InsertAVL(BiTree* bt, BiTElemType data, int *flag)
{
	if ((*bt) == NULL)
	{
		BiTree Node = (BiTree)malloc(sizeof(BiTNode));
		if (Node == NULL)
		{
			printf("%s\n", strerror(errno));
			return FALSE;
		}
		Node->bf = 0;
		Node->left = Node->right = NULL;
		Node->value = data;
		(*bt) = Node;
		*flag = 1;//增高一层
	}
	else if ((*bt)->value <= data)  //data值大于或等于把,往右插
	{
		if(!InsertAVL(&(*bt)->right, data, flag))
			return FALSE;
		if (*flag)//右子树增高一层
		{
			switch ((*bt)->bf)
			{
			case 0:
				(*bt)->bf = -1;//右树增高,影响上层树的结构
				*flag = 1;
				break;
			case 1:
				(*bt)->bf = 0;
				*flag = 0;
				break;
			case -1:
				RightBalance(bt);//右平衡
				*flag = 0;
				break;
			}
			
		}
	}
	else
	{
		if (!InsertAVL(&(*bt)->left, data, flag))
			return FALSE;
		if (*flag)//左子树增高一层
		{
			switch ((*bt)->bf)
			{
			case 0:
				(*bt)->bf = 1;//左树增高一层，影响上层结构
				*flag = 1;
				break;
			case 1:
				LeftBalance(bt);
				*flag = 0;
				break;
			case -1:
				(*bt)->bf = 0;
				*flag = 0;
				break;
			}
			
		}
	}
}

/**
 * @brief 删除节点, 同时平衡树
 *
 * @param p  根节点
 * @param data 删除数据
 * @param flag 判断是否变矮  1表变矮1层  0表未层数
 */
Status deleteAVL(BiTree* bt, BiTElemType data, int* flag)
{

	if (!*bt)
		return FALSE;
	BiTree q = NULL;
	if (data == (*bt)->value)
	{
		if (NULL == (*bt)->left)
		{ // 左⼦树为空，直接连接右节点
			q = (*bt);
			(*bt) = q->right;
			free(q);
			q = NULL;
			*flag = 1;
		}
		else if (NULL == (*bt)->right)
		{ // 右⼦树为空，直接连接左节点
			q = (*bt);
			(*bt) = q->left;
			free(q);
			q = NULL;
			*flag = 1;
		}
		else 
		{
			q = (*bt)->left;
			while (q->right)
			{
				q = q->right;
			}
			(*bt)->value = q->value;
			deleteAVL(&(*bt)->left, q->value, flag); // 在左⼦树中递归删除前驱节点 
		}
	}
	else if (data < (*bt)->value)
	{
		if (!deleteAVL(&(*bt)->left, data, flag))
		{
			return FALSE;
		}
		if (*flag)
		{
			switch ((*bt)->bf)
			{
			case 1:
				(*bt)->bf = 0;
				*flag = 1;
				break;
			case 0:
				(*bt)->bf = -1;
				*flag = 0;
				break;
			case -1:
				LeftBalance(bt);
				if (0 == (*bt)->right->bf)
				{
					*flag = 0;
				}
				else
				{
					*flag = 1;
				}
				break;
			}
		}
	}
	else
	{
		if (!deleteAVL(&(*bt)->right, data, flag))
		{
			return FALSE;
		}
		if (*flag)
		{
			switch ((*bt)->bf)
			{
			case -1:
				(*bt)->bf = 0;
				*flag = 1;
				break;
			case 0:
				(*bt)->bf = 1;
				*flag = 0;
				break;
			case 1:
				RightBalance(bt);
				if (0 == (*bt)->left->bf)
				{
					*flag = 0;
				}
				else
				{
					*flag = 1;
				}
				break;
			}
		}
	}
	return SUCCESS;
}


//先序遍历
Status AVL_preorderR(BiTree* bt)
{
	if (bt == NULL)
		return FALSE;
	if ((*bt) == NULL)
		return FALSE;
	printf("%d ", (*bt)->value);
	AVL_preorderR(&((*bt)->left));
	AVL_preorderR(&((*bt)->right));
}

//中序遍历
Status AVL_inorderR(BiTree* bt)
{
	if (bt == NULL)
		return FALSE;
	if ((*bt) == NULL)
		return FALSE;
	AVL_preorderR(&((*bt)->left));
	printf("%d ", (*bt)->value);
	AVL_preorderR(&((*bt)->right));
}

//后序遍历
Status AVL_postorderR(BiTree* bt)
{
	if (bt == NULL)
		return FALSE;
	if ((*bt) == NULL)
		return FALSE;
	AVL_preorderR(&((*bt)->left));
	AVL_preorderR(&((*bt)->right));
	printf("%d ", (*bt)->value);
}

//输入整数
int AVLEnterInteger(void)
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


void AVLdelete(BiTree* bt)
{
	system("cls");
	if ((*bt) != NULL)
	{
		printf("中序遍历: ");
		AVL_inorderR(bt);
		printf("\n");
	}
	int avlflag = 0;
	printf("请输入你要删除的数据: ");
	int data = AVLEnterInteger();
	int flag = deleteAVL(bt, data, &avlflag);
	if (flag == 1)
		printf("删除成功\n");
	else
		printf("不存在该节点\n");
	printf("删除后的数据： ");
	AVL_inorderR(bt);
	printf("\n");
	system("pause");
}

//加如新节点
void AVLinsert(BiTree *bt)
{
	system("cls");
	if ((*bt) != NULL)
	{
		printf("中序遍历: ");
		AVL_inorderR(bt);
		printf("\n");
	}
	printf("请输入想要插入节点的数据: ");
	int data = AVLEnterInteger();
	int flag = 0;
	InsertAVL(bt, data, &flag);
	printf("插入成功\n");
	printf("插入后的数据: ");
	AVL_inorderR(bt);
	printf("\n");
	system("pause");
}
