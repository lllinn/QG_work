#define _CRT_SECURE_NO_WARNINGS 1

#include "binary_sort_tree.h"
#include "stack.h"
#include "LQueue.h"
/**
 * BST 初始化
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr bst)
{
	bst->root = NULL;
	return succeed;
}

/**
 * BST 插入
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr bst, ElemType data)
{
	//若为空,创建新新节点
	if (bst->root == NULL)
	{
		bst->root = (NodePtr)malloc(sizeof(Node));
		if (bst->root == NULL)
		{
			printf("%s\n", strerror(errno));
			return failed;
		}
		bst->root->left = NULL;
		bst->root->right = NULL;
		bst->root->value = data;
		return succeed;
	}
	else
	{
		if (bst->root->value > data)//小于插左边
		{
			BST_insert(&(bst->root->left), data);
		}
		else//大于等于插右边
		{
			BST_insert(&(bst->root->right), data);
		}
	}
	return succeed;
}

void Deleteroot(NodePtr *Node, NodePtr *NodeLeft)
{
	NodePtr p;
	if ((*NodeLeft)->right != NULL)
	{
		Deleteroot(Node, &((*NodeLeft)->right));//递归寻找最右的节点s,左子树最大的值
	}
	else
	{
		(*Node)->value = (*NodeLeft)->value;//将值传递给要删除的节点
		p = (*NodeLeft);
		(*NodeLeft) = (*NodeLeft)->left;
		free(p);
		p = NULL;
	}
}

void Delete(NodePtr* np)
{
	NodePtr q;
	NodePtr p = *np;
	if (p->right == NULL)//p节点没有右子树
	{
		q = p;
		(*np) = p->left;//用左节点替换
		free(q);
		q = NULL;
	}
	else if (p->left == NULL)//p节点没有左子树
	{
		q = p;
		(*np) = p->right;
		free(q);
		q = NULL;
	}
	else//同时存在左右节点
	{
		Deleteroot(np, &(p->left));
	}
}
/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(BinarySortTreePtr bst, ElemType data)
{
	if (bst == NULL)//空树
		return failed;
	if (bst->root == NULL)
		return failed;
	else
	{
		if (bst->root->value < data)//寻找要删除的节点
			return BST_delete(&(bst->root->right), data);
		else if (bst->root->value > data)
			return BST_delete(&(bst->root->left), data);
		else
		{
			Delete(&(bst->root));
			return succeed;
		}
	}


}

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(BinarySortTreePtr bst, ElemType data)
{
	//找不到节点
	if (bst->root == NULL)
	{
		return false;
	}
	//找到节点
   	if (data == bst->root->value)
	{
		return true;
	}
	else if (data < bst->root->value)
	{
		BST_search(&(bst->root->left), data);
	}
	else
	{
		BST_search(&(bst->root->right), data);
	}
	return succeed;
}

/**
 * printf data
 * @param NodePtr  data
 */
void visit(NodePtr data)
{
	printf("%d ", data->value);
}

/**
 * 非递归先序
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(BinarySortTreePtr bst, void (*visit)(NodePtr))
{
	LinkStack s;
	initLStack(&s);
	NodePtr p = bst->root;
	pushLStack(&s, p);
	while (!isEmptyLStack(&s))
	{
		p = popLStack(&s);
		visit(p);
		if (p->right)
		{
			pushLStack(&s, p->right);
		}
		if (p->left)
		{
			pushLStack(&s, p->left);
		}
	}
	destroyLStack(&s);
	return succeed;
}

/**
 * 递归先序
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(BinarySortTreePtr bst, void (*visit)(NodePtr))
{
	if (bst == NULL)
		return succeed;
	if (bst->root == NULL)
		return succeed;
	visit(bst->root);
	BST_preorderR(&(bst->root->left), visit);
	BST_preorderR(&(bst->root->right), visit);
	return succeed;
}

/**
 * 中序非递归
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(BinarySortTreePtr bst, void (*visit)(NodePtr))
{
	LinkStack s;
	initLStack(&s);
	NodePtr p = bst->root, ptemp = bst->root;
	while (p || !isEmptyLStack(&s))
	{
		if (p)
		{
			pushLStack(&s, p);
			p = p->left;
		}
		else
		{
			p = popLStack(&s);
			visit(p);
			p = p->right;
		}
	}
	destroyLStack(&s);
	return succeed;
}

/**
 * 中序非递归
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(BinarySortTreePtr bst, void (*visit)(NodePtr))
{
	if (bst == NULL)
		return succeed;
	if (bst->root == NULL)
		return succeed;
	BST_inorderR(&(bst->root->left), visit);
	visit(bst->root);
	BST_inorderR(&(bst->root->right), visit);
	return succeed;
}


/**
 * 后序非递归
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(BinarySortTreePtr bst, void (*visit)(NodePtr))
{
	LinkStack s;
	initLStack(&s);
	NodePtr p = bst->root, r = NULL;
	while (p || !isEmptyLStack(&s))
	{
		if (p)//指向最下的节点
		{
			pushLStack(&s, p);//入栈
			p = p->left;//左孩子
		}
		else
		{
			p = getTopLStack(&s);//获取栈顶元素
			if (p->right && p->right != r)//判断右节点是否存在  防止重复指向右孩子
			{
				p = p->right;
			}
			else
			{
				p = popLStack(&s);//出栈
				visit(p);
				r = p;//存放之前的节点
				p = NULL;//p指向空, 防止重复指向左孩子
			}
		}
	} 

}

/**
 * 后序递归
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(BinarySortTreePtr bst, void (*visit)(NodePtr))
{
	if (bst == NULL)
		return succeed;
	if (bst->root == NULL)
		return succeed;
	BST_postorderR(&(bst->root->left), visit);
	BST_postorderR(&(bst->root->right), visit);
	visit(bst->root);
	return succeed;
}


/**
 * 层次遍历
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(BinarySortTreePtr bst, void (*visit)(NodePtr))
{
	NodePtr p = bst->root;//根节点
	LinkQueue q;
	InitQueue(&q);//初始化
	if (p)
		EnQueue(&q, p);//进队列
	while (p && !QueueEmpty(q))
	{
		p = DeQueue(&q);//出队列
		visit(p);
		if (p->left)
		{
			EnQueue(&q, p->left);//进队列
		}
		if (p->right)
		{
			EnQueue(&q, p->right);//进队列
		}
	}
	return succeed;
}

//输入整数
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

//加如新节点
void insert(BinarySortTreePtr bst)
{
	system("cls");	
	if (bst->root != NULL)
	{
		printf("中序遍历: ");
		BST_inorderI(bst, visit);
		printf("\n");
	}
	printf("请输入想要插入节点的数据: ");
	int data = EnterInteger();
	BST_insert(bst, data);
	printf("插入成功\n");
	printf("插入后的数据: ");
	BST_inorderI(bst, visit);
	printf("\n");
	system("pause");
}


void color(short x)/*自定义函数根据参数改变颜色*/
{
	if (x >= 0 && x <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);/*改变字体颜色*/
	else/*默认为白色*/
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

//二叉排序树菜单
void SortTreeMenu(void)
{
	system("cls");
	printf("\n\n\n");
	color(14);//黄色
	printf("\t\t\t*********************************\n");
	color(2);//绿色
	printf("\t\t\t*");
	color(12);//红色
	printf("           功能菜单           ");
	color(2);//黄色
	printf(" * \n");

	color(2);//黄色
	printf("\t\t\t*");
	color(10);//红色
	printf("         1.");
	color(3);//蓝色 
	printf(" 插入新节点        ");
	color(2);//黄色
	printf(" * \n");

	color(2);//黄色
	printf("\t\t\t*");
	color(10);//红色
	printf("         2.");
	color(3);//淡绿色
	printf(" 删除节点          ");
	color(2);//黄色
	printf(" * \n");

	color(2);//黄色
	printf("\t\t\t*");
	color(10);//红色
	printf("         3.");
	color(3);//蓝色 
	printf(" 寻找数据          ");
	color(2);//黄色
	printf(" * \n");

	color(2);//黄色
	printf("\t\t\t*");
	color(10);//红色
	printf("         4.");
	color(3);//蓝色 
	printf(" 先序非递归        ");
	color(2);//黄色
	printf(" * \n");

	color(2);//黄色
	printf("\t\t\t*");
	color(10);//红色
	printf("         5.");
	color(3);//蓝色 
	printf(" 先序递归          ");
	color(2);//黄色
	printf(" * \n");

	color(2);//黄色
	printf("\t\t\t*");
	color(10);//红色
	printf("         6.");
	color(3);//蓝色 
	printf(" 中序非递归        ");
	color(2);//黄色
	printf(" * \n");

	color(2);//黄色
	printf("\t\t\t*");
	color(10);//红色
	printf("         7.");
	color(3);//蓝色 
	printf(" 中序递归          ");
	color(2);//黄色
	printf(" * \n");

	color(2);//黄色
	printf("\t\t\t*");
	color(10);//红色
	printf("         8.");
	color(3);//蓝色 
	printf(" 后序非递归        ");
	color(2);//黄色
	printf(" * \n");

	color(2);//黄色
	printf("\t\t\t*");
	color(10);//红色
	printf("         9.");
	color(3);//蓝色 
	printf(" 后序递归          ");
	color(2);//黄色
	printf(" * \n");

	color(2);//黄色
	printf("\t\t\t*");
	color(10);//红色
	printf("         10.");
	color(3);//蓝色 
	printf("层次遍历          ");
	color(2);//黄色
	printf(" * \n");

	color(2);//黄色
	printf("\t\t\t*");
	color(10);//红色
	printf("         0.");
	color(3);//蓝色
	printf(" 返回              ");
	color(2);//黄色
	printf(" * \n");

	color(14);
	printf("\t\t\t*********************************\n");
	printf("\n");

	color(15);
	printf("请输入想要输入的功能");
	color(8);
	printf("[0~10] : ");
	color(15);//淡绿色
}

void delete(BinarySortTreePtr bst)
{
	system("cls");
	if (bst->root != NULL)
	{
		printf("中序遍历: ");
		BST_inorderI(bst, visit);
		printf("\n");
	}
	printf("请输入你要删除的数据");
	int data = EnterInteger();
	int flag = BST_delete(bst, data);
	if (flag == 1)
		printf("删除成功\n");
	else
		printf("不存在该节点\n");
	printf("删除后的数据： ");
	BST_inorderI(bst, visit);
	printf("\n");
	system("pause");
}

void find(BinarySortTreePtr bst)
{
	system("cls");
	if (bst->root != NULL)
	{
		printf("中序遍历: ");
		BST_inorderI(bst, visit);
		printf("\n");
	}
	printf("请输入你要寻找的数据: ");
	int data = EnterInteger();
	int flag = BST_search(bst,data);
	if (flag == 1)
		printf("找到该节点\n");
	else
		printf("不存在该节点\n");
	system("pause");
}


//主菜单
void mainMenu(void)
{
	system("cls");
	printf("\n\n\n");
	color(14);//黄色
	printf("\t\t\t*********************************\n");
	color(2);//绿色
	printf("\t\t\t*");
	color(12);//红色
	printf("             主菜单           ");
	color(2);//黄色
	printf(" * \n");

	color(2);//黄色
	printf("\t\t\t*");
	color(10);//红色
	printf("         1.");
	color(3);//蓝色 
	printf(" 二叉排序树        ");
	color(2);//黄色
	printf(" * \n");


	color(2);//黄色
	printf("\t\t\t*");
	color(10);//红色
	printf("         2.");
	color(3);//蓝色 
	printf(" 二叉平衡树        ");
	color(2);//黄色
	printf(" * \n");



	color(2);//黄色
	printf("\t\t\t*");
	color(10);//红色
	printf("         0.");
	color(3);//蓝色
	printf(" 退出系统          ");
	color(2);//黄色
	printf(" * \n");

	color(14);
	printf("\t\t\t*********************************\n");
	printf("\n");

	color(15);
	printf("请输入想要输入的功能");
	color(8);
	printf("[0~2] : ");
	color(15);//淡绿色

}

//二叉平衡树菜单
void AVLMenu(void)
{

	system("cls");
	printf("\n\n\n");
	color(14);//黄色
	printf("\t\t\t*********************************\n");
	color(2);//绿色
	printf("\t\t\t*");
	color(12);//红色
	printf("          二叉平衡树          ");
	color(2);//黄色
	printf(" * \n");

	color(2);//黄色
	printf("\t\t\t*");
	color(10);//红色
	printf("         1.");
	color(3);//蓝色 
	printf(" 插入新节点        ");
	color(2);//黄色
	printf(" * \n");

	color(2);//黄色
	printf("\t\t\t*");
	color(10);//红色
	printf("         2.");
	color(3);//蓝色 
	printf(" 删除节点          ");
	color(2);//黄色
	printf(" * \n");

	color(2);//黄色
	printf("\t\t\t*");
	color(10);//红色
	printf("         3.");
	color(3);//蓝色 
	printf(" 先序遍历          ");
	color(2);//黄色
	printf(" * \n");

	color(2);//黄色
	printf("\t\t\t*");
	color(10);//红色
	printf("         4.");
	color(3);//蓝色 
	printf(" 中序遍历          ");
	color(2);//黄色
	printf(" * \n");

	color(2);//黄色
	printf("\t\t\t*");
	color(10);//红色
	printf("         5.");
	color(3);//蓝色 
	printf(" 后序遍历          ");
	color(2);//黄色
	printf(" * \n");

	color(2);//黄色
	printf("\t\t\t*");
	color(10);//红色
	printf("         0.");
	color(3);//蓝色
	printf(" 退出系统          ");
	color(2);//黄色
	printf(" * \n");

	color(14);
	printf("\t\t\t*********************************\n");
	printf("\n");

	color(15);
	printf("请输入想要输入的功能");
	color(8);
	printf("[0~5] : ");
	color(15);//淡绿色
}


