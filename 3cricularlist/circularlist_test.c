#include "circularlist.h"

int main(void)
{
	CircularList		*pList;
	CircularListNode	new;
	// CircularListNode	*test;
	int					data;

	pList = createCircularList();
	data = 10;
	// new.data = data;
	// addLLElement(pList, 0, new);
	// // displayLinkedList(pList);
	// new.data += 10;
	// addLLElement(pList, 0, new);
	// displayLinkedList(pList);
	// // 잘 나왔나 확인.
	// for (size_t i = 0; i < 15; i++)
	// {
	// 	new.data = data;
	// 	addLLElement(pList, 0, new);
	// 	data += 10;
	// }
	// displayLinkedList(pList);
	for (size_t i = 0; i < 15; i++)
	{
		new.data = data;
		addCLElement(pList, 0, new);
		displayCircularList(pList);
		data += 10;
	}
	// displayCircularList(pList);
	printf("\blen : %d\n", getCircularListLength(pList));
	// printf("%d\n", test->pLink->data);
	for (int i = 15; i > 0; i--)
	{
		removeCLElement(pList, 0);
		// test = getCLElement(pList, 14);
		displayCircularList(pList);
		// printf("%d\n", test->pLink->data);
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