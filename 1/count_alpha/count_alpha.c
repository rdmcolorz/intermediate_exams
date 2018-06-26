#include <stdio.h>
#include <unistd.h>

int		is_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

char	*lowercase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
		i++;
	}
	return (str);
}

int		search(char c, char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

int		is_dup(char c, int i, char *str)
{
	if (i == 0)
		return (0);
	while (--i >= 0)
	{
		if (str[i] == c)
			return (1);
	}
	return (0);
}

int		checkRest(int i, char *str)
{
	while (str[i])
	{
		if (!is_dup(str[i], i, str) && is_alpha(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	int i;
	char *str;

	if (ac == 2)
	{
		i = 0;
		str = lowercase(av[1]);
		while (av[1][i])
		{
			if (is_alpha(str[i]) && !is_dup(str[i], i, str))
			{
				printf("%i%c", search(str[i], str), str[i]);
				if (checkRest(i + 1, str))
					printf(", ");
			}
			i++;
		}
		printf("\n");
	}
	else
		write(1, "\n", 1);
	return (0);
}
