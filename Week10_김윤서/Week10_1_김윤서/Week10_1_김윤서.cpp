#include <stdio.h>
#include <stdlib.h>
#define MAX 200

typedef int element;
typedef struct HeapType {
	element heap[MAX];
	int heap_size;
}HeapType;

void printInfo();
void insert_max_heap(HeapType* h, element item);
element delete_max_heap(HeapType* h);
void insert_min_heap(HeapType* h, element item);
element delete_min_heap(HeapType* h);
void print_heap(HeapType* h);

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}
void init(HeapType* h) { //heap 초기화
	h->heap_size = 0;
}

int main() {
	printInfo(); //정보 출력
	char input; // I/D/X 중에 사용자 선택
	int value; //insert/delete 시에 입력받을 값
	HeapType* max_heap = create();
	HeapType* min_heap = create();
	init(max_heap);
	init(min_heap);
	do {
		printf("* operation 선택: Insert(I) / Delete(D) / Exit(X): ");
		scanf_s("\n%c", &input);

		switch (input) {
		case'I': case'i':
			printf("Input value to Insert: ");
			scanf_s("%d", &value);
			insert_max_heap(max_heap, value); //value를 max_heap에 insert
			insert_min_heap(min_heap, value); //value를 min_heap에 insert
			printf("<Max Heap>\n");
			print_heap(max_heap);
			printf("<Min Heap>\n");
			print_heap(min_heap);
			printf("\n\n");
			break;
		case'D':case'd':
			delete_max_heap(max_heap); //max_heap에서 delete
			delete_min_heap(min_heap); //min_heap에서 delete
			printf("<Max Heap>\n");
			print_heap(max_heap);
			printf("<Min Heap>\n");
			print_heap(min_heap);
			printf("\n\n");
			break;
		case 'X':
			break;
		default:
			printf("Wrong Input\n");
			break;
		}
	} while (input != 'X'); //입력이 X이면 반복문 종료

	free(max_heap); free(min_heap);
	return 0;
}
void printInfo(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}
void insert_max_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size); // 노드 추가
	while ((i != 1) && (item > h->heap[i / 2])) { // 트리를 거슬러 올라가면서 부모 노드의 key 값과 비교
		h->heap[i] = h->heap[i / 2]; // 추가 된 노드 key값보다 작은 경우 부모노드를 downheap
		i /= 2; // 인덱스를 부모 자리로 이동
	}
	h->heap[i] = item; // 최종위치에 새로운 노드 insert

}
element delete_max_heap(HeapType* h) {
	int parent = 1, child = 2; // 두 번째 노드부터 root 노드와 비교 시작
	element item = h->heap[1]; // 삭제되는 노드(삭제 후 반환)
	element temp = h->heap[h->heap_size--]; // 말단 노드를 temp에 대입(노드 삭제 후 heap_size가 감소)
	while (child <= h->heap_size) { // 최대 말단까지 트리를 내려가면서 자식노드 key값과 temp key 비교
		if ((child < h->heap_size) && (h->heap[child] < h->heap[child + 1])) // sibling이 있을 때 둘 중 큰 값 찾기
			child++; // sibling이 비교대상 노드가 됨(subtree 선택)
		if (temp >= h->heap[child])
			break; // 자식 노드보다 신규 노드 key가 크면 위치 확정되어 반복 종료
		h->heap[parent] = h->heap[child]; // 자식 노드 key가 더 크면 parent 노드에 child 노드 복사
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp; // 확정위치(parent)에 신규노드 insert
	return item;

}
void insert_min_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);
	while ((i != 1) && (item) < h->heap[i / 2]) {
		h->heap[i] = h->heap[i / 2];
		i /= 2; //인덱스 새로운 위치(부모)로 이동
	}
	h->heap[i] = item; //최종 위치에 insert
}
element delete_min_heap(HeapType* h) {
	int parent = 1, child = 2;
	element item = h->heap[1];
	element temp = h->heap[(h->heap_size)--]; //말단노드를 temp에 대입
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child] > h->heap[child + 1]))
			child++;
		if (temp < h->heap[child])break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp; //확정 위치(parent)에 신규 노드 insert
	return item;
}
void print_heap(HeapType* h) {
	for (int i = 1; i < h->heap_size+1; i++)
		printf("%d ", h->heap[i]);
	printf("\n");
}