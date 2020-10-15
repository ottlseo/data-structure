/* 연습 1-1. 배열 이용한 선형 큐 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX];
}QueueType;

void error(const char* message);
void init(QueueType* q); //queue 초기화
bool is_full(QueueType* q);
bool is_empty(QueueType* q);
void enqueue(QueueType* q, element item);
element dequeue(QueueType* q);
void print_queue(QueueType* q);

int main() {
	element item;
	QueueType q; //queue 정의하고, //동적할당 해야하나???
	init(&q); //초기화
	enqueue(&q, 10); print_queue(&q);
	enqueue(&q, 20); print_queue(&q);
	enqueue(&q, 30); print_queue(&q);

	item = dequeue(&q); print_queue(&q);
	item = dequeue(&q); print_queue(&q);
	item = dequeue(&q); print_queue(&q);
	item = dequeue(&q); print_queue(&q);

	return 0;
}

/* 함수 정으의 ------------------ */
void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init(QueueType* q) { //queue 초기화
	q->front = q->rear = -1; //선형 큐이므로 -1부터 시작. 원형은 0부터, 연결리스트는 NULL로.
}
bool is_full(QueueType* q) {
	return (q->rear == MAX - 1); //max값에서 1 뺀값과 rear가 같으면 full
}
bool is_empty(QueueType* q) {
	return (q->rear == q->front); //rear가 front와 같은 경우
}
void enqueue(QueueType* q, element item) {
	if (is_full(q)) { error("queue Overflow"); return; }
	q->data[++q->rear] = item; //증가 먼저, 이후 값 대입
}
element dequeue(QueueType* q) {
	if (is_empty(q)) { error("queue empty"); return -1; }
	else return q->data[q->front++];
}
void print_queue(QueueType* q) {
	for (int i = 0; i < MAX; i++) {
		if (i < q->front || i > q->rear)
			printf("	|");
		else { printf("%3d	|",q->data[i]); }
	}
	printf("\n");
}