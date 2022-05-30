#ifndef _GRAPH_ADJMATRIX_
#define _GRAPH_ADJMATRIX_

typedef struct ArrayGraphType
{
	int maxVertexCount;		// �ִ� ��� ����
	int currentVertexCount;	// ���� ���Ǵ� ����� ����
	int graphType;			// �׷��� ����: 1-Undirected, 2-Directed
	int **ppAdjEdge;		// ���� ������ ���� 2���� array
	int *pVertex;
	int	*visited;			// ��� ������ ���� 1���� array
} ArrayGraph;


ArrayGraph* createArrayGraph(int maxVertexCount);
ArrayGraph* createArrayDirectedGraph(int maxVertexCount);


void deleteArrayGraph(ArrayGraph* pGraph);


int isEmptyAG(ArrayGraph* pGraph);


int addVertexAG(ArrayGraph* pGraph, int vertexID);


int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight);


int checkVertexValid(ArrayGraph* pGraph, int vertexID);

int removeVertexAG(ArrayGraph* pGraph, int vertexID);

int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);

// �׷��� ���� ���
void displayArrayGraph(ArrayGraph* pGraph);

void initArrayGraph(ArrayGraph *pArrayGraph);

void DFS(ArrayGraph *pGraph, int vertexID);

void BFS(ArrayGraph *pGraph);


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
