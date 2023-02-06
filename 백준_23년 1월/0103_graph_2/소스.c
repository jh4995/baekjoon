/*
//Kruskal의 MST(최소비용신장트리) 알고리즘

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES];

void set_init(int n)
{
	for (int i = 0; i < n; i++)
	{
		parent[i] = -1;
	}
}

int set_find(int curr)
{
	if (parent[curr] == -1)
	{
		return curr;
	}
	while (parent[curr] != -1)
	{
		curr = parent[curr];
	}
	return curr;
}

void set_union(int a, int b)
{
	int root_1 = set_find(a);
	int root_2 = set_find(b);
	if (root_1 != root_2)
	{
		parent[root_1] = root_2;
	}
}

struct Edge {
	int start, end, weight;
};

typedef struct GraphType {
	int n;
	int n_vertex;
	struct Edge edges[2 * MAX_VERTICES];
}GraphType;

void graph_init(GraphType* g)
{
	g->n = g->n_vertex = 0;
	for (int i = 0; i < 2 * MAX_VERTICES; i++)
	{
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INF;
	}
}

void insert_edge(GraphType* g, int start, int end, int w)
{
	g->edges[g->n].start = start;
	g->edges[g->n].end = end;
	g->edges[g->n].weight = w;
	g->n++;
}

int compare(const void* a, const void* b)
{
	struct Edge* x = (struct Edge*)a;
	struct Edge* y = (struct Edge*)b;
	return (x->weight - y->weight);
}

void kruskal(GraphType* g)
{
	int edge_accepted = 0;
	int u_set, v_set;
	struct Edge e;

	set_init(g->n_vertex);
	qsort(g->edges, g->n, sizeof(struct Edge), compare);

	printf("크루스칼 최소 신장 트리 알고리즘 \n");
	int i = 0;
	while (edge_accepted < (g->n_vertex - 1))
	{
		e = g->edges[i];
		u_set = set_find(e.start);
		v_set = set_find(e.end);
		if (u_set != v_set)
		{
			printf("간선 (%d, %d) %d 선택\n", e.start, e.end, e.weight);
			edge_accepted++;
			set_union(u_set, v_set);
		}
		i++;
	}
}

int main(void)
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	graph_init(g);

	g->n_vertex = 7;
	insert_edge(g, 0, 1, 29);
	insert_edge(g, 1, 2, 16);
	insert_edge(g, 2, 3, 12);
	insert_edge(g, 3, 4, 22);
	insert_edge(g, 4, 5, 27);
	insert_edge(g, 5, 0, 10);
	insert_edge(g, 6, 1, 15);
	insert_edge(g, 6, 3, 18);
	insert_edge(g, 6, 4, 25);

	kruskal(g);
	free(g);
	return 0;
}*/

/*
//Prim의 MST(최소비용신장트리) 알고리즘

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

typedef struct GraphType {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

int get_min_vertex(int n)
{
	int v, i;
	for (i = 0; i < n; i++)
	{
		if (!selected[i])
		{
			v = i;
			break;
		}
	}
	for (i = 0; i < n; i++)
	{
		if (!selected[i] && (distance[i] < distance[v]))
		{
			v = i;
		}
	}
	return (v);
}

void prim(GraphType* g, int s)
{
	int i, u, v;

	for (u = 0; u < g->n; u++)
	{
		distance[u] = INF;
	}
	distance[s] = 0;
	for (i = 0; i < g->n; i++)
	{
		u = get_min_vertex(g->n);
		selected[u] = TRUE;
		if (distance[u] == INF)
		{
			return;
		}
		printf("정점 %d 추가\n", u);

		for (v = 0; v < g->n; v++)
		{
			if (g->weight[u][v] != INF)
			{
				if (!selected[v] && g->weight[u][v] < distance[v])
				{
					distance[v] = g->weight[u][v];
				}
			}
		}
	}
}

int main(void)
{
	GraphType g = { 7,
	{{0,29,INF, INF, INF, 10, INF},
		{29,0,16,INF,INF,INF,15},
		{INF,16,0,12,INF,INF,INF},
		{INF,INF,12,0,22,INF,18},
		{INF,INF,INF,22,0,27,25},
		{10, INF, INF, INF, 27, 0, INF},
		{INF, 15, INF, 18, 25, INF, 0}}
	};
	prim(&g, 0);
	return 0;
}*/

/*
//Dijkstra의 최단 경로 알고리즘

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000

typedef struct GraphType {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int distance[MAX_VERTICES];
int found[MAX_VERTICES];

int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
	{
		if (distance[i] < min && !found[i])
		{
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}

void print_status(GraphType* g)
{
	static int step = 1;
	printf("STEP %d: ", step++);
	printf("distance: ");
	for (int i = 0; i < g->n; i++)
	{
		if (distance[i] == INF)
		{
			printf(" * ");
		}
		else
		{
			printf("%2d ", distance[i]);
		}
	}
	printf("\n");
	printf(" found: ");
	for (int i = 0; i < g->n; i++)
	{
		printf("%2d ", found[i]);
	}
	printf("\n\n");
}

void shortest_path(GraphType* g, int start)
{
	int i, u, w;
	for (i = 0; i < g->n; i++)
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE;
	distance[start] = 0;

	for (i = 0; i < g->n - 1; i++)
	{
		print_status(g);
		u = choose(distance, g->n, found);
		found[u] = TRUE;
		for (w = 0; w < g->n; w++)
		{
			if (!found[w])
			{
				if (distance[u] + g->weight[u][w] < distance[w])
				{
					distance[w] = distance[u] + g->weight[u][w];
				}
			}
		}
	}
}

int main(void)
{
	GraphType g = { 7,
	{{0, 7, INF, INF, 3, 10, INF},
	 {7, 0, 4, 10, 2, 6, INF},
	 {INF, 4, 0, 2,INF,INF,INF},
	 {INF, 10, 2, 0, 11, 9, 4},
	 {3, 2, INF, 11, 0, INF, 5},
	 {10, 6, INF, 9, INF, 0, INF},
	 {INF, INF, INF, 4, 5, INF, 0}}
	};
	shortest_path(&g, 0);
}*/

/*
//Floyd 최단 경로 알고리즘

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000

typedef struct GraphType {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int A[MAX_VERTICES][MAX_VERTICES];

void print_A(GraphType* g)
{
	int i, j;
	printf("================================\n");
	for (i = 0; i < g->n; i++)
	{
		for (j = 0; j < g->n; j++)
		{
			if (A[i][j] == INF)
			{
				printf(" * ");
			}
			else
			{
				printf("%3d ", A[i][j]);
			}
		}
		printf("\n");
	}
	printf("================================\n");
}

void floyd(GraphType* g)
{
	int i, j, k;
	for (i = 0; i < g->n; i++)
	{
		for (j = 0; j < g->n; j++)
		{
			A[i][j] = g->weight[i][j];
		}
	}
	print_A(g);

	for (k = 0; k < g->n; k++)
	{
		for (i = 0; i < g->n; i++)
		{
			for (j = 0; j < g->n; j++)
			{
				if (A[i][k] + A[k][j] < A[i][j])
				{
					A[i][j] = A[i][k] + A[k][j];
				}
			}
		}
		print_A(g);
	}
}

int main(void)
{
	GraphType g = { 7,
	{{0, 7, INF, INF, 3, 10, INF},
	 {7, 0, 4, 10, 2, 6, INF},
	 {INF, 4, 0, 2,INF,INF,INF},
	 {INF, 10, 2, 0, 11, 9, 4},
	 {3, 2, INF, 11, 0, INF, 5},
	 {10, 6, INF, 9, INF, 0, INF},
	 {INF, INF, INF, 4, 5, INF, 0}}
	};
	floyd(&g);
	return 0;
}*/

//위상 정렬
