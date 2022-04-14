#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "binary_sort_tree.h"
#include "AVLTree.h"


int main() 
{
	BiTree bt = NULL;
	int flag;
    BinarySortTree bst; 
    BST_init(&bst);
    int input = 0;
	int bstinput = 0;
	int AVLinput = 0;
	do
	{
	Input:
		mainMenu();
		input = EnterInteger();
		switch (input)
		{
		case 0:
			break;
		case 1:
			do
			{
			bstInput:
			SortTreeMenu();
			bstinput = EnterInteger();
			switch (bstinput)
			{
			case 0:
				break;
			case 1:
				insert(&bst);
				break;
			case 2:
				delete(&bst);
				break;
			case 3:
				find(&bst);
				break;
			case 4:
				system("cls");
				BST_preorderI(&bst, visit);
				printf("\n");
				system("pause");
				break;
			case 5:
				system("cls");
				BST_preorderR(&bst, visit);
				printf("\n");
				system("pause");
				break;
			case 6:
				system("cls");
				BST_inorderI(&bst, visit);
				printf("\n");
				system("pause");
				break;
			case 7:
				system("cls");
				BST_inorderR(&bst, visit);
				printf("\n");
				system("pause");
				break;
			case 8:
				system("cls");
				BST_postorderI(&bst, visit);
				printf("\n");
				system("pause");
				break;
			case 9:
				system("cls");
				BST_postorderR(&bst, visit);
				printf("\n");
				system("pause");
				break;
			case 10:
				system("cls");
				BST_levelOrder(&bst, visit);
				printf("\n");
				system("pause");
				break;
			default:
				printf("输入错误,请重新输入[0~10]\n");
				system("pause");
				goto bstInput;
				break;
			}
		} while (bstinput);
			break;
		case 2:
			do
			{
			AVLInput:
				AVLMenu();
				AVLinput = EnterInteger();
				switch (AVLinput)
				{
				case 0:
					break;
				case 1:
					AVLinsert(&bt);
					break;
				case 2:
					AVLdelete(&bt);
					break;
				case 3:
					system("cls");
					AVL_preorderR(&bt);
					printf("\n");
					system("pause");
					break;
				case 4:
					system("cls");
					AVL_inorderR(&bt);
					printf("\n");
					system("pause");
					break;
				case 5:
					system("cls");
					AVL_postorderR(&bt);
					printf("\n");
					system("pause");
					break;
				default:
					printf("输入错误,请重新输入[0~5]\n");
					system("pause");
					goto AVLInput;
					break;
				}


			} while (AVLinput);
			break;
		default:
			printf("输入错误,请重新输入[0~2]\n");
			system("pause");
			goto Input;
			break;
		}
	} while (input);
	printf("退出成功\n");
	return 0;

}
