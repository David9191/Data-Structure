#include "linkedqueue.h"

LinkedQueue	*createLinkedQueue()
{
	LinkedQueue	*rt_LinkedQueue;

	rt_LinkedQueue = malloc(sizeof(LinkedQueue));
	if (!rt_LinkedQueue)
		return (NULL);
	// c에서 버그 없애주는 거라는데 솔직히 잘 모르겠음.
	memset(rt_LinkedQueue, 0, sizeof(LinkedQueue));
	rt_LinkedQueue->currentElementCount = 0;
	rt_LinkedQueue->pFrontNode = NULL;
	rt_LinkedQueue->pRearNode = NULL;
	return (rt_LinkedQueue);
}
int	isLinkedQueueEmpty(LinkedQueue *pLQueue)
{
	if (!pLQueue)
		return (FALSE);
	if (!(pLQueue->currentElementCount))
		return (TRUE);
	else
		return (FALSE);
}
int	enqueueLQ(LinkedQueue *pLQueue, LinkedQueueNode *element)
{
	LinkedQueueNode	*node;

	if (!pLQueue || !element)
		return (FALSE);
	node = malloc(sizeof(LinkedQueueNode));
	if (!node)
		return (FALSE);
	node->data = element->data;
	node->pLink = NULL;
	if (isLinkedQueueEmpty(pLQueue))
	{
		pLQueue->pFrontNode = node;
		pLQueue->pRearNode = node;
	}
	else
	{
		pLQueue->pRearNode->pLink = node;
		pLQueue->pRearNode = node;
	}
	pLQueue->currentElementCount++;
	return (TRUE);
}
LinkedQueueNode	*dequeueLQ(LinkedQueue *pLQueue)
{
	LinkedQueueNode	*rt_node;

	if (!pLQueue || isLinkedQueueEmpty(pLQueue))
		return (NULL);
	rt_node = pLQueue->pFrontNode;
	pLQueue->pFrontNode = pLQueue->pFrontNode->pLink;
	pLQueue->currentElementCount--;
	return (rt_node);
}
LinkedQueueNode	*peekLQ(LinkedQueue *pLQueue)
{
	LinkedQueueNode	*rt_node;

	if (!pLQueue || isLinkedQueueEmpty(pLQueue))
		return (NULL);
	rt_node = malloc(sizeof(LinkedQueueNode));
	if (!rt_node)
		return (NULL);
	rt_node->data = pLQueue->pFrontNode->data;
	rt_node->pLink = pLQueue->pFrontNode->pLink;
	return (rt_node);
}
void	deleteLinkedQueue(LinkedQueue *pLQueue)
{
	LinkedQueueNode	*del;
	
	if (pLQueue == NULL)
		return ;
	while (pLQueue->currentElementCount > 0)
	{
		del = dequeueLQ(pLQueue);
		free (del);
	}
	free (pLQueue);
	pLQueue = NULL;
}
LinkedQueue* copyLinkedQueue(LinkedQueue* pLQueue)
{
	LinkedQueue     *newLinkedQueue;
	LinkedQueueNode *temp;

	newLinkedQueue = (LinkedQueue *)malloc(sizeof(LinkedQueue));
	if (newLinkedQueue == NULL)
		return (NULL);
	temp = pLQueue->pFrontNode;
	while (temp)
	{
		enqueueLQ(newLinkedQueue, temp);
		temp = temp->pLink;
	}
	return (newLinkedQueue);
}
void    displayLQ(LinkedQueue* pLQueue)
{
	LinkedQueueNode *temp;

	if (pLQueue == NULL)
		printf("ArrayQueue is NULL\n");
	else if (isLinkedQueueEmpty(pLQueue))
		printf("ArrayQueue is Empty\n");
	else
	{
		temp = pLQueue->pFrontNode;
		printf("front ");
		while (temp)
		{
			printf("| %c ", temp->data);
			temp = temp->pLink;
		}
		printf("| end\n");
	}
}
int main()
{
	LinkedQueue *lq;
	LinkedQueue *lq2;
	LinkedQueueNode *temp;

	// createArrayQueue
	lq = createLinkedQueue();
	printf("< createLinkedQueue >\n");
	displayLQ(lq);
	
	printf("\n< isLinkedQueueEmpty >\n");
	printf("isLinkedQueueEmpty : %d\n", isLinkedQueueEmpty(lq));

	printf("\n< enqueueLQ 3times >\n");
	enqueueLQ(lq, &((LinkedQueueNode){'a', NULL}));
	displayLQ(lq);
	enqueueLQ(lq, &((LinkedQueueNode){'b', NULL}));
	displayLQ(lq);
	enqueueLQ(lq, &((LinkedQueueNode){'c', NULL}));
	displayLQ(lq);

	// printf("\n< canEnqueueCount >\n");
	// printf("canEnqueueCount : %d\n", canEnqueueCount(lq));

	printf("\n< enqueueLQ 2times >\n");
	enqueueLQ(lq, &((LinkedQueueNode){'d', NULL}));
	displayLQ(lq);
	enqueueLQ(lq, &((LinkedQueueNode){'e', NULL}));
	displayLQ(lq);

	printf("\n< copyLinkedQueue >\n");
	lq2 = copyLinkedQueue(lq);
	displayLQ(lq2);

	printf("\n< dequeueLQ 3times >\n");
	temp = dequeueLQ(lq); printf("dequeueLQ->data : %c | ", temp->data); displayLQ(lq); free(temp);
	temp = dequeueLQ(lq); printf("dequeueLQ->data : %c | ", temp->data); displayLQ(lq); free(temp);
	temp = dequeueLQ(lq); printf("dequeueLQ->data : %c | ", temp->data); displayLQ(lq); free(temp);

	printf("\n< peekLQ >\n");
	temp = peekLQ(lq);
	printf("peekLQ : %c\n", temp->data);

	printf("\n< deleteLinkedQueue >\n");
	deleteLinkedQueue(lq);
	lq = NULL;
	displayLQ(lq);

	printf("\n< leaks check >\n");
	system("leaks a.out");
}