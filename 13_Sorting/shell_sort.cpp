/* Shell sort (쉘 정렬) 
	- insertion 정렬을 보완한 버전 (using gap)
	- 시간복잡도: 평균= O(n^1.5), 최악= O(n^2)
	*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

/* insertion_sort를 응용 */
void inc_insertion_sort(int list[], int first, int last, int gap) {
	int i, j, key;
	for (i = first; i <= last; i += gap) { // i<=last 인 것 주의. // i+=gap 중요!!!
		key = list[i];
		for (j = i - gap; j >= first && list[j] > key; j -= gap) // j= i-gap 중요! 
			list[j + gap] = list[j]; //반복문 끝나면
		list[j + gap] = key; // 
	}
}
void shell_sort(int list[], int n) {
	for (int gap = n / 2; gap > 0; gap /= 2) {
		if (gap % 2 == 0) { gap++; } //gap이 홀수인 게 성능 좋음
		for (int i = 0; i < gap; i++)
			inc_insertion_sort(list, i, n - 1, gap); // i, n-1 인 것 주의!!!!
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

	shell_sort(list, n); // 쉘 정렬 호출
	printf("\n\n< After Shell Sorting >\n");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]); //정렬 전 리스트 출력
	printf("\n");

	return 0;
}
