#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include "LinkStack.h"

extern void* data[100];//�������
extern char  datatype[100];//����������� 'd'С�� �� 'c'�ַ�
extern int datanum;//����λ��
extern int datacount;//���ݵ�����


void Addchar(char ch);//����ַ���������
void Adddouble(double decimal);//���С����������
void print(void);//��ӡ�����е�����
Status InfixToSuffix(void);//��׺ת��׺
void SuffixCal(void);//��׺��������
void menu(void);//���ܲ˵�
void color(int x);//��ɫ����
#endif