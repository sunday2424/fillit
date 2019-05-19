/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atropnik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 22:45:52 by atropnik          #+#    #+#             */
/*   Updated: 2019/05/19 00:42:41 by atropnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet	*handle_input(char *file)
{
	int		fd;
	char	str[BUFF_SIZE + 1];
	int		bytesread;

	
	fd = open(file, O_RDONLY);
	bytesread = read(fd, str, BUFF_SIZE);
	str[bytesread] = '\0';
	return valid_input(str);
}

t_tet	*valid_input(char *str)
{
	char	**array;

	if (!(array = ft_strsplit(str, '\n')) || ctbks(array) || ccon(array))
		print_error();
	else
		return (save_if_valid(array));
}

t_tet	*save_if_valid(char **array)
{
	int		i;

	i = 0;
	while (*array)
	{
		i++;
		array++;
	}
	return (start_list(i, array));
	/*
	if (!(tet = (char **)malloc(sizeof(char *) * 4 + 1)))
		print_error();
	tet[4] = NULL;
	while ((array != NULL) && (**array != '\n'))
	{
		alpha += 1;
		while (*tet)
		{
			*tet = ft_strnew(5);
			*tet = *array;
			array++;
			tet++;
		}
		tet = trim_edge(tet);
		add_to_list(&list, new_tetris(*tet, (right(tet) \
					   - left(tet)), (bottom(tet) - top(tet)), alpha));
		array++;
	}
	if ((**array == '\n') || alpha > 90)
		print_error();
	return (list);
	*/
}

int		ctbks(char **map)
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

int		ccon(char **map)
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
