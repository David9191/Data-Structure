#include "heap.h"

int	main(void)
{
	ArrayMaxHeap	*maxHeap = createMaxHeap(31);
	for (int i = 0; i < 31; i++)
	{
		insertMaxHeap(maxHeap , rand()%(0-200+1)+200);
	}
	displayMaxHeap(maxHeap);
	deleteMaxHeap(maxHeap);
	system("leaks a.out");
}