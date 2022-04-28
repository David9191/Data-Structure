#include "mapdef.h"

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos,
MapPosition endPos, LinkedStack *pStack)
{
	MapPosition	myPosition;

	myPosition = startPos;
	// push StartPostion in pStack;
	pushLSMapPosition(pStack, myPosition);
	mazeArray[myPosition.x][myPosition.y] = VISIT;
	while (1)
	{
		if (isHereEnd(myPosition, endPos))
			break ;
		if (mazeArray[myPosition.x][myPosition.y - 1] == NOT_VISIT)
		{
			myPosition.y -= 1;
			pushLSMapPosition(pStack, myPosition);
			mazeArray[myPosition.x][myPosition.y] = VISIT;
		}
		else if (mazeArray[myPosition.x + 1][myPosition.y] == NOT_VISIT)
		{
			myPosition.x += 1;
			pushLSMapPosition(pStack, myPosition);
			mazeArray[myPosition.x][myPosition.y] = VISIT;
		}
		else if (mazeArray[myPosition.x][myPosition.y + 1] == NOT_VISIT)
		{
			myPosition.y += 1;
			pushLSMapPosition(pStack, myPosition);
			mazeArray[myPosition.x][myPosition.y] = VISIT;
		}
		else if (mazeArray[myPosition.x - 1][myPosition.y] == NOT_VISIT)
		{
			myPosition.x -= 1;
			pushLSMapPosition(pStack, myPosition);
			mazeArray[myPosition.x][myPosition.y] = VISIT;
		}
		else
		{
			popLS(pStack);
			mazeArray[myPosition.x][myPosition.y] = VISITED;
			myPosition = *(peekLS(pStack));
		}
	}
}

int	isHereEnd(MapPosition myPosition, MapPosition endPos)
{
	if ((myPosition.x == endPos.x)
		&& (myPosition.y == endPos.y))
		return (1);
	else
		return (0);
}
void printMaze(int mazeArray[HEIGHT][WIDTH])
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (j == 0)
				printf("| ");
			if (mazeArray[i][j] == NOT_VISIT || mazeArray[i][j] == VISITED)
				printf("🛣 | ");
			else if (mazeArray[i][j] == WALL)
				printf("💎 | ");
			else
				printf("✅ | ");
		}
		printf("\n");
	}
	printf("\n");
}
void showPath(LinkedStack *pStack)
{
	StackNode *temp;

	temp = pStack->pTopElement;
	while (temp)
	{
		printf("{ %d, %d }\n", temp->myPosition.x, temp->myPosition.y);
		temp = temp->pLink;
	}
}
