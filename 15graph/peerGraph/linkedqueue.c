#include<stdlib.h>
#include<string.h>

#include"linkedqueue.h"

LinkedQueue* createLinkedQueue()
{
	LinkedQueue	*new;

	new = malloc(sizeof(LinkedQueue));

	new->currentElementCount = 0;
	new->pFrontNode = NULL;
	new->pRearNode = NULL;
	return(new);
}

int enqueueLQ(LinkedQueue* pQueue, LinkedQueueNode element)
{	
	LinkedQueueNode	*node;
	
	if (!pQueue)
		return (FALSE);
	node = malloc(sizeof(LinkedQueue));
	if(!node)
		return (FALSE);
	*node = element;
	node->pLink = NULL;
	if (!isLinkedQueueEmpty(pQueue))
	{
		pQueue->pRearNode->pLink = node;
		pQueue->pRearNode = node;
	}
	else
	{
		pQueue->pRearNode = node;
		pQueue->pFrontNode = node;
	}
	(pQueue->currentElementCount)++;
	return (TRUE);
}

LinkedQueueNode* dequeueLQ(LinkedQueue* pQueue)
{
	LinkedQueueNode	*toDelete;

	if (isLinkedQueueEmpty(pQueue))
		return (FALSE);
	toDelete = peekLQ(pQueue);
	pQueue->pFrontNode = toDelete->pLink;
	if (toDelete->pLink == NULL)
		pQueue->pRearNode = NULL;
	toDelete->pLink = NULL;
	(pQueue->currentElementCount)--;
	return (toDelete);

}
LinkedQueueNode* peekLQ(LinkedQueue* pQueue)
{
	LinkedQueueNode	*peek;

	if (isLinkedQueueEmpty(pQueue))
		return (NULL);
	peek = pQueue->pFrontNode;
	return (peek);	
}

void deleteLinkedQueue(LinkedQueue* pQueue)
{
	LinkedQueueNode	*toDelete;
	if(!pQueue)
		return ;
	while(!isLinkedQueueEmpty(pQueue))
	{
		toDelete = dequeueLQ(pQueue);
		memset(toDelete, 0, sizeof(LinkedQueueNode));
		free(toDelete);
	}
	memset(pQueue, 0, sizeof(LinkedQueue));
	free(pQueue);
}

int isLinkedQueueEmpty(LinkedQueue* pQueue)
{
	if (!pQueue)
		return (ERROR);
	return((pQueue->currentElementCount) == 0);
}

