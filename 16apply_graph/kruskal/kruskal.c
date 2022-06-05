#include "arraygraph.h"
#include "heap.h"
#include <stdlib.h>

typedef struct DisjointSet
{
	int *parent;
	int *sizeOfSet;
} DisjointSet;

void initDisjointSet(DisjointSet *set, int size)
{
	int i;

	set->parent = malloc(sizeof(int) * size);
	set->sizeOfSet = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++) {
		set->parent[i] = -1;
		set->sizeOfSet[i] = 1;
	}
}

int setFind(DisjointSet *set, int vertex)
{
	int parent = -1;
	int root = -1;
	int i = -1;

	for (i = vertex; (parent = set->parent[i]) >= 0; i = parent);
	root = i;
	for (i = vertex; (parent = set->parent[i]) >= 0; i = parent)
		set->parent[i] = root;
	return root;
}

void setUnion(DisjointSet *set, int s1, int s2)
{
	if (set->sizeOfSet[s1] > set->sizeOfSet[s2])
	{
		set->parent[s1] = s2;
		set->sizeOfSet[s2] += set->sizeOfSet[s1];
	}
	else
	{
		set->parent[s2] = s1;
		set->sizeOfSet[s1] += set->sizeOfSet[s2];
	}
}

void addVertexToHeap(ArrayGraph *graph, ArrayMinHeap *heap)
{
	for (int i = 0; i < graph->maxVertexCount; i++)
	{
		for (int j = i + 1; j < graph->maxVertexCount; j++)
		{
			if (graph->ppAdjEdge[i][j])
			{
				insertMinHeap(heap, (HeapNode){graph->ppAdjEdge[i][j], i , j});
			}
		}
	}
	displayMinHeap(heap);
}

ArrayGraph *kruskal(ArrayGraph *graph)
{
	ArrayGraph *result;
	ArrayMinHeap *sortedEdges;
	HeapNode *edge;
	DisjointSet edges;

	int vertexCount = graph->maxVertexCount;
	int edgeCount = 0;
	int uset;
	int vset;

	result = createArrayGraph(vertexCount);
	initDisjointSet(&edges, vertexCount);
	sortedEdges = createMinHeap((vertexCount * (vertexCount - 1)) / 2 );
	addVertexToHeap(graph, sortedEdges);
	
	while (edgeCount < graph->maxVertexCount - 1)
	{
		//힙에서 데이터 추출
		edge = removeMinHeap(sortedEdges);
		if (edge == NULL)
			break;
		printf("removed node \nfrom : %d, to : %d, weight: %d\n", edge->from, edge->to, edge->data);
		//displayMinHeap(sortedEdges);
		printf("\n");
		uset = setFind(&edges, edge->from);
		vset = setFind(&edges, edge->to);
		if (uset != vset)
		{
			edgeCount++;
			setUnion(&edges, uset, vset);
			addVertexAG(result, edge->to);
			addVertexAG(result, edge->from);
			addEdgewithWeightAG(result, edge->from, edge->to, edge->data);
		}
	}

	return result;
}

int main()
{
	ArrayGraph *graph;
	ArrayGraph *minimumSpanningTree;
	graph = createArrayGraph(6);
	for (int i = 0; i < 6; i++)
	{
		addVertexAG(graph, i);
	}
	addEdgewithWeightAG(graph, 0, 1, 4);
	addEdgewithWeightAG(graph, 1, 2, 2);
	addEdgewithWeightAG(graph, 2, 0, 3);
	addEdgewithWeightAG(graph, 2, 3, 1);
	addEdgewithWeightAG(graph, 3, 4, 1);
	addEdgewithWeightAG(graph, 4, 5, 6);
	addEdgewithWeightAG(graph, 3, 5, 5);
	displayArrayGraph(graph);
	minimumSpanningTree = kruskal(graph);
	displayArrayGraph(minimumSpanningTree);
}