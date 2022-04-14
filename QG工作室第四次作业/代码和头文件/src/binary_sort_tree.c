#define _CRT_SECURE_NO_WARNINGS 1

#include "binary_sort_tree.h"
#include "stack.h"
#include "LQueue.h"
/**
 * BST ��ʼ��
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr bst)
{
	bst->root = NULL;
	return succeed;
}

/**
 * BST ����
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr bst, ElemType data)
{
	//��Ϊ��,�������½ڵ�
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
		if (bst->root->value > data)//С�ڲ����
		{
			BST_insert(&(bst->root->left), data);
		}
		else//���ڵ��ڲ��ұ�
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
		Deleteroot(Node, &((*NodeLeft)->right));//�ݹ�Ѱ�����ҵĽڵ�s,����������ֵ
	}
	else
	{
		(*Node)->value = (*NodeLeft)->value;//��ֵ���ݸ�Ҫɾ���Ľڵ�
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
	if (p->right == NULL)//p�ڵ�û��������
	{
		q = p;
		(*np) = p->left;//����ڵ��滻
		free(q);
		q = NULL;
	}
	else if (p->left == NULL)//p�ڵ�û��������
	{
		q = p;
		(*np) = p->right;
		free(q);
		q = NULL;
	}
	else//ͬʱ�������ҽڵ�
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
	if (bst == NULL)//����
		return failed;
	if (bst->root == NULL)
		return failed;
	else
	{
		if (bst->root->value < data)//Ѱ��Ҫɾ���Ľڵ�
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
	//�Ҳ����ڵ�
	if (bst->root == NULL)
	{
		return false;
	}
	//�ҵ��ڵ�
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
 * �ǵݹ�����
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
 * �ݹ�����
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
 * ����ǵݹ�
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
 * ����ǵݹ�
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
 * ����ǵݹ�
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
		if (p)//ָ�����µĽڵ�
		{
			pushLStack(&s, p);//��ջ
			p = p->left;//����
		}
		else
		{
			p = getTopLStack(&s);//��ȡջ��Ԫ��
			if (p->right && p->right != r)//�ж��ҽڵ��Ƿ����  ��ֹ�ظ�ָ���Һ���
			{
				p = p->right;
			}
			else
			{
				p = popLStack(&s);//��ջ
				visit(p);
				r = p;//���֮ǰ�Ľڵ�
				p = NULL;//pָ���, ��ֹ�ظ�ָ������
			}
		}
	} 

}

/**
 * ����ݹ�
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
 * ��α���
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(BinarySortTreePtr bst, void (*visit)(NodePtr))
{
	NodePtr p = bst->root;//���ڵ�
	LinkQueue q;
	InitQueue(&q);//��ʼ��
	if (p)
		EnQueue(&q, p);//������
	while (p && !QueueEmpty(q))
	{
		p = DeQueue(&q);//������
		visit(p);
		if (p->left)
		{
			EnQueue(&q, p->left);//������
		}
		if (p->right)
		{
			EnQueue(&q, p->right);//������
		}
	}
	return succeed;
}

//��������
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

//�����½ڵ�
void insert(BinarySortTreePtr bst)
{
	system("cls");	
	if (bst->root != NULL)
	{
		printf("�������: ");
		BST_inorderI(bst, visit);
		printf("\n");
	}
	printf("��������Ҫ����ڵ������: ");
	int data = EnterInteger();
	BST_insert(bst, data);
	printf("����ɹ�\n");
	printf("����������: ");
	BST_inorderI(bst, visit);
	printf("\n");
	system("pause");
}


void color(short x)/*�Զ��庯�����ݲ����ı���ɫ*/
{
	if (x >= 0 && x <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);/*�ı�������ɫ*/
	else/*Ĭ��Ϊ��ɫ*/
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

//�����������˵�
void SortTreeMenu(void)
{
	system("cls");
	printf("\n\n\n");
	color(14);//��ɫ
	printf("\t\t\t*********************************\n");
	color(2);//��ɫ
	printf("\t\t\t*");
	color(12);//��ɫ
	printf("           ���ܲ˵�           ");
	color(2);//��ɫ
	printf(" * \n");

	color(2);//��ɫ
	printf("\t\t\t*");
	color(10);//��ɫ
	printf("         1.");
	color(3);//��ɫ 
	printf(" �����½ڵ�        ");
	color(2);//��ɫ
	printf(" * \n");

	color(2);//��ɫ
	printf("\t\t\t*");
	color(10);//��ɫ
	printf("         2.");
	color(3);//����ɫ
	printf(" ɾ���ڵ�          ");
	color(2);//��ɫ
	printf(" * \n");

	color(2);//��ɫ
	printf("\t\t\t*");
	color(10);//��ɫ
	printf("         3.");
	color(3);//��ɫ 
	printf(" Ѱ������          ");
	color(2);//��ɫ
	printf(" * \n");

	color(2);//��ɫ
	printf("\t\t\t*");
	color(10);//��ɫ
	printf("         4.");
	color(3);//��ɫ 
	printf(" ����ǵݹ�        ");
	color(2);//��ɫ
	printf(" * \n");

	color(2);//��ɫ
	printf("\t\t\t*");
	color(10);//��ɫ
	printf("         5.");
	color(3);//��ɫ 
	printf(" ����ݹ�          ");
	color(2);//��ɫ
	printf(" * \n");

	color(2);//��ɫ
	printf("\t\t\t*");
	color(10);//��ɫ
	printf("         6.");
	color(3);//��ɫ 
	printf(" ����ǵݹ�        ");
	color(2);//��ɫ
	printf(" * \n");

	color(2);//��ɫ
	printf("\t\t\t*");
	color(10);//��ɫ
	printf("         7.");
	color(3);//��ɫ 
	printf(" ����ݹ�          ");
	color(2);//��ɫ
	printf(" * \n");

	color(2);//��ɫ
	printf("\t\t\t*");
	color(10);//��ɫ
	printf("         8.");
	color(3);//��ɫ 
	printf(" ����ǵݹ�        ");
	color(2);//��ɫ
	printf(" * \n");

	color(2);//��ɫ
	printf("\t\t\t*");
	color(10);//��ɫ
	printf("         9.");
	color(3);//��ɫ 
	printf(" ����ݹ�          ");
	color(2);//��ɫ
	printf(" * \n");

	color(2);//��ɫ
	printf("\t\t\t*");
	color(10);//��ɫ
	printf("         10.");
	color(3);//��ɫ 
	printf("��α���          ");
	color(2);//��ɫ
	printf(" * \n");

	color(2);//��ɫ
	printf("\t\t\t*");
	color(10);//��ɫ
	printf("         0.");
	color(3);//��ɫ
	printf(" ����              ");
	color(2);//��ɫ
	printf(" * \n");

	color(14);
	printf("\t\t\t*********************************\n");
	printf("\n");

	color(15);
	printf("��������Ҫ����Ĺ���");
	color(8);
	printf("[0~10] : ");
	color(15);//����ɫ
}

void delete(BinarySortTreePtr bst)
{
	system("cls");
	if (bst->root != NULL)
	{
		printf("�������: ");
		BST_inorderI(bst, visit);
		printf("\n");
	}
	printf("��������Ҫɾ��������");
	int data = EnterInteger();
	int flag = BST_delete(bst, data);
	if (flag == 1)
		printf("ɾ���ɹ�\n");
	else
		printf("�����ڸýڵ�\n");
	printf("ɾ��������ݣ� ");
	BST_inorderI(bst, visit);
	printf("\n");
	system("pause");
}

void find(BinarySortTreePtr bst)
{
	system("cls");
	if (bst->root != NULL)
	{
		printf("�������: ");
		BST_inorderI(bst, visit);
		printf("\n");
	}
	printf("��������ҪѰ�ҵ�����: ");
	int data = EnterInteger();
	int flag = BST_search(bst,data);
	if (flag == 1)
		printf("�ҵ��ýڵ�\n");
	else
		printf("�����ڸýڵ�\n");
	system("pause");
}


//���˵�
void mainMenu(void)
{
	system("cls");
	printf("\n\n\n");
	color(14);//��ɫ
	printf("\t\t\t*********************************\n");
	color(2);//��ɫ
	printf("\t\t\t*");
	color(12);//��ɫ
	printf("             ���˵�           ");
	color(2);//��ɫ
	printf(" * \n");

	color(2);//��ɫ
	printf("\t\t\t*");
	color(10);//��ɫ
	printf("         1.");
	color(3);//��ɫ 
	printf(" ����������        ");
	color(2);//��ɫ
	printf(" * \n");


	color(2);//��ɫ
	printf("\t\t\t*");
	color(10);//��ɫ
	printf("         2.");
	color(3);//��ɫ 
	printf(" ����ƽ����        ");
	color(2);//��ɫ
	printf(" * \n");



	color(2);//��ɫ
	printf("\t\t\t*");
	color(10);//��ɫ
	printf("         0.");
	color(3);//��ɫ
	printf(" �˳�ϵͳ          ");
	color(2);//��ɫ
	printf(" * \n");

	color(14);
	printf("\t\t\t*********************************\n");
	printf("\n");

	color(15);
	printf("��������Ҫ����Ĺ���");
	color(8);
	printf("[0~2] : ");
	color(15);//����ɫ

}

//����ƽ�����˵�
void AVLMenu(void)
{

	system("cls");
	printf("\n\n\n");
	color(14);//��ɫ
	printf("\t\t\t*********************************\n");
	color(2);//��ɫ
	printf("\t\t\t*");
	color(12);//��ɫ
	printf("          ����ƽ����          ");
	color(2);//��ɫ
	printf(" * \n");

	color(2);//��ɫ
	printf("\t\t\t*");
	color(10);//��ɫ
	printf("         1.");
	color(3);//��ɫ 
	printf(" �����½ڵ�        ");
	color(2);//��ɫ
	printf(" * \n");

	color(2);//��ɫ
	printf("\t\t\t*");
	color(10);//��ɫ
	printf("         2.");
	color(3);//��ɫ 
	printf(" ɾ���ڵ�          ");
	color(2);//��ɫ
	printf(" * \n");

	color(2);//��ɫ
	printf("\t\t\t*");
	color(10);//��ɫ
	printf("         3.");
	color(3);//��ɫ 
	printf(" �������          ");
	color(2);//��ɫ
	printf(" * \n");

	color(2);//��ɫ
	printf("\t\t\t*");
	color(10);//��ɫ
	printf("         4.");
	color(3);//��ɫ 
	printf(" �������          ");
	color(2);//��ɫ
	printf(" * \n");

	color(2);//��ɫ
	printf("\t\t\t*");
	color(10);//��ɫ
	printf("         5.");
	color(3);//��ɫ 
	printf(" �������          ");
	color(2);//��ɫ
	printf(" * \n");

	color(2);//��ɫ
	printf("\t\t\t*");
	color(10);//��ɫ
	printf("         0.");
	color(3);//��ɫ
	printf(" �˳�ϵͳ          ");
	color(2);//��ɫ
	printf(" * \n");

	color(14);
	printf("\t\t\t*********************************\n");
	printf("\n");

	color(15);
	printf("��������Ҫ����Ĺ���");
	color(8);
	printf("[0~5] : ");
	color(15);//����ɫ
}


