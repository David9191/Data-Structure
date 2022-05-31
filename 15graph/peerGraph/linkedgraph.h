#ifndef _GRAPH_ADJMATRIX_
#define _GRAPH_ADJMATRIX_

#include "graphlinkedlist.h"
#include "linkedliststack.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct LinkedGraphType
{
	int			maxVertexCount;
	int			currentVertexCount;
	int 		graphType;
	LinkedList	**ppAdjEdge;
	int 		*pVertex;
} LinkedGraph;

LinkedGraph* createLinkedGraph(int maxVertexCount);
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount);

void deleteLinkedGraph(LinkedGraph* pGraph);

int isEmptyLG(LinkedGraph* pGraph);

int addVertexLG(LinkedGraph* pGraph, int vertexID);

int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight);

int checkVertexValid(LinkedGraph* pGraph, int vertexID);

int removeVertexLG(LinkedGraph* pGraph, int vertexID);

int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);

void displayLinkedGraph(LinkedGraph* pGraph);

void DFS(LinkedGraph *pGraph, int vertexID);

void BFS(LinkedGraph *pGraph, int vertexID);

#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define USED				1
#define NOT_USED			0

#define SUCCESS				1
#define FAIL				0

#define TRUE				1
#define FALSE				0
#define ERROR				-1

#define GRAPH_UNDIRECTED	1
#define GRAPH_DIRECTED		2


#endif
