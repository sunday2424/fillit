/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atropnik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:44:12 by atropnik          #+#    #+#             */
/*   Updated: 2019/05/17 23:18:42 by atropnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet	handle_input(char *file)
{
	int		fd;
	char	str[BUFF_SIZE + 1];
	t_list	result;
	int		bytesread;

	fd = open(file, O_RDONLY);
	bytesread = read(fd, str, BUFF_SIZE);
	str[bytesread] = '\0';
	return valid_input(fd, str);
}

t_tet	valid_input(int fd, char *str)
{
	t_tet	*list;
	char	**array;
	char	**tet;
	char	alpha;
	int		i;

	if (!(array = ft_strsplit(str, '\n')))
			return NULL;
	if (!(count_blocks(array) && (count_connection(array))))
		return NULL;
	alpha = 64;
	ft_lstnew(list);
	while ((array != NULL) && (**array != '\n'))
	{
		alpha += 1;
		tet = (char **)malloc(sizeof(char *) * 4 + 1);
		i = -1;
		while (++i <= 3)
		{
			tet[i] = ft_strnew(5);
			tet[i] = *array;
			array++;
		}
		list->str = new_tetris(tet, \
				(right(temp) - left(temp)), (bottom(temp) - top(temp)), alpha);
		free(tet);
		array++;
	// spit out a whole tetramino from big str and put each into new_tetris(trim(str))
	// return valid t_tetris if everything is good	
	}
	if (**array == '\n')
		return NULL;
	else
		return (list);
}

void	save_if_valid(char **map, int alp)
{
	if (alp < 0 || alp >= 26)
		print_error();
	if (count_blocks(map))
		if (count_connection(map))

}

int		count_blocks(char **map)
{
	int x;
	int y;
	int d;
	int s;

	y = 0;
	d = 0;
	s = 0;
	while (y < 5)
	{
		x = 0;
		while (x < 5)
		{
			if (map[y][x] == '.')
				d++;
			else if (map[y][x] == '#')
				s++;
			else if (map[y][x] != '\n')
				print_error();
			x++;
		}
		y++;
	}
	return ((d == 12 && s == 4) ? 1 : 0);
}

int		count_connection(char **map)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 5)
		{
			if ((x + 1) < 5 && map[y][x + 1] == '#')
				count++;
			if ((x - 1) >= 0 && map[y][x - 1] == '#')
				count++;
			if ((y + 1) < 4 && map[y + 1][x] == '#')
				count++;
			if ((y - 1) >= 0 && map[y - 1][x] == '#')
				count++;
			x++;
		}
		y++;
	}
	return ((count == 6 || count == 8) ? 1 : 0);
}
