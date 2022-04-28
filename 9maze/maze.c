#include "mapdef.h"

int	main(void)
{
	int			mazeArray[8][8] = {
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 0, 1},
		{1, 0, 1, 0, 1, 1, 0, 1},
		{0, 0, 1, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 0, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 0, 0}
	};
	LinkedStack	*pStack;
	MapPosition	startPos;
	MapPosition	endPos;

	pStack = createLinkedStack();
	startPos.x = 4; startPos.y = 0;
	endPos.x = 7; endPos.y = 1;
	// printMaze(mazeArray);
	findPath(mazeArray, startPos, endPos, pStack);
	printMaze(mazeArray);
	showPath(pStack);
	system("leaks a.out | grep leaked");
}
