#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode { //링크로 이진트리 구현
	char* key;
	TreeNode* left, * right;
}TreeNode;

void printInfo(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}
void inorder(TreeNode* root) {
	if (root == NULL) return;
	else {
		inorder(root->left);
		printf("%s\n", root->key);
		inorder(root->right);
	}
}
TreeNode* new_node(const char* item) { //새 노드 생성
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	strcpy(node->key, item); //node->key = item;
	node->left = node->right = NULL; //child 노드를 널로 초기화
	return node;
}
TreeNode* search(TreeNode* node, const char* item) {
	if (node == NULL)return NULL;
	if (strcmp(node->key, item)) return node;
	else if (item[0] < node->key[0])return search(node->left, item);
	else return search(node->right, item);
}
TreeNode* insert_node(TreeNode* node, const char* item) {
	if (node == NULL) return new_node(item);
	
	if (item[0] < node->key[0]) node->left = insert_node(node->left, item); //맨 앞글자의 순위 따지기
	else if (item[0] > node->key[0]) node->right = insert_node(node->right, item);
	return node;
}
TreeNode* min_value_node(TreeNode* root) { //right child의 최솟값 찾기
	TreeNode* current = root;
	while (root->left != NULL) { current = current->left; }
	return current;
}
TreeNode* delete_node(TreeNode* root, const char* item) { //key값을 갖는 노드삭제
	if (root == NULL) return root;
	else if (item[0] < root->key[0]) { root->left = delete_node(root->left, item); }
	else if (item[0] > root->key[0]) { root->right = delete_node(root->right, item); }
	else {
		/* CASE 1,2 단말노드거나 Child 하나 가질 경우 */
		if (root->left == NULL) { //오른쪽 child 하나일 경우
			TreeNode* temp = root->right;
			free(root);
			return temp;
		} else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		/* CASE 3. Child 2개 가질 경우 */
		TreeNode* temp = min_value_node(root->right);
		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}
int main() {
	printInfo(); //정보 출력
	int input; //사용자 선택
	char* fruit;
	TreeNode* root = new_node("apple");
	root = insert_node(root, "banana");
	root = insert_node(root, "blueberry");
	root = insert_node(root, "kiwi");
	root = insert_node(root, "orange");
	root = insert_node(root, "pear");
	
	do {
		printf("* Choose operation <1.insert 2.delete 3.search 4.print 5.exit>: ");
		scanf("\%d", &input);

		switch (input) {
		case 1: /* insert */
			printf("\nEnter a word: ");
			scanf("%d", &fruit);
			root = insert_node(root, fruit); //fruit를 insert
			printf("\n\n");
			break;
		case 2: /* delete */
			printf("\nEnter a word to delete: ");
			scanf("%d", &fruit);
			root = delete_node(root, fruit); //value를 delete
			printf("\n\n");
			break;
		case 3: /* search */
			printf("\nEnter a word: ");
			scanf("%d", &fruit);
			if (search(root, fruit) != NULL) { printf("%s is found\n", fruit); }
			else { printf("search failed\n"); }
			break;
		case 4: /* print */
			inorder(root);
			break;
		case 5: //exit
			break;
		default:
			printf("Wrong Input\n");
			break;
		}
	} while (input != 5); //입력이 5이면 반복문 종료
	printf("Program finished\n");

	return 0;
}
