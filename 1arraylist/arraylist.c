#include "arraylist.h"

ArrayList	*createArrayList(int maxElementCount)
{
	ArrayList	*rt_ArrayList;

	if (maxElementCount <= 0)
		return (NULL);
	rt_ArrayList = malloc(sizeof(ArrayList));
	if (!rt_ArrayList)
		return (NULL);
	// maxElementCount 만큼 공간할당.
	rt_ArrayList->pElement = malloc(sizeof(ArrayListNode) * maxElementCount);
	if (!(rt_ArrayList->pElement))
		return (NULL);
	// max 초기값 세팅.
	rt_ArrayList->maxElementCount = maxElementCount;
	// 현재는 아무것도 add가 안됐으므로 currCnt는 0으로 초기화
	rt_ArrayList->currentElementCount = 0;
	return (rt_ArrayList);
}

int	addALElement(ArrayList *pList, int position, ArrayListNode element)
{
	int	curr;
	int	idx;

	curr = pList->currentElementCount;
	// pList가 NULL이거나 position(인덱스)이 0보다 작으면 0 리턴.
	if (!pList || position < 0)
		return (0);
	// currCnt가 max보가 크거나 같으면 더 이상 공간이 없으므로 0 리턴.
	// position이 curEleCnt보다 크면 position - currCnt만큼 공간이 비므로 0 리턴.
	if (curr >= pList->maxElementCount
		|| position > curr)
		return (0);
	idx = position;
	// [curElecnt] = [curElecnt - 1]; 오른쪽으로 하나씩 밀음.
	while (curr > position)
	{
		pList->pElement[curr] = pList->pElement[curr - 1];
		curr--;
	}
	// 다 오른쪽으로 밀어졌다면 이 때 추가.
	pList->pElement[position] = element;
	pList->currentElementCount += 1;
	return (position + 1);
}

int	removeALElement(ArrayList *pList, int position)
{
	int	curEleCnt;

	curEleCnt = pList->currentElementCount;
	if (!pList || position < 0)
		return (0);
	// position이 curEleCnt보다 크거나 같으면 오버된 주소에 접근하고 있는 것.
	if (position >= curEleCnt)
		return (0);
	// [position] = [position + 1]; 왼쪽으로 하나씩 땡김.
	while (position < curEleCnt - 1)
	{
		pList->pElement[position] = pList->pElement[position + 1];
		position++;
	}
	// 왼쪽으로 다 땅기면 position인덱스에는
	// 값이 남아있을 텐데 얘 값은 계속 내비둬야 되는가?
	// 아니면 아래처럼 초기화를 시켜줘야 하는가?
	pList->pElement[position].data = 0;
	pList->currentElementCount -= 1;
	return (position);
}

void	deleteArrayList(ArrayList *pList)
{
	if (!pList)
		return ;
	free(pList->pElement);
	free(pList);
}

void	clearArrayList(ArrayList *pList)
{
	if (!pList || !pList->currentElementCount)
		return ;
	memset(pList->pElement, 0, pList->currentElementCount);
	pList->currentElementCount = 0;
}

ArrayListNode	*getALElement(ArrayList *pList, int position)
{
	if (!pList || position < 0)
		return (0);
	if (position >= pList->currentElementCount)
		return (0);
	return (&(pList->pElement[position]));
}

void	displayArrayList(ArrayList *pList)
{
	int	idx;
	int	crnt;

	if (!pList || !(pList->pElement))
		return ;
	crnt = pList->currentElementCount;
	idx = 0;
	while (idx < crnt)
	{
		printf("%3d | ", pList->pElement[idx].data);
		idx++;
	}
	printf("\b\n");
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
