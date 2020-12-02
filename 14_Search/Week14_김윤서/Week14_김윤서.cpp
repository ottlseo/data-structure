/* 실습4. 색인순차탐색 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#define SIZE 100
//#define INDEX_SIZE 256

typedef struct itable {
	int key;
	int index;
}itable;

itable index_list[SIZE]; //index table
int list[SIZE];
int itable_size; //INDEX_SIZE 대신 전역변수 사용

/* 순차탐색 함수 */
int seq_search(int key, int low, int high) {
	int i;
	for (int i = low; i <= high; i++)
		if (list[i] == key) return i;
	return -1;
}
/* index_list 생성 및 출력 */
void create_itable(int interval) {
	itable_size = (int)((SIZE - 1) / interval); //interval값에 따라 전역변수인 itable_size를 지정
	for (int i = 0; i <= itable_size; i++) {
		index_list[i] = { list[i * interval], i * interval }; //index_list의 i번째 원소로 key와 인덱스를 insert
		printf("%2d: %4d\n", i, list[i * interval]);
	}
	printf("\n");
}
/* 색인순차탐색 함수 */
int indexed_search(int key, int n) { //찾을 키, 리스트 사이즈를 인자로 전달
	int i, low, high;
	if (key<list[0] || key>list[n - 1]) return -1; //범위 밖인 경우 종료
	for (i = 0; i < itable_size; i++)
		if (index_list[i].key <= key && index_list[i + 1].key > key) break; //범위 맞는 인덱스 찾으면 break
	if (i == itable_size) { //인덱스보다 더 큰 값일 경우
		low = index_list[i - 1].index;
		high = n;
	}
	else {
		low = index_list[i].index;
		high = index_list[i + 1].index;
	}
	printf("\n< Indexed Search 결과 >\n");
	printf("Index location: %d\n", i);
	return seq_search(key, low, high); //그 줄부터 순차탐색
}
void printInfo(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}
/* ============== main ============== */
int main() {
	printInfo();
	srand(time(NULL));
	int interval, key, res;
	for (int i = 0; i < SIZE; i++)
		list[i] = rand() % 1000;
	for (int i = 0; i < SIZE; i++) {
		if (i % 10 == 0) putchar('\n'); // 10개마다 개행
		printf("%4d", list[i]);
	}
	printf("\n\n< Sorting Result >\n");
	quick_sort(list, 0, SIZE); // quick sort 호출
	for (int i = 0; i < SIZE; i++) { // 위에서와 똑같이 출력
		if (i % 10 == 0) putchar('\n');
		printf("%4d", list[i]);
	}

	printf("\n\nInput index interval(1~100): "); // interval 입력받기
	scanf_s("%d", &interval);
	printf("\n< Index table >\n");
	create_itable(interval); // itable 생성 및 출력-

	printf("Input key to search: ");
	scanf_s("%d", &key);

	res = indexed_search(key, SIZE);
	if (res != -1)
		printf("%d is found in position %d\n", key, res);
	else printf("search failed\n");
}