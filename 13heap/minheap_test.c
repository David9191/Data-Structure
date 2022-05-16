#include "heap.h"

int	main(void)
{
	int				arr[31];
	int				data;
	ArrayMinHeap	*minHeap = createMinHeap(31);
	for (int i = 0; i < 31; i++)
	{
		data = rand()%(0-200+1)+200;
		arr[i] = data;
		insertMinHeap(minHeap , data);
	}
	printf("\n==============data array==============\n\n");
	for (int i = 0; i < 31; i++)
	{
		printf("%d ", arr[i]);
		if (i == 30)
			printf("\n\n");
	}
	displayMinHeap(minHeap);
	HeapNode	*node = removeMinHeap(minHeap);
	printf("min : %d\n", node->data);
	free (node);
	displayMinHeap(minHeap);
	deleteMinHeap(minHeap);
	// system("leaks a.out | grep leaked");
}