#include <stdio.h>

void func_self(int n);
void func_repeat(int n);
void printName();

int main() {
	
	printName();

	int n;
	printf("양의 정수 입력: ");
	scanf_s("%d", &n);
	printf("\n반복함수 호출: ");
	func_repeat(n); // 반복함수
	printf("\n재귀함수 호출: ");
	func_self(n); // 재귀함수

	return 0;
}

void func_self(int n) { //재귀함수, 최종값을 출력하는 형태이므로 void
	if (n < 0) { return; } // 0 출력하면 끝남
	else
	{
		printf("%d ", n);
		return func_self(n - 1); //재귀함수
	}
}
void func_repeat(int n) { //반복함수, 최종값을 출력하는 형태이므로 void
	for (int i = n; i >= 0; i--) {
		printf("%d ", i);
	}
}
void printName(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}
