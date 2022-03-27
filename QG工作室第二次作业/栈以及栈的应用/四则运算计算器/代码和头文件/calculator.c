#define _CRT_SECURE_NO_WARNINGS 1
#include "calculator.h"

void* data[100];//存放数据
char  datatype[100];//存放数据类型
int datanum = 0;//数据位置
int datacount = 0;//数据的数量

//添加字符到数组中
void Addchar(char ch)
{
	datatype[datanum] = 'c';//存放类型
	data[datanum] = (char*)malloc(sizeof(char));//开辟空间
	if (data[datanum] == NULL)//开辟内存失败
	{
		printf("%s\n", strerror(errno));
		return;
	}
	memcpy(data[datanum], &ch, sizeof(char));
	datanum++;//位置+1
	datacount++;//数量+1
}


//添加小数到数组中
void Adddouble(double decimal)
{
	datatype[datanum] = 'd';//存放类型
	data[datanum] = (double*)malloc(sizeof(double));//开辟空间
	if (data[datanum] == NULL)//开辟内存失败
	{
		printf("%s\n", strerror(errno));
		return;
	}
	memcpy(data[datanum], &decimal, sizeof(double));
	datanum++;//位置+1
	datacount++;//数量+1
}

//打印数组中的内容
void print(void)
{
	int i = 0;
	char ch;//查看对应类型
	for (i = 0; i < datacount; i++)
	{
		ch = datatype[i];//获取类型
		switch (ch)
		{
		case 'c':
			color(15);
			printf("%c ", *((char*)data[i]));
			break;
		case 'd':
			color(14);
			printf("%.3lf ", *((double*)data[i]));
			break;
		}
	}
	printf("\n");
}




//中缀转后缀
Status InfixToSuffix(void)
{
	datanum = 0;//数组清零
	datacount = 0;//数量清零
	char ch;
	char chs;//用来读取[ 数字 或 '(' ]后的字符
	int chsflag = 0;//提前读取标志位，用来判断数字后面的是数字还是字符,用来'('后面字符的判断
	int decimalflag = 0;//小数点标志位,用于判断小数点后面的数
	int firstflag = 1;//第一次读取的标志位
	int negativeflag = 0;//用来判断是否是负数
	int nextflag = 0;//直接读取下一个字符标志位
	char temp;
	double num;//存放数字
	double decimal = 0;//存放小数点后的数
	CLinkStack S;//创建栈用来放元素符
	initCLStack(&S);//初始化S
	int flag = 1;//标志位：用来判断读取的是运算符还是数字,标志位为1时表数字，标志位为0时表字符
	do
	{
		num = 0;//数字清零
		decimal = 0;//小数点后的数清零
		if (firstflag)//第一次读取
		{
			scanf(" %c", &ch);//读取第一个非空字符
			if (ch == '-')//如果读到是-号
			{
				negativeflag = 1;//负数标志位置1
				nextflag = 1;//直接读取下一个字符标志位置1
			}
			else if (ch == '+')//如果读到是+号
			{
				negativeflag = 0;//负数标志位置0
				nextflag = 1;//直接读取下一个字符标志位置1
			}
			firstflag = 0;//第一次读取标志位置0
		}
		else//不是第一次读取
		{
			if (chsflag) //数字后面是运算符
			{
				ch = chs;//ch读取运算符
				chsflag = 0;//清零
			}
			else
			{
				while ((ch = getchar(), ch == ' ' || ch == '\t'));//读取除了'\n'的空字符
			}
		}
		if (nextflag)//第一次读取到的是+-号
		{
			while ((ch = getchar(), ch == ' ' || ch == '\t'));//读取除了'\n'的空字符
			nextflag = 0;
		}
		if ((ch == '(') || (ch == ')'))   //若运算符为 '(' 或 ')'  
			flag = 0;
		if (flag)    //存储数字
		{
			if ((ch >= '0') && (ch <= '9'))//输入的是数字
			{
				num = ch - '0';//赋值
				while (1)
				{
					chs = getchar();//读取数字后面的字符
					if ((chs >= '0') && (chs <= '9'))//数字后面的是数字
					{
						if (decimalflag == 0)//不是小数点后面的数
						{
							num *= 10;//增大十倍
							num += chs - '0';//读取个位数
						}
						else//是小数点后面的数 
						{
							//先放到整数部分，退出循环后，再把它缩小成小数
							decimal *= 10;//增大十倍
							decimal += chs - '0';//读取个位数
						}
					}
					else if (chs == '.')//数字后面是小数点
					{
						decimalflag = 1;
					}
					else if ((chs == ' ') || (chs == '\t'))//如果是空字符,跳出循环
					{
						break;
					}
					else//数字后面的其他字符,跳出循环
					{
						chsflag = 1;
						break;
					}
				}
				while (decimal >= 1.0)//将小数部分化成小数
				{
					decimal /= 10;
				}
				num += decimal;//把小数部分加上来
				if (negativeflag)//如果是负数
				{
					negativeflag = 0;//负数标志位置0
					num *= (-1);
				}
				if (num <= 10000.0 && num >= -10000.0)
				{
					Adddouble(num);//把小数放到数组中
				}
				else
				{
					printf("输入的数超过范围\n");
					return ERROR;
				}
			}
			else if(ch == '\n')//如果是换行符
			{
				chsflag = 1;
				chs = ch;
			}
			else//其他情况
			{
				printf("输入错误\n");
				return ERROR;
			}
			flag = 0;//标志位置0，数字后面是必定是运算符
		}
		else         //存储运算符
		{
			if (ch == '(') //'('后面一定是数字,（ 一定进栈
			{
				pushCLStack(&S, ch);//入栈
				while ((chs = getchar(), chs == ' ' || chs == '\t'));//读取除了'\n'的非空字符
				if (chs == '-')//左括号后面是-号
				{
					negativeflag = 1;//负数标志位置1
				}
				else if (chs == '+')//左括号后面是+号
				{
					negativeflag = 0;//负数标志位置0
				}
				else
				{
					chsflag = 1;//提前读取标志位置1
				}
			}
			else if (ch == ')')//')'后面一定是运算符, )   各元素出栈直到 (
			{
				if (isEmptyCLStack(&S))//栈为空，输入错误
				{
					printf("输入错误\n");
					return ERROR;
				}
				do//一直找到 (,同时将数据存放到数组中
				{
					popCLStack(&S, &temp);//栈顶出栈
					if (temp == '(')//找到 ( 退出循环
					{
						break;
					}
					if (isEmptyCLStack(&S))//栈为空，找不到 ( ,输入错误
					{
						printf("输入错误\n");
						return ERROR;
					}
					//此时栈中必定是运算符
					Addchar(temp);//添加运算符到数组中
				} while (temp != '(');
				flag = 0;//下一轮运算符
				continue;
			}
			else if ((ch == '*') || (ch == '/'))//*或/一定进栈
			{
				if (isEmptyCLStack(&S))//栈为空
				{
					pushCLStack(&S, ch);//入栈
				}
				else//不为空
				{
					getTopCLStack(&S, &temp);//获取栈顶元素
					if (temp == '(' || temp == '+' || temp == '-')//栈顶为 (或+或-，直接入栈
					{
						pushCLStack(&S, ch);
					}
					else//如果为*或/,栈顶出栈，并存放到数组中
					{
						popCLStack(&S, &temp);//栈顶出栈
						Addchar(temp);
						pushCLStack(&S, ch);//*或/入栈
					}
				}
			}
			else if ((ch == '+') || (ch == '-'))//+或-
			{
				if (isEmptyCLStack(&S))//栈为空，直接入栈
				{
					pushCLStack(&S, ch);
				}
				else//栈不为空
				{
					while (1)
					{
						getTopCLStack(&S, &temp);//获取栈顶元素
						if (temp == '(')//栈顶为：'(' 直接入栈
						{
							break;
						}
						else  //其他情况( + - * / )栈中的元素都要出栈
						{
							popCLStack(&S, &temp);//栈顶出栈
							Addchar(temp);//存放到数组中
						}
						if (isEmptyCLStack(&S))//元素出栈后,栈为空
						{
							break;
						}
					}
					pushCLStack(&S, ch);//入栈
				}
			}
			else if(ch == '\n')//如果是换行符
			{
				break;
			}
			else//其他情况输入错误
			{
				printf("输入错误\n");
				return ERROR;
			}
			flag = 1;//标志位置1，运算符后面必定是数字[除了")"]
		}
	} while (ch != '\n');//换行符为结束条件
	while (isEmptyCLStack(&S) == 0) //如果栈不为空
	{
		char popchar = 0;
		popCLStack(&S, &popchar);//出栈
		if (popchar == '(')
		{
			printf("输入错误\n");
			return ERROR;
		}
		Addchar(popchar);//添加字符到数组中
	}
	return SUCCESS;
}

//加法
double Add(double num1, double num2)
{
	return num1 + num2;
}

//减法
double Sub(double num1, double num2)
{
	return num1 - num2;
}

//乘法
double Mul(double num1, double num2)
{
	return num1 * num2;
}

//除法
double Div(double num1, double num2)
{
	return num1 / num2;
}

//计算
Status Cal(DLinkStack *D, double (*p)(double num1, double num2))
{
	double num1, num2;//存放运算数
	if (isEmptyDLStack(D))//判断是否为空
	{
		printf("输入错误\n");
		return ERROR;
	}
	popDLStack(D, &num2);//取出栈顶
	if (isEmptyDLStack(D))//判断是否为空
	{
		printf("输入错误\n");
		return ERROR;
	}
	popDLStack(D, &num1);
	if (p == Div)
	{
		if (num2 == 0)
		{
			printf("0不能除数\n");
			return ERROR;
		}
	}
	num1 = p(num1, num2);
	pushDLStack(D, num1);
	return SUCCESS;
}

//后缀表达式计算出结果
Status Calculation(DLinkStack* D)
{
	int i = 0;
	char type;//获取数据类型
	double num;//存放浮点数
	char ch;//存放运算符
	for (i = 0; i < datacount; i++)
	{
		type = datatype[i];
		switch (type)
		{
		case 'd': //数字
			num = *((double*)(data[i]));//转化为浮点数
			pushDLStack(D, num);//数字进栈
			break;
		case 'c': //运算符
			ch = *((char*)(data[i]));//转化为字符类型
			switch (ch)
			{
			case '+':
				if (!Cal(D, Add))
					return ERROR;
				break;
			case '-':
				if (!Cal(D, Sub))
					return ERROR;
				break;
			case '*':
				if (!Cal(D, Mul))
					return ERROR;
				break;
			case '/':
				if (!Cal(D, Div))
					return ERROR;
				break;
			}
			break;
		}
	}
	return SUCCESS;
}

//改变字体颜色
void color(int x)/*自定义函数根据参数改变颜色*/
{
	if (x >= 0 && x <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x | FOREGROUND_INTENSITY);/*改变字体颜色*/
	else/*默认为白色*/
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void SuffixCal(void)
{
	DLinkStack D;
	initDLStack(&D);//初始化
	double num;
	if (Calculation(&D))
	{
		if (isEmptyDLStack(&D))
		{
			printf("输入错误\n");
			return;
		}
		popDLStack(&D,&num);
		color(12);
		printf("\t\t计算结果是: ");
		color(1);
		printf("%.3lf ", num);
		color(8);
		printf("(结果保留3位小数)\n");
	}
}


//菜单
void menu(void)
{
		system("cls");
		printf("\n");
		printf("\n");
		printf("\n");
		color(6);//黄色
		printf("\t\t\t\t   ________________________\n");
		printf("\t\t\t\t  |                        |\n");
		printf("\t\t\t\t  | ");
		color(10);//绿色
		printf("四则计算器");
		color(6);
		printf("             | \n");
		printf("\t\t\t\t  |");
		color(3);//紫色
		printf("________________________");
		color(6);
		printf("|\n");

		printf("\t\t\t\t  |                        |\n");
		printf("\t\t\t\t  | ");
		color(15);//绿色
		printf(" +");
		color(9);
		printf("  加号");
		color(6);
		printf("               | \n");
		printf("\t\t\t\t  |");
		color(3);//紫色
		printf("________________________");
		color(6);
		printf("|\n");

		printf("\t\t\t\t  |                        |\n");
		printf("\t\t\t\t  | ");
		color(15);//绿色
		printf(" -");
		color(9);
		printf("  减号");
		color(6);
		printf("               | \n");
		printf("\t\t\t\t  |");
		color(3);//紫色
		printf("________________________");
		color(6);
		printf("|\n");

		printf("\t\t\t\t  |                        |\n");
		printf("\t\t\t\t  | ");
		color(15);//绿色
		printf(" *");
		color(9);
		printf("  乘号");
		color(6);
		printf("               | \n");
		printf("\t\t\t\t  |");
		color(3);//紫色
		printf("________________________");
		color(6);
		printf("|\n");

		printf("\t\t\t\t  |                        |\n");
		printf("\t\t\t\t  | ");
		color(15);//绿色
		printf(" /");
		color(9);
		printf("  除号");
		color(6);
		printf("               | \n");
		printf("\t\t\t\t  |");
		color(3);//紫色
		printf("________________________");
		color(6);
		printf("|\n");

		printf("\t\t\t\t  |                        |\n");
		printf("\t\t\t\t  | ");
		color(15);//绿色
		printf(" ( )");
		color(9);
		printf(" 括号");
		color(6);
		printf("              | \n");
		printf("\t\t\t\t  |");
		color(3);//紫色
		printf("________________________");
		color(6);
		printf("|\n");

		printf("\t\t\t\t  |                        |\n");
		printf("\t\t\t\t  |");
		color(15);//绿色
		printf("  输入法: ");
		color(0);
		printf(" 英文输入法");
		color(6);
		printf("   | \n");
		printf("\t\t\t\t  |");
		color(3);//紫色
		printf("________________________");
		color(6);
		printf("|\n");
		printf("\n");
		printf("\t\t\t请输入你想要运算的式子(数字范围[-10000.0~10000.0])\n");
		color(12);
		printf("\t\t   计算式:>>");
		color(3);
}
