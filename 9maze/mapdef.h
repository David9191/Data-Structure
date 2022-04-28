#ifndef _MAP_DEF_
#define _MAP_DEF_

#define WIDTH 8
#define HEIGHT 8

#define NUM_DIRECTIONS 4

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// offset: x, y
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
	{0, -1},	// 북
	{1, 0},		// 동
	{0, 1},		// 남
	{-1, 0}		// 서
};

enum PosStatus { NOT_VISIT = 0, WALL = 1 , VISIT = 2 , VISITED = 5 };

typedef struct MapPositionType
{
	int x;
	int y;
	int direction;
} MapPosition;

typedef struct StackNodeType
{
	struct	StackNodeType	*pLink;
	MapPosition				myPosition;
} StackNode;

typedef struct MazeLinkedStack
{
	StackNode	*pTopElement;
	int			currentElementCount;
} LinkedStack;

void		findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack);
int			isHereEnd(MapPosition myPosition, MapPosition endPos);
void		printMaze(int mazeArray[HEIGHT][WIDTH]);
void		showPath(LinkedStack *pStack);

LinkedStack	*createLinkedStack();
int			pushLSMapPosition(LinkedStack *pStack, MapPosition element);
MapPosition	*popLS(LinkedStack *pStack);
MapPosition	*peekLS(LinkedStack *pStack);
void		deleteLinkedStack(LinkedStack *pStack);

#define FALSE	0
#define TRUE	1

#endif
