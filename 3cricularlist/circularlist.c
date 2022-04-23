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
	pre = &(pList->headerNode);
	idx = 0;
	while (idx++ < position)
		pre = pre->pLink;
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
	CircularListNode	*last;
	// ⬆️ 필수 0번째 삭제 했을 때 마지막 친구가 헤더의 피링크를 가리킬 수 있도록 해줌.
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
	// 실수 : -1을 안해줬었음. 왜 안해줬지?
	// 얘는 원형이라 그렇게 하면 한바퀴 돌고 + 1 만큼 더 감.
	last = getCLElement(pList, (pList->currentElementCount) - 1); // 필수
	del = pre->pLink;
	pre->pLink = del->pLink;
	free (del);
	last->pLink = pList->headerNode.pLink; // 필수
	pList->currentElementCount -= 1;
	// 이거 없으면 이상한데를 계속 가리키고 있음. 좋았다~
	if (pList->currentElementCount == 0)
		pList->headerNode.pLink = NULL;
	return (position);
}

CircularListNode	*getCLElement(CircularList *pList, int position)
{
	CircularListNode	*getNode;
	int			idx;

	if (!pList || position < 0 \
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

// remove에서 처리만 잘해주게 짜면 while 안돌고
// 계속 remove(position 0)넣고 하면 잘 될 듯?
void	clearCircularList(CircularList *pList)
{
	int	crnt;

	if (!pList || !(pList->currentElementCount))
		return ;
	crnt = pList->currentElementCount;
	for (int i = crnt; i > 0; i--)
		removeCLElement(pList, 0);
		// removeCLElement(pList, i - 1); /* 둘 다 됨. */
}

void	deleteCircularList(CircularList *pList)
{
	if (!pList)
		return ;
	clearCircularList(pList);
	free (pList);
}
