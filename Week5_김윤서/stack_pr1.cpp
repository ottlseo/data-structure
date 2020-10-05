/* week 5. Stack 전역 기본 배열 사용 예제 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100 //스택의 최대크기 지정

typedef int element; //원소는 int로 지정
element stack[MAX_STACK_SIZE]; //1차원 int 배열

int top = -1; //전역변수 top. 초기상태는 -1
void error(const char* X); //오류 메시지 출력 함수
bool is_full();
bool is_empty();
element pop(void);
void push(element e);

int main() {
	push(1); 
	push(2);
	push(3);

	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop()); //스택 empty 상황

	return 0;
}

void error(const char* X) { //오류 메시지 출력 함수
	fprintf(stderr, X);
}
bool is_full() {
	return (top == MAX_STACK_SIZE - 1); // top이 최대면 true 반환
}
bool is_empty() {
	return (top == - 1); // top이 -1이면 true 반환
}
element pop(void) { // pop 함수
	if (is_empty()) { //비어있으면 error메시지 출력
		error("Stack Empty");
		exit(1);
	}
	else { return stack[top--]; } // top 원소값 반환, 이후 top 다음값으로 바꿔주기
}
void push(element e) {
	if (is_full()) {
		error("Stack Overflow");
		return;
	}
	else {
		stack[++top] = e; //top 증가 후 stack의 가장 위에 e 집어넣기. 
						  //top 카운트가 먼저이므로 [++top]
	}
}
