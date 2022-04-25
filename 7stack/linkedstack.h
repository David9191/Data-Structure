#ifndef _LINKED_STACK_
#define _LINKED_STACK_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "2linkedlist/linkedlist.h"

typedef struct StackNodeType
{
	char data;
	struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;	// 현재 스택 원소 개수
	StackNode* pTopElement;		// Top 노드의 포인터
} LinkedStack;

LinkedStack*	createLinkedStack();
int				pushLS(LinkedStack* pStack, StackNode element);
StackNode*		popLS(LinkedStack* pStack);
StackNode*		peekLS(LinkedStack* pStack);
void			deleteLinkedStack(LinkedStack* pStack);
int				isLinkedStackFull(LinkedStack* pStack); // 링크드리스트에서 필요할까? Nope.
int				isLinkedStackEmpty(LinkedStack* pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif