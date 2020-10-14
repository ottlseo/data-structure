#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX];
}QueueType;

void printInfo();
void init(QueueType* q); //큐 초기화 함수
bool is_full(QueueType* q);
bool is_empty(QueueType* q);
void enqueue(QueueType* q, element item); //원소 넣기. full인지 체크하기 위해 int로 반환
element dequeue(QueueType* q); //원소 반환
void print_queue(QueueType* q);  //큐 출력
int print_num(QueueType* q); //원소 개수 반환

int main() {
	printInfo(); //정보 출력

	char input; //입력 받을 문자값 (e, d, p, 0)
	element en, de; //enqueue,dequeue 할 값
	QueueType q;
	init(&q); //큐 초기화

	printf("원하는 작업 <E/e:enqueue, D/d:dequeue, P/p:output, 0:quit>: ");
	scanf_s("%c", &input);

	while (input != '0') { //입력이 0이면 break
		switch (input) {
		case 'E': case 'e':
			printf("정수 입력: ");
			scanf_s("\n%d", &en); //엔터를 입력값으로 받지 않도록 \n%d
			if (is_full(&q)) { printf("queue is full"); }
			else { enqueue(&q, en); }//입력받은 en값을 enqueue
			break;
		case 'D': case 'd':
			if (is_empty(&q)) { printf("queue empty"); } //empty일 경우 출력
			else { printf("%3d\n", dequeue(&q)); } //dequeue한 값 반환, print
			break;
		case 'P': case 'p':
			print_queue(&q);
			break;
		default: //이외의 값 들어오면
			printf("Wrong Input\n");
			break;
		}
		printf("\n원하는 작업 <E/e:enqueue, D/d:dequeue, P/p:output, 0:quit>: ");
		scanf_s("\n%c", &input);
	} //end of while

	printf("\n현재 원소 개수는: %d\n", print_num(&q)); //원소 개수를 출력
	print_queue(&q); // 큐 출력하고 종료
	printf("Program Finished.");

	return 0;
}

void init(QueueType* q) {
	q->front = q->rear = 0;
}
bool is_full(QueueType* q) {
	return ((q->front) % MAX == (q->rear + 1) % MAX); //포화 상태
}
bool is_empty(QueueType* q) {
	return (q->front == q->rear);
}
void enqueue(QueueType* q, element item) {
	q->rear = (q->rear + 1) % MAX; //rear 증가
	q->data[q->rear] = item;
}
element dequeue(QueueType* q) {
	q->front = (q->front + 1) % MAX; //front 증가
	return q->data[q->front];
}
void print_queue(QueueType* q) {
	printf("Queue (front: %d, rear: %d) = ", q->front, q->rear); //front와 rear 위치 출력
	if (!is_empty(q)) {
		int i = q->front; //front에서 시작.
		do {
			i = (i + 1) % MAX; // i 증가시켜준다
			printf("%3d	|", q->data[i]); // 출력
			if (i == q->rear) break; // i가 rear와 같아지면 break
		} while (i != q->front);
	}
	printf("\n");
}
int print_num(QueueType* q) {
	return (q->rear - q->front + MAX) % MAX;
}

void printInfo(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}