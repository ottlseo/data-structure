#include <stdio.h>

void printName(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}

double iterative(int n); //반복함수
double recursive(int n); //재귀함수

int main() {
	printName(); //정보 출력

	int n; //입력받을 양의 정수
	while (true) {
		printf("양의 정수 입력: ");
		scanf_s("%d", &n); //n에 저장

		if (n <= 0) { //입력값이 0이하이면 종료
			break;
		}

		printf("Result from iterative: %.2f", (double)(iterative(n))); // 소수점 둘째자리까지 출력
		printf("\nResult from recursive: %.2f", (double)(recursive(n))); // 소수점 둘째자리까지 출력
		printf("\n\n");
	}
}

double iterative(int n) { //반복함수
	double result = 0;
	for (int i = 1; i <= n; i++) {
		result += (double)1 / i;
	}
	return result;
}
double recursive(int n) { //재귀함수
	if (n == 1) { return 1; } //n==1이면 recursive(0)-> 종료
	else {
		return (double)1 / n + recursive(n - 1); //인자만 바꿔서 자기 자신 호출
	}
}
