#include "../6stack/linkedstack.h"

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

int	pushLS(LinkedStack *pStack, StackNode element)
{
	StackNode	*node;

	if (!pStack)
		return (FALSE);
	node = malloc(sizeof(StackNode));
	if (!node)
		return (FALSE);
	node->data = element.data;
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

int	popLS(LinkedStack *pStack)
{
	StackNode	*del;
	int			rt_data;

	if (!pStack || !(pStack->currentElementCount))
		return (FALSE);
	rt_data = peekLS(pStack);
	del = pStack->pTopElement;
	pStack->pTopElement = pStack->pTopElement->pLink;
	free (del);
	pStack->currentElementCount -= 1;
	return (rt_data);
}

int	peekLS(LinkedStack *pStack)
{
	if (!pStack || !(pStack->currentElementCount))
		return (FALSE);
	return (pStack->pTopElement->data);
}

void	deleteLinkedStack(LinkedStack *pStack)
{
	int	crnt;

	if (!pStack || !(pStack->pTopElement))
	{
		free (pStack);
		return ;
	}
	crnt = pStack->currentElementCount;
	while (crnt--)
		popLS(pStack);
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
