#define _CRT_SECURE_NO_WARNINGS 1
#include "LQueue.h"

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q) {
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	p->next = NULL;//ָ���ָ��
	Q->front = Q->rear = p;//front rearָ��ͷ���
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue* Q) {
	while (Q->front)
	{
		Q->rear = Q->front->next; //������һ������rear
		free(Q->front); //�ͷſռ�
		Q->front = Q->rear; //frontָ����һ�����
	}
	Q->length = 0;
	Q->front = Q->rear = NULL;//ָ���ָ��
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : �ж��Ƿ�Ϊ�գ����޷��ж�front�Ƿ��Ѿ�����
 */
Status IsEmptyLQueue(const LQueue* Q) {
	if (Q->front == Q->rear)
		return TRUE;
	else
		return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue* Q, void* e) {
	if (Q->front == NULL)//����δ��ʼ��
	{
		printf("δ��ʼ������\n");
		return FALSE;
	}
	if (IsEmptyLQueue(Q))//����Ϊ��
	{
		printf("����Ϊ��,���������\n");
		return FALSE;
	}
	int size = 0;
	printf("��ǰ���е�����Ϊ: ");
	print(Q);
	if (datatype[0] == 'i')//�����������
		size = sizeof(int);
	else if (datatype[0] == 'c')//����ַ�����
		size = sizeof(char);
	else if (datatype[0] == 'd')//��Ÿ�������
		size = sizeof(double);
	else if (datatype[0] == 's')//����ַ�������
		size = 21;              //Ĭ�ϴ��20���ֽڵ�����,���һ���ֽڴ��'\0'
	e = (void*)malloc(size);
	memcpy(e, Q->front->next->data, size);//����ͷԪ�ظ��Ƶ�e��
	printf("��ͷԪ��Ϊ: ");
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue* Q) {
	if (Q->front == NULL)
	{
		printf("δ��ʼ������\n");
		return FALSE;
	}
	return Q->length;//���س���
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue* Q, void* data) {
	if (Q->front == NULL) 
	{
		printf("δ��ʼ������\n");
		return FALSE;
	}
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
		return ERROR;
	}
	int size = 0;
	if (datatype[Q->length] == 'i')//�����������
		size = sizeof(int);
	else if (datatype[Q->length] == 'c')//����ַ�����
		size = sizeof(char);
	else if (datatype[Q->length] == 'd')//��Ÿ�������
		size = sizeof(double);
	else if (datatype[Q->length] == 's')//����ַ�������
		size = 21;              //Ĭ�ϴ��20���ֽڵ�����
	p->data = (void*)malloc(size);//Ϊp->data���ٿռ�

	if (p->data == NULL)//���ٿռ�ʧ��
	{
		printf("%s\n", strerror(errno));
		return FALSE;
	}
	memcpy(p->data, data, size);//��data���Ƶ�p��
	Q->rear->next = p;//pָ���β����һ�����
	Q->rear = p;//ָ���β
	p->next = NULL;
	Q->length++;//������1
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue* Q) {
	system("cls");
	if (Q->front == NULL)
	{
		printf("δ��ʼ������\n");
		system("pause");
		return FALSE;
	}
	if (IsEmptyLQueue(Q))
	{
		printf("ջΪ�գ��޷�����ɾ������\n");
		system("pause");
		return FALSE;
	}
	printf("����ǰ������: ");
	print(Q);
	Node* p = Q->front->next;//ָ���ͷ
	Q->front->next = p->next;
	if (Q->front->next == NULL)//��Q��ֻ��һ��Ԫ��ʱ
	{
		Q->rear = Q->front;
	}
	free(p);//�ͷ�p
	Q->length--;//���ȼ�1
	ForwardArray(Q);//����Ԫ����ǰ�ƶ�һλ
	printf("���ӳɹ�\n");
	printf("���Ӻ������: ");
	print(Q);
	system("pause");
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : ��ն��У�����ͷ�����
 */
void ClearLQueue(LQueue* Q) {
	system("cls");
	if (Q->front == NULL)
	{
		printf("δ��ʼ������\n");
		system("pause");
		return;
	}
	Node* p, * q;
	p = Q->front->next;//pָ���ͷ
	Q->rear = Q->front;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	Q->front->next = NULL;
	Q->length = 0;//�����ֵ
	printf("��ճɹ�\n");
	system("pause");
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
int num = 0;
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {
	system("cls");
	if (Q->front == NULL)
	{
		printf("δ��ʼ������\n");
		system("pause");
		return FALSE;
	}
	Node* p = Q->front->next;//��ͷԪ��
	num = 0;
	printf("���е�����Ϊ: ");
	while (p)
	{
		foo(p->data);//��ӡԪ��
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
 *    @description : ��������
 *    @param         q ָ��q

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

//����Ԫ����ǰ�ƶ�һλ
void ForwardArray(LQueue* Q)
{
	unsigned int i = 0;
	for (i = 0; i < Q->length; i++)//������ǰ��1λ
	{
		datatype[i] = datatype[i + 1];
	}
}

//�ı�������ɫ
void color(int x)/*�Զ��庯�����ݲ����ı���ɫ*/
{
	if (x >= 0 && x <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x | FOREGROUND_INTENSITY);/*�ı�������ɫ*/
	else/*Ĭ��Ϊ��ɫ*/
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

//�˵�
void menu(void)
{
	system("cls");
	printf("\n");
	printf("\n");
	printf("\n");
	color(6);//��ɫ
	printf("\t\t\t\t   __________________________________________\n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  |              ");
	color(4);//��ɫ
	printf("����ϵͳ���ܲ˵�            ");
	color(6);//��ɫ
	printf("|\n");
	printf("\t\t\t\t  |");
	color(3);//��ɫ
	printf("__________________________________________");
	color(6);
	printf("| \n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | ");
	color(10);//��ɫ
	printf("            1. ");
	color(1);//��ɫ
	printf("��ʼ������");
	color(6);
	printf("                | \n");
	printf("\t\t\t\t  |");
	color(3);//��ɫ
	printf("__________________________________________");
	color(6);//��ɫ
	printf("| \n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | ");
	color(10);//��ɫ
	printf("            2. ");
	color(1);//��ɫ
	printf("���ٶ���");
	color(6);
	printf("                  | \n");
	printf("\t\t\t\t  |");
	color(3);//��ɫ
	printf("__________________________________________");
	color(6);//��ɫ
	printf("| \n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | ");
	color(10);//��ɫ
	printf("            3. ");
	color(1);//��ɫ
	printf("�鿴��ͷ����");
	color(6);
	printf("              | \n");
	printf("\t\t\t\t  |");
	color(3);//��ɫ
	printf("__________________________________________");
	color(6);//��ɫ
	printf("| \n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | ");
	color(10);//��ɫ
	printf("            4. ");
	color(1);//��ɫ
	printf("���г���");
	color(6);
	printf("                  | \n");
	printf("\t\t\t\t  |");
	color(3);//��ɫ
	printf("__________________________________________");
	color(6);//��ɫ
	printf("| \n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | ");
	color(10);//��ɫ
	printf("            5. ");
	color(1);//��ɫ
	printf("���");
	color(6);
	printf("                      | \n");
	printf("\t\t\t\t  |");
	color(3);//��ɫ
	printf("__________________________________________");
	color(6);//��ɫ
	printf("| \n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | ");
	color(10);//��ɫ
	printf("            6. ");
	color(1);//��ɫ
	printf("����");
	color(6);
	printf("                      | \n");
	printf("\t\t\t\t  |");
	color(3);//��ɫ
	printf("__________________________________________");
	color(6);//��ɫ
	printf("| \n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | ");
	color(10);//��ɫ
	printf("            7. ");
	color(1);//��ɫ
	printf("��ն���");
	color(6);
	printf("                  | \n");
	printf("\t\t\t\t  |");
	color(3);//��ɫ
	printf("__________________________________________");
	color(6);//��ɫ
	printf("| \n");
	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | ");
	color(10);//��ɫ
	printf("            8. ");
	color(1);//��ɫ
	printf("��������");
	color(6);
	printf("                  | \n");
	printf("\t\t\t\t  |");
	color(3);//��ɫ
	printf("__________________________________________");
	color(6);//��ɫ
	printf("| \n");


	printf("\t\t\t\t  |                                          |\n");
	printf("\t\t\t\t  | ");
	color(10);//��ɫ
	printf("            0. ");
	color(1);//��ɫ
	printf("�˳�ϵͳ");
	color(6);
	printf("                  | \n");
	printf("\t\t\t\t  |");
	color(6);//��ɫ
	printf("__________________________________________");
	color(6);//��ɫ
	printf("| \n");
	printf("\n");

	printf("��������Ҫѡ��Ĺ���:");

}

//����һ������
int Enter(void)
{
	int NodeNum = 0;
	char ch;
	//while ((!scanf("%d", &NodeNum)) || (getchar() != '\n'))  /*���������Ϊ����*/
	while ((!scanf("%d", &NodeNum)) || (ch = getchar(), ((ch != '\n') && (ch != '\t') && (ch != ' '))))  /*���������Ϊ����*/
	{
		while (getchar() != '\n');  /*����������������*/
		return -1;
	}
	return NodeNum;
}

int flag = 1;
//��ʼ������
Status Init(LQueue* Q)
{
	system("cls");
	if (!flag)
	{
		printf("�ѳ�ʼ�����У������ظ���ʼ��\n");
		system("pause");
		return FALSE;
	}
	InitLQueue(Q);
	printf("��ʼ���ɹ�\n");
	flag = 0;
	system("pause");
	return TRUE;
}

//���ٶ���
Status Destory(LQueue* Q)
{
	system("cls");
	DestoryLQueue(Q);
	printf("���ٳɹ�\n");
	flag = 1;
	system("pause");
	return TRUE;
}

//�鿴��ͷ����
Status GetHead(LQueue* Q)
{
	system("cls");
	char e;
	GetHeadLQueue(Q, &e);
	system("pause");
	return TRUE;
}

//��ӡ����
Status print(const LQueue* Q) 
{
	Node* p = Q->front->next;//��ͷԪ��
	num = 0;
	while (p)
	{
		LPrint(p->data);//��ӡԪ��
		p = p->next;
		num++;
	}
	num = 0;
	printf("NULL\n");
	return TRUE;
}

//���г���
Status GetLength(LQueue* Q)
{
	system("cls");
	if (Q->front == NULL)
	{
		printf("δ��ʼ������\n");
		system("pause");
		return FALSE;
	}
	printf("���е�����Ϊ: ");
	print(Q);
	int Length = LengthLQueue(Q);
	printf("���еĳ���Ϊ: %d\n", Length);
	system("pause");
	return TRUE;
}

//���һ������
int Enternum(void)
{
	int enterNumber = 0;
	char ch;
	printf("������һ������[0~10000]: ");
	while ((!scanf("%d", &enterNumber)) || (enterNumber > 10000 && enterNumber < 0) || (ch = getchar(), ((ch != '\n') && (ch != '\t') && (ch != ' '))))  /*���������Ϊ����*/
	{
		while (getchar() != '\n');  /*����������������*/
		printf("�������,����������[0~10000]: ");
	}
	return enterNumber;
}

//���һ���ַ�
char Enterchar(void)
{
	char enterch = 0;
	char ch;
	printf("������һ���ַ�: ");
	while ((!scanf("%c", &enterch)) || (ch = getchar(), ((ch != '\n') && (ch != '\t') && (ch != ' '))))  /*���������Ϊ�ַ�*/
	{
		while (getchar() != '\n');  /*����������������*/
		printf("�������,����������һ���ַ�: ");
	}
	return enterch;
}

//���һ��С��
double Enterdou(void)
{
	double enterdou = 0;
	char ch;
	printf("������һ��С��[0~10000.0]: ");
	while ((!scanf("%lf", &enterdou)) || (enterdou > 10000 && enterdou < 0) || (ch = getchar(), ((ch != '\n') && (ch != '\t') && (ch != ' '))))  /*���������ΪС��*/
	{
		while (getchar() != '\n');  /*����������������*/
		printf("�������,����������[0~10000.0]: ");
	}
	return enterdou;
}

//���һ���ַ���
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
	printf("������һ���ַ���(˵�������ʮ�����ֻ��ʮ����ĸ): ");
	while ((!scanf("%[^\n]", enterstr)) || (length = strlen(enterstr),length > 20) || (ch = getchar(), ((ch != '\n') && (ch != '\t') && (ch != ' '))))  /*���������ΪС��*/
	{
		while (getchar() != '\n');  /*����������������*/
		printf("�������,��ע��˵�� (���ʮ�����ֻ��ʮ����ĸ): ");
	}
	return enterstr;
}

//������ݲ˵�
void Addmenu(void)
{
	printf("\n");
	printf("\n");
	printf("\n");
	color(6);//��ɫ
	printf("\t\t\t\t   ________________________\n");
	printf("\t\t\t\t  |                        |\n");
	printf("\t\t\t\t  | ");
	color(10);//��ɫ
	printf(" 1. ");
	color(1);//��ɫ
	printf("����");
	color(6);
	printf("               | \n");
	printf("\t\t\t\t  |");
	color(3);//��ɫ
	printf("________________________");
	color(6);
	printf("|\n");

	printf("\t\t\t\t  |                        |\n");
	printf("\t\t\t\t  | ");
	color(10);//��ɫ
	printf(" 2. ");
	color(1);//��ɫ
	printf("�ַ�");
	color(6);
	printf("               | \n");
	printf("\t\t\t\t  |");
	color(3);//��ɫ
	printf("________________________");
	color(6);
	printf("|\n");

	printf("\t\t\t\t  |                        |\n");
	printf("\t\t\t\t  | ");
	color(10);//��ɫ
	printf(" 3. ");
	color(1);//��ɫ
	printf("С��");
	color(6);
	printf("               | \n");
	printf("\t\t\t\t  |");
	color(3);//��ɫ
	printf("________________________");
	color(6);
	printf("|\n");

	printf("\t\t\t\t  |                        |\n");
	printf("\t\t\t\t  | ");
	color(10);//��ɫ
	printf(" 4. ");
	color(1);//��ɫ
	printf("�ַ���");
	color(6);
	printf("             | \n");
	printf("\t\t\t\t  |");
	color(6);//��ɫ
	printf("________________________");
	color(6);
	printf("|\n");
	printf("\n");

}

//���
Status Add(LQueue* Q)
{
	system("cls");
	if (Q->front == NULL)
	{
		printf("δ��ʼ������\n");
		system("pause");
		return FALSE;
	}
	int input;
	do
	{
	Return:
		system("cls");
		printf("���ǰ������: ");
		print(Q);
		Addmenu();
		printf("��ѡ����Ҫ��ӵ���������[1~4]: ");
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
			printf("�����������������!");
			system("pause");
			goto Return;
			break;
		}
	} while (!input);
	printf("��ӳɹ�\n");
	printf("��Ӻ������: ");
	print(Q);
	system("pause");
	return TRUE;
}
