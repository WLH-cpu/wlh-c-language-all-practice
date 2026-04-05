#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2

typedef int QElemType;
typedef int Status;

typedef struct QNode
{
	QElemType data;
	struct QNode* next;
}QNode,*QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue* Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front) exit(OVERFLOW);
	Q->front->next = NULL;
	return OK;
}

Status QueueEmpty(LinkQueue Q)
{
    return Q.front==Q.rear?TRUE:FALSE;
}

Status DestroyQueue(LinkQueue* Q)
{
	while (Q->front)
	{
		QueuePtr p = Q->front->next;
		free(Q->front);
		Q->front = p;
	}
	return OK;
}

Status EnQueue(LinkQueue* Q, QElemType e)
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}

Status DeQueue(LinkQueue* Q, QElemType* e)
{
	if (Q->front == Q->rear) return ERROR;
	QueuePtr p = (Q->front)->next;
	*e = p->data;
	(Q->front)->next = p->next;
	if (Q->rear == p) Q->rear = Q->front;
	free(p);
	return OK;
}

Status GetHead (LinkQueue Q,QElemType* e)
{
	if (Q.front == Q.rear) return ERROR;
	*e = Q.front->next->data;
	return OK;
}

int main()
{
    LinkQueue Q;
    QElemType e;
    InitQueue(&Q);

    EnQueue(&Q,1);
    EnQueue(&Q,2);
    EnQueue(&Q,3);

    GetHead(Q,&e);
    printf("%d\n",e);

    DeQueue(&Q,&e);
    GetHead(Q,&e);
    printf("%d\n",e);

    return 0;
}