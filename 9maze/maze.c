#include "mapdef.h"

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos,
MapPosition endPos, LinkedStack *pStack);
int pushLSMapPosition(LinkedStack* pStack, MapPosition data);
void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]);
void printMaze(int mazeArray[HEIGHT][WIDTH]);
int	isHereEnd(MapPosition myPosition, MapPosition endPos);

void printMaze(int mazeArray[HEIGHT][WIDTH])
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (j == 0)
				printf("| ");
			if (mazeArray[i][j] == 0 || mazeArray[i][j] == 5)
				printf("🛣 | ");
			else if (mazeArray[i][j] == 1)
				printf("💎 | ");
			else
				printf("✅ | ");
		}
		printf("\n");
	}
	printf("\n");
}

int	isHereEnd(MapPosition myPosition, MapPosition endPos)
{
	if ((myPosition.x == endPos.x)
		&& (myPosition.y == endPos.y))
		return (1);
	else
		return (0);
}

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos,
MapPosition endPos, LinkedStack *pStack)
{
	MapPosition	myPosition;
	// LinkedStack *rtStack;

	myPosition = startPos;
	mazeArray[myPosition.x][myPosition.y] = 2;
	while (1)
	{
		if (isHereEnd(myPosition, endPos))
			break ;
		if (mazeArray[myPosition.x][myPosition.y - 1] == 0)
		{
			myPosition.y -= 1;
			pushLS(pStack, myPosition);
			mazeArray[myPosition.x][myPosition.y] = 2;
		}
		else if (mazeArray[myPosition.x + 1][myPosition.y] == 0)
		{
			myPosition.x += 1;
			pushLS(pStack, myPosition);
			mazeArray[myPosition.x][myPosition.y] = 2;
		}
		else if (mazeArray[myPosition.x][myPosition.y + 1] == 0)
		{
			myPosition.y += 1;
			pushLS(pStack, myPosition);
			mazeArray[myPosition.x][myPosition.y] = 2;
		}
		else if (mazeArray[myPosition.x - 1][myPosition.y] == 0)
		{
			myPosition.x -= 1;
			pushLS(pStack, myPosition);
			mazeArray[myPosition.x][myPosition.y] = 2;
		}
		else
		{
			popLS(pStack);
			mazeArray[myPosition.x][myPosition.y] = 5;
			myPosition = *(peekLS(pStack));
		}
	}
}

int	main(void)
{
	// int mazeArray[8][8] = {
	// 	{0, 0, 1, 1, 1, 1, 1, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 1, 1, 0, 1, 1, 1, 1},
	// 	{1, 1, 1, 0, 1, 1, 1, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 1, 1, 1, 1, 1, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 0},
	// 	{1, 1, 1, 1, 1, 1, 1, 0}
	// };
	int mazeArray[8][8] = {
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 0, 1},
		{1, 0, 1, 0, 1, 1, 0, 1},
		{0, 0, 1, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 0, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 0, 0}
	};

	LinkedStack *pStack = createLinkedStack();
	MapPosition startPos;
	startPos.x = 4;
	startPos.y = 0;
	MapPosition endPos;
	endPos.x = 7;
	endPos.y = 1;
	printMaze(mazeArray);
	findPath(mazeArray, startPos, endPos, pStack);
	printMaze(mazeArray);

	StackNode *temp;
	temp = pStack->pTopElement;
	// printf("%d", temp->myPosition.x);
	// printf("%d\n", temp->myPosition.y);
	// temp = temp->pLink;
	// printf("%d", temp->myPosition.x);
	// printf("%d\n", temp->myPosition.y);
	// while(temp)
	// {
	// 	printf("[%d, %d]->", temp->myPosition.x, temp->myPosition.y);
	// 	temp = temp->pLink;
	// }
}
