#include "flood_fill.h"
#include <stdio.h>
void	allWays(char **tab, t_point size, int x, int y, char c)
{
	if (tab[y][x] != c)
		return ;
	tab[y][x] = 'F';
	if (x + 1 < size.x)
		allWays(tab, size, x + 1, y, c);
	if (x - 1 >= 0)
		allWays(tab, size, x - 1, y, c);
	if (y + 1 < size.y)
		allWays(tab, size, x, y + 1, c);
	if (y - 1 >= 0)
		allWays(tab, size, x, y - 1, c);
	return ;
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char zoneChar;
	int x;
	int y;

	x = begin.x;
	y = begin.y;
	if (x < 0 || x >= size.x || y < 0 || y >= size.y)
		return ;
	zoneChar = tab[y][x];
	allWays(tab, size, x, y, zoneChar);
}
#include <stdio.h>
#include <stdlib.h>
char **make_area(char **zone, t_point size)
{
	char **area;
	int i;
	int x;

	i = 0;
	area = malloc(sizeof(char *) * size.y);
	while (i < size.y)
	{
		area[i] = malloc(sizeof(char) * (size.x * 2 - 1));
		x = 0;
		while (x < size.x * 2 - 1)
		{
			area[i][x] = zone[i][x];
			x++;
		}
		area[i][x] = 0;
		i++;
	}
	return (area);
}

void	print_tab(char **area, t_point size)
{
	int y;

	y = 0;
	while (y < size.y)
	{
		printf("%s\n", area[y]);
		y++;
	}
}

int main(void)
{
	char **area;
	t_point size = { 8, 5 };
	t_point begin = { 2, 2 };
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11000001",
	};
	area = make_area(zone,size);
	print_tab(area, size);
	flood_fill(area, size, begin);
	printf("\n");
	print_tab(area, size);
	return (0);
}