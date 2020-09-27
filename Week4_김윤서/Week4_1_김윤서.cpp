#include <stdio.h>
#include <stdlib.h>

typedef int element; //int 타입의 element 자료형 정의
typedef struct ListNode {
	element num; //사용자가 입력하는 정수
	ListNode* link; //노드 연결에 사용할 link
}ListNode;
typedef struct ListType { //리스트의 정보 포함하는 구조체- 시작위치, 종료위치, 리스트 크기...
	ListNode* head;
	ListNode* tail;
	int size;
};

void printName();
void error(const char* message);
ListType* create(void);
void printList(ListType* plist); //리스트 출력 함수
void insert_last(ListType* plist, int value); //리스트 마지막에 insert하는 함수
int search_MAX(ListType* plist);
int search_MIN(ListType* plist);

//-------------------- main ----------------------
int main() {
	printName();
	int input; //사용자가 정수 입력
	ListType* intList;
	intList = create();

	while (true) //무한반복, input이 0이면 종료
	{
		printf("Input an integer to insert <0 to quit>: ");
		scanf_s("%d", &input);
		if (input == 0) { break; } //입력이 0일 경우 반복문 빠져나간다
		else { insert_last(intList, input); } //intList 마지막에 input값을 삽입
	}
	printf("\n<List>\n");
	printList(intList); //리스트 출력

	printf("\nMax: %d\n", search_MAX(intList)); //max
	printf("\nMin: %d\n", search_MIN(intList)); //min

	free(intList);
	return 0;
}
//-------------------- 함수 정의 Area ----------------------
void error(const char* message) { //오류 메시지
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListType* create(void) { // ListType 노드 생성 (다항식 정보 포함한 노드)
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->head = NULL;
	plist->tail = NULL;
	plist->size = 0;
	return plist; //생성하고 초기화해서 반환하는 함수임
}

void insert_last(ListType* plist, int value) { //리스트 마지막에 insert하는 함수
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //구조체 p 생성(삽입할 구조체)
	
	if (p == NULL) { //메모리 할당 실패 시
		error("동적 메모리 할당 실패");
		exit(1);
	}
	p->num = value; //일단 p의 값 지정
	p->link = NULL; //링크는 일단 NULL로.

	if (plist->size == 0) { //리스트에 아무것도 없으면
		/* head에 p 연결하는 방식 */
		plist->head = plist->tail = p; //OK
	}
	else {
		plist->tail->link = p; //연결 OK
		plist->tail = p; // 마지막 항의 정보를 새 노드 주소(p)로 수정
	}
	plist->size++; //항 개수 정보 하나 증가해주기++
}
void printList(ListType* plist) {  //리스트 출력 함수
	ListNode* p = plist->head;
	for (int i=0; i< plist->size; i++) { //head에서 시작해서 끝(NULL나올때)까지 반복
		printf("%d  ", p->num);
		p = p->link;
	}
}
int search_MAX(ListType* plist) {
	int max = plist->head->num; //최댓값을 맨 처음 값으로 지정
	for (ListNode* p = plist->head; p != NULL; p = p->link) { //head에서 시작해서 끝(NULL나올때)까지 반복
		if ((p->num) > max) //max보다 현재 노드의 num이 더 크다면
			max = p->num; // p->num을 최댓값으로 지정
		else
			continue; //아니면 다음값으로 이동
	}
	return max;
}
int search_MIN(ListType* plist) {
	int min = plist->head->num; //최솟값을 맨 처음 값으로 지정
	for (ListNode* p = plist->head; p != NULL; p = p->link) { //head에서 시작해서 tail까지 반복
		if ((p->num) < min) //min보다 현재 노드의 num이 더 작다면
			min = p->num; // p->num을 최솟값으로 지정
		else
			continue; //아니면 다음값으로 이동
	}
	return min;
}


void printName(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}