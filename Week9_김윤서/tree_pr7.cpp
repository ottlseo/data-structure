/* 이진탐색트리- search, insert, delete */
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int key;
	TreeNode* left, * right;
}TreeNode;

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
		printf("[%d]", root->key);
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
TreeNode* delete_node(TreeNode* root, int key) {
	if (root == NULL)return root; // CASE 1.
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
		TreeNode* temp = min_value_node(root->right); //새로운 root를 
		root->key = temp->key;
		root->right = delete_node(root->right, temp->key); //복사된 값을 갖고 있던 기존노드 삭제
	}
	return root; //새로운 root 반환
}
int main() {
	TreeNode* root = NULL;
	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);

	printf("이진 탐색 트리 중위 순회 결과\n");
	inorder(root);
	printf("\n\n");

	root = insert_node(root, 55);
	inorder(root);
	printf("\n");
	root = delete_node(root, 50);
	inorder(root);
	printf("\n\n");

	if (search(root, 30) != NULL) { printf("30 발견"); }
	else { printf("30 발견 실패"); }

	return 0;
}
