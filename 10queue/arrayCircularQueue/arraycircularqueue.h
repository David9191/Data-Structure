#ifndef _ARRAY_QUEUE_
#define _ARRAY_QUEUE_

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

typedef struct ArrCriQueNodeType
{
	char data;
} ArrCriQueNode;

typedef struct ArrCirQueType
{
	int 			maxElementCount;		// 최대 원소 개수
	int 			currentElementCount;	// 현재 원소 개수
	int 			front;					// front 위치 디큐
	int 			rear;					// rear 위치 인큐
	ArrCriQueNode	*pElement;				// 노드 저장을 위한 1차원 배열 포인터
} ArrCirQue;

ArrCirQue		*createArrCirQue(int maxElementCount);
int				isArrCirQueFull(ArrCirQue* pACQueue);
int				isArrCirQueEmpty(ArrCirQue* pACQueue);
int				enqueueACQ(ArrCirQue* pACQueue, ArrCriQueNode element);
ArrCriQueNode	*dequeueACQ(ArrCirQue* pACQueue);
ArrCriQueNode	*peekACQ(ArrCirQue* pACQueue);
void			deleteArrCirQue(ArrCirQue* pACQueue);
int				canCircularEnqueueCount(ArrCirQue* pACQueue);
void			displayACq(ArrCirQue* pACQueue);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif
