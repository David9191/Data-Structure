#ifndef _ARRAY_STACK_
#define _ARRAY_STACK_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct StackNodeType
{
	char data;
} StackNode;

typedef struct ArrayStackType
{
	int maxElementCount;	// 현재 스택 원소 개수
	int currentElementCount;	// 현재 스택 원소 개수
	StackNode* pTopElement;		// Top 노드의 포인터
} ArrayStack;

ArrayStack*	createArrayStack(int maxElementCount);
int			pushAS(ArrayStack* pStack, StackNode element);
char		popAS(ArrayStack* pStack);
char		peekAS(ArrayStack* pStack);
void		deleteArrayStack(ArrayStack* pStack);
int			isArrayStackFull(ArrayStack* pStack);
int			isArrayStackEmpty(ArrayStack* pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif