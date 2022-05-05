#ifndef _LINKED_QUEUE_
#define _LINKED_QUEUE_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkedQueueNodeType
{
	int							data;
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

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif
