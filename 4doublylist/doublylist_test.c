#include "doublylist.h"

int	main(void)
{
	DoublyList		*pList;
	DoublyListNode	node;

	pList = createDoublyList();
	node.data = 55555;
	node.pRLink = NULL;
	for (int i = 0; i < 15; i++)
	{
		node.data += i;
		node.pRLink = NULL;
		printf("add : %d", addDLElement(pList, i, node));
		displayDoublyList(pList);
	}
	printf("crntEleCnt : %d\n", pList->currentElementCount);

	for (int i = 14; i >= 0; i--)
	{
		printf("remove : %d", removeDLElement(pList, i));
		displayDoublyList(pList);
	}
	printf("\ncrntEleCnt : %d\n", pList->currentElementCount);
	deleteDoublyList(pList);
	displayDoublyList(pList);
	return (0);
}
