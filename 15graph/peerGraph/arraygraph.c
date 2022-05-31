#include "arraygraph.h"

int main()
{
	ArrayGraph	*new;

	new = createArrayDirectedGraph(6);
	if (!new)
		return (FALSE);
	addVertexAG(new, 0);
	addVertexAG(new, 1);
	addVertexAG(new, 2);
	addVertexAG(new, 3);
	addVertexAG(new, 4);
	addEdgeAG(new, 0, 1);
	addEdgeAG(new, 1, 2);
	addEdgeAG(new, 2, 3);
	addEdgeAG(new, 3, 4);
	printf ("\n");
	displayArrayGraph(new);
	// BFS(new, 0);
	printf ("\n");
	removeVertexAG(new, 3);
	displayArrayGraph(new);
	printf ("\n");
	// BFS(new, 0);
	// deleteArrayGraph(new);
	new = NULL;
	return 0;
}

ArrayGraph	*createArrayGraph(int maxVertexCount)
{
	ArrayGraph	*ret;


	ret = malloc(sizeof(ArrayGraph));
	if (!ret)
		return (NULL);
	ret->maxVertexCount = maxVertexCount;
	ret->currentVertexCount = 0;
	ret->graphType = GRAPH_UNDIRECTED;
	ret->pVertex = (int *)malloc(sizeof(int) * maxVertexCount);
	if (!ret->pVertex)
	{
		free(ret);
		return (NULL);
	}
	ret->ppAdjEdge = (int **)malloc(sizeof(int *) * maxVertexCount);
	if (!ret->ppAdjEdge)
	{
		free(ret->pVertex);
		free(ret);
		return (NULL);
	}
	for (size_t i = 0; i < maxVertexCount; i++)
	{
		ret->ppAdjEdge[i] = (int *)malloc(sizeof(int) * maxVertexCount);
		if (!ret->ppAdjEdge[i])
		{
			for (int j = 0; j < i; j++)
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

ArrayGraph	*createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph  *ret;

	ret = createArrayGraph(maxVertexCount);
	if (!ret)
		return (NULL);
	ret->graphType = GRAPH_DIRECTED;
	return (ret);
}

void	initArrayGraph(ArrayGraph *pArrayGraph)
{
	for (int i = 0; i < pArrayGraph->maxVertexCount; i++)
	{
		for (int j = 0; j < pArrayGraph->maxVertexCount; j++)
		{
			// 2차원 배열 0으로 초기화
			pArrayGraph->ppAdjEdge[i][j] = 0;
		}
	}
	for (int k = 0; k < pArrayGraph->maxVertexCount; k++)
	{
		pArrayGraph->pVertex[k] = NOT_USED;
	}
	pArrayGraph->visited = malloc(sizeof(int) * pArrayGraph->maxVertexCount);
	pArrayGraph->intersection = malloc(sizeof(int) * pArrayGraph->maxVertexCount);
	memset(pArrayGraph->visited, NOT_VISITED, pArrayGraph->maxVertexCount);
	memset(pArrayGraph->intersection, FALSE, pArrayGraph->maxVertexCount);
}

void	deleteArrayGraph(ArrayGraph *pGraph)
{
	if (!pGraph)
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

int	isEmptyAG(ArrayGraph *pGraph)
{
	if (pGraph->currentVertexCount == 0)
		return (TRUE);
	else
		return (FALSE);
}

int	addVertexAG(ArrayGraph *pGraph, int vertexID)
{
	if (!pGraph || pGraph->currentVertexCount == pGraph->maxVertexCount
		|| vertexID > pGraph->maxVertexCount)
		return (FAIL);
	if (pGraph->pVertex[vertexID] == NOT_USED)
	{
		pGraph->pVertex[vertexID] = USED;
		pGraph->currentVertexCount++;
		return (SUCCESS);
	}
	return (FAIL);
}

int	addEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID)
{
	if (!pGraph || fromVertexID >= pGraph->maxVertexCount || fromVertexID < 0
		|| toVertexID >= pGraph->maxVertexCount || toVertexID < 0)
		return (FAIL);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = 1;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = 1;
	return (TRUE);
}

int	addEdgewithWeightAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID, int weight)
{
	if (!pGraph)
		return (FALSE);
	if (fromVertexID < 0 || fromVertexID >= pGraph->maxVertexCount
		|| toVertexID < 0 || toVertexID >= pGraph->maxVertexCount)
		return (FALSE);
	if (checkVertexValid(pGraph, fromVertexID) && checkVertexValid(pGraph, toVertexID))
	{
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
		if (pGraph->graphType == GRAPH_UNDIRECTED)
			pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
		return (TRUE);
	}
	return (FALSE);
}

int	checkVertexValid(ArrayGraph *pGraph, int vertexID)
{
	if (!pGraph && (vertexID >= pGraph->maxVertexCount || vertexID < 0))
		return (ERROR);
	if (pGraph->pVertex[vertexID] == NOT_USED)
		return (FALSE);
	return (TRUE);
}

int	removeVertexAG(ArrayGraph *pGraph, int vertexID)
{
	if (pGraph && checkVertexValid(pGraph, vertexID))
	{
		pGraph->pVertex[vertexID] = NOT_USED;
		for (int i = 0; i < pGraph->maxVertexCount; i++)
		{
			for (int j = 0; j < pGraph->maxVertexCount; j++)
			{
				if (i == vertexID || j == vertexID)
					pGraph->ppAdjEdge[i][j] = 0;
			}
		}
		return (SUCCESS);
	}
	return (FAIL);
}

int	removeEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID)
{
	if (!pGraph)
		return (FAIL);
	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FAIL);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
	return (SUCCESS);
}

void	displayArrayGraph(ArrayGraph *pGraph)
{
	if (!pGraph)
		return ;
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		printf ("%d : ", i);
		for (int j = 0; j < pGraph->maxVertexCount; j++)
			printf ("%d ", pGraph->ppAdjEdge[i][j]);
		printf ("\n");
	}
}

void	stack_DFS(ArrayGraph *pGraph, int vertexID)
{
	LinkedStack	*stack;
	StackNode	*node;

	if (!pGraph)
		return;
	stack = createLinkedStack();
	pGraph->visited[vertexID] = VISITED;
	pushLS (stack, (StackNode){vertexID, NULL});
	is_intersection(pGraph, vertexID);
	while (!isLinkedStackEmpty(stack))
	{
		for (int i = 0; i < pGraph->currentVertexCount; i++)
		{
			if (pGraph->ppAdjEdge[vertexID][i] && !pGraph->visited[i])
			{
				printf ("visit -> %d\n", i);
				pushLS (stack, (StackNode){i, NULL});
				is_intersection(pGraph, i);
			}
		}
		node = popLS(stack);
		while (!pGraph->intersection[node->vertex])
			node = popLS(stack);
		vertexID = node->vertex;
	}
}

void	DFS(ArrayGraph *pGraph, int vertexID)
{
	LinkedStack	*stack;
	StackNode	*node;

	if (!pGraph)
		return;
	stack = createLinkedStack();
	pushLS (stack, (StackNode){vertexID, NULL});
	while (!isLinkedStackEmpty(stack))
	{
		node = popLS(stack);
		printf ("visit %d -> ", node->vertex);
		vertexID = node->vertex;
		for (int i = 0; i < pGraph->currentVertexCount; i++)
		{
			if (pGraph->ppAdjEdge[vertexID][i] && !pGraph->visited[i])
				pushLS (stack, (StackNode){i, NULL});
		}
	}
}

void	is_intersection(ArrayGraph *pGraph, int vertexID)
{
	int	cnt;

	if (!pGraph)
		return ;
	for (int j = 0; j < pGraph->maxVertexCount; j++)
	{
		if (pGraph->ppAdjEdge[vertexID][j] && !pGraph->visited[j])
			cnt++;
	}
	if (cnt > 1)
		pGraph->intersection[vertexID] = TRUE;
	else
		pGraph->intersection[vertexID] = FALSE;
}

void	recursive_DFS(ArrayGraph *pGraph, int vertexID)
{
	if (!pGraph)
		return ;
	pGraph->visited[vertexID] = VISITED;
	printf ("Visit %d ->", vertexID);
	for (int i = 0; i < pGraph->currentVertexCount; i++)
	{
		if (pGraph->ppAdjEdge[vertexID][i] && pGraph->visited[i] == NOT_VISITED)
			recursive_DFS(pGraph, i);
	}
}

void	BFS(ArrayGraph *pGraph, int vertexID)
{
	LinkedQueue		*queue;
	LinkedQueueNode	*node;

	if (!pGraph)
		return ;
	queue = createLinkedQueue();
	enqueueLQ (queue, (LinkedQueueNode){ vertexID, NULL });
	pGraph->visited[vertexID] = VISITED;
	while (!isLinkedQueueEmpty(queue))
	{
		node = dequeueLQ(queue);
		printf ("visit %d -> ", node->vertex);
		for (int j = 0; j < pGraph->currentVertexCount; j++)
		{
			if (pGraph->ppAdjEdge[node->vertex][j] && !pGraph->visited[j])
			{
				pGraph->visited[j] = VISITED;
				enqueueLQ (queue, (LinkedQueueNode){j, NULL});
			}
		}
		free (node);
	}
}
