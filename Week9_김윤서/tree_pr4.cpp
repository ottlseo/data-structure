/* 3- 레벨 순회 코드 -- pass 
* 4. 수식 트리 계산 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct TreeNode {
	int data;
	TreeNode* left, * right;
}TreeNode;

TreeNode n1 = { 1,NULL,NULL };
TreeNode n2 = { 4,NULL,NULL };
TreeNode n3 = { '*',&n1,&n2 };
TreeNode n4 = { 16,NULL,NULL };
TreeNode n5 = { 25,NULL,NULL };
TreeNode n6 = { '+',&n4,&n5 };
TreeNode n7 = { '+',&n3,&n6 };
TreeNode* exp = &n7;

int evaluate(TreeNode* exp) {
	if (exp == NULL) { return 0; } //노드가 없는 경우
	else if (exp->left == NULL && exp->right == NULL) { return exp->data; } //말단 노드인 경우
	else {
		int op1 = evaluate(exp->left);
		int op2 = evaluate(exp->right);
		printf("%2d %c %2d\n", op1, exp->data, op2);
		switch (exp->data)
		{
		case '+':return op1 + op2; break;
		case '-':return op1 - op2; break;
		case '*':return op1 * op2; break;
		case '/':return op1 / op2; break;
		}
	}
	return 0;
}
int main() {
	
	printf("1*4 + 16+25\n===================\n");
	printf("===================\nResult= %d\n", evaluate(exp));

	return 0;
}
