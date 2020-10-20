/* week7-4 연습: 배열 이용한 덱
	== 원형 큐 ADT와 비슷함! */
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX];
}DequeType;

void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init(DequeType* dq) {
	dq->front = dq->rear = 0; //원형 큐와 같음
}
bool is_full(DequeType* dq) {
	return ((dq->rear + 1) % MAX == dq->front); //원형 큐와 같음
}
bool is_empty(DequeType* dq) {
	return (dq->front == dq->rear);
}
void add_rear(DequeType* dq, element item) {
	if (is_full(dq)) { error("deque is full"); }
	dq->rear = (dq->rear + 1) % MAX; //하나 증가시켜주고
	dq->data[dq->rear] = item;
}
void add_front(DequeType* dq, element item) {
	if (is_full(dq)) error("deque is full");
	dq->data[dq->front] = item;
	dq->front = (dq->front - 1+MAX) % MAX; //front 자리에 값을 넣고 front를 감소 시켜줌
}
element get_rear(DequeType* dq) {
	if (is_empty(dq))error("deque is empty"); //비어있을 경우 오류
	return dq->data[dq->rear]; //값 반환, rear 위치는 그대로
}
element get_front(DequeType* dq) {
	if (is_empty(dq))error("deque is empty");
	return dq->data[(dq->front + 1) % MAX]; //front 다음 위치에 있는 값 반환, front 위치는 그대로
}
element del_rear(DequeType* dq) {
	if (is_empty(dq))error("deque is empty");
	int prev = dq->rear; //기존의 rear위치 임시 저장
	dq->rear = (dq->rear - 1 + MAX) % MAX; //rear를 감소시켜 새로운 rear로.
	return dq->data[prev]; //값 반환
}
element del_front(DequeType* dq) {
	if (is_empty(dq))error("deque is empty");
	dq->front = (dq->front + 1) % MAX; //front를 증가시킴
	return dq->data[dq->front]; //증가된 front위치에 있는 값 반환
}
void print_deque(DequeType* dq) {
	printf("Deque(front:%d, rear:%d) = ", dq->front, dq->rear);
	if (!is_empty(dq)) {
		int i = dq->front;
		do {
			i = (i + 1) % MAX;
			printf("%3d  |", dq->data[i]);
			if (i == dq->rear)break; //종료 조건
		} while (i != dq->front); //front로 돌아오면 종료
		printf("\n");
	}
}
int main() {
	DequeType dq;
	init(&dq);
	int element;

	printf("<front>에 데이터 추가\n");
	for (int i = 0; i < 3; i++) {
		printf("정수 입력: ");
		scanf_s("%d", &element);
		add_front(&dq, element);
		print_deque(&dq);
	}
	printf("\n<rear에서 데이터 가져오기>\n");
	for (int i = 0; i < 4; i++) {
		printf("%3d\n", del_rear(&dq));
		print_deque(&dq);
	}
	return 0;
}
