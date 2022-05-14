#include "heap.h"

int	main(void)
{
	ArrayMaxHeap	*maxHeap = createMaxHeap(7);
	insertMaxHeap(maxHeap, 5);
	displayMaxHeap(maxHeap);
}