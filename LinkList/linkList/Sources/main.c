#define _CRT_SECURE_NO_WARNINGS 1
#include "linkedList.h"
#include <stdio.h>

int main()
{
	system("color 0b");
	int input;
	LinkedList L;
	InitList(&L);
	void(*visit)(ElemType e) = visitElem;
	do
	{
		menu();
		printf("��ѡ��ģʽ[0~11]:>");
	Input:
		input = EnterInteger();
		switch (input)
		{
		case 0:
			break;
		case 1:
			CreateList(&L);
			break;
		case 2:
			Insert(&L);
			break;
		case 3:
			Delete(&L);
			break;
		case 4:
			TraverseList(L, visit);
			break;
		case 5:
			Search(L);
			break;
		case 6:
			FindMidNode(&L);
			break;
		case 7:
			IsLoopList(L);
			break;
		case 8:
			ReverseEvenList(&L);
			break;
		case 9:
			ReverseList(&L);
			break;
		case 10:
			ReverseRecLink(&L);
			break;
		case 11:
			DestroyList(&L);
			break;
		default:
			printf("�������,����������[0~11]:>");
			goto Input;
			break;
		}
	} while (input);
	printf("�˳��ɹ�\n");
	return 0;
}
