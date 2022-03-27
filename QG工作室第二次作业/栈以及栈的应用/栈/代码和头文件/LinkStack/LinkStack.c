#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkStack.h"

//��ʼ��ջ
Status initLStack(LinkStack* s)
{
	s->top = NULL;//ָ���ָ��
	s->count = 0;//��ʼ����ֵ
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
//����0 ��ջ��Ϊ��
//����1 ��ջΪ��
Status isEmptyLStack(LinkStack* s)
{
	if (s->count)  //ջ��Ϊ��
		return 0;
	else          //ջΪ��
		return 1;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack* s, ElemType* e)
{
	if (isEmptyLStack(s))  //ջΪ��
	{
		printf("δ����ջ\n");
		return ERROR;
	}
	*e = s->top->data;  //�����ݴ���e
	return SUCCESS;
}


//���ջ
Status clearLStack(LinkStack* s)
{
	system("cls");
	LinkStackPtr p, q;
	p = s->top;  //ָ��ջ��
	while (p)
	{
		q = p->next; //ָ����һ�����
		free(p);
		p = q;
	} 
	s->top = NULL;  //ָ���ָ��
	s->count = 0;   //��ռ���
	printf("����ɹ�\n");
	system("pause");
	return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack* s)
{
	if (isEmptyLStack(s))  //ջΪ��
	{
		printf("δ����ջ\n");
		return ERROR;
	}
	LinkStackPtr p, q;
	p = s->top;  //ָ��ջ��
	while (p)
	{
		q = p->next; //ָ����һ�����
		free(p);
		p = q;
	}
	s->top = NULL;  //ָ���ָ��
	s->count = 0;   //��ռ���
	return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack* s, int* length)
{
	*length = s->count;//���ݸ���
	return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack* s, ElemType data)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode)); //����һ���µĿռ�
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
		return ERROR;
	}
	p->next = s->top; //p��nextָ��ջ��
	p->data = data;   //��ȡ����
	s->top = p;       //p��Ϊջ��
	s->count++;       //������1
	return SUCCESS;
}

//��ջ
Status popLStack(LinkStack* s, ElemType* data)
{
	if (isEmptyLStack(s))  //ջΪ��
	{
		printf("δ����ջ\n");
		return ERROR;
	}
	LinkStackPtr p = s->top; //pָ��ջ��
	*data = s->top->data;    //��ȡ����
	s->top = s->top->next;   //ջ��ָ����һ�����
	s->count--;              //������1
	free(p);                 //�ͷſռ�
	return SUCCESS;
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
	printf("ջϵͳ���ܲ˵�              "); 
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
	printf("���һ����Ԫ��");
	color(6);
	printf("            | \n");
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
	printf("ɾ��һ��Ԫ��");
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
	printf("            3. ");
	color(1);//��ɫ
	printf("ջ��Ԫ��");
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
	printf("            4. ");
	color(1);//��ɫ
	printf("���ջ");
	color(6);
	printf("                    | \n");
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
	printf("ջ�ĳ���");
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
	printf("            6. ");
	color(1);//��ɫ
	printf("����ջ");
	color(6);
	printf("                    | \n");
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

//��������
int EnterInteger(void)
{
	int NodeNum = 0;
	char ch;
	//while ((!scanf("%d", &NodeNum)) || (getchar() != '\n'))  /*���������Ϊ����*/
	while ((!scanf("%d", &NodeNum)) || (NodeNum < 0 || NodeNum > 10000) ||(ch = getchar(), ((ch != '\n') && (ch != '\t') && (ch != ' '))))  /*���������Ϊ����*/
	{
		printf("�������,������������ȷ������\n");
		while (getchar() != '\n');  /*����������������*/
	}
	return NodeNum;
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

//��ӡջ
Status printStack(LinkStack* s)
{
	LinkStackPtr p = s->top;
	while (p)  //p��Ϊ��
	{
		printf("%d->",p->data);
		p = p->next;
	}
	printf("NULL\n");
	return SUCCESS;
}


//����ջ
Status print(LinkStack* s)
{
	system("cls");
	if (isEmptyLStack(s))
	{
		printf("δ����ջ\n");
		system("pause");
		return ERROR;
	}
	printf("ջ������Ϊ: ");
	printStack(s);
	system("pause");
	return SUCCESS;
}

//���һ����Ԫ��
Status Add(LinkStack* s)
{
	system("cls");
	printf("���ǰ��ջ: ");
	printStack(s);
	printf("������Ҫ��ӵ�����(0~10000): ");
	ElemType data = EnterInteger();
	pushLStack(s, data);
	printf("��Ӻ��ջ: ");
    printStack(s);
	system("pause");
	return SUCCESS;
}

//ɾ��һ��Ԫ��
Status Delete(LinkStack* s)
{
	system("cls");
	if (isEmptyLStack(s))
	{
		printf("ջ��û������,�޷�����ɾ������\n");
		system("pause");
		return ERROR;
	}
	printf("ɾ��ǰ��ջ: ");
	printStack(s);
	ElemType data;
	popLStack(s, &data);//��ջ
	printf("ɾ�����ջ: ");
	printStack(s);
	printf("ɾ��������Ϊ��%d\n", data);
	system("pause");
	return SUCCESS;
}

//��ȡջ��Ԫ��
Status GetTop(LinkStack* s)
{
	system("cls");
	if (isEmptyLStack(s))
	{
		printf("ջ��û�����ݣ�û��ջ��\n");
		system("pause");
		return ERROR;
	}
	printf("ջ������Ϊ: ");
	printStack(s);
	ElemType data;
	getTopLStack(s, &data);
	printf("��ȡ��ջ��Ԫ��Ϊ: %d\n", data);
	system("pause");
	return SUCCESS;
}

//ջ�ĳ���
Status GetLenghth(LinkStack* s)
{
	system("cls");
	printf("ջ������Ϊ: ");
	printStack(s);
	int length;
	LStackLength(s, &length);//���ջ����
	printf("ջ�ĳ���Ϊ: %d\n", length);
	system("pause");
	return SUCCESS;
}