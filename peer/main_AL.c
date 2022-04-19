#include "../arraylist.h"
int	main(void)
{
	ArrayListNode	new;

	ArrayList	*arr1 = createArrayList(5);
	for (int i = 5; 0 < i; i--)
	{
		new.data = i;
		addALElement(arr1, getArrayListLength(arr1), new);
	}
	displayArrayList(arr1);
	removeALElement(arr1, getArrayListLength(arr1) - 1);
	displayArrayList(arr1);
	clearArrayList(arr1);
	// displayArrayList(arr1);
	// deleteArrayList(arr1);
	return (0);
}
