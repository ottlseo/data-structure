/* 이진트리 traversal */
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	TreeNode* left, * right;
}TreeNode;

TreeNode n1 = { 1,NULL,NULL };
TreeNode n2 = { 2,&n1,NULL };
TreeNode n3 = { 3,NULL,NULL };
TreeNode n4 = { 4,NULL,NULL };
TreeNode n5 = { 5,&n3,&n4 };
TreeNode n6 = { 6,&n2,&n5 };
TreeNode *root = &n6;

void inorder(TreeNode* root) { /* 중위 순회 (LVR) */
	if (root) {
		inorder(root->left);
		printf("[%d]", root->data);
		inorder(root->right);
	}
}
void preorder(TreeNode* root) { /* 전위 순회 (VLR) */
	if (root) {
		printf("[%d]", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(TreeNode* root) { /* 후위 순회 (LRV) */
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("[%d]", root->data);
	}
}
int main() {
	printf("<Inorder>\n");
	inorder(root);
	printf("\n");

	printf("<Preorder>\n");
	preorder(root);
	printf("\n");

	printf("<Postorder>\n");
	postorder(root);
	printf("\n");

	return 0;
}