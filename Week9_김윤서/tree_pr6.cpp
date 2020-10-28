/* 6. 이진트리 연산: 노드 개수, 높이, 단말노드 개수 등등 */
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	TreeNode* left, * right;
}TreeNode;

int node_count(TreeNode* exp) {
	if (exp == NULL)return 0;
	else { return node_count(exp->left) + node_count(exp->right) + 1; }
}
int leaf_count(TreeNode* exp) {
	if (exp == NULL) { return 0; }
	else {
		if (exp->left == NULL && exp->right == NULL) { return 1; } //단말노드인 경우
		else { return leaf_count(exp->left) + leaf_count(exp->right); } //child가 있는 경우- 더해줌
	}
}
int get_height(TreeNode* exp) {
	if (exp == NULL) { return 0; }
	else {
		int l_height = get_height(exp->left);
		int r_height = get_height(exp->right);
		if (l_height >= r_height)return l_height + 1;
		else return r_height + 1;
	}
}
int main() {

	TreeNode n1 = { 1,NULL,NULL };
	TreeNode n2 = { 4,NULL,NULL };
	TreeNode n3 = { '*',&n1,&n2 };
	TreeNode n4 = { 16,NULL,NULL };
	TreeNode n5 = { 25,NULL,NULL };
	TreeNode n6 = { '+',&n4,&n5 };
	TreeNode n7 = { '+',&n3,&n6 };
	TreeNode* exp = &n7;

	printf("node count = %d\n", node_count(exp));
	printf("leaf node count = %d\n", leaf_count(exp));
	printf("Height of Tree: %d\n", get_height(exp));

	return 0;
}
