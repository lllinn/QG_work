#define _CRT_SECURE_NO_WARNINGS 1
#include "LQueue.h"

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q) {
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	p->next = NULL;//指向空指针
	Q->front = Q->rear = p;//front rear指向头结点
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue* Q) {
	while (Q->front)
	{
		Q->rear = Q->front->next; //传递下一个结点给rear
		free(Q->front); //释放空间
		Q->front = Q->rear; //front指向下一个结点
	}
	Q->length = 0;
	Q->front = Q->rear = NULL;//指向空指针
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : 判断是否为空，但无法判断front是否已经销毁
 */
Status IsEmptyLQueue(const LQueue* Q) {
	if (Q->front == Q->rear)
		return TRUE;
	else
		return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue* Q, void* e) {
	if (Q->front == NULL)//队列未初始化
	{
		printf("未初始化队列\n");
		return FALSE;
	}
	if (IsEmptyLQueue(Q))//队列为空
	{
		printf("队列为空,请添加数据\n");
		return FALSE;
	}
	int size = 0;
	printf("当前队列的数据为: ");
	print(Q);
	if (datatype[0] == 'i')//存放整数类型
		size = sizeof(int);
	else if (datatype[0] == 'c')//存放字符类型
		size = sizeof(char);
	else if (datatype[0] == 'd')//存放浮点类型
		size = sizeof(double);
	else if (datatype[0] == 's')//存放字符串类型
		size = 21;              //默认存放20个字节的内容,最后一个字节存放'\0'
	e = (void*)malloc(size);
	memcpy(e, Q->front->next->data, size);//将队头元素复制到e中
	printf("队头元素为: ");
	switch (datatype[0])
	{
	case 'i':
		printf("%d\n", *(int*)e);
		break;
	case 'd':
		printf("%.2lf\n", *(double*)e);
		break;
	case 'c':
		printf("%c\n", *(char*)e);
		break;
	case 's':
		printf("%s\n", (char*)e);
		break;
	}

	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue* Q) {
	if (Q->front == NULL)
	{
		printf("未初始化队列\n");
		return FALSE;
	}
	return Q->length;//返回长度
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue* Q, void* data) {
	if (Q->front == NULL) 
	{
		printf("未初始化队列\n");
		return FALSE;
	}
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
		return ERROR;
	}
	int size = 0;
	if (datatype[Q->length] == 'i')//存放整数类型
		size = sizeof(int);
	else if (datatype[Q->length] == 'c')//存放字符类型
		size = sizeof(char);
	else if (datatype[Q->length] == 'd')//存放浮点类型
		size = sizeof(double);
	else if (datatype[Q->length] == 's')//存放字符串类型
		size = 21;              //默认存放20个字节的内容
	p->data = (void*)malloc(size);//为p->data开辟空间

	if (p->data == NULL)//开辟空间失败
	{
		printf("%s\n", strerror(errno));
		return FALSE;
	}
	memcpy(p->data, data, size);//将data复制到p中
	Q->rear->next = p;//p指向队尾的下一个结点
	Q->rear = p;//指向队尾
	p->next = NULL;
	Q->length++;//个数加1
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue* Q) {
	system("cls");
	if (Q->front == NULL)
	{
		printf("未初始化队列\n");
		system("pause");
		return FALSE;
	}
	if (IsEmptyLQueue(Q))
	{
		printf("栈为空，无法进行删除操作\n");
		system("pause");
		return FALSE;
	}
	printf("出队前的数据: ");
	print(Q);
	Node* p = Q->front->next;//指向队头
	Q->front->next = p->next;
	if (Q->front->next == NULL)//当Q中只有一个元素时
	{
		Q->rear = Q->front;
	}
	free(p);//释放p
	Q->length--;//长度减1
	ForwardArray(Q);//所有元素往前移动一位
	printf("出队成功\n");
	printf("出队后的数据: ");
	print(Q);
	system("pause");
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : 清空队列，除了头结点外
 */
void ClearLQueue(LQueue* Q) {
	system("cls");
	if (Q->front == NULL)
	{
		printf("未初始化队列\n");
		system("pause");
		return;
	}
	Node* p, * q;
	p = Q->front->next;//p指向队头
	Q->rear = Q->front;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	Q->front->next = NULL;
	Q->length = 0;//清空数值
	printf("清空成功\n");
	system("pause");
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
int num = 0;
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {
	system("cls");
	if (Q->front == NULL)
	{
		printf("未初始化队列\n");
		system("pause");
		return FALSE;
	}
	Node* p = Q->front->next;//队头元素
	num = 0;
	printf("队列的数据为: ");
	while (p)
	{
		foo(p->data);//打印元素
		p = p->next;
		num++;
	}
	num = 0;
	printf("NULL\n");
	system("pause");
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
void LPrint(void* q) {
	type = datatype[num];
	switch (type)
	{
	case 'i':
		printf("%d->", *(int*)q);
		break;
	case 'd':
		printf("%.2lf->", *(double*)q);
		break;
	case 'c':
		printf("%c->", *(char*)q);
		break;
	case 's':
		printf("%s->", (char*)q);
		break;
	}
}

//所有元素往前移动一位
void ForwardArray(LQueue* Q)
{
	unsigned int i = 0;
	for (i = 0; i < Q->length; i++)//数据往前放1位
	{
		datatype[i] = datatype[i + 1];
	}
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
	printf("队列系统功能菜单            ");
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
	printf("初始化队列");
	color(6);
	printf("                | \n");
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
	printf("销毁队列");
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
	printf("            3. ");
	color(1);//蓝色
	printf("查看队头数据");
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
	printf("            4. ");
	color(1);//蓝色
	printf("队列长度");
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
	printf("            5. ");
	color(1);//蓝色
	printf("入队");
	color(6);
	printf("                      | \n");
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
	printf("出队");
	color(6);
	printf("                      | \n");
	printf("\t\t\t\t  |");
	color(3);//紫色
	printf("__________________________________________");
	color(6);//黄色
	printf("| \n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | ");
	color(10);//绿色
	printf("            7. ");
	color(1);//蓝色
	printf("清空队列");
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
	printf("            8. ");
	color(1);//蓝色
	printf("遍历队列");
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

int flag = 1;
//初始化队列
Status Init(LQueue* Q)
{
	system("cls");
	if (!flag)
	{
		printf("已初始化队列，请勿重复初始化\n");
		system("pause");
		return FALSE;
	}
	InitLQueue(Q);
	printf("初始化成功\n");
	flag = 0;
	system("pause");
	return TRUE;
}

//销毁队列
Status Destory(LQueue* Q)
{
	system("cls");
	DestoryLQueue(Q);
	printf("销毁成功\n");
	flag = 1;
	system("pause");
	return TRUE;
}

//查看对头数据
Status GetHead(LQueue* Q)
{
	system("cls");
	char e;
	GetHeadLQueue(Q, &e);
	system("pause");
	return TRUE;
}

//打印队列
Status print(const LQueue* Q) 
{
	Node* p = Q->front->next;//队头元素
	num = 0;
	while (p)
	{
		LPrint(p->data);//打印元素
		p = p->next;
		num++;
	}
	num = 0;
	printf("NULL\n");
	return TRUE;
}

//队列长度
Status GetLength(LQueue* Q)
{
	system("cls");
	if (Q->front == NULL)
	{
		printf("未初始化队列\n");
		system("pause");
		return FALSE;
	}
	printf("队列的数据为: ");
	print(Q);
	int Length = LengthLQueue(Q);
	printf("队列的长度为: %d\n", Length);
	system("pause");
	return TRUE;
}

//添加一个整数
int Enternum(void)
{
	int enterNumber = 0;
	char ch;
	printf("请输入一个整数[0~10000]: ");
	while ((!scanf("%d", &enterNumber)) || (enterNumber > 10000 && enterNumber < 0) || (ch = getchar(), ((ch != '\n') && (ch != '\t') && (ch != ' '))))  /*输入的数不为整数*/
	{
		while (getchar() != '\n');  /*将缓冲区的数读走*/
		printf("输入错误,请重新输入[0~10000]: ");
	}
	return enterNumber;
}

//添加一个字符
char Enterchar(void)
{
	char enterch = 0;
	char ch;
	printf("请输入一个字符: ");
	while ((!scanf("%c", &enterch)) || (ch = getchar(), ((ch != '\n') && (ch != '\t') && (ch != ' '))))  /*输入的数不为字符*/
	{
		while (getchar() != '\n');  /*将缓冲区的数读走*/
		printf("输入错误,请重新输入一个字符: ");
	}
	return enterch;
}

//添加一个小数
double Enterdou(void)
{
	double enterdou = 0;
	char ch;
	printf("请输入一个小数[0~10000.0]: ");
	while ((!scanf("%lf", &enterdou)) || (enterdou > 10000 && enterdou < 0) || (ch = getchar(), ((ch != '\n') && (ch != '\t') && (ch != ' '))))  /*输入的数不为小数*/
	{
		while (getchar() != '\n');  /*将缓冲区的数读走*/
		printf("输入错误,请重新输入[0~10000.0]: ");
	}
	return enterdou;
}

//添加一个字符串
char* Enterstr(void)
{
	char* enterstr = (char*)malloc(sizeof(21));
	if (enterstr == NULL)
	{
		printf("%s\n",strerror(errno));
		return NULL;
	}
	char ch;
	int length;
	printf("请输入一个字符串(说明：最多十个汉字或二十个字母): ");
	while ((!scanf("%[^\n]", enterstr)) || (length = strlen(enterstr),length > 20) || (ch = getchar(), ((ch != '\n') && (ch != '\t') && (ch != ' '))))  /*输入的数不为小数*/
	{
		while (getchar() != '\n');  /*将缓冲区的数读走*/
		printf("输入错误,请注意说明 (最多十个汉字或二十个字母): ");
	}
	return enterstr;
}

//添加数据菜单
void Addmenu(void)
{
	printf("\n");
	printf("\n");
	printf("\n");
	color(6);//黄色
	printf("\t\t\t\t   ________________________\n");
	printf("\t\t\t\t  |                        |\n");
	printf("\t\t\t\t  | ");
	color(10);//绿色
	printf(" 1. ");
	color(1);//蓝色
	printf("整数");
	color(6);
	printf("               | \n");
	printf("\t\t\t\t  |");
	color(3);//紫色
	printf("________________________");
	color(6);
	printf("|\n");

	printf("\t\t\t\t  |                        |\n");
	printf("\t\t\t\t  | ");
	color(10);//绿色
	printf(" 2. ");
	color(1);//蓝色
	printf("字符");
	color(6);
	printf("               | \n");
	printf("\t\t\t\t  |");
	color(3);//紫色
	printf("________________________");
	color(6);
	printf("|\n");

	printf("\t\t\t\t  |                        |\n");
	printf("\t\t\t\t  | ");
	color(10);//绿色
	printf(" 3. ");
	color(1);//蓝色
	printf("小数");
	color(6);
	printf("               | \n");
	printf("\t\t\t\t  |");
	color(3);//紫色
	printf("________________________");
	color(6);
	printf("|\n");

	printf("\t\t\t\t  |                        |\n");
	printf("\t\t\t\t  | ");
	color(10);//绿色
	printf(" 4. ");
	color(1);//蓝色
	printf("字符串");
	color(6);
	printf("             | \n");
	printf("\t\t\t\t  |");
	color(6);//紫色
	printf("________________________");
	color(6);
	printf("|\n");
	printf("\n");

}

//入队
Status Add(LQueue* Q)
{
	system("cls");
	if (Q->front == NULL)
	{
		printf("未初始化队列\n");
		system("pause");
		return FALSE;
	}
	int input;
	do
	{
	Return:
		system("cls");
		printf("入队前的数据: ");
		print(Q);
		Addmenu();
		printf("请选择想要添加的数据类型[1~4]: ");
		input = Enter();
		switch(input)
		{
		case 1:
			datatype[Q->length] = 'i';
			int number = Enternum();
			EnLQueue(Q, &number);
			break;
		case 2:
			datatype[Q->length] = 'c';
			char ch = Enterchar();
			EnLQueue(Q, &ch);
			break;
		case 3:
			datatype[Q->length] = 'd';
			double dou = Enterdou();
			EnLQueue(Q, &dou);
			break;
		case 4:
			datatype[Q->length] = 's';
			char* str = (char*)malloc(sizeof(21));
			str = Enterstr();
			EnLQueue(Q, str);
			break;
		default:
			printf("输入错误，请重新输入!");
			system("pause");
			goto Return;
			break;
		}
	} while (!input);
	printf("添加成功\n");
	printf("入队后的数据: ");
	print(Q);
	system("pause");
	return TRUE;
}
