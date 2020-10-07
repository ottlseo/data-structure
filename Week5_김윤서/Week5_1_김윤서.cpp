#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef int element;
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
void dec_to_bin(StackType* s, int decimal); //십진수를 이진수로 변환해 출력하는 함수

int main() {
	int input; //입력받을 정수. 초기값 아무거나 지정
	StackType* s = (StackType*)malloc(sizeof(StackType)); //스택 포인터 생성

	printInfo(); //정보 출력
	printf("십진수 입력 <종료: 0 이하 입력>\n");
	scanf_s("%d", &input);
	
	while (input > 0) { //0이하 입력 시 종료
		dec_to_bin(s, input); // 이진수로 변환해 출력하는 함수
		printf("\n\n");

		printf("십진수 입력 <종료: 0 이하 입력>\n");
		scanf_s("%d", &input); //입력 계속 받고 0이하이면 반복문 빠져나가도록
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
void dec_to_bin(StackType *s,int decimal) {
	int r; //나머지
	init(s); //스택 생성하고 초기화
	while (decimal != 0) {
		r = decimal % 2;
		push(s, r); //스택에 나머지를 넣어준다
		decimal /= 2; //2로 나눈 몫으로 계속 반복. 몫이 0이 될때까지.
	}
	printf("이진수 표현: ");
	while (!is_empty(s)) { printf("%d", pop(s)); } //스택에 있는 숫자 모두 pop해서 출력
}
void printInfo(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}
