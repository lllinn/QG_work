#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkStack.h"

//初始化栈
Status initLStack(LinkStack* s)
{
	s->top = NULL;//指向空指针
	s->count = 0;//初始化数值
	return SUCCESS;
}

//判断栈是否为空
//返回0 表栈不为空
//返回1 表栈为空
Status isEmptyLStack(LinkStack* s)
{
	if (s->count)  //栈不为空
		return 0;
	else          //栈为空
		return 1;
}

//得到栈顶元素
Status getTopLStack(LinkStack* s, ElemType* e)
{
	if (isEmptyLStack(s))  //栈为空
	{
		printf("未创建栈\n");
		return ERROR;
	}
	*e = s->top->data;  //将数据传给e
	return SUCCESS;
}


//清空栈
Status clearLStack(LinkStack* s)
{
	system("cls");
	LinkStackPtr p, q;
	p = s->top;  //指向栈顶
	while (p)
	{
		q = p->next; //指向下一个结点
		free(p);
		p = q;
	} 
	s->top = NULL;  //指向空指针
	s->count = 0;   //清空计数
	printf("清除成功\n");
	system("pause");
	return SUCCESS;
}

//销毁栈
Status destroyLStack(LinkStack* s)
{
	if (isEmptyLStack(s))  //栈为空
	{
		printf("未创建栈\n");
		return ERROR;
	}
	LinkStackPtr p, q;
	p = s->top;  //指向栈顶
	while (p)
	{
		q = p->next; //指向下一个结点
		free(p);
		p = q;
	}
	s->top = NULL;  //指向空指针
	s->count = 0;   //清空计数
	return SUCCESS;
}

//检测栈长度
Status LStackLength(LinkStack* s, int* length)
{
	*length = s->count;//传递个数
	return SUCCESS;
}

//入栈
Status pushLStack(LinkStack* s, ElemType data)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode)); //开辟一个新的空间
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
		return ERROR;
	}
	p->next = s->top; //p的next指向栈顶
	p->data = data;   //获取数据
	s->top = p;       //p改为栈顶
	s->count++;       //数量加1
	return SUCCESS;
}

//出栈
Status popLStack(LinkStack* s, ElemType* data)
{
	if (isEmptyLStack(s))  //栈为空
	{
		printf("未创建栈\n");
		return ERROR;
	}
	LinkStackPtr p = s->top; //p指向栈顶
	*data = s->top->data;    //获取数据
	s->top = s->top->next;   //栈顶指向下一个结点
	s->count--;              //数量减1
	free(p);                 //释放空间
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

//菜单
void menu(void)
{
	system("cls");
	printf("\n");
	printf("\n");
	printf("\n");
	color(6);//黄色
	printf("\t\t\t\t   __________________________________________\n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  |              ");
	color(4);//红色
	printf("栈系统功能菜单              "); 
	color(6);//黄色
	printf("|\n");
	printf("\t\t\t\t  |");
	color(3);//紫色
	printf("__________________________________________");
	color(6);
    printf("| \n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | ");
	color(10);//绿色
	printf("            1. ");
	color(1);//蓝色
	printf("添加一个新元素");
	color(6);
	printf("            | \n");
	printf("\t\t\t\t  |");
	color(3);//紫色
	printf("__________________________________________");
	color(6);//黄色
	printf("| \n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | ");
	color(10);//绿色
	printf("            2. ");
	color(1);//蓝色
	printf("删除一个元素");
	color(6);
	printf("              | \n");
	printf("\t\t\t\t  |");
	color(3);//紫色
	printf("__________________________________________");
	color(6);//黄色
	printf("| \n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | ");
	color(10);//绿色
	printf("            3. ");
	color(1);//蓝色
	printf("栈顶元素");
	color(6);
	printf("                  | \n");
	printf("\t\t\t\t  |");
	color(3);//紫色
	printf("__________________________________________");
	color(6);//黄色
	printf("| \n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | ");
	color(10);//绿色
	printf("            4. ");
	color(1);//蓝色
	printf("清空栈");
	color(6);
	printf("                    | \n");
	printf("\t\t\t\t  |");
	color(3);//紫色
	printf("__________________________________________");
	color(6);//黄色
	printf("| \n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | ");
	color(10);//绿色
	printf("            5. ");
	color(1);//蓝色
	printf("栈的长度");
	color(6);
	printf("                  | \n");
	printf("\t\t\t\t  |");
	color(3);//紫色
	printf("__________________________________________");
	color(6);//黄色
	printf("| \n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | ");
	color(10);//绿色
	printf("            6. ");
	color(1);//蓝色
	printf("遍历栈");
	color(6);
	printf("                    | \n");
	printf("\t\t\t\t  |");
	color(3);//紫色
	printf("__________________________________________");
	color(6);//黄色
	printf("| \n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | ");
	color(10);//绿色
	printf("            0. ");
	color(1);//蓝色
	printf("退出系统");
	color(6);
	printf("                  | \n");
	printf("\t\t\t\t  |");
	color(6);//紫色
	printf("__________________________________________");
	color(6);//黄色
	printf("| \n");
	printf("\n");

	printf("请输入你要选择的功能:");

}

//输入整数
int EnterInteger(void)
{
	int NodeNum = 0;
	char ch;
	//while ((!scanf("%d", &NodeNum)) || (getchar() != '\n'))  /*输入的数不为整数*/
	while ((!scanf("%d", &NodeNum)) || (NodeNum < 0 || NodeNum > 10000) ||(ch = getchar(), ((ch != '\n') && (ch != '\t') && (ch != ' '))))  /*输入的数不为整数*/
	{
		printf("输入错误,请重新输入正确的数据\n");
		while (getchar() != '\n');  /*将缓冲区的数读走*/
	}
	return NodeNum;
}

//输入一个整数
int Enter(void)
{
	int NodeNum = 0;
	char ch;
	//while ((!scanf("%d", &NodeNum)) || (getchar() != '\n'))  /*输入的数不为整数*/
	while ((!scanf("%d", &NodeNum)) || (ch = getchar(), ((ch != '\n') && (ch != '\t') && (ch != ' '))))  /*输入的数不为整数*/
	{
		while (getchar() != '\n');  /*将缓冲区的数读走*/
		return -1;
	}
	return NodeNum;
}

//打印栈
Status printStack(LinkStack* s)
{
	LinkStackPtr p = s->top;
	while (p)  //p不为空
	{
		printf("%d->",p->data);
		p = p->next;
	}
	printf("NULL\n");
	return SUCCESS;
}


//遍历栈
Status print(LinkStack* s)
{
	system("cls");
	if (isEmptyLStack(s))
	{
		printf("未创建栈\n");
		system("pause");
		return ERROR;
	}
	printf("栈的数据为: ");
	printStack(s);
	system("pause");
	return SUCCESS;
}

//添加一个新元素
Status Add(LinkStack* s)
{
	system("cls");
	printf("添加前的栈: ");
	printStack(s);
	printf("请输入要添加的数据(0~10000): ");
	ElemType data = EnterInteger();
	pushLStack(s, data);
	printf("添加后的栈: ");
    printStack(s);
	system("pause");
	return SUCCESS;
}

//删除一个元素
Status Delete(LinkStack* s)
{
	system("cls");
	if (isEmptyLStack(s))
	{
		printf("栈中没有数据,无法进行删除操作\n");
		system("pause");
		return ERROR;
	}
	printf("删除前的栈: ");
	printStack(s);
	ElemType data;
	popLStack(s, &data);//出栈
	printf("删除后的栈: ");
	printStack(s);
	printf("删除的数据为：%d\n", data);
	system("pause");
	return SUCCESS;
}

//获取栈顶元素
Status GetTop(LinkStack* s)
{
	system("cls");
	if (isEmptyLStack(s))
	{
		printf("栈中没有数据，没有栈顶\n");
		system("pause");
		return ERROR;
	}
	printf("栈的数据为: ");
	printStack(s);
	ElemType data;
	getTopLStack(s, &data);
	printf("读取的栈顶元素为: %d\n", data);
	system("pause");
	return SUCCESS;
}

//栈的长度
Status GetLenghth(LinkStack* s)
{
	system("cls");
	printf("栈的数据为: ");
	printStack(s);
	int length;
	LStackLength(s, &length);//检测栈长度
	printf("栈的长度为: %d\n", length);
	system("pause");
	return SUCCESS;
}