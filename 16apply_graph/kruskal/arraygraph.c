#include "arraygraph.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkeddeque.h"

ArrayGraph* createArrayGraph(int maxVertexCount)
{
    ArrayGraph *pGraph;

    pGraph = (ArrayGraph *)malloc(sizeof(ArrayGraph));
    pGraph->pVertex = (int *)malloc(sizeof(int) * maxVertexCount);
    pGraph->ppAdjEdge = (int **)malloc(sizeof(int *) * maxVertexCount);
    for (int i = 0; i < maxVertexCount; i++)
    {
        pGraph->ppAdjEdge[i] = (int *)malloc(sizeof(int) * maxVertexCount);
    }
    pGraph->maxVertexCount = maxVertexCount;
    pGraph->currentVertexCount = 0;
    pGraph->graphType = GRAPH_UNDIRECTED;

    memset(pGraph->pVertex, 0, sizeof(int) * maxVertexCount);
    for (int i = 0; i < maxVertexCount; i++)
    {
        memset(pGraph->ppAdjEdge[i], 0, sizeof(int) * maxVertexCount);
    }

    return (pGraph);
}
ArrayGraph* createArrayDirectedGraph(int maxVertexCount)
{
    ArrayGraph *pGraph;

    pGraph = (ArrayGraph *)malloc(sizeof(ArrayGraph));
    pGraph->pVertex = (int *)malloc(sizeof(int) * maxVertexCount);
    pGraph->ppAdjEdge = (int **)malloc(sizeof(int *) * maxVertexCount);
    for (int i = 0; i < maxVertexCount; i++)
    {
        pGraph->ppAdjEdge[i] = (int *)malloc(sizeof(int) * maxVertexCount);
    }
    pGraph->maxVertexCount = maxVertexCount;
    pGraph->currentVertexCount = 0;
    pGraph->graphType = GRAPH_DIRECTED;

    memset(pGraph->pVertex, 0, sizeof(int) * maxVertexCount);
    for (int i = 0; i < maxVertexCount; i++)
    {
        memset(pGraph->ppAdjEdge[i], 0, sizeof(int) * maxVertexCount);
    }

    return (pGraph);
}

void deleteArrayGraph(ArrayGraph* pGraph)
{
    for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		free(pGraph->ppAdjEdge[i]);
	}
    free(pGraph->ppAdjEdge);
    free(pGraph->pVertex);
    free(pGraph);
}

int isEmptyAG(ArrayGraph* pGraph)
{
    if (pGraph->currentVertexCount == 0)
        return (TRUE);

    return (FALSE);
}

int addVertexAG(ArrayGraph* pGraph, int vertexID)
{
    if (pGraph->pVertex[vertexID] == USED)
        return (FALSE);
    pGraph->pVertex[vertexID] = USED;
    pGraph->currentVertexCount++;

    return (SUCCESS);
}

int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
    pGraph->ppAdjEdge[fromVertexID][toVertexID] = USED;
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        pGraph->ppAdjEdge[toVertexID][fromVertexID] = USED;

    return (TRUE);
}
int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
    pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
        
    return (TRUE);
}

int checkVertexValid(ArrayGraph* pGraph, int vertexID)
{
    if (pGraph->maxVertexCount < vertexID)
        return (FALSE);

    return (TRUE);
}

int removeVertexAG(ArrayGraph* pGraph, int vertexID)
{
    for (int i = 0; i < pGraph->maxVertexCount; i++)
    {
        removeEdgeAG(pGraph, vertexID, i);
        removeEdgeAG(pGraph, i, vertexID);
    }
    pGraph->pVertex[vertexID] = NOT_USED;
    pGraph->currentVertexCount--;

    return (SUCCESS);
}

int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
    pGraph->ppAdjEdge[fromVertexID][toVertexID] = NOT_USED;    
    if(pGraph->graphType == GRAPH_UNDIRECTED)
        pGraph->ppAdjEdge[toVertexID][fromVertexID] = NOT_USED;

    return (SUCCESS);
}
void displayArrayGraph(ArrayGraph* pGraph)
{
	if (!pGraph)
		return;
	printf("maxVertexCount     : %d\n", pGraph->maxVertexCount);
	printf("currentVertexCount : %d\n", pGraph->maxVertexCount);

	printf("*** ");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		printf("%d ", pGraph->pVertex[i]);
	}
	printf("\n");
	printf("*** ");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	printf("--- ");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		printf("- ");
	}
	printf("\n");

	for (int i = 0; i < pGraph->maxVertexCount; i++)
    {
		printf("%d | ", i);
        for (int j = 0; j < pGraph->maxVertexCount; j++)
        {
            printf("%d ", pGraph->ppAdjEdge[i][j]);
        }
        printf("\n");
    }
}

void DFSArrayGraph(ArrayGraph* pGraph)
{
	int vertex;
	int i = 0;
	int visited[pGraph->maxVertexCount];

	memset(visited, 0, sizeof(visited));
	LinkedDeque *deque = createLinkedDeque();

	while (i < pGraph->maxVertexCount)
	{
		if (pGraph->pVertex[i] != NOT_USED)
		{
			vertex = i;
			break;
		}
		i++;
	}
	visited[i] = 1;
	insertRearLD(deque, (DequeNode){vertex, NULL, NULL});
	while (isLinkedDequeEmpty(deque) == FALSE)
	{
		DequeNode *current = deleteRearLD(deque);
		printf("current vertex: %d\n", current->data);
		for (int j = 0; j < pGraph->maxVertexCount; j++) {
			if (pGraph->ppAdjEdge[current->data][j] > 0 && visited[j] == 0)
			{
				visited[j] = 1;
				insertRearLD(deque, (DequeNode){j, NULL, NULL});
			}
		}
	}
}

void BFSArrayGraph(ArrayGraph* pGraph)
{
	int vertex;
	int i = 0;
	int visited[pGraph->maxVertexCount];

	memset(visited, 0, sizeof(visited));
	LinkedDeque *deque = createLinkedDeque();

	while (i < pGraph->maxVertexCount)
	{
		if (pGraph->pVertex[i] != NOT_USED)
		{
			vertex = i;
			break;
		}
		i++;
	}
	visited[i] = 1;
	insertRearLD(deque, (DequeNode){vertex, NULL, NULL});
	while (isLinkedDequeEmpty(deque) == FALSE)
	{
		DequeNode *current = deleteFrontLD(deque);
		printf("current vertex: %d\n", current->data);
		for (int j = 0; j < pGraph->maxVertexCount; j++) {
			if (pGraph->ppAdjEdge[current->data][j] > 0 && visited[j] == 0)
			{
				visited[j] = 1;
				insertRearLD(deque, (DequeNode){j, NULL, NULL});
			}
		}
	}
}