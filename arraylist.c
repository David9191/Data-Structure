#include "arraylist.h"

ArrayList	*createArrayList(int maxElementCount)
{
	ArrayList	*rt_ArrayList;
	int			idx;

	if (maxElementCount <= 0)
		return (NULL);
	rt_ArrayList = malloc(sizeof(ArrayList) * maxElementCount);
	if (!rt_ArrayList)
		return (NULL);
	idx = 0;
	while (idx < maxElementCount)
	{
		rt_ArrayList[idx].maxElementCount = maxElementCount;
		rt_ArrayList[idx].currentElementCount = 0;
		idx++;
	}
	return (rt_ArrayList);
}

int	addALElement(ArrayList *pList, int position, ArrayListNode element)
{
	int	copyCurEleCnt;

	copyCurEleCnt = pList->currentElementCount;
	if (!pList || position < 0)
		return (0);
	if (copyCurEleCnt >= pList->maxElementCount
		|| position > copyCurEleCnt)
		return (0);
	while (position > copyCurEleCnt)
	{
		pList[copyCurEleCnt] = pList[copyCurEleCnt - 1];
		pList[copyCurEleCnt].currentElementCount += 1;
		copyCurEleCnt--;
	}
	if (position == copyCurEleCnt)
	{
		pList[position].pElement = &element;
		pList[position].maxElementCount = pList[position + 1].maxElementCount;
		pList[position].currentElementCount = pList[position + 1].currentElementCount;
	}
	return (position);
}

int	removeALElement(ArrayList *pList, int position)
{
	int	copyCurEleCnt;

	copyCurEleCnt = pList->currentElementCount;
	if (!pList || position < 0)
		return (0);
	if (position >= copyCurEleCnt)
		return (0);
	while (position < copyCurEleCnt - 1)
	{
		pList[position] = pList[position + 1];
		pList[position].currentElementCount--;
		position++;
	}
	free(pList[position].pElement);
	return (position);
}

void	deleteArrayList(ArrayList *pList)
{
	if (!pList)
		return ;
	free(pList);
}

void	clearArrayList(ArrayList *pList)
{
	if (!pList)
		return ;
	free(pList);
}

ArrayListNode	*getALElement(ArrayList *pList, int position)
{
	if (!pList || position < 0)
		return (0);
	if (position >= pList->maxElementCount
		|| position >= pList->currentElementCount)
		return (0);
	return (pList->pElement);
}

void	displayArrayList(ArrayList *pList)
{
	int	idx;

	idx = 0;
	if (!pList)
		return (0);
	while (idx < (pList->currentElementCount) - 1)
	{
		printf("%d | ", pList[idx].pElement->data);
		idx++;
	}
	printf("%d", pList[idx].pElement->data);
}

int	getArrayListLength(ArrayList *pList)
{
	if (!pList)
		return (0);
	return (pList->currentElementCount);
}

int	isArrayListFull(ArrayList *pList)
{
	if (!pList)
		return (0);
	if (pList->currentElementCount == pList->maxElementCount)
		return (1);
	else
		return (0);
}