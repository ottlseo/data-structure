#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 50
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int partition1(int list[], int left, int right) {
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1; //인덱스
	pivot = list[left];
	printf("* pivot: %d\n", pivot); // pivot 값 출력
	do {
		do { low++; } while (list[low] < pivot); // low는 피봇보다 항상 작아야 하므로. -> 더 큰 값이면 ++을 멈춘다
		do { high--; } while (list[high] > pivot);

		if (low < high) { SWAP(list[low], list[high], temp); }
	} while (low < high);

	//만약 high > low가 되면,
	SWAP(list[left], list[high], temp); //high와 피봇의 위치 바꾸기
	return high; //피봇의 위치 반환
}
void quick_sort1(int list[], int left, int right) {
	if (left < right) {
		int p = partition1(list, left, right); //partition1 호출
		quick_sort1(list, left, p - 1); // 피봇 전까지 재귀호출
		quick_sort1(list, p + 1, right); //피봇 뒤부터 끝까지 재귀호출
	}
}
int median(int left, int right) { // left와 right 위치 받아서 가운데 위치값(median)을 구하는 함수
	return (left + (right - left) / 2);
}
int partition2(int list[], int left, int right) { // median of three의 값이 pivot이 되도록 설정
	int mid = median(left, right); //중간 값 구하기
	int pivot = list[mid]; // median의 값을 pivot으로
	printf("* pivot: %d\n", pivot); // pivot 값 출력
	left = mid; // left값은 mid값으로 설정
	int temp, low, high;
	low = left;
	high = right + 1;
	do {
		do { low++; } while (list[low] < pivot); // low는 피봇보다 항상 작아야 하므로. -> 더 큰 값이면 ++을 멈춘다
		do { high--; } while (list[high] > pivot);

		if (low < high) { SWAP(list[low], list[high], temp); }
	} while (low < high);

	//만약 high > low가 되면,
	SWAP(list[left], list[high], temp); //high와 피봇의 위치 바꾸기
	return high; //피봇의 위치 반환
}
void quick_sort2(int list[], int left, int right) {
	if (left < right) {
		int p = partition2(list, left, right); // partition2 호출해서 pivot 찾기
		quick_sort2(list, left, p - 1); // 피봇 전까지 재귀호출
		quick_sort2(list, p + 1, right); //피봇 뒤부터 끝까지 재귀호출
	}
}
void printInfo(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}
int main(void) {
	printInfo(); //정보 출력

	int i, input;
	int list[MAX_SIZE];

	printf("Input size of list(1~50): ");
	scanf_s("%d", &input);
	printf("Input %d numbers in the list\n", input);

	for (i = 0; i < input; i++)
		scanf_s("%d", &list[i]); // 리스트에 넣을 값 입력받음
	printf("\n<< 정렬 이전 상태 >>\n");
	for (i = 0; i < input; i++)
		printf("%2d ", list[i]); // 정렬 전 출력
	printf("\n");

	printf("< Quick Sorting >\n");
	quick_sort1(list, 0, input - 1); // quick sort 1 실행
	printf("\n< Result >\n");
	for (i = 0; i < input; i++)
		printf("%2d ", list[i]); //출력
	printf("\n");

	printf("\n< Quick Sorting <Median of three> >\n");
	quick_sort2(list, 0, input - 1); // quick sort 2 실행
	printf("\n< Result >\n");
	for (i = 0; i < input; i++)
		printf("%2d ", list[i]); // 정렬 후 출력
	printf("\n");

	return 0;
}
