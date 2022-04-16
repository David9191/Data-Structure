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
	ArrayList	*copy_pList;

	if (!pList)
		return ;
	copy_pList = pList;
	while (pList)
	{
		free(pList->pElement);
		pList++;
	}
	free(copy_pList);
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

void		displayArrayList(ArrayList *pList);

void		clearArrayList(ArrayList *pList)
{
	deleteArrayList(pList);
}

int			getArrayListLength(ArrayList *pList);
int			isArrayListFull(ArrayList *pList);