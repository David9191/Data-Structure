#include "circularlist.h"

// remove, clear 다시 짜기
// cmd + k + 0 == 함수 모두 닫기
// cmd + k + j == 함수 모두 열기 핵꿀 단축키

CircularList *createCircularList(void)
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

int	addCLElement(CircularList *pList, int position, CircularListNode element)
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
	last = getCLElement(pList, pList->currentElementCount);
	last->pLink = pList->headerNode.pLink;
	pList->currentElementCount += 1;
	return (position + 1);
}

int	removeCLElement(CircularList *pList, int position)
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

CircularListNode*	getCLElement(CircularList *pList, int position)
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

void	displayCircularList(CircularList *pList)
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

int	getCircularListLength(CircularList *pList)
{
	if (!pList)
		return (FALSE);
	return (pList->currentElementCount);
}


void	clearCircularList(CircularList *pList)
{
	CircularListNode	*node;
	CircularListNode	*next;
	int					idx;
	int					crnt;

	if (!pList || !(pList->currentElementCount))
		return ;
	node = pList->headerNode.pLink;
	idx = 0;
	crnt = pList->currentElementCount;
	while (idx < crnt)
	{
		next = node->pLink;
		free (node);
		node = next;
	}
	pList->currentElementCount = 0;
	pList->headerNode.pLink = NULL;
}

void	deleteCircularList(CircularList *pList)
{
	if (!pList)
		return ;
	clearCircularList(pList);
	free (pList);
}
