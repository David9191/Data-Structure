#ifndef _SIMDEF_H_
#define _SIMDEF_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


typedef struct LinkedQueueNodeType
{
	SimCustomer					customer;
	struct LinkedQueueNodeType	*pLink;
} LinkedQueueNode;

typedef struct LinkedqueType
{
	int				currentElementCount;	// 현재 원소 개수
	LinkedQueueNode	*pFrontNode;			// Front 원소
	LinkedQueueNode	*pRearNode;				// Rear 원소
} LinkedQueue;

LinkedQueue		*createLinkedQueue();
int				isLinkedQueueEmpty(LinkedQueue *pLQueue);
int				enqueueLQ(LinkedQueue *pLQueue, LinkedQueueNode *element);
LinkedQueueNode	*dequeueLQ(LinkedQueue *pLQueue);
LinkedQueueNode	*peekLQ(LinkedQueue *pLQueue);
void			deleteLinkedQueue(LinkedQueue *pLQueue);
LinkedQueue		*copyLinkedQueue(LinkedQueue *pLQueue);
void			displayLQ(LinkedQueue *pLQueue);


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

#ifndef _SYMBOL_
#define _SYMBOL_

#define FALSE		0
#define TRUE		0

#endif
