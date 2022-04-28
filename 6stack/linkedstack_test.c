#include "linkedstack.h"

int	main(void)
{
	LinkedStack	*pStack = createLinkedStack();
	StackNode *pNode;
	StackNode node;
	node.data = 0;

	// push & peek all of stack
	printf("--- push & peek all of stack ---\n");
	for (size_t i = 0; i < 10; i++)
	{
		if (i % 5 == 0)
			printf("\n");
		node.data += 10;
		pushLS(pStack, node);
		printf("%3d | ", peekLS(pStack));
	}
	printf("\n\ncrntCnt : %d\n", pStack->currentElementCount);
	// pop all of stack & peek
	printf("\n--- pop all of stack ---\n");
	// for (size_t i = 0; pStack->pTopElement; i++)
	// {
	// 	if (i % 5 == 0)
	// 		printf("\n");
	// 	printf("%3d | ", popLS(pStack));
	// }

	// 메모리 릭 테스트
	pNode = pStack->pTopElement;
	for (size_t i = 0; pNode; i++)
	{
		if (i % 5 == 0)
			printf("\n");
		printf("%3d | ", pNode->data);
		pNode = pNode->pLink;
	}
	printf("\n\ncrntCnt : %d\n", pStack->currentElementCount);
	deleteLinkedStack(pStack);
	system("leaks a.out | grep leaked");
	return (0);
}
