#pragma once
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

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
