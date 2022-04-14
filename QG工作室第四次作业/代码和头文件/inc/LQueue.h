#include "binary_sort_tree.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0


typedef NodePtr QElemType; /* QElemType类型根据实际情况而定，这里假设为int */

typedef struct QNode	/* 结点结构 */
{
	QElemType data;
	struct QNode* next;
}QNode, * QueuePtr;

typedef struct			/* 队列的链表结构 */
{
	QueuePtr front, rear; /* 队头、队尾指针 */
}LinkQueue;

Status InitQueue(LinkQueue* Q);/* 构造一个空队列Q */
Status DestroyQueue(LinkQueue* Q);//销毁队列
Status QueueEmpty(LinkQueue Q);//判断是否为空队列
int QueueLength(LinkQueue Q);//求队列长度
NodePtr GetHead(LinkQueue Q);//获取头元素
Status EnQueue(LinkQueue* Q, QElemType e);//插入新元素
NodePtr DeQueue(LinkQueue* Q);//删除队列元素


