/* ArrayListType 구현 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element; //항목 정의
typedef struct {
	element array[MAX_LIST_SIZE]; //배열- 항목 데이터
	int size; //구조체 하나에 저장된 항목들의 개수
}ArrayListType;

void error(const char* message) {
	fprintf(stderr, "%s\n", message); //표준 에러 출력
	exit(1);
}
void init(ArrayListType *A) {
	//왜 포인터로 받나? A가 구조체 전체를 가리키게/ A->size 표현도 가능
	// 그리고 값 변경 시 지속 되게. 주소에 저장되어있으므로 저장/누적 가능
	
	A->size = 0; //사이즈 0으로 .
}
int is_empty(ArrayListType* A) {
	return (A->size == 0); //비어있으면 1 반환, 아니면 0 반환. C언어에는 boolean이 없다!!!
}
int is_full(ArrayListType* A) {
	return (A->size == MAX_LIST_SIZE); //가득 차있으면 1
}
element get_element(ArrayListType* A, int pos) { //구조체와 위치 입력하면 원소 리턴
	if (pos < 0 || pos >= A->size)
		error("location error"); //포지션이 잘못 입력될 경우 에러 출력
	return A->array[pos];
}
void print_list(ArrayListType* A) {
	int i;
	for (i = 0; i < A->size; i++)
		printf("%d->", A->array[i]);
	printf("%d\n", A->array[i]); //마지막 항목 출력(화살표 x)
}
void insert_last(ArrayListType* A, element item) { //마지막에 삽입
	if (A->size >= MAX_LIST_SIZE) {
		error("list overflow");
	}
	A->array[A->size++] = item; //마지막 방에 넣고 size 증가
}
void insert(ArrayListType* A, int location, element item) {
	if (!is_full(A) && (location >= 0) && (location <= A->size)) {
		for (int i = (A->size - 1); i >= location; i--)
			A->array[i + 1] = A->array[i]; //하나씩 뒤로 밀기
		A->array[location] = item; //item 삽입
		A->size++;
	}
}
element del(ArrayListType* A, int location) {
	element item;
	if (location < 0 || location >= A->size)
		error("location error");
	item = A->array[location]; //삭제할 아이템 저장
	for (int i = location; i < (A->size - 1); i++)
		A->array[i] = A->array[i + 1]; //앞으로 밀기
	A->size--;
	return item; //지우고, 반환
}

int main(void) {
	ArrayListType list; //배열 아님! 구조체 변수
	init(&list); //list의 주소 전달. (list.size=0;)
	
	insert(&list, 0, 10);
	printf("\n0번째 위치에 10 추가"); //추가하고 size++ 됨
	print_list(&list); //리스트 출력

	insert(&list, 0, 20);
	printf("\n0번째 위치에 20 추가");
	print_list(&list);
	
	insert(&list, 0, 30);
	printf("\n0번째 위치에 30 추가");
	print_list(&list);

	insert_last(&list, 40); //맨 뒤에 40 추가~
	printf("\n맨 끝에 40 추가~~");
	print_list(&list);

	del(&list, 0); //0번째 원소 삭제
	printf("0번째 원소 삭제\n");
	print_list(&list);

	return 0;
}

/*
* 구조체 *A 로 선언하면, 전달할 때 A로
* 그냥 A로 선언하면, 전달할 때 &A로. 항상 주소값을 전달해야함!
*/
