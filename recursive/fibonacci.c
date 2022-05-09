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
int	fibo2(int n)
{
	int	ret = 0;

	if (n < 2)
		ret = n;
	else
	{
		int	i = 0, temp = 0, current = 1, last = 0;
		for (i = 2; i <= n; i++)
		{
			temp = current;
			current += last;
			last = temp;
		}
		ret = current;
	}	
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