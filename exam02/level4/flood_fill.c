#include "flood_fill.h"
#include <stdlib.h>

void	dfs(char **tab, int r, int c, t_point size, int color)
{
	if (tab[r][c] == color)
	{
		tab[r][c] = 'F';
		if (r >= 1)
		{
			dfs(tab, r - 1, c, size, color);
		}
		if (c >= 1)
		{
			dfs(tab, r, c - 1, size, color);
		}
		if (r + 1 < size.y)
		{
			dfs(tab, r + 1, c, size, color);
		}
		if (c + 1 < size.x)
		{
			dfs(tab, r, c + 1, size, color);
		}
	}
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	int	color;
	int	r;
	int	c;

	r = begin.y;
	c = begin.x;
	if (r < 0 || c < 0 || r >= size.y || c >= size.x)
		return ;
	color = tab[r][c];
	if (color != 'F')
	{
		dfs(tab, r, c, size, color);
	}
}

#include "flood_fill.h"
#include <stdio.h>
#include <stdlib.h>

char	**make_area(char **zone, t_point size)
{
	char	**new;

	new = malloc(sizeof(char *) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}
	return (new);
}

int	main(void)
{
	t_point size = {8, 5};
	// char *zone[] = {
	// 	"11111111",
	// 	"10001001",
	// 	"10010001",
	// 	"10110001",
	// 	"11100001",
	// };

	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10100001",
		"11000000",
	};

	char **area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	// t_point begin = {7, 4};
	t_point begin = {2, 2};

	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}