#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 
#define TABLE_SIZE 7 // M

typedef struct element {
	int key;
}element;

struct list {
	element item;
	struct list* link;
};

struct list* hash_table[TABLE_SIZE]; // item과 link로 구성된 포인터의 배열

int hash_function(int key) {
	return key % TABLE_SIZE; //modulo 연산 사용한 해시함수
}
void hash_chain_add(element item, struct list* ht[]) {
	int hash_value = hash_function(item.key); //해시밸류는 해시함수값

	struct list* ptr; //새로운 노드
	struct list * node = ht[hash_value], * node_before = NULL; // 루트 노드node와 그 뒤에 위치하는 before노드
	
	for (; node; node_before = node, node = node->link) { //해당 위치의 노드 검색
		if (node->item.key == item.key) { //같은 값이 들어있으면 중복-
			fprintf(stderr, "%d is already stored\n", item.key);
			return;
		}
	}
	ptr = (struct list*)malloc(sizeof(struct list));
	ptr->item = item;
	ptr->link = NULL;
	if (node_before)
		node_before->link = ptr; //마지막 위치에 추가
	else //해당 위치에 노드가 없으므로
		ht[hash_value] = ptr; // 첫 노드로 연결	
}
void hash_chain_search(element item, struct list* ht[]) {
	struct list* node;
	int hash_value = hash_function(item.key); //찾으려는 value 구하기
	for (node = ht[hash_value]; node; node = node->link) //해당 해시테이블로 가서 item이 있는지 보기
		if (node->item.key == hash_value) {
			fprintf(stderr, "%d is found\n", item.key);
			return;
		}
	fprintf(stderr, "%d is found\n", item.key);
}
void hash_chain_print(struct list* ht[]) {
	struct list* node;
	int i;
	printf("\n============================\n");
	for (i = 0; i < TABLE_SIZE; i++) {
		printf("[%d]", i);
		for (node = ht[i]; node; node = node->link)
			printf("-%3d", node->item.key);
		printf("\n");
	}
	printf("\n============================\n");
}

int main() {
	int data[SIZE] = { 8,1,9,6,13 };
	element e;
	for (int i = 0; i < SIZE; i++) {
		e.key = data[i];
		hash_chain_add(e, hash_table);
		hash_chain_print(hash_table);
	}
	for (int i = 0; i < SIZE; i++) {
		e.key = data[i];
		hash_chain_search(e, hash_table);
	}
	return 0;
}