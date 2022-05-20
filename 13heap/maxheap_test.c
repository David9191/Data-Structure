#include "heap.h"

int	main(void)
{
	int				arr[31];
	int				data;
	ArrayMaxHeap	*maxHeap = createMaxHeap(31);
	for (int i = 0; i < 31; i++)
	{
		data = rand()%(0-200+1)+200;
		arr[i] = data;
		insertMaxHeap(maxHeap , data);
	}
	printf("\n==============data array==============\n\n");
	for (int i = 0; i < 31; i++)
	{
		printf("%d ", arr[i]);
		if (i == 30)
			printf("\n\n");
	}
	displayMaxHeap(maxHeap);
	HeapNode	*node = removeMaxHeap(maxHeap);
	printf("max : %d\n\n", node->data);
	free (node);
	displayMaxHeap(maxHeap);
	deleteMaxHeap(maxHeap);
	// system("leaks a.out | grep leaked");
}