#ifndef _LINKED_STACK_
#define _LINKED_STACK_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct StackNodeType
{
	int						data;
	int						index;
	struct	StackNodeType	*pLink;
} StackNode;

typedef struct LinkedStackType
{
	int			currentElementCount;	// 현재 스택 원소 개수
	StackNode	*pTopElement;			// Top 노드의 포인터
} LinkedStack;

LinkedStack	*createLinkedStack();
int			pushLS(LinkedStack *pStack, StackNode element);
int			popLS(LinkedStack *pStack);
int			peekLS(LinkedStack *pStack);
void		deleteLinkedStack(LinkedStack *pStack);
int			isLinkedStackEmpty(LinkedStack *pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif
