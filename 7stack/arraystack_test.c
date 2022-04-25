#include "arraystack.h"

int	main(void)
{
	ArrayStack *as = createArrayStack(10);
	StackNode sn;

	sn.data = 0;
	// push & peek all of stack
	// as->currentElementCount = as->maxElementCount; // error test good
	printf("--- push & peek all of stack ---\n");
	for (size_t i = 0; i < 10; i++)
	{
		if (i % 5 == 0)
			printf("\n");
		sn.data += 10;
		pushAS(as, sn);
		printf("%3d | ", peekAS(as));
	}
	printf("\n\ncrntCnt : %d\n", as->currentElementCount);
	// pop all of stack & peek
	// as->currentElementCount = 0; // error test good
	printf("\n--- pop all of stack ---\n");
	for (size_t i = 0; i < 10; i++)
	{
		if (i % 5 == 0)
			printf("\n");
		printf("%3d | ", popAS(as));
	}
	printf("\n\ncrntCnt : %d\n", as->currentElementCount);
	deleteArrayStack(as);
}