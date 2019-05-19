#include "fillit.h"

int		top (char **map)
{
	int	x;
	int	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (map[y][x] == '#')
				break ;
			x++;
		}
		if (map[y][x] == '#')
			break ;
		y++;
	}
	return (y);
}

int		bottom (char **map)
{
	int	x;
	int	y;

	y = 3;
	while (y >= 0)
	{
		x = 3;
		while (x >= 0)
		{
			if (map[y][x] == '#')
				break ;
			x--;
		}
		if (map[y][x] == '#')
			break ;
		y--;
	}
	return (y);
}

int		right (char **map)
{
	int	x;
	int	y;

	x = 3;
	while (x >= 0)
	{
		y = 3;
		while (y >= 0)
		{
			if (map[y][x] == '#')
				break ;
			y--;
		}
		if (map[y][x] == '#')
			break ;
		x--;
	}
	return (x);
}
int		left (char **map)
{
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (map[y][x] == '#')
				break ;
			x++;
		}
		if (map[y][x] == '#')
			break ;
		y++;
	}
	return (x);
}

char	**trim_edge (char **map)
{
	char	**tmp;
	int		i;
	int		j;
	int		x;
	int		y;

	y = 0;
	j = top(map);
	tmp = (char **)malloc(sizeof(char *) * (bottom(map) - top(map)) + 1);
	tmp[bottom(map) - top(map)] = NULL;
	while (y < (bottom(map) - top(map)))
	{
		x = 0;
		i = left(map);
		tmp[y] = (char *)malloc(sizeof(char) * (right(map) - left(map)) + 1);
		tmp[y][right(map) - left(map)] = '\0';
		while (x < (right(map) - left(map)))
			tmp[y][x++] = map[j][i++];
		y++;
		j++;
	}
	return (tmp);
}
