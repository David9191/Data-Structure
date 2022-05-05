#ifndef _SIMDEF_H_
#define _SIMDEF_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "10queue/linkedqueue/linkedqueue.h"

typedef enum SimStatusType
{
	arrival, start, end // 이러면 0부터 각 변수별로 + 1만큼 됨. 신기하네.
}	SimStatus;
typedef struct SimCustomerType
{
	SimStatus	status;
	int 		arrivalTime;
	int 		serviceTime;
	int 		startTime;
	int 		endTime;
}				SimCustomer;
void	insertCutomer(int arrivalTime, int processTime, LinkedQueue *pQueue);
void	processArrival(int currentTime, LinkedQueue *pArrivalQueue,
	LinkedQueue *pWaitQueue);
LinkedQueueNode	*processServiceNodeStart(int currentTime,
	LinkedQueue *pWaitQueue);
LinkedQueueNode	*processServiceNodeEnd(int currentTime,
	LinkedQueueNode *pServiceNode, int *pServiceUserCount,
	int *pTotalWaitTime);
void	printSimCustomer(int currentTime, SimCustomer customer);
void	printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue);
void	printReport(LinkedQueue *pWaitQueue, 
	int serviceUserCount, int totalWaitTime);

#endif