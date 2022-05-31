#include "graphlinkedlist.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList	*createLinkedList()
{
	LinkedList	*ret;

	ret = malloc(sizeof(LinkedList));
	if(!ret)
		return (NULL);
	ret->currentElementCount = 0;
	ret->headerNode.data.vertexID = 0;
	ret->headerNode.data.weightH = 0;
	ret->headerNode.pLink = NULL;
	return (ret);
}
int	addLLElement(LinkedList *pList, int position, ListNode element)
{
	ListNode	*curr;
	ListNode	*tmp;

	if (position > pList->currentElementCount)
		return (FALSE);
	curr = &pList->headerNode;
	while (position > 0)
	{
		curr = curr->pLink;
		position--;
	}
	tmp = malloc(sizeof(ListNode));
	if (tmp == NULL)
		return (FALSE);
	tmp->data = element.data;
	tmp->pLink = curr->pLink;
	curr->pLink = tmp;
	pList->currentElementCount++;
	return (TRUE);

}
int	removeLLElement(LinkedList *pList, int position)
{
	ListNode	*curr;
	ListNode	*toDelete;

	if(position >= pList->currentElementCount)
		return (FALSE);
	curr = &pList->headerNode;
	while (position > 0)
	{
		curr = curr->pLink;
		position--;
	}
	toDelete = curr->pLink;
	curr->pLink = toDelete->pLink;
	free(toDelete);
	pList->currentElementCount--;
	return (TRUE);
}

ListNode	*getLLElement(LinkedList *pList, int position)
{
	ListNode	*curr;

	if(position >= pList->currentElementCount)
		return (NULL);
	curr = pList->headerNode.pLink;
	while (position > 0)
	{
		curr = curr->pLink;
		position--;
	}
	return (curr);
}

void	clearLinkedList(LinkedList *pList)
{
	ListNode	*toDelete;

	while(pList->headerNode.pLink != NULL)
	{
		toDelete = pList->headerNode.pLink;
		pList->headerNode.pLink = toDelete->pLink;
		free(toDelete);
	}
	pList->currentElementCount = 0;
}

int	getLinkedListLength(LinkedList *pList)
{
	return (pList->currentElementCount);
}

void	deleteLinkedList(LinkedList *pList)
{
	clearLinkedList(pList);
	free(pList);
	pList = NULL;
}
