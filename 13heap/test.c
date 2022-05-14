#include <stdio.h>

void	swap(int arr[])
{
	int	temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
}

int	main(void)
{
	int	arr[2] = { 1, 42 };
	printf("%d %d\n", arr[0], arr[1]);
	swap(arr);
	printf("%d %d\n", arr[0], arr[1]);
	arr[1] = -2147483648;
	if (arr[1] == 0)
		printf("omg\n");
}