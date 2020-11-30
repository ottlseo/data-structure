/* 3. DFS_인접행렬 ver. */
#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct GraphType {
	int n; // vertex의 수
	int adj_mat[MAX][MAX]; //행렬
}GraphType;

int visited[MAX]; //방문했는지 아닌지..

void init(GraphType* g) {
	int row, col;
	g->n = 0;
	for (row = 0; row < MAX; row++)
		for (col = 0; col < MAX; col++)
			g->adj_mat[row][col] = 0; //모든 원소 0으로 초기화
}
void insert_vertex(GraphType* g, int value) {
	if (g->n + 1 > MAX) {
		fprintf(stderr, "그래프: 정점의 개수 초과\n");
		return;
	}
	else g->n++; //vertex 개수 증가
}
void insert_edge(GraphType* g, int start, int end) {
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류\n");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1; //대칭 위치에 모두 1로 set
}
void print_adj_mat(GraphType* g) {
	int row, col;
	for (row = 0; row < g->n; row++) {
		for (col = 0; col < g->n; col++)
			printf("%2d", g->adj_mat[row][col]);
		printf("\n");
	}
}
void dfs_mat(GraphType* g, int value) {
	int w;
	visited[value] = true;
	printf("vertex%d ", value);
	for (w = 0; w < g->n; w++) {
		if (g->adj_mat[value][w] && !visited[w])
			dfs_mat(g, w); //재귀 호출s
	}
}
int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	for (int i = 0; i < 4; i++) { insert_vertex(g, i); }
	insert_edge(g, 0, 1); // 0-1 연결
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	print_adj_mat(g);

	printf("< DFS >\n");
	dfs_mat(g, 0);
	printf("\n");

	free(g);
	return 0;
}
