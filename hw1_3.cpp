#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int num;
	ListNode* link;
}ListNode;
typedef struct ListType {
	ListNode* head;
	ListNode* tail;
	int size;
}ListType;

void printInfo();
void error(const char* message);
ListType* create();
ListType* insert_first(ListType* plist, int value);
ListType* insert_sort(ListType* plist, int num); //오름차순으로 insert
void print_list(ListType* plist);

/* ------------------ main -----------------*/
int main() {
	int input;
	ListType* mylist = create();
	printInfo(); //정보 출력

	printf("Input data to insert to linkedlist <0 to quit>\n");
	scanf_s("%d", &input);

	while (input != 0) {
		mylist = insert_sort(mylist, input);
		print_list(mylist);
		scanf_s("%d", &input);
	}
	printf("Program finished.\n");
	return 0;
}
/* ---------------- func def -----------------*/
void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListType* create() {
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->head = plist->tail = NULL;
	plist->size = 0;
	return plist;
}
ListType* insert_first(ListType* plist, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //삽입할 노드 생성
	p->num = value;
	p->link = plist->head;
	plist->head = p; //head를 p로 바꿔버린다
	return plist;
}
ListType* insert_sort(ListType* plist, int value) {
	ListNode* pre = plist->head; // 노드 생성 -반복문에 이용
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //삽입할 노드 생성
	if (p == NULL) { //메모리 할당 실패 시
		error("동적 메모리 할당 실패");
		exit(1);
	}
	p->num = value; //값 삽입
	p->link = NULL;

	if (pre == plist->tail) { //항이 없을 경우(head==tail 일 때)
		return insert_first(plist, value);
	}
	else {
		while (pre != plist->tail) { //pre가 마지막 항이 될때까지
			if (value >= (pre->num) && value <= (pre->link->num)) { //맞는 위치 찾으면, 삽입하고 반환
				p->link = pre->link;
				pre->link = p; //삽입
				return plist;
			}
			pre = pre->link; //아니면 계속 반복
		} // end of while 
		  // while문 끝났는데 리턴 안 되면 마지막 항으로 삽입
		plist->tail->link = p;
		plist->tail = p;
	}
}
void print_list(ListType* plist) {
	for (ListNode* p = plist->head; p != plist->tail; p = p->link)
		printf("%3d ->", p->num);
	printf("  NULL\n");
}
void printInfo(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}
