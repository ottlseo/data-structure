#include <stdio.h>
#include <stdlib.h>
#include <math.h> //pow 함수 사용하기 위한 헤더

typedef struct ListNode {
	int coef; //계수
	int expon; //차수(x^)
	struct ListNode* link; // 노드
}ListNode;
typedef struct ListType { //다항식의 정보 나타내는 노드
	int size; //다항식의 항 개수
	ListNode* head;
	ListNode* tail;
}ListType;

void printInfo();
void error(const char* message);
void init(ListNode* p); //노드 한 개 초기화- 각 항을 추가할 때마다 초기화해서 정보 저장
ListType* create(); //ListType 노드 생성 (다항식 정보 초기화)
void insert_last(ListType* plist, int coef, int expon); //새로운 항 추가
void print_poly(ListType* plist); //다항식 출력
int poly_result(ListType* plist, int x); // x값 넣었을 때 함수값 계산해서 반환

/* ---------------- main ----------------- */
int main() {
	printInfo(); //정보 출력
	int coef, expon; //입력받을 계수, 차수
	int x; //입력받을 x 값
	ListType* poly = create(); //새로운 poly 생성

	printf("Input coef and exponent of polynomial <마지막항: exponent를 0으로 입력>\n");
	scanf_s("%d %d", &coef, &expon);
	insert_last(poly, coef, expon); // 다항식에 

	while (expon != 0) { //마지막항(expon이 0) 입력 전까지 반복
		scanf_s("%d %d", &coef, &expon);
		insert_last(poly, coef, expon); //항 추가
	}
	printf("\n< Polynomial >\n"); //다항식 출력
	print_poly(poly);
	
	printf("\nInput the value x: ");
	scanf_s("%d", &x);
	printf("\nResult of polynomial with x: %d\n", poly_result(poly, x)); //x값 넣어서 계산해서 결과값 출력
	
	free(poly); //동적할당한 poly 풀어줌
	return 0;
}
/* ---------------- function def ----------------- */
void error(const char* message) {
	fprintf(stderr, message);
	exit(1);
}
ListType* create() { //ListType 노드 생성 (다항식 정보 초기화)
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->head = NULL;
	plist->tail = NULL;
	plist->size = 0; //다항식 정보 초기화
	return plist;
}
void insert_last(ListType* plist, int coef, int expon) { //새로운 항 추가
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //추가할 항
	if (p == NULL) { //메모리 할당 실패 시
		error("동적 메모리 할당 실패");
		exit(1);
	}
	p->coef = coef;
	p->expon = expon; //계수와 차수값 넣어준다
	p->link = NULL;

	if (plist->size == 0) { plist->head = plist->tail = p; } //첫 항일 경우
	else { 
		plist->tail->link = p; //마지막 항과 연결
		plist->tail = p; //p를 마지막항으로 지정
	}
	plist->size++; //사이즈 ++
}
void print_poly(ListType* plist) {
	ListNode* p = NULL;
	for (p = plist->head; p != plist->tail;p=p->link) //마지막항 전까지 모든 항을 방문하도록
		printf("%dx^%d + ", p->coef, p->expon);
	printf("%dx^%d\n", p->coef, p->expon); //마지막 항은 +없이 출력
}
int poly_result(ListType* plist, int x) {
	int result = 0;
	ListNode* p = plist->head;
	for (int i = 0; i < plist->size; i++) {
		result += (int)pow((double)x, (double)(p->expon)) * (p->coef); //제곱 계산해주는 pow함수 이용
		p = p->link; //다음항으로 이동
	}
	return result;
}

void printInfo(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}