#include "mapdef.h"

LinkedStack *createLinkedStack()
{
	LinkedStack	*rt_satck;

	rt_satck = malloc(sizeof(LinkedStack));
	if (!rt_satck)
		return (NULL);
	rt_satck->currentElementCount = 0;
	rt_satck->pTopElement = NULL;
	return (rt_satck);
}

int	pushLS(LinkedStack *pStack, MapPosition element)
{
	StackNode	*node;

	if (!pStack)
		return (FALSE);
	node = malloc(sizeof(StackNode));
	if (!node)
		return (FALSE);
	node->myPosition = element;
	// pStack->pTopElement == NULL인 경우. 즉, 스택을 막 생성한 상태.
	if (!(pStack->pTopElement))
	{
		node->pLink = NULL;
		pStack->pTopElement = node;
	}
	else
	{
		node->pLink = pStack->pTopElement;
		pStack->pTopElement = node;
	}
	pStack->currentElementCount += 1;
	return (TRUE);
}

MapPosition	*popLS(LinkedStack *pStack)
{
	StackNode	*del;
	MapPosition	*rt_data;

	if (!pStack || !(pStack->currentElementCount))
		return (NULL);
	rt_data = peekLS(pStack);
	del = pStack->pTopElement;
	pStack->pTopElement = pStack->pTopElement->pLink;
	free (del);
	pStack->currentElementCount -= 1;
	return (rt_data);
}

MapPosition	*peekLS(LinkedStack *pStack)
{
	if (!pStack || !(pStack->currentElementCount))
		return (NULL);
	return (&(pStack->pTopElement->myPosition));
}

void	deleteLinkedStack(LinkedStack *pStack)
{
	StackNode	*del;

	if (!pStack || !(pStack->currentElementCount))
	{
		free (pStack);
		return ;
	}
	while (pStack->pTopElement)
	{
		del = pStack->pTopElement;
		pStack->pTopElement = pStack->pTopElement->pLink;
		free (del);
	}
	free (pStack);
}

int	isLinkedStackEmpty(LinkedStack *pStack)
{
	if (pStack
		&& pStack->currentElementCount == 0)
		return (TRUE);
	else
		return (FALSE);
}
