#include <stdio.h>
#include <stdlib.h>

//다항식 항마다 생성되는 노드
typedef struct ListNode {
	int coef; //계수
	int expon; //차수
	struct ListNode* link; //노드(다음 연결리스트 주소)
}ListNode;

// 연결 리스트 헤더
typedef struct ListType { // 다항식의 정보 포함하는 노드
	int size; //다항식의 항 개수
	ListNode* head; //다항식 처음 노드 주소. 노드(ListNode)를 멤버로 가짐
	ListNode* tail; //다항식 마지막 노드 주소
}ListType;

void error(const char* message) { //오류 메시지
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListType* create(void) { // ListType 노드 생성 (다항식 정보 포함한 노드)
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->head = NULL;
	plist->tail = NULL;
	plist->size = 0;
	return plist; //생성하고 초기화해서 반환하는 함수임
}
void insert_last(ListType* plist, int coef, int expon) { //리스트 마지막에 항 추가, head,tail 활용해서
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode)); //추가할 노드 생성

	//메모리할당 실패 시
	if (temp == NULL) { error("memory allocation error\n"); } 

	//노드의 계수, 차수 대입
	temp->coef = coef; 
	temp->expon = expon;
	temp->link = NULL; //마지막에 추가하므로 링크는 NULL;
	
	if (plist->tail == NULL) //plist가 빈 리스트일 경우
		plist->head = plist->tail = temp; //처음이자 끝인 노드 temp
	else { //기존에 노드 있으면
		plist->tail->link = temp; //가장 마지막에 temp 추가
		plist->tail = temp; //마지막 항의 정보를 새 노드 주소(temp)로 수정
	}
	plist->size++; //항 개수 정보 하나 증가해주기++
}

void poly_print(ListType* plist) {
	ListNode* node = plist->head; //다항식의 처음 원소(의 주소)
	
	for (int i = 0; i < plist->size - 1; i++) {
		printf("%dx^%d + ", node->coef, node->expon);
		node = node->link;
	}
	printf("%dx^%d \n", node->coef, node->expon); //마지막 항 출력

	/* 참고. 모든 항 방문할 때, for문 대신 while(node!=NULL){} 써도 됨 */
}
void poly_add(ListType* list1, ListType* list2, ListType* result) { // (1)+(2) = (result)
	ListNode* p1, *p2;
	p1 = list1->head; //list1 시작 주소
	p2 = list2->head;
	int sum;

	while (p1 && p2) { //두 다항식 모두에 "항이 남아있는동안" //이렇게 표현함!
		
		if (p1->expon > p2->expon) { //[list 1] 항의 차수가 더 큰 경우
			insert_last(result, p1->coef, p1->expon); //result 리스트에 항 추가(p1만.)
			p1 = p1->link;
			//p1만 이동(이제 head가 아님, 점점 이동)
			//p2는 제자리- 계속 비교해서 큰 것만 추가하는 방식임
		}
		else if (p1->expon == p2->expon) { //차수가 동일할 경우 --> 더한다
			sum = p1->coef + p2->coef;
			if (sum != 0) { insert_last(result, sum, p1->expon); }
			p1 = p1->link;
			p2 = p2->link; //둘다 다음으로 이동
		}
		else { //list1의 차수 < list2의 차수
			insert_last(result, p2->coef, p2->expon);
			p2 = p2->link;
		}
	}
	while (p1) { //위의 while에서 나왔을 때, p1에만 항이 남아있으면
		insert_last(result, p1->coef, p1->expon); //남아있는 모든 항 그대로 result에 복사
		p1 = p1->link;
	}
	while (p2) { //p2에만 항이 남아있으면
		insert_last(result, p2->coef, p2->expon); //남아있는 모든 항 그대로 result에 복사
		p2 = p2->link;
	}
}

// ---------------- main --------------------
int main() {
	ListType* list1, * list2, * result;

	list1 = create(); //다항식 생성 및 초기화
	list2 = create();
	result = create();

	// list1
	insert_last(list1, 3, 12);
	insert_last(list1, 2, 8);
	insert_last(list1, 13, 0); 

	// list2
	insert_last(list2, 5, 8);
	insert_last(list2, 1, 7);
	insert_last(list2, 5, 3);
	insert_last(list2, 13, 0);

	printf("< Poly 1 >\n");
	poly_print(list1);
	printf("< Poly 2 >\n");
	poly_print(list2);

	poly_add(list1, list2, result); //더해주기
	printf("\n< Poly1 + Poly2 >\n");
	poly_print(result);

	free(list1); //동적메모리 할당한 것 풀어주기
	free(list2);
	free(result);
	return 0;
}