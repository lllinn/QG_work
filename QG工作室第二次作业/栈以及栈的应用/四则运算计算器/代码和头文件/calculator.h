#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include "LinkStack.h"

extern void* data[100];//存放数据
extern char  datatype[100];//存放数据类型 'd'小数 和 'c'字符
extern int datanum;//数据位置
extern int datacount;//数据的数量


void Addchar(char ch);//添加字符到数组中
void Adddouble(double decimal);//添加小数到数组中
void print(void);//打印数组中的内容
Status InfixToSuffix(void);//中缀转后缀
void SuffixCal(void);//后缀计算出结果
void menu(void);//功能菜单
void color(int x);//颜色更改
#endif