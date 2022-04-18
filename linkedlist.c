#include "linkedlist.h"

LinkedList	*createLinkedList(void)
{
	LinkedList  *rt_LList;

	rt_LList = malloc(sizeof(LinkedList));
	if (!rt_LList)
		return ;
	rt_LList->currentElementCount = 0;
	(rt_LList->headerNode).pLink = NULL;
	return (rt_LList);
}

int	addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode	*pre;
	ListNode	*next;
	int			idx;

	if (!pList || position > (pList->currentElementCount))
		return (FALSE);
	next = malloc(sizeof(ListNode));
	if (!next)
		return (FALSE);
	next = (pList->headerNode).pLink;
	pre = NULL;
	idx = 0;
	while (idx < position)
	{
		pre = next;
		next = next->pLink;
		idx++;
	}
	element.pLink = next;
	if (pre)
		pre->pLink = &element;
	else
		pList->headerNode.pLink = &element;
	pList->currentElementCount += 1;
	return (TRUE);
}

int removeLLElement(LinkedList* pList, int position)
{
	ListNode	*removeList;
	ListNode	*pre;
	int			idx;

	if (!pList || position > (pList->currentElementCount))
		return (FALSE);
	removeList = malloc(sizeof(ListNode));
	if (!removeList)
		return (FALSE);
	removeList = (pList->headerNode).pLink;
	pre = NULL;
	idx = 0;
	while (idx < position)
	{
		pre = removeList;
		removeList = removeList->pLink;
		idx++;
	}
	if (pre)
		pre->pLink = removeList->pLink;
	removeList->pLink = NULL;
	free (removeList);
	pList->currentElementCount -= 1;
	return (TRUE);
}

ListNode*	getLLElement(LinkedList* pList, int position)
{

}


void 		clearLinkedList(LinkedList* pList);
int			getLinkedListLength(LinkedList* pList)
{
	if (!pList)
		return (FALSE);
	return (pList->currentElementCount);
}
void		deleteLinkedList(LinkedList* pList);