#include "circularlist.h"

CircularList *createLinkedList(void)
{
	CircularList	*rtn_LinkedList;

	rtn_LinkedList = malloc(sizeof(CircularList));
	if (!rtn_LinkedList)
		return (NULL);
	memset(rtn_LinkedList, 0, sizeof(CircularList));
	rtn_LinkedList->currentElementCount = 0;
	rtn_LinkedList->headerNode.pLink = NULL;
	return (rtn_LinkedList);
}

int	addFirstElement(CircularList *pList, CircularListNode *new)
{
	pList->headerNode.pLink = new;
	new->pLink = new;
	pList->currentElementCount += 1;
	return (TRUE);
}

int	addLLElement(CircularList *pList, int position, CircularListNode element)
{
	CircularListNode	*new;
	CircularListNode	*pre;
	CircularListNode	*last;
	int			idx;

	if (!pList || 0 > position
		|| position > pList->currentElementCount)
		return (FALSE);
	new = (CircularListNode *)malloc(sizeof(CircularListNode));
	if (!new)
		return (FALSE);
	new->data = element.data;
	// if pList->currentElementCount == 0 / exit
	if (pList->currentElementCount == 0)
		return (addFirstElement(pList, new));
	pre = &(pList->headerNode);
	idx = 0;
	while (idx < position)
	{
		pre = pre->pLink;
		idx++;
	}
	new->pLink = pre->pLink;
	pre->pLink = new;
	// add in circular
	last = getLLElement(pList, pList->currentElementCount);
	last->pLink = pList->headerNode.pLink;
	pList->currentElementCount += 1;
	return (position + 1);
}

int	removeLLElement(CircularList *pList, int position)
{
	CircularListNode	*del;
	CircularListNode	*pre;
	int			idx;

	if (!pList || 0 > position \
		|| position > pList->currentElementCount)
		return (FALSE);
	pre = &(pList->headerNode);
	idx = 0;
	while (idx < position)
	{
		pre = pre->pLink;
		idx++;
	}
	del = pre->pLink;
	pre->pLink = del->pLink;
	free (del);
	pList->currentElementCount -= 1;
	return (position);
}

CircularListNode*	getLLElement(CircularList *pList, int position)
{
	CircularListNode	*getNode;
	int			idx;

	if (!pList || 0 > position \
		|| position > pList->currentElementCount)
		return (NULL);
	getNode = pList->headerNode.pLink;
	idx = 0;
	while (idx < position)
	{
		getNode = getNode->pLink;
		idx++;
	}
	return (getNode);
}

void	displayLinkedList(CircularList *pList)
{
	CircularListNode	*node;
	int					idx;
	int					crnt;

	if (!pList || !(pList->headerNode.pLink))
		return ;
	node = pList->headerNode.pLink;
	idx = 0;
	crnt = pList->currentElementCount;
	while (idx < crnt)
	{
		if (idx % 5 == 0)
			printf("\n");
		printf("%9d | ", node->data);
		node = node->pLink;
		idx++;
	}
	printf("\b\n");
}

int	getLinkedListLength(CircularList *pList)
{
	if (!pList)
		return (FALSE);
	return (pList->currentElementCount);
}


void	clearLinkedList(CircularList *pList)
{
	CircularListNode	*node;

	if (!pList)
		return ;
	node = pList->headerNode.pLink;
	while (node)
	{
		node->data = 0;
		node = node->pLink;
	}
}

void	deleteLinkedList(CircularList *pList)
{
	CircularListNode	*del;
	CircularListNode	*node;

	if (!pList)
		return ;
	clearLinkedList(pList);
	del = (pList->headerNode).pLink;
	while (del)
	{
		node = del->pLink;
		free (del);
		del = node;
	}
	free (pList);
}
