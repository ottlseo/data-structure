#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

void printInfo(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}
int partition(int list[], int left, int right) {
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1; //인덱스
	pivot = list[left];
	do {
		do { low++; } while (list[low] < pivot); // low는 피봇보다 항상 작아야 하므로. -> 더 큰 값이면 ++을 멈춘다
		do { high--; } while (list[high] > pivot);
		if (low < high) { SWAP(list[low], list[high], temp); }
		
	} while (low < high);

	//만약 high > low가 되면,
	SWAP(list[left], list[high], temp); //high와 피봇의 위치 바꾸기
	return high; //피봇의 위치 반환
}
void quick_sort(int list[], int n, int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);

		printf("\n* pivot: %d\n", list[q]); //피봇의 값 출력
		for (int i = 0; i < n; i++)
			printf("%d ", list[i]);
		printf("\nleft size: %d	right size: %d\n", q - left, right - q); //left,right 사이즈 출력

		quick_sort(list, n, left, q - 1); //재귀적으로 left side 정렬
		quick_sort(list, n, q + 1, right); // right side도 정렬
	}
}

int main() {
	printInfo(); //정보 출력

	int i, n;
	printf("Input size of list<1~10>: ");
	scanf_s("%d", &n); //사이즈를 입력받아 n에 저장
	
	int* list = (int*)malloc(sizeof(int) * n); //크기가 정해지지 않았으므로, 동적 할당으로 배열 생성
	printf("Input %d numbers in the list\n", n);
	for (int i = 0; i < n; i++) { scanf_s("%d", &list[i]); } //n개의 정수 입력 받기

	printf("\n< Before Sorting >\n");
	for (int i = 0; i < n; i++) { printf("%d ", list[i]); } //before sorting 리스트 먼저 출력
	printf("\n");

	quick_sort(list, n, 0, n - 1); //퀵 정렬 호출 --단계별 출력도 여기서 일어남

	printf("\n\n< After Quick Sorting >\n");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]); //프린트

	printf("\n");

	free(list); //동적할당한 리스트를 풀어준다
	return 0;
}