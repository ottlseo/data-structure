#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode {
	element num; //데이터부
	QueueNode* link; //연결
}QueueNode;
typedef struct QueueType {
	QueueNode* front; //front 노드
	QueueNode* rear; //rear 노드
}QueueType;

void printInfo();
void error(const char* message);
void init(QueueType* q);
bool is_empty(QueueType* q);
void enqueue(QueueType* q, element item);
element dequeue(QueueType* q);
void print_queue(QueueType* q);
int node_num(QueueType* q);

int main() {
	printInfo(); //정보 출력

	int N; //N개의 카드
	element t1, t2; //버릴 카드, 아래로 옮길 카드
	QueueType* q = (QueueType*)malloc(sizeof(QueueType));
	init(q);

	printf("Input number of cards: ");
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) { enqueue(q, i + 1); } // 1부터 N까지의 카드를 큐에 넣는다

	while (node_num(q) != 1) { // 큐에 하나 남을 때까지
		print_queue(q);
		t1 = dequeue(q); //맨 위 카드를 버린다
		print_queue(q);
		t2 = dequeue(q); //다음 카드 t2를 빼고
		enqueue(q, t2); //t2를 제일 뒤로 넣는다
	}
	printf("Final element is %d\n", q->rear->num); //마지막 카드 번호 출력
	
	free(q); //동적할당한 큐를 풀어준다
	return 0;
}
void init(QueueType* q) {
	q->front = q->rear = NULL; //큐 초기화 함수
}
void error(const char* message) {
	fprintf(stderr,"%s\n", message);
	exit(1);
}
bool is_empty(QueueType* q) {
	return (q->front == NULL);
}
void enqueue(QueueType* q, element item) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->num = item;
	temp->link = NULL;
	if (is_empty(q)) { q->front = q->rear = temp; } //q가 비어있을 경우
	else {
		q->rear->link = temp; //rear의 link와 temp 연결
		q->rear = temp; //q의 rear를 temp로 변경한다.
	}
}
element dequeue(QueueType* q) {
	if (is_empty(q)) { error("queue is empty"); }
	QueueNode* temp = q->front;
	element data = temp->num; //반환할 값

	if (q->front->link == NULL) { //q에 원소가 하나일 경우
		q->front = q->rear = NULL; //큐를 비운 상태로 해준다
	}
	else { q->front = q->front->link; } //front 위치를 바꿔준다

	free(temp); //temp를 free 해준다
	return data;
}
void print_queue(QueueType* q) { //큐 프린트 함수
	QueueNode* temp = q->front;
	while (temp != NULL) {
		printf("  %3d  |", temp->num);
		temp = temp->link;
	}
	printf("\n");
}
int node_num(QueueType* q) { //연결리스트 시작주소를 받아 노드의 개수를 반환하는 함수
	QueueNode* node = q->front;
	int count = 0;
	while (node != q->rear) { //
		count++;
		node = node->link;
	}
	return (count + 1);
}
void printInfo(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}