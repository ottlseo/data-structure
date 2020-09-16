#include <stdio.h>
#include <string.h>

void printName();
void func_recursive(char* list); //거꾸로 출력하는 재귀함수

int main() {
	printName(); //정보 출력

	char X[100]; //문자 배열 선언
	printf("Input String\n");
	gets_s(X); //입력받은 문자열을 인자로 받은 배열에 넣어주는 함수 실행
	puts("변경 전: ");
	puts(X);
	puts("변경 후: ");
	func_recursive(X); //재귀함수 호출

	return 0;
}

void func_recursive(char* list) { // 재귀함수
	int size = strlen(list); //문자열의 길이

	if (*list == '\0') { return; } //문자열의 끝인 널문자를 만나면 종료
	else {
		func_recursive(list + 1); //다음 문자를 부르며 자기자신 호출
		printf("%c", *(list)); //맨 첫 글자 - 위의 재귀가 모두 돌아간 후 제일 마지막에 출력됨
	}
}
void printName(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}