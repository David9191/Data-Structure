#include "doublylist.h"

DoublyList	*createDoublyList()
{
	DoublyList	*rt_DoublyList;

	rt_DoublyList = (DoublyList *)malloc(sizeof(DoublyList));
	if (!rt_DoublyList)
		return (NULL);
	memset(rt_DoublyList, 0, sizeof(DoublyList));
	rt_DoublyList->currentElementCount = 0;
	rt_DoublyList->headerNode.pRLink = NULL;
	return (rt_DoublyList);
}

int	addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
	DoublyListNode	*add;
	DoublyListNode	*add_pre;
	int				idx;

	if (!pList || 0 > position
	|| position > pList->currentElementCount)
		return (FALSE);
	add = (DoublyListNode *)malloc(sizeof(DoublyListNode));
	if (!add)
		return (FALSE);
	add->data = element.data;
	add_pre = &(pList->headerNode);
	idx = 0;
	while (idx < position)
	{
		add_pre = add_pre->pRLink;
		idx++;
	}
	if (!(add_pre->pRLink))
		add->pRLink = NULL;
	else
	{
		(add_pre->pRLink)->pLLink = add;
		add->pRLink = add_pre->pRLink;
	}
	add_pre->pRLink = add;
	add->pLLink = add_pre;
	pList->currentElementCount += 1;
	return (position + 1);
}

int	removeDLElement(DoublyList* pList, int position)
{
	DoublyListNode	*del;
	int				idx;

	if (!pList || 0 > position
	|| position > pList->currentElementCount)
		return (FALSE);
	del = &(pList->headerNode);
	idx = 0;
	while (idx <= position)
	{
		del = del->pRLink;
		idx++;
	}
	// wow point
	del->pLLink->pRLink = del->pRLink;
	// mistake point
	if (del->pRLink)
		del->pRLink->pLLink = del->pLLink;
	free (del);
	pList->currentElementCount -= 1;
	return (position + 1);
}

void	displayDoublyList(DoublyList* pList)
{
	DoublyListNode	*display;

	if (!pList || !(pList->currentElementCount))
		return ;
	display = pList->headerNode.pRLink;
	while (display)
	{
		printf("%9d | ", display->data);
		display = display->pRLink;
	}
	printf("\b\n");
}

DoublyListNode*	getDLElement(DoublyList* pList, int position)
{
	DoublyListNode	*rt_node;
	int				idx;

	if (!pList || 0 > position
	|| position > pList->currentElementCount)
		return (NULL);
	rt_node = &(pList->headerNode);
	idx = 0;
	while (idx <= position)
	{
		rt_node = rt_node->pRLink;
		idx++;
	}
	return (rt_node);
}

int	getDoublyListLength(DoublyList* pList)
{
	if (!pList)
		return (FALSE);
	return (pList->currentElementCount);
}


void	clearDoublyList(DoublyList* pList)
{
	DoublyListNode	*node;
	DoublyListNode	*next;

	if (!pList || !(pList->currentElementCount))
		return ;
	node = pList->headerNode.pRLink;
	while (node)
	{
		next = node->pRLink;
		free (node);
		node = next;
	}
}

void	deleteDoublyList(DoublyList* pList)
{
	DoublyListNode	*del;

	if (!pList || !(pList->currentElementCount))
		return ;
	clearDoublyList(pList);
	del = pList->headerNode.pRLink;
	if (pList->currentElementCount == 1)
		free (del);
	else
	{
		del = del->pRLink;
		while (del)
		{
			free (del->pLLink);
			if (!del->pRLink)
				free(del);
			del = del->pRLink;
		}
	}
	free (pList);
}
