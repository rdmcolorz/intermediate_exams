int		find_pivot(int *arr, int n)
{
	int i;
	int sum = 0;
	int left = 0;

	i = 0;
	while (i < n)
	{
		sum += arr[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		sum -= arr[i];
		if (sum == left)
			return (i);
		left += arr[i];
		i++;
	}
	return (-1);
}
#include <stdio.h>
int main()
{
	int arr[5] = {1, 100, 0, 0, 1};

	printf("%i\n", find_pivot(arr, 5));
}