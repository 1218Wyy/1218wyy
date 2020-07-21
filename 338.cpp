#include <cstdio>
#include <cstdlib>
 
typedef struct QNode{
	int value;	//��ǰ�����ܼ�ֵ
	int weight; //��ǰ��������
	struct QNode *next;
}QNode, *QueuePtr;
 
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}Queue;
 
int initQueue(Queue &Q) {
	Q.front=Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front) return -1;
	Q.front->next = NULL;
	return 1;
}
 
int emptyQueue(Queue Q) {
	if(Q.front == Q.rear) return 1;
	else return 0;
}
 
int destroyQueue(Queue &Q) {
	while(Q.front) {
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return 1;
}
 
int enQueue(Queue &Q, int value, int weight) {
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if(!p) return -1;
	p->value = value; 
	p->weight = weight; 
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	
	return 1;
}
 
int deQueue(Queue &Q, int &value, int &weight) {
	QueuePtr p;
	if(Q.front == Q.rear) return -1;
	p = Q.front->next;
	value = p->value;
	weight = p->weight;
	Q.front->next = p->next;
 
	if(Q.rear == p) Q.rear = Q.front;	
	free(p);
	return 1;
}
 
Queue loadingQueue;
int bestvalue, n;
 
void inQueue(int value, int weight, int i) {
	if(i == n - 1) {
		if(value > bestvalue) bestvalue = value;
	}
	else enQueue(loadingQueue, value, weight);
}
 
 
 
int main() {
	
	int i,j,k;
	int *w, *v, ew, ev;
	int c;
 
	freopen("knapsack.txt", "r", stdin);
//	freopen("knapsackout.txt", "w", stdout);
	scanf("%d%d",&n,&c);
 
	w=new int[n];
	v=new int[n];

	for(i=0;i<n;i++) scanf("%d%d",&w[i], &v[i]);

	initQueue(loadingQueue);
	enQueue(loadingQueue, -1, 0);		
 
	i=0;	//����
	ew=0;	//��չ����Ӧ��������
	ev=0;	
 
	while(true)	{
		if(ew + w[i] <= c) inQueue(ev + v[i], ew + w[i], i);
		inQueue(ev, ew, i); 
		deQueue(loadingQueue, ev, ew);
		if(ev == -1) {
			if(emptyQueue(loadingQueue)) {
				printf("the result is %d.\n", bestvalue);
			}
			enQueue(loadingQueue, -1, 0);
			deQueue(loadingQueue, ev, ew);
			i++;
		}
	}		
	
	return 0;
}
