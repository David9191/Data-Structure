#include "arraylist.h"

int	main(void)
{
	ArrayList		*pList = createArrayList(15);
	ArrayListNode	node;
	
	node.data = 10;
	for (size_t i = 0; i < 15; i++)
	{
		addALElement(pList, i, node);
		displayArrayList(pList);
		node.data += 10;
	}
	printf("len : %d\n", getArrayListLength(pList));
	for (size_t i = 15; i > 0 ; i--)
	{
		removeALElement(pList, i - 1);
		displayArrayList(pList);
	}
	printf("len : %d\n", getArrayListLength(pList));
	clearArrayList(pList);
	deleteArrayList(pList);
}
