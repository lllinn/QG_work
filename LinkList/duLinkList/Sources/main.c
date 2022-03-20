#define _CRT_SECURE_NO_WARNINGS 1
#include "duLinkedList.h"




int main()
{
	system("color 0b");
	int input;
	DuLinkedList L;
	InitList_DuL(&L);
	void(*visit)(ElemType e) = visitElem;
	do
	{
		menu();
		printf("请选择模式[0~6]:>");
	Input:
		input = EnterInteger();
		switch (input)
		{
		case 0:
			break;
		case 1:
			CreateduList(&L);
			break;
		case 2:
			InsertBefore(&L);
			break;
		case 3:
			InsertAfter(&L);
			break;
		case 4:
			Delete(&L);
			break;
		case 5:
			TraverseList_DuL(L, visit);
			break;
		case 6:
			DestroyList_DuL(&L);
			break;
		default:
			printf("输入错误,请重新输入[0~6]:>");
			goto Input;
			break;
		}
	} while (input);
	printf("退出系统成功\n");
	return 0;
}


