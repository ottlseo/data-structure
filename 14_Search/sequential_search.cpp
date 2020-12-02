/* 14주차 실습1,2 : 순차탐색 (기존/개선) */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

int list[SIZE];

/* 일반 순차탐색 */
int seq_search(int key, int low, int high) { //low, high는 시작과 끝 인덱스
	for (int i = low; i <= high; i++)
		if (list[i] == key) return i;
	return -1;
}
int seq_search2(int key, int low, int high) {
	int i;
	list[high + 1] = key;
	for (i = low; list[i] != key; i++); // 리스트의 끝인지 비교할 필요x (key와 같으면 바로 for문 종료)
	
	if (i == high + 1) return -1; // 마지막 위치까지 체크했다면 탐색 실패
	else return i;
}
int main() {
	srand(time(NULL));
	int key, res1,res2;
	for (int i = 0; i < SIZE; i++)
		list[i] = rand() % 1000; //0~999
	for (int i = 0; i < SIZE; i++) {
		if (i % 10 == 0) putchar('\n'); //개행
		printf("%4d", list[i]);
	}
	printf("\n\nInput key to search: ");
	scanf_s("%d", &key);
	res1 = seq_search(key, 0, SIZE - 1);
	res2 = seq_search2(key, 0, SIZE - 2); //키 삽입을 위해 배열의 마지막 방을 남겨두어야 함

	/* if (res1 != -1) printf("\n%d is found in position %d by sequential search 1\n", key, res1); */
	if (res2 != -1) printf("\n%d is found in position %d! (by sequential search 2)\n", key, res2);
	else printf("search failed\n");
}