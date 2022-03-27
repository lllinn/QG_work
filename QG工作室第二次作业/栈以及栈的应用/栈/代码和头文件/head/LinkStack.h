#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

#define ERROR   0
#define SUCCESS 1


typedef int Status;
typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;


typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;



//链栈
Status initLStack(LinkStack* s);//初始化栈
Status isEmptyLStack(LinkStack* s);//判断栈是否为空
Status getTopLStack(LinkStack* s, ElemType* e);//得到栈顶元素
Status clearLStack(LinkStack* s);//清空栈
Status destroyLStack(LinkStack* s);//销毁栈
Status LStackLength(LinkStack* s, int* length);//检测栈长度
Status pushLStack(LinkStack* s, ElemType data);//入栈
Status popLStack(LinkStack* s, ElemType* data);//出栈

void menu(void); //菜单
int EnterInteger(void);//输入整数
int Enter(void);//输入一个整数
Status print(LinkStack* s);//打印栈
Status Add(LinkStack* s);//添加一个新的元素
Status Delete(LinkStack* s);//删除一个元素
Status GetTop(LinkStack* s);//获取栈顶元素
Status GetLenghth(LinkStack* s);//栈的长度
#endif 
