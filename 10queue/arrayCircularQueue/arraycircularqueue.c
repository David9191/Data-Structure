#include "arraycircularqueue.h"

ArrCirQue* createArrCirQue(int maxElementCount)
{
	ArrCirQue      *newArrCirQue;
	ArrCriQueNode  *pElement;

	newArrCirQue = (ArrCirQue *)malloc(sizeof(ArrCirQue));
	if (newArrCirQue == NULL)
		return (NULL);
	pElement = (ArrCriQueNode *)malloc(sizeof(ArrCriQueNode) * maxElementCount);
	if (pElement == NULL)
	{
		free(newArrCirQue);
		return (NULL);
	}
	newArrCirQue->pElement = pElement;
	newArrCirQue->maxElementCount = maxElementCount;
	newArrCirQue->currentElementCount = 0;
	newArrCirQue->front = 0;
	newArrCirQue->rear = 0;
	return (newArrCirQue);
}

int isArrCirQueFull(ArrCirQue* pACQueue)
{
	if (pACQueue == NULL)
		return (ERROR);
	if (pACQueue->maxElementCount == pACQueue->currentElementCount)
		return (TRUE);
	return (FALSE);
}

int isArrCirQueEmpty(ArrCirQue* pACQueue)
{
	if (pACQueue == NULL)
		return (ERROR);
	if (pACQueue->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}

int enqueueACQ(ArrCirQue* pACQueue, ArrCriQueNode element)
{
	if (isArrCirQueFull(pACQueue))
	{
		printf("ArrCirQue is Full");
		return (ERROR);
	}
	if (pACQueue == NULL)
	{
		printf("ArrCirQue is NULL");
		return (ERROR);
	}
	if (isArrCirQueEmpty(pACQueue) == 0)
		pACQueue->rear = (pACQueue->rear + 1) % pACQueue->maxElementCount;
	(pACQueue->pElement)[pACQueue->rear] = element;
	pACQueue->currentElementCount++;
	return (TRUE);
}

ArrCriQueNode *dequeueACQ(ArrCirQue* pACQueue)
{
	ArrCriQueNode *dequeue;

	if (isArrCirQueEmpty(pACQueue) > 0)
	{
		printf("ArrCirQue is Empty\n");
		return(NULL);
	}
	if (pACQueue == NULL)
	{
		printf("ArrCirQue is NULL\n");
		return (NULL);
	}
	dequeue = &(pACQueue->pElement)[pACQueue->front];
	pACQueue->currentElementCount--;
	pACQueue->front %= pACQueue->maxElementCount;
	return (dequeue);
}

ArrCriQueNode *peekACQ(ArrCirQue* pACQueue)
{
	ArrCriQueNode *peek;

	if (pACQueue == NULL)
	{
		printf("ArrCirQue is NULL\n");
		return (NULL);
	}
	if (isArrCirQueEmpty(pACQueue) == 1)
	{
		printf("ArrCirQue is Empty\n");
		return(NULL);
	}
	peek = malloc(sizeof(ArrCriQueNode));
	if (peek == NULL)
	{
		printf("malloc error\n");
		return (NULL);
	}
	peek->data = (pACQueue->pElement)[pACQueue->front].data;
	return (peek);
}

void deleteArrCirQue(ArrCirQue* pACQueue)
{
	if (pACQueue == NULL)
		return ;
	free(pACQueue->pElement);
	free(pACQueue);
}

int canCircularEnqueueCount(ArrCirQue* pACQueue)
{
	return (pACQueue->maxElementCount - pACQueue->currentElementCount);
}

void    displayACq(ArrCirQue* pACQueue)
{
	int n;

	n = -1;
	if (pACQueue == NULL)
		printf("ArrCirQue is NULL\n");
	else if (isArrCirQueEmpty(pACQueue))
		printf("ArrCirQue is Empty\n");
	else
	{
		printf("front ");
		while (++n < pACQueue->currentElementCount)
			printf("| %c ", (pACQueue->pElement[(pACQueue->front + n) % pACQueue->maxElementCount]).data);
		printf("| end\n");
	}
}

int main()
{
	ArrCirQue *acq;
	ArrCriQueNode *temp;

	// createArrCirQue
	acq = createArrCirQue(5);
	printf("< createArrCirQue >\n");
	displayACq(acq);
	printf("Maxcount : %d\n", acq->maxElementCount);

	printf("\n< isArrCirQueEmpty >\n");
	printf("isArrCirQueEmpty : %d\n", isArrCirQueEmpty(acq));

	printf("\n< enqueueACQ 3times >\n");
	enqueueACQ(acq, (ArrCriQueNode){'a'});
	displayACq(acq);
	enqueueACQ(acq, (ArrCriQueNode){'b'});
	displayACq(acq);
	enqueueACQ(acq, (ArrCriQueNode){'c'});
	displayACq(acq);

	printf("\n< canCircularEnqueueCount >\n");
	printf("canCircularEnqueueCount : %d\n", canCircularEnqueueCount(acq));

	printf("\n< enqueueACQ 2times >\n");
	enqueueACQ(acq, (ArrCriQueNode){'d'});
	displayACq(acq);
	enqueueACQ(acq, (ArrCriQueNode){'e'});
	displayACq(acq);

	printf("\n< isArrCirQueFull >\n");
	printf("isArrCirQueFull : %d\n", isArrCirQueFull(acq));

	printf("\n< dequeueACQ 3times >\n");
	temp = dequeueACQ(acq); printf("dequeueACQ.data : %c | ", temp->data); displayACq(acq);
	temp = dequeueACQ(acq); printf("dequeueACQ.data : %c | ", temp->data); displayACq(acq);
	temp = dequeueACQ(acq); printf("dequeueACQ.data : %c | ", temp->data); displayACq(acq);

	printf("\n< canCircularEnqueueCount >\n");
	printf("canCircularEnqueueCount : %d\n", canCircularEnqueueCount(acq));

	printf("\n< enqueueACQ 3times >\n");
	enqueueACQ(acq, (ArrCriQueNode){'f'});
	displayACq(acq);
	enqueueACQ(acq, (ArrCriQueNode){'g'});
	displayACq(acq);
	enqueueACQ(acq, (ArrCriQueNode){'h'});
	displayACq(acq);

	printf("\n< peekACQ >\n");
	temp = peekACQ(acq);
	printf("peekACQ : %c\n", temp->data);

	printf("\n< deleteArrCirQue >\n");
	deleteArrCirQue(acq);
	acq = NULL;
	displayACq(acq);
	system("leaks a.out");
}
