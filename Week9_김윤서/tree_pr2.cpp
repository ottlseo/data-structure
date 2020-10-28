/* 반복적인 순회
	: 재귀 대신 반복 이용- 스택 사용 */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct TreeNode {
	int data;
	TreeNode* left, * right;
}TreeNode;

typedef struct StackType {
	TreeNode* stack[SIZE];
	int top = -1;
}StackType;

TreeNode n1 = { 1,NULL,NULL };
TreeNode n2 = { 2,&n1,NULL };
TreeNode n3 = { 3,NULL,NULL };
TreeNode n4 = { 4,NULL,NULL };
TreeNode n5 = { 5,&n3,&n4 };
TreeNode n6 = { 6,&n2,&n5 };
TreeNode* root = &n6;

bool is_full(StackType* s) {
	return (s->top == SIZE - 1);
}
bool is_empty(StackType* s) {
	return (s->top == -1);
}
void push(TreeNode* p, StackType*s) {
	if (!is_full(s)) { s->stack[++s->top] = p; }
}
TreeNode* pop(StackType* s) {
	TreeNode* p = NULL;
	if (!is_empty(s)) { p = s->stack[s->top--]; }
	return p;
}
void inorder_stack(TreeNode* root, StackType* s) {
	while (true) {
		for (; root; root = root->left) { push(root,s); } //반복문, root가 존재하면 계속 push. inorder이므로 루트를 왼쪽으로 옮겨줌
		root = pop(s); //left노드가 더이상 없으면 pop
		if (root == NULL)break;
		printf("[%d]", root->data);
		root = root->right; //왼쪽 노드 끝났으니 오른쪽 노드로 이동해서 동일작업 다시 반복
	}
}
int main() {
	StackType s;
	printf("Inorder: ");
	inorder_stack(root, &s);
	printf("\n");

	return 0;
}
