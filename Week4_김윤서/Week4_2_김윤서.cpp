/* Week4_2_김윤서 */
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct dListNode {
	element data; // 정수 입력 받아 저장
	dListNode* llink; // left
	dListNode* rlink; // right
}dListNode;

void printName();
void init(dListNode* phead);
void dinsert(dListNode* head, element value); //head 정보 인자 전달하면, 헤드 뒤에 노드 삽입
void ddelete(dListNode* head, dListNode* removed);
void print_dlist(dListNode* phead);
dListNode* search_dlist(dListNode* head, element value); //값 찾아서 주소값 반환

int main() {
	printName(); //정보 출력
	int input;
	int choose; //number to SEARCH and DELETE
	dListNode* head = (dListNode*)malloc(sizeof(dListNode)); //intLIst 정의
	dListNode* search; //검색결과를 담아 delete의 인자로 전달할 노드

	init(head); //head 노드 초기화!!!!!!!
	while (true) //insert
	{
		printf("Input an Integer to add <0 to quit>: ");
		scanf_s("%d", &input);
		if (input == 0) { break; } //입력값 0일 경우 break
		else {
			dinsert(head, input); //insert
			continue;
		}
	}
	printf("\n<LIST>\n");
	print_dlist(head); //intList 출력
	printf("\nInput a number to SEARCH and DELETE: ");
	scanf_s("%d", &choose); // 검색해서 지울 값을 입력받음

	search = search_dlist(head, choose); //값이 있는지 없는지, 있으면 그 주소를 변수에 저장
	if (search == NULL) { printf("%d is not in the LIST\n",choose); } //search에 없을 경우
	else {
		ddelete(head, search); //search를 전달해 노드를 삭제한다
		printf("%d is found and deleted\n", choose);
	}
	printf("<LIST>\n");
	print_dlist(head); //intList 출력

	return 0;
}
void init(dListNode* phead) { //이중연결리스트 초기화
	phead->rlink = phead;
	phead->llink = phead; //왼-오 링크가 자기 자신 가리키게...
}
void dinsert(dListNode* head, element value) { //새로운 데이터를 head의 오른쪽에 insert
	dListNode* newnode = (dListNode*)malloc(sizeof(dListNode)); //새로운 노드 생성
	newnode->data = value; //newnode에 데이터 넣기

	newnode->llink = head;
	newnode->rlink = head->rlink;
	head->rlink->llink = newnode;
	head->rlink = newnode;
}
void ddelete(dListNode* head, dListNode* removed) { //맨 앞에 있는 기존노드 removed를 delete
	if (removed == head) { return; } //공백 상태의 리스트: 지울 것 없으므로 그냥 리턴
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}
void print_dlist(dListNode* phead) { //이중연결리스트 출력
	dListNode* p = phead->rlink;
	while (p != phead) {
		printf("%3d", p->data);
		p = p->rlink;
	}
	/*
	dListNode* p = NULL;
	for (p = phead->rlink; p != phead; p = p->rlink) //head의 오른쪽 노드부터 하나씩 출력
		printf("%3d", p->data);
	*/
	printf("\n");
}
dListNode* search_dlist(dListNode* head, element value) {
	// 찾으면 해당 노드를, 없으면 NULL 반환
	dListNode* p = head->rlink; // p 생성- head의 다음 노드부터.
	while (p!=head) //p가 head로 돌아오면 반복문 종료
	{
		if ((p->data) == value) { return p; }
		p = p->rlink; // 다음 노드로 이동
	}
	return NULL; //없을 경우 NULL 반환
}
void printName(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}

/* < 이중연결리스트 주의할 점 >
* void init() 함수로 꼭꼭꼭 초기화 해줄 것
* insert 함수에는 비어있을 경우를 처리해줄 필요 없다 (if(head==NULL){} 할 필요 XX)
* insert 함수에서는 그냥 4줄의 연결코드만 작성해주면 됨!
* for문/while문의 종료 조건은 p!=head; //head로 다시 돌아오면 종료
*/