#include"linkedliststack.h"
#include"../../2linkedlist/linkedlist.h"
#include<stdio.h>
#include<stdlib.h>

LinkedStack* createLinkedStack()
{
	LinkedStack	*stack;

	stack = malloc(sizeof(LinkedStack));
	if(stack == NULL)
		return (NULL);
	stack->currentElementCount = 0;
	stack->pTopElement = NULL;
	return (stack);
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	StackNode	*new;

	if(pStack == NULL)
		return (ERROR);
	new = malloc(sizeof(StackNode));
	if(new == NULL)
		return (ERROR);
	*new = element;
	new->pLink = pStack->pTopElement;
	pStack->pTopElement = new;
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode* popLS(LinkedStack* pStack)
{
	StackNode	*popNode;

	if(pStack == NULL || pStack->pTopElement == NULL)
		return (NULL);
	popNode = pStack->pTopElement;
	pStack->pTopElement = popNode->pLink;
	pStack->currentElementCount--;
	return (popNode);
}

StackNode* peekLS(LinkedStack* pStack)
{
	if(pStack == NULL || pStack->pTopElement == NULL)
		return (NULL);
	return (pStack->pTopElement);
}

void deleteLinkedStack(LinkedStack* pStack)
{
	StackNode	*tmp;

	if(pStack == NULL || pStack->pTopElement == NULL)
		return ;
	while(pStack->pTopElement != NULL)
	{
		tmp = pStack->pTopElement;
		pStack->pTopElement = tmp->pLink;
		free(tmp);
	}
	free(pStack);
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	if(pStack == NULL)
		return (ERROR);
	if(pStack->currentElementCount == 0)
		return (TRUE);
	else
		return (FALSE);
}
