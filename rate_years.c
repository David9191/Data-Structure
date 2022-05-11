#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

long long	thousand(long long n, float rate)
{
	rate /= 100;
	printf("0year : %lld\n", n);
	for (long long i = 0; i < 40; i++)
	{
		n = n + (n * rate);
		if (i == 0)
			printf("1year : %lld\n", n);
		else
			printf("%lldyears : %lld\n", i + 1, n);

	}
	return (n);
}

int	int_len(long long n)
{
	// 자릿수 구하기 for malloc
	int len = 0;
	
	for (len = 0; n > 0; len++)
		n /= 10;
	len = len + (len / 3) + 1;
	return (len);
}

int	make_str(char *str, long long n, int len)
{
	int	k = 1, cpy;

	// len - 2는 인덱스 생각해보면 됨.
	// cpy >= 0은 0인덱스까지 집어넣어야 되기 때문.
	for (cpy = len - 2; cpy >= 0; cpy--)
	{
		str[cpy] = (n % 10) + '0';
		if (k && k % 3 == 0)
		{
			cpy--;
			str[cpy] = ',';
		}
		n /= 10;
		k++;
	}
	// 마지막 번째 널 터미네이트.
	str[len - 1] = '\0';
	return (len - 1);
}

int	print_pervious(char *str)
{
	while (*str)
	{
		write(1, &(*str), 1);
		str++;
	}
	return (1);
}

int	print_main(char *str)
{
	// 앞에 쓸데없는 거 건너뛰기
	while (*str == -1 || *str == ',')
		str++;
	// 문자열 출력
	while (*str)
	{
		write(1, &(*str), 1);
		str++;
	}
	write(1, "\n", 1);
	return (1);
}

int main()
{
	char		*value, *str = "after 40 years : ";
	long long	sum = thousand(100000000, 25);
	int			i = 0;

	i = int_len(sum);
	value = malloc(sizeof(char) * i);
	memset(value, -1, i);
	make_str(value, sum, i);
	print_pervious(str);
	print_main(value);
	return (0);
}
