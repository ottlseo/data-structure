#include <stdio.h>
#include <malloc.h>
#define MAX_LENGTH 100

typedef int element;
typedef struct ListNode {
	element data; //데이터
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value);
void print_list(ListNode* head) { //head부터 링크로 연결된 노드의 data를 계속 출력
	for (ListNode* p = head; p != NULL; p = p->link) //head에서부터 NULL이 되기 전까지, 
		printf("%3d ->", p->data);
	printf(" NULL\n");
}
ListNode* search_list(ListNode* head, element value) { //value값이 리스트에 있는지 탐색
	ListNode* p = NULL;
	for (p = head; p != NULL; p = p->link) {
		if (p->data == value) { return p; } //일치하는 경우, p 리턴
	}
	return NULL; //search 실패
}

ListNode* concat_list(ListNode* headA, ListNode* headB) { //두개의 리스트를 하나로 합침
	if (headA == NULL) { return headB; } //A가 NULL일 경우 합치면 B가 됨
	else if (headB == NULL) { return headA; }

	ListNode* p = headA; //p가 첫번째 리스트를 가리킴(화살표)
	while (p->link != NULL) //다음 노드가 있을 경우에 계속 반복
	{
		p = p->link; //계속 이어줌
	}
	p->link = headB; //마지막 p->link와 B 연결
	return headA;
}

ListNode* reverse_list(ListNode* head) { //리스트를 역순으로 재연결
	ListNode* p, * q, * r;
	p = head; //p는 처음 노드부터 계속 다음 노드로 이동
	q = r = NULL; //q는 p 뒤에서 노드의 link를 "이전 노드주소 r"로 변경
	while (p != NULL) { //p가 NULL이면 p를 뒤따르는 q가 주소를 변경하므로 new head가 됨.
		r = q; // r: 이전 노드 주소
		q = p; // q가 다음 노드로 이동하기 전에 q에 주소를 복사 (q도 p 뒤에서 한 칸씩 이동함)
		p = p->link; //다음 노드로 이동하는 코드
		q->link = r; //p가 이동하기 전 노드의 link값에 그 전 노드주소 r 대입 (link 방향 반대로)
	}
	return q; // p는 NULL이 돼버리고 q가 마지막 노드의 주소, 즉 새로운 head값을 가짐
}

int main() {
	ListNode* head = NULL;
	int num;
	printf("[List A ]\n");
	for (int i=0; i<5; i++){
		head = insert_first(head, i);
		print_list(head);
	}
	printf("\n< SEARCH >\n찾을 값을 입력하세요: ");
	scanf_s("%d",&num); //찾을 값
	if (search_list(head, num) != NULL) //search한 결과가 NULL이 아니면
		printf("List A에서 %d 찾음\n", num);
	else
		printf("List A에서 %d 찾지 못함\n", num);

	ListNode* headB = NULL;
	printf("\n[ List B ]\n");
	for (int i = 6; i < 10; i++) {
		headB = insert_first(headB, i); //B 내용 6~9로 채우기
		print_list(headB); //B 출력
	}
	printf("\n< CONCAT > : A와 B 연결\n");
	head = concat_list(headB, head); //두 리스트를 연결
	print_list(head); //연결한 결과

	printf("\n< REVERSE > : A 역순정렬\n");
	head = reverse_list(head);
	print_list(head);

	return 0;
}

// ------------------- 
ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //새로운 노드 p 생성
	p->data = value;
	p->link = head; //새로운 노드가 기존의 head를 가리킴
	head = p; //새로운 노드가 기존의 head가 됨
	return head; //새로운 head 반환
}
