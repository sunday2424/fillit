/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atropnik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 22:45:52 by atropnik          #+#    #+#             */
/*   Updated: 2019/05/19 04:29:48 by atropnik         ###   ########.fr       */
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

	if (!(array = ft_strsplit(str, '\n')))
		return NULL;
	else
		return (save_if_valid(array));
}

t_tet	*save_if_valid(char **array)
{
	int		i;
	int		j;
	int		num;
	char	***grps_of_4;
	char	**temp;

	i = 0; 
	while (array[i])
		i++;
	grps_of_4 = (char ***)malloc(sizeof(char **) * (i / 4));
	temp = (char **)malloc(sizeof(char *) * 4);
	num = i;
	i = 0;
	while (i < num)
	{
		j = 0;
		while (j < 4)
			temp[j++] = array[i++];
		grps_of_4[i / 4] = temp;
		i++;
	}
	free (temp);
	return (start_list(num, grps_of_4));
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
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (map[y][x] == '.')
				d++;
			else if (map[y][x] == '#')
				s++;
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
