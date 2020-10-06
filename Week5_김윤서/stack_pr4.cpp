/* 괄호쌍 검사 코드 ans */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef char element;
typedef struct stack {
	element data[MAX];
	int top; //최고 원소의 인덱스
}StackType;

void init_stack(StackType* s) { //스택 초기화- 구조체 포인터를 인자로 전달받음
	s->top = -1; // top 초기상태는 -1
}
void error(const char* string) {
	fprintf(stderr, string); //에러 메시지 출력
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
bool parenth_check(char* X) { //문자열 X
	StackType* s = (StackType*)malloc(sizeof(StackType)); //스택 객체 생성
	char pop_ch, ch; //ch는 문자열 방문하며 문자 하나하나, pop_ch는 스택에서 꺼내는 문자
	init_stack(s);
	
	for (int i = 0; i < strlen(X); i++) {
		ch = X[i]; //문자를 읽어옴 - 포인터지만 배열로 문자하나에 접근
		switch (ch) {
		case '<': case '(': case '[': //여는 괄호
			push(s, ch);
			break;
		case '>': case ')': case ']': //닫는 괄호
			if (is_empty(s)) { return false; }
			else {
				pop_ch = pop(s);
				if (((pop_ch == '<') && (ch != '>')) ||
					((pop_ch == '(') && (ch != ')')) ||
					((pop_ch == '[') && (ch != ']')))
					return false; //괄호쌍 안맞는지, && 로 체크, 일일이 false 하지않고 ||로 한번에
			}
			break;
		} //end of switch
	} //end of for
	if (!is_empty(s)) { return false; } //문자열 체크 끝났는데 스택에 열린 괄호가 남아있으면 false
	return true; //위 체크에 다 걸리지 않고 내려오면 true
}

int main() {
	char str[100]; //문자열 입력받을때 배열로 !
	printf("Input expression\n");
	gets_s(str);
	if (parenth_check(str)) { printf("Correct\n"); } //통과하면 correct
	else { printf("Incorrect"); } //false면 Incorr~

	return 0;
}
