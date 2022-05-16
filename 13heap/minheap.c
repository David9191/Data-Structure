#include "heap.h"

ArrayMinHeap	*createMinHeap(int maxCount)
{
	ArrayMinHeap	*minHeap;

	if (maxCount <= 0)
		return (NULL);
	minHeap = (ArrayMinHeap *)malloc(sizeof(ArrayMinHeap));
	if (minHeap)
	{
		minHeap->pData = (HeapNode *)malloc(sizeof(HeapNode) * (maxCount + 1));
		if (minHeap->pData)
		{
			minHeap->maxCount = maxCount;
			minHeap->currentCount = 0;
			return (minHeap);
		}
		else
		{
			free (minHeap);
			return (NULL);
		}
	}
	return (NULL);
}
void	deleteMinHeap(ArrayMinHeap *heap)
{
	if (heap)
	{
		free (heap->pData);
		free (heap);
	}
}
// 가장 마지막에 추가.
// 부모 노드와 비교 후 if(부모 > 나) swap();
// 반복
int	insertMinHeap(ArrayMinHeap *heap, int data)
{
	int			curr;
	int			temp;
	HeapNode	*cpy_pData;

	if (heap && heap->currentCount < heap->maxCount)
	{
		curr = ++heap->currentCount;
		cpy_pData = heap->pData;
		cpy_pData[curr].data = data;
		while (curr > 1 && (cpy_pData[curr].data < cpy_pData[curr / 2].data))
		{
			temp = cpy_pData[curr].data;
			cpy_pData[curr].data = cpy_pData[curr / 2].data;
			cpy_pData[curr / 2].data = temp;
			curr /= 2;
		}
		return (TRUE);
	}
	return (FALSE);
}
// 루트 노드 제거
// 마지막애를 루트 노트로 옮김.
// 루트와 자식 왼, 오를 비교해서 더 작은 값이랑 바꿈.
// 반복
HeapNode *removeMinHeap(ArrayMinHeap *heap)
{
	HeapNode	*rt_node;
	int			curr;
	int			idx;
	int			temp;

	if (heap)
	{
		rt_node = (HeapNode *)malloc(sizeof(HeapNode));
		if (rt_node)
		{
			rt_node->data = heap->pData[1].data; // save data of root node to return
			heap->pData[1].data = heap->pData[heap->currentCount].data; // move last node to root node
			heap->currentCount--;
			idx = 1;
			while (idx <= heap->currentCount
				&& (heap->pData[idx].data > heap->pData[(idx * 2) + 1].data // root > right node
				|| heap->pData[idx].data > heap->pData[idx * 2].data)) // root > left node
			{
				if (heap->pData[(idx * 2) + 1].data < heap->pData[idx * 2].data)
					curr = (idx * 2 + 1);
				else
					curr = idx * 2;
				temp = heap->pData[curr].data;
				heap->pData[curr].data = heap->pData[idx].data;
				heap->pData[idx].data = temp;
				idx = curr;
			}
			return (rt_node);
		}
	}
	return (NULL);
}

void	displayMinHeap(ArrayMinHeap *heap)
{
	if (heap)
	{
		int	curr = heap->currentCount, idx = 1, level = 1, heapLevel = 0, maxCnt = heap->maxCount/*, j = 0, k = 1*/;
		while (maxCnt > 0)
		{
			maxCnt = maxCnt / 2 - 1;
			heapLevel++;
		}
		while (curr--)
		{
			/*if (idx == 1 || idx == k)
			{
				j = heapLevel;
				while (j > 0)
				{
					printf("\t\t");
					j--;
				}
				j = heapLevel;
				while (j > 1)
				{
					printf("\b\b\b\b\b\b\b\b\b\b\b\b\b");
					j--;
				}
				heapLevel--;
				k *= 2;
			}*/
			printf("%d ", heap->pData[idx].data);
			if (idx == 1 || idx == level)
			{
				level = (level * 2) + 1;
				printf("\n");
			}
			idx++;
		}
		printf("\b\n");
	}
	else
		printf("GG");
}