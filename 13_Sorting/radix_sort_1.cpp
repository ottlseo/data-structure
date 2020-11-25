/* radix sort */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 100
#define BUCKETS 10 //십진수
#define DIGITS 4 //최대 4자리수까지 가능
#define SIZE 10

void printInfo(void);

/*------------------ Queue func ------------------*/
typedef int element;
typedef struct QueueType {
	int front, rear;
	element data[MAX_QUEUE_SIZE]; //큐
}QueueType;

void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init_queue(QueueType* q) { //큐 초기화 함수
	q->front = q->rear = 0; 
}
int is_empty(QueueType* q) {
	return (q->front == q->rear); //front와 rear가 같으면 empty
}
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); //원형 큐로 구현, rear+1이 front와 같으면 포화
}
void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("Queue is full");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("Queue is empty");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE; //front를 하나 당겨주고 
	return q->data[q->front]; //front에 있는 값을 리턴한다
}

/*------------------ radix_sort func ------------------*/
void radix_sort(int list[], int n) {
	int i, buc, dig, factor = 1;
	QueueType queue[BUCKETS];

	for (buc = 0; buc < BUCKETS; buc++) init_queue(&queue[buc]); //큐 초기화
	
	for (dig = 0; dig < DIGITS; dig++) { // 자릿수에 따라 반복문 돌림
		for (i = 0; i < n; i++)
			enqueue(&queue[(list[i] / factor) % 10], list[i]); //데이터들을 자리수에 따라 큐에 삽입

		for (buc = i = 0; buc < BUCKETS; buc++) { //버킷에서 꺼내어 list로 합치는 과정
			while (!is_empty(&queue[buc])) //비어있지 않으면
				list[i++] = dequeue(&queue[buc]);
		}
		factor *= 10; //자릿수를 결정하는 factor *10
	}
}

/*------------------ main ------------------*/
int main() {
	printInfo(); //정보 출력
	
	int list[SIZE];
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
		list[i] = rand() % 100;

	radix_sort(list, SIZE);
	for (int i = 0; i < SIZE; i++)
		printf("%d ", list[i]);
	printf("\n");

	return 0;
}

void printInfo(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}