#include <stdio.h>

void	print_doublon(int *a, int na, int *b, int nb)
{
	int flag = 0;
	int i = 0;
	int j = 0;

	while (i < na && j < nb)
	{
		if (a[i] == b[j])
		{
			if (flag == 1)
				printf(" ");
			printf("%i", a[i]);
			flag = 1;
			i++;
			j++;
		}
		else if (a[i] > b[j])
			j++;
		else if (a[i] < b[j])
			i++;
	}
	printf("\n");
}

/*
int main()
{
	int a[] = { 100,  200, 300};
	int b[] = {  2,  4,  5,6};
	print_doublon(a, 3, b, 4);
}
*/
