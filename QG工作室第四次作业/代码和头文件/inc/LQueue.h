#include "binary_sort_tree.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0


typedef NodePtr QElemType; /* QElemType���͸���ʵ������������������Ϊint */

typedef struct QNode	/* ���ṹ */
{
	QElemType data;
	struct QNode* next;
}QNode, * QueuePtr;

typedef struct			/* ���е�����ṹ */
{
	QueuePtr front, rear; /* ��ͷ����βָ�� */
}LinkQueue;

Status InitQueue(LinkQueue* Q);/* ����һ���ն���Q */
Status DestroyQueue(LinkQueue* Q);//���ٶ���
Status QueueEmpty(LinkQueue Q);//�ж��Ƿ�Ϊ�ն���
int QueueLength(LinkQueue Q);//����г���
NodePtr GetHead(LinkQueue Q);//��ȡͷԪ��
Status EnQueue(LinkQueue* Q, QElemType e);//������Ԫ��
NodePtr DeQueue(LinkQueue* Q);//ɾ������Ԫ��


