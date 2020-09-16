#include <stdio.h>
#define ROWS 4
#define COLS 3

void printName(void); // 정보 출력
void matrixInput(int M[ROWS][COLS]); //행렬로 저장하는 함수
void matrixPrint(int M[ROWS][COLS]); //행렬을 출력
void matrixAdd(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS]); //두 행렬을 더해 C에 저장하는 함수

int main() {
	printName();

	int A[ROWS][COLS], B[ROWS][COLS], C[ROWS][COLS];
	printf("Input values for %dX%d matrix A\n", ROWS, COLS); //4x3 행렬 A입력
	matrixInput(A);
	printf("Input values for %dX%d matrix B\n", ROWS, COLS); //4x3 행렬 B입력
	matrixInput(B);
	puts("< A >");
	matrixPrint(A);
	puts("\n");
	puts("< B >");
	matrixPrint(B);
	puts("\n");
	puts("< A+B >");
	matrixAdd(A, B, C);
	matrixPrint(C);

	return 0;
}
void matrixInput(int M[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) { 
		for (int j = 0; j < COLS; j++) // 중첩 반복문 이용, 
			scanf_s("%d", &M[i][j]); //scanf로 받은 숫자를 [i][j]에 순차적으로 넣기
	}
}
void matrixPrint(int M[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("%3d", M[i][j]); // %3d로 간격 띄워주기, 순차적으로 출력
		}
		printf("\n"); //row 바뀔때마다 줄바꿈
	}
}
void matrixAdd(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			C[i][j] = A[i][j] + B[i][j]; // A,B의 같은 자리 원소들을 C에 저장.
			//배열 A,B,C 모두 포인터(주소값)이므로 리턴할 필요없이 바로 저장 ok
		}
	}
}
void printName(void) { //이름 출력
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}

