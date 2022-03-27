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
		printf("请选择模式[0~6]:>");
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
			printf("输入错误,请重新输入!\n");
			system("pause");
			goto Input;
			break;
		}
	} while (input);
	printf("退出成功\n");
	return 0;
}