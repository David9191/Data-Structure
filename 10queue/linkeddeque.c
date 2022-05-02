#include "linkeddeque.h"

LinkedDeque	*createLinkedDeque()
{
	LinkedDeque	*rt_pDeque;

	rt_pDeque = malloc(sizeof(LinkedDeque));
	if (!rt_pDeque)
		return (NULL);
	rt_pDeque->pFrontNode = NULL;
	rt_pDeque->pRearNode = NULL;
	rt_pDeque->currentElementCount = 0;
	return (rt_pDeque);
}
int insertFront(LinkedDeque *pDeque, DequeNode element)
{
	DequeNode	*node;

	if (!pDeque)
		return (FALSE);
	node = malloc(sizeof(DequeNode));
	if (!node)
		return (FALSE);
	node->data = element.data;
	if (isLinkedDequeEmpty(pDeque))
	{
		node->pRLink = NULL;
		pDeque->pFrontNode = node;
		pDeque->pRearNode = node;
	}
	else
	{
		node->pRLink = pDeque->pFrontNode;
		pDeque->pFrontNode->pLLink = node;
		if (pDeque->currentElementCount == 1)
			pDeque->pRearNode = pDeque->pFrontNode;
		pDeque->pFrontNode = node;
	}
	pDeque->currentElementCount += 1;
	return (TRUE);
}
int insertRear(LinkedDeque *pDeque, DequeNode element)
{
	DequeNode	*node;
	
	if (!pDeque)
		return (FALSE);
	// 위 함수에서 처리. 잘 되니까
	if (isLinkedDequeEmpty(pDeque))
	{
		if (insertFront(pDeque, element))
			return (TRUE);
		else
			return (FALSE);
	}
	node = malloc(sizeof(DequeNode));
	if (!node)
		return (FALSE);
	node->data = element.data;
	node->pRLink = NULL;
	node->pLLink = pDeque->pRearNode;
	pDeque->pRearNode->pRLink = node;
	pDeque->pRearNode = node;
	pDeque->currentElementCount += 1;
	return (TRUE);
}
int	deleteFront(LinkedDeque *pDeque)
{
	DequeNode	*del;
	int	rt_value;

	if (!pDeque || isLinkedDequeEmpty(pDeque))
		return (FALSE);
	rt_value = pDeque->pFrontNode->data;
	del = pDeque->pFrontNode;
	pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
	free (del);
	pDeque->currentElementCount -= 1;
	return (rt_value);
}
int	deleteRear(LinkedDeque *pDeque)
{
	DequeNode	*del;
	int	rt_value;

	if (!pDeque || isLinkedDequeEmpty(pDeque))
		return (FALSE);
	rt_value = pDeque->pRearNode->data;
	del = pDeque->pRearNode;
	pDeque->pRearNode = pDeque->pRearNode->pLLink;
	free (del);
	pDeque->currentElementCount -= 1;
	return (rt_value);
}
int	peekFront(LinkedDeque *pDeque)
{
	if (!pDeque || isLinkedDequeEmpty(pDeque))
		return (FALSE);
	return (pDeque->pFrontNode->data);
}
int	peekRear(LinkedDeque *pDeque)
{
	if (!pDeque || isLinkedDequeEmpty(pDeque))
		return (FALSE);
	return (pDeque->pRearNode->data);
}
void	deleteLinkedDeque(LinkedDeque *pDeque);
int	isLinkedDequeEmpty(LinkedDeque *pDeque)
{
	// if (!pDeque || pDeque->currentElementCount != 0) 이건 왜 안될까..?
	if (!pDeque)
		return (FALSE);
	if (pDeque->currentElementCount == 0)
		return (TRUE);
	else
		return (FALSE);
}