#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef char element;
typedef struct stack {
	element data[MAX];
	int top; //최고층 원소의 인덱스
}StackType;

void printInfo();
void init(StackType* s); //스택 초기화 함수
void error(const char* message); //에러 출력 함수
bool is_full(StackType* s);
bool is_empty(StackType* s);
element pop(StackType* s); //pop 함수
void push(StackType* s, element value); //push 함수
void count_ch(char* string); //문자열을 인자로 전달받아 카운트하고 출력하는 함수

int main() {
	printInfo(); //정보 출력
	char string[MAX];

	printf("\n반복되는 알파벳으로 구성된 문자열 입력 <종료시 '0'입력>\n");
	gets_s(string);

	while (strcmp(string, "0") != 0) { //0이 아닐 경우
		count_ch(string);

		printf("\n\n반복되는 알파벳으로 구성된 문자열 입력 <종료시 '0'입력>\n");
		gets_s(string);
	}
	return 0;
}

void init(StackType* s) { //스택 초기화 함수
	s->top = -1;
}
void error(const char* message) {
	fprintf(stderr, message); //오류 메시지 출력 함수
}
bool is_full(StackType* s) { //꽉 찼는지 확인
	if (s->top == MAX) { return true; }
	else { return false; }
}
bool is_empty(StackType* s) { //비어있나 확인하는 함수
	if (s->top == -1) { return true; }
	else { return false; }
}
element pop(StackType* s) { // pop 함수
	if (is_empty(s)) {
		error("Stack Empty");
		exit(1);
	}
	else return (s->data[s->top--]); //top이 나중에 --, data는 배열이므로 []
}
void push(StackType* s, element value) {
	if (is_full(s)) {
		error("Stack Overflow");
		return;
	}
	else 
		s->data[++(s->top)] = value; // ++먼저, s->data의 top 값에 value 저장.
}
element peek(StackType* s) {
	if (is_empty(s)) {
		error("Stack Empty");
		exit(1);
	}
	else return (s->data[s->top]); //top 감소시키지 않고 값만 반환
}
void count_ch(char* string) {
	int count = 1; //각 문자를 카운트할 변수
	char ch;
	StackType s; //스택 변수 정의
	init(&s); // 스택 초기화
	
	push(&s, string[0]); //첫번째 문자를 push
	for (int i = 1; i < strlen(string); i++) {
		ch = string[i];
		if (ch != peek(&s)) {
			//다른 문자 나왔을 경우, 문자를 count 수와 함께 출력. 이후 스택과 카운트변수 초기화
			printf("%d%c", count, peek(&s));
			init(&s); //스택 초기화
			count = 0; //count변수 초기화
		}
		push(&s, ch);
		count++; // 변수 count ++
	}
	if (!is_empty(&s)) { printf("%d%c", count, peek(&s)); }
	// 한 문자로만 이루어진 입력(aaaaaaaaa) 들어왔을 경우에도 출력되도록
}

void printInfo(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}
