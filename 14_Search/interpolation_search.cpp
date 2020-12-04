/* 4. 보간탐색 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quick_sort.h"
#define SIZE 100
#define INDEX_SIZE 256

typedef struct itable {
	int key;
	int index;
}itable;
itable index_list[INDEX_SIZE]; //index table

int list[SIZE];
int interpol_search(int key, int n) {
	int i, low, high;
	low = 0;
	high = n - 1;
	while ((key <= list[high]) && (key > list[low])) { //key값이 low와 high 사이에 있을 때
		i = ((float)(key - list[low]) / (list[high] - list[low]) * (high - low)) + low; //비례식 이용하여 인덱스 유추
		if (key > list[i]) low = i + 1; //만약 유추한 것보다 클 경우, 왼쪽 버림
		else if (key < list[i]) high = i - 1; //작을 경우, 오른쪽 버림
		else low = i; // 바로 맞춘 경우 low=i 하고 아래에서 low를 리턴함
	}
	if (list[low] == key) return low; // 탐색 성공
	else return -1; // 탐색 실패
}
int main() {

	int key, res;
	srand(time(NULL));
	
	for (int i = 0; i < SIZE; i++)
		list[i] = rand() % 1000; //0~999
	/* 정렬 전 */
	for (int i = 0; i < SIZE; i++) {
		if (i % 10 == 0) putchar('\n'); //개행
		printf("%4d", list[i]);
	}
	quick_sort(list, 0, SIZE);
	printf("\n\n< Sorting Result >\n"); /* 정렬 후 */
	for (int i = 0; i < SIZE; i++) {
		if (i % 10 == 0) putchar('\n');
		printf("%4d", list[i]);
	}
	printf("\n\nInput key to search: ");
	scanf_s("%d", &key);

	printf("\n< Interpolation Search Result >\n");
	res = interpol_search(key, SIZE);
	if (res != -1)
		printf("\n%d is found in position %d!\n", key, res);
	else printf("Search failed\n");

}

/*
int size = 10; // int list[size]={...}로 정의가 불가...
int list[10] = { 0,3,5,6,17,18,30,67,72, 89 };
// rand, sort 과정 생략 */