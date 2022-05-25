#ifndef _GRAPH_ADJMATRIX_
# define _GRAPH_ADJMATRIX_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct	ArrayGraphType
{
	int		maxVertexCount;
	int		currentVertexCount;
	int		graphType;
	int		**ppAdjEdge;
	int		*pVertex;
}			ArrayGraph;

ArrayGraph*	createArrayGraph(int maxVertexCount);
ArrayGraph*	createArrayDirectedGraph(int maxVertexCount);
void		initArrayGraph(ArrayGraph* pArrayGraph);

int			checkVertexValid(ArrayGraph* pGraph, int vertexID);
int			addVertexAG(ArrayGraph* pGraph, int vertexID);

int			addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);
int			addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight);

void		displayArrayGraph(ArrayGraph* pGraph);
int			isEmptyAG(ArrayGraph* pGraph);

int			removeVertexAG(ArrayGraph* pGraph, int vertexID);
int			removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);
void		deleteArrayGraph(ArrayGraph* pGraph);

#endif

#ifndef _COMMON_GRAPH_DEF_
# define _COMMON_GRAPH_DEF_

# define USED				1 // ppAdjEdge, checkValid
# define NOT_USED			0

# define SUCCESS			1 // add
# define FAIL				0

# define TRUE				1 // is
# define FALSE				0

# define GRAPH_UNDIRECTED	1 // graphType
# define GRAPH_DIRECTED		2
#endif
