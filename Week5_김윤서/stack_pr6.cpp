/* week5. 후위 표기식 계산 코드 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef int element;
typedef struct StackType {
	element data[MAX]; //피연산자(정수): int 배열 --스택에 넣을것!
	int top; //최고차항의 index
}StackType;

/* ------------- stack General Function ------------- */
void init(StackType* s) { //스택 초기화 함수
	s->top = -1;
}
void error(const char* message) {
	fprintf(stderr, message); //오류 메시지 출력 함수
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
	} else {
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
int eval(char* input); //계산해서 결과값 출력하는 함수

/* ---------------------- main ---------------------- */
int main() {
	char input[MAX]; //입력 받기 - 입력받을 때 배열로!

	printf("Input postfix\n");
	gets_s(input);
	printf("=================\n[postfix]\n");
	puts(input);
	printf("[Result]\n%d", eval(input));

	return 0;
}


int eval(char* input) { //계산해서 결과값 출력하는 함수
	int first, second;
	char ch;
	StackType s;
	init(&s);
	
	/* for문 사용 */
	for (int i = 0; i < strlen(input); i++) {
		ch = input[i]; //문자 읽어오기
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
			push(&s, ch - '0'); //문자를 숫자로 바꾼 후 push
		else { //연산자일 경우
			second = pop(&s);
			first = pop(&s);

			switch (ch) {
			case '+':
				push(&s, first + second);
				break;
			case '-':
				push(&s, first - second);
				break;
			case '*':
				push(&s, first * second);
				break;
			case '/':
				push(&s, first / second);
				break;
			default:
				error("expression error\n");
			} // switch end
		} // else end
	} // for end
	return pop(&s); //최종 결과값
}
/* 
(*s) 로 정의하면 무조건 동적할당 해줘야함.
-- init 함수에 동적할당 코드 없이 top만 정해주는 거라면 그냥 s로 정의하고 &s 쓰든가,
	아니면 *s 하고 메인에서 할당해줘야 함
*/

/* //while문 ver.
* 
while (*input) { //비어있지 않으면!
		ch = *input; //첫번째 문자
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
			push(&s, ch-'0'); //문자를 숫자로 바꾼 후 push
		else { //연산자일 경우
			second = pop(&s);
			first = pop(&s);

			switch (ch) {
			case '+':
				push(&s, first + second);
				break;
			case '-':
				push(&s, first - second);
				break;
			case '*':
				push(&s, first * second);
				break;
			case '/':
				push(&s, first / second);
				break;
			default:
				error("expression error\n");
			} // switch end
		} // else end

		input++; //한칸씩 뒤로 이동
	} //while end
*/