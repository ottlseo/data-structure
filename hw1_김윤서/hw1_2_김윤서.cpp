#include <stdio.h>
#include <stdlib.h>

typedef struct dListNode {
	int num;
	dListNode* llink;
	dListNode* rlink;
}dListNode;
typedef struct dListType {
	dListNode* head;
	int size; //리스트의 크기
}dListType;

void printInfo();
void error(const char* message);
dListNode* create(); //생성
void insert_last(dListNode* head, int num); // 마지막에 항 추가하는 함수
void print_dlist(dListNode* head); //리스트 출력 함수
void print_reverse(dListNode* head); //역순 출력 함수

/* ------------------ main -----------------*/
int main() {
	int input; //입력값
	dListNode* head = create(); //새로운 리스트 생성
	
	printInfo(); //정보 출력
	printf("Input data in dual linkedlist <0 to quit>\n");
	scanf_s("%d", &input);
	
	while (input != 0) {
		insert_last(head, input); //항 추가
		scanf_s("%d", &input);
	} //input으로 0이 들어오면 입력 종료

	print_dlist(head); //리스트 출력
	printf("\nPrint the list in reverse order\n"); //역순 출력
	print_reverse(head);

	free(head);
	return 0;
}
/* ---------------- func def -----------------*/
void error(const char* message) {
	fprintf(stderr, message);
	exit(1);
}
dListNode* create() { //생성
	dListNode* head = (dListNode*)malloc(sizeof(dListNode)); //헤드 노드
	head->llink = head->rlink = head; //헤드 노드 초기화

	return head; //초기화한 head 반환
}
void insert_last(dListNode* head, int num) { // 마지막에 항 추가하는 함수
	dListNode* p = (dListNode*)malloc(sizeof(dListNode)); //새로운 노드 생성
	p->num = num;

	p->llink = head->llink;
	p->rlink = head;
	head->llink->rlink = p;
	head->llink = p;
}
void print_dlist(dListNode* head) { //리스트 출력 함수
	dListNode* p = (dListNode*)malloc(sizeof(dListNode)); //새로운 노드 생성
	for (p = head->rlink; p != head->llink; p = p->rlink)
		printf("  %d  <->", p->num);
	printf("  %d", p->num);
}
void print_reverse(dListNode* head) { //역순 출력 함수
	dListNode* p = (dListNode*)malloc(sizeof(dListNode)); //새로운 노드 생성
	for (p = head->llink; p != head->rlink; p = p->llink)
		printf("  %d  <->", p->num);
	printf("  %d", p->num);
}

void printInfo(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}