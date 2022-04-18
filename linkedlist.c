#include "linkedlist.h"

LinkdedList	*createLinkedList(void)
{
	LinkedList  *newLList = NULL;

	newLList = (LinkedList *)malloc(sizeof(LinkedList));
	if (newLList)
	{
		newLList -> currentElementCount = 0;
		(newLList -> headerNode).pLink = NULL;
	}
	return (newLList);
}

int	addLLElement(LinkedList* pList, int position, ListNode element)
{
	int	idx;
	int	crnt;
	ListNode pLHeadNode;

	crnt = pList -> currentElementCount;
	if (!pList || position > crnt)
		return (FALSE);
	pLHeadNode = pList -> headerNode;
	idx = 0;
	while (idx < position)
	{
		pLHeadNode = pLHeadNode.pLink[0];
		idx++;
	}
	if (!pLHeadNode.pLink)
		pLHeadNode = element;
	else
	{
		element.pLink = pLHeadNode.pLink;
		pLHeadNode.pLink = &element;
	}
	pList -> currentElementCount += 1;
	return (position);
}

int	removeLLElement(LinkedList *pList, int position)
{
	int         idx = 0, ret = ERROR;
	ListNode    *next;
	ListNode    *pre = NULL;

	if (pList)
	{
		if (position < pList -> currentElementCount)
		{
			next = (pList -> headerNode).pLink;
			while (idx++ < position)
			{
				pre = next;
				next = next -> pLink;
			}
			next -> data = 0;
			if (pre)
				pre -> pLink = next -> pLink;
			next -> pLink = NULL;
			free(next);
			ret = position;
		}
	}
	return (ret);
}

ListNode*	getLLElement(LinkedList* pList, int position)
{
	ListNode	*rt_ListNode;
	ListNode	pLHeadNode;
	int	idx;

	if (!pList || position > pList -> currentElementCount)
		return (NULL);
	pLHeadNode = pList -> headerNode;
	idx = 0;
	while (idx < position)
	{
		pLHeadNode = pLHeadNode.pLink[0];
		idx++;
	}
	rt_ListNode = pLHeadNode.pLink;
	return (rt_ListNode);
}

void	clearLinkedList(LinkedList *pList)
{
	ListNode    *tmp;
	ListNode    *next;

	if (pList)
	{
		next = (pList -> headerNode).pLink;
		while (next)
		{
			tmp = next -> pLink;
			next -> data = 0;
			next -> pLink = NULL;
			free(next);
			next = tmp;
		}
		(pList -> headerNode).pLink = NULL;
		pList -> currentElementCount = 0;
	}
}

int	getLinkedListLength(LinkedList* pList)
{
	if (!pList)
		return (FALSE);
	return (pList -> currentElementCount);
}

void	deleteLinkedList(LinkedList *pList)
{
	if (pList)
	{
		clearLinkedList(pList);
		free(pList);
	}
}
