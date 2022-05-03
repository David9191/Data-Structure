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
	return (rt_LinkedQueue);

}
int	isLinkedQueueEmpty(LinkedQueue* pLQueue);
int	enqueueLQ(LinkedQueue* pLQueue, LinkedQueueNode *element);
LinkedQueueNode	*dequeueLQ(LinkedQueue* pLQueue);
LinkedQueueNode	*peekLQ(LinkedQueue* pLQueue);
void	deleteLinkedQueue(LinkedQueue* pLQueue);
LinkedQueue	*copyLinkedQueue(LinkedQueue* pLQueue);
void	displayLQ(LinkedQueue* pLQueue);
