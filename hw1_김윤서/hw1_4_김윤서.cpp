#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef char element;
typedef struct stack {
	element data[MAX]; //문자열
	int top; //최고층 원소의 인덱스
}StackType; //stack 구조체 생성

void printInfo();
void init_stack(StackType* s);
void error(const char* message);
bool is_full(StackType* s);
bool is_empty(StackType* s);
element pop(StackType* s);
void push(StackType* s, element item);
bool symmetric_arr(char* string); // 배열 이용
bool symmetric_stack(char* string); // 스택 이용

/* ------------------ main ------------------- */
int main() {
	printInfo(); //정보 출력
	char string[MAX]; //입력받을 문자열

	printf("알파벳으로 구성된 문자열 입력\n");
	gets_s(string);
	
	while (strcmp(string, "0") != 0) { //입력받은 문자열이 0이 아닐 경우에 계속 반복
		
		if (symmetric_arr(string)) { printf("대칭 <배열>\n"); }
		else { printf("비대칭 <배열>\n"); }
		if (symmetric_stack(string)) { printf("대칭 <스택>\n"); }
		else { printf("비대칭 <스택>\n"); }

		printf("\n알파벳으로 구성된 문자열 입력\n");
		gets_s(string);
	}
	return 0;
}
/* ------------------ func def ------------------- */
void init_stack(StackType* s) {
	s->top = -1; //스택 초기화. top 초기상태는 -1
}
void error(const char* message) { //에러 출력 함수
	fprintf(stderr, "%s\n", message);
	exit(1);
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
	if (is_empty(s)) { //스택이 비어있다면 오류 출력하고 나감
		error("stack empty");
		exit(1);
	} else { return s->data[s->top--]; }
}
void push(StackType* s, element item) {
	if (is_full(s)) { //스택 가득차 있는 경우
		error("stack Overflow");
		return;
	} else { s->data[++s->top] = item; }
}
/**/
bool symmetric_arr(char* string) { // 배열 이용
	int length = strlen(string);
	int end = (length + 1) / 2; //length가 짝수여도 7/2==3으로 
	for (int i = 0; i < end; i++) {
		if (string[i] != string[length - i-1]) { return false; } //인덱스 이용- 앞에서 i번째, 뒤에서 i번째 문자가 다르면false
	}
	return true;
}
bool symmetric_stack(char* string) { // 스택 이용
	StackType* s = (StackType*)malloc(sizeof(StackType));
	init_stack(s); //스택 초기화
	int length = strlen(string);
	int end = (length + 1) / 2; //스택에 push할 만큼의 인덱스
	int temp; //홀수개 문자열 입력 시, 중간 문자를 빼기 위함

	for (int i = 0; i < end; i++) { push(s, string[i]); }
	if (s->top != length - end-1) { temp= pop(s); } //스택의 문자 수와 남은 문자 수가 다르면 하나를 뺀다
	for (int i = end; i < length; i++) {
		if (pop(s) != string[i]) { return false; }
	} //스택에서 pop한 것과 다음 문자가 다르면 false 
	if (!is_empty(s)) { return false; } //끝났는데 스택에 남아있으면 false
	return true; //다 통과하면 true
}

void printInfo(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}