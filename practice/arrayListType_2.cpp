#include <stdio.h>
#include <malloc.h>
#define MAX_LENGTH 100

typedef int element;
typedef struct ListNode {
	element data; //데이터
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //새로운 노드 p 생성
	p->data = value;
	p->link = head; //새로운 노드가 기존의 head를 가리킴
	head = p; //새로운 노드가 기존의 head가 됨
	return head; //새로운 head 반환
}
ListNode* insert(ListNode* head, ListNode* pre, element value) { //pre 뒤에 새로운 노드 insert
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //새로운 노드 p
	p->data = value;
	p->link = pre->link; //새로운 노드가 기존의 pre가 가리키던 노드를 가리킴
	pre->link = p; // 기존의 pre는 새로운 노드를 가리킴
	return head; //대표노드인 헤드포인터 리턴
}
ListNode* delete_first(ListNode* head) { //맨 처음 노드 삭제
	if (head == NULL) { return NULL; } //노드 없는 경우
	else {
		ListNode* removed = head; //기존의 head가 가리키던 노드를 removed가 가리키게 함
		head = head->link; //head는 기존의 head->link가 가리키던 노드를 가리킴
		free(removed); //removed 메모리 반환
		return head;
	}
}
ListNode* del(ListNode* head, ListNode* pre) { //pre가 가리키는 노드의 다음 노드를 삭제한다
	ListNode* removed = pre->link; //pre가 가리키는 노드의 다음 노드주소를 removed에 저장
	pre->link = removed->link; //pre가 가리키는 노드를 removed가 가리키던 노드로 변경
	free(removed); //removed 메모리 반환
	return head;
}
void print_list(ListNode* head) { //head부터 링크로 연결된 노드의 data를 계속 출력
	for (ListNode* p = head; p != NULL; p = p->link) //head에서부터 NULL이 되기 전까지, 
		printf("%3d ->", p->data);
	printf(" NULL\n");
}

int main() {
	ListNode* head = NULL;
	int num;
	for (int i = 0; i < 5; i++) { //리스트의 맨 앞에 0~4의 data 값을 갖는 노드를 계속 insert
		head = insert_first(head, i);
		print_list(head);
	}
	for (int i = 0; i < 5; i++) { // 리스트의 맨 앞에서 5개 노드를 계속 delete
		head = delete_first(head);
		print_list(head); //변화 출력
	}
	return 0;
}

/*
	del 좀 더 공부...
*/
