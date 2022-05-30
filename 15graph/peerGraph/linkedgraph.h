#ifndef _GRAPH_ADJMATRIX_
#define _GRAPH_ADJMATRIX_

#include "graphlinkedlist.h"

typedef struct LinkedGraphType
{
	int			maxVertexCount;		// �ִ� ��� ����
	int			currentVertexCount;	// ���� ���Ǵ� ����� ����
	int 		graphType;			// �׷��� ����: 1-Undirected, 2-Directed
	LinkedList	**ppAdjEdge;		// ���� ������ ���� 2���� array
	int 		*pVertex;			// ��� ������ ���� 1���� array
} LinkedGraph;

// �׷��� ����
LinkedGraph* createLinkedGraph(int maxVertexCount);
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount);

// �׷��� ����
void deleteLinkedGraph(LinkedGraph* pGraph);

// ���� �׷��� ���� �Ǵ�
int isEmptyLG(LinkedGraph* pGraph);

// ��� �߰�
int addVertexLG(LinkedGraph* pGraph, int vertexID);

// ���� �߰�
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight);

// ����� ��ȿ�� ����.
int checkVertexValid(LinkedGraph* pGraph, int vertexID);

// ��� ����
int removeVertexLG(LinkedGraph* pGraph, int vertexID);

// ���� ����
int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);

// �׷��� ���� ���
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
