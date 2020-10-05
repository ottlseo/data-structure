/* 5-2. 구조체 내의 배열 사용 예제 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef int element;
typedef struct StackType {
	element data[MAX]; //배열의 요소 (element 타입)
	int top; //top값을 멤버로 포함함. top은 최고 원소의 인덱스
}StackType;

void init_stack(StackType* s) { //스택 초기화- 구조체 포인터를 인자로 전달받음
	s->top = -1; // top 초기상태는 -1
}
void error(const char* string) {
	fprintf(stderr, string); //에러 메시지 출력
}
bool is_full(StackType* s);
bool is_empty(StackType* s);
element pop(StackType* s);
void push(StackType* s, element e);

int main() {
	StackType s; //구조체 변수 s 선언
	init_stack(&s); //구조체 초기화
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));

	return 0;
}

bool is_full(StackType* s) {
	if (s->top == MAX) { return true; } 
	else { return false; }
}
bool is_empty(StackType* s) {
	if (s->top == -1) { return true; }
	else { return false; }
}
element pop(StackType* s) {
	if (is_empty(s)) {
		error("Stack Empty");
		exit(1);
	}
	else {
		return (s->data[s->top--]); //top이 나중에 --, data는 배열이므로 []
	}
}
void push(StackType* s, element value) {
	if (is_full(s)) {
		error("Stack Overflow");
		return;
	}
	else {
		s->data[++(s->top)] = value; // ++먼저, s->data의 top 값에 value 저장.
	}
}

/*
* 인자로 포인터(*s) 받으면, 매개변수 보낼때는 무조건 "주소값"으로 보낸다
	-- *s 로 정의하면, s가 주소값/ *s가 값 이므로, (s)로 보내면 됨
	-- s 로 정의하면, s가 값/ &s가 주소값 이므로, (&s)로 보내면 됨
* 
*/
