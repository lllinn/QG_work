#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkStack.h"


int main()
{
	LinkStack S;
	initLStack(&S);
	int input;
	do
	{
	Input:
		menu();
		printf("��ѡ��ģʽ[0~6]:>");
		input = Enter();
		switch (input)
		{
		case 0:
			break;
		case 1:
			Add(&S);
			break;
		case 2:
			Delete(&S);
			break;
		case 3:
			GetTop(&S);
			break;
		case 4:
			clearLStack(&S);
			break;
		case 5:
			GetLenghth(&S);
			break;
		case 6:
			print(&S);
			break;
		default:
			printf("�������,����������!\n");
			system("pause");
			goto Input;
			break;
		}
	} while (input);
	printf("�˳��ɹ�\n");
	return 0;
}