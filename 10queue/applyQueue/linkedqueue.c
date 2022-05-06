#include "simulation.h"

LinkedQueue	*createLinkedQueue()
{
	LinkedQueue	*newLinkedQueue;

	newLinkedQueue = (LinkedQueue *)malloc(sizeof(LinkedQueue));
	if (newLinkedQueue == NULL)
		return (NULL);
	newLinkedQueue->currentElementCount = 0;
	newLinkedQueue->pFrontNode = NULL;
	newLinkedQueue->pRearNode = NULL;
	return (newLinkedQueue);
}

int	isLinkedQueueEmpty(LinkedQueue *pLQueue)
{
	if (pLQueue == NULL)
		return (FALSE);
	if (pLQueue->currentElementCount == 0)
		return (TRUE);
	else
		return (FALSE);
}

int	enqueueLQ(LinkedQueue *pLQueue, LinkedQueueNode *element)
{
	LinkedQueueNode	*newNode;

	if (!pLQueue || !element)
		return (FALSE);
	newNode = malloc(sizeof(LinkedQueueNode));
	if (newNode == NULL)
		return (FALSE);
	newNode->customer = element->customer;
	newNode->pLink = NULL;
	if (isLinkedQueueEmpty(pLQueue))
	{
		pLQueue->pFrontNode = newNode;
		pLQueue->pRearNode = newNode;
	}
	else
	{
		pLQueue->pRearNode->pLink = newNode;
		pLQueue->pRearNode = newNode;
	}
	pLQueue->currentElementCount++;
	return (TRUE);
}

LinkedQueueNode	*dequeueLQ(LinkedQueue *pLQueue)
{
	LinkedQueueNode	*lq;

	if (pLQueue == NULL)
	{
		printf("LinkedQueue is NULL\n");
		return (NULL);
	}
	if (isLinkedQueueEmpty(pLQueue))
	{
		printf("LinkedQueue is Empty\n");
		return (NULL);
	}
	lq = pLQueue->pFrontNode;
	if (pLQueue->currentElementCount == 1)
	{
		pLQueue->pFrontNode = NULL;
		pLQueue->pRearNode = NULL;
		pLQueue->currentElementCount--;
	}
	else
	{
		pLQueue->pFrontNode = pLQueue->pFrontNode->pLink;
		pLQueue->currentElementCount--;
	}
	return (lq);
}

LinkedQueueNode	*peekLQ(LinkedQueue *pLQueue)//copy
{
	LinkedQueueNode	*lq;

	if (pLQueue == NULL)
	{
		printf("LinkedQueue is NULL\n");
		return (NULL);
	}
	if (isLinkedQueueEmpty(pLQueue))
	{
		printf("LinkedQueue is Empty\n");
		return (NULL);
	}
	lq = (LinkedQueueNode *)malloc(sizeof(LinkedQueueNode));
	if (lq == NULL)
		return (NULL);
	lq->customer = pLQueue->pFrontNode->customer;
	lq->pLink = pLQueue->pFrontNode->pLink;
	return (lq);
}

void	deleteLinkedQueue(LinkedQueue *pLQueue)
{
	LinkedQueueNode	*temp;

	if (pLQueue == NULL)
		return ;
	if (isLinkedQueueEmpty(pLQueue))
	{
		printf("LinkedQueue is Empty\n");
		return ;
	}
	while (pLQueue->currentElementCount > 0)
	{
		temp = dequeueLQ(pLQueue);
		free(temp);
	}
	free(pLQueue);
	pLQueue = NULL;
}

LinkedQueue	*copyLinkedQueue(LinkedQueue *pLQueue)
{
	LinkedQueue		*newLinkedQueue;
	LinkedQueueNode	*temp;

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

void	displayLQ(LinkedQueue *pLQueue)
{
	LinkedQueueNode	*temp;

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
			printf("| %d, %d ", temp->customer.arrivalTime, temp->customer.serviceTime);
			temp = temp->pLink;
		}
		printf("| end\n");
	}
}
