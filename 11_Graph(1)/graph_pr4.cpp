#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct GraphType {
	int n; //vertex의 개수
	int adj_matrix[MAX][MAX]; //vertex 배열
}GraphType;

int visited[MAX];

void init(GraphType* g) {
	/* init 순서: (1) g->n=0; (2) 모든 원소 초기화 */
	g->n = 0;
	for (int r = 0; r < MAX; r++) {
		for (int c = 0; c < MAX; c++)
			g->adj_matrix[r][c] = 0; //모든 원소 0으로 초기화
	}
}
void insert_vertex(GraphType* g, int value) {
	if (g->n + 1 > MAX) {
		fprintf(stderr,"그래프: 정점의 개수 초과\n");
		return;
	}
	else g->n++; //vertex개수 증가
}
void insert_edge(GraphType* g, int start, int end) {
	if (start >= g->n || end >= g->n) {
		fprintf(stderr,"그래프: 정점 번호 오류\n");
		return;
	}
	g->adj_matrix[start][end] = 1;
	g->adj_matrix[end][start] = 1; //대칭 위치에 모두 1로 set
}
void dfs_matrix(GraphType* g, int value) {
	int w;
	visited[value] = true;
	printf("vertex%d ", value);
	for (w = 0; w < g->n; w++) {
		if (g->adj_matrix[value][w]==1 && !visited[w]) //아직 방문 안했고 값이 있으면 dfs 다시 
			dfs_matrix(g, w);
	}
}
int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 4; i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	dfs_matrix(g,0);

	free(g);
	return 0;
}