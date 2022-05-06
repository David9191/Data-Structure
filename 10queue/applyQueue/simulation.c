#include "simulation.h"

int main()
{
	LinkedQueue		*pArrivalQueue = createLinkedQueue();
	LinkedQueue		*pWaitQueue = createLinkedQueue();
	LinkedQueueNode	*pStartNode = NULL;
	LinkedQueueNode	*pEndNode = NULL;
	int				serviceUserCount = 0;
	int				totalWaitTime = 0;
	int				t = 0;

	insertCutomer(0, 3, pArrivalQueue);
	insertCutomer(2, 2, pArrivalQueue);
	insertCutomer(4, 1, pArrivalQueue);
	insertCutomer(6, 1, pArrivalQueue);
	insertCutomer(8, 3, pArrivalQueue);
	while (t < 10)
	{
		processArrival(t, pArrivalQueue, pWaitQueue);
		pEndNode = processServiceNodeEnd(t, pStartNode, &serviceUserCount, &totalWaitTime);
		if (pStartNode == NULL)
			pStartNode = processServiceNodeStart(t, pWaitQueue);
		printWaitQueueStatus(t, pWaitQueue);
		printf("\n\n");
		if (pEndNode != NULL)
		{
			free(pEndNode);
			pEndNode = NULL;
			pStartNode = NULL;
		}
		t++;
	}
	printReport(pWaitQueue, serviceUserCount, totalWaitTime);
}
