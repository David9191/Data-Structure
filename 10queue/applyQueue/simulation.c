#include "simulation.h"

int main()
{
	LinkedQueue		*pArrivalQueue = createLinkedQueue();
	LinkedQueue		*pWaitQueue = createLinkedQueue();
	LinkedQueueNode	*pStartNode = NULL;
	LinkedQueueNode	*pEndNode = NULL;
	int				serviceUserCount = 0;
	int				totalWaitTime = 0;

	insertCutomer(0, 3, pArrivalQueue);
	insertCutomer(2, 2, pArrivalQueue);
	insertCutomer(4, 1, pArrivalQueue);
	insertCutomer(6, 1, pArrivalQueue);
	insertCutomer(8, 3, pArrivalQueue);
	// pStartNode = pArrivalQueue->pFrontNode;
	// 집에서 뇌버깅 해보자..!
	int	t = 0;
	while (pArrivalQueue->pRearNode || pStartNode)
	{
		processArrival(t, pArrivalQueue, pWaitQueue);
		if (pStartNode && pStartNode->customer.endTime == t)
		{
			pEndNode = processServiceNodeEnd(t, pStartNode, &serviceUserCount, &totalWaitTime);
			free (pEndNode);
			pStartNode = NULL;
		}
		if (!pStartNode)
		{
			pStartNode = processServiceNodeStart(t, pWaitQueue);
			pEndNode = NULL;
		}
		printWaitQueueStatus(t, pWaitQueue);
		t++;
	}
	printReport(pWaitQueue, serviceUserCount, totalWaitTime);
}
