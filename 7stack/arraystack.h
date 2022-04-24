#ifndef _ARRAY_STACK_
#define _ARRAY_STACK_

typedef struct StackNodeType
{
	char data;
} StackNode;

typedef struct LinkedStackType
{
	int maxElementCount;	// 현재 스택 원소 개수
	int currentElementCount;	// 현재 스택 원소 개수
	StackNode* pTopElement;		// Top 노드의 포인터
} LinkedStack;

LinkedStack*    createLinkedStack();
int             pushLS(LinkedStack* pStack, StackNode element);
StackNode*      popLS(LinkedStack* pStack);
StackNode*      peekLS(LinkedStack* pStack);
void            deleteLinkedStack(LinkedStack* pStack);
int             isLinkedStackFull(LinkedStack* pStack);
int             isLinkedStackEmpty(LinkedStack* pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif