#include <stdio.h>
#include <time.h>

int	fibo1(int n)
{
	int	ret = 0;

	if (n == 0)
		ret = 0;
	else if (n == 1)
		ret = 1;
	else
		ret = fibo1(n - 1) + fibo1(n - 2);
	return (ret);
}
int	main(void)
{
	int	fib, i;

	for (i = 2; i < 30; i++)
	{
		fib = fibo1(i);
		printf("fibo1[%d] : %d\n", i, fib);
	}
	return (0);
}