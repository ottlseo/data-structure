#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

typedef struct TreeNode {
    char key[SIZE]; //문자 배열 //주의* 여기서 char* key 처럼 포인터로 정의하면 값을 못 바꿔서 에러남. 배열로 하기
    TreeNode* left, * right;
}TreeNode;

void inorder(TreeNode* root) { //중위순회 출력 (LVR)
    if (root == NULL)return;
    else {
        inorder(root->left);
        printf("%s\n", root->key);
        inorder(root->right);
    }
}
TreeNode* new_node(char* item) {//노드 생성
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(node->key, item);//값 복사
    node->left = node->right = NULL; //왼,오 child 모두 널로 초기화
    return node;
}

TreeNode* insert_node(TreeNode* node, char* key) { //적절한 위치 찾아서 insert
    if (node == NULL) return new_node(key);//트리가 비어있을 경우
    
    if (strcmp(key, node->key) < 0) { node->left = insert_node(node->left, key); } //key값이 root보다 작을 때 --left
    else if (strcmp(key, node->key) > 0){ node->right = insert_node(node->right, key); } // 클 때-- right 재귀호출
    else printf("%s is already in the binary search tree\n", key);
    return node; //변경된 root 반환
}

TreeNode* search(TreeNode* node, char* key) {
    if (node == NULL)return NULL;
    if (strcmp(key, node->key) == 0) return node;//찾은 노드 리턴
    else if (strcmp(key, node->key) < 0) return search(node->left, key);//left 재귀호출
    else return search(node->right, key);//right 재귀호출
}

TreeNode* min_value_node(TreeNode* node) {//right child 최솟값 찾기
    TreeNode* current = node;
    while (current->left != NULL) current = current->left;
    return current;
}
TreeNode* delete_node(TreeNode* root, char* key) { //key가 저장된 노드를 삭제
    if (root == NULL) return root;
    else if (strcmp(root->key, key) > 0){ root->left = delete_node(root->left, key); }
    else if (strcmp(root->key, key) < 0){ root->right = delete_node(root->right, key); }
    else {
        /* CASE 1,2 단말노드거나 Child 하나 가질 경우 */
        if (root->left == NULL) {  //오른쪽 child 하나일 경우
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) { //왼쪽 child 하나일 경우
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        /* CASE 3. Child 2개 가질 경우 */
        TreeNode* temp = min_value_node(root->right);
        strcpy(temp->key, root->key);
        root->right = delete_node(root->right, temp->key);//복사된 값을 갖고있던 노드 삭제
    }
    return root;
}

TreeNode* init_node(TreeNode* node) {//초기화 함수
    char fruit[6][SIZE] = { "apple","banana","blueberry","kiwi","orange","pear" };
    for (int i = 0; i < 6; i++) {
        node = insert_node(node, fruit[i]); //초기값들 트리에 삽입
    }
    return node;
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
    int input; //사용자 선택
    TreeNode* root = NULL;
    char fruit[SIZE];

    root = init_node(root);//초기값 입력 
    do {
        printf("* Choose operation <1.insert 2.delete 3.search 4.print 5.exit>: ");
        scanf("%d", &input);
        
        switch (input) {
        case 1: /* insert */
            printf("\nEnter a word: ");
            scanf("\n%s", &fruit);
            root = insert_node(root, fruit); //fruit를 insert
            printf("\n");
            break;
        case 2: /* delete */
            printf("\nEnter a word to delete: ");
            scanf("\n%s", &fruit);
            root = delete_node(root, fruit); //value를 delete
            printf("\n");
            break;
        case 3: /* search */
            printf("\nEnter a word: ");
            scanf("\n%s", &fruit);
            if (search(root, fruit) != NULL) { printf("%s is found\n\n", fruit); }
            else printf("%s is not found\n\n", fruit);
            break;
        case 4: /* print */
            inorder(root);
            printf("\n");
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
