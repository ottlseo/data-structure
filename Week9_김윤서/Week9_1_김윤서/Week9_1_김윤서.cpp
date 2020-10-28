#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	TreeNode* left, * right;
}TreeNode;

void printInfo();
void inorder(TreeNode* exp);
int node_count(TreeNode* exp);
int leaf_count(TreeNode* exp);
int get_height(TreeNode* exp);
void balanced(TreeNode* exp);
void greater_num(TreeNode* exp, int num);

int main() {
	printInfo(); //정보 출력

	int check; //number to check
	TreeNode n1 = { 1,NULL,NULL };
	TreeNode n2 = { 2,NULL,NULL };
	TreeNode n3 = { 3,&n1,&n2 };
	TreeNode n4 = { 4,NULL,NULL };
	TreeNode n5 = { 5,NULL,NULL };
	TreeNode n6 = { 6,&n4,&n5 };
	TreeNode n7 = { 7,&n3,&n6 };
	TreeNode* exp = &n7;

	inorder(exp);
	printf("\n\nNumber of nodes in Tree: %d", node_count(exp));
	printf("\nHeight of the Tree: %d", get_height(exp));
	printf("\nNumber of leafs in Tree: %d", leaf_count(exp));
	printf("\nBalanced Tree? ");
	balanced(exp);
	printf("\nInput a number to check: ");
	scanf_s("%d", &check);
	printf("\nnumbers greater than %d: ", check);
	greater_num(exp,check);

	return 0;
}
void inorder(TreeNode* exp) { /* 중위 순회 (LVR) */
	if (exp) {
		inorder(exp->left);
		printf("[%d]", exp->data);
		inorder(exp->right);
	}
}
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
		int l_height = get_height(exp->left); //왼쪽 높이
		int r_height = get_height(exp->right); //오른쪽 높이
		if (l_height >= r_height)return l_height + 1;
		else return r_height + 1;
	}
}
void balanced(TreeNode* exp) {
	if (exp == NULL) { return; }
	else {
		int l_height = get_height(exp->left);
		int r_height = get_height(exp->right);
		if (abs(l_height - r_height) > 1) { printf("No"); } //양 subtree의 높이가 1 이상 차이나면 no 출력
		else { printf("Yes"); } //차이가 1 이하이면 Yes 출력
	}
}
void greater_num(TreeNode* exp, int num) {
	TreeNode* root = exp;
	if(root){
		greater_num(exp->left, num); //LVR 방식으로 순회하며 num보다 더 큰 값을 찾는다
		if (root->data > num) { printf("%d ",root->data); } //num보다 값이 더 큰 노드를 찾으면, 출력
		greater_num(exp->right, num);
	}
}
void printInfo(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}