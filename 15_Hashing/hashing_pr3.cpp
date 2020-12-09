/* 3. 이중해싱법-- h'(k) */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KEY_SIZE 10 //탐색키의 최대 길이
#define TABLE_SIZE 13 //ht의 크기(prime number)
#define empty(item) (strlen(item.key)==0)
#define equal(item1, item2) (!strcmp(item1.key, item2.key))
#define DH_VALUE 11

typedef struct element {
	char key[KEY_SIZE];
}element;

element hash_table[TABLE_SIZE]; //2차원 배열처럼

void init_table(element ht[]) {
	for (int i = 0; i < TABLE_SIZE; i++)
		ht[i].key[0] = NULL; //모든 테이블의 0번 키를 널로 초기화
}
int transform(char* key) { //각 문자의 아스키코드를 더해서 숫자로 반환 --> K
	int num = 0;
	while (*key)
		num += *key++; //다음 문자로 넘어감++
	return num;
}
int hash_function(char* key) { //modulo 연산 사용한 h(k)
	return transform(key) % TABLE_SIZE; // k mod M
}
int hash_function2(char* key) { // h'(k)
	return DH_VALUE - (transform(key) % DH_VALUE);  // h'(k) = C-(K mod C)
}
void hash_dh_add(element item, element ht[]) { //key를 해시 테이블에 insert
	int i, hash_value, inc;
	hash_value = i = hash_function(item.key);
	inc = hash_function2(item.key); //inc가 1,2,...M-1 이 아니라, 해시함수로 정의됨
	while (!empty(ht[i])) {
		if (equal(ht[i], item)) {
			fprintf(stderr, "search key duplicated\n");
			exit(1);
		}
		i = (i + inc) % TABLE_SIZE; //다음 위치 찾기 I=(i+inc) % table size
		if (i == hash_value) {
			fprintf(stderr, "table is full\n");
			exit(1);
		}
	}
	ht[i] = item;
}
void hash_print(element ht[]) { 
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
		hash_dh_add(e, hash_table); //해시테이블에 e를 넣는다
		hash_print(hash_table); //해시테이블 프린트
	}
	return 0;
}

/* 다른 부분 
* inc에 값을 넣는다. h'(k) = C - k mod C 이용.
*/
