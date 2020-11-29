/* 2. insertion sort (삽입 정렬)
	: (비교) - (이동1) - (이동2) 의 순서로 진행
	- for(j=i-1; ...; j--) 이 "비교" 부분에서 효율성 저하 (n-1 + n-2 + ... + 1 = O(n^2) )
	- 최선= O(n), 최악= O(n^2) 
	- 안정된 정렬 방법
	*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

void insertion_sort(int list[], int n) {
	int i, j, key;
	for (i = 1; i < n; i++) { //0번째 원소는 정렬되었다고 가정!! (1번부터 하는거 주의)
		key = list[i];  // i번째 원소가 key

		for (j = i - 1; j >= 0 && list[j] > key; j--) //비교하는 부분. // j-- 중요
			list[j + 1] = list[j]; // (key가 1일 때,) 3 5 5 8 10 이런 식으로 되도록.  /* 이동1 */
			/*이걸 계속 반복. j<0이거나 list[j]가 key보다 작은 값일 때까지*/

		list[j + 1] = key; // 반복문 끝난 위치에 key 삽입  /* 이동2 */
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

	insertion_sort(list, n); //삽입정렬 호출
	printf("\n\n< After Selection Sorting >\n");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]); //정렬 전 리스트 출력
	printf("\n");

	return 0;
}
