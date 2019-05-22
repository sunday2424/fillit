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
	char	*ptr;
	int		bytesread;
	int		n;

	
	fd = open(file, O_RDONLY);
	bytesread = read(fd, str, BUFF_SIZE);
	str[bytesread] = '\0';
	ptr = str;
	n = 0;
	while (*ptr != '\0')
	{
		if (*ptr == '\n')
		{
			n++;
			if (((n + 1) % 5 == 0) && \
					!(*(ptr + 1) == '\0' || *(ptr + 1) == '\n'))
				print_error();
		}
		ptr++;
	}
	return valid_input(n, str);
}

t_tet	*valid_input(int ns, char *str)
{
	char	**array;
	int		i;
	int		j;

	if (!(array = ft_strsplit(str, '\n')))
		return NULL;
	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
			j++;
		if (j != 4)
			print_error();
		i++;
	}
	ns = ns - i;
	if ((i % 4 != 0) || (!(((i + ns + 1) % 5) == 0) && i > 4))
		print_error();
	return (save_if_valid(i, array));
}

t_tet	*save_if_valid(int num, char **array)
{
	int		i;
	int		j;
	int		tetn;
	char	***grps_of_4;

	grps_of_4 = (char ***)malloc(sizeof(char **) * (num / 4));
	i = 0;
	while (i < num)
	{
		j = 0;
		tetn = i / 4;
		grps_of_4[tetn] = (char **)malloc(sizeof(char *) * 4);
		while (j < 4)
			grps_of_4[tetn][j++] = array[i++];
		if (!(ctbks(grps_of_4[tetn]) && ccon(grps_of_4[tetn])))
			print_error();
	}
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
		while (x < 4)
		{
			if (map[y][x] == '#')
			{
				if ((x + 1) < 4 && map[y][x + 1] == '#')
					count++;
				if ((x - 1) >= 0 && map[y][x - 1] == '#')
					count++;
				if ((y + 1) < 4 && map[y + 1][x] == '#')
					count++;
				if ((y - 1) >= 0 && map[y - 1][x] == '#')
					count++;
			}
			x++;
		}
		y++;
	}
	return ((count == 6 || count == 8) ? 1 : 0);
}
