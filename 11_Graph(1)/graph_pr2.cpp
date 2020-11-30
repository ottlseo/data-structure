#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct GraphNode {
	int vertex;
	GraphNode* link;
}GraphNode;

typedef struct GraphType {
	int n; //vertex 개수
	GraphNode* adj_list[MAX]; //vertex 개수 크기의 포인터 배열
}GraphType;

void init(GraphType* g) {
	g->n = 0; //노드 수 0으로 초기화
	for (int i = 0; i < MAX; i++) 
		g->adj_list[i] = NULL; //모든 vertex NULL로 초기화
}
void insert_vertex(GraphType* g, int value) {
	if (g->n + 1 > MAX) { //예외처리
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	else g->n++; //vertex개수 증가
}
void insert_edge(GraphType* g, int u, int value) {
	if (u >= g->n || value >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = value; //값 넣고
	node->link = g->adj_list[u]; //u리스트의 맨 앞에 연결
	g->adj_list[u] = node; //insert된 노드가 맨앞 vertex가 됨
}
void print_adj_list(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		GraphNode* temp = g->adj_list[i]; //각 vertex마다 반복해서 출력
		printf("vertex %d의 adj list ", i);
		while (temp != NULL) {
			printf(" -> %d ", temp->vertex);
			temp = temp->link;
		}
		printf("\n");
	}
}
int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	for (int i = 0; i < 4; i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 1, 0); //대칭아니어서, 직접 양방향으로 넣어줘야한다
	insert_edge(g, 0, 2);
	insert_edge(g, 2, 0);
	insert_edge(g, 0, 3);
	insert_edge(g, 3, 0);
	insert_edge(g, 1,2);
	insert_edge(g, 2,1);
	insert_edge(g, 2,3);
	insert_edge(g, 3,2);

	print_adj_list(g);
	
	free(g);
	return 0;
}