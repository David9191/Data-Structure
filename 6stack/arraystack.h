#ifndef _ARRAY_STACK_
#define _ARRAY_STACK_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct StackNodeType
{
	int	data;
} StackNode;

typedef struct ArrayStackType
{
	int 		maxElementCount;		// 현재 스택 원소 개수
	int 		currentElementCount;	// 현재 스택 원소 개수
	StackNode	*pTopElement;			// 스택배열
} ArrayStack;

ArrayStack	*createArrayStack(int maxElementCount);
int			pushAS(ArrayStack *pStack, StackNode element);
int			popAS(ArrayStack *pStack);
int			peekAS(ArrayStack *pStack);
void		deleteArrayStack(ArrayStack *pStack);
int			isArrayStackFull(ArrayStack *pStack);
int			isArrayStackEmpty(ArrayStack *pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif