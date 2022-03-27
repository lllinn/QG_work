#define _CRT_SECURE_NO_WARNINGS 1
#include "calculator.h"


int main()
{
	while (1)
	{
		menu();
		if (InfixToSuffix())
		{
			color(12);
			printf("\t\t后缀表达式: ");
			color(3);
			print();
			SuffixCal();
			system("pause");
		}
		else
		{
			char ch;
			while (ch = getchar(), ch != '\n');
			system("pause");
		}
	}	
	return 0;
}