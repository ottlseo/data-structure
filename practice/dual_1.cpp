/* 이중연결리스트 - insertion/deletion */

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct dListNode {
	element data;
	struct dListNode* llink;
	struct dListNode* rlink;
}dListNode;

void init(dListNode* phead) { //이중연결리스트 초기화
	phead->llink = phead; //자기 자신을 가리키도록
	phead->rlink = phead;
}
void dinsert(dListNode* pnode, element value) { //새로운 데이터를 기존 노드 pnode의 오른쪽에 insert
	dListNode* newnode = (dListNode*)malloc(sizeof(dListNode)); //새로운 노드 생성
	newnode->data = value;
	newnode->llink = pnode;
	newnode->rlink = pnode->rlink;
	pnode->rlink->llink = newnode;
	pnode->rlink = newnode;
}
void ddelete(dListNode* head, dListNode* removed) { //맨 앞에 있는 기존노드 removed를 delete
	if (removed == head) { return; } //공백 상태의 리스트
	removed->rlink->llink = head; //delete할 노드의 오른쪽 노드의 llink에 head를 가리킴
	head->rlink = removed->rlink;
	free(removed);
}
void print_dlist(dListNode* phead) { //이중연결리스트 출력
	dListNode* p = NULL;
	for (p = phead->rlink; p != phead; p = p->rlink) //head의 오른쪽 노드부터 하나씩 출력
		printf("%3d", p->data);
	printf("\n");
}

int main() {
	dListNode* head = (dListNode*)malloc(sizeof(dListNode)); //head 노드
	init(head); //head 노드 초기화

	printf("첫 위치에 노드 5개 순차적 추가\n");
	for (int i = 1; i < 6; i++) {
		dinsert(head, i); //0~4 head노드 오른쪽에 insert
		print_dlist(head);
	}
	printf("\n첫번째 노드 5개 순차적 삭제\n");
	print_dlist(head);
	for (int i = 1; i < 6; i++) {
		ddelete(head, head->rlink); //head노드의 오른쪽 노드를 하나씩 삭제
		print_dlist(head);
	}
	free(head);
	return 0;
}