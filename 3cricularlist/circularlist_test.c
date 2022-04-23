#include "circularlist.h"

int main(void)
{
	CircularList		*pList;
	CircularListNode	new;
	// CircularListNode	*test;
	int					data;

	pList = createCircularList();
	data = 10;
	for (size_t i = 0; i < 15; i++)
	{
		new.data = data;
		addCLElement(pList, 0, new);
		displayCircularList(pList);
		data += 10;
	}
	printf("\blen : %d\n", getCircularListLength(pList));
	// printf("%d\n", test->pLink->data);
	for (int i = 15; i > 0; i--)
	{
		removeCLElement(pList, i - 1);
		displayCircularList(pList);
	}
	printf("\blen : %d\n", getCircularListLength(pList));
	// test = getCLElement(pList, 0);
	// printf("%d\n", test->pLink->data);
	displayCircularList(pList);
	printf("%p\n", pList->headerNode.pLink);
	clearCircularList(pList);
	printf("%p\n", pList->headerNode.pLink);
	deleteCircularList(pList);
	printf("%p\n", pList->headerNode.pLink);
}
