#ifndef _GRAPH_ADJMATRIX_
#define _GRAPH_ADJMATRIX_

#include "linkedliststack.h"
#include "linkedqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct ArrayGraphType
{
	int	maxVertexCount;
	int	currentVertexCount;
	int	graphType;
	int	**ppAdjEdge;
	int	*pVertex;
	int	*visited;
	int	*intersection;
}		ArrayGraph;


ArrayGraph	*createArrayGraph(int maxVertexCount);
ArrayGraph	*createArrayDirectedGraph(int maxVertexCount);
void		initArrayGraph(ArrayGraph *pArrayGraph);

void		deleteArrayGraph(ArrayGraph *pGraph);

int			isEmptyAG(ArrayGraph *pGraph);

int			checkVertexValid(ArrayGraph *pGraph, int vertexID);
int			addVertexAG(ArrayGraph *pGraph, int vertexID);
int			addEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID);
int			addEdgewithWeightAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID, int weight);

int			removeVertexAG(ArrayGraph *pGraph, int vertexID);
int			removeEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID);

void		is_intersection(ArrayGraph *pGraph, int vertexID);
void		recursive_DFS(ArrayGraph *pGraph, int vertexID);
void		stack_DFS(ArrayGraph *pGraph, int vertexID);
void		BFS(ArrayGraph *pGraph, int vertexID);
void		DFS(ArrayGraph *pGraph, int vertexID);

void		displayArrayGraph(ArrayGraph *pGraph);

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

#define VISITED				1
#define NOT_VISITED			0

#define GRAPH_UNDIRECTED	1
#define GRAPH_DIRECTED		2
#endif
