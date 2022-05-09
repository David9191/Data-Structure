#include <stdio.h>
#include <time.h>

long long	fact1(long long n)
{
	long long	ret = 0;
	
	if (n <= 1)
		ret = 1;
	else
		ret = n + (fact1(n - 1));
	return (ret);
}

long long	fact2(long long n)
{
	long long	ret = 0;
	
	for (long long i = 1; i <= n; i++)
		ret += i;
	return (ret);
}

int	main(void)
{
	int			start1, end1, start2, end2;
	float		res1, res2;
	long long	n_fac, i;

	start1 = clock();
	for (i = 1; i <= 10000; i++)
	{
		n_fac = fact1(i);
		if (i == 10000)
			printf("[%lld_fac] : %lld\n", i, n_fac);
	}
	end1 = clock();
	res1 = (float)(end1 - start1)/CLOCKS_PER_SEC;

	start2 = clock();
	for (i = 1; i <= 10000; i++)
	{
		n_fac = fact2(i);
		if (i == 10000)
			printf("[%lld_fac] : %lld\n", i, n_fac);
	}
	end2 = clock();
	res2 = (float)(end2 - start2)/CLOCKS_PER_SEC;
	printf("recursive time : %.5f\nfor iter time : %.5f\n", res1, res2);
	return (0);
}