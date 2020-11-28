/* 1. selection sort 코드 */

/* 시간복잡도 = O(n^2)
// 안정성을 만족하지 않음 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) //switch 매크로

void selection_sort(int list[], int n) {
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i; //least는 인덱스, 아직 정렬되지 않은 첫번째 원소
		for (j = i + 1; j < n; j++) { //그 뒤의 값보다
			if (list[least] > list[j]) //앞의 값이 크면
				least = j; //least를 j로
		}
		SWAP(list[i], list[least], temp); //i번째와 least(j)번째 원소 switch //temp는 의미x
	}
}
int main() {
	int list[MAX_SIZE];
	int i, n;
	n = MAX_SIZE;
	srand(time(NULL));

	for (i = 0; i < n; i++)
		list[i] = rand() % 100; // 0~99
	printf("\n< Before Sorting >\n");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]); //정렬 전 리스트 출력

	selection_sort(list, n); //선택정렬 호출
	printf("\n< After Selection Sorting >\n");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]); //정렬 전 리스트 출력
	printf("\n");

	return 0;
}
