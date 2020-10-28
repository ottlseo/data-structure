/* 이진탐색트리- search, insert, delete */
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int key;
	TreeNode* left, * right;
}TreeNode;

void printInfo(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}
TreeNode* new_node(int item) { //새 노드 생성
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->key = item;
	node->left = node->right = NULL; //child 노드를 널로 초기화
	return node;
}
TreeNode* insert_node(TreeNode* node, int key) {
	if (node == NULL) { return new_node(key); }

	/* insert할 값의 크기에 따라 subtree를 root로 insert 재귀호출 */
	if (key < node->key) { node->left = insert_node(node->left, key); }
	else if (key > node->key) { node->right = insert_node(node->right, key); }

	return node; //변경된 root 포인터 반환
}
void inorder(TreeNode* root) {
	if (root == NULL) return;
	else {
		inorder(root->left);
		printf(" [%d]", root->key);
		inorder(root->right);
	}
}
TreeNode* search(TreeNode* node, int key) {
	if (node == NULL)return NULL;
	if (node->key == key)return node;
	else if (node->key < key)return search(node->left, key);
	else return search(node->right, key);
}
TreeNode* min_value_node(TreeNode* node) { //최솟값 찾기-- left 순회 하면 됨
	TreeNode* current = node;
	while (current->left != NULL) { current = current->left; } //제일 왼쪽의 값일때까지 반복
	return current;
}
TreeNode* max_value_node(TreeNode* node) { //최댓값 찾기-- right 순회 하면 됨
	TreeNode* current = node;
	while (current->right != NULL) { current = current->right; } //제일 오른쪽의 값일때까지 반복
	return current;
}
TreeNode* delete_node(TreeNode* root, int key) {
	if (root == NULL)return root;
	else if (root->key > key) { root->left = delete_node(root->left, key); }
	else if (root->key < key) { root->right = delete_node(root->right, key); }
	else {
		if (root->left == NULL) { //CASE 2. 단말 노드거나, child를 하나 갖는 노드인 경우 (1)
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) { //CASE 2-(2)
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		/* CASE 3. child가 둘 다 있는 경우
			- 가장 가까운 key 값 갖는 노드 찾기(오른쪽) */
		TreeNode* temp1 = min_value_node(root->right); // right subtree에서 최소값 찾기
		TreeNode* temp2 = max_value_node(root->left); // left subtree에서 최대값 찾기
		printf("left subtree의 min: %d\n", temp2->key);
		printf("right subtree의 min: %d\n", temp1->key);
		if (abs(root->key - temp1->key) < abs(root->key - temp2->key)) { //root값과의 차이가 temp1이 더 작을 경우
			printf("original value: %d | new value: %d\n", root->key, temp1->key);
			root->key = temp1->key;
			root->right = delete_node(root->right, temp1->key); //복사된 값을 갖고 있던 기존노드 삭제
		}
		else {
			printf("original value: %d | new value: %d\n", root->key, temp2->key);
			root->key = temp2->key;
			root->left = delete_node(root->left, temp2->key); //복사된 값을 갖고 있던 기존노드 삭제
		}
	}
	return root; //새로운 root 반환
}
int main() {
	printInfo(); //정보 출력

	TreeNode* root = NULL;
	char input; // I/D/X 중에 사용자 선택
	int value; //insert/delete 시에 입력받을 값

	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 45);
	root = insert_node(root, 50);
	root = insert_node(root, 60);

	printf("이진 탐색 트리 중위 순회 결과\n");
	inorder(root);
	printf("\n\n");

	do {
		printf("* operation 선택: Insert(I) / Delete(D) / Exit(X): ");
		scanf_s("\n%c", &input);

		switch (input) {
		case'I': case'i':
			printf("Insert할 값은? ");
			scanf_s("%d", &value);
			root = insert_node(root, value); //value를 insert
			inorder(root); //트리 출력
			printf("\n\n");
			break;
		case'D':case'd':
			printf("Delete할 값은? ");
			scanf_s("%d", &value);
			root = delete_node(root, value); //value를 delete
			inorder(root); //트리 출력
			printf("\n\n");
			break;
		case 'X':
			break;
		default:
			printf("Wrong Input\n");
			break;
		}
	} while (input != 'X'); //입력이 X이면 반복문 종료
	printf("프로그램 종료");

	return 0;
}