#include "../6stack/linkedstack.h"

// 40 : (, 41 : ), 123 : {, 125 : }, 91 : [, 93 : ]

int	checkBracket(LinkedStack *pStack, char *str)
{
	StackNode	node;
	char		comp;

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
	if (isLinkedStackEmpty(pStack))
	{
		deleteLinkedStack(pStack);
		return (TRUE);
	}
	else
	{
		deleteLinkedStack(pStack);
		return (FALSE);
	}
}

int	main(int argc, char *argv[])
{
	LinkedStack	*pStack;
	int			check;

	if (argc == 0 || !argv[1])
		return (FALSE);
	printf("\n--- check normal case bracket ---\n\n");
	for (int i = 1; argv[i]; i++)
	{
		pStack = createLinkedStack();
		check = checkBracket(pStack, argv[i]);
		if (check)
			printf("case[%d] %15s : ✅\n", i - 1, argv[i]);
		else
			printf("case[%d] %15s : ❌\n", i - 1, argv[i]);
	}
	return (0);
}

// In test case⬇️
// a check_bracket.c ../7stack/linkedstack.c
// s "(" ")" "{(A * B) + C}" "1+2-3" "{C[A+B(5*5)]}" "{[)}" "1+2"
// find ../ -type d -name "a.out*" -print -exec rm -rf {} +
// git commit -am == all message
