/* 2-1. 배열 이용한 원형 큐 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int element;
typedef struct {
	int front; //프론트 인덱스
	int rear;
	element data[MAX];
}QueueType;

void error(const char* message);
void init(QueueType* q);
bool is_full(QueueType* q);
bool is_empty(QueueType* q);
void enqueue(QueueType* q, element item);
element dequeue(QueueType* q);
void print_queue(QueueType* q);

int main() {
	QueueType q;
	init(&q);
	int input;

	printf("<데이터 추가>\n");
	while (!is_full(&q)) {
		printf("정수 입력: ");
		scanf_s("%d", &input);
		enqueue(&q, input);
		print_queue(&q);
	}
	printf("Queue is full\n");
	printf("\n<데이터 가져오기>\n");
	while (!is_empty(&q)) {
		printf("%3d\n", dequeue(&q));
		print_queue(&q);
	}
	printf("Queue is empty");
	return 0;
}
void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init(QueueType* q) {
	q->front = q->rear = 0;
}
bool is_full(QueueType* q) {
	return ((q->rear + 1) % MAX == q->front); //rear를 증가시킨 값이 front와 같으면 full
}
bool is_empty(QueueType* q) {
	return (q->rear == q->front); //front와 rear가 같으면 empty
}
void enqueue(QueueType* q, element item) {
	if (is_full(q)) { error("queue is full"); }
	else {
		q->rear = (q->rear + 1) % MAX; //rear를 증가시킴
		q->data[q->rear] = item;
	}
}
element dequeue(QueueType* q) {
	if (is_empty(q)) { error("queue is empty"); }
	else {
		q->front = (q->front + 1) % MAX; //front를 증가시킴 (원래 front는 아무 데이터도 안갖고 있으므로 먼저 증가)
		return q->data[q->front]; //반환
	}
}
void print_queue(QueueType* q) {
	printf("Queue <front:%d, rear:%d> = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX; //front+1부터 출력
			printf("%3d	:", q->data[i]);
			if (i == q->rear) { break; } //rear에 다다르면 다 출력한 것이므로 종료
		} while (i != q->front); //front가 아닐 때 계속 반복. 돌아오면 종료
	}
	printf("\n");
}
