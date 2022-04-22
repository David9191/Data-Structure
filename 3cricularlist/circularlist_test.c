#include "circularlist.h"

int main(void)
{
	CircularList		*pList;
	CircularListNode	new;
	int					data;

	pList = createLinkedList();
	data = 10;
	// new.data = data;
	// addLLElement(pList, 0, new);
	// // displayLinkedList(pList);
	// new.data += 10;
	// addLLElement(pList, 0, new);
	// displayLinkedList(pList);
	// // 잘 나왔나 확인.
	// printf("%d", pList->headerNode.pLink->pLink->pLink->data);
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
		addLLElement(pList, i, new);
		data += 10;
	}
	displayLinkedList(pList);
}