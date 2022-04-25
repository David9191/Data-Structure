#include "linkedstack.h"

int	main(void)
{
	LinkedStack	*pStack = createLinkedStack();
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
	for (size_t i = 0; i < 10; i++)
	{
		if (i % 5 == 0)
			printf("\n");
		printf("%3d | ", popLS(pStack));
	}
	printf("\n\ncrntCnt : %d\n", pStack->currentElementCount);
	deleteLinkedStack(pStack);
}