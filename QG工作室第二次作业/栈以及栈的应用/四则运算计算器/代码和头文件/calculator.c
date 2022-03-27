#define _CRT_SECURE_NO_WARNINGS 1
#include "calculator.h"

void* data[100];//�������
char  datatype[100];//�����������
int datanum = 0;//����λ��
int datacount = 0;//���ݵ�����

//����ַ���������
void Addchar(char ch)
{
	datatype[datanum] = 'c';//�������
	data[datanum] = (char*)malloc(sizeof(char));//���ٿռ�
	if (data[datanum] == NULL)//�����ڴ�ʧ��
	{
		printf("%s\n", strerror(errno));
		return;
	}
	memcpy(data[datanum], &ch, sizeof(char));
	datanum++;//λ��+1
	datacount++;//����+1
}


//���С����������
void Adddouble(double decimal)
{
	datatype[datanum] = 'd';//�������
	data[datanum] = (double*)malloc(sizeof(double));//���ٿռ�
	if (data[datanum] == NULL)//�����ڴ�ʧ��
	{
		printf("%s\n", strerror(errno));
		return;
	}
	memcpy(data[datanum], &decimal, sizeof(double));
	datanum++;//λ��+1
	datacount++;//����+1
}

//��ӡ�����е�����
void print(void)
{
	int i = 0;
	char ch;//�鿴��Ӧ����
	for (i = 0; i < datacount; i++)
	{
		ch = datatype[i];//��ȡ����
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




//��׺ת��׺
Status InfixToSuffix(void)
{
	datanum = 0;//��������
	datacount = 0;//��������
	char ch;
	char chs;//������ȡ[ ���� �� '(' ]����ַ�
	int chsflag = 0;//��ǰ��ȡ��־λ�������ж����ֺ���������ֻ����ַ�,����'('�����ַ����ж�
	int decimalflag = 0;//С�����־λ,�����ж�С����������
	int firstflag = 1;//��һ�ζ�ȡ�ı�־λ
	int negativeflag = 0;//�����ж��Ƿ��Ǹ���
	int nextflag = 0;//ֱ�Ӷ�ȡ��һ���ַ���־λ
	char temp;
	double num;//�������
	double decimal = 0;//���С��������
	CLinkStack S;//����ջ������Ԫ�ط�
	initCLStack(&S);//��ʼ��S
	int flag = 1;//��־λ�������ж϶�ȡ�����������������,��־λΪ1ʱ�����֣���־λΪ0ʱ���ַ�
	do
	{
		num = 0;//��������
		decimal = 0;//С������������
		if (firstflag)//��һ�ζ�ȡ
		{
			scanf(" %c", &ch);//��ȡ��һ���ǿ��ַ�
			if (ch == '-')//���������-��
			{
				negativeflag = 1;//������־λ��1
				nextflag = 1;//ֱ�Ӷ�ȡ��һ���ַ���־λ��1
			}
			else if (ch == '+')//���������+��
			{
				negativeflag = 0;//������־λ��0
				nextflag = 1;//ֱ�Ӷ�ȡ��һ���ַ���־λ��1
			}
			firstflag = 0;//��һ�ζ�ȡ��־λ��0
		}
		else//���ǵ�һ�ζ�ȡ
		{
			if (chsflag) //���ֺ����������
			{
				ch = chs;//ch��ȡ�����
				chsflag = 0;//����
			}
			else
			{
				while ((ch = getchar(), ch == ' ' || ch == '\t'));//��ȡ����'\n'�Ŀ��ַ�
			}
		}
		if (nextflag)//��һ�ζ�ȡ������+-��
		{
			while ((ch = getchar(), ch == ' ' || ch == '\t'));//��ȡ����'\n'�Ŀ��ַ�
			nextflag = 0;
		}
		if ((ch == '(') || (ch == ')'))   //�������Ϊ '(' �� ')'  
			flag = 0;
		if (flag)    //�洢����
		{
			if ((ch >= '0') && (ch <= '9'))//�����������
			{
				num = ch - '0';//��ֵ
				while (1)
				{
					chs = getchar();//��ȡ���ֺ�����ַ�
					if ((chs >= '0') && (chs <= '9'))//���ֺ����������
					{
						if (decimalflag == 0)//����С����������
						{
							num *= 10;//����ʮ��
							num += chs - '0';//��ȡ��λ��
						}
						else//��С���������� 
						{
							//�ȷŵ��������֣��˳�ѭ�����ٰ�����С��С��
							decimal *= 10;//����ʮ��
							decimal += chs - '0';//��ȡ��λ��
						}
					}
					else if (chs == '.')//���ֺ�����С����
					{
						decimalflag = 1;
					}
					else if ((chs == ' ') || (chs == '\t'))//����ǿ��ַ�,����ѭ��
					{
						break;
					}
					else//���ֺ���������ַ�,����ѭ��
					{
						chsflag = 1;
						break;
					}
				}
				while (decimal >= 1.0)//��С�����ֻ���С��
				{
					decimal /= 10;
				}
				num += decimal;//��С�����ּ�����
				if (negativeflag)//����Ǹ���
				{
					negativeflag = 0;//������־λ��0
					num *= (-1);
				}
				if (num <= 10000.0 && num >= -10000.0)
				{
					Adddouble(num);//��С���ŵ�������
				}
				else
				{
					printf("�������������Χ\n");
					return ERROR;
				}
			}
			else if(ch == '\n')//����ǻ��з�
			{
				chsflag = 1;
				chs = ch;
			}
			else//�������
			{
				printf("�������\n");
				return ERROR;
			}
			flag = 0;//��־λ��0�����ֺ����Ǳض��������
		}
		else         //�洢�����
		{
			if (ch == '(') //'('����һ��������,�� һ����ջ
			{
				pushCLStack(&S, ch);//��ջ
				while ((chs = getchar(), chs == ' ' || chs == '\t'));//��ȡ����'\n'�ķǿ��ַ�
				if (chs == '-')//�����ź�����-��
				{
					negativeflag = 1;//������־λ��1
				}
				else if (chs == '+')//�����ź�����+��
				{
					negativeflag = 0;//������־λ��0
				}
				else
				{
					chsflag = 1;//��ǰ��ȡ��־λ��1
				}
			}
			else if (ch == ')')//')'����һ���������, )   ��Ԫ�س�ջֱ�� (
			{
				if (isEmptyCLStack(&S))//ջΪ�գ��������
				{
					printf("�������\n");
					return ERROR;
				}
				do//һֱ�ҵ� (,ͬʱ�����ݴ�ŵ�������
				{
					popCLStack(&S, &temp);//ջ����ջ
					if (temp == '(')//�ҵ� ( �˳�ѭ��
					{
						break;
					}
					if (isEmptyCLStack(&S))//ջΪ�գ��Ҳ��� ( ,�������
					{
						printf("�������\n");
						return ERROR;
					}
					//��ʱջ�бض��������
					Addchar(temp);//����������������
				} while (temp != '(');
				flag = 0;//��һ�������
				continue;
			}
			else if ((ch == '*') || (ch == '/'))//*��/һ����ջ
			{
				if (isEmptyCLStack(&S))//ջΪ��
				{
					pushCLStack(&S, ch);//��ջ
				}
				else//��Ϊ��
				{
					getTopCLStack(&S, &temp);//��ȡջ��Ԫ��
					if (temp == '(' || temp == '+' || temp == '-')//ջ��Ϊ (��+��-��ֱ����ջ
					{
						pushCLStack(&S, ch);
					}
					else//���Ϊ*��/,ջ����ջ������ŵ�������
					{
						popCLStack(&S, &temp);//ջ����ջ
						Addchar(temp);
						pushCLStack(&S, ch);//*��/��ջ
					}
				}
			}
			else if ((ch == '+') || (ch == '-'))//+��-
			{
				if (isEmptyCLStack(&S))//ջΪ�գ�ֱ����ջ
				{
					pushCLStack(&S, ch);
				}
				else//ջ��Ϊ��
				{
					while (1)
					{
						getTopCLStack(&S, &temp);//��ȡջ��Ԫ��
						if (temp == '(')//ջ��Ϊ��'(' ֱ����ջ
						{
							break;
						}
						else  //�������( + - * / )ջ�е�Ԫ�ض�Ҫ��ջ
						{
							popCLStack(&S, &temp);//ջ����ջ
							Addchar(temp);//��ŵ�������
						}
						if (isEmptyCLStack(&S))//Ԫ�س�ջ��,ջΪ��
						{
							break;
						}
					}
					pushCLStack(&S, ch);//��ջ
				}
			}
			else if(ch == '\n')//����ǻ��з�
			{
				break;
			}
			else//��������������
			{
				printf("�������\n");
				return ERROR;
			}
			flag = 1;//��־λ��1�����������ض�������[����")"]
		}
	} while (ch != '\n');//���з�Ϊ��������
	while (isEmptyCLStack(&S) == 0) //���ջ��Ϊ��
	{
		char popchar = 0;
		popCLStack(&S, &popchar);//��ջ
		if (popchar == '(')
		{
			printf("�������\n");
			return ERROR;
		}
		Addchar(popchar);//����ַ���������
	}
	return SUCCESS;
}

//�ӷ�
double Add(double num1, double num2)
{
	return num1 + num2;
}

//����
double Sub(double num1, double num2)
{
	return num1 - num2;
}

//�˷�
double Mul(double num1, double num2)
{
	return num1 * num2;
}

//����
double Div(double num1, double num2)
{
	return num1 / num2;
}

//����
Status Cal(DLinkStack *D, double (*p)(double num1, double num2))
{
	double num1, num2;//���������
	if (isEmptyDLStack(D))//�ж��Ƿ�Ϊ��
	{
		printf("�������\n");
		return ERROR;
	}
	popDLStack(D, &num2);//ȡ��ջ��
	if (isEmptyDLStack(D))//�ж��Ƿ�Ϊ��
	{
		printf("�������\n");
		return ERROR;
	}
	popDLStack(D, &num1);
	if (p == Div)
	{
		if (num2 == 0)
		{
			printf("0���ܳ���\n");
			return ERROR;
		}
	}
	num1 = p(num1, num2);
	pushDLStack(D, num1);
	return SUCCESS;
}

//��׺���ʽ��������
Status Calculation(DLinkStack* D)
{
	int i = 0;
	char type;//��ȡ��������
	double num;//��Ÿ�����
	char ch;//��������
	for (i = 0; i < datacount; i++)
	{
		type = datatype[i];
		switch (type)
		{
		case 'd': //����
			num = *((double*)(data[i]));//ת��Ϊ������
			pushDLStack(D, num);//���ֽ�ջ
			break;
		case 'c': //�����
			ch = *((char*)(data[i]));//ת��Ϊ�ַ�����
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

//�ı�������ɫ
void color(int x)/*�Զ��庯�����ݲ����ı���ɫ*/
{
	if (x >= 0 && x <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x | FOREGROUND_INTENSITY);/*�ı�������ɫ*/
	else/*Ĭ��Ϊ��ɫ*/
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void SuffixCal(void)
{
	DLinkStack D;
	initDLStack(&D);//��ʼ��
	double num;
	if (Calculation(&D))
	{
		if (isEmptyDLStack(&D))
		{
			printf("�������\n");
			return;
		}
		popDLStack(&D,&num);
		color(12);
		printf("\t\t��������: ");
		color(1);
		printf("%.3lf ", num);
		color(8);
		printf("(�������3λС��)\n");
	}
}


//�˵�
void menu(void)
{
		system("cls");
		printf("\n");
		printf("\n");
		printf("\n");
		color(6);//��ɫ
		printf("\t\t\t\t   ________________________\n");
		printf("\t\t\t\t  |                        |\n");
		printf("\t\t\t\t  | ");
		color(10);//��ɫ
		printf("���������");
		color(6);
		printf("             | \n");
		printf("\t\t\t\t  |");
		color(3);//��ɫ
		printf("________________________");
		color(6);
		printf("|\n");

		printf("\t\t\t\t  |                        |\n");
		printf("\t\t\t\t  | ");
		color(15);//��ɫ
		printf(" +");
		color(9);
		printf("  �Ӻ�");
		color(6);
		printf("               | \n");
		printf("\t\t\t\t  |");
		color(3);//��ɫ
		printf("________________________");
		color(6);
		printf("|\n");

		printf("\t\t\t\t  |                        |\n");
		printf("\t\t\t\t  | ");
		color(15);//��ɫ
		printf(" -");
		color(9);
		printf("  ����");
		color(6);
		printf("               | \n");
		printf("\t\t\t\t  |");
		color(3);//��ɫ
		printf("________________________");
		color(6);
		printf("|\n");

		printf("\t\t\t\t  |                        |\n");
		printf("\t\t\t\t  | ");
		color(15);//��ɫ
		printf(" *");
		color(9);
		printf("  �˺�");
		color(6);
		printf("               | \n");
		printf("\t\t\t\t  |");
		color(3);//��ɫ
		printf("________________________");
		color(6);
		printf("|\n");

		printf("\t\t\t\t  |                        |\n");
		printf("\t\t\t\t  | ");
		color(15);//��ɫ
		printf(" /");
		color(9);
		printf("  ����");
		color(6);
		printf("               | \n");
		printf("\t\t\t\t  |");
		color(3);//��ɫ
		printf("________________________");
		color(6);
		printf("|\n");

		printf("\t\t\t\t  |                        |\n");
		printf("\t\t\t\t  | ");
		color(15);//��ɫ
		printf(" ( )");
		color(9);
		printf(" ����");
		color(6);
		printf("              | \n");
		printf("\t\t\t\t  |");
		color(3);//��ɫ
		printf("________________________");
		color(6);
		printf("|\n");

		printf("\t\t\t\t  |                        |\n");
		printf("\t\t\t\t  |");
		color(15);//��ɫ
		printf("  ���뷨: ");
		color(0);
		printf(" Ӣ�����뷨");
		color(6);
		printf("   | \n");
		printf("\t\t\t\t  |");
		color(3);//��ɫ
		printf("________________________");
		color(6);
		printf("|\n");
		printf("\n");
		printf("\t\t\t����������Ҫ�����ʽ��(���ַ�Χ[-10000.0~10000.0])\n");
		color(12);
		printf("\t\t   ����ʽ:>>");
		color(3);
}
