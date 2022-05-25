#include "arraygraph.h"

ArrayGraph	*createArrayGraph(int maxVertexCount)
{
	ArrayGraph	*ret = NULL;
	int			edge[maxVertexCount][maxVertexCount];
	int			vertex[maxVertexCount];

	ret = malloc(sizeof(ArrayGraph));
	if(ret)
	{
		ret->maxVertexCount = maxVertexCount;
		ret->currentVertexCount = 0;
		ret->graphType = GRAPH_UNDIRECTED;
		ret->ppAdjEdge = edge;
		ret->pVertex = vertex;
		initArrayGraph(ret);
	}
	return (ret);
}

void	initArrayGraph(ArrayGraph *pArrayGraph)
{
	if (pArrayGraph)
	{
		for(int i = 0; i < pArrayGraph->maxVertexCount; i++)
		{
			for(int j = 0; j < pArrayGraph->maxVertexCount; j++)
			{
				pArrayGraph->ppAdjEdge[i][j] = NOT_USED;
			}
		}
	}
}

int	checkVertexValid(ArrayGraph *pGraph, int vertexID)
{
	if(pGraph && (pGraph->currentVertexCount == pGraph->maxVertexCount))
	{
		for(int i = 0; i < pGraph->currentVertexCount; i++)
		{
			if(pGraph->pVertex[i] == vertexID)
				return (FALSE);
		}
		return (TRUE);
	}
	return (FALSE);
}

int	addVertexAG(ArrayGraph *pGraph, int vertexID)
{
	if(pGraph && checkVertexValid(pGraph, vertexID))
	{
		pGraph->pVertex[pGraph->currentVertexCount] = vertexID;
		pGraph->currentVertexCount++;
		return (SUCCESS);
	}
	return (FAIL);
}

int	addEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID)
{
	if(pGraph
		&& (!checkVertexValid(pGraph, fromVertexID) // fromVertexID가 존재한다면
		&& !checkVertexValid(pGraph, toVertexID))) // toVertexID가 존재한다면
	{
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = USED;
		return (SUCCESS);
	}
	return (FAIL);
}

int	addEdgewithWeightAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID, int weight)
{
	if(pGraph
		&& (!checkVertexValid(pGraph, fromVertexID)
		&& !checkVertexValid(pGraph, toVertexID)))
	{
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
		return (SUCCESS);
	}
	return (FAIL);
}

void	displayArrayGraph(ArrayGraph *pGraph)
{
	if(pGraph)
	{
		for (int i = 0; i < pGraph->maxVertexCount; i++)
		{
			for (int j = 0; j < pGraph->maxVertexCount; j++)
			{
				printf("%d ", pGraph->ppAdjEdge[i][j]);
			}
			printf("\n");
		}
	}
}

int	isEmptyAG(ArrayGraph *pGraph)
{
	if (pGraph)
	{
		if(pGraph->currentVertexCount == 0)
			return (TRUE);
		else
			return (FALSE);
	}
}

int	removeVertexAG(ArrayGraph *pGraph, int vertexID)
{
	if(pGraph && !checkVertexValid(pGraph, vertexID))
	{
		pGraph->pVertex[vertexID] = 0;
		for(int i = 0; i < pGraph->maxVertexCount; i++)
		{
			for(int j = 0; j < pGraph->maxVertexCount; i++)
			{
				if(i == vertexID || j == vertexID)
					pGraph->ppAdjEdge[i][j] = 0;
			}
		}
		for(int k = 0; k < pGraph->currentVertexCount - 1; k++)
			pGraph->pVertex[k] == pGraph->pVertex[k + 1];
		return (TRUE);
	}
	return (FALSE);
}

int	removeEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID)
{
	if(pGraph)
	{
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
		return (TRUE);
	}
	return (FALSE);
}

void	deleteArrayGraph(ArrayGraph *pGraph)
{
	if(pGraph)
	{
		for (int i = 0; i < pGraph->maxVertexCount; i++)
			memset(pGraph->ppAdjEdge[i], 0, sizeof(pGraph->maxVertexCount));
		memset(pGraph->pVertex, 0, sizeof(pGraph->pVertex));
		free (pGraph);
	}
}
