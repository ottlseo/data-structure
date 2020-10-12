#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int num;
	ListNode* link;
}ListNode;

void printInfo();
void error(const char* message);
ListNode* insert_first(ListNode* plist, int value); //맨앞에 삽입
ListNode* insert(ListNode* head, ListNode* pre, int value); //특정 위치 삽입
ListNode* insert_sort(ListNode* plist, int num); //오름차순으로 insert
void print_list(ListNode* plist); //리스트 출력 함수

/* ------------------ main -----------------*/
int main() {
	printInfo(); //정보 출력

	int input;
	ListNode* head = NULL; //연결리스트 생성

	printf("Input data to insert to linkedlist <0 to quit>\n");
	scanf_s("%d", &input);
	
	while (input != 0) { //오름차순으로 넣기
		head = insert_sort(head, input);
		print_list(head);
		scanf_s("%d", &input);
	} // 0넣으면 종료
	
	printf("Program finished.\n");
	return 0;
}
/* ---------------- func def ----------------- */
void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode* head, int value) { //맨 앞에 넣기
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //삽입할 노드 생성
	if (p == NULL) { //메모리 할당 실패 시
		error("동적 메모리 할당 실패");
		exit(1);
	}
	p->num = value;
	p->link = head; // p->link가 현재 헤드 가리키게
	head = p; //head포인터가 가리키는 걸 p로 변경
	return head;
}
ListNode* insert(ListNode* head, ListNode* pre, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //삽입할 노드 생성
	if (p == NULL) { //메모리 할당 실패 시
		error("동적 메모리 할당 실패");
		exit(1);
	}
	p->num = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}
ListNode* insert_sort(ListNode* head, int value) {
	if (head == NULL) { return insert_first(head, value); }  //빈 리스트일 때.
	else if (head->link == NULL) { //노드가 1개일 때.
		ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //삽입할 노드 생성
		if (value >= head->num) { //더 큰 값이면 헤드 뒤에 삽입
			p->num = value; //값 삽입
			head->link = p;
			return head;
		} else { return insert_first(head, value); } //더 작은 값이면 맨 앞에.
	}
	ListNode* pre = head; // 노드 생성 -반복문에 이용
	if (value <= (head->num)) { return insert_first(head, value); } //가장 작을 경우.
	while (pre->link != NULL) { //pre는 head에서부터 끝까지
		
		if (value >= (pre->num) && value <= (pre->link->num)) { //맞는 위치 찾으면, 삽입하고 반환
			return insert(head, pre, value);
		}
		pre = pre->link; //반복 조건
	} //end of while
	return insert(head, pre, value); // while문 끝났는데 리턴 안 되면 마지막 항으로 삽입
}
void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
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