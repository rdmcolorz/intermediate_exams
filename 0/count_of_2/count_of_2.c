int		count_of_2(int n)
{
	int count;
	int temp;
	int i;

	count = 0;
	i = 1;
	while (i <= n)
	{
		temp = i;
		while (temp)
		{
			if (temp % 10 == 2)
				count++;
			temp /= 10;
		}
		i++;
	}
	return (count);
}
