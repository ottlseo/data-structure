/* 연결리스트 (단어 연결하기) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[10]; //member가 문자배열인 구조체
}element; //element라는 새로운 자료형 생성

typedef struct ListNode {
	element data; //문자열
	struct ListNode* link; //연결리스트의 link
}ListNode;

ListNode* insert_first(ListNode* head, element value); //맨 앞에 삽입 함수
ListNode* insert(ListNode* head, element value, int location); //원하는 위치에 삽입 함수
void print(ListNode* head); //head로부터 link로 연결된 노드의 data를 계속 출력

int main() {
	ListNode* head = NULL;
	element data;
	
	strcpy_s(data.name, "Apple"); //data리스트의 맨 앞에 "Apple" insert
	head = insert_first(head, data); //head 리스트에 data 삽입
	print(head);

	strcpy_s(data.name, "Banana");
	head = insert_first(head, data);
	print(head);

	strcpy_s(data.name, "Orange");
	head = insert_first(head, data);
	print(head);

	return 0;
}

//함수 정의 Area --------------------------------------
ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //새로운 노드 p 생성
	p->data = value;

	p->link = head; 
	head = p; //head를 p로 바꿔버린다고 생각하기

	/* 내가 쓴 코드
	p->link = head->link;
	head->link = p;
	// 이렇게 하면 안 되나??? ---안 됨. insert 코드임 */

	return head;
}
void print(ListNode* head) { //head로부터 link로 연결된 노드의 data를 계속 출력
	ListNode* p = NULL;
	for (p = head; p != NULL; p = p->link) //반복문 코드
		printf("%s ->", p->data.name);
	printf(" NULL\n");
}

// 내가 쓴 insert 코드------ 나중에 Review 하기
// ppt에는 location을 받지 않고, 이전 위치 pre를 따로 받았다
ListNode* insert(ListNode* head, element value, int location) { //원하는 위치에 삽입 함수
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //새로운 노드 p 생성
	ListNode* pre = head; //
	for (int i = 0; i < location-1; i++) {
		pre = pre->link; //location 이전 위치로 pre 이동하기
	}
	p->data = value;
	p->link = pre->link;
	pre->link = p;

	return head;
}