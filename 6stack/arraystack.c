#include "arraystack.h"

ArrayStack*	createArrayStack(int maxElementCount)
{
	ArrayStack *rt_stack;

	if (maxElementCount <= 0)
		return (NULL);
	rt_stack = malloc(sizeof(ArrayStack));
	if (!rt_stack)
		return (NULL);
	memset(rt_stack, 0, sizeof(ArrayStack));
	// 배열 생성
	rt_stack->pTopElement = malloc(sizeof(StackNode) * maxElementCount);
	if (!rt_stack->pTopElement)
		return (NULL);
	memset(rt_stack->pTopElement, 0, sizeof(StackNode) * maxElementCount);
	rt_stack->currentElementCount = 0;
	rt_stack->maxElementCount = maxElementCount;
	return (rt_stack);
}

int	pushAS(ArrayStack* pStack, StackNode element)
{
	int	crnt;

	if (!pStack || isArrayStackFull(pStack))
		return (FALSE);
	crnt = pStack->currentElementCount;
	pStack->pTopElement[crnt] = element;
	pStack->currentElementCount += 1;
	return (TRUE);
}

int	popAS(ArrayStack* pStack)
{
	int	rt_data;
	int	topData; // topData의 위치

	if (!pStack || isArrayStackEmpty(pStack))
		return (FALSE);
	topData = (pStack->currentElementCount) - 1;
	rt_data = peekAS(pStack);
	pStack->pTopElement[topData].data = 0;
	pStack->currentElementCount -= 1;
	return (rt_data);
}

int	peekAS(ArrayStack* pStack)
{
	int	topData;

	if (!pStack || isArrayStackEmpty(pStack))
		return (FALSE);
	topData = (pStack->currentElementCount) - 1;
	return (pStack->pTopElement[topData].data);
}

void	deleteArrayStack(ArrayStack* pStack)
{
	if (!pStack)
		return ;
	free (pStack->pTopElement);
	free (pStack);
}

int	isArrayStackFull(ArrayStack* pStack)
{
	if (!pStack
		|| pStack->currentElementCount != pStack->maxElementCount)
		return (FALSE);
	else
		return (TRUE);
}

int	isArrayStackEmpty(ArrayStack* pStack)
{
	if (!pStack
	|| pStack->currentElementCount != 0)
		return (FALSE);
	else
		return (TRUE);
}
