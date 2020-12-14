#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20


typedef struct TreeNode{
    char key[SIZE]; //treenode의 key는 문자배열
    struct TreeNode*left,*right;
}TreeNode;

TreeNode* new_node(char* item){//노드 생성
    TreeNode* node=(TreeNode*)malloc(sizeof(TreeNode));//새로운 메모리 할당
    strcpy(node->key,item);//값 복사
    node->left=NULL;
    node->right=NULL;//child node 0으로 초기화
    return node;//새로 생성된 노드 반환
}

TreeNode* insert_node(TreeNode*node, char* key){//해당 위치 찾아서 key값 갖는 노드 insert
    if(node==NULL) return new_node(key);//트리가 공백이면 insert된 새로운 노드를 반환
    if(strcmp(key,node->key)<0)
        node->left=insert_node(node->left,key);
    //insert할 값이 root의 key보다 작으면 left subtree 를 root로 insert 재귀호출
    else if(strcmp(key,node->key)>0)
        node->right=insert_node(node->right,key);
    //insert할 값이 root의 key보다 크면 right subtree 를 root로 insert 재귀호출
    else printf("%s is already in the binary search tree\n",key);
    return node;//변경된 root포인터 반환
}


TreeNode* init_node(TreeNode*node){//초기화 함수
    node=insert_node(node, "apple");
    node=insert_node(node, "banana");
    node=insert_node(node, "blueberry");
    node=insert_node(node, "kiwi");
    node=insert_node(node, "orange");
    node=insert_node(node, "pear");
    return node;
}
void inorder(TreeNode*root){//출력
    if (root==NULL)return;//empty tree면 NULL반환
    else{
        inorder(root->left);//left subtree traverse
        printf("%s\n",root->key);
        inorder(root->right);//right subtree traverse
    }
}

TreeNode* search(TreeNode*node, char* key){//검색
    if(node==NULL)return NULL;
    if(strcmp(key,node->key)==0) {
        printf("%s is found\n",key);
        return node;//찾고자 하는 노드면 반환
    }
    else if(strcmp(key,node->key)<0) return search(node->left,key);//left subtree를 다시 search
    else return search(node->right,key);//right subtree를 다시 search
}

TreeNode* min_value_node(TreeNode*node){//right subtree의 최소값 찾기
    TreeNode*current=node;
    while(current->left!=NULL) current=current->left;
    return current;
}

TreeNode* max_value_node(TreeNode*node){//left subtree의 최대값 찾기
    TreeNode*current=node;
    while(current->right!=NULL) current=current->right;
    return current;
}

TreeNode* delete_node(TreeNode*root, char* key){//key가 저장된 노드를 찾아 삭제하고 새로운 root 반환
    if(root==NULL) return root;
    else if(strcmp(root->key,key)>0)//왼쪽 subtree에서 key값을 찾아 삭제하도록 재귀호출
        root->left=delete_node(root->left,key);//새로운 left child로 변경
    else if(strcmp(root->key,key)<0)//오른쪽 subtree에서 key값을 찾아 삭제하도록 재귀호출
        root->right=delete_node(root->right,key);//새로운 right child로 변경
    else{//delete하려고 하는 key를 찾았을 때(3가지 경우)
        if(root->left==NULL){//말단노드 or child 1개 갖는 노드
            TreeNode*temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            TreeNode*temp=root->left;
            free(root);
            return temp;
        }
        //child 2개 있는 경우 가까운 key값 갖는 노드 찾아야 함
        TreeNode*temp=min_value_node(root->right);
        strcpy(temp->key,root->key);
        root->right=delete_node(root->right, temp->key);//복사된 값을 갖고있던 노드 삭제
    }
    return root;
}

int main(int argc, const char * argv[]) {
    TreeNode* root = NULL;
    root=init_node(root);//초기값 입력 
    while(1){
    printf("* Choose operation <1. insert   2. delete   3. search   4. print    5. exit>:");
    int ans;
    char name[SIZE];
    scanf("%d",&ans);
    getchar();
    switch(ans){
        case 1:
            printf("\nEnter a word: ");
            scanf("%s",&name);
            getchar();
            root=insert_node(root, name);
            break;
        case 2:
            printf("\nEnter a word to delete: ");
            scanf("%s",&name);
            getchar();
            root=delete_node(root,name);
            break;
        case 3:
            printf("\nEnter a word: ");
            scanf("%s",&name);
            getchar();
            search(root, name);
            break;
        case 4:
            inorder(root);
            break;
        case 5:
            goto EXIT;
            break;
        default:
            printf("Wrong Input\n");
            
        }
    }
    EXIT://라벨 EXIT
    printf("Program finished\n");
    return 0;
}
