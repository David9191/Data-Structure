#include "linkedlist.h"

int	main(void)
{
	LinkedList	*pList;
	ListNode	node;

	pList = createLinkedList();
	node.data = 42;
	node.pLink = NULL;
	for (int i = 0; i < 15; i++)
	{
		node.data += i;
		node.pLink = NULL;
		printf("add : %d", addLLElement(pList, i, node));
		displayLinkedList(pList);
	}
	printf("crntEleCnt : %d\n", pList->currentElementCount);

	for (int i = 14; i >= 0; i--)
	{
		printf("remove : %d", removeLLElement(pList, i));
		displayLinkedList(pList);
	}
	printf("crntEleCnt : %d\n", pList->currentElementCount);
	deleteLinkedList(pList);
	displayLinkedList(pList);
	return (0);
}
