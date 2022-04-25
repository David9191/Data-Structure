#include "../7stack/linkedstack.h"

// 40 : (, 41 : ), 123 : {, 125 : }, 91 : [, 93 : ]

int	isBracketInStr(char *str)
{
	while (*str) {
		if ((*str == '(') || (*str == '{') || (*str == '['))
			return (TRUE);
		str++;
	}
	return (FALSE);
}

int	checkBracket(LinkedStack *pStack, char *str)
{
	StackNode	node;
	char		comp;

	if (!isBracketInStr(str))
		return (FALSE);
	while (*str) {
		if ((*str == '(') || (*str == '{') || (*str == '[')) {
			node.data = *str;
			pushLS(pStack, node);
		}
		if (*str == ')') {
			comp = (char)popLS(pStack);
			// 아스키 코드로 비교.
			if ((*str - 1 == comp)) ;
			else	return (FALSE);
		}
		else if ((*str == '}') || (*str == ']')) {
			comp = (char)popLS(pStack);
			if ((*str - 2 == comp)) ;
			else	return (FALSE);
		}
		str++;
	}
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	LinkedStack	*pStack;
	int			check;

	if (argc == 0 || !argv[1])
		return (FALSE);
	pStack = createLinkedStack();
	printf("\n--- check normal bracket ---\n\n");
	for (int i = 1; argv[i]; i++)
	{
		check = checkBracket(pStack, argv[i]);
		if (check)
			printf("case[%d] %15s : ✅\n", i, argv[i]);
		else
			printf("case[%d] %15s : ❌\n", i, argv[i]);
	}
	deleteLinkedStack(pStack);
	return (0);
}
