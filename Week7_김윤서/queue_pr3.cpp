/* 7-3. 연결리스트로 구현한 큐 코드 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int element;
typedef struct QueueNode {
	element data;
	QueueNode* link;
}QueueNode;
typedef struct QueueType {
	QueueNode* front;
	QueueNode* rear;
}QueueType;

void error(const char* message);
void init(QueueType* q);
bool is_full(QueueType* q); //full일 수는 없음
bool is_empty(QueueType* q);
void enqueue(QueueType* q, element item);
element dequeue(QueueType* q);
void print_queue(QueueType* q);

int main() {
	QueueType* q = (QueueType*)malloc(sizeof(QueueType));
	init(q);

	printf("<데이터 추가>\n");
	for (int i = 0; i < 5; i++) {
		enqueue(q, i+1);
		print_queue(q);
	}
	printf("\n<데이터 가져오기>\n");
	for (int i = 0; i < 5; i++) {
		dequeue(q); print_queue(q);
	}
	free(q);
	return 0;
}
void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init(QueueType* q) {
	q->front = q->rear = NULL; //연결리스트 큐 초기화: front,rear 모두 NULL로 설정
}
bool is_full(QueueType* q) { //full일 수는 없음
	return 0;
}
bool is_empty(QueueType* q) {
	return (q->front == NULL); //front가 NULL이면 empty
}
void enqueue(QueueType* q, element item) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = item;
	temp->link = NULL;
	if (is_empty(q)) { //하나도 없을 경우. (빈 큐일 경우)
		q->front = temp;
		q->rear = temp;
	} else {
		q->rear->link = temp;
		q->rear = temp;
	}
}
element dequeue(QueueType* q) {
	if (is_empty(q)) { error("queue is empty"); }
	QueueNode* temp = q->front;
	element data = temp->data;
	if (q->front == q->rear) { //노드가 한 개있는 경우- 빈 큐로 만들어줌
		q->front = q->rear = NULL; 
	} else { q->front = q->front->link; } //else- front위치를 옮겨준다
	
	free(temp); //dequeue한 노드 동적할당을 풀어준다
	return data;
}
void print_queue(QueueType* q) {
	QueueNode* temp = q->front;
	while (temp != NULL) {
		printf("%3d  :", temp->data);
		temp = temp->link;
	}
	/* for(QueueNode* temp= q->front; temp!=NULL; temp=temp->link){} 로 해도 ok */
	printf("\n");
}