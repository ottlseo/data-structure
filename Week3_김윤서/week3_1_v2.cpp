#include <stdio.h>
#include <string.h>

void printName();
void func_recursive(char * list, int size); //거꾸로 출력하는 재귀함수

int main() {
	printName(); //정보 출력

	char X[100]; //문자 배열 선언
	int size;
	printf("Input String\n");
	gets_s(X); //입력받은 문자열을 인자로 받은 배열에 넣어주는 함수 실행
	puts("변경 전: ");
	puts(X);
	puts("변경 후: ");
	size = strlen(X);
	func_recursive(X,size); //재귀함수 호출

	return 0;
}

void func_iterative(char* list) { //반복함수
	int size = strlen(list); //문자열의 길이
	for (int i = 0; i < size; i++)
		printf("%c", *(list + size-1 - i));
}

void func_recursive(char* list, int size) { // 재귀함수
	if (size== 0) { return; }
	else {
		printf("%c", *(list + size - 1)); //가장 마지막에 있는 문자
		return func_recursive(list, size - 1);
	}
}
void printName(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}