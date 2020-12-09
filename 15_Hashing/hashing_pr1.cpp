/* 1. 선형조사법 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KEY_SIZE 10 //탐색키의 최대 길이
#define TABLE_SIZE 13 //ht의 크기(prime number)
#define empty(item) (strlen(item.key)==0)
#define equal(item1, item2) (!strcmp(item1.key, item2.key))

typedef struct element {
	char key[KEY_SIZE];
}element;

element hash_table[TABLE_SIZE]; //2차원 배열처럼

void init_table(element ht[]) {
	for (int i = 0; i < TABLE_SIZE; i++)
		ht[i].key[0] = NULL; //모든 테이블의 0번 키를 널로 초기화
}
int transform(char* key) { //각 문자의 아스키코드를 더해서 숫자로 반환
	int num = 0;
	while (*key)
		num += *key++; //다음 문자로 넘어감++
	return num;
}
int hash_function(char* key) { //modulo 연산 사용한 hash function
	return transform(key) % TABLE_SIZE; // k mod M
}
void hash_lp_add(element item, element ht[]) { //key를 hash table에 insert
	int i, hash_value;
	hash_value = i = hash_function(item.key); //hash 값 계산
	while (!empty(ht[i])) { //동일한 키값이 이미 들어있으면
		if (equal(ht[i], item)) {
			fprintf(stderr, "search key duplicated\n");
			exit(1);
		}
		i = (i + 1) % TABLE_SIZE; //다음 위치 찾기
		if (i == hash_value) { //돌고돌아 그 자리로 돌아오면
			fprintf(stderr, "table is full\n"); //테이블이 꽉 찬 것
			exit(1);
		}
	}
	ht[i] = item; //해당 위치가 비어있으면 insert
}
void hash_lp_search(element item, element ht[]) { //item이 있는지 찾는 함수
	int i, hash_value;
	hash_value = i = hash_function(item.key);
	while (!empty(ht[i])) { //값이 있으면

		if (equal(item, ht[i])) { //같으면 찾았다고 표시, 리턴
			fprintf(stderr, "%s: location = %d\n", item.key, i);
			return;
		}
		i = (i + 1) % TABLE_SIZE; // i++
		if (i == hash_value) { //한 바퀴 다 돌면
			fprintf(stderr, "not in the table\n");
			return;
		}
	} // end of while
	fprintf(stderr, "not in the table\n");
}
void hash_lp_print(element ht[]) {
	int i;
	printf("\n==============================\n");
	for (i = 0; i < TABLE_SIZE; i++)
		printf("[%d]	%s\n", i, ht[i].key);
	printf("==============================\n\n");
}
int main() {
	const char* s[7] = { "do","for","if","case","else","return","function" };
	element e;

	for (int i = 0; i < 7; i++) {
		strcpy(e.key, s[i]); // e.key에 위의 단어들을 복사
		puts(s[i]);
		hash_lp_add(e, hash_table); //해시테이블에 e를 넣는다
		hash_lp_print(hash_table); //해시테이블 프린트
	}
	return 0;
}