#include "arraystack.h"

int	main(void)
{
	ArrayStack *pStack = createArrayStack(10);
	StackNode node;

	node.data = 0;
	// push & peek all of stack
	// pStack->currentElementCount = pStack->maxElementCount; // error test good
	printf("--- push & peek all of stack ---\n");
	for (size_t i = 0; i < 10; i++)
	{
		if (i % 5 == 0)
			printf("\n");
		node.data += 10;
		pushAS(pStack, node);
		printf("%3d | ", peekAS(pStack));
	}
	printf("\n\ncrntCnt : %d\n", pStack->currentElementCount);
	// pop all of stack & peek
	// pStack->currentElementCount = 0; // error test good
	printf("\n--- pop all of stack ---\n");
	for (size_t i = 0; i < 10; i++)
	{
		// if (i % 5 == 0)
		// 	printf("\n");
		printf("%3d\n", popAS(pStack));
	}
	printf("\n\ncrntCnt : %d\n", pStack->currentElementCount);
	deleteArrayStack(pStack);
	system("leaks a.out | grep leaked");
	return (0);
}