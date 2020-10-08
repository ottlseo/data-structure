/* 연결리스트로 구현한 스택 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct StackNode { //스택 노드 구조체
	element data; //노드니까 ㅐ열 아님 //데이터부
	struct StackNode* link; //링크
}StackNode;

typedef struct {
	StackNode* top; //스택의 top 노드 주소. top이 인덱스가 아니라, head 노드의 주소가 됨!!
}LinkedStackType;

void init(LinkedStackType* s) {
	s->top = NULL; //연결리스트 초기화 방법: head노드를 NULL로
}
void error(const char* message) {
	fprintf(stderr, message);
}
bool is_full(LinkedStackType* s) {
	return 0; //full이 될 수 없음...
}
bool is_empty(LinkedStackType* s) {
	return (s->top == NULL); //top이 NULL이면 빈스택임
}
element pop(LinkedStackType* s) {
	if (is_empty(s)) {
		error("Stack empty");
		exit(1);
	}
	else {
		StackNode* temp = s->top; //연결만 풀어주는게 아니라, free까지 해주기 위해!
		element data = temp->data; //반환할 데이터값
		s->top = s->top->link; 
		free(temp); // !!!
		return data;
	}
}
void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item; //데이터 저장
	temp->link = s->top; //새로 생성된 노드의 link가 기존의 top을 가리킴
	s->top = temp; //새로 생성된 노드가 새로운 top이 됨
}
void print_stack(LinkedStackType* s) {	
	for (StackNode* go = s->top; go!= NULL; go = go->link) {
		printf("%d -> ", go->data);
	}
	printf("NULL \n"); //마지막 링크는 NULL
}
int main() {
	LinkedStackType s; //동적 스택 헤드포인터 선언 (??)
	init(&s);
	
	for (int i = 0; i < 10; i++) {
		push(&s, i);
	}
	printf("< Stack >\n");
	print_stack(&s); // 출력

	for (int i = 0; i < 5; i++)
		pop(&s);
	printf("\n < Pop 1 >\n");
	print_stack(&s);
	for (int i = 0; i < 5; i++)
		pop(&s);
	printf("\n < Pop 2 >\n");
	print_stack(&s);

	return 0;
}