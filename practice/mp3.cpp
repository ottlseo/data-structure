/* week4 이중연결리스트
	-- MP3 재생 프로그램 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char element[100]; //element는 char[100]을 가지는 배열 (문자열 자료형)
typedef struct dListNode {
	element data; //element는 문자열(char 100)
	dListNode* llink;
	dListNode* rlink;
}dListNode;

dListNode* current; //현재 선택된 노드 //main밖에 정의하는 이유?-- print함수에서도 불러와야해서

void init(dListNode* phead); //이중연결리스트 초기화 함수
dListNode* dinsert(dListNode* head, const element value); //head옆에 삽입 함수, head를 반환할 것
void print_dList(dListNode* head); //출력

int main() {
	dListNode* head = (dListNode*)malloc(sizeof(dListNode));

	init(head);
	char ch;
	dinsert(head, "Memories");
	dinsert(head, "When I was your man");
	dinsert(head, "Someone like you");
	dinsert(head, "Mer"); //head 다음에 곡명 insert
	current = head->rlink; //초기 상태로는 첫 곡이 선택됨
	
	printf("[ PlayList ]\n");
	print_dList(head);

	do {
		puts("\nInput < or > or 'q':");
		scanf_s(" %c", &ch); //이전 입력 후 남은 엔터 처리 위해 %c 앞에 space 처리!!!
		switch (ch) {
		case '<':
			current = current->llink; //왼쪽으로 이동
			if (current == head) { current = current->llink; } //이동해서 head면 한 번 더 이동
			print_dList(head);
			break;
		case '>':
			current = current->rlink; //오른쪽으로 이동
			if (current == head) { current = current->rlink; } //이동해서 head면 한 번 더 이동
			print_dList(head);
			break;
		case 'q':
			break;
		default:
			puts("Wrong Input");
		} //switch end
	} while (ch != 'q'); //while이 참이면 do를 계속 반복(do-while문)
	puts("Program Finished.\n");
}
void init(dListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
	//이중연결리스트 초기화 함수 init은 이게 끝 ! 기억하기
}
dListNode* dinsert(dListNode* head, const element value) { //왜 const element로 받지,,, 문자열은 그렇게 해야되나.
	dListNode* node = (dListNode*)malloc(sizeof(dListNode));
	//node->data = value; //오류! 문자열이므로 strcpy 써야됨. 주의!!
	strcpy_s(node->data, value); //노드에 값 넣기

	node->rlink = head->rlink;
	node->llink = head;
	head->rlink->llink = node;
	head->rlink = node;
	
	return head;
}
void print_dList(dListNode* head) {
	dListNode* p = head->rlink;
	while (p != head) { //p가 다시 head가 될 때까지 반복
		if (p == current) { printf("<< %s >> : ", p->data); } //current이면 다른 형식으로 출력
		else { printf("%s : ", p->data); }
		p = p->rlink; //옆으로 계속 이동
	}
}
