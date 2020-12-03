/* 2. 이진탐색- 재귀/반복 */
#include <stdio.h>
#include <stdlib.h>
// #include <time.h> 
//#include "quick_sort.h" //퀵 정렬 헤더파일
#define SWAP(x,y,t)((t)=(x), (x)=(y), (y)=(t))
#define SIZE 100

//int list[SIZE];

/* 재귀 */
int bin_search_recursive(int list[], int key, int low, int high) {
	int mid;
	if (low <= high) { //low, high를 인자로 주며 반복
		mid = (low + high) / 2;
		if (key == list[mid]) return mid;
		else if(key < list[mid]) bin_search_recursive(list, key, low, mid - 1); //왼쪽 절반 다시 탐색
		else return bin_search_recursive(list, key, mid + 1, high); //오른쪽 절반 다시 탐색
	}
	else return -1; // when failed
}
/* 반복 */
int bin_search_iterative(int list[], int key, int low, int high) {
	int mid;
	while (low <= high) { //while로 한다!!
		mid = (low + high) / 2;
		if (key == list[mid]) return mid;
		else if (key < list[mid]) high = mid - 1; //값이 mid 아래쪽에 있으면 mid 위쪽을 버림
		else low = mid + 1; //아래를 버림
	}
	return -1; // when failed
}

int main() {
	int key, res;
	int size = 10; // int list[size]={...}로 정의가 불가...

	int list[10] = { 0,3,5,6,17,18,30,67,72, 89 };

	// rand, sort 과정 생략
	for (int i = 0; i < size; i++) {
		printf("%3d", list[i]);
	}
	printf("\n\nInput key to search: ");
	scanf_s("%d", &key);

	printf("\n< 재귀호출 결과 >\n");
	res = bin_search_recursive(list, key, 0, size);
	if (res != -1)
		printf("\n%d is found in position %d!\n", key, res);
	else printf("Search failed\n");

	printf("\n< 반복호출 결과 >\n");
	res = bin_search_iterative(list, key, 0, size);
	if (res != -1)
		printf("\n%d is found in position %d!\n", key, res);
	else printf("Search failed\n");

	return 0;
}
/* < 함수의 인자가 배열인 경우 >
	* 정의에는 list[] 또는 *list 
	* 메인에서 전달할 때는 list

* 배열 정의 시, list[변수] = {1,2,3};은 안 된다. []안에는 상수값이 들어가야 함

*/