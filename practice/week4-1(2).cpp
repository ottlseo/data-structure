#include <stdio.h>
#include <stdlib.h>

typedef int element; //int 타입의 element 자료형 정의
typedef struct ListNode {
	element num; //사용자가 입력하는 정수
	ListNode* link; //노드 연결에 사용할 link
}ListNode;

void printName();
void printList(ListNode* head); //리스트 출력 함수
ListNode* insert_first(ListNode* head, int value); //리스트 맨 앞에 insert하는 함수
ListNode* insert_last(ListNode* head, int value); //리스트 마지막에 insert하는 함수
int search_MAX(ListNode* head);
int search_MIN(ListNode* head);

int main() {
	printName();
	int input; //사용자가 정수 입력
	//int count = 0; //
	
	ListNode* intList = (ListNode*)malloc(sizeof(ListNode)); //구조체 intList 정의
	
	printf("Input an integer to add <0 to quit>: ");
	scanf_s("%d", &input);
	intList = insert_first(intList, input); //초기값 넣어준다.

	while (input!=0) //무한반복, input이 0이면 종료
	{
		printf("Input an integer to add <0 to quit>: ");
		scanf_s("%d", &input);
		if (input == 0) { break; } //입력이 0일 경우 반복문 빠져나간다
		else {
			intList=insert_last(intList, input); //intList 마지막에 input값을 삽입
			//intList=insert_first(intList, input); //intList 마지막에 input값을 삽입
		}
	}
	printf("\n<List>\n");
	printList(intList); //리스트 출력
	
	printf("\nMax: %d\n", search_MAX(intList)); //max
	printf("\nMin: %d\n", search_MIN(intList)); //min

	return 0;
}

ListNode* insert_last(ListNode* head, element value) { //리스트 마지막에 insert하는 함수
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //구조체 p 생성(삽입할 구조체)
	ListNode* preq = head; // pre는 끝을 찾아 p와 연결할 구조체임
	ListNode* pre = NULL; // pre는 preq 바로 전 구조체

	p->num = value; //구조체 p에 value 저장
	
	/* 연결 코드 작성하기 */
	while (preq != NULL) { //preq가 끝까지 가도록
		pre = preq; //pre는 preq보다 한 단계 전 노드. preq가 NULL이 되면 pre가 마지막 노드가 된다.
		preq = preq->link;
	}
	p->link = pre->link;
	pre->link = p;

	return head;
}
void printList(ListNode* head) {  //리스트 출력 함수
	for (ListNode* p = head; p != NULL; p = p->link) //head에서 시작해서 끝(NULL나올때)까지 반복
		printf("%3d ", p->num);
	printf("\n");
}
int search_MAX(ListNode* head) {
	int max = head->num; //최댓값을 맨 처음 값으로 지정
	for (ListNode* p = head; p != NULL; p = p->link) { //head에서 시작해서 끝(NULL나올때)까지 반복
		if ((p->num) > max) //max보다 현재 노드의 num이 더 크다면
			max = p->num; // p->num을 최댓값으로 지정
		else
			continue; //아니면 다음값으로 이동
	}
	return max;
}
int search_MIN(ListNode* head) {
	int min = head->num; //최솟값을 맨 처음 값으로 지정
	for (ListNode* p = head; p != NULL; p = p->link) { //head에서 시작해서 끝(NULL나올때)까지 반복
		if ((p->num) < min) //min보다 현재 노드의 num이 더 작다면
			min = p->num; // p->num을 최솟값으로 지정
		else
			continue; //아니면 다음값으로 이동
	}
	return min;
}
ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //새로운 노드 p 생성
	p->num = value;
	p->link = head; //새로운 노드가 기존의 head를 가리킴
	head = p; //새로운 노드가 기존의 head가 됨
	return head; //새로운 head 반환
}

void printName(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}
