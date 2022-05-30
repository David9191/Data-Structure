#include "arraygraph.h"
#include "linkedliststack.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
	ArrayGraph *new;

	new = createArrayDirectedGraph(5);
	if(!new)
		return (FALSE);
	addVertexAG(new, 0);
	addVertexAG(new, 1);
	addVertexAG(new, 2);
	addVertexAG(new, 3);
	addVertexAG(new, 4);
	addEdgeAG(new, 0, 1);
	addEdgeAG(new, 1, 2);
	addEdgeAG(new, 2, 0);
	addEdgeAG(new, 2, 3);
	addEdgeAG(new, 3, 2);
	addEdgeAG(new, 3, 4);
	addEdgeAG(new, 1, 4);
	printf("DFS : \n");
	DFS(new, 4);
   /* removeVertexAG(new, 3);
    printf("ArrayGraph : \n");
    displayArrayGraph(new);
    removeEdgeAG(new, 0, 1);
    printf("ArrayGraph : \n");
    displayArrayGraph(new);
	deleteArrayGraph(new);
    printf("ArrayGraph : \n");
	new = NULL;
    displayArrayGraph(new);
	return 0;*/
}

ArrayGraph* createArrayGraph(int maxVertexCount)
{
	ArrayGraph  *ret;


	ret = malloc(sizeof(ArrayGraph));
	if(!ret)
		return (NULL);
	ret->maxVertexCount = maxVertexCount;
	ret->currentVertexCount = 0;
	ret->graphType = GRAPH_UNDIRECTED;
	ret->pVertex = (int *)malloc(sizeof(int) * maxVertexCount);
	if(!ret->pVertex)
	{
		free(ret);
		return (NULL);
	}
	ret->ppAdjEdge = (int **)malloc(sizeof(int *) * maxVertexCount);
	if(!ret->ppAdjEdge)
	{
		free(ret->pVertex);
		free(ret);
		return (NULL);
	}
	for (size_t i = 0; i < maxVertexCount; i++)
	{
		ret->ppAdjEdge[i] = (int *)malloc(sizeof(int) * maxVertexCount);
		if(!ret->ppAdjEdge[i])
		{
			for(int j = 0; j < i; j++)
				free(ret->ppAdjEdge[j]);
			free(ret->pVertex);
			free(ret->ppAdjEdge);
			free(ret);
			return (NULL);
		}
	}
	initArrayGraph(ret);
	return (ret);
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph  *ret;

	ret = createArrayGraph(maxVertexCount);
	if(!ret)
		return (NULL);
	ret->graphType = GRAPH_DIRECTED;
	return (ret);
}

void    initArrayGraph(ArrayGraph *pArrayGraph)
{
	for(int i = 0; i < pArrayGraph->maxVertexCount; i++)
	{
		for(int j = 0; j < pArrayGraph->maxVertexCount; j++)
			pArrayGraph->ppAdjEdge[i][j] = 0;
	}
	for(int k = 0; k < pArrayGraph->maxVertexCount; k++)
	{
		pArrayGraph->pVertex[k] = NOT_USED;
	}
	pArrayGraph->visited = malloc(sizeof(int) * pArrayGraph->maxVertexCount);
	memset(pArrayGraph->visited, NOT_VISITED, pArrayGraph->maxVertexCount);
}

void deleteArrayGraph(ArrayGraph* pGraph)
{
	if(!pGraph)
		return ;
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		memset(pGraph->ppAdjEdge[i], 0, sizeof(pGraph->maxVertexCount));
		free(pGraph->ppAdjEdge[i]);
	}
	free (pGraph->ppAdjEdge);
	memset (&pGraph->pVertex, 0, sizeof(pGraph->pVertex));
	free (pGraph->pVertex);
	free (pGraph);
}

int isEmptyAG(ArrayGraph* pGraph)
{
	if(pGraph->currentVertexCount == 0)
		return (TRUE);
	else
		return (FALSE);
}

int addVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if(!pGraph)
		return (FAIL);
	if(pGraph->currentVertexCount == pGraph->maxVertexCount)
		return (FAIL);
	if(vertexID > pGraph->maxVertexCount)
		return (FAIL);
	if(pGraph->pVertex[vertexID] == NOT_USED)
	{
		pGraph->pVertex[vertexID] = USED;
		pGraph->currentVertexCount++;
		return (SUCCESS);
	}
	return (FAIL);
}

int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if(!pGraph)
		return (FAIL);
	if (fromVertexID < 0 || fromVertexID >= pGraph->maxVertexCount
		|| toVertexID < 0 || toVertexID >= pGraph->maxVertexCount)
		return (FAIL);
	if(checkVertexValid(pGraph, fromVertexID) && checkVertexValid(pGraph, toVertexID))
	{
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = 1;
		if(pGraph->graphType == GRAPH_UNDIRECTED)
			pGraph->ppAdjEdge[toVertexID][fromVertexID] = 1; // USED? 똑같긴 할텐디 혹시 멀라서
		return (TRUE);
	}
	return (FAIL);
}

int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	if(!pGraph)
		return (FALSE);
	if (fromVertexID < 0 || fromVertexID >= pGraph->maxVertexCount
		|| toVertexID < 0 || toVertexID >= pGraph->maxVertexCount)
		return (FALSE);
	if(checkVertexValid(pGraph, fromVertexID) && checkVertexValid(pGraph, toVertexID))
	{
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
		if(pGraph->graphType == GRAPH_UNDIRECTED)
			pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
		return (TRUE);
	}
	return (FALSE);
}

int checkVertexValid(ArrayGraph* pGraph, int vertexID)
{
	if(!pGraph && (vertexID >= pGraph->maxVertexCount || vertexID < 0))
		return (ERROR); //return이 false인지 fail인지? 멀로할까
	if(pGraph->pVertex[vertexID] == NOT_USED)
		return (FALSE);
	return (TRUE);
	/*if(!pGraph)
		return (FALSE);
	for(int i = 0; i < pGraph->currentVertexCount; i++)
	{
	//    if(pGraph->pVertex[i] == vertexID)
	 //       return (FALSE);
	}
	return (TRUE);*/
}

int removeVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if(!pGraph)
		return (FAIL);
	if(checkVertexValid(pGraph, vertexID))
	{
		pGraph->pVertex[vertexID] = NOT_USED;
		for(int i = 0; i < pGraph->maxVertexCount; i++)
		{
			for(int j = 0; j < pGraph->maxVertexCount; j++)
			{
				if(i == vertexID || j == vertexID)
					pGraph->ppAdjEdge[i][j] = 0;
			}
		}
		return (SUCCESS);
	}
	return (FAIL);
}

int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if(!pGraph)
		return (FAIL);
	if(!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FAIL);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
	if(pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
	return (SUCCESS);
}

void displayArrayGraph(ArrayGraph* pGraph)
{
	if(!pGraph)
		return ;
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		for (int j = 0; j < pGraph->maxVertexCount; j++)
			printf("%d ", pGraph->ppAdjEdge[i][j]);
		printf("\n");
	} 
}

void DFS(ArrayGraph *pGraph, int vertexID)
{
	if (!pGraph)
		return ;
	pGraph->visited[vertexID] = VISITED;
	printf("Visit %d ->", vertexID);
	for(int i = 0; i < pGraph->currentVertexCount; i++)
	{	// 전체 정점의 개수만큼 반복
		if(pGraph->ppAdjEdge[vertexID][i] && pGraph->visited[i] == NOT_VISITED)
			DFS(pGraph, i);
	}
}

void BFS(ArrayGraph *pGraph)
{
	if(!pGraph)
		return ;
	
}