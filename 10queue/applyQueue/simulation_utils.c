#include "simulation.h"

//enqueue, SimCustomer만들기. 대기목록.
void	insertCutomer(int arrivalTime, int serviceTime, LinkedQueue *pQueue)
{
	LinkedQueueNode	Node;

	if (pQueue == NULL)
		return ;
	Node.customer.arrivalTime = arrivalTime;
	Node.customer.serviceTime = serviceTime;
	Node.customer.status = arrival;
	Node.customer.startTime = 0;
	Node.customer.endTime = 0;
	Node.pLink = NULL;
	enqueueLQ(pQueue, &Node);
}

// pArrivalQueue == 고객목록, pWaitQueue 고객 도착시간 == 현재시간 됐을 때 추가해주기
void	processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue)
{
	LinkedQueueNode	*Node;

	if (pArrivalQueue != NULL && pWaitQueue != NULL)
		if (pArrivalQueue->pFrontNode->customer.arrivalTime == currentTime)
		{
			Node = dequeueLQ(pArrivalQueue);
			enqueueLQ(pWaitQueue, Node);
			free(Node);
		}
}

// pWaitQueue에서 dequeue하고, SimCustomer멤버들 start로 바꿔주기
LinkedQueueNode	*processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue)
{
	LinkedQueueNode	*NodeStart;

	if (pWaitQueue != NULL && !isLinkedQueueEmpty(pWaitQueue))
	{
		NodeStart = dequeueLQ(pWaitQueue);
		NodeStart->customer.status = start;
		NodeStart->customer.startTime = currentTime;
		NodeStart->customer.endTime = NodeStart->customer.startTime + NodeStart->customer.serviceTime;
		return (NodeStart);
	}
	return (NULL);
}

// SimCustomer멤버들 end로 바꿔주기, 사람 들어올때마다 pServiceUserCount++, pTotalWaitTime += startTime - arrivalTime
LinkedQueueNode	*processServiceNodeEnd(int currentTime, LinkedQueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{
	if (pServiceNode != NULL)
		if (pServiceNode->customer.endTime == currentTime)
		{
			pServiceNode->customer.status = end;
			(*pTotalWaitTime) += pServiceNode->customer.startTime - pServiceNode->customer.arrivalTime;
			(*pServiceUserCount)++;
			return (pServiceNode);
		}
	return (NULL);
}

// SimCustomer의 멤버들 보기좋게 출력해주기
void	printSimCustomer(int currentTime, SimCustomer customer)
{
	char	*str;

	if (customer.status == arrival)
		str = "arrival";
	else if (customer.status == start)
		str = "start";
	else if (customer.status == end)
		str = "end";
	else
		str = "!error!";
	printf("CurrentTime[%d] : ", currentTime);
	printf("status : %s, arrivalTime : %d, serviceTime : %d, startTime : %d, endTime : %d\n", \
	str, customer.arrivalTime, customer.serviceTime, customer.startTime, customer.endTime);
}

// pWaitQueue 관련해서 보여줄것 출력해주기. 현재 대기인원, printSimCustomer
void	printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue)
{
	LinkedQueueNode	*temp;
	int				n;

	if (pWaitQueue == NULL)
		return ;
	temp = pWaitQueue->pFrontNode;
	if (temp == NULL)
	{
		printf("pWaitQueue is Empty!\n");
		return ;
	}
	n = 0;
	printf("Waiting Count : %d\n", pWaitQueue->currentElementCount);
	while (temp != NULL)
	{
		printf("Waiting index [%d]\n", n);
		printSimCustomer(currentTime, temp->customer);
		temp = temp->pLink;
		n++;
	}
}

// printWaitQueueStatus, serviceUserCount, totalWaitTime, 평균대기시간(float)
void	printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTime)
{
	if (pWaitQueue == NULL)
		return ;
	printf("Waiting Count : %d\n", pWaitQueue->currentElementCount);
	printf("serviceUserCount : %d\n", serviceUserCount);
	printf("totalWaitTime : %d\n", totalWaitTime);
	printf("average waiting time : %.2f\n", ((float)totalWaitTime / serviceUserCount));
}
