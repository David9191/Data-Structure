#include "linkedlist.h"

LinkedList* createLinkedList(void)
{
	LinkedList	*rtn_LinkedList;

	rtn_LinkedList = malloc(sizeof(LinkedList));
	if (!rtn_LinkedList)
		return ;
	// c에서 버그 없애주는 거라는데 솔직히 잘 모르겠음.
	memset(rtn_LinkedList, 0, sizeof(LinkedList));
	rtn_LinkedList->currentElementCount = 0;
	rtn_LinkedList->headerNode.pLink = NULL;
	return (rtn_LinkedList);
}

int	addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode	*new;
	ListNode	*pre;
	int			idx;

	if (!pList || 0 < position \
		|| position > pList->currentElementCount)
		return (NULL);
	// 왜 말록을 해주나? 그냥 element바로 쓰면 되는거 아니야?
	// no! 바로 element를 쓰면 얘의 주소는 이상한데 있어서 안 됨.
	new = malloc(sizeof(ListNode));
	if (!new)
		return (FALSE);
	new->data = element.data;
	pre = &(pList->headerNode);
	idx = 0;
	// 32 라인을 pre = &(pList->headerNode); 로 바꾸면
	// idx < position 이렇게 해도 됨.
	while (idx < position)
	{
		pre = pre->pLink;
		idx++;
	}
	new->pLink = pre->pLink;
	pre->pLink = new;
	pList->currentElementCount += 1;
	return (position + 1);
}

int	removeLLElement(LinkedList* pList, int position)
{
	ListNode	*del;
	ListNode	*pre;
	int			idx;

	if (!pList || 0 < position \
		|| position > pList->currentElementCount)
		return (NULL);
	pre = &(pList->headerNode);
	idx = 0;
	while (idx < position)
	{
		pre = pre->pLink;
		idx++;
	}
	del = pre->pLink;
	pre->pLink = del->pLink;
	// del == NULL이면 free (NULL)인데 에러 안생기네?? 신기신기 왜지?
	free (del);
	pList->currentElementCount -= 1;
	return (position);
}

ListNode*	getLLElement(LinkedList* pList, int position)
{
	// position + 1만큼 headernode로 부터 이동해야 한다.
	ListNode	*getNode;
	int			idx;

	if (!pList || 0 < position \
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


int	getLinkedListLength(LinkedList* pList)
{
	if (!pList)
		return (FALSE);
	return (pList->currentElementCount);
}
void	clearLinkedList(LinkedList* pList);
void	deleteLinkedList(LinkedList* pList);