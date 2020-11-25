/* quick sort */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))

int list[MAX_SIZE];
int n;

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
void quick_sort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}
int main() {
	int i;
	n = MAX_SIZE;
	
	srand(time(NULL));
	printf("< Before Sorting >\n");
	for (i = 0; i < n; i++){
		list[i] = rand() % 100; //난수 생성 및 출력
		printf("%d ", list[i]);
	}

	quick_sort(list, 0, n - 1); //퀵 정렬 호출
	printf("\n\n< After Sorting >\n");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]); //프린트

	printf("\n");
	return 0;
}