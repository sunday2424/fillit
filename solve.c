#include "fillit.h"

int		check_place(int i, int j, t_tet *tetris, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < tetris->height)
	{
		x = 0;
		while (x < tetris->width)
		{
			if (tetris->str[y][x] == '#' && map->array[y+j][x+i] != '.')
				return (0);
			x++;
		}
		y++;
	}
	put_piece(tetris, map, new_position(x, y), tetris->alpha);
	return (1);
}

void	put_piece(t_tet *tetris, t_map *map, t_position *position, char c)
{
	int	x;
	int	y;

	y = 0;
	while (y < tetris->height)
	{
		x = 0;
		printf("%d :y\n", y);
		while (x < tetris->width)
		{
			printf("%d :x\n\n", x);
			if (tetris->str[y][x] == '#')
			{
				if (map->size > position->y + y)
				{
					printf("setting up piece at x: %d y: %d\n", position->x + x, position->y + y);
					map->array[position->y + y][position->x + x] = c;
				}
			}
			x++;
		}
		y++;
	}
	ft_memdel((void **)&position);
}

int		rec_backtrack(t_map *map, t_tet *tetlst)
{
	int		x;
	int		y;
	t_tet	*tetris;


	printf("rec_back start\n");

	if(!tetlst)
		return(0);
	y = 0;
	tetris = tetlst;
	while (y <= (map->size - tetlst->height))
	{
		x = 0;
		while (x <= (map->size - tetlst->width))
		{
			if (check_place(x, y, tetris, map))
			{
				if (rec_backtrack(map, tetlst->next))
					return (0);
				else
					put_piece(tetris, map, new_position(x, y), '.');
			}
			x++;
		}
		y++;
	}
	printf("rec_back end\n");
	return(1);
}

t_map	*solve(t_tet *tetlst)
{
	int		x;
	t_map	*map;

	x = 2;
	map = new_map(x);
	while (rec_backtrack(map, tetlst))
	{
		free_map(map);
		x++;
		map = new_map(x);
	}
	return (map);
}
