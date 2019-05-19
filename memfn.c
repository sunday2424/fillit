#include "fillit.h"

t_map	*new_map(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->array = (char **)ft_memalloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map->array[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			map->array[i][j] = '.';
			j++;
		}
		map->array[i][j] = '\0';
		i++;
	}
	map->array[i] = NULL;
	return (map);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}

t_tet	*new_tetris(char **pos, int width, int height, char value)
{
	t_tet	*tetris;

	tetris = ft_memalloc(sizeof(t_tet));
	tetris->str = pos;
	tetris->width = width;
	tetris->height = height;
	tetris->alpha = value;
	return (tetris);
}

void	free_tetris(t_tet *tetris)
{
	int	y;

	y = 0;
	while (y < tetris->height)
	{
		ft_memdel((void **)(&(tetris->str[y])));
		y++;
	}
	ft_memdel((void **)(&(tetris->str)));
	ft_memdel((void **)&tetris);
}

t_position	*new_position(int x, int y)
{
	t_position	*position;

	position = ft_memalloc(sizeof(t_position));
	position->x = x;
	position->y = y;
	return (position);
}