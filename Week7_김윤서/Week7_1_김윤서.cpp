#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode { //큐에 넣을 노드 1개
	element data; //노드의 data부
	QueueNode* link; //노드의 link부
}QueueNode;
typedef struct QueueType {
	QueueNode* front; // 큐 전체에서 front인 노드
	QueueNode* rear; //rear 노드
}QueueType;

void printInfo();
void error(const char* message);
void init(QueueType* q);
bool is_empty(QueueType* q);
void enqueue(QueueType* q, element item);
element dequeue(QueueType* q);

int main() {
	printInfo(); //정보 출력
	
	int num, result = 0; //입력받을 값, 결과값=0
	QueueType fibo; //큐 생성
	init(&fibo);
	enqueue(&fibo, 0); // f(0)=0 삽입
	enqueue(&fibo, 1); // f(1)=1 삽입

	printf("Input a fibonicci location: ");
	scanf_s("%d", &num); //입력 받는다

	for (int i = 0; i <= num; i++) {
		result += dequeue(&fibo); //result값에 더해준다
		enqueue(&fibo, result); // 다음 값에 더해주기 위해 큐에 넣어준다
		printf("   %3d", result);
	}
	printf("\n");
	return 0;
}

void error(const char* message) { //오류 출력 함수
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init(QueueType* q) { //큐 초기화 함수
	q->front = q->rear = NULL; // front와 rear를 모두 NULL로 설정
}
bool is_empty(QueueType* q) {
	return (q->front == NULL); // front나 rear가 NULL이면 empty
}
void enqueue(QueueType* q, element item) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode)); //새 노드 생성
	temp->data = item; //data에 값 넣고
	temp->link = NULL; // link는 NULL로.
	if (is_empty(q)) { //q가 비어있을 경우, front와 rear를 모두 temp로 정한다
		q->front = q->rear = temp;
	} else {
		q->rear->link = temp; //rear의 link와 temp 연결
		q->rear = temp; //q의 rear를 temp로 변경한다.
	}
}
element dequeue(QueueType* q) {
	if (is_empty(q)) { error("Queue is empty"); }
	element data; // 지운 노드의 데이터 반환할 것
	QueueNode* temp = q->front; //지울 노드를 저장할 새 노드 생성
	data = temp->data;
	q->front = q->front->link; //front의 값을 옆으로 옮겨준다
	if (q->front == NULL) { q->rear = NULL; } //q에 노드가 한 개 있는 경우라면 queue를 공백으로 만들어줌
	free(temp); //지운 노드를 free 해준다
	return data; //지운 노드의 데이터 값 반환
}
void printInfo(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}