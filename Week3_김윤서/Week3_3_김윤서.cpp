#include <stdio.h>
#define MAX_SIZE 100

void printName();
void elementGeneration(int* arr, int num); //arr 원소 입력
void elementInsertion(int* arr, int num); // 새로운 element 정보 입력
void elementDeletion(int* arr, int num); //element 삭제
void elementPrint(int* arr, int num); //arr 출력

int main() {
	printName(); //Print information

	int arr[MAX_SIZE]; //배열 선언
	int choose = 1; //초기값 1로 설정
	int num; // "How many numbers?"

	printf("How many numbers? ");
	scanf_s("%d", &(num)); //처음 배열 원소 개수 입력받음

	elementGeneration(arr, num); //배열의 원소 입력받고 시작
	elementPrint(arr, num); //출력
	while (1) //무한반복, 0 입력 시 종료(if문 이용)
	{
		printf("\nChoose operation:\n");
		printf("1.Insertion	2.deletion	3.output	0.program end\n");
		scanf_s("%d", &choose); //사용자의 선택 입력받아 choose에 전달

		if (choose == 0) //0 입력할 경우
			break; //반복문 빠져나간다

		else if (choose == 1) { // 입력 1인 경우 elementInsertion 함수 호출
			elementInsertion(arr, num);
			num++; //배열 크기 ++
		}
		else if (choose == 2) { //입력 2인 경우 elementDeletion 함수 호출
			elementDeletion(arr, num);
			num--; //배열 크기 --
		}
		else if (choose == 3) { elementPrint(arr, num); } //입력 3인 경우 elementPrint 함수 호출
		else {
			printf("Wrong Input"); //0~3 외에 다른 값 입력할 경우
			continue; //반복문 계속
		}
	}
	return 0;
}
void elementGeneration(int* arr, int num) { //arr 원소 입력하는 함수

	printf("\nInput %d numbers ", num);
	for (int i = 0; i < num; i++)
		scanf_s("%d", &arr[i]); //arr배열의 각 원소로 저장
}
void elementInsertion(int* arr, int num) {
	int location, value; //삽입할 위치와 값
	printf("\nInput location and value to insert: ");
	scanf_s("%d %d", &location, &value); //입력받아 저장
	for (int i = 0; i < location + 2; i++) {
		arr[num - i] = arr[num - i-1]; //뒤로 한칸씩 밀기
	}
	arr[location-1] = value; //원하는 자리에 삽입.
}
void elementDeletion(int* arr, int num) {
	int location; //삭제할 위치
	printf("\nInput location to delete: ");
	scanf_s("%d", &location);
	for (int i = 0; i < location + 2; i++) {
		arr[location - 1 + i] = arr[location + i];
	}
}
void elementPrint(int* arr, int num) {
	printf("\nArray:	");
	for (int i = 0; i < num; i++)
		printf("%3d", arr[i]);
}

void printName(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}