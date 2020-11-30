/* 12주차 과제: 다익스트라 알고리즘을 인접리스트로 표현하기 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L //무한대(연결이 없는 경우)

typedef struct GraphNode {
	int vertex; //정점 번호
	int weight; //해당 리스트 정점과의 거리를 저장
	GraphNode* link; // 링크
}GraphNode;
typedef struct GraphType {
	int n; //정점 개수
	GraphNode* adj_list[MAX_VERTICES]; //포인터 배열
}GraphType;

void printInfo(void) {
	printf("====================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971063\n");
	printf("성명: 김윤서\n");
	printf("====================\n");
}
/* ----------------- adj_list Func ---------------- */
void init(GraphType* g) {
	g->n = 0;
	for (int v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL; //포인터 배열 초기화
}
void insert_vertex(GraphType* g, int v) {
	if ((g->n) + 1 > MAX_VERTICES) { // vertex 수가 MAX를 넘어선 경우
		fprintf(stderr, "%s\n", "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}
void insert_edge(GraphType* g, int u, int ver, int wei) {  //u의 인접리스트에 v를 삽입한다
	GraphNode* node;
	if (u >= g->n || ver >= g->n) {
		fprintf(stderr, "%s\n", "그래프: 정점 번호 오류");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode)); // 삽입할 새 노드 생성
	node->vertex = ver; //
	node->weight = wei; //
	node->link = g->adj_list[u]; //링크 연결
	g->adj_list[u] = node; //node를 연결리스트 u의 맨 처음에 삽입
}

/* ------------------ Graph Func ------------------ */
int distance[MAX_VERTICES]; // start vertex로부터 각 정점까지의 최단 거리
int found[MAX_VERTICES]; //방문한 정점 표시

int choose(int distance[], int n, int found[]) { /* distance 중에서 가장 짧은 vertex번호를 리턴 */
	int i, min, min_vertex;
	min = INT_MAX;
	min_vertex = -1; // 최소거리 갖는 vertex: 없는 vertex로 일단 초기화
	for (i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i]; // min값 갱신
			min_vertex = i; //최소거리 갖는 vertex
		}
	}
	return min_vertex; //vertex 번호 반환
}
void print_status(GraphType* g) {
	static int step = 1;
	printf("STEP %d:\n", step++); //step 1, 2, ...
	printf(" distance: ");
	for (int i = 0; i < g->n; i++)
		if (distance[i] == INF) { printf(" * "); }
		else { printf("%2d ", distance[i]); }
	printf("\n found: ");
	for (int i = 0; i < g->n; i++)
		printf("%2d ", found[i]);
	printf("\n\n");
}
int find_weight(GraphType* g, int u, int v) { /* vertex u에서 v까지의 거리 찾는 함수 */
	GraphNode* p = g->adj_list[u];
	int utov_weight = 0; 
	while (p != NULL) {

		if (p->vertex == v) { // u의 인접리스트에서 v를 만나면
			utov_weight = p->weight; //u에서 v까지의 거리
			break;
		}
		else p = p->link; 
	}
	return utov_weight;
}
void shortest_path(GraphType* g, int start) { // start_vertex 번호 받기
	int i, u, w;
	GraphNode* p = g->adj_list[start];

	/* 1.초기화 */
	for (int i = 0; i < g->n; i++) {
		found[i] = FALSE;
		distance[i] = INF; //distance는 모두 INF로 초기화하고, 나중에 값이 있는 것만 갱신한다
	}
	for (p; p!=NULL; p=p->link)	
		distance[p->vertex] = p->weight; //start vertex로부터의 정점까지의 거리 (1,INF,3 등등...)
	
	/* 2.start vertex 설정 */
	found[start] = TRUE;
	distance[start] = 0;
	/////////////////여기까지 ok

	/* 3.최단 vertex를 찾아서 found에 추가 */
	for (int i = 0; i < g->n - 1; i++) {
		print_status(g); //step 출력
		u = choose(distance, g->n, found); // 제일 작은 distance 갖는 vertex 반환 == u
		found[u] = TRUE;

		/* 4.u를 거쳐가는 게 더 짧을 경우, 갱신 */
		for (w = 0; w < g->n; w++) {
			if (!found[w]) { // !found 주의...
				if (distance[u] + find_weight(g,w,u) < distance[w]) //더 짧을 경우
					distance[w] = distance[u] + find_weight(g, w, u); // distance[w]값 갱신
			}
		}
	}
}
int main() {
	printInfo(); //정보 출력
	/*
	GraphType g = {
		7,
		{
		0 {0,7,INF,INF,3,10,INF},
		1 {7,0,4,10,2,6,INF},
		2 {INF,4,0,2,INF,INF,INF},
		3 {INF,10,2,0,11,9,4},
		4 {3,2,INF,11,0,INF,5},
		5 {10,6,INF,9,INF,0,INF},
		6 {INF,INF,INF,4,5,INF,0}
		}
	}; */
	GraphType* g = (GraphType*)malloc(sizeof(GraphType)); //그래프 생성
	init(g);
	for (int i = 0; i < 7; i++)
		insert_vertex(g, i); // n=7 :정점 7개 생성 (0~6)

	insert_edge(g, 0, 1, 7); insert_edge(g, 1, 0, 7); //대칭으로 저장되는 것이 아니므로, (1,0) 과 (0,1) 두번 연결해줘야함
	insert_edge(g, 0, 4, 3); insert_edge(g, 4, 0, 3);
	insert_edge(g, 0, 5, 10); insert_edge(g, 5, 0, 10);

	insert_edge(g, 1, 2, 4); insert_edge(g, 2, 1, 4);
	insert_edge(g, 1, 3, 10); insert_edge(g, 3, 1, 10);
	insert_edge(g, 1, 4, 2); insert_edge(g, 4, 1, 2);
	insert_edge(g, 1, 5, 6); insert_edge(g, 5, 1, 6);

	insert_edge(g, 2, 3, 2); insert_edge(g, 3, 2, 2);

	insert_edge(g, 3,4, 11); insert_edge(g, 4, 3, 11);
	insert_edge(g, 3, 5, 9); insert_edge(g, 5, 3, 9);
	insert_edge(g, 3, 6, 4); insert_edge(g, 6, 3, 4);

	insert_edge(g, 4, 6, 5); insert_edge(g, 6, 4, 5);

	shortest_path(g, 0); //0번 vertex에서 모든 vertex까지의 shortest path

	free(g);
	return 0;
}