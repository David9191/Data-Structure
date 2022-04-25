#include "arraystack.h"

int	main(void)
{
	ArrayStack *as = createArrayStack(10);
	StackNode sn;
	sn.data = 50;

	printf("%d\n", as->currentElementCount);
	pushAS(as, sn);
	int a = as->currentElementCount;
	printf("%d\n", as->pTopElement[a - 1].data);
	printf("%d\n", as->currentElementCount);
	printf("%d\n", as->maxElementCount);
}