#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode { //링크로 이진트리 구현
	int key;
	TreeNode* left, * right;
}TreeNode;

int get_max_node(TreeNode* root) { /* 최댓값 구하기 */
	int root_key, left_max, right_max, max_node = 0; //가장 작은 값으로 초기화
	if (root) {
		root_key = root->key; //루트의 key값 저장
		left_max = get_max_node(root->left); // left child에서 가장 큰 것 찾기
		right_max = get_max_node(root->right); // right child에서 가장 큰 것 찾기
		
		if (left_max > right_max) max_node = left_max;
		else max_node = right_max;
		if (root_key > max_node) max_node = root_key; //만약 root의 값이 가장 클 경우
	}
	return max_node; // 최댓값 리턴
}
int get_min_node(TreeNode* root) { /* 최솟값 구하기 */
	int root_key, left_min, right_min, min_node = INT_MAX; //가장 큰 값으로 초기화
	if (root) {
		root_key = root->key; //루트의 key값 저장
		left_min = get_min_node(root->left); // left child에서 가장 작은 것 찾기
		right_min = get_min_node(root->right); // right child에서 가장 작은 것 찾기

		if (left_min < right_min) min_node = left_min;
		else min_node = right_min;
		if (root_key < min_node) min_node = root_key; //만약 root의 값이 가장 작을 경우
	}
	return min_node; // 최솟값 리턴
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