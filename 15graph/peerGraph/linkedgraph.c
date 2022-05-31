#include "linkedgraph.h"

int main()
{
	LinkedGraph *new;

	// new = createLinkedGraph(4);
	new = createLinkedDirectedGraph(4);
	if (!new)
		return (FALSE);
	addVertexLG(new, 0);
	addVertexLG(new, 1);
	addVertexLG(new, 2);
	addVertexLG(new, 3);
	addEdgeLG(new, 0, 1);
	addEdgeLG(new, 1, 2);
	addEdgeLG(new, 2, 0);
	addEdgeLG(new, 2, 3);
	addEdgeLG(new, 3, 2);
	printf("LinkedGraph : \n");
	displayLinkedGraph(new);


	removeVertexLG(new, 3);
	printf("LinkedGraph : \n");
	displayLinkedGraph(new);
	deleteLinkedGraph(new);
	return 0;
}

LinkedGraph	*createLinkedGraph(int maxVertexCount)
{
	LinkedGraph *ret;

	if (maxVertexCount < 0)
		return (NULL);
	ret = malloc(sizeof(LinkedGraph));
	if (!ret)
		return (NULL);
	ret->maxVertexCount = maxVertexCount;
	ret->currentVertexCount = 0;
	ret->graphType = GRAPH_UNDIRECTED;
	ret->pVertex = malloc(sizeof(int) * maxVertexCount);
	memset(ret->pVertex, NOT_USED, maxVertexCount);
	if (!(ret->pVertex))
	{
		free (ret->ppAdjEdge);
		free (ret);
		return (NULL);
	}
	ret->ppAdjEdge = calloc(maxVertexCount, sizeof(LinkedList *) * maxVertexCount);
	if (!(ret->ppAdjEdge))
	{
		free (ret->pVertex);
		free (ret);
		return (NULL);
	}
	for(int i = 0; i < maxVertexCount; i++)
	{
		ret->ppAdjEdge[i] = createLinkedList();
		if (!ret->ppAdjEdge[i])
		{
			for(int j = 0; j < i - 1; j++)
				free(ret->ppAdjEdge[j]);
			free(ret->ppAdjEdge);
			free(ret->pVertex);
			free(ret);
			return (NULL);
		}
	}
	return (ret);
}

LinkedGraph	*createLinkedDirectedGraph(int maxVertexCount)
{
	LinkedGraph *ret;

	if (maxVertexCount < 0)
		return(NULL);
	ret = createLinkedGraph(maxVertexCount);
	ret->graphType = GRAPH_DIRECTED;
	return (ret);
}

void	deleteLinkedGraph(LinkedGraph *pGraph)
{
	if (!pGraph || isEmptyLG(pGraph))
		return ;
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		deleteLinkedList(pGraph->ppAdjEdge[i]);
	}
	free (pGraph->pVertex);
	free (pGraph->ppAdjEdge);
	free (pGraph);
}

int	isEmptyLG(LinkedGraph *pGraph)
{
	if (pGraph && pGraph->currentVertexCount == 0)
		return (TRUE);
	return (FALSE);
}

int	addVertexLG(LinkedGraph *pGraph, int vertexID)
{
	if (!pGraph || vertexID < 0 || vertexID >= pGraph->maxVertexCount)
		return (FAIL);
	if (checkVertexValid(pGraph, vertexID) == FALSE)
	{
		pGraph->pVertex[vertexID] = USED;
		pGraph->currentVertexCount++;
		return (SUCCESS);
	}
	return (FAIL);
}


int	addEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
	int			check = 0;
	LinkedList	*list;
	ListNode	*node;

	if (!pGraph || checkVertexValid(pGraph, fromVertexID) != TRUE
		|| checkVertexValid(pGraph, toVertexID) != TRUE)
		return (FAIL);
	list = pGraph->ppAdjEdge[fromVertexID];
	node = list->headerNode.pLink;
	// 중복 제거 추가.
	for (int i = 0; i < list->currentElementCount; i++)
	{
		if (node->data.vertexID == toVertexID)
		{
			check = 1;
			break ;
		}
		node = node->pLink;
	}
	if (check == 1)
		return (FAIL);
	addLLElement(pGraph->ppAdjEdge[fromVertexID], 0, (ListNode){ {toVertexID, 0}, NULL });
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		addLLElement(pGraph->ppAdjEdge[toVertexID], 0, (ListNode){ {fromVertexID, 0}, NULL });
	return (SUCCESS);
}


int	addEdgewithWeightLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID, int weight)
{
	if (!pGraph || checkVertexValid(pGraph, fromVertexID) != TRUE
		|| checkVertexValid(pGraph, toVertexID) != TRUE)
		return (FAIL);
	addLLElement(pGraph->ppAdjEdge[fromVertexID], 0, (ListNode){ {toVertexID, weight}, NULL });
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		addLLElement(pGraph->ppAdjEdge[toVertexID], 0, (ListNode){ {fromVertexID, weight}, NULL });
	return (SUCCESS);

}

int	checkVertexValid(LinkedGraph *pGraph, int vertexID)
{
	if (!pGraph || vertexID < 0 || vertexID >= pGraph->maxVertexCount)
		return (ERROR);
	if (pGraph->pVertex[vertexID] == NOT_USED)
		return (FALSE);
	return (TRUE);
}

int	removeVertexLG(LinkedGraph *pGraph, int vertexID)
{
	ListNode	*tmp;

	if (!pGraph || checkVertexValid(pGraph, vertexID) != TRUE || isEmptyLG(pGraph))
		return (FAIL);
	for (int i = 0; i < pGraph->currentVertexCount; i++)
	{
		tmp = pGraph->ppAdjEdge[i]->headerNode.pLink;
		// 링크드 리스트 전체 삭제
		if (i == vertexID)
			clearLinkedList(pGraph->ppAdjEdge[i]);
		// 다른 vertex에서도 삭제하고자 하는 vertex가 있을 수 있으니 그 아이를 삭제
		for (int j = 0; j < getLinkedListLength(pGraph->ppAdjEdge[i]); j++)
		{
			if (tmp->data.vertexID == vertexID)
			{
				removeLLElement(pGraph->ppAdjEdge[i], j);
				break ;
			}
			tmp = tmp->pLink;
		}
	}
	pGraph->pVertex[vertexID] = NOT_USED;
	pGraph->currentVertexCount--;
	return (SUCCESS);
}

int	removeEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
	ListNode	*tmp;

	if (!pGraph || checkVertexValid(pGraph, fromVertexID) != TRUE
		|| checkVertexValid(pGraph, toVertexID) != TRUE || isEmptyLG(pGraph))
		return (FAIL);
	tmp = pGraph->ppAdjEdge[fromVertexID]->headerNode.pLink;
	// from -> to 간선 지워주는 작업
	for (int i = 1; i < getLinkedListLength(pGraph->ppAdjEdge[fromVertexID]); i++)
	{
		if (tmp->data.vertexID == toVertexID)
			removeLLElement(pGraph->ppAdjEdge[fromVertexID], i);
		tmp = tmp->pLink;
	}
	// 무방향이면 반대도 해줘야 하니까 삭제해주는 작업.
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		tmp = pGraph->ppAdjEdge[toVertexID]->headerNode.pLink;
		for (int j = 1; j < getLinkedListLength(pGraph->ppAdjEdge[toVertexID]); j++)
		{
			if (tmp->data.vertexID == fromVertexID)
				removeLLElement(pGraph->ppAdjEdge[toVertexID], j);
			tmp = tmp->pLink;
		}
	}
	return (SUCCESS);
}

void	displayLinkedGraph(LinkedGraph *pGraph)
{
	ListNode	*tmp;

	if (!pGraph)
		return ;
	for (int i = 0; i < pGraph->currentVertexCount; i++)
	{
		tmp = pGraph->ppAdjEdge[i]->headerNode.pLink;
		printf("%d : ", i);
		for (int j = 1; j <= getLinkedListLength(pGraph->ppAdjEdge[i]); j++)
		{
			printf("%d ", tmp->data.vertexID);
			tmp = tmp->pLink;
		}
		printf("\n");
	}
	printf("\n");
}
