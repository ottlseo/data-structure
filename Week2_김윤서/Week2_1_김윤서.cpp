#include <stdio.h>

void bin(int n);
void printName();

int main() {
	printName();

	int n;
	printf("양의 정수 입력: ");
	scanf_s("%d", &n);
	printf("\n십진수 %d의 이진표현: ",n);
	bin(n); //재귀함수 호출
	putchar('\n');

	return 0;
}
void bin(int n) { //반복함수 정의
	int rest; //나머지
	int array[100]; //배열
	int count = 0; // 배열 크기 count

	while (true)
	{
		if (n == 0) { break; }
		array[count] = n % 2; // 배열에 2로 나눈 나머지 추가
		n /= 2; // 몫. 이걸 계속 반복하면서 n이 0일 때까지 반복

		count++; //배열 크기 ++
	}
	for (int i = count-1; i >= 0; i--) {
		printf("%d", array[i]); //뒤에서부터 출력
	}
}

void printName(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}
