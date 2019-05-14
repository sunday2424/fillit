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

char	**trim_tet (char **map)
{
	char	**tmp;
	int		x;
	int		y;

	y = 0;
	tmp = (char **)malloc(sizeof(char *) * (bottom - top) + 1);
	while (y < (bottom - top))
	{
		tmp[y] = (char *)malloc(sizeof(char) * (right - left) + 1);
		y++;
	}
	return (tmp);
}