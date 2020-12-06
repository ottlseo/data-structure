#include <stdio.h>
#include <stdlib.h>
#define MAX_INT 1000L

typedef struct TreeNode { //링크로 이진트리 구현
	int key;
	TreeNode* left, * right;
}TreeNode;

int get_max_node(TreeNode* root) { /* 최댓값 구하기 */
	int max_node = 0; //가장 작은 값으로 초기화
	if (root == NULL) return 0; ////// 여기가 문제---
	else {
		max_node = get_max_node(root->left);
		if (root->key > max_node) max_node = root->key; //현재 노드와 max값을 비교해서 더 큰 값이면 갱신
		max_node = get_max_node(root->right); // LVR 방식으로 모든 노드 순회
		return max_node; // 최댓값 리턴
	}
}
int get_min_node(TreeNode* root) { /* 최솟값 구하기 */
	int min_node = 3; //가장 큰 값으로 초기화
	if (root == NULL) return MAX_INT;
	else {
		min_node = get_min_node(root->left);
		if (root->key < min_node) min_node = root->key; //현재 노드와 min값을 비교해서 더 작으면 값 갱신
		min_node = get_min_node(root->right); // LVR 방식으로 순회
		return min_node;
	}
}

int get_sum(TreeNode* root) { /* key 합계 구하기 */
	int sum = 0;
	if (root == NULL) return 0;
	else {
		sum += get_sum(root->left);
		sum += root->key;
		sum += get_sum(root->right); // LVR 방식으로 순회하며 값 더하기
		return sum;
	}
}
int get_only_child(TreeNode* root) { /* child가 한 개인 노드의 수 구하기 */
	int num = 0; //child가 한 개인 노드의 개수
	if (root == NULL) return 0;
	else { //LVR 순으로 순회하며 num++
		num += get_only_child(root->left);
		if (!(root->left == NULL && root->right == NULL) && ((root->left == NULL) || (root->right == NULL)))
			num++; // left,right가 둘다 NULL(단말노드)가 아님 && 둘 중 하나는 NULL인 노드일 경우
		num += get_only_child(root->right);
		return num; ///노드 개수(num) 리턴
	}
}
void printInfo(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}

int main() {
	printInfo(); //정보 출력
	TreeNode n0 = { 11, NULL, NULL };
	TreeNode n1 = { 2, &n0, NULL };
	TreeNode n2 = { 5, &n1, NULL };
	TreeNode n3 = { 13, &n2, NULL };
	TreeNode n4 = { 25, &n3, NULL };
	TreeNode n5 = { 8, NULL, NULL };
	TreeNode n6 = { 3, NULL, &n5 };
	TreeNode n7 = { 21, &n4, &n6 };
	TreeNode* exp = &n7; // n7이 root노드임

	printf("\nSum of keys in Binary tree: %d\n", get_sum(exp));
	printf("Num of one child nodes: %d\n", get_only_child(exp));
	printf("Max value: %d\n",get_max_node(exp));
	printf("Min value: %d\n", get_min_node(exp));

	return 0;
}
